#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

void dump(int a[],int n){
    for (int i=0;i<=n-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

template<typename T>
int Partition(T A[], int low, int high){
    int pivot=A[low];
    while(low<high){
        while(low<high && pivot<=A[high]){
            --high;
        }
        A[low]=A[high];
        while(low<high && A[low]<=pivot){
            ++low;
        }
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}

template<typename T>
void QuickSort(T A[], int low, int high){
    if(low<high){
        int pivot=Partition(A,low,high);
        QuickSort(A,low,pivot-1);
        QuickSort(A,pivot+1,high);
    }
}

template<typename T>
void QuickSort(T A[],int len){
    QuickSort(A,0,len-1);
}

// 非递归实现

struct Range{
    int start,end;
    Range(int s=0,int e=0){
        start=s;
        end=e;
    }
};

template<typename T>
void quick_sort(T arr[], const int len){
    if(len<=0){
        return;
    }
    Range r[len];
    int p=0;
    r[p++]=Range(0,len-1);
    while(p){
        Range range=r[--p];
        if(range.start>=range.end){
            continue;
        }
        T mid=arr[range.end];
        int left=range.start,right=range.end-1;
        while(left<right){
            while(arr[left]<mid && left<right){
                left++;
            }
            while(arr[right]>=mid && left<right){
                right--;
            }
            swap(arr[left],arr[right]);
        }
        if(arr[left]>=arr[range.end]){
            swap(arr[left],arr[range.end]);
        }
        else{
            left++;
        }
        r[p++]=Range(range.start,left-1);
        r[p++]=Range(left+1,range.end);
    }
}

// 三路快速排序

template<typename T>
void three_way_radix_quick_sort(T arr[], const int len){
    if(len<=1){
        return;
    }
    // 随机选择基准（pivot）
    const T pivot=arr[rand()%len];
    // i：当前操作的元素下标
    // arr[0, j)：存储小于 pivot 的元素
    // arr[k, len)：存储大于 pivot 的元素
    int i=0,j=0,k=len;
    // 完成一趟三路快排，将序列分为：
    // 小于 pivot 的元素 | 等于 pivot 的元素 | 大于 pivot 的元素
    while(i<k){
        if(arr[i]<pivot){
            swap(arr[i++],arr[j++]);
        }
        else if(pivot<arr[i]){
            swap(arr[i],arr[--k]);
        }
        else{
            i++;
        }
    }
    // 递归完成对于两个子序列的快速排序
    three_way_radix_quick_sort(arr,j);
    three_way_radix_quick_sort(arr+k,len-k);
}

void test1(){
    int a[]={5,15,2,13,8,4,16,6,7,12,1,3,10,9,14,11};
    int n=sizeof(a)/sizeof(a[0]);
    QuickSort(a,n);
    dump(a,n);
    assert(a[0]==1);
    assert(a[n-1]==n);
}

void test2(){
    int a[]={5,15,2,13,8,4,16,6,7,12,1,3,10,9,14,11};
    int n=sizeof(a)/sizeof(a[0]);
    quick_sort(a,n);
    dump(a,n);
    assert(a[0]==1);
    assert(a[n-1]==n);
}

void test3(){
    int a[]={5,15,2,13,8,4,16,6,7,12,1,3,10,9,14,11};
    int n=sizeof(a)/sizeof(a[0]);
    three_way_radix_quick_sort(a,n);
    dump(a,n);
    assert(a[0]==1);
    assert(a[n-1]==n);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}