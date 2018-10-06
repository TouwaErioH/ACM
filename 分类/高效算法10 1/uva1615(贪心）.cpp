#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct village
{
    double l,r;
    village(double _l,double _r):l(_l),r(_r){}
    bool operator < (const village &a) const {
        return r<a.r;
    }
};
vector<village>vec;
int length,D,n;


void dist(int x,int y,double &l,double &r)
{
    l=(double)x-sqrt((double)D*(double)D-(double)y*(double)y);
    r=(double)x+sqrt((double)D*(double)D-(double)y*(double)y);
}

int main()
{
    int x,y;
    double l,r;
    while(scanf("%d",&length)!=EOF)
    {
        scanf("%d%d",&D,&n);
        vec.clear();
        for(int i=0;i<n;++i){
            scanf("%d%d",&x,&y);
            dist(x,y,l,r);
            vec.push_back(village(max(0.0,l),min((double)length,r)));
        }
        sort(vec.begin(),vec.end());
         int ans=0;
         double temp=-1.0;
         for(int i=0;i<n;++i){
        if(temp<vec[i].l||temp>vec[i].r){
            ++ans;
            temp=vec[i].r;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
