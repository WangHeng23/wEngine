#pragma once

#include "runtime/core/base/macro.hpp"
#include "runtime/core/log/logger.hpp"

namespace wen {

class LogSystem final {
    WEN_DECLARE_SINGLETON(LogSystem, const LogLevel& core_level, const LogLevel& client_level)

public:
    auto createLogger(const std::string& name, LogLevel level) -> Logger*;

    static void setCoreLevel(const LogLevel& level) { core_logger->setLevel(level); }
    static void setClientLevel(const LogLevel& level) { client_logger->setLevel(level); }

private:
    std::vector<std::unique_ptr<Logger>> loggers_;
};

} // namespace wen