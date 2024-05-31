#include "runtime/function/event/event.hpp"

namespace wen {

#define EVENT_CALLBACKS(event_type) \
    std::vector<EventCallback<event_type##Event>> event_type##Event::callbacks;

EVENT_CALLBACKS(WindowResized)
EVENT_CALLBACKS(WindowMoved)
EVENT_CALLBACKS(WindowClosed)
EVENT_CALLBACKS(WindowFocus)
EVENT_CALLBACKS(WindowLostFocus)
EVENT_CALLBACKS(KeyPressed)
EVENT_CALLBACKS(KeyReleased)
EVENT_CALLBACKS(InputChar)
EVENT_CALLBACKS(MousePressed)
EVENT_CALLBACKS(MouseReleased)
EVENT_CALLBACKS(MouseMoved)
EVENT_CALLBACKS(MouseScrolled)

} // namespace wen