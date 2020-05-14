#include <debugger.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace Debug {
void GB_Debugger::kill_threads(void) {

    request_destroy = true;

    pthread_join(frame_render_thread_handle, NULL);
}

}    // namespace Debug