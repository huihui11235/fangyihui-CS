#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

struct node {
	int data[205];
	int lenth;
} La, Lb;

int main() {
	int n, m, i, j;
	int ans = 0;
	while (scanf("%d", &m) != EOF) {
		if (ans != 0) {
			printf("\n");
		}
		ans++;
		for (i = 0; i < m; i++) {
			scanf("%d", &La.data[i]);
		}
		La.lenth = m;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &Lb.data[i]);
		}
		Lb.lenth = n;
		for (i = 0; i < La.lenth; i++) {
			if (i != 0)
				printf(" ");
			printf("%d", La.data[i]);
		}
		printf("\n");
		for (i = 0; i < Lb.lenth; i++) {
			if (i != 0)
				printf(" ");
			printf("%d", Lb.data[i]);
		}
		printf("\n");
		for (i = 0; i < Lb.lenth; i++) {
			for (j = 0; j < La.lenth; j++) {
				if (La.data[j] == Lb.data[i]) {
					break;
				}
			}
			if (j == La.lenth) {
				La.lenth++;
				La.data[j] == Lb.data[i];
			}
			int k;
			for (k = 0; k < La.lenth; k++) {
				if (k != 0)
					printf(" ");
				printf("%d", La.data[k]);
			}
			printf("\n");
		}
	}
	return 0;
}
