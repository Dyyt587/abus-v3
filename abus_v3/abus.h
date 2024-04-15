#ifndef ABUS_H
#define ABUS_H
#ifdef __cplusplus
extern "C" {
#endif
#include "abus_port.h"
#define MaxSize 10
#define NullKey 0xFFFFFFFF
#define ABUS_HASH_PRINTF printf
#define ABUS_MALLOC malloc
    // ������
    typedef struct LNode
    {
        const char* name;
        void* data;
        struct LNode* next;
    }LNode, * LinkList; //LNode node; // ����һ���������        LinkList list; // ����һ�������ָ��

    // ��ϣ��
    typedef struct hashTable
    {
        LinkList list;// ����һ�������ָ��
        int count;
        int list_size;
    }hashTable;

    typedef struct abusAccounter
    {
        const char* name;

    }abusAcc_t;

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
