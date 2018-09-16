#include <cstdio>
#define MOD 10001
using namespace std;

int ts[210];
int n;

void gcd(int a,int b,int& d,int &x,int &y){
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main(){
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++)               //������Ŀ��n>0
            scanf("%d",&ts[(i<<1)+1]);
        long long a,b;

            for(a=0;a<10001;a++){        //ö��a����b
                int gd,x,y;
                gcd(a+1,MOD,gd,x,y);
                if((ts[3]-a*a*ts[1])%gd==0){   //a*a*d[1]�������long long
                    b=((ts[3]-a*a*ts[1])/gd)*x;
                    int i;
                    for(i=1;i<n;i++){
                        ts[i<<1]=(ts[(i<<1)-1]*a+b)%MOD;
                        if(ts[(i<<1)+1]!=((ts[(i<<1)]*a+b)%MOD))    //����ì��
                            break;
                    }
                    if(i==n){
                        ts[n<<1]=(ts[(n<<1)-1]*a+b)%MOD;
                        break; }             //ֻ��Ҫһ��
                }
            }

        for(int i=1;i<=n;i++){
            printf("%d\n",ts[i<<1]);
        }
    }
    return 0;
}
