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
        //因为v[x]本身就包括了异或上一层父节点的值，此时与上一层再异或一次，就抵消了
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
    if (r1==T) swap(r1,r2);   //Xp^Xq=val;  由于程序运行顺序， v[p]= v[p]^v[r1]  v[q]=v[q]^v[r2]
    f[r1]=r2;
    v[r1]=v[p]^v[q]^val;//这里要注意，实际V[r1]=Vr1^Vr2，而Vp和Vq包含这两项，并且用val把他们自身给抵消了，就剩下那两项了
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
                if (sscanf(s,"%d%d%d",&p,&q,&val)==2) {         //调整两种I
                    val=q;q=T;
                }
                if (err) continue;
                if (!unite(p,q,val)){
                    printf("The first %d facts are conflicting.\n",facts);
                    err=1;
                }
            }
            // if (err) continue;有后续输入，不能直接下一次
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
                    if (vis[a[i]]){//这里判断是否是奇数次
                        if (a[i]!=T){//如果奇数次是超级父节点，没关系，因为他的值已知
                            flag=0;
                        }
                         vis[a[i]]=0;   //还原
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
1. f[]照样是代表父节点，照样进行路径压缩，把每个 V[i]=V[i]^V[f[i]]，即节点存储的值实际是它与它父亲的异或的值。为什么要这样呢，因为异或首先满足交换律，而且异或同一个数偶数次，即相当于本身，那么这个题目的其中一个要求是探测冲突，则如果两个点同属一个集合,那么 他们的 Xp^Xq=Xp^Xf^Xq^Xf=v[p]^v[q],就是利用了异或偶数次等于本身的原理，在真正计算的时候，也是这样，只有父节点被异或了偶数次 才可以被消除，求得真正的值，只有其中有一个或者以上的父节点经过了奇数次的异或，说明根本就求不出来，输出 I don't know.

2.为了应对I P V 这种直接赋值的做法，人为添加一个超级父节点T，v[T]=0每次让它跟T来异或，这样就不用特殊处理了

3.每次合并的时候，T一定要是父节点，特判一下。find的时候，进行路径压缩，同时对加权进行合并，通过异或偶数等于本身的特性，将底下的节点顺利的转化为父节点的子节点。

4.注意一下 ！运算的优先级高于^,为了这个WA了几次，以后涉及位运算的，多写括号，感觉不是第一次被优先级给坑了。
*/
