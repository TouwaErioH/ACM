#include <iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int>P;
P s[10005];
bool cmp(P a,P b)
{
    return a.second>b.second;
}
int main() {
	int n,Case=1;
	while (scanf("%d", &n) && n){
		int i;
		for (i = 0; i < n; i++)
			scanf("%d%d", &s[i].first, &s[i].second);
		sort(s, s + n,cmp);
		int sum = 0,temp=0;
		for (i = 0; i < n; i++){
			sum += s[i].first;
			temp = ((sum+s[i].second)>temp )? sum+s[i].second : temp;//当前完成时间和之前的完成时间
		}
		printf("Case %d: %d\n",Case,temp);
		Case++;
	}
	return 0;

}
