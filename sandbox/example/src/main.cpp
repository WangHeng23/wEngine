#include "wen.hpp"

int main() {
    auto* engine = new wen::WEngine();

    engine->startEngine();

    while (!wen::global_context->window_system->shouldClose()) {
        wen::global_context->window_system->pollEvents();
    }

    engine->shutdownEngine();

    return 0;
}