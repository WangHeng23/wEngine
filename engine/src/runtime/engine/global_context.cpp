#include "runtime/engine/global_context.hpp"

namespace wen {

GlobalContext* global_context = nullptr;

void GlobalContext::startup() {
    log_system.initialize(LogLevel::trace, LogLevel::trace);
    window_system.initialize(WindowCreateInfo());
    event_system.initialize();
    input_system.initialize();
}

void GlobalContext::shutdown() {
    input_system.destroy();
    event_system.destroy();
    window_system.destroy();
    log_system.destroy();
}

} // namespace wen