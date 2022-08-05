#include <stdio.h>
#include <stdlib.h>
#include "array_adt1.h"

int main()
{
    struct Array arr1;
    int ch;
    int x, index;
    struct Array arr2;
    struct Array *arr3;

    printf("Enter Size of Array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;
    do
    {
        printf("\n\n-------MENU-------\n");
        printf("1.  Append\n");
        printf("2.  Insert\n");
        printf("3.  Delete\n");
        printf("4.  Linear Search (with Transposition)\n");
        printf("5.  Binary Search\n");
        printf("6.  Recursive Binary Search\n");
        printf("7.  Get Element\n");
        printf("8.  Set Element\n");
        printf("9.  Maximum value in array\n");
        printf("10. Minimum Value in array\n");
        printf("11. Sum\n");
        printf("12. Average\n");
        printf("13. Reverse Array\n");
        printf("14. Left Rotate Array\n");
        printf("15. Insert in Sorted Array\n");
        printf("16. Check if array is sorted\n");
        printf("17. Rerrange with negative values to left and positive to right\n");
        printf("18. Perform Binary Operations (Merge and Set Operations)");
        printf("19. Check for Set Membership");
        printf("20. Display all elements of the array\n");
        printf("21.Exit\n");
        printf("----------------------");

        printf("\n\nEnter you choice ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an element to append: ");
            scanf("%d", &x);
            Append(&arr1, x);
            break;

        case 2:
            printf("Enter an element and index: ");
            scanf("%d%d", &x, &index);
            Insert(&arr1, index, x);
            break;
        case 3:
            printf("Enter index: ");
            scanf("%d", &index);
            x = Delete(&arr1, index);
            printf("\nDeleted Element is: %d\n", x);
            break;
        case 4:
            printf("Enter element for linear search: ");
            scanf("%d", &x);
            index = LinearSearch(&arr1, x);
            printf("\nElement index %d\n", index);
            break;
        case 5:
            printf("Enter element for binary search: ");
            scanf("%d", &x);
            index = BinarySearch(arr1, x);
            printf("\nElement index %d\n", index);
            break;
        case 6:
            printf("Enter element for recursive binary search: ");
            scanf("%d", &x);
            index = RBinSearch(arr1.A, 0, arr1.length, x);
            printf("\nElement index %d\n", index);
            break;
        case 7:
            printf("Enter index to get element from: ");
            scanf("%d", &index);
            x = Get(arr1, index);
            printf("\nElement in given index is: %d\n", x);
            break;
        case 8:
            printf("\nEnter index to set element in: ");
            scanf("%d", &index);
            printf("\nEnter key/ element to set: ");
            scanf("%d", &x);
            Set(&arr1, index, x);
            break;
        case 9:
            x = Max(arr1);
            printf("\n Maxiumum Value in array is: %d\n", x);
            break;
        case 10:
            x = Min(arr1);
            printf("\n %d Minimum Value in array is: %d\n", x);
            break;
        case 11:
            printf("Sum is %d\n", Sum(arr1));
            break;
        case 12:
            printf("Average is %d\n", Avg(arr1));
            break;
        case 13:
            Reverse(&arr1);
            printf("\nElements were reversed!\n");
            Display(arr1);
            break;
        case 14:
            LRotate(&arr1);
            printf("\nElements were left rotated!\n");
            Display(arr1);
            break;
        case 15:
            printf("\nEnter key to insert in sorted array: ");
            scanf("%d", &x);
            InsertSort(&arr1, x);
            break;
        case 16:
            x = isSorted(arr1);
            if (x == 1)
                printf("\nArray is sorted!\n");
            else
                printf("\nArray is not sorted!\n");
            break;
        case 17:
            Rearrange(&arr1);
            printf("\nArray was rearranged!\n");
            break;

        case 18:
        {
            char c;
            printf("\n Enter second array to operate upon");
            printf("Enter Size of Second Array");
            scanf("%d", &arr2.size);
            arr2.A = (int *)malloc(arr1.size * sizeof(int));
            arr2.length = 0;
            do
            {
                printf("\n\nMenu for 2nd Array\n");
                printf("1. Append\n");
                printf("2. Insert\n");
                printf("3. Delete\n");
                printf("4. Display\n");
                printf("5. Exit");
                printf("Enter you choice ");
                scanf("%d", &c);
                switch (c)
                {
                case 1:
                    printf("Enter an element to append: ");
                    scanf("%d", &x);
                    Append(&arr1, x);

                case 2:
                    printf("Enter an element and index: ");
                    scanf("%d%d", &x, &index);
                    Insert(&arr1, index, x);
                    break;
                case 3:
                    printf("Enter index: ");
                    scanf("%d", &index);
                    x = Delete(&arr1, index);

                    printf("\nDeleted Element is: %d\n", x);
                    break;
                case 4:
                    Display(arr1);
                    break;
                }
            } while (c > 0 && c < 5);

            printf("\n--Menu for Binary Operations--");
            printf("\n1. Merge two arrays ");
            printf("\n2. Union");
            printf("\n3. Intersection");
            printf("\n4. Difference");
            printf("\nEnter your choice");
            scanf("%d", &c);

            switch (c)
            {
            case 1:
                arr3 = Merge(arr1, arr2);
                printf("\n");
                Display(*arr3);
            case 2:
                arr3 = Union(arr1, arr2);
                printf("\n");
                Display(*arr3);
            case 3:
                arr3 = Intersection(arr1, arr2);
                printf("\n");
                Display(*arr3);
            case 4:
              {
                int a;
                printf("\n Options for difference:");
                printf("\n1. Array1 - Array2");
                printf("\n2. Array2 - Array1");
                printf("\n Enter choice: ");
                scanf("%d", &a);
                if (a == 1)
                    arr3 = Difference(arr1, arr2);
                else
                    arr3 = Difference(arr2, arr1);
                printf("\n");
                Display(*arr3);
              }
            }
        }
        case 19:
        {

            int a, key;
            printf("\n Enter array number to check membership in (1 to 3) [give 1, if Binary Operations not done");
            scanf("%d", &a);
            printf("\n Enter key to check for set memebership:");
            scanf("%d", key);
            if (a == 1)
                index = SetMembership(arr1, key);
            else if (a == 2)
                index = SetMembership(arr2, key);
            else
                index = SetMembership(*arr3, key);
            printf("\n Element index: %d", index);
        }

        case 20:
            Display(arr1);
        }
    } while (ch > 0 && ch < 21);

    printf("\n Thank you for using Array ADT Program!!");

    free(arr1.A);
    free(arr3);

    return 0;
}

/* for static
   int main()
   {
     struct Array arr = {{1, 2, 3, 4, 5}, 5, 6};
     int n, i;
   }
*/