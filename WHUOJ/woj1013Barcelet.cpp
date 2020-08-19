//题意，输入字符串，看成环，从任一点开始一周构成“子串”，输出字典序最小的串
//比如 输入 1236  子串有1236 2361 3612 6123输出1236

#include<iostream>
#include<algorithm>
#include<cstring> 
#include<vector>
using namespace std;

bool cmp1(string a,string b){
    return a<b;
}
bool cmp(char*a,char*b){
    return strcmp(a,b);
}

char origin[105];
char mapp[105][105];

string ori;
vector<string>ans;
string tmp;
int main(){

while(cin>>ori){
    int len=ori.length();  //string.length() .size()
        for(int i=0;i<len;i++){
            tmp=ori;
            for(int j=0;j<len;j++){
                tmp[j]=ori[(i+j)%len];
            }
            //mapp[i][len]='\0';  //essential C可以这样，C++不行。 Array must be initialized with a brace enclosed initializer
            //mapp[i][len]=;
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end(),cmp1);
        cout<<ans[0]<<endl;
        ans.clear();  //别忘了
}

/* 
    while(scanf("%s",origin)!=EOF){
        int len=strlen(origin);  //string.length() .size()
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                mapp[i][j]=origin[(i+j)%len];
            }
            //mapp[i][len]='\0';  //essential C可以这样，C++不行。 Array must be initialized with a brace enclosed initializer
            //mapp[i][len]=;  没找到解决办法 T_T 应该是初始化的问题
        }
        sort(mapp,mapp+len,cmp);
        cout<<mapp[0]<<endl;

    }
    */
    return 0;
}


/*
字典序全排列生成：https://www.cnblogs.com/lqerio/p/12079873.html

algorithm
sort 推荐，一般更快
sort(first_pointer,first_pointer+n,cmp) //sort(mapp,mapp+5,cmp) sort(vec.begin(),vec.end())
cmp bool返回

不推荐
cstdlib
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
base-- 指向要排序的数组的第一个元素的指针。
nitems-- 由 base 指向的数组中元素的个数。
size-- 数组中每个元素的大小，以字节为单位。
compar-- 用来比较两个元素的函数，即函数指针（回调函数）.
cmp 用int返回，需要const void*

int compare(const void *a,const void *b)
{
     return *(int*)b-*(int*)a;//从大到小排序，若从小到大牌组为:*(int*)a-*(int*)b
}
*/

