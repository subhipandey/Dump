#include "stdio.h"
#include "conio.h"

void main()
{
    int v[20], w[20], i,j,n,W;
    void knapsack(int[], int[],int,int);
    printf("No of objects:");
    scanf("%d", &n);
    printf("Capacity of knapsack");
    scanf("%d", &W);

    for(i =1; i <= n; i++)
    {
        printf("Enter the weight and value of objects: ", i);
        scanf("%d", &w[i]);
        scanf("%d", &v[i]);
    }
    knapsack(v,w,n,W);
    getch();
}

void knapsack(int v[], int w[], int n, int W) {
    int k[20][20], i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                k[i][j] = 0;
            } else if (j < w[i]) {
                k[i][j] = k[i - 1][j];
            } else {
                if (k[i - 1][j] > k[i - 1][j - w[i]] + v[i]) {
                    k[i][j] = k[i - 1][j];
                } else {
                    k[i][j] = k[i - 1][j - w[i]] + v[i];
                }
            }
        }
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            printf(" %d ", k[i][j]);
        }
        printf("\n");
    }
    printf("___________________________________________");
    printf("\nMaximum possible profit: %d", k[n][W]);
}

/*
 * No of objects:5
Capacity of knapsack 11
Enter the weight and value of objects:1 1
 Enter the weight and value of objects:2 6
 Enter th
e weight and value of objects:5 18
 Enter the weight and value of objects:6 22
 Enter the weight and value of objects:7 28
  0  0  0  0
  0  0  0  0  0  0  0  0
 0  1  1  1  1  1  1  1  1  1  1  1
 0  1  6  7  7  7  7  7  7  7  7  7
 0  1  6  7  7  18  19  24  25  25  25  25
 0  1  6  7  7  18  22  24  28  29  29  40
 0  1  6  7  7  18  22  28  29  34  35  40
___________________________________________
Maximum possible profit: 40
 */