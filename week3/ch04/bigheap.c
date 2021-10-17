#include<stdio.h>
#define N 100

int Heap[N];
int Heap_size = 0;

//入堆//
void put(int d)
{
    int now, father, temp;
    Heap[Heap_size] = d;        //将新元素入堆
    Heap_size++;
    now = Heap_size-1;
    while (now >= 1){
        father = now >> 1;
        if (Heap[father] > Heap[now]){
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

//出堆//
int get()
{
    int now = 0, son, res = Heap[0], temp;
    Heap[0] = Heap[Heap_size-1];
    Heap_size--;
    //重新整理成小根堆//
    while ((now * 2 + 1) < Heap_size){
        son = now * 2 + 1;
        if ((now * 2 + 2) < Heap_size && Heap[now * 2 + 1] < Heap[now * 2 + 2]){
            son++;
        }

        temp = Heap[now];
        Heap[now] = Heap[son];
        Heap[son] = temp;
        now = son;
    }
    return res;
}

int main()
{
    int i, n;
    printf("请输入堆的长度");
    scanf("%d", &n);
    printf("请输入堆的元素");
    for (i = 0; i < n; i++){
        scanf("%d", &Heap[i]);
        put(Heap[i]);
    }
    for (i = 0; i < n; i++){
        printf("%d",get());
    }
    return 0;
}
