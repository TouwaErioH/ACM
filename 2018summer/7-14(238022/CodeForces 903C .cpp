#include <cstdio>
using namespace std;
#include<algorithm>  //重复次数最多的盒子
int a[5005];
int main()
{
int n;
scanf("%d",&n);
for (int i = 0; i < n; i++)
scanf("%d",&a[i]);
sort(a, a + n);
int temp = 1;
int max = 1;
for (int i = 1; i < n; i++)
{
if (a[i] == a[i - 1])
{
temp++;
if (max < temp)
max = temp;
}
else
temp = 1;
}
printf("%d",max);
return 0;
}
