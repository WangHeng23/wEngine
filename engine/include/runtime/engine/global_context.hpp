#pragma once

#include "runtime/core/base/singleton.hpp"
#include "runtime/core/log/log_system.hpp"
#include "runtime/function/window/window_system.hpp"

namespace wen {

class GlobalContext {
public:
    void startup();
    void shutdown();

    Singleton<LogSystem> log_system;
    Singleton<WindowSystem> window_system;
};

extern GlobalContext* global_context;

} // namespace wen