    #include<bits/stdc++.h>
    using namespace std;
    const int maxn=1e6+5;//̫���ˣ�ȫ�ֱ���
    int num[maxn];
    int main(){
    	int n;
        scanf("%d",&n);
    	for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    	int sum=1;
    	int len=n-num[n];
    	for(int i=n;i>=1;i--)
        {
    		if(i<len)
    		sum++;
    		if(len>=i-num[i])//j<=i-num[i],����
    		len=i-num[i];
    	}
    	printf("%d\n",sum);
    	return 0;
    }
