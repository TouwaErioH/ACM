#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
struct point{
LL g;
int p;
point(LL g=0, int p=0):g(g),p(p){}
  bool operator < (const point& rhs) const {
    return g < rhs.g || (g == rhs.g && p < rhs.p);
  }
};

LL ps[100005];
LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}
int n;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%lld",&ps[i]);
            vector<point>points;
            LL ans=0;
            for(int j=0;j<n;j++)
            {
                points.push_back(point(0,j));
                for(int i=0;i<points.size();i++)
                    points[i].g=gcd(points[i].g,ps[j]);
                sort(points.begin(),points.end());

                vector<point> newp;
      for(int i = 0; i < points.size(); i++)
        if(i == 0 || points[i].g != points[i-1].g) {
          newp.push_back(points[i]);
          ans = max(ans, points[i].g * (j - points[i].p + 1));
        }
      points = newp;
        }
       printf("%lld\n",ans);
    }
    return 0;
}
