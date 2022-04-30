#include<stdio.h>
void main()
{
    int bsize[10],psize[10],bno,pno,flags[10],allocation[10],i,j;
    for(i=0;i<10;i++)
    {
        flags[i]=0;
        allocation[i]=-1;
    }
    printf("enter no of blocks");
    scanf("%d",&bno);
    printf("\n Enter size of each block:");
    for(i=0;i<bno;i++)
        scanf("%d",&bsize[i]);
    printf("\nEnter no of process:");
    scanf("%d", &pno);
    printf("\nEnter size of each process:");
    for(i=0;i<pno;i++)
        scanf("%d", &psize[i]);
    for(i=0;i<pno;i++)
        for(j=0;j<bno;j++)
            if(flags[j]==0 && bsize[j]>=psize[j])
            {
                allocation[j]=i;
                flags[j]=1;
                break;
            }
    printf("\nBlock no.\tsize\t\tprocess.\t\tsize");
    for(i=0;i<bno;i++)
    {
        break;
    }
    printf("\nBlock no.\tsize\t\tprocess.\t\tsize");
    for(i=0;i<bno;i++)
    {
        printf("\n%d\t\t%d\t\t", i+1,bsize[i]);
        if(flags[i]==1)
            printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
        else
            printf("Not Allocated");
    }
}

/*
 * enter no of blocks5

 Enter size of each block:100
500
200
300
600

Enter no of process:4

Enter size of each process:212
417
112
426

Block no.       size            process.                size
Block no.       size            process.                size
1               100             Not Allocated
2               500             1                       212
3               200             2                       417
4               300             Not Allocated
5               600             Not Allocated
Process finished with exit code 5
 */