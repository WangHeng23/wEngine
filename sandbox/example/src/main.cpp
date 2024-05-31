#include "wen.hpp"

int main() {
    auto* engine = new wen::WEngine();

    engine->startEngine();

    auto& event_sys = wen::global_context->event_system;
    event_sys->attach<wen::KeyPressedEvent>([](wen::KeyPressedEvent& event) {
        WEN_CLIENT_INFO("Key: {}, {}, {}, {}", (char)event.key, event.is_repeat, (int)event.category, (int)event.type)
        return false;
    });
    event_sys->attach<wen::MousePressedEvent>([](wen::MousePressedEvent& event) {
        WEN_CLIENT_INFO("1. mouse button: {}", event.button)
        return true;
    });
    event_sys->attach<wen::MousePressedEvent>([](wen::MousePressedEvent& event) {
        WEN_CLIENT_INFO("2. mouse button: {}", event.button)
        return false;
    });

    while (!wen::global_context->window_system->shouldClose()) {
        wen::global_context->window_system->pollEvents();
    }

    engine->shutdownEngine();

    return 0;
}