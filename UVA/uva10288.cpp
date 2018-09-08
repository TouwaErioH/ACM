#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define LL long long
using namespace std;

LL gcd(LL a,LL b){
return a==0?b:gcd(b%a,a);
}

LL lcm(LL a,LL b){
    return a/gcd(a,b)*b;
}

int main()
{

    LL n;
    while(cin >> n) {
        LL lm = 1;
        for(LL i = 1;i <= n;i++) {
            lm = lcm(lm,i);
        }

        LL fenzi = 0;
        for(LL i = 1;i <= n;i++) {
            fenzi += (lm/i);
        }
        fenzi = fenzi * n;

        LL ansfz = fenzi / gcd(fenzi,lm);
        LL ansfm = lm / gcd(fenzi,lm);

        LL tmp = ansfm;
        int cont = 0;
        while(tmp / 10) {
            cont ++;
            tmp = tmp / 10;
        }

        tmp = ansfz/ansfm;
        int cont2 = 0;
        while(tmp / 10) {
            cont2 ++;
            tmp = tmp / 10;
        }

        if(ansfz % ansfm == 0)
            cout << ansfz / ansfm << endl;
        else {
            for(int i = 0;i <= cont2;i++) cout << " ";
            cout << " " << ansfz%ansfm << endl;

            cout << ansfz/ansfm << " ";
            for(int i = 0;i <= cont;i++) cout << "-";

            cout << endl;
            for(int i = 0;i <= cont2;i++) cout << " ";
            cout << " " << ansfm << endl;
        }
    }

    return 0;
}
