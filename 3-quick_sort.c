#include "sort.h"

/**
* quick_sort - sorts an array of integers using quick sort
* with lomutu partition scheme
* @array: the array to be sorted
* @size: the size of the array
*
* Return: nothing
*/
void quick_sort(int *array, size_t size)
{
	size_t start = 0;
	size_t end = size - 1;

	if (array == NULL  || size < 2)
		return;

	recursive_sort(array, start, end, size);
}

/**
* partition - partitions the array
* @low: the start of the array
* @high: the end of the array
* @array: the array
* @size: size of array
* Return: the current position of the pivot
*/
int partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low;
	size_t j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
* recursive_sort - recursively sorts the array
* @array: the array
* @low: the first element
* @high: the last element
* @size: size of the array
* Return: nothing
*/
void recursive_sort(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		if (pivot > 0 && pivot > low)
			recursive_sort(array, low, pivot - 1, size);
		if (pivot < high)
			recursive_sort(array, pivot + 1, high, size);
	}
}
/**
* swap - swaps two elements of an array
* @a: first element
* @b: second element
*
* Return: nothing
*/

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
