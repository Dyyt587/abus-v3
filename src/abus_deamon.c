#include "abus.h"
#include "abus_deamon.h"
#include "abus_osal.h"


//


typedef struct{
    uint8_t flag;//0:表示本地广播 1：表示向远程数据发送 
    const char* topic_name;//发布/接收到达的主题的名字
    uint32_t data_size;
    uint8_t data[0];
}abus_agent_data_t;
/*deamon线程用于发布代理数据，多传感器分布式传输*/
void* abus_deamon_entry(void* arg)
{
    while(1)
    {
        printf("abus_agent_data_t size is %zd\n",sizeof(abus_agent_data_t));
        abus_os_delay(1);
    }
}
void abus_deamon_start(void)
{
    static abus_thread_t abus_deamon_thread;
    printf("abus_deamon_start\n");
    abus_thread_create(&abus_deamon_thread,  abus_deamon_entry,NULL );
}







