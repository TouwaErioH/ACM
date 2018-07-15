#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
	while(~scanf("%d",&n))
	{
	    long double sum = 0, temp = 0;
        map<long long, long long> num;
		for(int i = 1; i <= n; i++)
		{
			long long a;
			scanf("%lld",&a);
			temp += (i - 1) * a - sum - num[a - 1] + num[a + 1];
			num[a]++;
			sum += a;
		}
        cout << fixed << setprecision(0) << temp << endl;
		//printf("%.0llf\n",temp);
	}
	return 0;
}
