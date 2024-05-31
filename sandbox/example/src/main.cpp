#include "wen.hpp"

int main() {
    auto* engine = new wen::WEngine();

    engine->startEngine();

    auto& input_sys = wen::global_context->input_system;

    while (!wen::global_context->window_system->shouldClose()) {
        wen::global_context->window_system->pollEvents();

        if (input_sys->isKeyPressed(WEN_KEY_A)) {
            WEN_CLIENT_INFO("Key A is pressed")
        }
        if (input_sys->isMousePressed(WEN_MOUSE_BUTTON_1)) {
            WEN_CLIENT_INFO("Mouse button 1 is pressed")
        }
    }

    engine->shutdownEngine();

    return 0;
}