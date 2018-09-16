#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		bool flag = false;
		for(int i = 0; i * a <= n; i++)
		{
			if((n - a * i) % b == 0)
			{
				flag = true; printf("YES\n%d %d\n",i, (n - a * i) / b);
				break;
			}
		}
		if(flag == false) printf("NO\n");
	}

	return 0;
}
