#pragma once

#include <spdlog/spdlog.h>
#include <cstdint>

namespace wen {

enum class LogLevel : uint8_t { trace, debug, info, warn, error, fatal };

class Logger final {
public:
    Logger(const std::string& name, const LogLevel& level);
    ~Logger();

    void setLevel(const LogLevel& level) const;

    template <typename... Args>
    void log(const LogLevel level, Args&&... args) {
        switch (level) {
            case LogLevel::trace:
                logger_->trace(std::forward<Args>(args)...); break;
            case LogLevel::debug:
                logger_->debug(std::forward<Args>(args)...); break;
            case LogLevel::info:
                logger_->info(std::forward<Args>(args)...); break;
            case LogLevel::warn:
                logger_->warn(std::forward<Args>(args)...); break;
            case LogLevel::error:
                logger_->error(std::forward<Args>(args)...); break;
            case LogLevel::fatal:
                logger_->critical(std::forward<Args>(args)...); break;
            default: break;
        }
    }

private:
    std::shared_ptr<spdlog::logger> logger_;
};

extern Logger* core_logger;
extern Logger* client_logger;

} // namespace wen

#define WEN_CORE_LOG_HELPER(level, ...) core_logger->log(level, "[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__);
#define WEN_CLIENT_LOG_HELPER(level, ...) client_logger->log(level, "[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__);