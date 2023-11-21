#include "sort.h"

/**
 * swap - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t pass, current_index;

	if (array == NULL || size < 2)
		return;

	for (pass = 0; pass < size - 1; pass++)
	{
		for (current_index = 0; current_index < size - pass - 1; current_index++)
		{
			if (array[current_index] > array[current_index + 1])
			{
				swap(&array[current_index], &array[current_index + 1]);
				print_array(array, size);
			}
		}
	}
}
