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

int abus_subcribe(const char *topic, const char *accounter, abus_filter *filter, abus_subcribe_cb cb)
{
    abus_subcriber_t subcriber;
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
    subcriber.acc = acc;
    subcriber.cb = cb;
    if (filter != NULL)
    {
        ABUS_HASH_PRINTF("filter is not null load filter\n");
        subcriber.filter = *filter;
    }
    // if(top->subcribers){
    //     cv_pushback(top->subcribers, &subcriber);
    // }
    // if(top->sub_hash_table){
    //     HashTableInsert(top->sub_hash_table, accounter, &subcriber);
    // }
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
    // if (accounter == NULL)
    //     return -2;
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
    if (topic)
    {
        topic->name = name;
        topic->cfg = *cfg;
        topic->desc = desc;
        if (cfg->is_using_hash)
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
    HashTableRemove(topics_Table, topic->name);
    cvector_destroy(topic->subcribers);
    HashTableDestroy(topic->sub_hash_table);
    ABUS_FREE(topic);
}
