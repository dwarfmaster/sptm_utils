
#include "config.hpp"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

Config::Config()
{}

Config::~Config()
{}

std::string Config::operator[](const std::string& key) const
{
    auto it = m_values.find(key);
    if(it == m_values.end())
        return "";
    else
        return it->second;
}

bool Config::has(const std::string& key) const
{
    return m_values.find(key) != m_values.end();
}

bool Config::load()
{
    /* Opening the file. */
    std::string path = std::getenv("HOME");
    path += "/.sptm_utils";
    std::ifstream ifs(path.c_str());
    if(!ifs) {
        std::cerr << "Couldn't open \"" << path << "\"." << std::endl;
        return false;
    }

    /* Parsing it. */
    std::string line;
    while(std::getline(ifs, line)) {
        if(line.empty() || line[0] == '#')
            continue;
        std::istringstream iss(line);
        std::string key;
        std::getline(iss, key, ' ');
        std::string value;
        std::getline(iss, value);
        m_values[key] = value;
    }

    return true;
}

