#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

typedef pair<int,int> info; //ancestor,age
map<string,info> family = {{"Adam",make_pair(1,930)},{"Seth",make_pair(2,912)},
{"Enosh",make_pair(3,905)},{"Kenan",make_pair(4,910)},
{"Mahalalel",make_pair(5,895)},{"Jared",make_pair(6,962)},{"Enoch",make_pair(7,365)},{"Methuselah",make_pair(8,969)},
{"Lamech",make_pair(9,777)},{"Noah",make_pair(10,-1)},{"Shem",make_pair(11,-1)},{"Ham",make_pair(11,-1)},{"Japheth",make_pair(11,-1)}};

/*好像struct更简单。但是查起来麻烦
struct people {
	string name[20];
	int ancestor;
	int old;
}
*/

void initial(){
    //复习一下
    //info p;
    //map<string,info> person;
    //p=make_pair(1,930); //p.first,p.second
    //person.insert(make_pair("Adam",p));
    
    return;
}

int main(){
    /*
    string line;
    while(getline(cin,line,'#'))
    {cout <<line;
    fflush(stdin);
    }
    */
    //initial();
    //char name1[15],name2[15];
    string name1,name2;
    map<string,info>::iterator iter1,iter2;
    while(cin>>name1>>name2)    //cin空格截断.getline可以一行
    {
        //  if(family.count(name1)>0)  必定存在，不判断
        iter1=family.find(name1);
        iter2=family.find(name2);
        if(iter1->second.first==-1||iter2->second.first==-1)  //注意map用-> pair用.
            cout<<"No enough information"<<endl;
		else if(iter1->second.first<iter2->second.first)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
 
		if(iter1->second.second==-1||iter2->second.second==-1)
			printf("No enough information\n");
		else if(iter1->second.second>iter2->second.second)
			printf("Yes\n");
		else
			printf("No\n");
    }
    return 0;
}

/*
1.while((scanf"%d,%d",&m,&n)==2)

  {

  //...

  }

2.while((scanf"%d,%d",&m,&n)!=EOF)

  {

  //...

  }

3.while(cin>>m>>n)

*/