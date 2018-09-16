#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<string> s;
    string temp;
    while (cin >> temp)
    {
        s.insert(temp);
    }
    for (set<string>::iterator it = s.begin(); it != s.end(); it++)
    {
        string a = *it;
        for (int i = 1; i < a.length(); ++i)
        {
            if (s.find(a.substr(0, i)) != s.end() && s.find(a.substr(i, a.length() - i)) != s.end())//ºËÐÄ
            {
                cout << a << endl;
                break;
            }
        }
    }
}
