#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

const int K=3;

void dump(int a[][K],int n){
    for (int i=1;i<=n;i++){
        for(int k=1;k<K;k++){
            cout<<a[i][k];
        }
        cout<<" ";
    }
    cout<<endl;
    return;
}

void counting_sort(int a[][K], int n,int k,int b[][K]){
    int c[11];
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        c[a[i][k]]++;
    }
    for(int i=0;i<10-1;i++){
        c[i+1]+=c[i];
    }
    for(int i=n;i>=1;i--){
        memcpy(b[c[a[i][k]]--],a[i],sizeof(int)*K);
    }
    memcpy(a,b,sizeof(int)*(n+1)*K);
}

void radix_sort(int a[][K],int n, int b[][K]){
   for(int k=K-1;k>=1;k--){
       counting_sort(a,n,k,b);
   } 
}

void test(){
    int a[][K]={{0,0,0},{0,5,1},{0,2,3},{0,8,3},{0,4,6},{0,6,2},{0,7,3},{0,1,9},{0,3,3}};
    int b[sizeof(a)/sizeof(a[0][0])/K][K];
    int n=sizeof(a)/sizeof(a[0][0])/K-1;

    radix_sort(a,n,b);

    dump(a,n);
}

int main()
{
    test();

    return 0;
}