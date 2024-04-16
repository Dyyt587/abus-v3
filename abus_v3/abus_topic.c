#include "abus.h"
#define TOPIC_TABLE_SIZE 16
static hashTable *topics_Table;
static uint8_t is_init = 0;
void abus_topic_init(void)
{
    if (is_init == 0)
    {
        is_init = 1;
        topics_Table = HashTableInit(TOPIC_TABLE_SIZE);
    }
}

abus_topic_t *abus_topic_create(const char *name, abus_topic_cfg *cfg)
{
    abus_topic_init();
    abus_topic_t *topic = ABUS_MALLOC(sizeof(abus_topic_t));
    if (topic)
    {
        topic->name = name;
        topic->cfg = *cfg;
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
            ABUS_FREE(topic);
            return NULL;
        }
    }
    return topic;
}
void abus_topic_destroy(abus_topic_t *topic)
{
}
