/*!
 * @file logger.hpp
 *
 * @brief Logger header file
 */

#pragma once

#include <stdio.h>
#include <stdint.h>
#include <chrono>
#include <string>
#include <memory>

namespace logger {

class Logger;
std::unique_ptr<Logger> createLogger();

class Logger {
public:

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
     * @brief Prints a progress bar and the elapsed time from last time to
     * stderr (the progress bar resets after 20 calls)
     */
    void operator[](const std::string& s);

    /*!
     * @brief Prints the total elapsed time so far to stderr
     */
    void total(const std::string& s) const;

    friend std::unique_ptr<Logger> createLogger();
private:
    Logger();
    Logger(const Logger&) = delete;
    const Logger& operator=(const Logger&) = delete;

    double time_;
    uint32_t bar_;
    std::chrono::time_point<std::chrono::steady_clock> time_point_;
};

std::unique_ptr<Logger> createLogger() {
    return std::unique_ptr<Logger>(new Logger());
}

Logger::Logger()
        : time_(0.), bar_(0), time_point_(std::chrono::steady_clock::now()) {
}

Logger::~Logger() {
}

void Logger::operator()() {
    auto new_point = std::chrono::steady_clock::now();
    time_ += std::chrono::duration_cast<std::chrono::duration<double>>(
        new_point - time_point_).count();
    time_point_ = new_point;
}

void Logger::operator()(const std::string& s) const {
    fprintf(stderr, "%s real: %.3lf s\n", s.c_str(),
        std::chrono::duration_cast<std::chrono::duration<double>>(
        std::chrono::steady_clock::now() - time_point_).count());
}

void Logger::operator[](const std::string& s) {
    ++bar_;
    std::string progress_bar = std::string(bar_, '=') + ">";
    fprintf(stderr, "%s [%-20.20s] real: %.3lf s", s.c_str(),
        progress_bar.c_str(),
        std::chrono::duration_cast<std::chrono::duration<double>>(
        std::chrono::steady_clock::now() - time_point_).count());
    bar_ %= 20;
    fprintf(stderr, bar_ == 0 ? "\n" : "\r");
}

void Logger::total(const std::string& s) const {
    fprintf(stderr, "%s real: %.3lf s\n", s.c_str(),
        time_ + std::chrono::duration_cast<std::chrono::duration<double>>(
        std::chrono::steady_clock::now() - time_point_).count());
}

}
