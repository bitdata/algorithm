#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

tuple<int,int,int> find_max_subarray(int a[], int low, int high){
    if(low>high){
        return make_tuple(low,high,0);
    }
    if(low==high){
        return make_tuple(low,high,a[low]);
    }

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

int find_max_two_subarray(int a[], int low, int high){
    tuple<int,int,int> result=find_max_subarray(a,low,high);
    int left=get<0>(result);
    int right=get<1>(result);
    tuple<int,int,int> result_left=find_max_subarray(a,low,left-1);
    tuple<int,int,int> result_right=find_max_subarray(a,right+1,high);
    for(int i=left;i<=right;i++)
    {
        a[i]=-a[i];
    }
    tuple<int,int,int> result_middle=find_max_subarray(a,left,right);
    for(int i=left;i<=right;i++)
    {
        a[i]=-a[i];
    }
    int max3=max(max(get<2>(result_left),get<2>(result_right)),get<2>(result_middle));
    return get<2>(result)+max3;
}

void test(){
    int a[]={0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int length=sizeof(a)/sizeof(a[0])-1;
    int sum=find_max_two_subarray(a,1,length);
    cout<<"sum:"<<sum<<endl;
}

int main(){
  test();
  return 0;  
}