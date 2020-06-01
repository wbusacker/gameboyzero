#include <display.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace Graphics {

void Monotonic::rate_limit(void) {
    struct timespec timer_get;
    double          cur_time;
    double          sleep_time;

    clock_gettime(CLOCK_MONOTONIC, &timer_get);

    cur_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    /* Calculate needed speel time  */
    sleep_time = (last_release + monotonic_rate) - cur_time;

    if (sleep_time > 0) {
        usleep(sleep_time * 1E6);
    }

    last_release += monotonic_rate;
}

}    // namespace Graphics