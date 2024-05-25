#include "runtime/engine/engine.hpp"

namespace wen {

void WEngine::initialize() {
    global_context = new GlobalContext();
    global_context->startup();
    WEN_ENGINE_CORE_INFO("initialize engine.")
}

void WEngine::destroy() {
    WEN_ENGINE_CORE_INFO("destroy engine.")
    global_context->shutdown();
}

} // namespace wen