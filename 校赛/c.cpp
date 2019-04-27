#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
#include<vector>
#include<map>
multimap<int,int>m1,m2;
using namespace std;
bool Comp(const int &a, const &b)
{
	return a<b;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	char c;
	int date,no;
	int qs[q];
	int flag=1;
	while(q--)
	{
		getchar();
		scanf("%c%d%d",&c,&date,&no);
		if(c=='M')
		{
			m1.insert(date,no);
		}
		else
		{
		    qs[flag]=date;
		    flag++;
		    m2.insert(date,no);

		}
	}
	vector<int>v;
	 sort(v.begin(),v.end(),Comp);


	for(int i=1;i<flag;i++)
    {
        int num=m2[qs[i]];
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), qs[i]);
			if((it-v.begin())>v.size())
                printf("-1\n");
            else
			printf("%d\n",*it);
    }
	return 0;
}
