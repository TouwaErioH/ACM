#include<bits/stdc++.h>
using namespace std;

const int MAXN=100005;
int door[MAXN];
int ctr[MAXN][2];     //记录门的两个开关
int par[MAXN*3];

void init(int m){
	for(int i=0;i<=m*2;i++)
	par[i]=i;
}
int findpar(int k)
{
	return k==par[k]?k:par[k]=findpar(par[k]);
}

void unite(int a,int b)
{
	a=findpar(a);
	b=findpar(b);
	if(a!=b)
	par[a]=b;
}

int main()
{
	int n,m,k,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        ctr[i][0]=ctr[i][1]=-1;
    }
    init(m);
	for(int i=1;i<=n;i++)
	cin>>door[i];
	for(int i=1;i<=m;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>t;
			if(ctr[t][0]==-1)
			ctr[t][0]=i;
			else
                ctr[t][1]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(door[i])
		{
			unite(ctr[i][0],ctr[i][1]);
			unite(ctr[i][0]+m,ctr[i][1]+m);
		}
		else
		{
			unite(ctr[i][0],ctr[i][1]+m);
			unite(ctr[i][0]+m,ctr[i][1]);
		}
	}
	for(int i=1;i<=m;i++)
	if(findpar(i)==findpar(i+m))
	{
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
 	return 0;
}

/*
大部分开关问题首先要想到的一点就是任何开关操作两次以上都是无意义的，因此对于每个开关，我们要么操作一次，要么不操作，对于控制的门初始状态为1的两个开关，我们要么两个都操作，要么两个都不操作，这样才能保证门的末状态为1，而控制的门初始状态为0的两个开关，我们只能而且必须操作其中一个。

有了上面的分析，我们考虑用并查集维护开关之间的关系，因为每个开关有操作和不操作两种状态，因此，我们要把每个点拆成两个点，i表示第i个开关没操作过，i+m表示第i个开关操作过，若第i个门初始状态为1，控制开关为a和b，则合并a，b和

a+m，b+m。

若初始状态为0，则合并a，b+m和b，a+m。最后判断一下如果存在i和i+m在同一个集合中则说明出现了矛盾。*/
