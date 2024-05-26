#include "runtime/engine/engine.hpp"

namespace wen {

void WEngine::startEngine() {
    global_context = new GlobalContext();
    global_context->startup();
    WEN_CORE_INFO("engine start.")
}

void WEngine::shutdownEngine() {
    WEN_CORE_INFO("engine shutdown.")
    global_context->shutdown();
    delete global_context;
    global_context = nullptr;
}

} // namespace wen