#include <bits/stdc++.h>
const int maxn=100005;

using namespace std;

typedef long long ll ;

void init(void)
{
    int m=floor(sqrt(k)+0.5);
    for(int i = 2; i<=m; i++){//对K质因数分解
        if(k%i==0){
            prime[++cnt] = i;
            while(k%i==0){
                k /= i;
                pcnt[cnt]++;
            }
        }
    }
    if(k>1){
        prime[++cnt] = k;
        pcnt[cnt] = 1;
    }

}

int p,n,k;
int a[maxn];
ll ans;
int prime[50];//从1开始编号
int pcnt[50];
int b[maxn][50];
int c[50];
int main()
{
    scanf("%d%d",&n,&k);
    int cnt = 0;

    init();

    for(int i = 1; i<=n; i++){
        scanf("%d",&a[i]);
        for(int j = 1; j<=cnt; j++){//对a[i]进行关于k质因子的分解
            while(a[i]%prime[j]==0){
                b[i][j]++;
                a[i] /= prime[j];
            }
        }
    }
    int i = 1,j = 0;
    while(i<=n){
        int flag = false;
        while(j<=n && !flag){
            j++;
            flag = true;
            for(int w = 1; w<=cnt; w++){
                c[w] += b[j][w];
                flag &= (c[w]>=pcnt[w]);
            }
        }
        if(!flag)   break;
        while(flag && i<=j){                //这里用while因为是乘法
            ans += n-j+1;                 //因为是乘法
            for(int w = 1; w<=cnt; w++){
                c[w] -= b[i][w];
                flag &= (c[w]>=pcnt[w]);
            }
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
