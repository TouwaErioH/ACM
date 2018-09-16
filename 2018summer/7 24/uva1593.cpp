#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
vector<string> words[1010];
int word_size[200];
int main()
{
    string line;
    int line_num=0;
    memset(word_size,0,sizeof(word_size));
    while(getline(cin,line))
    {
        string temp;
        int len,cnt=0;
        stringstream ss(line);
        while(ss >> temp)
        {
            len=temp.size();
            word_size[cnt]=max(word_size[cnt],len);  //找出同列最长
            words[line_num].push_back(temp);
            cnt++;
        }
        line_num++;
    }
    for(int i=0;i<line_num;i++)
    {
        for(int j=0;j<words[i].size();j++)
        {

            cout<<words[i][j];
            int s=(int) words[i][j].size();
            if(j!=(words[i].size()-1))
            {
                for(int k=s;k<word_size[j];k++)
                cout<<" ";
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
