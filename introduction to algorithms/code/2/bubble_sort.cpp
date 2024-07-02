#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

void bubble_sort(int A[], int length){
    for(int i=1;i<=length;i++){
        for(int j=length;j>=i+1;j--){
            if(A[j]<A[j-1]){
                // exchange A[j] with A[j-1]
                int x=A[j];
                A[j]=A[j-1];
                A[j-1]=x;
            }
        }
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
    int A[]={0,5,2,4,6,1,3};
    int length=sizeof(A)/sizeof(A[0])-1;
    bubble_sort(A,length);
    dump(A,length);
    assert(A[1]==1);
    assert(A[length]==6);
}

int main(){
  test();
  return 0;  
}