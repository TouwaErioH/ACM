#include<cstdio>
#include<cmath>
using namespace std;

int main ()
{
    int n ,m;
    double Ans;
    while(~scanf("%d %d" ,&n ,&m))
    {
        Ans = 0;
        for(int i = 1 ;i < n ;i ++)
        {
           double pos = i * 1.0 / n * (n + m);
           double now = abs(pos - int(pos + 0.5)) / (n + m);
           Ans += now;
        }
        printf("%.4lf\n" ,Ans * 10000);
    }
    return 0;
}
