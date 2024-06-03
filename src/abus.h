/*
 * @Author: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @Date: 2024-05-15 22:20:48
 * @LastEditors: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @LastEditTime: 2024-05-31 08:22:02
 * @FilePath: \24_robocon_code\project\applications\abus_v3\src\abus.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
#include "abus_osal.h"
#include "abus_port.h"
#include "cvector.h"
#include "afifo.h"
#include "stdbool.h"
#include "abus_def.h"
#include "abus_deamon.h"

#define MaxSize 10
#define NullKey 0
#define ABUS_HASH_PRINTF rt_kprintf
#define ABUS_MALLOC rt_malloc
#define ABUS_MEMMSET rt_memset
#define ABUS_FREE rt_free

#define ACCOUNTERS_TABLE_SIZE 32
#define TOPIC_TABLE_SIZE 16


#define ABUS_ASSSERT(x)                      \
    while (!(x))                             \
    {                                        \
        ABUS_HASH_PRINTF("assert failed\n"); \
    }

#define ABUS_TOPIC_CREATE(__topic, __dat_type, __hashSize)                    \
    ({                                                                         \
        abus_topic_cfg ABUS_TOPIC_CGF = {                         \
            .hash_table_size = __hashSize,                                    \
            .topic_data_size = sizeof(__dat_type),                            \
        };                                                                    \
        abus_topic_create(__topic, &ABUS_TOPIC_CGF, #__dat_type); \
    })

#define ABUS_ACC_CREATE(__acc, __filter)        \
    ({                                           \
        abus_accounter_create(__acc, __filter); \
    })

#define ABUS_SUB_BY_NAME(__acc, __topic, _fifo, __cb, __filter_gloab) \
    {                                                             \
        abus_subcribe_cfg_t _SBU_CFG__topic = {                   \
            .fifo = _fifo,                                    \
            .filter = __filter_gloab,                             \
            .cb = __cb,                                           \
        };                                                        \
        abus_subcribe(__topic, __acc, &_SBU_CFG__topic);          \
    }

/*
查找用户如果没有就创建一个进行订阅
*/
#define ABUS_SUB_FORCE(__acc, __topic, _fifoSize, __cb, __filter_gloab, __filter_acc) \
    {                                                                                 \
        abus_subcribe_cfg_t ___SUB__topic = {                                         \
            .fifo = _fifoSize,                                                        \
            .filter = __filter_gloab,                                                 \
            .cb = __cb,                                                               \
        };                                                                            \
        if (abus_accounter_find_by_name(__acc))                                       \
        {                                                                             \
            abus_subcribe(__topic, __acc, &___SUB__topic);                            \
        }                                                                             \
        else                                                                          \
        {                                                                             \
            ABUS_ACC_CREATE(__acc, __filter_acc);                                     \
            abus_subcribe(__topic, __acc, &___SUB__topic);                            \
        }                                                                             \
    }

    hashTable *HashTableInit(int size);
    void HashTableDestroy(hashTable *H);
    void HashTableInsert(hashTable *H, const char *key, void *data);
    void HashTableRemove(hashTable *H, const char *key);
    void *HashTableSearch(hashTable *H, const char *key);
    void DisplayHashTable(hashTable *H);
    void HashTableIterate(hashTable *H, HashIterCallback callback, void *userdata);

    abus_topic_t *abus_topic_create(const char *name, abus_topic_cfg *cfg, const char *desc);
    abus_topic_t *abus_topic_create(const char *name, abus_topic_cfg *cfg, const char *desc);

    void abus_topic_destroy(abus_topic_t *topic);

    void abus_topic_set_show(abus_topic_t *topic, abus_type_show_fun show, const char *token);
    void abus_topic_set_show_by_name(const char *topic, abus_type_show_fun show, const char *token);

    abus_topic_t *abus_topic_find_by_name(const char *name);
    abus_subcriber_t *abus_subcribe_find_by_name(abus_topic_t *topic, const char *subcriber);

    abus_acc_t *abus_accounter_create(const char *name, abus_filter *filter);
    void abus_accounter_destroy(abus_acc_t *accounter);
    abus_acc_t *abus_accounter_find_by_name(const char *name);

    int abus_subcribe(const char *topic, const char *subcriber, abus_subcribe_cfg_t *cfg);
    int abus_unsubcribe(const char *topic, const char *subcriber);

    int abus_publish(const char *topic, void *data);
    int abus_publish_to(const char *topic, void *data, const char *subcriber);

    void abus_topic_show(const char *topic);
    void abus_topic_show_all(void);

    void abus_acc_show(const char *acc);
    void abus_acc_show_all(void);

    void abus_echo_by_name(const char *topic, int rate); // 创建一个订阅者，按照发布次数来打印数据
    void abus_echo(abus_topic_t *topic, int rate);

    /**
     * @brief 从订阅者独立缓冲区获取数据
     *
     * @param subcriber 订阅者句柄
     * @param pdata 接收数据地址
     * @param data_cnt 想要接收数据个数
     * @return uint32_t 实际接收数据个数
     */
    uint32_t abus_get_data(abus_subcriber_t *subcriber, uint8_t *pdata, size_t data_cnt);
    /**
     * @brief 获取到订阅者独立缓存中的数据个数
     *
     * @param subcriber
     * @return uint32_t
     */
    uint32_t abus_get_received(abus_subcriber_t *subcriber);

    uint32_t abus_get_data_by_name(const char *topic, const char *subcriber, uint8_t *pdata, size_t data_cnt);

    uint32_t abus_get_received_by_name(const char *topic, const char *subcriber);

    int abus_subcriber_wait(abus_subcriber_t *subcriber, uint32_t max_time);
    int abus_subcriber_wait_by_name(const char *topic, const char *subcriber, uint32_t max_time);

#ifdef __cplusplus
}
#endif
#endif
