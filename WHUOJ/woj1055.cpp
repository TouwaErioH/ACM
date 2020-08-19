#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

string useless,head;
//char sent[205];
string sent;
int main()
{
    while(cin>>head)
    {
        if(head=="ENDOFINPUT") 
            break;
       
        getchar();
        //gets(sent); //c++ 11移除
        getline(cin,sent);

        //int len=strlen(sent);
        int len=sent.size();
        int i;
        for(i=0;i<len;i++)
            if(sent[i]>='A'&&sent[i]<='Z')
                sent[i]=(sent[i]-'A'+21)%26+'A';
        cout<<sent<<endl;
        cin>>useless;
    }
    return 0;
}