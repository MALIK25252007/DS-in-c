#include <stdio.h>

int main(){ 
    while(1){
    int choice;
    printf("Enter your choice (1/2):\n");
    printf("1. MATRIX MULTIPLICATION \n");
    printf("2. DIFFERENCE BETWEEN DIGONALS \n");
    scanf("%d",&choice);
    if (choice==1){
    int n1, n2, c1, c2, i, j, k;
    printf("enter the dimension of matrix_1:");
    scanf("%d %d", &n1, &c1);
    printf("enter the dimension of matrix_2:");
    scanf("%d %d", &n2, &c2);
    if (c1 != n2){
        printf("column of matrix 1 must be equal to matrix 2");
        return 1;
    }

    int a[n1][c1], b[n2][c2], c[n1][c2];
    printf("enter the elements of matrix_1:\n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("enter the elements of matrix_2:");
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    
printf("the product of the matrix is:\n");
for(i=0;i<n1;i++){
    for ( j = 0; j < c2; j++)
    {
       printf("%d\t",c[i][j]);
    }
    printf("\n");
    
}
return 0;

}
else if(choice==2){
    int n1, c1, i, j, k,difference;
    int sum1=0,sum2=0;
    printf("enter the dimension of matrix:");
    scanf("%d %d", &n1, &c1);
    if (n1 != c1)
    {
        printf("matrix should be square :");
        break;
    }

    int a[n1][c1];
    printf("enter the elements of matrix:\n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j <c1; j++)
        {     
            sum1+=a[i][i];
            sum2+=a[i][n1-1-i];
        }
    }
    difference=sum1-sum2;
    printf("the difference between the principal and anti diagonal is %d",difference);
return 0;

}
else{
    return 0;
}
}
return 0;
}