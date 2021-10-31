#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	int value;
	int time;
};
struct node a[20], b[20];

int main() {
	int n, i, j, min;
	struct node t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		a[i].num = i;
		scanf("%d", &a[i].time);

	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i].value);
	}
	for (i = 1; i <= n; i++)
		for (j = i + 1; i <= n; j++)

		{
			if (a[i].time > a[j].time) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			} else if
			(a[i].time == a[j].time) {
				if
				(a[i].value < a[j].value) {
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
		}
	for (i = 1; i <= n; i++) {
		if (!b[a[i].time].num)
			b[a[i].time] = a[i];
		else {
			for (j = 1; j < a[i].time; j++) {
				if (!b[j].num) {
					b[j] = a[i];
					break;
				} else {
					min = b[1].value;
					int flag = 1;
					for (j = 2; j < a[i].time; j++)
						if (min > b[j].value) {
							min = b[j].value;
							flag = j;
						}
					if (a[i].value > min) {
						b[flag] = a[i];
					}
				}
			}
		}
	}
	int sum = 0;
	for (i = 1; i <= n; i++) {
		if (b[i].num == 0)
			continue;
		sum = sum + b[i].value;
		printf("%d ", b[i].num);
	}
	printf("\n");
	printf("%d", sum);
	return 0;
}
