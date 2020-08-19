// 线性代数，行列式。。需要复习了
//二阶三阶行列式求值可以用沙路法（对角线法则）
//题意：给出的三阶行列式是变形公式，乘unit cubic 
//The coordinates of the eight vertices of the unit cubic are: (0, 0, 0),(0, 1, 0),(1, 1, 0),(1, 0, 0),(0, 0, 1),(0, 1, 1),
//(1, 1, 1),(1, 0, 1).
//Output the volume of the object transformed from a unit cubic, round to 2 digits after the decimal point.
//小数点后2位。
//然后算体积
//https://www.zhihu.com/question/36966326 这题我没明白，看了资料说是行列式就是线性变换的伸缩因子，
//原来的体积是1，经过矩阵的线性变换的体积就是1*矩阵行列式
//可以设几个例子看确实是这样的
//北大数学系的hzg说是在xyz三个维度拉长，比如行列式值为4，就是拉长4^(1/3)，乘起来就是4

//港大数学系的同学说就是积分换元(体积积分)

/*样例
样例输入
1 0 1
0 2 0
-1 0 1

1 0 0
0 1 0
0 0 1

样例输出
4.00
1.00
*/
#include<cstdio>
#include<cmath>
using namespace std;

double x1;
double x2,x3;
double y11;
double y2,y3,z1,z2,z3;

int main()
{
    while(scanf("%lf%lf%lf",&x1,&x2,&x3)==3)
    {
      scanf("%lf%lf%lf",&y11,&y2,&y3); 
      scanf("%lf%lf%lf",&z1,&z2,&z3);
      printf("%.2lf\n",fabs(x1*(y2*z3-y3*z2)-y11*(x2*z3-x3*z2)+z1*(x2*y3-x3*y2)));//沙路法，对角线法则
    }
   return 0;  
}

/* 使用double y1声明报错。
显示变量y1 和Ｃ＋＋标准库中的某个变量名称冲突，这个问题应当引起注意。
另外这不是头文件写成<bits/stdc++.h>引起的，即使换成各具体的头文件（<iostream>, <algorithm>, <ctring>）还是会返回这个错误。
具体原因及解决办法还有待研究。

main.cpp：4：17：错误：'double y1'被重新声明为另一种符号
double x1，x2，x3，y1，y2，y3，z1，z2，z3; 
                 ^〜
在从/usr/include/features.h:424:0包含的文件，
                 从/usr/include/x86_64-linux-gnu/c++/7/bits/os_defines.h:39，
                 从/ usr /包括/ x86_64的-linux-gnu / c ++ / 7 / bits / c ++ config.h：533，
                 来自/ usr / include / c ++ / 7 / cstdio：41，
                 来自main.cpp：2：
/ usr / include / x86_64-linux- gnu / bits / mathcalls.h：221：1：注意：先前的声明'double y1（double）' 
__MATHCALL（y1 ,,（_Mdouble_））; 
*/
/*
float，单精度浮点型，对应%f.
double,双精度浮点型，对应%lf.
在用于输出时:
float类型可以使用%lf格式，但不会有任何好处。
double类型如果使用了%f格式可能会导致输出错误。
在用于输入时:
double 类型使用了%f格式，会导致输入值错误。
float类型使用double类型不仅会导致输入错误，还可能引起程序崩溃。

C语言中，
求整数的绝对值abs()和labs()应该包含stdlib.h
求浮点数的绝对值fabs()应该包含math.h
在C++中，只需要包括cmath即可。
*/

