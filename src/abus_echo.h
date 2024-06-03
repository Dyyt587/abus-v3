/*
 * @Author: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @Date: 2024-05-17 16:29:06
 * @LastEditors: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @LastEditTime: 2024-05-22 19:14:09
 * @FilePath: \project\applications\abus_v3\src\abus_echo.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef ABUS_ECHO_H
#define ABUS_ECHO_H

#include "abus.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef union
{
    uint8_t u8;
    int8_t i8;
    uint16_t u16;
    int16_t i16;
    uint32_t u32;
    int32_t i32;
    uint64_t u64;
    int64_t i64;

    float f32;
    double f64;
    char *str;
} BitArray;

#define TOSTR(x) #x
#define TTOFFSET(src, offsetof) src += sizeof(offsetof);

#define ABUS_DATA_TYPE_CREATE(__type_data__,__struct_name__)  \
    typedef struct{ __type_data__ } __struct_name__; static const char* __struct_name__##_name = TOSTR(typedef struct{ __type_data__ }__struct_name__;);

#define ABUS_ECHO_EXPORT(__TOPIC__,__struct_name__)  __TOPIC__.token = __struct_name__##_name;


#ifdef __cplusplus
}
#endif
#endif
