//row major ordering matrix product
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char *argv[]){
    struct timeval start,end;
    //matrix a created for row major matrix multiplication
    //matrix d created for standart matrix multiplication
    int **a, **b, **c, **d;
    int row, col, i, j, k;
    row = atoi(argv[1]);
    col = atoi(argv[2]);

    gettimeofday(&start,NULL);
    //allocate memory from heap for row size of the matrices
    a=(int **)malloc(row*sizeof(int *));
    b=(int **)malloc(row*sizeof(int *));
    c=(int **)malloc(row*sizeof(int *));
    d=(int **)malloc(row*sizeof(int *));


    for ( i = 0; i < row; i++)
    {
        //allocate memory from heap for column size of the matrices
        a[i]=(int *)malloc(col*sizeof(int));
        b[i]=(int *)malloc(col*sizeof(int));
        c[i]=(int *)malloc(col*sizeof(int));
        d[i]=(int *)malloc(col*sizeof(int));
        for ( j = 0; j < col; j++)
        {
            b[i][j]=rand();
            c[i][j]=rand();

        }
    }
    gettimeofday(&end,NULL);
    printf("Initialization time: %3.4f\n", ((end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec))/1000000.0);

    //row wise matrix multiplication
    gettimeofday(&start,NULL);
    for (i = 0; i < row; i++)
    {
        for ( k = 0; k < col; k++)
        {
          for ( j = 0; j < col; j++)
            {
                a[i][j] += b[i][k]*c[k][j];
            }          
        }
    }
    gettimeofday(&end,NULL);
    printf("Execution time for row wise matrix multiplication: %3.4f\n", ((end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec))/1000000.0);
    
    //standart matrix multiplication
    gettimeofday(&start,NULL);
    for (i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
          for ( k = 0; k < col; k++)
            {
                d[i][j] += b[i][k]*c[k][j];
            }          
        }
    }
    gettimeofday(&end,NULL);
    printf("Execution time for standart matrix multiplication: %3.4f\n", ((end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec))/1000000.0);


   return 0;
}