#include <stdio.h>

#define SIZE 8

int temp[SIZE] = {0};

void merge (int array[], int start_1, int end_1, int start_2, int end_2)
{
    //indexes for left and right halves of portion we're merging
    int i = start_1, j = start_2; 
    
    //index for temporary array
    int k = 0; 
    
    //
    while (i <= end_1 && j <= end_2)
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    
    while (i <= end_1)
    {
        temp[k] = array[i];
        i++;
        k++;
    }
    
    while (j <= end_2)
    {
        temp[k] = array[j];
        j++;
        k++;
    }
    
    for (i = start_1, j = end_2, k = 0; i <= j; i++)
    {
        array[i] = temp[k];
        k++;
    }
        
}

void sort (int array[], int start, int end)
{
    if (end > start)
    {
        int middle = (start + end) / 2;

        // sort left half
        sort(array, start, middle);

        // sort right half
        sort(array, middle + 1, end);

        // merge the two halves
        merge(array, start, middle, middle + 1, end);
    }
}

int main(void)
{
    int numbers[SIZE] = { 410, 1, 27, 28, 2, 599, 2015, 7};
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    sort(numbers, 0, SIZE - 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}

