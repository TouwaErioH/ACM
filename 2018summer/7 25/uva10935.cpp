#include<iostream>
#include<queue>
using namespace std;
int n;
int main()
{
  while(cin>>n,n)
  {
  queue<int>q;
  if(n==1)
  {
  cout<<"Discarded cards:"<<endl;
  cout<<"Remaining card: 1"<<endl;
  continue;
  }
  for(int i=2;i<=n;i++)
  {
  q.push(i);
  }
  cout<<"Discarded cards: 1";
   while(q.size()>1)
  {
  q.push(q.front());
  q.pop();
  cout<<","<<" "<<q.front();
  q.pop();
  }
  cout<<endl;
  cout<<"Remaining card: "<<q.front()<<endl;
  }
  return 0;
}
