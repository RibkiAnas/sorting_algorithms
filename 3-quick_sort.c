#include "sort.h"

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
 * quicksort - Sorts an array of integers in
 * ascending order using
 * the Quick sort algorithm and the Lomuto
 * partition scheme.
 * @array: Pointer to the first element of
 * the array to sort.
 * @low: The lowest index of the partition to
 * sort.
 * @high: The highest index of the partition
 * to sort.
 * @size: The size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
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
	quicksort(array, 0, size - 1, size);
}
