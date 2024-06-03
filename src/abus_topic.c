/*
 * @Author: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @Date: 2024-04-15 11:28:27
 * @LastEditors: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @LastEditTime: 2024-06-03 18:45:08
 * @FilePath: \abus-v3\abus_v3\abus_topic.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "abus.h"

static hashTable *topics_Table;
static uint8_t is_init = 0;


void abus_topic_set_show_by_name(const char *topic, abus_type_show_fun show, const char *token)
{
    abus_topic_t *top = abus_topic_find_by_name(topic);
    if (top)
    {
        top->show = show;
    }
}
static int abus_cb_async_notify(abus_subcriber_t *subcriber, void *data)
{
    if (subcriber->sem)
    {
        return abus_sem_post(subcriber->sem);
    }
    else
    {
        return -1;
    }
}
int abus_subcriber_wait(abus_subcriber_t *subcriber, uint32_t max_time)
{
    if (subcriber->sem)
    {
        return abus_sem_wait(subcriber->sem, max_time);
    }
    else
    {
        return -1;
    }
}
int abus_subcriber_wait_by_name(const char *topic, const char *subcriber, uint32_t max_time)
{
    abus_topic_t *top = abus_topic_find_by_name(topic);
    if (top)
    {
        abus_subcriber_t *sub = abus_subcribe_find_by_name(top, subcriber);
        if (sub)
        {
            return abus_subcriber_wait(sub, max_time);
        }
    }
    return -2;
}
int abus_subcribe(const char *topic, const char *accounter, abus_subcribe_cfg_t *cfg)
{
    abus_subcriber_t subcriber;
    ABUS_MEMMSET(&subcriber, 0, sizeof(abus_subcriber_t));

    abus_topic_t *top = abus_topic_find_by_name(topic);
    abus_acc_t *acc = abus_accounter_find_by_name(accounter);
    if (topic == NULL)
    {
        ABUS_HASH_PRINTF("topic name is null\n");
        return -1;
    }
    if (accounter == NULL)
    {
        ABUS_HASH_PRINTF("accounter is null\n");
        return -2;
    }
    if (top == NULL)
    {
        ABUS_HASH_PRINTF("[abus sub]topic(%s) is null\n", topic);

        return -3;
    }
    subcriber.acc = acc;
    subcriber.cb = cfg->cb;
    subcriber.fifo = cfg->fifo;
    subcriber.state.rx_cnt = 0;
    if (cfg->is_async == 1)
    {
        printf("sub %s notify\n", subcriber.acc->name);
        abus_sem_init(cfg->sem, 0);
        subcriber.cb = abus_cb_async_notify;
    }
    else
    {
        // while (1){
        //     printf("%d %d\n",cfg->is_async  , cfg->sem);
        // }
        ; // TODO:警告
    }
    if (cfg->filter != NULL)
    {
        ABUS_HASH_PRINTF("filter is not null load filter\n");
        subcriber.filter = cfg->filter;
    }
    if (top->subcribers)
    {
        cvector_pushback(top->subcribers, &subcriber);
    }
    else
    {
        return -2;
    }
    if (top->sub_hash_table)
    {
        HashTableInsert(top->sub_hash_table, accounter, cvector_end(top->subcribers));
    }

    // cvector_popback(top->subcribers, &subcriber);
    //  HashTableInsert(top->sub_hash_table, accounter, &subcriber);
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
    return 0;
}

int abus_publish(const char *topic, void *data)
{
    abus_topic_t *top = abus_topic_find_by_name(topic);
    // abus_acc_t *acc = abus_accounter_find_by_name(accounter);
    abus_subcriber_t *sub;
    if (top == NULL)
        return -1;

    /* 遍历所有订阅者 */
		ABUS_ASSSERT(top->subcribers);
    //CVECTOR_FOREACH(top->subcribers, sub, abus_subcriber_t)

    for (sub = (abus_subcriber_t*)cvector_begin(top->subcribers); sub != (abus_subcriber_t*)cvector_end(top->subcribers); sub = (abus_subcriber_t*)cvector_next(top->subcribers, sub))
    {
        if (sub->fifo)
            afifo_in(sub->fifo, data, top->cfg.topic_data_size);

        if (sub->cb)
            sub->cb(sub, data);
        else
        {
            printf("sub %s have no cb\n", sub->acc->name);
        }
        sub->state.rx_cnt++;
    }

    return 0;
}

