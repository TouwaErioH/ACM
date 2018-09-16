/*
���� tmp �� n/i ��ֵ����n == 10��ʱ��ȡ����ֵ��
�� tmp = 1 ʱ������ ��10/1 - 10/2 == 5��

�� tmp = 2 ʱ������ ��10/2 - 10/3 == 2��

�� tmp = 3 ʱ������ ��10/3 - 10/4 == 1��
��������
�� tmp = 10ʱ��������10/10 - 10/11 == 1��
�������Ƿ����и������ˣ���tmp == i ��ʱ������Ҫ��ĸ������� 10/i - 10/(i+1)��Ȼ������ǰ1 �� sqrt(n)��������ֵ���ǱȽϴ�ģ��������ݷ�Χ��С��
���������������ʣ�µ� sqrt(n)+1 �� n������ ���ݷ�Χ���ǱȽϴ󣬵��� n/i �����ݷ�Χ���� 1 - sqrt(n)֮�䣬�����������ҳ��Ĺ��ɿ��������

*/
#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
int main()
{
    int T;
    LL n;
    cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        cin>>n;
        int m = sqrt(n);
        LL ret = 0;
        for(int i=1; i<=m; i++)
            ret += n/i;
        for(int i=1; i<=m; i++)
            ret += (n/i - n/(i+1))*i;
        if(m == n/m)                  //ȥ�أ���x/sqrt(x)=sqrt(x)
            ret -= m;
        cout<<"Case "<<cas<<": "<<ret<<endl;
    }
    return 0;
}
