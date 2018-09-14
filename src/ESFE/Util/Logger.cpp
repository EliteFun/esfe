#include "ESFE\Util\Logger.hpp"

namespace esfe
{
Logger::Logger ( std::string name,
                    LoggerMode mode,
                    int level, std::string filePath,
                    std::string folderPath
                )
{
    m_name  = name;
    m_mode  = mode;
    m_level = level;

    int log_number;

    std::string t_fileName;

    switch (mode)
    { // mode specific initialization
    case LoggerMode::CONSOLE:
#ifdef USE_WINDOWS
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // USE_WINDOWS
        break;
    case LoggerMode::MONO_FILE:
        m_file.open(filePath);
        break;
    case LoggerMode::MULTI_FILES:
        for ( auto & logs : fs::directory_iterator(folderPath))
        {
            if (fs::is_regular_file(logs.status()))
            { // assuming there are only logs from 1 to 9 in the directory
                log_number = ((fs::path) logs).stem().string().back()-'0'+1;
                if (log_number == 10)
                {
                    for (auto & p : fs::directory_iterator(folderPath))
                    {
                        std::remove(((fs::path)p).string().c_str());
                    }
                    log_number = 0;
                }
            }
        }
        m_file.open(std::string("logs\\log" + std::to_string(log_number)));
        break;
    default: // error
        break;
    }
}

Logger::~Logger()
{
    m_file.close();
}

void Logger::error(std::string message, int id)
{
    if (m_level >= 1)
    {
        switch (m_mode)
        {
        case LoggerMode::CONSOLE:
#ifdef USE_WINDOWS
            SetConsoleTextAttribute(hConsole, 4);
#endif // USE_WINDOWS
            std::cout << "[" << m_name << "] Error (" << id << "): "
                        << message << std::endl;
#ifdef USE_WINDOWS
            SetConsoleTextAttribute(hConsole, 15);
#endif // USE_WINDOWS
            break;
        case LoggerMode::MONO_FILE:
            m_file << "[" << m_name << "] Error (" << id << "): "
                    << message << std::endl;
            break;
        case LoggerMode::MULTI_FILES:
            m_file << "[" << m_name << "] Error (" << id << "): "
                    << message << std::endl;
            break;
        default: // error
            break;
        }
    }
}

void Logger::success(std::string message, int id)
{ // COLOR: GREEN
    if (m_level >= 3)
    {
        switch (m_mode)
        {
        case LoggerMode::CONSOLE:
#ifdef USE_WINDOWS
            SetConsoleTextAttribute(hConsole, 2);
#endif // USE_WINDOWS
            std::cout << "[" << m_name << "] Success (" << id << "): "
                        << message << std::endl;
#ifdef USE_WINDOWS
            SetConsoleTextAttribute(hConsole, 15);
#endif // USE_WINDOWS
            break;
        case LoggerMode::MONO_FILE:
            m_file << "[" << m_name << "] Success (" << id << "): "
                    << message << std::endl;
            break;
        case LoggerMode::MULTI_FILES:
            m_file << "[" << m_name << "] Success (" << id << "): "
                    << message << std::endl;
            break;
        default: // error
            break;
        }
    }
}

void Logger::info(std::string message, int id)
{ // COLOR: NORMAL WHITE
    if (m_level >= 4)
    {
        switch (m_mode)
        {
        case LoggerMode::CONSOLE:
#ifdef USE_WINDOWS
            SetConsoleTextAttribute(hConsole, 15);
#endif // USE_WINDOWS
            std::cout << "[" << m_name << "] Info (" << id << "): "
                        << message << std::endl;
#ifdef USE_WINDOWS
            SetConsoleTextAttribute(hConsole, 15);
#endif // USE_WINDOWS
            break;
        case LoggerMode::MONO_FILE:
            m_file << "[" << m_name << "] Info (" << id << "): "
                    << message << std::endl;
            break;
        case LoggerMode::MULTI_FILES:
            m_file << "[" << m_name << "] Info (" << id << "): "
                    << message << std::endl;
            break;
        default: // error
            break;
        }
    }
}

void Logger::warning(std::string message, int id)
{ // COLOR: YELLOW
    switch (m_mode)
    {
    case LoggerMode::CONSOLE:
#ifdef USE_WINDOWS
        SetConsoleTextAttribute(hConsole, 6);
#endif // USE_WINDOWS
        std::cout << "[" << m_name << "] Warning (" << id << "): "
                    << message << std::endl;
#ifdef USE_WINDOWS
        SetConsoleTextAttribute(hConsole, 15);
#endif // USE_WINDOWS
        break;
    case LoggerMode::MONO_FILE:
        m_file << "[" << m_name << "] Warning (" << id << "): "
                << message << std::endl;
        break;
    case LoggerMode::MULTI_FILES:
        m_file << "[" << m_name << "] Warning (" << id << "): "
                << message << std::endl;
        break;
    default: // error
        break;
    }
}

void Logger::setLevel(int level)
{
    m_level = level;
}

int Logger::getLevel()
{
    return m_level;
}
}
