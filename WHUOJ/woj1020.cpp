// 先计算差，再排序
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,S,tmp;
vector<int>nums;
vector<int>ans;
int main(){
    cin>>T;
    int casee=0;
    while(casee<T){
        nums.clear();
        ans.clear();  //每次清空
        if(casee!=0)
            cout<<endl;
        casee++;
        cin>>S;
        cin>>tmp;
        nums.push_back(tmp);
        ans.push_back(tmp);
        S--;
        while(S--)
        {
            cin>>tmp;
            nums.push_back(tmp);
            tmp=tmp-nums[nums.size()-2];
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end());
        printf("Case %d:\n",casee);
        for(int i=0;i<nums.size()-1;i++){
            cout<<ans[i]<<' ';
        }
        cout<<ans[ans.size()-1]<<endl;
    }
    //system("pause");
    return 0;
}

// sort 自己写快排
//list vector 数组模拟list https://blog.csdn.net/stormdpzh/article/details/8836268
// 学习笔记 https://blog.csdn.net/stormdpzh