#include "runtime/engine/global_context.hpp"

namespace wen {

InputSystem::InputSystem() {
    attachEvent();
}

void InputSystem::tick() {
    mouse_scroll_ = {0.0, 0.0};
}

bool InputSystem::isKeyPressed(int key) const {
    return key_state_[key] == ButtonState::ePressed;
}

bool InputSystem::isKeyReleased(int key) const {
    return key_state_[key] == ButtonState::eReleased;
}

bool InputSystem::isMousePressed(int button) const {
    return mouse_state_[button] == ButtonState::ePressed;
}

bool InputSystem::isMouseReleased(int button) const {
    return mouse_state_[button] == ButtonState::eReleased;
}

glm::dvec2 InputSystem::getMousePosition() const {
    return mouse_position_;
}

glm::dvec2 InputSystem::getMouseScroll() const {
    return mouse_scroll_;
}

void InputSystem::attachEvent() {
    auto& event_system = global_context->event_system;
    event_system->attach<KeyPressedEvent>([&](KeyPressedEvent& event) {
        key_state_[event.key] = ButtonState::ePressed;
        return false;
    });

    event_system->attach<KeyReleasedEvent>([&](KeyReleasedEvent& event) {
        key_state_[event.key] = ButtonState::eReleased;
        return false;
    });

    event_system->attach<MousePressedEvent>([&](MousePressedEvent& event) {
        mouse_state_[event.button] = ButtonState::ePressed;
        return false;
    });

    event_system->attach<MouseReleasedEvent>([&](MouseReleasedEvent& event) {
        mouse_state_[event.button] = ButtonState::eReleased;
        return false;
    });

    event_system->attach<MouseMovedEvent>([&](MouseMovedEvent& event) {
        mouse_position_ = {event.xpos, event.ypos};
        return false;
    });

    event_system->attach<MouseScrolledEvent>([&](MouseScrolledEvent& event) {
        mouse_scroll_ = {event.xoffset, event.yoffset};
        return false;
    });
}

InputSystem::~InputSystem() = default;

} // namespace wen