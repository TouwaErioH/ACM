/*
难题，dp好题，几何题（？数学题）
想明白了其实思路很简单，但是因为数据量很大优化需要考虑.
滚动数组。

# description 
You are given a chessboard made up of N squares by M squares. Some of the squares are colored black, and the others are colored white. Please
write a program to calculate the number of rectangles which are completely made up of white squares.

# 输入格式
There are multiple test cases. Each test case begins with two integer N,M (1 <= N , M<= 2000), the board size. The following N lines, each with M
characters, have only two valid character values:
b - representing a black square;
w - representing a white square.
Process to the end of file.

# 输出格式
For each test case in the input, output the number of white rectangles a line.

# 样例输入
2 3
bbb
www
2 2
bw
wb
# 样例输出
6
2

# analyse
dp经典。
f(i,j)为以点[i][j]为右下角的矩形数量，这里化为滚动数组sum。


经验教训：
这种看着像dp 的可以试一试dp，然后找递推公式的时候注意，新增的i，和原来整体对比看有什么关系或者和i-1有什么关系

几何体画图，多画几种情况，考虑全
数据量很大的时候，用滚动数组

然后这种方块题通解就是计算以[i,j]为底的矩形数累加
然后考虑数据量用long long,输出%lld

hud1510//zoj2067
ZJU的1985也可以看一看

*/




//zoj2067改woj1012，再改良版
//zoj2067改woj1012见下面的注释
#include <cstdio>
#include <cstring>
#include<iostream>
using namespace std;
int n,m;

const int maxn=2005;

char g[maxn];
int f[maxn]; //当前行x,i列上[x,i]为底的矩形高度
long long ans;  //ans很大,考虑溢出
int pre[maxn];
long long sum[maxn]; //sum[i]记录以[x,i]为右下角的所有矩形数量，这样[x,i+1]如果f[i+1]>f[i]直接查表就行
/*pre[i]为最近的比i列矩形低的矩形的距离 比如 
  a   a
a a a a  pre[2]=1,pre[3]=1.pre[i]=0表示i列是0-i中最矮列，比如pre[0]=0;
*/
int main(int argc, char *argv[])
{
    while( scanf("%d %d",&n,&m)!=EOF ){
        getchar();                       //注意，没有可不可以？
        ans=0;
        for(int i=0;i<m;i++)
            f[i]=0;
        for(int i=0; i<n; i++){  //按行建图并在建立完一行后就计算以该行上的方块为右下角的矩形数量
           scanf("%s",g);
            for(int j=0;j<m;j++)
                if(g[j]=='b')
                    f[j]=0;
                else
                    f[j]++;
            sum[0] = 0 ;
            pre[0]=0;  //初始时没有比0列更矮(或相等)的列，距离为0
            for(int j=0;j<m;j++){
                if(j==0)
                    sum[j]+=f[j];
                else if(f[j]>=f[j-1]){
                    sum[j]=f[j]+sum[j-1];
                    pre[j]=1;
                }
                else if(f[j]<f[j-1]){
                    pre[j]=pre[j-1]+1;
                    int temp=j-pre[j];
                    while(f[temp]>f[j]&&pre[temp]){  //当templie比j列高并且temp列是0-temp最矮列的时候，就没必要继续找了
                        temp=temp-pre[temp];
                    }

                    //考虑比j列矮的列就可以，不必考虑最矮列，比如高度为 1232342(0-6列)，sum[6]=sum[3]+f[6]*(6-3)，因为3之前的就算有更矮的，也已经被sum[3]计算时考虑过了
                    if(f[temp]>f[j]) //找不到比j列矮的列
                    {
                        pre[j]=0;
                        sum[j]=f[j]*(j+1);
                    }
                    else{ //找到比j列矮的列temp
                        pre[j]=j-temp;
                        sum[j]=f[j]*(j-temp)+sum[temp];
                    }
                }
            //cout<<j<<" "<<sum[j]<<"// ";  调试的时候用
            ans+=sum[j];
            }
            //cout<<endl;
        }
        printf("%d\n",ans); //这里ans考虑完了,一开始用的还是%d,一直WA，所以注意啊
    }    
    return 0;
}


