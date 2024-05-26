#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace wen {

struct WindowCreateInfo {
    std::string title;
    uint32_t width;
    uint32_t height;

    WindowCreateInfo(std::string title = "wen", uint32_t width = 1600, uint32_t height = 900)
        : title(std::move(title)), width(width), height(height) {}
};

class Window final {
public:
    Window(const WindowCreateInfo& createInfo);
    ~Window();

    static void pollEvents();
    [[nodiscard]] bool shouldClose() const;

    [[nodiscard]] void* getWindow() const { return window_; }
    [[nodiscard]] uint32_t getWidth() const { return data_.width; }
    [[nodiscard]] uint32_t getHeight() const { return data_.height; }

private:
    GLFWwindow* window_;
    struct WindowData {
        std::string title;
        uint32_t width;
        uint32_t height;
    } data_;
};

} // namespace wen