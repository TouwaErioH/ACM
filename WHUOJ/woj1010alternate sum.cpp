/*
#题意
给一个集合Q，对于每个子集中元素非降序排列后，计算a1-a2+a3-a4....=alternate sum。

比如 Q={2,1,3,4}，其本身alternate sum=4-3+2-1=2，而其中一个子集｛1，3，4｝:4-3+1=2;

求Q中所有子集的alternate sum之和。

# 输入格式
There are several test cases. For each test case, it contains:
Line 1: One integer N (1<=N<=1000) which specifies the size of set  Q
Line 2: N integers (you are ensured that the absolute value of each integer is less than 2^16) which specify the elements of set Q.
There is a blank between two consecutive integers.
The input will be ended by zero.

#输出格式
The answer of the total value may be very large, so you should divide this answer by 2006 and just output the remainder instead.

#样例输入
1
-1
2
0 4
3
1 3 2
0
#样例输出
2005
8
12

分析:这种一看是数学题，就在纸上算算。

一共有2^N个子集,单个计算是不现实的。
对于集合中最大元素maxn，包含它的子集有2^(N-1)个。其在计算中必然为 + 。有2^(N-1)个
对于第二大元素a2:包含它的子集一共有2^(N-1)个，其中一半有maxn，在计算时-a2，一半+a2。所以总的下来没影响。
其他数以此类推。
所以最后结果为maxn*2(N-1)

要说怎么想到的：学集合的时候知道子集数量是2^N，其中2就相当于每个数取不取，然后就想到2^(N-1)...
*/

#include<iostream>
#include<cstdio>
using namespace std;

int maxn,n,ans,num,i;
int main(){
    while(scanf("%d",&num)==1&&num){
        cin>>n;
        maxn=n;
        for(i=0;i<num-1;i++){
            cin>>n;
            maxn=(maxn>n)?maxn:n;
        }
        maxn=(maxn%2006+2006)%2006;  //保证是正数
        for(i=0;i<num-1;i++){
            maxn=maxn*2;
            maxn=maxn%2006;  //防溢出
        }
        cout<<maxn<<endl;

    }
return 0;
}

/*

被除数÷除数=商……余数。
由此可知，余数=被除数-商×除数 (*)

以下摘录自C++ Primer（P130）

操作符%称为“求余”或“求模”操作符，该操作符的操作数只能为整型。

如果两个操作数为正，结果也为正；如果两个操作数都为负数，结果也为负数；如果一个操作数为正数，一个操作数为负数，求模结果的符号取决于机器。

当操作数中有一个为负，一个为正是，求模操作结果值的符号可依据分子（被除数）或分母（除数）的符号而定。
如果求模的结果随分子的符号，则除出来的值向零一侧取整；如果求模与分母的符号匹配，则除出来的值向负无穷大一侧取整。

取模运算https://baike.baidu.com/item/%E5%8F%96%E6%A8%A1%E8%BF%90%E7%AE%97/10739384?fr=aladdin
*/