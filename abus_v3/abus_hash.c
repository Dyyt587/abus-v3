#include "abus.h"

#include <math.h>


// ��ʼ����ϣ��
hashTable* HashTableInit(int size)
{
    hashTable* H;
    // ����������ͷ���ռ�
    H->list_size = (MaxSize > size ? MaxSize : size);
    H->list = (LNode*)ABUS_MALLOC(H->list_size *sizeof(LNode));//����20��LNode���Ԫ�ؿռ� 
    H->count = 0;
    if (H->list == 0) {
        H->list_size = 0;
        return 0;
    }
    // ��ʼ������ͷ��㣨ͷ���洢��ʼֵ�����������洢��ͻֵ��
    int i;
    for (i = 0; i < H->list_size; i++)
    {
        H->list[i].name = (const char*)NullKey;
        H->list[i].data = 0;
        H->list[i].next = NULL;
    }
    ABUS_HASH_PRINTF("�ѳ�ʼ����ϣ��!\n");
    return H;
}

// �����ϣ����
unsigned int hashFunction(const char* str) {
    unsigned int hash = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        hash += (int)str[i];
    }

    return hash % MaxSize;
}
// ���������ڵ������
void swap(LNode* a, LNode* b) {
    const char* temp;
    temp = a->name;

    a->name = b->name;

    b->name = temp;

}

// ���������ð������
void bubbleSort(LNode* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    int swapped;
    LNode* current;
    LNode* last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (strcmp(current->name, current->next->name) > 0) {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// ����ؼ���
void InsertHashKey(hashTable* H, const char* key, void* data)
{
    // ���ݹ�ϣ�����õ��±��ַ
    int address = hashFunction(key);
    ABUS_HASH_PRINTF("\n����ؼ��� %s, ��ϣ��ַ = %d\n", key, address);

    if (H->list[address].name == (const char*)NullKey)
    {
        // ��δ������ͻ����ֱ�Ӹ�ֵ��ͷ���
        H->list[address].name = key;
        H->list[address].data = data;
        ABUS_HASH_PRINTF("�����±��ַ[%d], ����ɹ�!\n\n", address);
    }
    else
    {
        // ��������ͻ�����ڸ�ͷ���������½���ͷ��
        // �����½��
        LNode* s;
        s = (LNode*)ABUS_MALLOC(sizeof(LNode));
        s->name = key;
        s->data = data;
        // ͷ�巨����
        s->next = H->list[address].next;//��ͷ����next��ֵ���½���next����ֵ��ǰ��
        H->list[address].next = s;

        bubbleSort(H->list[address].next);

        ABUS_HASH_PRINTF("�����±��ַ[%d], ������ͻ! �Ѳ���õ�ַ��������\n\n", address);
    }
    H->count++;
}

// ���ҹؼ���
void* SearchHashKey(hashTable H, const char* key)
{
    int address = hashFunction(key);
    // ���ݹ�ϣ��ַ��ȡ��Ӧ�����ͷ���
    LNode* p = &H.list[address];
    // �������в��ҹؼ���
    while (p != NULL && strcmp(p->name, key) != 0)
    {
        // ����̽��
        p = p->next;
    }
    return p->data;
}

void DisplayHashTable(hashTable H)
{
    int i;
    ABUS_HASH_PRINTF("��ϣ��\n**********************************\n");
    for (i = 0; i < MaxSize; i++)
    {
        ABUS_HASH_PRINTF("%d\t", i);
    }
    ABUS_HASH_PRINTF("\n");

    LNode* p;
    int j, k = 0, flag = 1;

    while (flag)
    {
        flag = 0;
        for (i = 0; i < MaxSize; i++)
        {
            j = 0;
            p = &H.list[i];
            while (j < k && p)
            {
                p = p->next;
                j++;
            }
            if (p && p->name != (const char*)NullKey)
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

