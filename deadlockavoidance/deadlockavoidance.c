#include <stdio.h>

struct DA
{
    int max[10],al[10],need[10],before[10],after[10];
}p[10];

void main()
{
    int i,j,k,l,r,n,tot[10],av[10],cn=0,cz=0,temp=0,c=0;
    printf("Enter the no of processes");
    scanf("%d", &n);
    printf("Enter the no of resources:");
    scanf("%d", &r);

    for(i=0;i<r;i++)
    {
        printf("Enter total value of resource %d:",i+1);
        scanf("%d", &tot[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Process: %d \n", i+1);
        for(j=0;j<r;j++)
        {
            printf("Max value for resource %d:", j+1);
            scanf("%d", &p[i].max[j]);
        }
        for(j=0;j<r;j++){
            printf("Allocated from resource %d:", j+1);
            scanf("%d", &p[i].al[j]);
            p[i].need[j]=p[i].max[j]-p[i].al[j];
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<n;j++)
            temp=temp+p[j].al[i];
        av[i]=tot[i]-temp;
        temp =0;
    }
    printf("\n\t max allocated need total avail");
    for(i=0;i<n;i++){
        printf("\n P%d \t",i+1);
        for(j=0;j<r;j++)
            printf("%d",p[i].al[i]);
        printf("\t");
        for(j=0;j<r;j++)
            printf("%d",p[i].need[j]);
        printf("\t");
        for(j=0;j<r;j++)
        {
            if(i==0)
                printf("%d", tot[j]);
        }
        printf(" ");
        for(j=0;j<r;j++){
            if(i==0)
                printf("%d",av[j]);
        }
    }
    printf("\n\nt AVAIL BEFORE \t AVAIL AFTER");

    for(l=0;l<n;l++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<r;j++)
            {
                if(p[i].need[j]==0)
                    cz++;
            }
            if(cn==0 && cz!=r)
            {
                for(j=0;j<r;j++){
                    p[i].before[j]=av[j]-p[i].need[j];
                    p[i].after[j]=p[i].before[j]+p[i].max[j];
                    av[j]=p[i].after[j];

                    p[i].max[j]=0;
                }
                printf("\n P%d \t",i+1);
                for(j=0;j<r;j++)
                    printf("%d",p[i].before[j]);
                printf("\t");

                for(j=0;j<r;j++)
                    printf("%d", p[i].after[j]);

                cn=0;
                cz=0;
                c++;

                break;
            }
            else {
                cn=0;cz=0;
            }
        }
    }
    if(c==n)
        printf("\nAbove sequence is a safe sequence");
    else

        printf("\n Deadlock occured");
}

/*
 * Enter the no of processes4
Enter the no of resources:3
Enter total value of resource 1:9
Enter total value of resource 2:3
Enter
 total value of resource 3:6
Process: 1
Max value for resource 1:3
Max value for resource 2:2
Max value for resource 3:2
Allocated from resource 11
Allocated from resou
rce 20
Allocated from resource 30
Process: 2
Max value for resource 1:6
Max value for resource 2:1
Max value for resource 3:3
Allocated from resource 15
Allocated from resou
rce 21
Allocated from resource 31
Process: 3
Max value for resource 1:3
Max value for resource 2:1
Max value for resource 3:4
Allocated from resource 12
Allocated from resou
rce 21
Allocated from resource 31
Process: 4
Max value for resource 1:4
Max value for resource 2:2
Max value for resource 3:2
Allocated from resource 10
Allocated from resou
rce 20
Allocated from resource 32

         max allocated need total avail
 P1     111     222     936 112
 P2     111     102
 P3     111     103
 P4     000     420

t AVAIL BEFORE   AVAIL AFTER
 P1     -1-10   212
 P1     0-10    0-10
 P1     -2-3-2  -2-3-2
 P1     -4-5-4  -4-5-4
Above sequence is a safe sequence
Process finished with exit code 34
 */