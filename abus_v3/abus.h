#ifndef ABUS_H
#define ABUS_H
#ifdef __cplusplus
extern "C"
{
#endif
#include "abus_port.h"
#include "cvector.h"
#include "afifo.h"

#define MaxSize 10
#define NullKey 0xFFFFFFFF
#define ABUS_HASH_PRINTF printf
#define ABUS_MALLOC malloc
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

    typedef struct abus_accounter
    {
        const char *name;
        abus_filter *filter; // 可选的账户全局过滤器
    } abus_acc_t;

    typedef struct
    {
        int TODO;
    } abus_filter;

    typedef int (*abus_subcribe_cb)(abus_subcriber *subcriber, void *data);
    typedef struct
    {
        abus_acc_t *acc;
        const char *desc; // 可选的订阅结构体字符串

        afifo_t *fifo;       // 订阅者可选独立数据缓存
        abus_filter *filter; // 订阅者可选过滤器
        abus_subcribe_cb cb; // 订阅者可选数据回调函数
    } abus_subcriber;

    typedef struct
    {
        int TODO;
    } abus_topic_cfg;
    typedef struct abusTopic
    {
        const char *name;
        cvector subcribers;   // 用于存储abus_subcriber类型的容器
        hashTable *sub_table; // 可选的hash快速索引
        abus_topic_cfg cfg;
    } abus_topic_t;

    hashTable *HashTableInit(int size);
    void InsertHashKey(hashTable *H, const char *key, void *data);
    void *SearchHashKey(hashTable H, const char *key);
    void DisplayHashTable(hashTable H);

#ifdef __cplusplus
}
#endif
#endif
