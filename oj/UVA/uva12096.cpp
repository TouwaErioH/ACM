#include<iostream>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

#define ALL(x) x.begin(), x.end()//所有的内容
#define INS(x) inserter(x, x.begin())//插入迭代器
typedef set<int> Set;
map<Set, int> IDcache; //把集合映射成ID
vector<Set> Setcache; //根据ID取集合

    //查找给定集合x的ID。如果找不到，分配一个新ID
int ID(Set x) {
    if (IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);//添加集合
    return IDcache[x] = Setcache.size() - 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        stack<int> s;//题目中的栈
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string op;
            cin >> op;
            if (op[0] == 'P') s.push(ID(Set()));
            else if (op[0] == 'D') s.push(s.top());
            else {
                Set x1 = Setcache[s.top()]; s.pop();
                Set x2 = Setcache[s.top()]; s.pop();
                Set x;
                if (op[0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));
                if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
                if (op[0] == 'A') { x = x2; x.insert(ID(x1)); }
                //cout << "................." << x.size() << endl;//测试语句
                s.push(ID(x));
            }
            cout << Setcache[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}