int abus_publish_to(const char *topic, void *data, const char *subcriber)
{
    return 0;
}

/**
 * @brief 对于TOPIC的全局初始化
 * 
 * @note 无需刻意调用，在创建第一个topic时候会自动被调用
 * 
 */
void abus_topic_init(void)
{
    if (is_init == 0)
    {
        is_init = 1;
        ABUS_HASH_PRINTF("Init topics hash table\n");

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
    ABUS_MEMMSET(topic, 0, sizeof(abus_topic_t));
    if (topic)
    {
        topic->name = name;
        topic->cfg = *cfg;
        topic->desc = desc;
        if (cfg->hash_table_size)
        {
            ABUS_HASH_PRINTF("Init sub hash table\n");
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
    ABUS_HASH_PRINTF("topic create: %s\n", topic->name);

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

/**
 * @brief 从订阅者独立缓冲区获取数据
 *
 * @param subcriber 订阅者句柄
 * @param pdata 接收数据地址
 * @param data_cnt 想要接收数据个数
 * @return uint32_t 实际接收数据个数
 */
uint32_t abus_get_data(abus_subcriber_t *subcriber, uint8_t *pdata, size_t data_cnt)
{
    ABUS_ASSSERT(subcriber);
    if (subcriber->fifo)
    {
        return afifo_out(subcriber->fifo, pdata, data_cnt);
    }
    return 0;
}
/**
 * @brief 获取到订阅者独立缓存中的数据个数
 *
 * @param subcriber
 * @return uint32_t
 */
uint32_t abus_get_received(abus_subcriber_t *subcriber)
{
    if (subcriber->fifo)
    {
        return afifo_get_used(subcriber->fifo);
    }
    else
    {
        return 0;
    }
}

abus_subcriber_t *abus_subcribe_find_by_name(abus_topic_t *topic, const char *subcriber)
{
    abus_subcriber_t *sub;

    if (topic->sub_hash_table)
    {
        /*use hash cache*/
        void *ret = HashTableSearch(topic->sub_hash_table, subcriber);
        if (ret == 0)
            goto __THIS;
    }
    else
    {
    __THIS:
        CVECTOR_FOREACH(topic->subcribers, sub, abus_subcriber_t)
        {
            if (strcmp(sub->acc->name, subcriber) == 0)
                return sub;
        }
    }
    return NULL;
}
uint32_t abus_get_data_by_name(const char *topic, const char *subcriber, uint8_t *pdata, size_t data_cnt)
{
    abus_topic_t *top = abus_topic_find_by_name(topic);
    if (top)
    {
        abus_subcriber_t *sub = abus_subcribe_find_by_name(top, subcriber);
        if (sub)
        {
            return abus_get_received(sub);
        }
    }
    return 0;
}

uint32_t abus_get_received_by_name(const char *topic, const char *subcriber)
{
    abus_topic_t *top = abus_topic_find_by_name(topic);
    if (top)
    {
        abus_subcriber_t *sub = abus_subcribe_find_by_name(top, subcriber);
        if (sub)
        {
            abus_get_received(sub);
        }
    }
    return 0;
}

void abus_topic_show(const char *topic)
{
    abus_topic_t *top = abus_topic_find_by_name(topic);
    if (top)
    {
        abus_subcriber_t *sub;
        ABUS_HASH_PRINTF("topic found:\t%s\ndata struct: \t%s size:%d bytes\n", topic, top->desc, top->cfg.topic_data_size);
        ABUS_HASH_PRINTF("subcribers: \tname\tfifo\trx_cnt\n");
        CVECTOR_FOREACH(top->subcribers, sub, abus_subcriber_t)
        {
            ABUS_HASH_PRINTF("\t\t\t%s\t%d\t%d\n", sub->acc->name, (uint32_t)(sub->fifo ? sub->fifo->size : -1), sub->state.rx_cnt);
        }
    }
    else
    {
        ABUS_HASH_PRINTF("%s is not found", topic);
    }
}
static void printKeyValuePair(const char *key, void *data, void *userdata)
{
    (void)userdata; // unused parameter
    ABUS_HASH_PRINTF("%16s\t%8p\n", key, data);
}

void abus_topic_show_all(void)
{
    ABUS_HASH_PRINTF("Key\t\t\tData\n");
    //DisplayHashTable(topics_Table);
    HashTableIterate(topics_Table, printKeyValuePair, NULL);

}