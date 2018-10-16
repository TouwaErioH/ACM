#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

//������Ҷ���logn��n�β��룬nlogn;������logmaxans(��ķ�Χ)
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> set_t;
const int SIZE = 1e6+10;
int a[SIZE],s[SIZE];
int main(){
    int  N,K;
    while(scanf("%d%d",&N,&K)&&N){
        for(int i=1;i<=N;i++){
            scanf("%d",&a[i]);
            s[i]=s[i-1]+a[i];
        }
        int ll=-10000*N,rr=10000*N;  //cnt ��guessans���ȵ�����͸���(��Ϊ���˸�1)
        while(ll<rr){
            int guessed_answer=(ll+rr+1)/2;
            set_t S;
            int cnt=0;
            for(int i=0;cnt<=K&&i<=N;i++){
                cnt+=S.order_of_key(make_pair(s[i]-guessed_answer+1,0));//�����ϸ�С�ڸ���ֵ�ĸ���
                S.insert(make_pair(s[i],i));
            }
            //printf("%d:%d\n",guessed_answer,cnt);
            if(cnt<K)rr=guessed_answer-1;
            else ll=guessed_answer;
        }
        printf("%d\n",ll);
    }
    return 0;
}
