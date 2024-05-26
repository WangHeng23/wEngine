#pragma once

#include "runtime/core/base/macro.hpp"
#include "runtime/function/window/window.hpp"

namespace wen {

class WindowSystem final {
    WEN_DECLARE_SINGLETON(WindowSystem, const WindowCreateInfo& createInfo)

public:
    static void pollEvents();
    [[nodiscard]] bool shouldClose() const;

    [[nodiscard]] Window* getRuntimeWindow() const { return window_; }

private:
    Window* window_;
};

} // namespace wen