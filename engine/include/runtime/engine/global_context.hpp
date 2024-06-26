#pragma once

#include "runtime/core/base/singleton.hpp"
#include "runtime/core/log/log_system.hpp"
#include "runtime/function/window/window_system.hpp"
#include "runtime/function/event/event_system.hpp"
#include "runtime/function/input/input_system.hpp"

namespace wen {

class GlobalContext {
public:
    void startup();
    void shutdown();

    Singleton<LogSystem> log_system;
    Singleton<WindowSystem> window_system;
    Singleton<EventSystem> event_system;
    Singleton<InputSystem> input_system;
};

extern GlobalContext* global_context;

} // namespace wen