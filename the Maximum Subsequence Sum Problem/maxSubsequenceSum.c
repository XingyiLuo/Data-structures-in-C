//the Maximum Subsequence Sum Problem
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "data.txt"
int main()
{
    int N = 8,maxSum;//思考是否可以通过其他方式获得文件大小
    int intArray[8] = {};

    FILE *fp;
    fp = fopen(FILE_NAME,"r");
    if(fp == NULL)
    {
        fprintf(stderr,"Error:can't open %s\n",FILE_NAME);
        //exit(EXIT_FILURE);
        return -1;
    }
    for(int i=0;i<N;i++)
        fscanf(fp,"%d",&intArray[i]);
    fclose(fp);
    /*
    for(int i=0;i<N;i++)
        printf("%d ",intArray[i]);
    */
    maxSum = maxSubsequenceSum4(intArray,N);
    printf("%d\n",maxSum);
    return 0;
}

//algorithm1
int maxSubsequenceSum1(const int A[],int N)
{
    int ThisSum,MaxSum,i,j,k;
    MaxSum = 0;
    for(i=0;i<N;i++)
    {
        for(j=i;j<N;j++)
        {
            ThisSum = 0;
            for(k=i;k<=j;k++)
                ThisSum += A[k];
            if(ThisSum>MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}
//algorithm2
int maxSubsequenceSum2(const int A[],int N)
{
    int ThisSum,MaxSum,i,j;
    MaxSum = 0;
    for(i=0;i<N;i++)
    {
        ThisSum = 0;
        for(j=i;j<N;j++)
        {
            ThisSum += A[j];
            if(ThisSum>MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}
//algorithm3: "divide-and-conquer"
int maxSubsequenceSum3(const int A[],int N)
{
    return maxsubsum(A,0,N-1);
}
int maxsubsum(const int A[],int Left,int Right)
{
    int MaxLeftSum,MaxRightSum;
    int MaxLeftBorderSum,MaxRightBorderSum;
    int LeftBorderSum,RightBorderSum;
    int Center,i;

    if(Left==Right) //base case
        if(A[Left]>0)
            return A[Left];
        else
            return 0;
    Center = (Left+Right)/2;
    MaxLeftSum = maxsubsum(A,Left,Center);
    MaxRightSum = maxsubsum(A,Center+1,Right);

    MaxLeftBorderSum = 0;LeftBorderSum = 0;
    for(i=Center;i>=Left;i--)
    {
        LeftBorderSum += A[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    MaxRightBorderSum = 0;RightBorderSum = 0;
    for(i=Center+1;i<=Right;i++)
    {
        RightBorderSum += A[i];
        if(RightBorderSum>MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);
}
int max3(int a,int b, int c)
{
    if(a>=b&&a>=c)
        return a;
    else if(b>=c)
        return b;
    else
        return c;
}

//algorithm4:O(N)
int maxSubsequenceSum4(const int A[], int N)
{
    int ThisSum, MaxSum,j;
    ThisSum = MaxSum =0;
    for(j=0;j<N;j++)
    {
        ThisSum += A[j];
        if(ThisSum>MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum <0 )
            ThisSum = 0;
    }
    return MaxSum;
}
