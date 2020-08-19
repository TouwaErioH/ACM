#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

//把第一个人的排存到一个集合中，对于第二个人的每一张牌，在集合里找一个能覆盖的最大的删去，如果有，答案加一。


int T;
int n,carnums;
int i,j,res;
int visted[30];
struct card{
	int x,y;
};

card solve(string s);
string s;

card Yadang[30],xiawa[30];

bool cardcmp(card car1,card car2){
	if(car1.x==car2.x)
	    return car1.y<car2.y;
	else
	    return car1.x<car2.x;
}

int main(){
	cin>>T;
	while(T--){
        res=0;
		cin>>carnums;
		for(i=0;i<2;i++)
		    for(j=0;j<carnums;j++){
			    cin>>s;
			    if(i==1)
			        xiawa[j]=solve(s);			        
			    else
                    Yadang[j]=solve(s);
		}
        for(i=0;i<30;i++)
            visted[i]=1;
		sort(xiawa,xiawa+carnums,cardcmp);
		for(i=0;i<carnums;i++)
		    for(j=0;j<carnums;j++){
			    if(visted[j]&&cardcmp(Yadang[i],xiawa[j])){
				    visted[j]=0;
                    res++;
				    break;
			        }
		    }
		cout<<res<<endl;
	}
	return 0;
} 



card solve(string s){
	card temp;
	switch(s[0]){
		case 'K':temp.x=13;break;
		case 'A':temp.x=14;break;
		case 'Q':temp.x=12;break;
		case 'T':temp.x=10;break;
		case 'J':temp.x=11;break;
		default:temp.x=s[0]-'0';
	}
	switch(s[1]){
		case 'S':temp.y=3;break;
		case 'D':temp.y=2;break;
		case 'H':temp.y=4;break;
		case 'C':temp.y=1;
	}
	return temp;
}
