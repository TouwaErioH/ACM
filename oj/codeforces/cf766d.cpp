#include<bits/stdc++.h>
using namespace std;

const int MAXN=100005;
int door[MAXN];
int ctr[MAXN][2];     //��¼�ŵ���������
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
�󲿷ֿ�����������Ҫ�뵽��һ������κο��ز����������϶���������ģ���˶���ÿ�����أ�����Ҫô����һ�Σ�Ҫô�����������ڿ��Ƶ��ų�ʼ״̬Ϊ1���������أ�����Ҫô������������Ҫô���������������������ܱ�֤�ŵ�ĩ״̬Ϊ1�������Ƶ��ų�ʼ״̬Ϊ0���������أ�����ֻ�ܶ��ұ����������һ����

��������ķ��������ǿ����ò��鼯ά������֮��Ĺ�ϵ����Ϊÿ�������в����Ͳ���������״̬����ˣ�����Ҫ��ÿ�����������㣬i��ʾ��i������û��������i+m��ʾ��i�����ز�����������i���ų�ʼ״̬Ϊ1�����ƿ���Ϊa��b����ϲ�a��b��

a+m��b+m��

����ʼ״̬Ϊ0����ϲ�a��b+m��b��a+m������ж�һ���������i��i+m��ͬһ����������˵��������ì�ܡ�*/
