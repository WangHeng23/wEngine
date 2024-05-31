#pragma once

#include <cstdint>
#include <functional>

namespace wen {

enum class EventType {
    eWindowResized,
    eWindowMoved,
    eWindowClosed,
    eWindowFocus,
    eWindowLostFocus,
    eKeyPressed,
    eKeyReleased,
    eInputChar,
    eMousePressed,
    eMouseReleased,
    eMouseMoved,
    eMouseScrolled,
};

enum class EventCategory {
    eWindow,
    eKey,
    eInput,
    eMouse,
};

template <class Event>
using EventCallback = std::function<bool(Event&)>;

#define REGISTER_EVENT(event_category, event_type, ...)                             \
    struct event_type##Event {                                                      \
        __VA_ARGS__                                                                 \
        static constexpr EventCategory category = EventCategory::e##event_category; \
        static constexpr EventType type = EventType::e##event_type;                 \
        static std::vector<EventCallback<event_type##Event>> callbacks;             \
    };

REGISTER_EVENT(Window, WindowResized, int32_t width; int32_t height;)
REGISTER_EVENT(Window, WindowMoved, int32_t xpos; int32_t ypos;)
REGISTER_EVENT(Window, WindowClosed)
REGISTER_EVENT(Window, WindowFocus)
REGISTER_EVENT(Window, WindowLostFocus)
REGISTER_EVENT(Key, KeyPressed, int32_t key; bool is_repeat;)
REGISTER_EVENT(Key, KeyReleased, int32_t key;)
REGISTER_EVENT(Input, InputChar, uint32_t codepoint;)
REGISTER_EVENT(Mouse, MousePressed, int32_t button;)
REGISTER_EVENT(Mouse, MouseReleased, int32_t button;)
REGISTER_EVENT(Mouse, MouseMoved, double xpos; double ypos;)
REGISTER_EVENT(Mouse, MouseScrolled, double xoffset; double yoffset;)

} // namespace wen