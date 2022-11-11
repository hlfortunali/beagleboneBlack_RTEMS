/*
* Hello world example
*/
#include "task.h"


#include <rtems.h>
#include <stdlib.h>
#include <stdio.h>
#include <rtems/bspIo.h>
#include <rtems/monitor.h>



// rtems_task Init(rtems_task_argument ignored)
// {
//     int i;
//     for(i=0; i<20; i++)
//     {
//         printk( "\nHello RTEMS\n" );
//         capture_wait (1000);
//     }

// exit( 0 );
// }


rtems_task Init(rtems_task_argument ignored)
{
  rtems_id    task_id_rtems, task_id_beagle;
  rtems_status_code status;

  status = rtems_task_create(
    rtems_build_name('H','E','L','O'),
    1,
    RTEMS_MINIMUM_STACK_SIZE,
    RTEMS_DEFAULT_MODES,
    RTEMS_FLOATING_POINT | RTEMS_DEFAULT_ATTRIBUTES,
    &task_id_rtems
  );

    status = rtems_task_create(
    rtems_build_name('B','O','N','E'),
    2,
    RTEMS_MINIMUM_STACK_SIZE,
    RTEMS_DEFAULT_MODES,
    RTEMS_FLOATING_POINT | RTEMS_DEFAULT_ATTRIBUTES,
    &task_id_beagle
  );

  status = rtems_task_start( task_id_rtems, say_hello_rtems, 1);
  status = rtems_task_start( task_id_beagle, say_hello_beagle, 2);
  status = rtems_task_delete( RTEMS_SELF );
}