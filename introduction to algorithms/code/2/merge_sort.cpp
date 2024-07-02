#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

void merge(int A[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    /// to do: optimize allocation
    int* pl=new int[n1+2];
    int* pr=new int[n2+2];
    for(int i=1;i<=n1;i++){
        pl[i]=A[p+i-1];
    }
    for(int j=1;j<=n2;j++){
        pr[j]=A[q+j];
    }
    pl[n1+1]=INT_MAX;
    pr[n2+1]=INT_MAX;
    int i=1;
    int j=1;
    for(int k=p;k<=r;k++){
        if(pl[i]<pr[j]){
            A[k]=pl[i];
            i=i+1;
        }
        else{
            A[k]=pr[j];
            j=j+1;
        }
    }
    delete[] pr;
    delete[] pl;
}

void merge_sort(int A[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
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
    merge_sort(A,1,length);
    dump(A,length);
    assert(A[1]==1);
    assert(A[length]==6);
}

int main(){
  test();
  return 0;  
}