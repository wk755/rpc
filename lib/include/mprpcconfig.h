#pragma once

#include <unordered_map>
#include <string>

//框架读取配置文件
class MprpcConfig
{
public:
    //负责解析加载配置文件
    void LoadConfigFile(const char *config_file);
    //查询配置项信息
    std::string Load(const std::string &key);
    //去掉空格
    void Trim(std::string &src_buf);

private:
    std::unordered_map<std::string, std::string> m_configMap;
};
