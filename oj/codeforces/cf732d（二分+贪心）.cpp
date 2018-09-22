#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int s[100005];

int arr[100005];
int prepare[100005];

int n,m;


bool C(int x){
    memset(s,0,sizeof(s));
    for(int i=0;i<x;i++){
        s[arr[i]]=max(s[arr[i]],i+1);    //ĳ�ſε����һ��(С�ڵ���xd���һ��)
    }
    sort(s+1,s+m+1);
    int ret=0;
    for(int i=1;i<=m;i++){
        ret+=prepare[i];
        if(ret+i-1>=s[i])  //׼����ʱ��+���Ե�ʱ��
            return true;
    }
    return false;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=m;i++){
        cin>>prepare[i];
    }
    int low=0;
    int high=n;
    while(high-low>1){               //���֣�high-low=2����mid=low+1
        int mid=(low+high)/2;
        if(C(mid)) low=mid;
        else high=mid;
    }
    if(C(low+1)) cout<<-1<<endl;
    else cout<<low+1<<endl;
}
