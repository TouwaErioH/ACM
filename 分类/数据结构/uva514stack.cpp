#include<cstdio>
#include<stack>
using namespace std;
const int MAXN=1000+10;
int target[MAXN];

int main()
{
    int n,A,B,ok;    //A�����A���ģ�B����ȥB�ĸ�����target����Ŀ��˳��
    while(scanf("%d",&n)==1&&n)
    	{
    		stack<int> s;
    		while(1)
            {
    		scanf("%d",&target[1]);
    		if(target[1]==0)
    		     break;
    		for(int i=2;i<=n;i++)
    		{
    		     scanf("%d",&target[i]);
    		}
    		A=B=ok=1;
    		while(B<=n)  //���ʻ��B�ĳ���������n����ѭ��������
    		{
    			//���ʻ��C�ĳ�����ʻ��B�ĳ������кţ�ֱ�Ӹý���ʻ��B
    			if(A==target[B]) { A++,B++;}
    			//�������ж�ջ����(����C������)���Ƿ����ʻ�� B�ĳ�
    			else if(!s.empty()&&s.top()==target[B]) {s.pop(),B++;}
    			//����ʻ��C
    			else if(A<=n) s.push(A++);
    			//�����ȫ����ʻ��C��ѭ����û�н�������ζ��������target˳����ʵ��
    			else
    			{
    				ok=0;
    				break;
    			}
    		}
    		printf("%s\n",ok?"Yes":"No");
    		}
    		printf("\n");
    }
    return 0;
}
