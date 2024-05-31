#include "runtime/engine/global_context.hpp"

namespace wen {

EventSystem::EventSystem() {
    setCallbacks();
}

void EventSystem::setCallbacks() {
    auto* window = global_context->window_system->getRuntimeWindow()->getWindow();
    auto* glfw_window = static_cast<GLFWwindow*>(window);

    glfwSetFramebufferSizeCallback(glfw_window, [](GLFWwindow*, int width, int height) {
        global_context->event_system->dispatch<WindowResizedEvent>({width, height});
    });

    glfwSetWindowPosCallback(glfw_window, [](GLFWwindow*, int xpos, int ypos) {
        global_context->event_system->dispatch<WindowMovedEvent>({xpos, ypos});
    });

    glfwSetWindowCloseCallback(glfw_window, [](GLFWwindow*) {
        global_context->event_system->dispatch<WindowClosedEvent>({});
    });

    glfwSetWindowFocusCallback(glfw_window, [](GLFWwindow*, int focused) {
        switch (focused) {
            case GLFW_TRUE:
                global_context->event_system->dispatch<WindowFocusEvent>({});
                break;
            case GLFW_FALSE:
                global_context->event_system->dispatch<WindowLostFocusEvent>({});
                break;
            default:
                break;
        }
    });

    glfwSetKeyCallback(glfw_window, [](GLFWwindow*, int key, int scancode, int action, int mods) {
        switch (action) {
            case GLFW_PRESS:
                global_context->event_system->dispatch<KeyPressedEvent>({key, false});
                break;
            case GLFW_REPEAT:
                global_context->event_system->dispatch<KeyPressedEvent>({key, true});
                break;
            case GLFW_RELEASE:
                global_context->event_system->dispatch<KeyReleasedEvent>({key});
                break;
            default:
                break;
        }
    });

    glfwSetCharCallback(glfw_window, [](GLFWwindow*, uint32_t codepoint) {
        global_context->event_system->dispatch<InputCharEvent>({codepoint});
    });

    glfwSetMouseButtonCallback(glfw_window, [](GLFWwindow*, int button, int action, int mods) {
        switch (action) {
            case GLFW_PRESS:
                global_context->event_system->dispatch<MousePressedEvent>({button});
                break;
            case GLFW_RELEASE:
                global_context->event_system->dispatch<MouseReleasedEvent>({button});
                break;
            default:
                break;
        }
    });

    glfwSetCursorPosCallback(glfw_window, [](GLFWwindow*, double xpos, double ypos) {
        global_context->event_system->dispatch<MouseMovedEvent>({xpos, ypos});
    });

    glfwSetScrollCallback(glfw_window, [](GLFWwindow*, double xoffset, double yoffset) {
        global_context->event_system->dispatch<MouseScrolledEvent>({xoffset, yoffset});
    });
}

EventSystem::~EventSystem() {
    WindowResizedEvent::callbacks.clear();
    WindowMovedEvent::callbacks.clear();
    WindowClosedEvent::callbacks.clear();
    WindowFocusEvent::callbacks.clear();
    WindowLostFocusEvent::callbacks.clear();
    KeyPressedEvent::callbacks.clear();
    KeyReleasedEvent::callbacks.clear();
    InputCharEvent::callbacks.clear();
    MousePressedEvent::callbacks.clear();
    MouseReleasedEvent::callbacks.clear();
    MouseMovedEvent::callbacks.clear();
    MouseScrolledEvent::callbacks.clear();
}

} // namespace wen