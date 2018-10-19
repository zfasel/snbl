#include "../system.h"

//APP_TIMER_DEF(m_annimation_timer);
#define APP_SCHED_MAX_EVENT_SIZE    62   	/**< Maximum size of scheduler events. */
#define APP_SCHED_QUEUE_SIZE        32   	/**< Maximum number of events in the scheduler queue. */


void util_timers_init() {
  APP_ERROR_CHECK(nrf_drv_clock_init());
  nrf_drv_clock_lfclk_request(NULL);
  APP_ERROR_CHECK(app_timer_init());

}
