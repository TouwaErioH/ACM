//题意 输入樱花坐标，判断所有点是否上下对称。
//因为数量小所以可以直接存图 1000 
//思路：找到纵坐标最低最高点,得到对称轴高度，然后判断每个x坐标上的点是否符合在对称轴两侧
//输入的时候做处理，使得所有的x坐标相同的点都放到一个vector数组，然后排序，那么对应的i,len-i两个点如果不对称，就不对称了。
//注意某个x坐标奇数个点有一个点应该在对称轴上
/*
样例输入
5
0 0
2 0
1 1
0 2
2 2
4
0 0
2 0
1 1
0 2
样例输出
YES
NO
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

const double eps=1e-6;

vector<int>xcoor;
vector<int>ycoor[1005];
int a,b,num,len,maxh,minh;
double avg;
vector<int>::iterator iter;
bool flag;
int main(){
    while(cin>>num){
        flag=true;
        xcoor.clear();
        for(int i=0;i<num;i++)
            ycoor[i].clear();
        cin>>a>>b;
        minh=maxh=b;
        xcoor.push_back(a);
        ycoor[xcoor.size()-1].push_back(b);
        for(int i=1;i<num;i++){
            cin>>a>>b;
            minh=minh>b?b:minh;
            maxh=maxh>b?maxh:b;
            if((iter=find(xcoor.begin(),xcoor.end(),a))!=xcoor.end()){
                ycoor[iter-xcoor.begin()].push_back(b);
            }
            else{
                xcoor.push_back(a);
                ycoor[xcoor.size()-1].push_back(b);
            }
        }
        avg=((double)minh+maxh)/2;         //注意double
        for(int i=0;i<xcoor.size();i++){
                len=ycoor[i].size();
                sort(ycoor[i].begin(),ycoor[i].end());
                for(int j=0;j<len/2;j++)
                    if(fabs(ycoor[i][j]+ycoor[i][len-j-1]-2*avg-0)>eps) //两边的点是否对称
                        {flag=false;break;}
                if(len&1==1){                          //一开始写成^1了....
                    if(fabs(avg-ycoor[i][len/2])>eps) //中间点是否在对称轴上
                        flag=false;
                }
                if(flag==false)
                    break;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

/*
不同于map（map有find方法），vector本身是没有find这一方法，其find是依靠algorithm来实现的。
 vector<int>::iterator it = find(vec.begin(), vec.end(), 6);
 
    if (it != vec.end())
        cout<<*it<<endl;
    else
        cout<<"can not find"<<endl;

count 类似
*/