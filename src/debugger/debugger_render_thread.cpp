#include <debugger.h>

namespace Debug {

void *
  GB_Debugger::render_thread(void *arg) {

    Debug::GB_Debugger *gbdb = reinterpret_cast<Debug::GB_Debugger *>(arg);

    while (1) {
    }
}

}    // namespace Debug