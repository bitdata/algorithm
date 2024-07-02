#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
#include <bits/stdc++.h>

int merge(int a[],int p,int q,int r){
    int count=0;
    int n1=q-p+1;
    int n2=r-q;
    /// to do: optimize allocation
    int* pl=new int[n1+2];
    int* pr=new int[n2+2];
    for(int i=1;i<=n1;i++){
        pl[i]=a[p+i-1];
    }
    for(int j=1;j<=n2;j++){
        pr[j]=a[q+j];
    }
    pl[n1+1]=INT_MAX;
    pr[n2+1]=INT_MAX;
    int i=1;
    int j=1;
    for(int k=p;k<=r;k++){
        if(pl[i]<=pr[j]){
            a[k]=pl[i];
            i=i+1;
        }
        else{
            a[k]=pr[j];
            count+=q-k+j;
            j=j+1;
        }
    }
    delete[] pr;
    delete[] pl;
    return count;
}

int inversion(int a[],int p,int r){
    if(p>=r){
        return 0;
    }
    int count=0;
    int q=(p+r)/2;
    count+=inversion(a,p,q);
    count+=inversion(a,q+1,r);
    count+=merge(a,p,q,r);
    return count;
}

void dump(int a[],int length){
    for (int i=1;i<=length;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

void test1(){
    int a[]={0,2,3,8,6,1};
    int length=sizeof(a)/sizeof(a[0])-1;
    int count=inversion(a,1,length);
    assert(5==count);
}

void test2(){
    int n=100;
    int* p=new int[n+1];
    for(int i=1;i<=n;i++){
      p[i]=n+1-i;
    }
    int count=inversion(p,1,n);
    assert((n*(n-1)/2)==count);
}

int main(){
  test1();
  test2();
  return 0;  
}