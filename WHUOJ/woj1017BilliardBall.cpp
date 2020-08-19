// 题目说明锐角三角形，各个边弹一次，回到起始位置，然后计算路径长度
// 可以证明DEF为垂足三角形时 符合要求的弹一次，并且最短
//证明见 http://blog.sina.com.cn/s/blog_493bff030100041r.html
//余弦定理  cos A=(b²+c²-a²)/2bc
///正弦定理  a/sinA = b/sinB =c/sinC = 2r=D（r为外接圆半径，D为直径）
//圆周角定理 圆周角所对弧对应角为圆周角的二倍 
//（海伦公式）（p=(a+b+c)/2）
//S=sqrt[p(p-a)(p-b)(p-c)]
// 三角形面积 1/2*b*c*sina


#include<iostream>
#include<cmath> //sqrt
using namespace std;

double leng(int a1,int b1,int a2,int b2){
    return sqrt(pow(a1-a2,2)+pow(b1-b2,2)); //pow
}

int main(){
    int a1,b1,a2,b2,a3,b3;
    double a,b,c,cosa,ans;
    int T;
    cin>>T;
    while(T){
        cin>>a1>>b1>>a2>>b2>>a3>>b3;
        a=leng(a1,b1,a2,b2);
        b=leng(a1,b1,a3,b3);
        c=leng(a2,b2,a3,b3);
        cosa=(b*b+c*c-a*a)/(2*b*c);
        ans=2*b*c*(1-cosa*cosa)/a;
        printf("%.3lf\n",ans);

        T--;
    }
return 0;
}