/*
zoj2067改编到woj1012，超时。如果这个代码里改成m=n,判断改成=='#',zoj2067可AC
状态：f(i,j)为记录i行j列，[i][j]为底的符合要求的正方形连续组成的矩形的高度
以[i][j]为右下角的矩形初值为f(i,j)
然后在i行从j-1 到 0 遍历矩形高度，不为0就可以扩展成以[i][j]为右下角的矩形
计算每个以每个点为右下角的矩形数量求和即为解

比如
    a a
a a a a
a a a b  ,算以b为右下角的矩形的时候先算了第三列，ans+3，然后前一列高度为3=3，ans+3，然后ans+2，ans+2...


然后看到网上很多的滚动数组版，节省了时间（节省时间不是滚动数组，是滚动数组的意义和计算方法），感觉不太清楚，就按照一个思路写了上面的代码
*/

/*
//zoj2067 ac
//结果还是在woj1012 te了。
#include <cstdio>
#include <cstring>
#include<iostream>
using namespace std;
int n,m;

const int maxn=2005;

char g[maxn][maxn];
int f[maxn][maxn];
int ans,tmp;

int main(int argc, char *argv[])
{
    while( scanf("%d %d",&n,&m)!=EOF ){
        getchar();
        ans=0;
        for(int i=0; i<n; i++){  //建图
           scanf("%s",g[i]);
            for(int j=0;j<m;j++){
                if(g[i][j]=='b')  //这里也可以优化。只用一个数组表示f[i][j]就行，因为一旦该点为0就和上面没关系了，而不为0直接++就行
                    f[i][j]=0;
                else{
                    if(i==0)
                        f[i][j]=1;
                    else
                        f[i][j]=f[i-1][j]+1;
                    ans+=f[i][j];
                    tmp=f[i][j];
                    for(int k=j-1;k>=0;k--){   //然后这里可以优化，记录比前一个自己所在矩形高度低的列就行，没必要每一列都循环
                        if(f[i][k]==0)
                            break;
                        else{
                            if(tmp>f[i][k])
                                tmp=f[i][k];
                            ans+=tmp;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }    
    return 0;
}
*/

/*
网上比较多的AC代码，思路和最上面我的代码一样，但是我觉得p,pre不太容易理解
#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    char in[2001];
    long sign[2001], i, min, sum[2001], pre[2001], j, k, n, m, s, p;
    long long out;
    while (scanf("%ld %ld\n", &n, &m) != EOF)
    {
        for (i = 1; i <= m; i++) //每一列当前连续白色方块数为0
            sign[i] = 0;
        for (s = 1, out = 0; s <= n; s++)
        {
            scanf("%s",in);  //因为按行处理，保留一行就可以  gets(in)也可以，和%s一样略过了最后的\n
            for (i = 0; i < m; i++)//记录i列s行，[s][i]为底的符合要求的正方形连续组成的矩形的高度,滚动数组1,处理单列上的白方块总数
            {
                if (in[i] == 'w')  //注意这里是sign[i+1]，为了下面的处理方便
                    sign[i + 1]++;
                else
                    sign[i + 1] = 0;
            }

            //然后横向处理计算以[s][i]为右下角的矩形的数量
            for (i = 1, sign[0] = pre[0] = 0; i <= m; i++) //0列是虚构的一列。注意输入是从in[0]开始的,为了方便处理i从1开始
            {
                if (sign[i] >= sign[i - 1])//如果比前列的矩形高,以[s][i-1]为右下角的所有的矩形都可以扩展到以[s][i]为右下角的矩形，同时i列以[s][i]为右下角的矩形数量为sign[i]
                {
                    sum[i] = sum[i - 1] + sign[i];//滚动数组2,记录前i列的白方块总数
                    pre[i] = 0;   //pre[i] 比i列矩形高度低的列的距离-1
                }
                else
                {
                    pre[i] = pre[i - 1] + 1;
                    p = i - pre[i];
                    while (p > 0 && sign[p - 1] >= sign[i])//找出比这列sign[]小的列
                        p = p - pre[p - 1] - 1;
                    if (p <= 0)//这列sign[]值最小,h*w计算[s][i]为右下角的矩形就可以
                    {
                        sum[i] = sign[i] * i;
                        pre[i] = 0;
                    }
 
                    else//p列sign[]值最小,分两部分，p列前的可以扩展到[s][i]为右下角的矩形,而p列到i列可以按h*w算
                    {
                        sum[i] = sign[i] * (i - p + 1) + sum[p - 1];
                        pre[i] = i - p - 1;
                    }
                }
                out += sum[i]; //每列加一次，加新生成的矩形数
            }
        }
        printf("%lld\n", out);
    }
    return 0;

}
*/



