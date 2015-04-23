#include<stdio.h>
#include<stdlib.h>
void quick_sort(int * array, int left, int right)
{
	if (left > right)
		return;
	int end = right;
	int start = left;
	int base = array[start];
	while (left < right)
	{
		while (array[right] >= base && right>left)
			right--;
		if (left < right)
			array[left++] = array[right];
		while (array[left] <= base && left < right)
			left++;
		if (left < right)
			array[right--] = array[left];
	}
	array[left] = base;
	quick_sort(array, start, left - 1);
	quick_sort(array, left + 1, end);
}

int main(void)
{
	int array[9] = { 7, 8, 2, 10, 3, 5, 12, 14 };
	quick_sort(array, 0, 7);
	for (int i = 0; i < 8; i++)
		printf("%d ", array[i]);
	system("pause");

}