#include<bits/stdc++.h>
using namespace std;

char board[10][10];
bool res[3][3];//����
char cur;//��ǰ������
char in[5];
int num_b, num_w;

   void Setboard() {
        num_b = num_w = 0;
        for(int i = 1; i < 9; i++) {
            for(int j = 1; j < 9; j++)
                board[i][j] = '-';
            board[i][9]  = 0,board[i][0]=0;
        }

        for(int i = 1; i <= 8; i++)
            for(int j = 1; j <= 8; j++)
            {
            char ch='\n';
            while(ch=='\r'||ch=='\n')
            {
                ch=getchar();
            }
            {
            board[i][j] =ch;
            if(board[i][j] == 'W') num_w++;
            else if(board[i][j] == 'B') num_b++;
        }
        }
         //for(int i = 1; i <= 8; ++i) {
            //for(int j = 1; j <= 8; ++j) printf("%c",board[i][j]);
            //printf("\n");}
        cur = getchar();

        while(cur != 'W' && cur != 'B') cur = getchar();//ֱ��getchar��-

    }


    void Putboard() {
        for(int i = 1; i <= 8; ++i) {
            for(int j = 1; j <= 8; ++j) printf("%c",board[i][j]);
            printf("\n");
        }
    }



    bool CheckDirection(int i, int j, int cal_i, int cal_j) {
        i =i+ cal_i, j=j+ cal_j;
        int dis = 1;//�����ϵĳ���
        while(i >= 1 && i <= 8 && j >= 1 && j <= 8) {
            if(board[i][j] == cur && dis == 1) return res[cal_i + 1][cal_j + 1] = false;//-1,0�����󣬵�������-1����+1,����������cur��Ч
            else if(board[i][j] == cur) return res[cal_i + 1][cal_j + 1] = true;
            else if(board[i][j] == '-') return res[cal_i + 1][cal_j + 1] = false;
            i += cal_i, j += cal_j, dis += 1;
        }
        return res[cal_i + 1][cal_j + 1] = false;
    }

    bool LegalMove(int i, int j) {    //8������;�ж��ܷ����i,j
        if(board[i][j] != '-') return false;
        memset(res, 0, sizeof(res));
        bool pos = false;
        if(CheckDirection(i, j, -1, 0)) pos = true;
        if(CheckDirection(i, j, -1, 1)) pos = true;
        if(CheckDirection(i, j, 0, 1)) pos = true;
        if(CheckDirection(i, j, 1, 1)) pos = true;
        if(CheckDirection(i, j, 1, 0)) pos = true;
        if(CheckDirection(i, j, 1, -1)) pos = true;
        if(CheckDirection(i, j, 0, -1)) pos = true;
        if(CheckDirection(i, j, -1, -1)) pos = true;
        return pos;
    }
    void ListAllLegalMoves() {
        int first = 1, exs = 0;
        for(int i = 1; i <= 8; ++i)
        for(int j = 1; j <= 8; ++j)
            if(LegalMove(i, j)) {
            exs = 1;
            if(first) first = 0;
            else printf(" ");
            printf("(%d,%d)",i,j);
        }
        if(!exs) printf("No legal move.");
        printf("\n");
    }

    void CoverDirection(int i, int j, int cal_i, int cal_j, char cover) {
        if(!res[cal_i + 1][cal_j + 1]) return;//�˷����޸���
        int *a, *b;
        if(cur == 'W') a = &num_w, b = &num_b;
        else a = &num_b, b = &num_w;
        i += cal_i, j += cal_j;
        while(board[i][j] == cover) {
            board[i][j] = cur;
            *a += 1, *b -= 1;
            i += cal_i, j += cal_j;
        }
    }

    char ReCur() {//����
    return cur == 'B' ? 'W' : 'B';
    }


    void MakeMove(int i, int j) {     //����
        if(!LegalMove(i, j)) cur = ReCur(), LegalMove(i, j);
        char cover = ReCur();//�����ǵ���ɫ
        board[i][j] = cur;
        cur == 'W' ? ++num_w : ++num_b;
        CoverDirection(i, j, -1, 0, cover);
        CoverDirection(i, j, -1, 1, cover);
        CoverDirection(i, j, 0, 1, cover);
        CoverDirection(i, j, 1, 1, cover);
        CoverDirection(i, j, 1, 0, cover);
        CoverDirection(i, j, 1, -1, cover);
        CoverDirection(i, j, 0, -1, cover);
        CoverDirection(i, j, -1, -1, cover);
        printf("Black -%3d White -%3d\n", num_b, num_w); //�����ʽ
        cur = ReCur();
    }

    int main() {
        int T;
        scanf("%d",&T);
        getchar();
        while(T--) {
            Setboard();
            while(scanf("%s",in)) {
                    getchar();
                if(in[0] == 'L') ListAllLegalMoves();
                else if(in[0] == 'M') MakeMove(in[1] - '0', in[2] - '0');
                else if(in[0] == 'Q') {
                    Putboard();
                    break;
                }
            }
            if(T) printf("\n");
        }
        return 0;
    }
