#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

int parent(int i){
    return i/2;
}

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}

void max_heapify(int A[],int heap_size,int i){
    int largest;
    int l=left(i);
    int r=right(i);
    if(l<=heap_size && A[l]>A[i]){
        largest=l;
    }
    else{
        largest=i;
    }
    if(r<=heap_size && A[r]>A[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(A[i],A[largest]);
        max_heapify(A,heap_size,largest);
    }
}

void build_max_heap(int A[], int length){
    int heap_size=length;
    for(int i=length/2;i>=1;i--){
        max_heapify(A,heap_size,i);
    }
}

void heapsort(int A[], int length){
    build_max_heap(A,length);
    int heap_size=length;
    for(int i=length;i>=2;i--){
        swap(A[1],A[i]);
        heap_size=heap_size-1;
        max_heapify(A,heap_size,1);
    }
}

void error(const char* message){
    cout<<message<<endl;
}

int heap_maximum(int A[]){
    return A[1];
}

int heap_extract_max(int A[],int& heap_size){
     if(heap_size<1){
        error("heap underflow");
    }

    int max=A[1];
    A[1]=A[heap_size];
    heap_size=heap_size-1;
    max_heapify(A,heap_size,1);
    return max;
}

void heap_increase_key(int A[],int i,int key){
    if(key<A[i]){
        error("new key is smaller");
    }

    A[i]=key;
    while(i>1 && A[parent(i)]<A[i]){
        swap(A[i],A[parent(i)]);
        i=parent(i);
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
    int A[]={0,2,8,4,14,1,7,16,9,10,3};
    int length=sizeof(A)/sizeof(A[0])-1;
    heapsort(A,length);
    dump(A,length);
    assert(A[1]==1);
    assert(A[length]==16);

    int B[]={0,2,8,4,14,1,7,16,9,10,3};
    build_max_heap(B,length);
    heap_increase_key(B,8,20);
    int heap_size=length;
    int max=heap_extract_max(B,heap_size);
    assert(max==20);
}

int main(){
  test();
  return 0;  
}