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
abus_filter filter1;
abus_filter filter2;
abus_filter filter3;
int abus_subcribe_cb1(abus_subcriber_t *subcriber, void *data)
{

	return 0;
}

int main()
{
	// 创建一个用户
	abus_acc_t *acc1 = abus_accounter_create("acc1", &filter1);
	abus_acc_t *acc2 = abus_accounter_create("acc2", &filter2);
	abus_acc_t *acc3 = abus_accounter_create("acc3", &filter3);
	// 创建话题
	abus_topic_cfg cfg = {
		.is_using_hash = true,
		.hash_table_size = 16,
	};
	abus_topic_t *topic1 = abus_topic_create("topic1", &cfg, "just a desc");
	abus_topic_t *topic2 = abus_topic_create("topic2", &cfg, "just a desc");
	cout << "sub start" << endl;

	//abus_subcribe("topic1", "acc1", &filter1, abus_subcribe_cb1);
	abus_subcribe("topicNULL", "acc1", &filter1, abus_subcribe_cb1);

	cout << "Hello CMake." << endl;
	return 0;
}
