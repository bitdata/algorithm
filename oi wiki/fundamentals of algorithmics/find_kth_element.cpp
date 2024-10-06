#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// 查找第rk小的数（从0开始）

template<typename T>
T find_kth_element(T arr[], int rk, const int len){
    if(len<=1){
        return arr[0];
    }
    const T pivot=arr[rand()%len];
    int i=0,j=0,k=len;
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
    if(rk<j){
        return find_kth_element(arr,rk,j);
    }
    if(rk>=k){
        return find_kth_element(arr+k,rk-k,len-k);
    }
    return pivot;
}

void test(){
    int a[]={5,15,2,13,8,4,16,6,7,12,1,3,10,9,14,11};
    int n=sizeof(a)/sizeof(a[0]);
    int x=find_kth_element(a,5,n);
    cout << x << endl;
    assert(x==6);
}


int main()
{
    test();

    return 0;
}