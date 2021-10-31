#include <stdio.h>
#include <stdlib.h>

void Swap(int *left,int *right)
{
	int tmp;
	tmp = *left;
	*left = *right;
	*right = tmp;
}
void InsertionSort(int a[],int n)
{
    int i,p;
    int tmp;
    for(p=0;p<n;p++)
    {
        tmp=a[p];
        for(i=p;i>0&&a[i-1]>tmp;i--)
        {
            a[i]=a[i-1];
        }
        a[i]=tmp;
    }
}
int median(int a[], int left, int right) {
    if(a[left]>a[center])
        Swap(&a[left],&a[center]);
    if(a[left]>a[right])
        Swap(&a[left],&a[right]);
    if(a[center]>a[right])
        Swap(&a[center],&a[right]);
    Swap(&a[center],&a[right-1]);
    return a[right-1];
}

void Qselect(int a[],int k,int left,int right)
{
    int i,j;
    int pivot;
    if(left+3<=right)
    {
        pivot=median(a,left,right);
        i=left;
        j=right-1;
        for( ; ; )
        {
            while(a[++i]<pivot){}
            while(a[--j]>pivot){}
            if(i<j)
                Swap(&a[i],&a[j]);
            else
                break;
        }
        Swap(&a[i],&a[right-1]);
        if(k<=j)
            Qselect(a,k,left,i-1);
        else if(k>i+1)
        Qselect(a,k,i+1,right);
    }
    else
        InsertionSort(a+left,right-left+1);
}
void QuickSelect(int a[],int n,int k)
{
    Qselect(a,k,0,n-1);
}
int main() {
    //找第k个最小元//
    int a[11]={3,1,4,1,5,9,2,6,5,3,5};
    int i=5;
    QuickSelect(a,11,i);
    printf("%d ",a[i]);
    return 0;
}
