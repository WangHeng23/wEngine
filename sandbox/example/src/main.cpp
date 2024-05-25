#include "wen.hpp"

using namespace wen;

int main() {
    auto* engine = new WEngine();

    engine->initialize();

    WEN_ENGINE_CLIENT_INFO("hello world!")

    engine->destroy();

    return 0;
}