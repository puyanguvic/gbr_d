#include "gbr_daemon.h"
#include <iostream>

GBRDaemon::GBRDaemon(const std::string &configFile) : config(configFile), isRunning(false) {}

bool GBRDaemon::initialize()
{
    // 加载配置文件
    if (!config.loadConfig())
    {
        std::cerr << "Failed to load config file." << std::endl;
        return false;
    }

    // 读取配置项
    logLevel = config.getValue("log_level", "INFO");
    maxNeighbors = std::stoi(config.getValue("max_neighbors", "10"));
    bufferSize = std::stoi(config.getValue("buffer_size", "1024"));

    std::cout << "Configuration loaded:" << std::endl;
    std::cout << "Log Level: " << logLevel << std::endl;
    std::cout << "Max Neighbors: " << maxNeighbors << std::endl;
    std::cout << "Buffer Size: " << bufferSize << std::endl;

    return true;
}

void GBRDaemon::start()
{
    if (!isRunning)
    {
        std::cout << "Starting GBRDaemon..." << std::endl;
        isRunning = true;
        // 这里可以添加启动逻辑，如启动线程、初始化资源等
    }
    else
    {
        std::cout << "GBRDaemon is already running." << std::endl;
    }
}

void GBRDaemon::stop()
{
    if (isRunning)
    {
        std::cout << "Stopping GBRDaemon..." << std::endl;
        isRunning = false;
        // 这里可以添加停止逻辑，如释放资源、停止线程等
    }
    else
    {
        std::cout << "GBRDaemon is not running." << std::endl;
    }
}
