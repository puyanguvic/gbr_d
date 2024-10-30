#pragma once
#include <string>
#include <map>

class ConfigParser
{
public:
    ConfigParser(const std::string &configFile);
    bool loadConfig();
    std::string getValue(const std::string &key, const std::string &defaultValue = "") const;

private:
    std::string configFilePath;
    std::map<std::string, std::string> configData;
};
