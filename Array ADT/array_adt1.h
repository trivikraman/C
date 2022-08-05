#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
    else
        printf("\nArray is full !!\n");
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
    else
        printf("\nIndex not compatible in size/length of the array !!\n");
}

int Delete(struct Array *arr, int index)
{
    int x, i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }

    else
        printf("\nGiven index not compatible !!\n");
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key) // with improvements, for without improvements,we need not use pointers.
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key)
{

    int mid = 0;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a, l, mid - 1, key);
    }
    else
        return RBinSearch(a, mid + 1, h, key);
    return -1;
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    else
        return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
    else
        printf("\n Index not compatible  !!");
}

int Max(struct Array arr)
{
    int i, max = arr.A[0];
    for (i = 0; i < arr.length; i++)
        if (arr.A[i] > max)
            max = arr.A[i];
    return max;
}

int Min(struct Array arr)
{
    int i, min = arr.A[0];
    for (i = 0; i < arr.length; i++)
        if (arr.A[i] < min)
            min = arr.A[i];
    return min;
}

int Sum(struct Array arr)
{
    int i, sum = 0;
    for (i = 0; i < arr.length; i++)
        sum = sum + arr.A[i];
    return sum;
}

float Avg(struct Array arr)
{
    int total;
    total = Sum(arr);
    return total / arr.length;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i, j;

    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
    free(B);
}

void Reverse2(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void LRotate(struct Array *arr)
{
    int i, temp;
    temp = arr->A[0];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i + 1];
    arr->A[arr->length - 1] = temp;
}

void InsertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array *Merge(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    // or even struct Array arr3 is enough, but return type should be changed

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = arr1.length + arr2.length;
    arr3->size = 10;
    return arr3;
}

struct Array *Union(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    // or even struct Array arr3 is enough, but return type should be changed

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else if (arr2.A[j] < arr1.A[i])
            arr3->A[k++] = arr2.A[j++];
        else
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Intersection(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    // or even struct Array arr3 is enough, but return type should be changed

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < arr1.A[i])
            j++;
        else
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Difference(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    // or even struct Array arr3 is enough, but return type should be changed

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else if (arr2.A[j] < arr1.A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    /* If B-A remove upper half and add this
       for (; j < arr2.length; j++)
           arr3->A[k++] = arr2.A[j]; 
    */

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int SetMembership(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
