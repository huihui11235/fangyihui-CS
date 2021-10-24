#include<stdio.h>
#include<string.h>
#define N  8
void
insertionsort(int a[])
{
	int i, j, temp;
	for (i= 0; i < N; i++)
	{
		temp = a[i];
		if ( a[i] < a[i - 1] )
		{
			for (j = i - 1; temp = a[j]; j--)
			{
				a[j + 1] = a[j];
		}
			a[j + 1] = temp;
		}
	}


}
int main()
{
	int a[] = { 24,35,64,6,75,79,21,57 };
	int i;
	printf("未排序前的数组为：\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n经历插入排序后的数组为：\n");

	insertionsort(a);

	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}

}
