#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 105;
char s[MAXN], t[MAXN];

int main()
{
	int T;
	(scanf("%d", &T);
    int kase = 1;
	while(T--)
	{

	    scanf("%s%s", s, t);
	    int s1 = 0, t1 = 0, len = strlen(s), d0 = 0, d1 = 0, que = 0;
	    for(int i = 0; i < len; ++i)
	    {
	        if(s[i] == '1') ++s1;
            if(t[i] == '1') ++t1;
            if(s[i] == '?') ++que;
            if(s[i] != t[i] && s[i] == '0') ++d0;
            if(s[i] != t[i] && s[i] == '1') ++d1;
        }
        printf("Case %d: ", kase++);
        if(s1 > t1)
            printf("-1\n");
            //��������Ϊdiff0 diff1��С���Ǹ��Σ�֮�����?����2*(diff0 - diff1)�β���(�ȱ��ٻ�)��ʣ�µ�?��ɶ�Ӧ��
        else //������ȫʣ1����ȫʣ0���ն���Ҫ����ÿ�����β����� ����que-(diff0 - diff1)����ʣ����ʺ�Ҫ���еĲ���
        {
           int ans=min(d0,d1)+abs(d0-d1)*2+que-abs(d0-d1);
            printf("%d\n", ans);
        }
    }
	return 0;
}

