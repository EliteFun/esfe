#ifndef ESFE_ARG_PARSER_HPP
#define ESFE_ARG_PARSER_HPP

#define TEST

#include <string>
#include <map>

namespace esfe
{

class TEST ArgParser
{
public:
    /** Default constructor */
    ArgParser();
    
    void addArgument();
    void addSwitch(std::string _key, std::string key);
    
    // Future: parse env
    
    void parse(int argc, char* argv[], char* envp[]);

private:
};

}

#endif // ESFE_ARG_PARSER_HPP
