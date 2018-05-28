    #include<iostream>
    #include<cstdio>
    #include<string>
    #include<cstring>
    using namespace std;
    #define MAX 26
    char CH='a';
    struct node{
        int key;
        node *next[MAX];
        node(){
            key=0;
            for(int i=0;i<MAX;i++)
                next[i]=NULL;
        }
    };
    node *root;
    void tireInsert(char* str){
        node*p=root,*q;
        for(int i=0;str[i];i++){
            int id=str[i]-CH;
            if(!p->next[id])
               p->next[id]=new node();
               p=p->next[id];
               p->key++;
        }
    }
    void dell(node*p)
    {
        if(p){
            for(int i=0;i<MAX;i++)
            if(p->next[i]){
                dell(p->next[i]);
                delete p->next[i];
            }
        }
    }
    int tireFind(char *str)
    {
        node *p=root;
        for(int i=0;str[i];i++){
            int id=str[i]-CH;
            p=p->next[id];
            if(!p)return 0;
        }
        return p->key;
    }
    int main()
    {
      char str[11];
      root=new node();
      while(gets(str),*str)tireInsert(str);
      while(gets(str))cout<<tireFind(str)<<endl;
    }
