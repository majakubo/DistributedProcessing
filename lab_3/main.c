#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include <math.h>
#include <zconf.h>
#include <unistd.h>


double calculate_pi(int iterations) {
    int points_inside =0;
    double x, y;
    for(int i = 0; i < iterations;i++) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        if(sqrt(x*x + y*y) <= 1) {
            points_inside++;
        }
    }
    double pi = (double)points_inside/(double)iterations * 4;
    return pi;
}


int main() {


    pid_t pid;
    int counter = 0;
    for(int i = 0; i < 10; i++) {
        counter++;
        pid = fork();
        if(pid == 0) {
            srand(getpid());
            break;
        }
    }

    if(pid == 0) {
        printf("new process number %i\n", counter);
        sleep(1);
        printf("%d pi calculated %f\n",counter, calculate_pi(100000));

    } else {
        sleep(5);
    }


    return 0;
}


