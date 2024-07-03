#include <stdio.h>
#include <cstring>
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

int c[11];
int w=sizeof(c)/sizeof(c[0])-1;

void counting_sort(int a[], int n,int b[]){
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        c[a[i]]++;
    }
    for(int i=1;i<w;i++){
        c[i+1]+=c[i];
    }
    for(int i=n;i>=1;i--){
        /// a[i]在c[]中的累计计数决定a[i]的在b[]中的位置
        b[c[a[i]]--]=a[i];
    }
}

void test(){
    int a[]={0,5,2,8,4,6,7,1,3};
    int b[sizeof(a)/sizeof(a[0])];
    int n=sizeof(a)/sizeof(a[0])-1;
    counting_sort(a,n,b);
    dump(b,n);
    assert(b[1]==1);
    assert(b[n]==n);
}

int main()
{
    test();

    return 0;
}