#pragma once

// LogLevels:
//          Nothing: 0
//          Error: 1+
//          Warning: 2+
//          Success: 3+
//          Info: 4+


//#if defined(__GNUC__) || defined(__GNUG__) // Using g++
#include <experimental/filesystem>
//#elif defined(_MSC_VER) // Using MSVC
//#include <filesystem>
//#endif

#include <fstream>
#include <iostream>
#include <cstdio>

#ifdef _WIN32
#define USE_WINDOWS
#include <windows.h> // console color
#endif // _WIN32


//#if defined(__GNUC__) || defined(__GNUG__) // Using g++
namespace fs = std::experimental::filesystem::v1;
//#elif defined(_MSC_VER) // Using MSVC
//namespace fs = std::filesystem;
//#endif

namespace esfe
{

enum LoggerMode { MONO_FILE, MULTI_FILES, CONSOLE };
// MONO_FILE : Re-write logs in one file
// MULTI_FILES : Create multiple logs in one directory (log1.log, log2.log, etc.)
// CONSOLE : Log to console

class Logger
{
public:
    /** Default constructor */
// TODO: override constructor depending on mode
// EG: not path for console mode, etc.
    Logger ( std::string name, LoggerMode mode,
             int level=4,
             std::string filePath="log.txt",
             std::string folderPath="logs"
           );

    /** Default destructor */
    virtual ~Logger ( );

    void error   ( std::string message, int id=0 );
    void success ( std::string message, int id=0 );
    void info    ( std::string message, int id=0 );
    void warning ( std::string message, int id=0 );

    // void log(); // for direct logging -> should be called to simplify the other's code

    void setLevel ( int level );
    int  getLevel ( );

private:
    std::string m_name;
    LoggerMode  m_mode;

    int m_level; // log level

    std::ofstream m_file;

#ifdef USE_WINDOWS
    HANDLE hConsole;
    // https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
#endif  // USE_WINDOWS

};

}  // namespace esfe
