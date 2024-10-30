#include "config_parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

ConfigParser::ConfigParser(const std::string &configFile) : configFilePath(configFile) {}

bool ConfigParser::loadConfig()
{
    std::ifstream file(configFilePath);
    if (!file.is_open())
    {
        std::cerr << "Unable to open config file: " << configFilePath << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string key, value;

        if (std::getline(ss, key, '=') && std::getline(ss, value))
        {
            configData[key] = value;
        }
    }

    file.close();
    return true;
}

std::string ConfigParser::getValue(const std::string &key, const std::string &defaultValue) const
{
    auto it = configData.find(key);
    if (it != configData.end())
    {
        return it->second;
    }
    return defaultValue;
}
