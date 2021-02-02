#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int size;
    int length;
    int arr[10];
};

void display(struct Array *array)
{

    for (int i = 0; i < array->length; i++)
    {
        printf("%d ", (*array).arr[i]);
    }
    printf("Length of The Array -> %d\n", array->length);
}

void insert(struct Array *array, int value)
{
    int i;
    for (i = array->length - 1; i > 0; i--)
    {
        if (value < array->arr[i])
        {
            array->arr[i + 1] = array->arr[i];
        }
    }
    array->arr[i + 1] = value;
    array->length++;
}

struct Array *merge(struct Array *array1, struct Array *array2)
{
    struct Array *array3 = (struct Array *)malloc(sizeof(struct Array));
    int i = 0, j = 0, k = 0;
    while (i < array1->length && j < array2->length)
    {
        if (array1->arr[i] < array2->arr[j])
            array3->arr[k++] = array1->arr[i++];
        if (array1->arr[i] > array2->arr[j])
            array3->arr[k++] = array2->arr[j++];
    }
    for (; i < array1->length; i++)
        array3->arr[k++] = array1->arr[i];
    for (; j < array2->length; j++)
        array3->arr[k++] = array2->arr[j];

    array3->length = array1->length + array2->length;
    array3->size;

    return array3;
}

int isSorted(struct Array *array)
{
    for (int i = 0; i < array->length - 1; i++)
    {
        if (array->arr[i] > array->arr[i + 1])
            return 0;
    }

    return 1;
}

void reArrange(struct Array *array)
{
    int temp;
    for (int i = 0, j = array->length - 1; j > i;)
    {
        while (array->arr[i] < 0)
            i++;
        while (array->arr[j] > 0)
            j--;
        if (j > i)
        {
            temp = array->arr[i];
            array->arr[i] = array->arr[j];
            array->arr[j] = temp;
        }
    }
}

int main()
{

    struct Array array1 =
        {
            10,
            5,
            {1, 3, 5, 7, 9}};
    struct Array array2 =
        {
            10,
            4,
            {2, 4, 6, 8}};

    // Merging Two Sorted Array
    display(&array1);
    display(&array2);
    display(merge(&array1, &array2));

    // Insertion in Sorted Array
    display(&array1);
    insert(&array1, 2);
    display(&array1);
    printf("%d\n", isSorted(&array1));

    // Re-Arranging -ve & +ve Elements in Sorted Array
    struct Array array3 =
        {
            10,
            5,
            {2, -4, 6, 8, -10}};
    display(&array3);
    reArrange(&array3);
    display(&array3);
    return 0;
}