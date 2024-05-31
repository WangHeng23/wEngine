#pragma once

#include "runtime/core/base/macro.hpp"
#include <glm/glm.hpp>

namespace wen {

enum class ButtonState {
    ePressed,
    eReleased,
};

class InputSystem final {
    WEN_DECLARE_SINGLETON(InputSystem)

public:
    void tick();

    [[nodiscard]] bool isKeyPressed(int key) const;
    [[nodiscard]] bool isKeyReleased(int key) const;
    [[nodiscard]] bool isMousePressed(int button) const;
    [[nodiscard]] bool isMouseReleased(int button) const;

    [[nodiscard]] glm::dvec2 getMousePosition() const;
    [[nodiscard]] glm::dvec2 getMouseScroll() const;

private:
    void attachEvent();

private:
    ButtonState key_state_[350];
    ButtonState mouse_state_[10];
    glm::dvec2 mouse_position_;
    glm::dvec2 mouse_scroll_;
};

} // namespace wen