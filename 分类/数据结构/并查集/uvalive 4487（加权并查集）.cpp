#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 20020;
int f[N],v[N];
int vis[N],a[20];
int T=N-10;

void init(int n)
{
    for (int i=0;i<=n+1;i++){
        f[i]=i;
        v[i]=0;
        vis[i]=0;
    }
    f[T]=T;
    v[T]=0;
}

int findparent(int x)          //findparent
{
    if (x!=f[x]){
        int tmp=f[x];
        f[x]=findparent(f[x]);   //V[i]=V[i]^V[f[i]]        Xp=V[p]
        v[x]^=v[tmp];
        //��Ϊv[x]����Ͱ����������һ�㸸�ڵ��ֵ����ʱ����һ�������һ�Σ��͵�����
    }
    return f[x];
}

bool unite(int p,int q,int val)   //unite
{
    int r1=findparent(p);
    int r2=findparent(q);
    if (r1==r2){
        if ((v[p]^v[q])!=val)
            return 0;
        else
            return 1;
    }
    if (r1==T) swap(r1,r2);   //Xp^Xq=val;  ���ڳ�������˳�� v[p]= v[p]^v[r1]  v[q]=v[q]^v[r2]
    f[r1]=r2;
    v[r1]=v[p]^v[q]^val;//����Ҫע�⣬ʵ��V[r1]=Vr1^Vr2����Vp��Vq���������������val����������������ˣ���ʣ����������
    return 1;
}
int main()
{
    int n,Q,p,q,val,kase=0;
    char ch[2];
    char s[40];
    while(scanf("%d%d",&n,&Q)&&n)
    {
        init(n);
        printf("Case %d:\n",++kase);
        int err=0;
        int facts=0;
        for (int i=1;i<=Q;i++){
            scanf("%s",ch);
            if (ch[0]=='I'){
                facts++;
                gets(s);
                if (sscanf(s,"%d%d%d",&p,&q,&val)==2) {         //��������I
                    val=q;q=T;
                }
                if (err) continue;
                if (!unite(p,q,val)){
                    printf("The first %d facts are conflicting.\n",facts);
                    err=1;
                }
            }
            // if (err) continue;�к������룬����ֱ����һ��
            else {
                int k,ans=0;
                scanf("%d",&k);
                for (int i=1;i<=k;i++){
                    scanf("%d",&a[i]);
                   if(err) continue;
                    int r=findparent(a[i]);
                    ans^=v[a[i]];
                    a[i]=r;
                    vis[r]^=1;
                }
               if (err) continue;
                bool flag=1;
                for (int i=1;i<=k;i++){
                    if (vis[a[i]]){//�����ж��Ƿ���������
                        if (a[i]!=T){//����������ǳ������ڵ㣬û��ϵ����Ϊ����ֵ��֪
                            flag=0;
                        }
                         vis[a[i]]=0;   //��ԭ
                    }
                }
                if (flag) printf("%d\n",ans);
                else printf("I don't know.\n");
            }
        }
        puts("");
    }
return 0;
}

/*
1. f[]�����Ǵ����ڵ㣬��������·��ѹ������ÿ�� V[i]=V[i]^V[f[i]]�����ڵ�洢��ֵʵ�������������׵�����ֵ��ΪʲôҪ�����أ���Ϊ����������㽻���ɣ��������ͬһ����ż���Σ����൱�ڱ�����ô�����Ŀ������һ��Ҫ����̽���ͻ�������������ͬ��һ������,��ô ���ǵ� Xp^Xq=Xp^Xf^Xq^Xf=v[p]^v[q],�������������ż���ε��ڱ����ԭ�������������ʱ��Ҳ��������ֻ�и��ڵ㱻�����ż���� �ſ��Ա����������������ֵ��ֻ��������һ���������ϵĸ��ڵ㾭���������ε����˵���������󲻳�������� I don't know.

2.Ϊ��Ӧ��I P V ����ֱ�Ӹ�ֵ����������Ϊ���һ���������ڵ�T��v[T]=0ÿ��������T����������Ͳ������⴦����

3.ÿ�κϲ���ʱ��Tһ��Ҫ�Ǹ��ڵ㣬����һ�¡�find��ʱ�򣬽���·��ѹ����ͬʱ�Լ�Ȩ���кϲ���ͨ�����ż�����ڱ�������ԣ������µĽڵ�˳����ת��Ϊ���ڵ���ӽڵ㡣

4.ע��һ�� ����������ȼ�����^,Ϊ�����WA�˼��Σ��Ժ��漰λ����ģ���д���ţ��о����ǵ�һ�α����ȼ������ˡ�
*/
