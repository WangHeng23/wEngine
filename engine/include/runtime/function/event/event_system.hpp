#pragma once

#include "runtime/core/base/macro.hpp"
#include "runtime/function/event/event.hpp"

namespace wen {

class EventSystem final {
    WEN_DECLARE_SINGLETON(EventSystem)

public:
    template <class Event>
    void attach(EventCallback<Event> callback) {
        Event::callbacks.push_back(callback);
    }

private:
    static void setCallbacks();

    template <class Event>
    void dispatch(Event event) {
        for (auto& callback : Event::callbacks) {
            if (callback(event)) {
                return;
            }
        }
    }
};

} // namespace wen