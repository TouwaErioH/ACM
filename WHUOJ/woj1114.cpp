#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
using namespace std;




vector<double>mapp = {3, 6, 9, 12, 15};
vector<int>point = {100, 80, 60, 40, 20};

int judge(double n){
    double eps=1e-10;
    return (n > eps) - (n < -eps);
}

int point1, point2;
int temp;
double position[10][2];
double len;

int main() {
    double pos_x[20], pos_y[20];
    while(cin >> position[0][0] >> position[0][1]) {
        point1=0;
        point2=0;
        for(int i = 1; i < 6; i++) cin >> position[i][0] >> position[i][1];
        
        if(judge(position[0][0] + 100) == 0)
            return 0;
        
        for(int i = 0; i < 6; i++) {
            len = position[i][0] * position[i][0] + position[i][1] * position[i][1];
            temp = 0;
            for(int j = 0; j < 5; j++) {
                if(judge(mapp[j] * mapp[j] - len) >= 0) {
                    temp = point[j];
                    break;
                }
            }
            if(i < 3)
                point1 = point1+temp;
            else
                point2 = point2+temp;
        }
        printf("SCORE: %d to %d, ", point1, point2);
        if(point1 == point2)
            cout<<"TIE."<<endl;
        else if(point1 > point2)
            cout<<"PLAYER 1 WINS."<<endl;
        else
            cout<<"PLAYER 2 WINS."<<endl;
    }
    return 0;
}