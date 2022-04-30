#include<stdio.h>
#include<unistd.h>

int main() {
    
    pid_t ret_value;
    printf("\n the process id is %d\n\n",getpid());
    ret_value=fork();
    if(ret_value<0)
    {
        printf("\n fork failure\n");
    }
    else if(ret_value == 0)
    {
        printf("\n the child process\n");
        printf("\n The process id is %d\n\n",getpid());
    }
    else
    {
        wait();
    }
    printf("Parent process\n");
    printf("the process id is %d\n",getpid());
    return 0;
}

/*
 * Enter the process burst time
: p[1]:12
 p[2]:10

Process]                Burst Time      Waiting Time    Turnaround Time
P[1]            12              0               12
P[2]            10              10              20

Average waiting time: 5.000000

Average turnaround time: 16.000000
Process finished with exit code 1

 */