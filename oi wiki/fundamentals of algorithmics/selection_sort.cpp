#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

void dump(int a[],int n){
    for (int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

void selection_sort(int a[], int n){
    for(int i=1;i<n;i++){
        int ith=i;
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[ith]){
                ith=j;
            }
        }
        swap(a[i],a[ith]);
    }
}

void test(){
    int a[]={0,5,2,8,4,6,7,1,3};
    int n=sizeof(a)/sizeof(a[0])-1;
    selection_sort(a,n);
    dump(a,n);
    assert(a[1]==1);
    assert(a[n]==n);
}

int main()
{
    test();

    return 0;
}