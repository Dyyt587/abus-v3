
/**
 * @brief 使用字符实现订阅数据的自动匹配
 *
 *
 *
 *
 *  c --字符
 *  s --字符串
 *  d --整形
 *  f --float
 *  lf --double
 *
 *  s16 --最长16个字符
 *  d32 --int  d16 --short d8 --char
 *  ud --无符号整形
 */
/*
 * @Author: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @Date: 2024-05-17 21:00:27
 * @LastEditors: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @LastEditTime: 2024-05-18 15:38:44
 * @FilePath: \undefinedc:\Users\33368\Desktop\test.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <string.h>
#include <posix/string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <ctype.h>
#include "abus.h"
#include "abus_echo.h"

#pragma pack(1)
ABUS_DATA_TYPE_CREATE(
    uint64_t e;
    uint8_t b;
    uint16_t c;
    uint32_t d;
    int8_t f;
    int16_t g;
    int32_t h;
    int64_t i;

    float j;
    //    double k;
    , test_data_t);
#pragma pack()

// 函数用于找到 '{' 并返回其后面的部分
const char *find_struct_start(const char *str)
{
    const char *start = strchr(str, '{');
    return start ? start : str;
}
// 函数用于找到 '}' 并返回其后面的部分
char *find_struct_end(char *str)
{
    char *end = strrchr(str, '}');
    return end ? end + 1 : str;
}

void skip_whitespace(char **ptr)
{
    while (**ptr && isspace((unsigned char)**ptr))
    {
        (*ptr)++;
    }
}

// 函数定义
int find_any_substring(const char *str, int format, ...)
{

    va_list args;
    const char *substring;

    // 初始化可变参数列表
    va_start(args, format);

    // 遍历可变参数列表
    for (int i = 0; i < format; ++i)
    {
        substring = va_arg(args, const char *);
        if (substring == 0)
        {
            break;
        }
        // ABUS_HASH_PRINTF("in '%s'find '%s' \n", str,substring);
        if (strstr(str, substring))
        {
            va_end(args);
            // ABUS_HASH_PRINTF("in '%s'found '%s' \n", str,substring);
            return 1;
        }
    }

    // 清理可变参数列表
    va_end(args);
    return 0;
}

void printf_data(char *str, uint8_t **buf) __attribute__((optnone))
{
    BitArray bitArray;

    if (find_any_substring(str, 2, "int32_t ", "int "))
    {
        bitArray.i32 = *(int32_t *)(*buf);
        ABUS_HASH_PRINTF("%18s\t%d\n", str, bitArray.i32);
        TTOFFSET((*buf), int32_t);
    }
    else if (find_any_substring(str, 2, "int16_t ", "short"))
    {
        bitArray.i16 = *(int16_t *)(*buf);
        ABUS_HASH_PRINTF("%18s\t%d\n", str, bitArray.u16);
        TTOFFSET((*buf), int16_t);
    }
    else if (find_any_substring(str, 2, "int8_t ", "char"))
    {
        bitArray.i8 = *(int8_t *)(*buf);
        ABUS_HASH_PRINTF("%18s\t%d\n", str, bitArray.u8);
        TTOFFSET((*buf), int8_t);
    }
    else if (find_any_substring(str, 2, "uint64_t ", "unsigned long long"))
    {
        bitArray.u64 = *(uint64_t *)(*buf);
        ABUS_HASH_PRINTF("%18s\t%llu\n", str, bitArray.u64);
        TTOFFSET((*buf), uint64_t);
    }
    else if (find_any_substring(str, 2, "int64_t ", "long long"))
    {
        bitArray.i64 = *(int64_t *)(*buf);
        ABUS_HASH_PRINTF("%18s\t%llu\n", str, bitArray.u64);
        TTOFFSET((*buf), int64_t);
    }
    else if (find_any_substring(str, 2, "uint32_t ", "unsigned int", "int"))
    {
        bitArray.u32 = *(uint32_t *)(*buf);
        ABUS_HASH_PRINTF("%18s\t%u\n", str, bitArray.u32);
        TTOFFSET((*buf), uint32_t);
    }
    else if (find_any_substring(str, 2, "uint16_t ", "unsigned short", "short"))
    {
        bitArray.u16 = *(uint16_t *)(*buf);
        ABUS_HASH_PRINTF("%18s\t%u\n", str, bitArray.u16);
        TTOFFSET((*buf), uint16_t);
    }
    else if (find_any_substring(str, 2, "uint8_t", "unsigned char"))
    {
        bitArray.u8 = *(uint8_t *)(*buf);
        ABUS_HASH_PRINTF("%18s\t%u\n", str, bitArray.u8);
        TTOFFSET((*buf), uint8_t);
    }
    else if (find_any_substring(str, 2, "float", "f32"))
    {
        bitArray.f32 = *(float *)(*buf);
        ABUS_HASH_PRINTF("%18s\t%f\n", str, bitArray.f32);
        TTOFFSET((*buf), float);
    }
    else if (find_any_substring(str, 2, "double", "f64"))
    {
        bitArray.f64 = *(double *)(*buf);
        ABUS_HASH_PRINTF("%18s\t%f\n", str, bitArray.f64);
        TTOFFSET((*buf), double);
    }
}
void replace_char_in_place(char *src, char to_replace, char new_char)
{
    if (src == NULL)
        return;

    for (int i = 0; src[i] != '\0'; ++i)
    {
        if (src[i] == to_replace)
        {
            src[i] = new_char;
        }
    }
}

// 函数用于分割字符串并打印结果
void abus_echo_data_by_token(const char *str, void *buf)
{
    const char *start = find_struct_start(str) + 1; // 找到 '{' 开始的位置

    char *str_copy = strdup(start);        // 创建字符串的副本以避免修改原始字符串
    char *token = NULL, *last = NULL;      // last用于保存分割状态
    char *end = find_struct_end(str_copy); // 找到 '}' 开始的位置
    // uint8_t **buf_ptr = &buf;
    replace_char_in_place(end, ';', ':');
    ABUS_HASH_PRINTF("%s\n", end);
    *(--(end)) = '\0';

    token = strtok_r(str_copy, ";", &last); // 开始分割

    for (; token != NULL; token = strtok_r(NULL, ";", &last))
    {
        skip_whitespace(&token);
        // ABUS_HASH_PRINTF("%s\n", token); // 打印分割后的字符串
        printf_data(token, (uint8_t **)&buf);
    }

    free(str_copy); // 释放副本字符串的内存
}
void abus_type_show_fun_1(abus_topic_t *topic, void *data)
{
    if (topic->token)
    {
    }
    else
    {
    }
}
void abus_echo_by_name(const char *topic, int rate) // 创建一个订阅者，按照发布次数来打印数据
{
    abus_topic_t *top = abus_topic_find_by_name(topic);
    abus_echo(top, rate);
}
void abus_echo(abus_topic_t *topic, int rate)
{
    if (topic)
    {
        topic->show = abus_echo_data_by_token;
    }
    else
    {
        while (1)
            ;
    }
}
int abus_echo_test()
{
    test_data_t test_data = {
        .b = 255,
        .c = 33478,
        .d = 4,
        .e = 5,
        .f = 6,
        .g = 7,
        .h = 8,
        .i = 9999,
        .j = 10.456,
        //        .k = 1.5455678901,
    };
    // ABUS_HASH_PRINTF("%s\n", test_data_t_name);
    abus_echo_data_by_token(test_data_t_name, &test_data);

    return 0;
}