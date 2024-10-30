#include "gbr_daemon.h"

int main()
{
    // 创建GBRDaemon对象并初始化
    GBRDaemon daemon("config/gbr_d.conf");
    if (!daemon.initialize())
    {
        return -1;
    }

    // 启动和停止守护进程
    daemon.start();
    // 在真实应用中可以等待信号、监听事件等
    daemon.stop();

    return 0;
}
