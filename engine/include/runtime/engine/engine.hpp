#pragma once

#include "pch.hpp"
#include "runtime/engine/global_context.hpp"

namespace wen {

class WEngine {
public:
    WEngine() = default;
    WEngine(const WEngine&) = delete;
    WEngine(WEngine&&) = delete;
    ~WEngine() = default;

    void initialize();
    void destroy();
};

} // namespace wen