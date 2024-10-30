#pragma once
#include <string>
#include "config_parser.h"

class GBRDaemon
{
public:
    GBRDaemon(const std::string &configFile);
    bool initialize();
    void start();
    void stop();

private:
    ConfigParser config;
    std::string logLevel;
    int maxNeighbors;
    int bufferSize;
    bool isRunning;
};
