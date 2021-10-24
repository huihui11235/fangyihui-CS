#pragma once
#include<stdio.h>
#define N 100

int Heap[N];//建立一个容量是N的堆数组
int Heap_size = 0;

//入堆
void putHeap(int d);

//出堆
int getHeap();
