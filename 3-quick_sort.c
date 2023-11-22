#include "sort.h"

void swap(int *array, ssize_t index1, ssize_t index2);
void quick_sort(int *array, size_t size);
void quicksort_recursion(int *array, ssize_t first, ssize_t last, int size);
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size);

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array.
 * @index1: Index of the first element.
 * @index2: Index of the second element.
 */
void swap(int *array, ssize_t index1, ssize_t index2)
{
	int temp = array[index1];

	array[index1] = array[index2];
	array[index2] = temp;
}

/**
 * quick_sort - Prepares the terrain for the QuickSort algorithm.
 * @array: The array.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_recursion(array, 0, size - 1, size);
}

/**
 * quicksort_recursion - QuickSort algorithm implementation.
 * @array: The array.
 * @first: Index of the first array element.
 * @last: Index of the last array element.
 * @size: The size of the array.
 */
void quicksort_recursion(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t pivot_index = 0;

	if (first < last)
	{
		pivot_index = lomuto_partition(array, first, last, size);
		quicksort_recursion(array, first, pivot_index - 1, size);
		quicksort_recursion(array, pivot_index + 1, last, size);
	}
}

/**
 * lomuto_partition - Lomuto partition sorting scheme implementation.
 * @array: The array.
 * @first: Index of the first array element.
 * @last: Index of the last array element.
 * @size: The size of the array.
 * Return: The position of the last element sorted.
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot_value = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot_value)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}

	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}

	return (current);
}
