#include <iostream>
#include <algorithm>
#include <set>
using namespace std;//˼·��ÿ����a+1(���һ��)��x�����䣬���x+1/(a+1)����
set<int> s;

int main()
{
    int m, n, a, k, x;
    while (scanf("%d%d%d", &n, &k, &a) != EOF) {
        scanf("%d", &m);
        s.clear();
        s.insert(0), s.insert(n+1);   // ʵ�����ⳤ�ȵ�С����
        int sum = (n+1) / (a+1);
        int ans = -1, f = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &x);
            set<int>::iterator it = s.upper_bound(x);
            int r = *it;                //ĳ��
            int l = *(--it);            //ĳ��x
            sum = sum - (r-l)/(a+1) +(x-l)/(a+1) + (r-x)/(a+1);

            if (sum < k && !f) {
                ans = i;
                f = 1;
            }
            if(f)
                break;
            s.insert(x);
        }
        printf("%d\n", ans);
    }
    return 0;
}
