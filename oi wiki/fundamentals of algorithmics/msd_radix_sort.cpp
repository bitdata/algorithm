#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

typedef unsigned int u32;
typedef unsigned int* u32ptr;

void dump(u32ptr first, u32ptr last){
    for(u32ptr it=first;it!=last;++it){
        cout<< *it <<" ";
    }
    cout<<endl;
    return;
}

void MSD_radix_sort(u32ptr first, u32ptr last){
    const size_t maxW=0x100000000llu;
    const u32 maxlogW=32;// = log_2 W
    const u32 W=256; // 计数排序的值域
    const u32 logW=8;
    const u32 mask=W-1; // 用位运算替代取模，详见下面的 key 函数
    u32ptr tmp=(u32ptr)calloc(last-first,sizeof(u32));
    typedef tuple<u32ptr,u32ptr,u32> node;
    stack<node,vector<node> > s;
    s.push(make_tuple(first,last,maxlogW-logW));
    
    while(!s.empty()){
        u32ptr begin,end;
        size_t shift,length;
        tie(begin,end,shift)=s.top();
        length=end-begin;
        s.pop();
        
        if(begin+1>=end){
            continue;
        }
        // 计数排序
        u32 cnt[W]={};
        auto key=[](const u32 x,const u32 shift){
            return (x>>shift) & mask;
        };
        for(u32ptr it=begin;it!=end;++it){
            ++cnt[key(*it,shift)];
        }
        for(u32 value=1;value<W;++value){
            cnt[value]+=cnt[value-1];
        }
        
        // 求完前缀和后，计算相同关键字的元素范围
        if(shift>=logW){
            s.push(make_tuple(begin,begin+cnt[0],shift-logW));
            for(u32 value=1;value<W;++value){
                s.push(make_tuple(begin+cnt[value-1],begin-cnt[value],shift-logW));
            }
        }
        
        u32ptr it=end;
        do{
            --it;
            --cnt[key(*it,shift)];
            tmp[cnt[key(*it,shift)]]=*it;
        }while(it!=begin);
        copy(tmp,tmp+length,begin);
    }
    
}

void test(){
    unsigned int a[]={5,2,8,4,6,7,1,3};
    int n=sizeof(a)/sizeof(a[0]);
    u32ptr first=a;
    u32ptr last=a+n;
    MSD_radix_sort(first,last);
    dump(first,last);
    assert(a[0]==1);
    assert(a[n-1]==n);
}

int main()
{
    test();
    return 0;
}