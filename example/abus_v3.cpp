/*
 * @Author: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @Date: 2024-04-15 11:28:27
 * @LastEditors: Dyyt587 67887002+Dyyt587@users.noreply.github.com
 * @LastEditTime: 2024-04-23 16:52:32
 * @FilePath: \abus-v3\abus_v3\abus_v3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// abus_v3.cpp: 定义应用程序的入口点。
//

#include "abus_v3.h"
#include "../src/abus.h"
#include "../src/abus_deamon.h"
#include "../src/alist.h"
#include "../src/abus_cplusplus.h"

typedef struct
{
	int cnt;
} test_data_t;

abus_filter filter1;
abus_filter filter2;
abus_filter filter3;
int abus_subcribe_cb1(abus_subcriber_t *subcriber, void *data)
{
	test_data_t *data1 = (test_data_t *)data;
	printf("sub %s data cnt %d\n", subcriber->acc->name, data1->cnt);
	return 0;
}

test_data_t test_data1;


// void *mypthreadFunction1(void*e)
// {
// 	printf("thread1 start\n");
// 	while(1){
// 		sleep(1);
// 		printf("thread1 loop\n");
// 	}

// }
/*
"acc1 -sub top1 -f 4096 - "
*/
int main()
{
	// 创建一个用户
	abus_acc_t *acc1 = abus_accounter_create("acc1", &filter1);
	abus_acc_t *acc2 = abus_accounter_create("acc2", &filter2);
	abus_acc_t *acc3 = abus_accounter_create("acc3", &filter3);
	// 创建话题
	abus_topic_cfg cfg = {
		.hash_table_size = 16,
		.topic_data_size = sizeof(test_data_t),
	};
	abus_topic_t *topic1 = abus_topic_create("topic1", &cfg, "just a desc");
	abus_topic_t *topic2 = abus_topic_create("topic2", &cfg, "just a desc2");
	printf("sub start\n");
	abus_subcribe_cfg_t cfg_sub = {
		.fifo = NULL,
		.filter = &filter1,
		.cb = abus_subcribe_cb1,
		.is_async = 0,
		.sem = NULL,
	};

	// abus_subcribe("topic1", "acc1", &cfg_sub);
	abus_subcribe("topic1", "acc2", &cfg_sub);
	abus_subcribe("topic1", "acc3", &cfg_sub);
	abus_subcribe("topicnull", "acc1", &cfg_sub);

	test_data1.cnt = 10;
	abus_publish("topic1", &test_data1);

	printf("Hello CMake.\n");

	ABUS_TOPIC_CREATE("topicmicro", test_data_t, 16);

	// ABUS_SUB("acc1", "topic1", 0, abus_subcribe_cb1, NULL);

	ABUS_SUB_FORCE("accnull", "topic1", 0, abus_subcribe_cb1, NULL, NULL);
	printf("Hello CMake.\n");
	ABUS_SUB("acc1", "topicmicro", 0, abus_subcribe_cb1, NULL);
	ABUS_SUB("acc2", "topicmicro", 0, abus_subcribe_cb1, NULL);
	abus_publish("topicmicro", &test_data1);
	abus_publish("topicmicro", &test_data1);

	abus_topic_show("topic1");

	abus_sem_t sem1;
	abus_subcribe_cfg_t cfg_sub1 = {
		.fifo = NULL,
		.filter = &filter1,
		.cb = NULL,
		.is_async = 1,
		.sem = &sem1,
	};

	abus_subcribe("topic1", "acc1", &cfg_sub1);
	abus_topic_show("topic1");

	abus_publish("topic1", &test_data1);

abus_deamon_start();
	// test(0.0);
	// pthread_t tid;
	// pthread_create(&tid, NULL, mypthreadFunction1, NULL);
	while(1)
	{
		abus_os_delay(10);
	}
	return 0;
}
