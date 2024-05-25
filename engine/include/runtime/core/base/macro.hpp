#pragma once

#include "runtime/core/base/singleton.hpp"

namespace wen {

#define WEN_DECLARE_SINGLETON(ClassName, ...) \
    friend class Singleton<ClassName>;        \
                                              \
private:                                      \
    ClassName(__VA_ARGS__);                   \
    ~ClassName();

} // namespace wen