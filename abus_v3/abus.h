#ifndef ABUS_H
#define ABUS_H
#ifdef __cplusplus
extern "C" {
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
        const char* name;
        void* data;
        struct LNode* next;
    }LNode, * LinkList; //LNode node; // 声明一个单个结点        LinkList list; // 声明一个链表的指针

    // 哈希表
    typedef struct hashTable
    {
        LinkList list;// 声明一个链表的指针
        int count;
        int list_size;
    }hashTable;

    typedef struct abusAccounter
    {
        const char* name;

    }abusAcc_t;

    typedef struct{
        abusAcc_t*acc;
        afifo_t* fifo;//订阅者可选独立数据缓存
    }abus_subcriber;
    typedef struct abusTopic
    {
        const char* name;
        
    }abusTopic_t;


    hashTable* HashTableInit(int size);
    void InsertHashKey(hashTable* H, const char* key, void* data);
    void* SearchHashKey(hashTable H, const char* key);
    void DisplayHashTable(hashTable H);



#ifdef __cplusplus
}
#endif
#endif
