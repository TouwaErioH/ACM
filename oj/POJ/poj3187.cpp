#include<cstdio>
#include<cstring>
int arr[20],vis[20],a[20],n,sum,flag;

void judge()
{
	int i,j;
	j=n;
	for(i=1;i<=n;i++)
	a[i]=arr[i];
	while(j-1)
	{
		for(i=1;i<j;i++)
	    a[i]=a[i]+a[i+1];
	    a[j]=0;
	    j--;
	}
	if(a[1]==sum)
	{
		flag=1;
		for(i=1;i<=n;i++)
	    printf("%d ",arr[i]);
	    printf("\n");
	}
	return ;
}
void dfs(int cnt)
{
	int i,j;
	if(cnt==n+1)
	{
		if(!flag)
	    judge();
	}
	else for(j=1;j<=n;j++)
	{
		if(!vis[j])
		{
			arr[cnt]=j;
			vis[j]=1;
			dfs(cnt+1);
			vis[j]=0;
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&sum)==2)
	{
		flag=0;
		arr[0]=arr[n+1]=0;
		memset(vis,0,sizeof(vis));
		dfs(1);
	}
	return 0;
}
