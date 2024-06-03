#include "abus.h"
#include "rtdbg.h"
/* Compiler Related Definitions */
#include <rtthread.h>
/**
 * 将abus的命令对接到rtthread的msh

*/

// 需要完成
// topic 信息显示
// 列举所有topic
// 列举所有acc

void abus_cmd_topic(int argc, char **argv)
{
    if (argc == 2) // 没有参数，打印所有topics
    {
        abus_topic_show_all();

    }
    else if (argc == 3) // 一个参数，打印该topic的内容
    {
        const char *requested_topic_name = argv[2];
        abus_topic_show(requested_topic_name);
    }
    else
    {
        LOG_RAW("Invalid number of arguments. Use 'abus topic' for all topics or 'abus topic <topic>' for a specific topic.\n");
    }
}

void abus_cmd_acc(int argc, char **argv)
{
    if (argc == 2) // 没有参数，打印所有topics
    {
        abus_acc_show_all();

    }
    else if (argc == 3) // 一个参数，打印该topic的内容
    {
        const char *requested_topic_name = argv[2];
        abus_topic_show(requested_topic_name);
    }
    else
    {
        LOG_RAW("Invalid number of arguments. Use 'abus acc' for all acc or 'abus acc <acc>' for a specific acc.\n");
    }
}

void abus_cmd_echo(int argc, char **argv)
{
    if (argc == 2) // 没有参数，打印所有accs
    {
        abus_topic_show_all();

    }
    else if (argc == 3) // 一个参数，打印该acc的内容
    {
        const char *requested_acc_name = argv[2];
        abus_acc_show(requested_acc_name);
    }
    else
    {
        LOG_RAW("Invalid number of arguments. Use 'abus acc' for all acc or 'abus acc <acc>' for a specific acc.\n");
    }
}
enum
{
    ABUS_OPT_TOPIC = 1U,
    ABUS_OPT_ACC,
    ABUS_OPT_ECHO,
};
CMD_OPTIONS_STATEMENT(cmd_abus_list)
static int cmd_abus_list(int argc, char **argv)
{
    if (argc >= 2)
    {
        switch (MSH_OPT_ID_GET(cmd_abus_list))
        {
        case ABUS_OPT_TOPIC:
            abus_cmd_topic(argc, argv);
            break;
        case ABUS_OPT_ACC:
            abus_cmd_acc(argc, argv);
            break;
        case ABUS_OPT_ECHO:
            abus_cmd_echo(argc, argv);
            break;
        default:
            goto _usage;
        };
        return 0;
    }

_usage:
    LOG_RAW("Usage: m [options]\n");
    LOG_RAW("[options]:\n");
    MSH_OPT_DUMP(cmd_abus_list);
    return 0;
}

CMD_OPTIONS_NODE_START(cmd_abus_list)
CMD_OPTIONS_NODE(ABUS_OPT_TOPIC, topic, list all motor id)
CMD_OPTIONS_NODE(ABUS_OPT_ACC, acc, set or get torque)
CMD_OPTIONS_NODE(ABUS_OPT_ECHO, echo, set or get speed)
CMD_OPTIONS_NODE_END

MSH_CMD_EXPORT_ALIAS(cmd_abus_list, abus, abus operate cmd, optenable);
