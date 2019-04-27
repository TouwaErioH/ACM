#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 1e-6

struct point
{
	double x,y;
	point(){}
	point(double _x,double _y)
	{
		x = _x;y = _y;
	}
	point operator -(const point &b)const
	{
		return point(x - b.x,y - b.y);
	};
	double operator ^(const point &b)const   //当线段过x轴时，用于求与x轴交点的x坐标
	{
		return x*b.y - y*b.x;
	}
	double operator *(const point &b)const
	{
		return x*b.x + y*b.y;
	}
};


struct line               //线段。e点在右
{
	point s,e;
}c[2005];


int t,n,L;
struct st
{
	double l,r;
};
vector<st> v;

double dist(point a,point b)                //两点距离
{
	return sqrt((a-b)*(a-b));
}

point NearestPointToLineSeg(point P,line L)                   //返回线段L上距离P最近的点  也是相似三角形。
{
	point result;
	double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	if(t >= 0 && t <= 1)
	{
		result.x = L.s.x + (L.e.x - L.s.x)*t;
		result.y = L.s.y + (L.e.y - L.s.y)*t;
	}
	else
	{
		if(dist(P,L.s) < dist(P,L.e))
		result = L.s;
		else result = L.e;
	}
	return result;
}

double find2(line L,double rr,double l,double r)    //圆心区间左点   这里用二分法找；理论上讲以这个点为圆心的圆与线段相切
{
	double m;
	while (r-l>1e-6)
	{
		m=(l+r)/2;
		if (dist(NearestPointToLineSeg(point(m,0),L),point(m,0))<rr) r=m;  //m到线段距离小于r，则需要左移； 直到刚好切
		else l=m;
	}
	return (l+r)/2;
}

double find3(line L,double rr,double l,double r)  //圆心区间右点
{
	double m;
	while (r-l>1e-6)
	{
		m=(l+r)/2;
		if (dist(NearestPointToLineSeg(point(m,0),L),point(m,0))>rr) r=m;
		else l=m;
	}
	return (l+r)/2;
}

bool cmp(st a,st b)                                  //圆心不能在的区间先左再右排序
{
	if (fabs(a.l-b.l)<1e-6) return a.r<b.r;
	else return a.l<b.l;
}

bool ok(double h)                                  //这个半径下能不能满足题意为空圆 false为可以
{
	sort(v.begin(),v.end(),cmp);
	if (v.empty()) return false;                       //可以 注意go函数时!ok()
	if (v[0].l+eps>0) return false;                    //0-v[0]l 有空间做圆心
	double r=v[0].r;
	int i=0;
	while (i<(int)v.size()-1 && (v[i+1].l+eps<r || v[i+1].l<0))  //区间没有空隙
	{
		i++;
		r=max(r,v[i].r);
	}
	if (r+eps<h) return false;
	else return true;
}


int go(double rr)
{
	v.clear();
	for (int i=1;i<=n;i++)
	{
		double len;
		double mid;
		double l,r;
		if (c[i].s.y*c[i].e.y>0)                    //x轴同侧
		{
			if (fabs(c[i].s.y)>fabs(c[i].e.y))
			{
				len=fabs(c[i].e.y);                    //而不是abs  到x轴的距离   len>r时就不需要考虑这条线段；否则要找到一个区间，圆心不能在区间内
				mid=c[i].e.x;
			}
			else
			{
				len=fabs(c[i].s.y);  
				mid=c[i].s.x;
			}
		}
		else                                       //异侧
		{
			len=0;                                 //点在x轴上，距离为0
			mid=c[i].s.x+fabs((c[i].s.y/(c[i].e.y-c[i].s.y)*(c[i].e.x-c[i].s.x)));  //交点x坐标   用相似三角形求
		}
		if (len<rr)                       //len<rr，需要考虑这条线段
		{
			l=find2(c[i],rr,-3e4,mid);    //圆心区间的左点
			r=find3(c[i],rr,mid,3e4);     //圆心区间的右点
			st x;
			x.l=l;x.r=r;
			v.push_back(x);
		}
	}
	return !ok(L);
}

double find1()                //二分半径
{
	double l=0,r=2e4;
	double m;
	while (r-l>1e-6)
	{
		m=(l+r)/2;
		if (go(m)==1) l=m;    //半径为m可以，就再加长一点
		else r=m;
	}
	return (l+r)/2;
}

int main()
{
	//freopen("c.in","r",stdin);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&L);
		for (int i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf",&c[i].s.x,&c[i].s.y,&c[i].e.x,&c[i].e.y);  //e点在右边
			if (c[i].s.x>c[i].e.x) swap(c[i].e,c[i].s);
		}
		printf("%.3f\n",find1());
	}
	return 0;
}
