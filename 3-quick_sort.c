#include "sort.h"

#define MAX_SIZE 1000
/**
 * swap - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions an array using the
 * Lomuto partition scheme.
 * @array: Pointer to the first element of
 * the array to partition.
 * @low: The lowest index of the partition.
 * @high: The highest index of the partition.
 * @size: The size of the array.
 * Return: The final pivot index.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	if (i != high)
		print_array(array, size);
	return (i);
}

/**
* quick_sort - function that sorts an array
* of integers in ascending order using the
* Quick sort algorithm.
* @array: The array to be sorted.
* @size: The size of array.
*/
void quick_sort(int *array, size_t size)
{
	int stack[MAX_SIZE];
	int top = -1;
	int high, low, pi;

	stack[++top] = 0;
	stack[++top] = size - 1;

	while (top >= 0)
	{
		high = stack[top--];
		low = stack[top--];
		pi = partition(array, low, high, size);

		if (pi - 1 > low)
		{
			stack[++top] = low;
			stack[++top] = pi - 1;
		}

		if (pi + 1 < high)
		{
			stack[++top] = pi + 1;
			stack[++top] = high;
		}
	}
}
