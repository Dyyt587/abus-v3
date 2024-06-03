/*
 * @Author: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @Date: 2024-05-21 13:45:16
 * @LastEditors: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @LastEditTime: 2024-05-23 22:15:40
 * @FilePath: \project\applications\abus_v3\src\abus_def.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#ifndef _ABUS_DEF_H_
#define _ABUS_DEF_H_

#include <stdint.h>
#include "afifo.h"
 struct abusTopic;
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
typedef void (*HashIterCallback)(const char *key, void *data, void *userdata);

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

    typedef struct
    {
        uint32_t rx_cnt;      /*用户接收数据包总数*/
        uint8_t is_async : 1; /*判断是否是同步订阅*/

    } abus_state_t;

    struct abus_subcriber
    {
        abus_acc_t *acc;
        afifo_t *fifo;       // 订阅者可选独立数据缓存
        abus_filter *filter; // 订阅者可选过滤器
        abus_subcribe_cb cb; // 订阅者可选数据回调函数
        abus_sem_t *sem;     // 用于异步通讯模式，异步通讯不必带fifo，无fifo只是接受不到数据，可以用作同步
        abus_state_t state;
    };
    typedef struct abus_subcribe_cfg
    {
        afifo_t *fifo;       // 订阅者可选独立数据缓存
        abus_filter *filter; // 订阅者可选过滤器
        abus_subcribe_cb cb; // 订阅者可选数据回调函数
        uint8_t is_async;    // 如果sync则cb替换为
        abus_sem_t *sem;     // 用于异步通讯模式，sem
    } abus_subcribe_cfg_t;
    typedef struct
    {
        uint16_t hash_table_size;
        uint16_t topic_data_size;
    } abus_topic_cfg;
    typedef void (*abus_type_show_fun)(const char* token,void *data);
    typedef struct abusTopic
    {
        const char *name;
        cvector subcribers;        // 用于存储abus_subcriber类型的容器
        cvector subcribers_async;  // 用于存储abus_subcriber类型的容器,异步
        hashTable *sub_hash_table; // 可选的hash快速索引
        abus_topic_cfg cfg;
        const char *desc; // 可选的订阅结构体字符串
        const char* token;//可选的用于可视化数据的数字解析名牌
        abus_type_show_fun show;
    } abus_topic_t;

#endif