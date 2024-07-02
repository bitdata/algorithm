#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

void insert_sort(int A[], int length){
    for(int j=2;j<=length;j++){
        int key=A[j];
        // Insert A[j] into the sorted sequence
        int i=j-1;
        while(i>0 && A[i]>key){
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
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
    insert_sort(A,length);
    dump(A,length);
    assert(A[1]==1);
    assert(A[length]==6);
}

int main(){
  test();
  return 0;  
}