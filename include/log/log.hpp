/*!
 * @file log.hpp
 *
 * @brief Log header file
 */

#pragma once

#include <stdio.h>
#include <stdint.h>
#include <chrono>
#include <string>

namespace log {

class Logger {
public:

    Logger();

    /*!
     * @brief Prints the total elapsed time to stderr
     */
    ~Logger();

    /*!
     * @brief Resets the time point
     */
    void operator()();

    /*!
     * @brief Prints the elapsed time from last time point to stderr
     */
    void operator()(const std::string& s) const;

    /*!
     * @brief Prints a progress bar with the elapsed time from last time point to stderr
     */
    void operator[](const std::string& s);
private:
    Logger(const Logger&) = delete;
    const Logger& operator=(const Logger&) = delete;

    double time_;
    uint32_t bar_;
    std::chrono::time_point<std::chrono::steady_clock> time_point_;
};

Logger::Logger()
        : time_(0.), bar_(0), time_point_(std::chrono::steady_clock::now()) {
}

Logger::~Logger() {
    fprintf(stderr, "[~] total time = %.2lf s\n", time_ +
        std::chrono::duration_cast<std::chrono::duration<double>>(
            std::chrono::steady_clock::now() - time_point_).count());
}

void Logger::operator()() {
    auto new_point = std::chrono::steady_clock::now();
    time_ += std::chrono::duration_cast<std::chrono::duration<double>>(
        new_point - time_point_).count();
    time_point_ = new_point;
}

void Logger::operator()(const std::string& s) const {
    fprintf(stderr, "[%s] elapsed time = %.2lf s\n", s.c_str(),
        std::chrono::duration_cast<std::chrono::duration<double>>(
        std::chrono::steady_clock::now() - time_point_).count());
}

void Logger::operator[](const std::string& s) {
    ++bar_;
    std::string progress_bar = std::string(bar_, '=') + ">";
    fprintf(stderr, "[%s] [%-20.20s] elapsed time = %.2lf s", s.c_str(),
        progress_bar.c_str(),
        std::chrono::duration_cast<std::chrono::duration<double>>(
        std::chrono::steady_clock::now() - time_point_).count());
    bar_ %= 20;
    fprintf(stderr, bar_ == 0 ? "\n" : "\r");
}

}