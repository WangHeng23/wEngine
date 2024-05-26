#include "runtime/function/window/window.hpp"
#include "runtime/core/base/macro.hpp"

namespace wen {

Window::Window(const WindowCreateInfo& createInfo) {
    std::string t = data_.title = createInfo.title;
    uint32_t w = data_.width = createInfo.width;
    uint32_t h = data_.height = createInfo.height;
    WEN_CORE_INFO("Create window: (\"{0}\", {1}, {2})", t, w, h)

    glfwSetErrorCallback([](int error, const char* description) {
        WEN_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    });

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window_ = glfwCreateWindow(static_cast<int>(w), static_cast<int>(h), t.c_str(), nullptr, nullptr);
}

Window::~Window() {
    glfwDestroyWindow(window_);
    window_ = nullptr;
    glfwTerminate();
}

void Window::pollEvents() {
    glfwPollEvents();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window_);
}

} // namespace wen