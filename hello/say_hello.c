#include <rtems.h>
#include <stdlib.h>
#include <stdio.h>
#include <rtems/bspIo.h>
#include <rtems/monitor.h>

static void capture_wait (uint32_t period)
{
  rtems_task_wake_after (RTEMS_MICROSECONDS_TO_TICKS (period * 1000));
}


rtems_task say_hello_rtems(rtems_task_argument ignored)
{
    int i;
    static u_int32_t count = 0;
    while (1)
    {
        count++;
        printk( "\nHello RTEMS : %8d",  count);
        capture_wait (2000);
    }

}

rtems_task say_hello_beagle(rtems_task_argument ignored)
{
    int i;
    static u_int32_t count = 0;
    while (1)
    {
        count++;
        printk( "\nHello Beaglebone : %8d",  count);
        capture_wait (1000);
    }

}