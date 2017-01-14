#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

void _merge(int *A, int low,int mid, int high)
{
    int *helper=(int *)malloc(6* sizeof(int));

    for(int i=low;i<=high;i++)
        helper[i]=A[i];

    int left=low, right=mid+1, cur=low;

    while(left<=mid and right<=high )
    {
        if(helper[left]>helper[right]) A[cur]=helper[right],right++;
        else if(helper[left]<=helper[right]) A[cur]=helper[left],left++;

        cur++;
    }

    int x=mid-left;
    for(int i=0;i<=x;i++) A[cur+i]=helper[left+i];

}

void merge_sort(int *A, int low, int high)
{
    if(low>=high) return;

    int mid=(low+high)/2;
    merge_sort(A,low,mid);
    merge_sort(A,mid+1,high);

    _merge(A,low,mid,high);

}



int main()
{
    int A[]={34,1,3,14,34,2};

    merge_sort(A,0,5);

    for(int i=0;i<6;i++) cout<<A[i]<<" ";
    cout<<endl;

    return 0;
}
