#include "abus.h"




/* globol variables */
static hashTable *accounters_Table;
static uint8_t is_init = 0;
void abus_acc_init(void)
{
    if (is_init == 0)
    {
        is_init = 1;
        accounters_Table = HashTableInit(ACCOUNTERS_TABLE_SIZE);
    }
}
abus_acc_t *abus_accounter_find_by_name(const char *name)
{
    ABUS_ASSSERT(name != NULL);
    ABUS_ASSSERT(accounters_Table != NULL);
    return HashTableSearch(accounters_Table, name);
}
abus_acc_t *abus_accounter_create(const char *name, abus_filter *filter)
{
    ABUS_ASSSERT(name != NULL);
    abus_acc_init();
    ABUS_ASSSERT(accounters_Table != NULL);

    abus_acc_t *acc =   ABUS_MALLOC(sizeof(abus_acc_t));
    if(acc)
    {  
        acc->name = name;
        acc->filter = filter;
        ABUS_HASH_PRINTF("accounter_create: %s\n", name);
        HashTableInsert(accounters_Table, name, acc);
    }
    return acc;
}
void abus_accounter_destroy(abus_acc_t *accounter)
{
    ABUS_ASSSERT(accounter);
    ABUS_ASSSERT(accounters_Table);
    HashTableRemove(accounters_Table, accounter->name);
    ABUS_FREE(accounter);
    ABUS_HASH_PRINTF("accounter_destroy: %s\n", accounter->name);
}


void abus_acc_show(const char* acc)
{
    abus_acc_t* acc_ = abus_accounter_find_by_name(acc);
    if (acc) {
        ABUS_HASH_PRINTF("accounter found:%s\n", acc);

    }
    else {
        ABUS_HASH_PRINTF("%s is not found", acc);
    }
}
static void  printKeyValuePair(const char *key, void *data, void *userdata)
{
    (void)userdata; // unused parameter
    
    ABUS_HASH_PRINTF("%16s\t%8p\n", key, data);
}
void abus_acc_show_all(void)
{
        ABUS_HASH_PRINTF("Key\t\t\tData\n");
	 //   DisplayHashTable(accounters_Table);
    HashTableIterate(accounters_Table, printKeyValuePair, NULL);
}
