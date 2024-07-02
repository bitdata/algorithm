#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

tuple<int,int,int> find_max_subarray(int a[], int low, int high){
    int max_left=low;
    int max_right=low;
    int min_right=low;
    int total_sum=a[low];
    int max_sum=total_sum;
    int min_sum=total_sum;
    for(int i=low+1;i<=high;i++){
        total_sum+=a[i];
        int remain_sum=total_sum-min_sum;
        if(remain_sum>max_sum){
            max_sum=remain_sum;
            max_left=min_right+1;
            max_right=i;
        }
        if(total_sum<min_sum){
            min_sum=total_sum;
            min_right=i;
        }
    }
    return make_tuple(max_left,max_right,max_sum);
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