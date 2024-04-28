#include "abus.h"

#include <math.h>

// 初始化哈希表
hashTable *HashTableInit(int size)
{
    hashTable *H=0;
    H = (hashTable *)ABUS_MALLOC(sizeof(hashTable));
    // 分配多个链表头结点空间
    H->list = (LNode *)ABUS_MALLOC((MaxSize > size ? MaxSize : size) * sizeof(LNode));
    if (H == NULL)
        return NULL;
    H->list_size = (MaxSize > size ? MaxSize : size);
    H->count = 0;
    if (H->list == 0)
    {
        H->list_size = 0;
        return 0;
    }
    // 初始化链表头结点（头结点存储初始值，链表后序结点存储冲突值）
    int i;
    for (i = 0; i < H->list_size; i++)
    {
        H->list[i].name = (const char *)NullKey;
        H->list[i].data = 0;
        H->list[i].next = NULL;
    }
    ABUS_HASH_PRINTF("init hash table!\n");
    return H;
}
void HashTableDestroy(hashTable *H)
{
    ABUS_FREE(H->list);
    ABUS_FREE(H);
    ABUS_HASH_PRINTF("destroy hashtable!\n");
}
// 定义哈希函数
unsigned int hashFunction(const char *str)
{
    unsigned int hash = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        hash += (int)str[i];
    }

    return hash % MaxSize;
}
// 交换两个节点的数据
void swap(LNode *a, LNode *b)
{
    const char *temp;
    temp = a->name;

    a->name = b->name;

    b->name = temp;
}

// 对链表进行冒泡排序
void bubbleSort(LNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    int swapped;
    LNode *current;
    LNode *last = NULL;

    do
    {
        swapped = 0;
        current = head;

        while (current->next != last)
        {
            if (strcmp(current->name, current->next->name) > 0)
            {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// 插入关键字
void HashTableInsert(hashTable *H, const char *key, void *data)
{
    // 根据哈希函数得到下标地址
    int address = hashFunction(key);
    ABUS_HASH_PRINTF("\ninsert key %s, hash addr = %d\n", key, address);

    if (H->list[address].name == (const char *)NullKey)
    {
        // 若未发生冲突，则直接赋值给头结点
        H->list[address].name = key;
        H->list[address].data = data;
        ABUS_HASH_PRINTF("inserted list[%d]!\n\n", address);
    }
    else
    {
        // 若发生冲突，则在该头结点的链表下进行头插
        // 创建新结点
        LNode *s;
        s = (LNode *)ABUS_MALLOC(sizeof(LNode));
        s->name = key;
        s->data = data;
        // 头插法插入
        s->next = H->list[address].next; // 将头结点的next赋值给新结点的next，新值在前面
        H->list[address].next = s;

        bubbleSort(H->list[address].next);

        ABUS_HASH_PRINTF("insert[%d] and Conflicts!\n\n", address);
    }
    H->count++;
}

// 查找关键字
void *HashTableSearch(hashTable* H, const char *key)
{
    int address = hashFunction(key);
    // 根据哈希地址获取对应链表的头结点
    LNode *p = &H->list[address];
    // 在链表中查找关键字
    while (p != NULL)
    {
        // 线性探测
        if(strcmp(p->name, key) != 0){
            p = p->next;
        }else{
            return p->data;
        }
    }
    //if(p==NULL || strcmp(p->name, key) == 0)return NULL;
    return NULL;
}
void HashTableRemove(hashTable *H, const char *key)
{
        int address = hashFunction(key);
    // 根据哈希地址获取对应链表的头结点
    LNode *p = &H->list[address];
    LNode *last_p=0;
    // 在链表中查找关键字
    while (p != NULL && strcmp(p->name, key) != 0)
    {
        // 线性探测
        last_p=p;
        p = p->next;
    }
    if(p){
        last_p->next=p->next;
    }
}

void DisplayHashTable(hashTable* H)
{
    int i;
    ABUS_HASH_PRINTF("hash table\n**********************************\n");
    for (i = 0; i < MaxSize; i++)
    {
        ABUS_HASH_PRINTF("%d\t", i);
    }
    ABUS_HASH_PRINTF("\n");

    LNode *p;
    int j, k = 0, flag = 1;

    while (flag)
    {
        flag = 0;
        for (i = 0; i < MaxSize; i++)
        {
            j = 0;
            p = &H->list[i];
            while (j < k && p)
            {
                p = p->next;
                j++;
            }
            if (p && p->name != (const char *)NullKey)
            {
                ABUS_HASH_PRINTF("%s\t", p->name);
                flag = 1;
            }
            else
            {
                ABUS_HASH_PRINTF(" \t");
            }
        }
        k++;
        ABUS_HASH_PRINTF("\n");
    }
    ABUS_HASH_PRINTF("*********************************\n");
}
