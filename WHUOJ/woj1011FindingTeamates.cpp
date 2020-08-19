/*

一般题。

# description
Big day is coming!
The Wuhan University Collegiate Programming Contest (WHUCPC 2006) will be held in this April. All the ACM lovers, excellent programmers and
computer geniuses in Wuhan University are of great joy, sweeping lots of problems at the Online Judges as preparation, waiting for this big day
to come.However, some students are still in trouble, because they have not found their teammates yet. So the WHUCPC Committee decided to
help these students. All the students that have no teammates are gathered in Peng Kun Square. The method to help them to find their
teammates is quite straightforward: all the students stand in a row, if some consecutive students form an increasing sequence
in their height, then these students must be put in the same team. That is, if there are 4 students who form an increasing sequence,
they must be put in one team and can't be divided long longo more than one team.
For example, if there are six students, standing as the following figure shows:

1 3 4 5 2 6

Where 1 represents the shortest student, and 6 represents the tallest student, etc.
Since (1, 3, 4, 5) forms an increasing sequence, they should put in the same team, and 2, 6 forms another increasing sequence,
so 2, 6 are put long longo another team. However, as we all know, the ACM teams are required 3 members each. In the above case, team 1
has 4 members, so the above alignment is invalid. The following figure shows some of the valid alignments:

1 3 4 2 5 6

But in some special cases, if the number of students cannot be divided evenly by 3, we ALLOW the LAST team has less than 3 members.
So if there are 5 students, the follow figure shows some of the valid and invalid alignments:

2 3 4 1 5 (ok) {234} {15}
1 5 2 3 4 (no) {15} {2 3 4 }  team1 is not the last team

Now, given the number of the students, your mission is to tell us how many valid alignments there are.
Note, no two students are of the same height.

# input
There are several test cases.
Each case contains a single long longeger n, representing the number of students who need to find teammates. (1<=n<=25)
# output
Output an long longeger in a single line, which is the number of valid alignments. You are ensured that the result is less than 2^63.
# Sample input
2
3
4
6
9
# Sample output
1 
1
3
19
1513

# analyse
3人一队，n形如3x+y，y=012.
一看感觉是递推(直接从n想我是想不出来)，先想了catalan，然后不对，估计就是自己推了。
假设知道了f(n)，然后加了一个数y，那么至少有一种解就是y放在最后，ans+f(N)
然后y放到前面某个位置，就发现，其实相当于把n+1序列分成两个子序列（因为是递增无重复）f（x）f（n+1-x）。
这里每一组都可以看成1...x，因为无重复且递增，就有了递推
然后考虑y的位置，假设index从1开始，那必须是3*x，否则不满足3人一队的条件。这样选择有n/3种。
然后这n/3种位置就有n/3种f（3x）f（n+1-3x）。
设x为数组下标，那么设y到了x组，这种方案，为f(3*x-1)(y固定在3x位置)*f(n+1-3*x)(后面的)*C(n,3x-1)  (挑出放在前面的3x-1个数)
最后想特殊情况，没想到，就代入4试试
带入4算得4，这时候想到问题是，1234这种不符合要求(刚刚忘了排除了)
解决，直接n+1/3找合适位置
然后又有问题是当n+1%2==2时其实是可以放在最后的，特判就行
然后就这样写吧

最后是经验：想不出来，就试试递推
先想一般情况
再考虑有没有特殊情况
代入试一试
*/

#include<iostream>
#include<cstdio>

using namespace std;


long long combine(int n,int m){  
    if(m>n-m)       //一开始没有优化错了。一方面减循环，一方面减少乘法溢出
    m=n-m;
    long long x=1,y=1,z=2;
    for(int i=n-m+1;i<=n;i++)
        x*=i;
    for(int i=1;i<=m;i++)
        y*=i;
    return x/y;

}

long long func(int n){
    /*
    if(n==0)
        return 0;   //一开始写成0了....这样返回后一乘就没了....
        */
    if(n>=0&&n<4)
        return 1;
    int cnt=(n)/3;
    long long ans=0;                     //注意ll
    for(int i=1;i<=cnt;i++){
        ans+=func(3*i-1)*func(n-3*i)*combine(n-1,3*i-1);
    }
    if(n%3==2)
        ans+=func(n-1);
    return ans;
}

int main(){
    int n;
    while(cin>>n){
        cout<<func(n)<<endl;
    }
    return 0;
}