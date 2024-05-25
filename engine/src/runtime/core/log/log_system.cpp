#include "runtime/core/log/log_system.hpp"

namespace wen {

Logger* core_logger = nullptr;
Logger* client_logger = nullptr;

auto LogSystem::createLogger(const std::string& name, LogLevel level) -> Logger* {
    loggers_.emplace_back(std::make_unique<Logger>(name, level));
    return loggers_.back().get();
}

LogSystem::LogSystem(const LogLevel& core_level, const LogLevel& client_level) {
    core_logger = createLogger("core", core_level);
    client_logger = createLogger("client", client_level);
}

LogSystem::~LogSystem() {
    core_logger = nullptr;
    client_logger = nullptr;
    for (auto& logger : loggers_) {
        logger.reset();
    }
    loggers_.clear();
    spdlog::shutdown();
}

} // namespace wen