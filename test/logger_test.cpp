/*!
 * @file logger_test.cpp
 *
 * @brief Logger unit test source file
 */

#include "logger/logger.hpp"
#include "gtest/gtest.h"

class LoggerTest: public ::testing::Test {
public:
    void SetUp() {
        logger = logger::Logger();
        logger.log();
    }

    void TearDown() {
        logger.total("[logger::LoggerTest::] total =");
    }

    logger::Logger logger;
};

TEST_F(LoggerTest, Log) {
    logger.log("[logger::LoggerTest::] elapsed time =");
}

TEST_F(LoggerTest, Bar) {
    for (std::uint32_t i = 0; i < 40; ++i) {
        logger.bar("[logger::LoggerTest::] elapsed time =");
    }
}
