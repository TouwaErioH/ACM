#include <cstdio>
int main()
{

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if(x == 1 || x == 2 || x == 4 || x == 5 || x == 8 || x == 11)//ÓÐ¹æÂÉ
            printf("NO\n");
        else
            printf("YES\n");
        }
        return 0;
}
