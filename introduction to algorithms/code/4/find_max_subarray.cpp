#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

tuple<int,int,int> find_max_crossing_subarray(int a[], int low, int mid, int high){
    int left_sum=-INT_MAX;
    int max_left=-1;
    int sum=0;
    for(int i=mid;i>=low;i--){
        sum=sum+a[i];
        if(sum>left_sum){
            left_sum=sum;
            max_left=i;
        }
    }
    int right_sum=-INT_MAX;
    int max_right=-1;
    sum=0;
    for(int j=mid+1;j<=high;j++){
        sum=sum+a[j];
        right_sum=sum;
        max_right=j;
    }
    return make_tuple(max_left,max_right,left_sum+right_sum);
}

tuple<int,int,int> find_max_subarray(int a[], int low, int high){
    if(high==low){
        reutnr make_tuple(low,high,a[low]);
    }
    else{
        mid=(low+high)/2;
        tuple<int,int,int> left_result=find_max_subarray(a,low,mid);
        int left_sum=get<2>(left_result);
        tuple<int,int,int> right_result=find_max_subarray(a,mid+1,high);
        int right_sum=get<2>(right_result);
        tuple<int,int,int> cross_result=find_max_cross_subarray(a,low,mid,high);
        int cross_sum=get<2>(cross_result);
        if(left_sum>=right_sum && left_sum>=cross_sum){
            return left_result;
        }
        else if(right_sum>=left_sum && right_sum>=cross_sum){
            return right_result;
        }
        else{
            return cross_result;
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