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