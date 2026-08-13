#include<stdio.h>
#include<conio.h>


int main()
{
    int a[100], n, i, choice, element, pos;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("\nOperations");
    printf("\n1. Insert at Beginning");
    printf("\n2. Insert at End");
    printf("\n3. Insert at Position");
    printf("\n4. Delete from Beginning");
    printf("\n5. Delete from End");
    printf("\n6. Delete from Position");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter element: ");
            scanf("%d",&element);

            for(i=n;i>0;i--)
                a[i]=a[i-1];

            a[0]=element;
            n++;
            break;

        case 2:
            printf("Enter element: ");
            scanf("%d",&element);

            a[n]=element;
            n++;
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d",&pos);

            printf("Enter element: ");
            scanf("%d",&element);

            for(i=n;i>=pos;i--)
                a[i]=a[i-1];

            a[pos-1]=element;
            n++;
            break;

        case 4:
            for(i=0;i<n-1;i++)
                a[i]=a[i+1];

            n--;
            break;

        case 5:
            n--;
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d",&pos);

            for(i=pos-1;i<n-1;i++)
                a[i]=a[i+1];

            n--;
            break;

        default:
            printf("Invalid Choice");
            return 0;
    }

    printf("\nUpdated Array:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}