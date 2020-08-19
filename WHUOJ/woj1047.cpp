#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int num = 0;
    string str1;
    string str2;
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        cin >> str1 >> str2;
        int length1 = str1.length();
        int length2 = str2.length();
        if(length1==0||length2==0)
        {
            cout<<0<<endl;
            continue;
        }
        int **dp = new int*[length1];
        for(int i = 0; i < length1; i++)
        {
            dp[i] = new int[length2];
        }

        for(int i = 0; i < length1; i++)
        {
            if(str1[i] == str2[0])
            {
                dp[i][0] = 1;
            }
            else
                dp[i][0] =0;

        }
        for(int j = 0; j < length2; j++)
        {
            if(str1[0] == str2[j])
            {
                dp[0][j] = 1;
            }
             else
                dp[0][j] =0;   //注意
        }
        for(int i = 1; i < length1; i++)
        {
            for(int j = 1; j < length2; j++)
            {
                if(str1[i] == str2[j])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = 0;
                }
                
            }
        }
        int max = 0;
        
        for(int i = 0; i < length1; i++)
        {
            for(int j = 0; j < length2; j++){
                if(dp[i][j] > max){
                    max = dp[i][j];
                }
            }
        }

        cout << max << endl;
        for(int i = 0; i < length1; i++)
        {
            delete[] dp[i];
        }
        delete[] dp;
    }
    return 0;
}