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

    int tot = 0; // how many different integers in current sliding window  //112有两个1,2
    fill(cnt+1, cnt+s+1, 0); // cnt[i] is the number of occurrence of i in the current sliding window
    fill(ok, ok+n+s+1, 0);   // ok[i] = 1 iff the i-th sliding window didn't have duplicate numbers

    // compute "ok" array  //预处理
    //每个窗口可以看做是n中某个数为左端点或者右端点的连续s个数
    //tot统计的是窗口中数字出现的次数，等同于属于n个数的数字出现的次数；所以赋值为-1的不用管
    //分成窗口自己作为完整s，和左边的不确定的数组合成为s(此时窗口没有完全进入n)，和右边三种情况
    for(int i = 0; i < n+s+1; i++) {
      if (tot == s) ok[i] = 1;              // complete window 这个窗口中每个数字恰好出现一次
      if (i < s && tot == i) ok[i] = 1;     // incomplete windows on the left side  这个i也是n个数中纳入窗口的数量，tot=i那么加上左边的-1就可以组成s  看做右端点
      if (i > n && tot == n+s-i) ok[i] = 1; // incomplete windows on the right side  看做左端点

      // update cnt and tot for the next sliding window  //注意是在计算下一个窗口
      if (i == n+s) break; // no more sliding windows, so we stop here
      if (x[i] != -1 && --cnt[x[i]]==0) tot--; // remove the first one  当前窗口第一个数减掉
      if (x[i+s] != -1 && cnt[x[i+s]]++==0) tot++; // add the next one  下一个数加入了下一个窗口
    }

    // check each possible answer
    int ans = 0;
    for(int i = 0; i < s; i++) {   //n中前s个数的各种情况(想一想就知道最后新的开始只和前面数量不大于s的数相关)
      int valid = 1;
      for (int j = i; j < n+s+1; j += s)
        if(!ok[j]) valid = 0;//i相当于取n中的前i个数做s，之后每次加s相当于再一个窗口；需要每个窗口都满足条件才可以是一种可行方案
      if(valid) ans++;
    }
    if(ans == n+1) ans = s; // special case  此时说明n个数可以作为整体作为开头或结尾或中间，就有ans=n-1(不作为整体)+s-n+1(作为整体)
    cout << ans << "\n";
  }
  return 0;
}
