#ifndef Rufbereitschaftstool_CONFIG_H
#define Rufbereitschaftstool_CONFIG_H

#include <tnt/tntconfig.h>

namespace Rufbereitschaftstool
{
class Config : public tnt::TntConfig
{
    friend void operator>>= (const cxxtools::SerializationInfo& si, Config& config);

    std::string _htdocs;
    std::string _dburl;

public:
    Config();
    const std::string& htdocs() const     { return _htdocs; }
    const std::string& dburl() const      { return _dburl; }

    static const Config& it();
};

}

#endif
