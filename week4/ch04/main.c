#include<stdio.h>
#define N 10
void shellsort(int a[])
{
	int i, j, Tmp, increment;
	for (increment = N / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < N; i++)
		{
			Tmp = a[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (Tmp < a[j - increment]);

			{
				a[j] = a[j - increment];
		    }
				else
				{
					break;

				}
			}
			a[j] = Tmp;
		}
	}
}
int main()
{
	int i;
	int array[] = { 21,23,5,25,75,79,11,14,1,15};
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		array[i] = rand() % 1000 + 1;

	}
	shellsort(array, sizeof(array) / sizeof(array[0]));
	for (i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;

}
