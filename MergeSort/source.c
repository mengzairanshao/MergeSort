#include <stdio.h>
#define N 18

/**
 * [swap 交换数组中的两个元素]
 * @param m [数组]
 * @param i [元素下标]
 * @param j [元素下标]
 */
void swap(int* m, int i, int j)
{
	int temp = m[i];
	m[i] = m[j];
	m[j] = temp;
}

/**
 * [merge 合并数组中的两个段]
 * @param m     [待合并的数组]
 * @param temp  [临时数组]
 * @param start [待合并数组开始的下标]
 * @param mid   [待合并数组分界的下标]
 * @param end   [待合并数组结束的下标]
 */
void merge(int* m, int *temp, int start, int mid, int end)
{
	int i = start, j = mid+1;
	/*循环直到所有元素排序完毕 */
	while (i <= mid || j <= end)
	{
		/*m[i] >= m[j]或者前半段已完全排序,而后半段未完全排序的情况*/
		if (j <= end && (m[i] >= m[j] || i > mid))
		{
			temp[i - start + j - mid - 1] = m[j];
			j++;
		}
		/* m[i] < m[j]或后半段已完全排序而前半段未完全排序的情况*/
		else if (i <= mid || j > end)
		{
			temp[i - start + j - mid - 1] = m[i];
			i++;
		}
	}
	/*将排序好的值赋值给原数组*/
	for (i = start; i <= end; m[i] = temp[i - start], i++);
}

/**
 * [mergeSort 归并排序]
 * @param m     [待排序的数组]
 * @param temp  [临时数组]
 * @param start [待排序的数组的开始下标]
 * @param end   [待排序的数组的结束下标]
 */
void mergeSort(int* m, int *temp, int start, int end)
{
	/*分解可以结束的情况*/
	if (start >= end || start < 0 || end > N - 1) return;
	/*分解到只剩下两个元素时,对其排序,并结束分解*/
	if (end - start == 1)
	{
		if (m[start] > m[end])
			swap(m, start, end);
		return;
	}
	/*分解左半部分*/
	mergeSort(m, temp,start, (int)((start + end) / 2));
	/*分解右半部分*/
	mergeSort(m,temp, (int)((start + end) / 2) + 1, end);
	/*分解排序后进行合并*/
	merge(m, temp,start, (int)((start + end) / 2), end);
}

int main()
{
	int m[N] = {0,2,1,6,5,3,4,9,8,7,11,15,18,20,50,2,3,5};
	int temp[N];
	for (int i = 0; i < N; i++)
		temp[i] = -1;
	mergeSort(m, temp,0,N - 1);
	for (int i = 0; i < N; i++)
		printf("%d ", m[i]);
	printf("\n");
	return 0;
}
