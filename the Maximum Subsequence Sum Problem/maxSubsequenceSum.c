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
    maxSum = maxSubsequenceSum(intArray,N);
    printf("%d\n",maxSum);
    return 0;
}

//algorithm1
int maxSubsequenceSum(const int A[],int N)
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
