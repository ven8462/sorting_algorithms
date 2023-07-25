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
	/* Validate input before sorting */
	if (array == NULL || size < 2)
		return;
	/*Calling helper function to perform quick sort*/
	quick_sort_split(array, 0, size - 1, size);
}

/**
 * quick_sort_split - Recursive split function for Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in @array
 */
void quick_sort_split(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	/*if low is equal to high it means there is a single element*/
	{
	/*Get the index of the pivot element after partitioning*/
	partition_index = partition(array, low, high, size);
	/*Recursively call quick_sort_split on the left and right partitions*/
	quick_sort_split(array, low, partition_index - 1, size);
	quick_sort_split(array, partition_index + 1, high, size);
	}
}

/**
 * swap_val - swaps two elements
 * @arr: array to be swapped
 * @index1: element one index
 * @index2: element two index
 * @size: Number of elements in @array
 */

void swap_val(int arr[], int index1, int index2, size_t size)
{
	if (arr[index1] != arr[index2])
		/*check if the indexes are different*/
	{
		int temp = arr[index1];

		arr[index1] = arr[index2];
		arr[index2] = temp;
		print_array(arr, size);
	}
}

/**
 * partition - divide the array into two parts based on a pivot element.
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: Last index of the partition
 * @size: Number of elements in @array
 * Return: sorted index of the pivot element
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	/*choose the last index as the pivot*/
	int i = low;
	int j;

	for (j = low; j < high ; j++)
		/*Iterate from the lowest index to the second-to-last element*/
	{
		/*check if current element is smaller than the pivot*/
		if (array[j] < pivot)
		{
			/*swap-val the current element with the element at index i*/
			swap_val(array, i, j, size);
			/*Increment index of smaller element*/
			i++;
		}
	}
	swap_val(array, i, high, size);
	/*swap-val the pivot element with element at index i*/
	return (i);
}
