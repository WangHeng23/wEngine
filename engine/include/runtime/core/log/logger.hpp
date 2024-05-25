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

#define WEN_ENGINE_CORE_TRACE(...) WEN_CORE_LOG_HELPER(wen::LogLevel::trace, __VA_ARGS__)
#define WEN_ENGINE_CORE_DEBUG(...) WEN_CORE_LOG_HELPER(wen::LogLevel::debug, __VA_ARGS__)
#define WEN_ENGINE_CORE_INFO(...)  WEN_CORE_LOG_HELPER(wen::LogLevel::info,  __VA_ARGS__)
#define WEN_ENGINE_CORE_WARN(...)  WEN_CORE_LOG_HELPER(wen::LogLevel::warn,  __VA_ARGS__)
#define WEN_ENGINE_CORE_ERROR(...) WEN_CORE_LOG_HELPER(wen::LogLevel::error, __VA_ARGS__)
#define WEN_ENGINE_CORE_FATAL(...) WEN_CORE_LOG_HELPER(wen::LogLevel::fatal, __VA_ARGS__)

#define WEN_ENGINE_CLIENT_TRACE(...) WEN_CLIENT_LOG_HELPER(wen::LogLevel::trace, __VA_ARGS__)
#define WEN_ENGINE_CLIENT_DEBUG(...) WEN_CLIENT_LOG_HELPER(wen::LogLevel::debug, __VA_ARGS__)
#define WEN_ENGINE_CLIENT_INFO(...)  WEN_CLIENT_LOG_HELPER(wen::LogLevel::info,  __VA_ARGS__)
#define WEN_ENGINE_CLIENT_WARN(...)  WEN_CLIENT_LOG_HELPER(wen::LogLevel::warn,  __VA_ARGS__)
#define WEN_ENGINE_CLIENT_ERROR(...) WEN_CLIENT_LOG_HELPER(wen::LogLevel::error, __VA_ARGS__)
#define WEN_ENGINE_CLIENT_FATAL(...) WEN_CLIENT_LOG_HELPER(wen::LogLevel::fatal, __VA_ARGS__)

#define WEN_ENGINE_CORE_ASSERT(x, ...)                               \
    if (!(x)) {                                                      \
        WEN_ENGINE_CORE_FATAL("Assertion Failed: {0}", __VA_ARGS__); \
        std::abort();                                                \
    }

#define WEN_ENGINE_CLIENT_ASSERT(x, ...)                               \
    if (!(x)) {                                                        \
        WEN_ENGINE_CLIENT_FATAL("Assertion Failed: {0}", __VA_ARGS__); \
        std::abort();                                                  \
    }
