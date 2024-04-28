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
#include "abus.h"
#include "alist.h"

using namespace std;
typedef struct {
	int cnt;
}test_data_t;

abus_filter filter1;
abus_filter filter2;
abus_filter filter3;
int abus_subcribe_cb1(abus_subcriber_t *subcriber, void *data)
{
	test_data_t* data1 = (test_data_t*)data;
	printf("data cnt %d\n", data1->cnt);
	return 0;
}

test_data_t test_data1;

#define ABUS_TOPIC_CREATE(__topic,__dat_type,__hashSize){abus_topic_cfg ABUS_TOPIC_CGF##__dat_type={\
		.hash_table_size = __hashSize,\
.topic_data_size = sizeof(__dat_type),\
};\
	abus_topic_create(__topic, &ABUS_TOPIC_CGF##__dat_type, #__dat_type);\
}

#define ABUS_ACC_CREATE(__acc,__filter){\
abus_accounter_create(__acc, __filter);\
}

#define ABUS_SUB(__acc,__topic,_fifoSize,__cb,__filter_gloab){abus_subcribe_cfg_t _SBU_CFG__topic={\
	.fifo = _fifoSize,\
	.filter =__filter_gloab,\
	.cb = __cb,\
};\
abus_subcribe(__topic, __acc, &_SBU_CFG__topic);}

/*
查找用户如果没有就创建一个进行订阅
*/
#define ABUS_SUB_FORCE(__acc,__topic,_fifoSize,__cb,__filter_gloab,__filter_acc){abus_subcribe_cfg_t ___SUB__topic={\
	.fifo = _fifoSize,\
	.filter =__filter_gloab,\
	.cb = __cb,\
};\
if(abus_accounter_find_by_name(__acc)){\
	abus_subcribe(__topic, __acc, &___SUB__topic);\
}else{\
	ABUS_ACC_CREATE(__acc,__filter_acc);\
	abus_subcribe(__topic, __acc,&___SUB__topic); \
}}


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
		.topic_data_size =sizeof(test_data_t),
	};
	abus_topic_t *topic1 = abus_topic_create("topic1", &cfg, "just a desc");
	abus_topic_t *topic2 = abus_topic_create("topic2", &cfg, "just a desc2");
	std::cout << "sub start" << endl;
	abus_subcribe_cfg_t cfg_sub = {
		.fifo = NULL,
		.filter = &filter1,
		.cb = abus_subcribe_cb1,
	};

	abus_subcribe("topic1", "acc1", &cfg_sub);
	abus_subcribe("topic1", "acc2", &cfg_sub);
	abus_subcribe("topic1", "acc3", &cfg_sub);
	abus_subcribe("topicnull", "acc1", &cfg_sub);

	test_data1.cnt = 10;
	abus_publish("topic1",&test_data1);


	std::cout << "Hello CMake." << endl;

	ABUS_TOPIC_CREATE("topicmicro", test_data_t, 16);

	ABUS_SUB("acc1", "topic1", 0, abus_subcribe_cb1, NULL);

	ABUS_SUB_FORCE("accnull", "topic1", 0, abus_subcribe_cb1, NULL, NULL);
	std::cout << "Hello CMake." << endl;

	abus_topic_show("topicmicro");
	return 0;
}
