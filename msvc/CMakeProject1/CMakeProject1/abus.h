/*
 * @Author: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @Date: 2024-04-15 11:28:27
 * @LastEditors: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @LastEditTime: 2024-04-16 11:17:33
 * @FilePath: \abus-v3\abus_v3\abus.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef ABUS_H
#define ABUS_H
#ifdef __cplusplus
extern "C"
{
#endif
#include "abus_port.h"
#include "cvector.h"
#include "afifo.h"
#include "stdbool.h"

#define MaxSize 10
#define NullKey 0
#define ABUS_HASH_PRINTF printf
#define ABUS_MALLOC malloc
#define ABUS_MEMMSET memset
#define ABUS_FREE free
#define ABUS_ASSSERT(x) \
    while (!(x))        \
    {\
        ABUS_HASH_PRINTF("assert failed\n");\
    }

    // 链表结点
    typedef struct LNode
    {
        const char *name;
        void *data;
        struct LNode *next;
    } LNode, *LinkList; // LNode node; // 声明一个单个结点        LinkList list; // 声明一个链表的指针

    // 哈希表
    typedef struct hashTable
    {
        LinkList list; // 声明一个链表的指针
        int count;
        int list_size;
    } hashTable;

    typedef struct
    {
        int TODO;
    } abus_filter;

    typedef struct abus_accounter
    {
        const char *name;
        abus_filter *filter; // 可选的账户全局过滤器
    } abus_acc_t;

    typedef struct abus_subcriber abus_subcriber_t;
    typedef int (*abus_subcribe_cb)(abus_subcriber_t *subcriber, void *data);

    typedef struct {
        uint32_t rx_cnt;/*用户接收数据包总数*/
    }abus_state_t;
    struct abus_subcriber
    {
        abus_acc_t *acc;
        afifo_t *fifo;       // 订阅者可选独立数据缓存
        abus_filter *filter; // 订阅者可选过滤器
        abus_subcribe_cb cb; // 订阅者可选数据回调函数
        abus_state_t state;
    };
    typedef struct abus_subcribe_cfg
    {
        afifo_t* fifo;       // 订阅者可选独立数据缓存
        abus_filter *filter; // 订阅者可选过滤器
        abus_subcribe_cb cb; // 订阅者可选数据回调函数
    } abus_subcribe_cfg_t;
    typedef struct
    {
        uint16_t hash_table_size;
        uint16_t topic_data_size;
    } abus_topic_cfg;
    typedef struct abusTopic
    {
        const char *name;
        cvector subcribers;        // 用于存储abus_subcriber类型的容器
        hashTable *sub_hash_table; // 可选的hash快速索引
        abus_topic_cfg cfg;
        const char *desc; // 可选的订阅结构体字符串
    } abus_topic_t;

    hashTable *HashTableInit(int size);
    void HashTableDestroy(hashTable *H);
    void HashTableInsert(hashTable *H, const char *key, void *data);
    void HashTableRemove(hashTable *H, const char *key);
    void *HashTableSearch(hashTable *H, const char *key);
    void DisplayHashTable(hashTable *H);

    abus_topic_t *abus_topic_create(const char *name, abus_topic_cfg *cfg, const char *desc);
    void abus_topic_destroy(abus_topic_t *topic);
    abus_topic_t *abus_topic_find_by_name(const char *name);

    abus_acc_t *abus_accounter_create(const char *name, abus_filter *filter);
    void abus_accounter_destroy(abus_acc_t *accounter);
    abus_acc_t *abus_accounter_find_by_name(const char *name);

    int abus_subcribe(const char *topic, const char *subcriber, abus_subcribe_cfg_t* cfg);
    int abus_unsubcribe(const char *topic, const char *subcriber);

    int abus_publish(const char *topic, void *data);
    int abus_publish_to(const char *topic, void *data, const char *subcriber);

    void abus_topic_show(const char* topic);
    void abus_acc_show(const char* acc);

#ifdef __cplusplus
}
#endif
#endif
