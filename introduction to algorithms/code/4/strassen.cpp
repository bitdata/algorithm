#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

void square_matrix_multiply(int n,int m,int a[],int b[],int c[],int i0,int j0,int k0){
    int c_x=a_x;
    int c_y=b_y;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            int x=0;
            for(int k=1;k<=m;k++){
                x=x+a[(i0+i)*n+(k0+k)]*b[(k0+k)*n+(j0+j)];
            }
            c[(i0+i)*n+(j0+j)]=x;
        }
    }
}

void square_matrix_multiply(int n,int a[],int b[],int c[]){
    square_matrix_multiply(n,n,a,b,c,0,0,0);
}

void stranssen(int a[],int b[],int c[],int rows){
    int n=rows;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i*n+j]=0;
            for(int k=1;k<=n;k++){
                c[i*n+j]=c[i*n+j]+a[i*n+k]*b[k*n+j];
            }
        }
    }
}

void test(){
    int a[]={0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int length=sizeof(a)/sizeof(a[0])-1;
    tuple<int,int,int> result=find_max_subarray(a,1,length);
    int sum=get<2>(result);
    cout<<"left:"<<get<0>(result)<<",right:"<<get<1>(result)<<",sum:"<<sum<<endl;
    assert(sum==43);
}

int main(){
  test();
  return 0;  
}