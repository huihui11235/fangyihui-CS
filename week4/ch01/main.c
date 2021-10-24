#include"Heap.h"
#include<stdio.h>
//入堆
void putHeap(int d)
{
    int now, father, temp;
    Heap[Heap_size] = d;
    Heap_size++;
    now = Heap_size-1;
    while (now >= 1){
        father = now >> 1;
        if (Heap[father] < Heap[now]){
            break;
        }
        else{
            temp = Heap[now];
            Heap[now] = Heap[father];
            Heap[father] = temp;
            now = father;
        }
    }
}

//出堆
int getHeap()
{
    int now = 0, son, res = Heap[0], temp;
    Heap[0] = Heap[Heap_size-1];
    Heap_size--;
    //重新整理成小根堆
    while ((now * 2 + 1) < Heap_size){
        son = now * 2 + 1;
        if ((now * 2 + 2) < Heap_size && Heap[now * 2 + 1] > Heap[now * 2 + 2]){
            son++;
        }

        temp = Heap[now];
        Heap[now] = Heap[son];
        Heap[son] = temp;
        now = son;
    }
    return res;
}


int k = 3;
//初始化堆//
void KthLargest(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        putHeap(a[i]);
    }
    for (i = 0; i < (n-k); i++){
        getHeap();
    }
}

//插入元素后求其第k大值//
void add(int x)
{
    putHeap(x);

    getHeap();

    printf("第3大的值是%d",getHeap());

}

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    KthLargest(a,10);
    add(10);
    return 0;
}
