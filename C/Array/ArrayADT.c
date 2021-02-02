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

int del(struct Array *array, int index)
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

int rBSearch(struct Array *array, int key, int low, int high)
{
    int mid = 0;
    if (high > low)
    {
        mid = (low + high) / 2;
        if (array->arr[mid] == key)
            return mid;
        else if (key < array->arr[mid])
            return rBSearch(array, key, low, mid - 1);
        else if (key > array->arr[mid])
            return rBSearch(array, key, mid + 1, high);
    }
    return -1;
}

int get(struct Array *array, int index)
{
    if (index >= 0 && index < array->length)
    {
        return array->arr[index];
    }
}

void set(struct Array *array, int index, int value)
{
    if (index >= 0 && index < array->length)
    {
        array->arr[index] = value;
    }
}

int max(struct Array *array)
{
    int max = array->arr[0];

    for (int i = 1; i < array->length; i++)
    {
        if (array->arr[i] > max)
        {
            max = array->arr[i];
        }
    }
    return max;
}

int min(struct Array *array)
{
    int min = array->arr[0];

    for (int i = 1; i < array->length; i++)
    {
        if (array->arr[i] < min)
        {
            min = array->arr[i];
        }
    }
    return min;
}

int sum(struct Array *array)
{
    int sum = 0;
    for (int i = 0; i < array->length; i++)
    {
        sum += array->arr[i];
    }
    return sum;
}

int avg(struct Array *array)
{
    int sum = 0;
    for (int i = 0; i < array->length; i++)
    {
        sum += array->arr[i];
    }
    return sum / array->length;
}

void reverse(struct Array *array)
{
    int temp;
    for (int i = 0, j = array->length - 1; i < j; i++, j--)
    {
        temp = array->arr[i];
        array->arr[i] = array->arr[j];
        array->arr[j] = temp;
    }
}

void lShift(struct Array *array)
{
    for (int i = 0; i < array->length; i++)
    {
        array->arr[i] = array->arr[i + 1];
    }
    array->arr[array->length - 1] = 0;
}

void rShift(struct Array *array)
{
    for (int i = array->length - 1; i > 0; i--)
    {
        array->arr[i] = array->arr[i - 1];
    }
    array->arr[0] = 0;
}

void lRotate(struct Array *array)
{
    int x = array->arr[0];
    for (int i = 0; i < array->length; i++)
    {
        array->arr[i] = array->arr[i + 1];
    }
    array->arr[array->length - 1] = x;
}

void rRotate(struct Array *array)
{
    int x = array->arr[array->length - 1];
    for (int i = array->length - 1; i > 0; i--)
    {
        array->arr[i] = array->arr[i - 1];
    }
    array->arr[0] = x;
}

int main()
{
    struct Array *array = (struct Array *)malloc(sizeof(struct Array)); // Dynamic Structure Memory Allocation
    (*array).size = 10;                                                 // Size of continuos heap memory
    (*array).length = 5;                                                // Length of Array
    (*array).arr = (int *)malloc(10 * sizeof(int));                     // Dynamic Array Memory Allocation

    // Populating Array
    for (int i = 0; i < array->length; i++)
    {
        array->arr[i] = (i + 1) * 5;
    }

    // Insertion
    add(array, 30);
    insert(array, 0, 0);

    // Display
    display(array);

    // Deletion
    printf("\n%d\n", del(array, 0));
    display(array);
    printf("\n%d\n", del(array, 3));
    display(array);

    // Searching
    printf("\n%d", lSearch(array, 29));                    // Linear Search
    printf("\n%d", bSearch(array, 29));                    // Binary Search Iterative
    printf("\n%d", rBSearch(array, 30, 0, array->length)); // Binary Search Recursive

    // Get(), Set(), Avg(), Max(), Min(), Sum()
    display(array);
    printf("\n%d\n", get(array, 4));
    set(array, 4, 50);
    display(array);
    printf("\n%d", avg(array));
    printf("\n%d", max(array));
    printf("\n%d", min(array));
    printf("\n%d\n", sum(array));

    // Reverse Array
    display(array);
    printf("\n");
    reverse(array); // Mutating Existing Array
    display(array);

    // Shifting Array
    printf("\n");
    lShift(array); // Left Shifting Array
    display(array);
    printf("\n");
    rShift(array); // Right Shifting Array
    display(array);

    // Rotating Array
    printf("\n");
    lRotate(array); // Left Rotating Array
    display(array);
    printf("\n");
    rRotate(array); // Right Rotating Array
    display(array);

    return 0;
}
