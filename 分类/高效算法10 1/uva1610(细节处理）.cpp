#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> str;

int main(){
    int n;
    while(cin>>n&& n){
        str.clear();
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            str.push_back(s);
        }
        sort(str.begin(), str.end());
        int len = str.size();
        string s1 = str[len/2 - 1];
        string s2 = str[len/2];
        len = s1.size();

        int p = 0;
        string ans = "A";   //
        while(p < len){
           while(ans[p] <= 'Z' && ans < s1)  ++ans[p];  //����ZΪ[,���ܳ����ڴ���
            if(ans[p] <= 'Z' && ans >= s1 && ans < s2)  break;
            --ans[p];
            ans += 'A';
            ++p;
            /*
            AYZZ
             AZ
             AY[
             */
           /*while(ans < s1)  ++ans[p];//�����������p�̣���ôans��p�������s1[p](����������ˣ������ʱs1[p]��Z����������)��p=length�������
            if(ans < s2)  break;
            ans[p]--;
            ans += "A";
            ++p;*/
        }
        cout << ans << endl;
    }
    return 0;
}
