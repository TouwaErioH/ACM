/*
(1) a[i+2][j+1]=(a[i][j]-a[i+2][j]-a[i+2][j+2])/2;

(2) a[i+1][j]=a[i+2][j+1]+a[i+2][j];

(3) a[i+1][j+1]=a[i+2][j+1]+a[i+2][j+2];
*/
#include<iostream>
#include<cstring>
using namespace std;

int mp[10][12];

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        memset(mp,sizeof(mp),0);
        for (int i = 1; i < 10; i+=2)
    		for (int j = 1; j < i + 1; j += 2)
    			cin >> mp[i][j];
    		for (int i = 7; i >= 1; i-=2)
    		{
    			for (int j = 1; j < i + 1; j += 2)
    			{
    				mp[i + 2][j + 1] = (mp[i][j] -mp[i + 2][j] - mp[i + 2][j + 2]) / 2;
    				mp[i + 1][j] =mp[i + 2][j + 1] + mp[i + 2][j];
    				mp[i + 1][j + 1] = mp[i + 2][j + 1] + mp[i + 2][j + 2];
    			}
    		}
    		for (int i = 1; i < 10;i++)
            {
    		for (int j = 1; j < i; j++)
    			cout<<mp[i][j]<<' ';
    			cout<<mp[i][i]<<endl;
            }

    }
    return 0;
}
