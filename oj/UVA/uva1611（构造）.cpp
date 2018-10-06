#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[10010];

void change(int l,  int r){
    for(int i = l, j = l+(r-l)/2+1; j <= r; ++i, ++j)
        swap(a[i], a[j]);
}

vector<pair<int, int>> Road;
int n;
int main(){
	int T; cin >> T;
	while (T--){
        cin >> n;
        Road.clear();
		for(int i = 0; i < n; ++i) cin >> a[i];  //计算到i时，前面的位置已经排好了
        for(int i = 0; i < n; ++i){
            int pos = find(a, a + n, i + 1) - a;
            if(pos == i) continue;
            if(i + 2*(pos-i) <= n){   //i+1可以直接交换到i位置(后面有足够的数，不越界)
                Road.push_back(make_pair(i+1, i + 2*(pos-i)));
                change(i, i + 2*(pos-i) - 1);
            }
            else{                    //交换到前一半
                if((pos-i)%2){  //偶数个
                    Road.push_back(make_pair(i+1, pos + 1));
                    change(i, pos);
                }
                else{
                    Road.push_back(make_pair(i+2, pos + 1));
                    change(i + 1, pos);
                }
                --i;
            }
        }
        cout << Road.size() << endl;
        for(long long i=0;i<Road.size();i++) printf("%d %d\n", Road[i].first, Road[i].second);
	}
	return 0;
}
