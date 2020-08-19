/*
水题。这种还好，我还记得紫书uva11210 麻将那道题，才是真的难受

题意，输入课程时间，按格式输出课程表
注意课程名称居中，偶数在末尾添加空格
COURSE_NAME: DAY TIME_SECTION CLASS_NUMBER
只有课程名因为中间有特殊的空格需要处理一下
两个记录数组，一个记录是否在day class有课
一个记录课名
上下午的处理:如果是下午直接+4
因为输出 是按行，所以记录数组应该是[classnum][day]的形式
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;

string name[7][5];
bool exist[7][5];  
string tmp,tmp2;
char day[5],timesec[15];
int classnum,date,i,j,k,len,space;

int main(){
    while(cin>>n){
        memset(exist,0,sizeof(exist));
        while(n-->0){
            cin>>tmp;
            while(tmp[tmp.size()-1]!=':'){  //我傻了，可能有多个空格!! 一开始只写了一个if
                cin>>tmp2;
                tmp=tmp+' '+tmp2;
            }
            tmp=tmp.substr(0,tmp.size()-1);
            scanf("%s %s",day,timesec); //注意空格
            scanf("%d",&classnum);
            if(timesec[0]=='A')
                classnum+=4;
            classnum--;
            if(day[1]=='O')
                date=0;
            else if(day[1]=='U')  //一开始少打一个=...
                date=1;
            else if(day[1]=='E')
                date=2;
            else if(day[1]=='H')
                date=3;
            else 
                date=4;
            exist[classnum][date]=true;
            name[classnum][date]=tmp;
            //cout<<classnum<<date<<tmp<<endl;
        }
        printf("+-----+-----------+-----------+-----------+-----------+-----------+\n"
			   "|     |    MON    |    TUE    |    WED    |    THU    |    FRI    |\n"
			   "+-----+-----------+-----------+-----------+-----------+-----------+\n"
			   "|                          Morning                                |\n"
			   "+-----+-----------+-----------+-----------+-----------+-----------+\n"
			   );
		for(i=0;i<4;i++){
			printf("|  %d  |",i+1);
			for(j=0;j<5;j++){
				if(exist[i][j]){
					len=name[i][j].size();
					if(!(len&1))
                        name[i][j]+=' ';
					space=(11-len)/2;
					for(k=0;k<space;k++)
					    printf(" ");
					cout<<name[i][j];
					for(k=0;k<space;k++)
					    printf(" ");
					printf("|");
				} 
				else
				printf("           |"); 
			}
			printf("\n");
			printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");
		} 
		printf("|                         Afternoon                               |\n"
			   "+-----+-----------+-----------+-----------+-----------+-----------+\n");
		for(i=4;i<7;i++){
			printf("|  %d  |",i-3);
			for(j=0;j<5;j++){
				if(exist[i][j]){
					len=name[i][j].size();
					if(!(len&1))
                        name[i][j]+=' ';
					space=(11-len)/2;
					for(k=0;k<space;k++)
					    printf(" ");
					cout<<name[i][j];
					for(k=0;k<space;k++)
					printf(" ");
					printf("|");
				} 
				else
				printf("           |"); 
			}
			printf("\n");
			printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");
		}
		printf("\n");
    }
    return 0;
}



/*网上的 c版,注意输入处理回车
#include<cstdio>
#include<cstring>
using namespace std;

void input(char* s){
	int i=0;
	char c;
	getchar();  //回车的处理
	while(scanf("%c",&c)&&c!=':'){
		s[i]=c;
		i++;
	}
	s[i]='\0';
}

int main(){
	char cou[15],coutab[7][5][15],day[5],mon[10];
	int yntab[7][5];
	int i,j,k,l,len,dayi,n,cnum;
	while(scanf("%d",&n)==1){
		memset(yntab,0,35*sizeof(int));
		while(n-->0){
			input(cou);
			scanf("%s %s %d",&day,&mon,&cnum);
			if(!strcmp(day,"MON"))
			dayi=0;
			else if(!strcmp(day,"TUE"))
			dayi=1;
			else if(!strcmp(day,"WED"))
			dayi=2;
			else if(!strcmp(day,"THU"))
			dayi=3;
			else if(!strcmp(day,"FRI"))
			dayi=4;
			if(!strcmp(mon,"Morning"))
			cnum-=1;
			else
			cnum+=3;
			yntab[cnum][dayi]=1;
			strcpy(coutab[cnum][dayi],cou);
		}
		printf("+-----+-----------+-----------+-----------+-----------+-----------+\n"
			   "|     |    MON    |    TUE    |    WED    |    THU    |    FRI    |\n"
			   "+-----+-----------+-----------+-----------+-----------+-----------+\n"
			   "|                          Morning                                |\n"
			   "+-----+-----------+-----------+-----------+-----------+-----------+\n"
			   );
		for(i=0;i<4;i++){
			printf("|  %d  |",i+1);
			for(j=0;j<5;j++){
				if(yntab[i][j]){
					len=strlen(coutab[i][j]);
					if(!(len&1)){
						coutab[i][j][len]=' ';
						len++;
						coutab[i][j][len]='\0';
					}
					k=(11-len)/2;
					for(l=0;l<k;l++)
					printf(" ");
					printf("%s",coutab[i][j]);
					for(l=0;l<k;l++)
					printf(" ");
					printf("|");
				} 
				else
				printf("           |"); 
			}
			printf("\n");
			printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");
		} 
		printf("|                         Afternoon                               |\n"
			   "+-----+-----------+-----------+-----------+-----------+-----------+\n");
		for(i=4;i<7;i++){
			printf("|  %d  |",i-3);
			for(j=0;j<5;j++){
				if(yntab[i][j]){
					len=strlen(coutab[i][j]);
					if(!(len&1)){
						coutab[i][j][len]=' ';
						len++;
						coutab[i][j][len]='\0';
					}
					k=(11-len)/2;
					for(l=0;l<k;l++)
					printf(" ");
					printf("%s",coutab[i][j]);
					for(l=0;l<k;l++)
					printf(" ");
					printf("|");
				} 
				else
				printf("           |"); 
			}
			printf("\n");
			printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");
		}
		printf("\n");
	}
	return 0;
}
*/