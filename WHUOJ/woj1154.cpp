#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
string s;
int cnt = 1;
int main() {
    while(cin >> s) {
        if(s == "#")
            break;
        for(int i = 0; i < s.size(); i++)
            if( s[i] >= 'a' && s[i] <= 'z'&&i % 2 == 1) 
                s[i] = s[i] - 'a' + 'A';
        cout << "Case " << cnt ++ << ": "  << s << endl;
    }
    return 0;
}