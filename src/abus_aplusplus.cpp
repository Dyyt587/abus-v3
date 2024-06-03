#include "abus_cplusplus.h"

void abus_topic::subcribed(abus_acc &acc, abus_subcribe_cfg_t *cfg=&abus_acc::default_cfg)
{
    abus_subcribe(topic->name, acc.acc->name, cfg);
}
void abus_topic::subcribed(const char* acc_name, abus_subcribe_cfg_t *cfg = &abus_topic::default_config)
{
    
}

void abus_acc::subcribe(abus_topic &topic, abus_subcribe_cfg_t *cfg = &abus_topic::default_config)
{
    topic.subcribed(*this,cfg);
}
void abus_acc::subcribe(const char* topic_name, abus_subcribe_cfg_t *cfg=&abus_acc::default_cfg)
{

}


