#include<iostream>
#include<vector>
using namespace std;

const int maxn = 100000 + 5;
int s, n, x[maxn*3], cnt[maxn], ok[maxn*2];

int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> s >> n;
    // add s "-1" to the left/right of orriginal sequence
    // so we don't have to worry about negative subscript or wrapping round
    fill(x, x+n+2*s, -1);
    for(int i = 0; i < n; i++) cin >> x[i+s];

    int tot = 0; // how many different integers in current sliding window  //112������1,2
    fill(cnt+1, cnt+s+1, 0); // cnt[i] is the number of occurrence of i in the current sliding window
    fill(ok, ok+n+s+1, 0);   // ok[i] = 1 iff the i-th sliding window didn't have duplicate numbers

    // compute "ok" array  //Ԥ����
    //ÿ�����ڿ��Կ�����n��ĳ����Ϊ��˵�����Ҷ˵������s����
    //totͳ�Ƶ��Ǵ��������ֳ��ֵĴ�������ͬ������n���������ֳ��ֵĴ��������Ը�ֵΪ-1�Ĳ��ù�
    //�ֳɴ����Լ���Ϊ����s������ߵĲ�ȷ��������ϳ�Ϊs(��ʱ����û����ȫ����n)�����ұ��������
    for(int i = 0; i < n+s+1; i++) {
      if (tot == s) ok[i] = 1;              // complete window ���������ÿ������ǡ�ó���һ��
      if (i < s && tot == i) ok[i] = 1;     // incomplete windows on the left side  ���iҲ��n���������봰�ڵ�������tot=i��ô������ߵ�-1�Ϳ������s  �����Ҷ˵�
      if (i > n && tot == n+s-i) ok[i] = 1; // incomplete windows on the right side  ������˵�

      // update cnt and tot for the next sliding window  //ע�����ڼ�����һ������
      if (i == n+s) break; // no more sliding windows, so we stop here
      if (x[i] != -1 && --cnt[x[i]]==0) tot--; // remove the first one  ��ǰ���ڵ�һ��������
      if (x[i+s] != -1 && cnt[x[i+s]]++==0) tot++; // add the next one  ��һ������������һ������
    }

    // check each possible answer
    int ans = 0;
    for(int i = 0; i < s; i++) {   //n��ǰs�����ĸ������(��һ���֪������µĿ�ʼֻ��ǰ������������s�������)
      int valid = 1;
      for (int j = i; j < n+s+1; j += s)
        if(!ok[j]) valid = 0;//i�൱��ȡn�е�ǰi������s��֮��ÿ�μ�s�൱����һ�����ڣ���Ҫÿ�����ڶ����������ſ�����һ�ֿ��з���
      if(valid) ans++;
    }
    if(ans == n+1) ans = s; // special case  ��ʱ˵��n����������Ϊ������Ϊ��ͷ���β���м䣬����ans=n-1(����Ϊ����)+s-n+1(��Ϊ����)
    cout << ans << "\n";
  }
  return 0;
}
