#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int size;
    int length;
    int *arr;
};

void display(struct Array *array)
{

    for (int i = 0; i < array->length; i++)
    {
        printf("%d ", (*array).arr[i]);
    }
    printf("Length of The Array -> %d", array->length);
}

void add(struct Array *array, int ele)
{
    if (array->length < array->size)
    {
        array->arr[array->length] = ele;
        array->length++;
    }
    else
    {
        printf("Array Out of Bound!");
    }
}

void insert(struct Array *array, int index, int ele)
{
    if (index <= array->length && index >= 0)
    {
        for (int i = array->length; i > index; i--)
        {
            array->arr[i] = array->arr[i - 1];
        }
        array->arr[index] = ele;
        array->length++;
    }
    else
    {
        printf("Array Out of Bound!");
    }
}

int delete (struct Array *array, int index)
{
    int x = -1;
    if (index >= 0 && index < array->length)
    {
        x = array->arr[index];
        for (int i = index; i < array->length; i++)
        {
            array->arr[i] = array->arr[i + 1];
        }
        array->length--;
    }

    return x;
}

int lSearch(struct Array *array, int key)
{
    for (int i = 0; i < array->length; i++)
    {
        if (array->arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int bSearch(struct Array *array, int key)
{
    int mid;
    int low = 0;
    int high = array->length - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array->arr[mid] == key)
            return mid;
        if (array->arr[low] == key)
            return low;
        if (array->arr[high] == key)
            return high;
        if (key < array->arr[mid])
            high = mid - 1;
        if (key > array->arr[mid])
            low = mid + 1;
    }
    return -1;
}

int main()
{
    struct Array array = {10, 5, (int *)malloc(10 * sizeof(int))};
    for (int i = 0; i < array.length; i++)
    {
        array.arr[i] = (i + 1) * 5;
    }
    add(&array, 30);
    insert(&array, 0, 0);
    display(&array);
    printf("\n%d\n", delete (&array, 0));
    display(&array);
    printf("\n%d\n", delete (&array, 3));
    display(&array);
    printf("\n%d", lSearch(&array, 29));
    printf("\n%d", bSearch(&array, 29));
    return 0;
}