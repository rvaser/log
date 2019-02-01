/*!
 * @file bioparser.hpp
 *
 * @brief Bioparser header file
 */

#pragma once

namespace log {

std::unique_ptr<Logger> createLogger();

class Logger {
public:
    ~Logger();

private:
    Logger();
    Logger(const Logger&) = delete;
    const Logger& operator=(const Logger&) = delete;
};

std::unique_ptr<Logger> createLogger() {
    return std::unique_ptr<Logger>(new Logger());
}

Logger::Logger() {
}

Logger::~Logger() {
}

}
