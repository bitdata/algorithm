#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

int partition(int A[],int p,int r){
    int x=A[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(A[j]<=x){
            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

int randomized_partition(int A[],int p,int r){
    int i=p+rand()%(r-p+1);
    swap(A[i],A[r]);
    return partition(A,p,r);
}

void randomized_quicksort(int A[],int p,int r){
    if(p<r){
        int q=randomized_partition(A,p,r);
        randomized_quicksort(A,p,q-1);
        randomized_quicksort(A,q+1,r);
    }
}

void dump(int A[],int length){
    for (int i=1;i<=length;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return;
}

void test(){
    int A[]={0,2,8,7,1,3,5,6,4};
    int length=sizeof(A)/sizeof(A[0])-1;
    randomized_quicksort(A,1,length);
    dump(A,length);
    assert(A[1]==1);
    assert(A[length]==8);
}

int main(){
  test();
  return 0;  
}