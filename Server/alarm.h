/*
 * Prints time in seconds since a newline character was entered at the prompt.
 */


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>


unsigned int alarm_hires (long microseconds);

/*
 * alarm function taken from 
 * http://www.gnu.org/s/libc/manual/html_node/Setting-an-Alarm.html
 * and modified for higher precision
 *
 */

unsigned int
alarm_hires (long microseconds)
{
    int seconds = microseconds/1000000;

    struct itimerval old, new;
    new.it_interval.tv_usec = 0;
    new.it_interval.tv_sec = 0;
    new.it_value.tv_usec = microseconds - (seconds * 1000000);
    new.it_value.tv_sec = seconds;
    if (setitimer (ITIMER_REAL, &new, &old) < 0)
        return 0;
    else
        return old.it_value.tv_sec;
}

