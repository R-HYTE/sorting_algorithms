#include "sort.h"

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
 * lomuto_partition - Lomuto partition sorting scheme implementation.
 * @array: The array.
 * @first: Index of the first array element.
 * @last: Index of the last array element.
 * @size: The size of the array.
 * Return: The position of the last element sorted.
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
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

/**
 * _quicksort - QuickSort algorithm implementation.
 * @array: The array.
 * @first: Index of the first array element.
 * @last: Index of the last array element.
 * @size: The size of the array.
 */
void _quicksort(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);
		_quicksort(array, first, position - 1, size);
		_quicksort(array, position + 1, last, size);
	}
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

	_quicksort(array, 0, size - 1, size);
}
