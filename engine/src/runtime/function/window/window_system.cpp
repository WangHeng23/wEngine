#include "runtime/function/window/window_system.hpp"

namespace wen {

WindowSystem::WindowSystem(const WindowCreateInfo& createInfo) {
    window_ = new Window(createInfo);
}

void WindowSystem::pollEvents() {
    Window::pollEvents();
}

bool WindowSystem::shouldClose() const {
    return window_->shouldClose();
}

WindowSystem::~WindowSystem() {
    if (window_) {
        delete window_;
        window_ = nullptr;
    }
}

} // namespace wen