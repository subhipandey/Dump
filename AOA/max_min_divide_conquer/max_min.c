#include<stdio.h>

int max, min;
int a[100];

void listmaxmin(int i,int j)
{
    int maximum, minimum, mid;
    if(i==j)
    {
        max = min = a[i];
    }

    else
    {
        if(i==j-1)
        {
            if(a[i] <a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else
        {
            mid = (i+j)/2;
            listmaxmin(i, mid);
           maximum = max;minimum = min;
            listmaxmin(mid + 1,j);
            if(max < maximum)
                max = maximum;
            if(min > minimum)
                min = minimum;
        }
    }
}

int main()
{
    int i, myArray;
    printf("\nEnter the total number of elements :");
    scanf("%d", &myArray);
    printf("Enter the elements: \n");
    for (i=1; i<= myArray; i++)
        scanf("%d", &a[i]);

    max = a[0];
    min = a[0];
    listmaxmin(1, myArray);
    printf("Minimum elements in an array : %d\n", min);
    printf("Maximum elements in an array : %d\n", max);
    return 0;
}

/*
 * Enter the total number of elements :3
Enter the elements:
-67
-100
89
Minimum elements in an array : -100
Maximum elements in an array : 89

Process finished with exit code 0

 */