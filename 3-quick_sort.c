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

	/* Scanning array from start and swap as needed */
	size_t i = low;

	while (i < high)
	{
		if (array[i] <= pivot)
		{
			/* Swap the elements at low and i */
			swap(&array[low], &array[i]);
			/* Print if low and i are not pointing at the same element */
			if (low != i)
				print_array(array, size);

					/* Always increment low after doing a swap */
					low++;
		}

		/* Always increment i after each check */
		i++;
	}

	/* Finally, swap the pivot to its final place */
	swap(&array[low], &array[high]);
	if (low != high)
		print_array(array, size);

	/* Return the final index of the pivot */
	return (low);
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
