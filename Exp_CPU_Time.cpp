#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>


int main()
{
    //  Start timers
    struct timeval start, end;
    gettimeofday(&start, NULL);




    .......// Program di sini



    //  Stop timers
    gettimeofday(&end, NULL);
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
         end.tv_usec - start.tv_usec) / 1.e6;
    printf("CPU_time = %g \n",delta);

   return 0;
}
