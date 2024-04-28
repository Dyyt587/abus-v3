/*
 * @Author: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @Date: 2024-04-15 11:28:27
 * @LastEditors: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @LastEditTime: 2024-04-23 17:42:52
 * @FilePath: \abus-v3\abus_v3\abus_topic.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "abus.h"
#define TOPIC_TABLE_SIZE 16
static hashTable *topics_Table;
static uint8_t is_init = 0;

int abus_subcribe(const char *topic, const char *accounter, abus_subcribe_cfg_t* cfg)
{
    abus_subcriber_t subcriber;
    ABUS_MEMMSET(&subcriber, sizeof(abus_subcriber_t), 0);

    abus_topic_t *top = abus_topic_find_by_name(topic);
    abus_acc_t *acc = abus_accounter_find_by_name(accounter);
    if (topic == NULL){
        ABUS_HASH_PRINTF("topic is null\n");
        return -1;
    }
    if (accounter == NULL){
        ABUS_HASH_PRINTF("accounter is null\n");
        return -2;
    }
    if (top == NULL) {
        ABUS_HASH_PRINTF("topic is null\n");
        return -3;
    }
    subcriber.acc = acc;
    subcriber.cb = cfg->cb;
    subcriber.fifo = cfg->fifo;

    if (cfg->filter != NULL)
    {
        ABUS_HASH_PRINTF("filter is not null load filter\n");
        subcriber.filter = cfg->filter;
    }
     if(top->subcribers){
         cvector_pushback(top->subcribers, &subcriber);
     }
     else {
         return -2;
     }
     if(top->sub_hash_table){
         HashTableInsert(top->sub_hash_table, accounter, cvector_end(top->subcribers));
     }
    //cvector_popback(top->subcribers, &subcriber);
    // HashTableInsert(top->sub_hash_table, accounter, &subcriber);
    return 0;
}

abus_subcriber_t *abus_find_subcriber(abus_topic_t *topic, const char *subcriber)
{
    if (topic->sub_hash_table)
    {
        return HashTableSearch(topic->sub_hash_table, subcriber);
    }

    return 0;
}
int abus_unsubcribe(const char *topic, const char *subcribe)
{
    abus_topic_t *top = abus_topic_find_by_name(topic);
    // abus_acc_t *acc = abus_accounter_find_by_name(accounter);
    abus_subcriber_t *sub = abus_find_subcriber(top, subcribe);
    if (topic == NULL)
        return -1;
     if (sub == NULL)
         return -2;
}

int abus_publish(const char* topic, void* data)
{
    abus_topic_t* top = abus_topic_find_by_name(topic);
    // abus_acc_t *acc = abus_accounter_find_by_name(accounter);
    abus_subcriber_t* sub;
    citerator iter=NULL;
    if (topic == NULL)
        return -1;

    /* 遍历所有订阅者 */ 
    CVECTOR_FOREACH(top->subcribers,sub, abus_subcriber_t*) {
        if (sub->fifo)afifo_in(sub->fifo, data, top->cfg.topic_data_size);

        if (sub->cb)sub->cb(sub, data);

    }

    return 0;
}

int abus_publish_to(const char* topic, void* data, const char* subcriber)
{
    return 0;
}

void abus_topic_init(void)
{
    if (is_init == 0)
    {
        is_init = 1;
        topics_Table = HashTableInit(TOPIC_TABLE_SIZE);
    }
}

abus_topic_t *abus_topic_find_by_name(const char *name)
{
    ABUS_ASSSERT(name);
    ABUS_ASSSERT(topics_Table);
    return HashTableSearch(topics_Table, name);
}
abus_topic_t *abus_topic_create(const char *name, abus_topic_cfg *cfg, const char *desc)
{
    abus_topic_init();
    abus_topic_t *topic = ABUS_MALLOC(sizeof(abus_topic_t));
    ABUS_MEMMSET(topic, sizeof(abus_topic_t), 0);
    if (topic)
    {
        topic->name = name;
        topic->cfg = *cfg;
        topic->desc = desc;
        if (cfg->hash_table_size)
        {
            topic->sub_hash_table = HashTableInit(cfg->hash_table_size);
        }
        else
        {
            topic->sub_hash_table = NULL;
        }
        topic->subcribers = cvector_create(sizeof(abus_subcriber_t));
        if (topic->subcribers)
        {
            HashTableInsert(topics_Table, name, topic);
        }
        else
        {
            ABUS_HASH_PRINTF("create subcribers error\n");
            ABUS_FREE(topic);
            return NULL;
        }
    }
    ABUS_HASH_PRINTF("topic create: %s\n",topic->name);

    return topic;
}
void abus_topic_destroy(abus_topic_t *topic)
{
    ABUS_ASSSERT(topic);
    ABUS_ASSSERT(topic->name);
    ABUS_ASSSERT(topics_Table);
    HashTableRemove(topics_Table, topic->name);
    cvector_destroy(topic->subcribers);
    HashTableDestroy(topic->sub_hash_table);
    ABUS_FREE(topic);
}


void abus_topic_show(const char* topic)
{
    abus_topic_t* top = abus_topic_find_by_name(topic);
    if (top) {
        ABUS_HASH_PRINTF("topic found:%s\ndata struct: %s size:%d\n", topic,top->desc,top->cfg.topic_data_size);

    }
    else {
        ABUS_HASH_PRINTF("%s is not found", topic);
    }
}