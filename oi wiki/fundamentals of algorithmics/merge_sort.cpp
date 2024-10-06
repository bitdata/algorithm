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

void merge(const int *a,size_t aLen,const int *b, size_t bLen, int *c){
    size_t i=0,j=0,k=0;
    while(i<aLen && j<bLen){
        if(b[j]<a[i]){
            c[k]=b[j];
            ++j;
        }
        else{
            c[k]=a[i];
            ++i;
        }
        ++k;
    }
    for(;i<aLen;++i,++k){
        c[k]=a[i];
    }
    for(;j<bLen;++j,++k){
        c[k]=b[j];
    }
}

void merge_sort(int *a, int l, int r){
    if(r-l<=1){
        return;
    }
    size_t mid=l+((r-l)>>1);
    merge_sort(a,l,mid);
    merge_sort(a,mid,r);
    int tmp[1024]={};
    merge(a+l,mid-l,a+mid,r-mid,tmp+l);
    for(int i=l;i<r;++i){
        a[i]=tmp[i];
    }
}

void test(){
    int a[]={5,15,2,13,8,4,16,6,7,12,1,3,10,9,14,11};
    int n=sizeof(a)/sizeof(a[0]);
    merge_sort(a,0,n);
    dump(a,n);
    assert(a[0]==1);
    assert(a[n-1]==n);
}


int main()
{
    test();

    return 0;
}