
// 贪心。和上学期算法期末考试一道题很像。
//这里读题的时候想了一会儿才发现每道题没有说完成耗时，那么就是说一个时间点就完成了
//期末那道题还考虑到占用时间，这里占用时间就是1
//总之就算每道题尽量拖到允许时间的最后再执行，这样可以给其他题留下更多时间。（像一条线段上窗口越靠后越好）
//因为这里还有罚时，贪心策略是罚时越高越先优执行
//所以先根据罚时排序，然后从高优先级的problem开始，尽量靠后的找到时间点;


#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct problem{
    int time,penalty;
    bool operator <(const problem &tmp)const{
        return penalty>tmp.penalty;
    }
};

/*
 if(a.grade != b.grade) 
        return a.grade < b.grade; 
    else if(t != 0)
        return t < 0; 
    else
        return a.age < b.age;
*/

problem probs[3005];
int T=0,casee=0,n;

bool vis[3005];  

// 50000*3000=150000000=1.5e8.  [-2^31,2^31),即-2147483648~2147483647约等于2e9,没超
int solve()  
{  
    int res = 0;
	memset(vis, 0, sizeof(vis));  
    for(int i = 0; i < n; i++){  
        bool ok = false;
		for(int j= probs[i].time; j >= 1; j--) { //time 从 1开始所以>=1
            if(!vis[j]) {       //还没被占用，就在这里完成  
                vis[j] = true;  
                ok = true;  
                break;  
            }  
        } 
        if(!ok) res += probs[i].penalty;  
    } 
    return res;  
}  

int main(){

    cin>>T;
    while(T--){
        cin>>n;
        if(casee!=0)
            cout<<endl;
        casee++;
        printf("Case %d:\n",casee);
        for(int i=0;i<n;i++)
            cin>>probs[i].time>>probs[i].penalty;
        sort(probs,probs+n);
        printf("%d\n",solve());
    }
    system("pause");
    return 0;
}