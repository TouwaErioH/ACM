#include <stdio.h>
#include <string.h>
int board[12][12];

int secondstep(int board[12][12], int x, int y)
{
    if(board[x+1][y-2] == 'H' && board[x+1][y-1] == 0) return 0;
    else if(board[x+2][y-1] == 'H' && board[x+1][y-1] == 0) return 0;
    else if(board[x+1][y+2] == 'H' && board[x+1][y+1] == 0) return 0;
    else if(board[x+2][y+1] == 'H' && board[x+1][y+1] == 0) return 0;
    else if(x-1>=1 && board[x-1][y+2] == 'H' && board[x-1][y+1] == 0) return 0;
    else if(x-2>=1 && board[x-2][y+1] == 'H' && board[x-1][y+1] == 0) return 0;
    else if(x-2>=1 && board[x-2][y-1] == 'H' && board[x-1][y-1] == 0) return 0;
    else if(x-1>=1 && board[x-1][y-2] == 'H' && board[x-1][y-1] == 0) return 0;
    int i, num = 0;
    for(i = x; i >=1; i--){
        if(num == 1 && board[i][y] != 0){
            num++;
            if(board[i][y] == 'C') return 0;
        }
        if(board[i][y] != 0 && num == 0){
            num++;
            if(board[i][y] =='R') return 0;
        }
    }
    num = 0;
    for(i = x; i <= 10; i++){
        if(num == 1 && board[i][y] != 0){
            num++;
            if(board[i][y] == 'C') return 0;
        }
        if(board[i][y] != 0 && num == 0){
            num++;
            if(board[i][y] == 'G' || board[i][y] =='R') return 0;
        }
    }
    num = 0;
    for(i = y; i >= 1; i--){
        if(num == 1 && board[x][i] != 0){
            num++;
            if(board[x][i] == 'C') return 0;
        }
        if(board[x][i] != 0 && num == 0){
            num++;
            if(board[x][i] =='R') return 0;
        }
    }
    num = 0;
    for(i = y; i <= 9; i++){
        if(num == 1 && board[x][i] != 0){
            num++;
            if(board[x][i] == 'C') return 0;
        }
        if(board[x][i] != 0 && num == 0){
            num++;
            if(board[x][i] =='R') return 0;
        }
    }
    return 1;
}

int judgewin(int board[12][12], int x, int y)
{
    char temp;
    int i;
    for(i = x; i <= 10; i++)
        if(board[i][y] != 0) break;
    if(i <=10 && board[i][y] == 'G') return 0;//½«É±Íõ

        if(x-1 >= 1){
            temp = board[x-1][y];
            board[x-1][y] = 0;
            if(secondstep(board,x-1,y)) return 0;
        }
        board[x-1][y] = temp;
        if(x+1 <= 3){
            temp =  board[x+1][y];
            board[x+1][y] = 0;
            if(secondstep(board,x+1,y)) return 0;
        }
         board[x+1][y] = temp;
        if(y-1 >= 4){
            temp = board[x][y-1];
            board[x][y-1] = 0;
            if(secondstep(board,x,y-1)) return 0;
        }
        board[x][y-1] = temp;
        if(y+1 <= 6){
            temp = board[x][y+1];
            board[x][y+1] = 0;
            if(secondstep(board,x,y+1)) return 0;
        }
        board[x][y+1] = temp;
        return 1;
}

int main()
{
    char s[4];
    int n,b_x,b_y;
    while(scanf("%d %d %d", &n, &b_x, &b_y) == 3 && n && b_x && b_y){
            getchar();
        memset(board,0,sizeof(board));
        int x, y;
        while(n--){
            scanf("%s%d%d", s, &x, &y);
            getchar();
            board[x][y] = s[0];
        }

        if(judgewin(board,b_x,b_y))
            printf("YES\n");
        else
            printf("NO\n");
            getchar();
    }
    return 0;
}

           /* char s[4];
            scanf("%s%d%d", s, &x, &y);
            getchar();
            board[x][y] = s[0];

            char s;
            scanf("%c%d%d", &s, &x, &y);
            getchar();
            board[x][y] = s;*/

