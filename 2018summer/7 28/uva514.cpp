#include<cstdio>
#include<stack>
using namespace std;
const int MAXN=1000+10;
int target[MAXN];

int main()
{
    int n,A,B,ok;    //A代表从A来的，B代表去B的个数，target代表目标顺序
    while(scanf("%d",&n)==1&&n)
    	{
    		stack<int> s;
    		while(1)
            {
    		scanf("%d",&target[1]);
    		if(target[1]==0)
    		     break;
    		for(int i=2;i<=n;i++)
    		{
    		     scanf("%d",&target[i]);
    		}
    		A=B=ok=1;
    		while(B<=n)  //如果驶向B的车个数等于n，则循环结束。
    		{
    			//如果驶向C的车等于驶向B的车的序列号，直接该将车驶进B
    			if(A==target[B]) { A++,B++;}
    			//否则，则判断栈顶的(即在C最上面)车是否等于驶向 B的车
    			else if(!s.empty()&&s.top()==target[B]) {s.pop(),B++;}
    			//将车驶进C
    			else if(A<=n) s.push(A++);
    			//如果车全部都驶入C，循环还没有结束，意味着所给的target顺序不能实现
    			else
    			{
    				ok=0;
    				break;
    			}
    		}
    		printf("%s\n",ok?"Yes":"No");
    		}
    		printf("\n");
    }
    return 0;
}
