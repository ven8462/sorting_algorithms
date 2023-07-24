#include "sort.h"

/**
* quick_sort - sorts an array of integers using quick sort
*  with lomutu partition scheme
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
	/* The pivot is the rightmost element */
	int pivot = array[high];

	/* Initialize i and store the index of the smaller element */
	size_t i = low - 1;

	/* Iterate over the array from low to high */
	size_t j = low;

	while (j <= high - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			/* Swap the elements at i and j */
			swap(&array[i], &array[j]);
			/* Print if i and j are not pointing at the same element */
			if (i != j)
				print_array(array, size);
		}
		j++;
	}

	/* Swap the pivot with the element at index i+1 */
	swap(&array[i + 1], &array[high]);
	/* Print if i+1 and high are not pointing at the same element */
	if (i + 1 != high)
		print_array(array, size);

	/* Return the final index of the pivot */
	return (i + 1);
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
