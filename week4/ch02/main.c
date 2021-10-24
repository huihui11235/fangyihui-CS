#include <stdio.h>  


void  swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void  printAaray(int array[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d  ", array[i]);

    }
    printf("\n");
}


void heap_ajust(int arr[], int start, int end)
{
   
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //   
        if (son + 1 <= end && arr[son] < arr[son + 1])   
            son++;
        if (arr[dad] > arr[son])
            return;
        else 
        {   
            swap(arr, dad, son);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}



void heap_sort(int arr[], int len) {
    int i;
    
    for (i = len / 2 - 1; i >= 0; i--)
    {
        heap_ajust(arr, i, len - 1);

    }
     
    for (i = len - 1; i > 0; --i)
    {

        swap(arr, 0, i);
        heap_ajust(arr, 0, i - 1);
    }
}

int main(int argc, char const* argv[])
{

    int arr[] = { 74,37,64,11,88,31,77,4,46,47,29,45,7,0 };
    int length = sizeof(arr) / sizeof(int);
    heap_sort(arr, length);

    printAaray(arr, length);

    return 0;
}
