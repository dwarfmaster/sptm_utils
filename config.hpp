
#ifndef DEF_CONFIG
#define DEF_CONFIG

#include <map>
#include <string>

class Config
{
    public:
        Config();
        ~Config();

        std::string operator[](const std::string& key) const;
        bool has(const std::string& key) const;
        /* Load from $HOME/.sptm_utils */
        bool load();

    private:
        std::map<std::string,std::string> m_values;
};

#endif

