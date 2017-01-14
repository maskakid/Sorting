#include<bits/stdc++.h>
using namespace std;

int _partition(int *A, int left, int right)
{
    int pivot=A[(left+right)/2];

    while(left<=right)
    {
        while(A[left]<pivot) left++;
        while(A[right]>pivot) right--;
        if(left<=right)
        {
            swap(A[left],A[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quick_sort(int *A, int low, int high)
{
    if(low>=high) return;
    int index=_partition(A,low,high);

    if(low<index-1)
        quick_sort(A,low,index-1);

    if(index<high)
        quick_sort(A,index,high);
}

int main()
{
    int A[]= {232,2,434,12,3,1};
    quick_sort(A,0,5);
    for(int i=0; i<6; i++) cout<<A[i]<<" ";
    cout<<endl;
}
