#pragma noce
#ifndef ABUS_CPLUEPLUE
#define ABUS_CPLUEPLUE

#include "abus.h"

class abus_topic;
class abus_acc;

class abus_acc
{
private:
    static abus_filter default_filter;
    static abus_subcribe_cfg_t default_cfg;
    abus_acc_t *acc;
    friend abus_topic;

public:
    abus_acc(const char *name)
    {
        acc = abus_accounter_create(name, &default_filter);
    }
    ~abus_acc()
    {
    }
    void subcribe(abus_topic &topic, abus_subcribe_cfg_t *cfg=&abus_acc::default_cfg);
    void subcribe(const char* topic_name, abus_subcribe_cfg_t *cfg=&abus_acc::default_cfg);
};

class abus_topic
{
private:
    abus_topic_t *topic;
    static abus_subcribe_cfg_t default_config;
    friend abus_acc;

public:
    abus_topic(const char *name, abus_topic_cfg *cfg)
    {
        topic = abus_topic_create(name, cfg, "null desc");
    }
    abus_topic(const char *name, abus_topic_cfg *cfg, const char *desc)
    {
        topic = abus_topic_create(name, cfg, desc);
    }
    ~abus_topic()
    {
    }

    void subcribed(abus_acc &acc, abus_subcribe_cfg_t *cfg = &abus_topic::default_config);
    void subcribed(const char* acc_name, abus_subcribe_cfg_t *cfg = &abus_topic::default_config);

};

#endif
