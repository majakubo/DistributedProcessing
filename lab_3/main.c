#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include <math.h>
#include <zconf.h>
#include <unistd.h>
#include <wait.h>


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
pid_t pid_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

int main() {


    pid_t pid;
    int i;
    int counter = 0;
    for(i = 0; i < 10; i++) {
        counter++;
        pid = fork();
        pid_array[i] = pid;
        if(pid == 0) {
            srand(getpid());
            break;
        }
    }

    if(pid == 0) {
        printf("new process number %i\n", counter);
        sleep(1);
        printf("%d pi calculated %f\n",i, calculate_pi(100000000));
    } else {
        for(int i = 0; i < 10; i++) {
            waitpid(pid_array[i] , NULL , 0);
        }
    }


    return 0;
}

