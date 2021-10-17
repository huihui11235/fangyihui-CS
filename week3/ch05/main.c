#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct heap {
	int *heap;
	int n;
	int count;
}; heap;
void swap(int* arr, int cx1, int cx2)
{
	int tmp = arr[cx1];
	arr[cx1] = arr[cx2];
	arr[cx2] = tmp;
}
void print(heap *h) {
	int n = h->n;
	int count = h->count;
	int* heap = h->heap;
	int i;
	for (i = 1; i <= count; i++)
	{
		printf("%08d\n", heap[i]);
	}
}
makeheap(int n) {
	heap* h;
	h->heap = (int*)malloc(sizeof(int) * (n + 1));
	h->n = n;
	h->count = 0;
	return h;
}
void insert(heap   *h, int e) {
	int count = h->count;
	int n = h->n;
	if (count >= n) return;
	int* heap = h->heap;
	heap[++count] = e;
	h->count = count;
	int i = count;
	while ((i / 2) > 0 && heap[i] > heap[i / 2]) {
		swap(heap, i, i / 2);
		i = 1 / 2;
	}
}
void delete(heap   *h) {
	if (h->count < 1) return;
	int count = h->count;
	int* heap = h->heap;
	heap[1] = heap[count];
	h->count = --count;
	int i = 1;
	while (true) {
		int max_pos = i;
		if (i * 2 <= count && heap[i] < heap[i * 2]) max_pos = i * 2;
		if (i * 2 + 1 <= count && heap[i] < heap[i * 2 + 1]) max_pos = i * 2 + 1;
		if (max_pos == i) break;
		swap(heap, i, max_pos);
		i = max_pos;
	}
}

int main(int argc, char* argv[])
{
	heap* h;
	h = makeheap(100);
	int arr[] = { 3,5,1,4,54,42,12,2 };
	int i;
	for (i = 0; i < sizeof(arr) / sizeof(int); i++) {
		insert(h, arr[i]);
	}
	print(h);
	printf("--------\n");
	delete(h);
	print(h);
}
