#include<stdio.h>

int request[50];
int SIZE;
int dist(int a, int b)
{
    if(a>b)
        return a-b;
    return b-a;
}

void fcfs(int n)
{
    int head,i;
    int seekcount =0;
    printf("ENTER THE CURRENT HEAD:\n");
    scanf("%d", &head);
    for(i=0;i<n;i++)
    {
        if(request[i]<SIZE-1){
            seekcount=seekcount+dist(head,request[i]);
            head=request[i];
        }
    }

    printf("TOTAL DISTANCE : %d",seekcount);
}

int main(){

    int n,i;
    printf("ENTER THE DISK SIZE: \n");
    scanf("%d", &SIZE);
    printf("ENTER THE NO OF REQUEST SEQUENCE :\n");
    scanf("%d", &n);
    printf("ENTER THE REQUEST SEQUENCE :\n");
    for(i=0;i<n;i++)
        scanf("%d",&request[i]);
    fcfs(n);
}

/*
 * ENTER THE DISK SIZE:
200
ENTER THE NO OF REQUEST SEQUENCE :
8
ENTER THE REQUEST SEQUENCE :
176
79
34
60
92
11
41
114
ENTER THE CURRENT HEAD:
50
TOTAL DISTANCE : 510
 */