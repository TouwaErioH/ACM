/*有了一定的麻将胡牌基础，这道题很容易理解。胡牌规则很简单，一个将（两个一样），4个顺子（3个同花相连的牌）或刻子（3张相同的牌）即可胡牌。题目的要求是给13 张牌判断是否已经听牌，即再有一张某种花色牌即可胡牌。如果是，输出需要哪一种花色牌即可胡牌，如果不是输出not ready。
算法的大致思路，首先枚举34种花色牌，表示有这种花色的牌可以胡牌（如果这种花色牌在13张中已经有4张，则跳过）。现在即有14张牌，对于这14张牌，再枚举34张种花色牌，表示有这种花色的两张牌则作为将，再对剩下12张牌进行操作。
剩下的12张牌使用dfs，及当搜索4次时，若果都符合则可以听牌。剩下的12张牌，依旧是枚举34种花色牌，先找这种花色是否有至少3张牌，如果有，则构成顺子，再继续搜索。如果没有则判断这张牌和与它后面相连的2张牌能否构成刻子，若可以，则构成刻子，再继续搜索。如果不能，则表示没有听牌，则跳出dfs,继续枚举将牌。需要注意的是Dong，Nan，Xi，Bei，Zhong，Fa，Bai都不能构成刻子。
存储方式则是先用一个二维字符数组存下所有的麻将花色，再用一维数组通过预处理13张牌保存下13张各种花色的牌各有多少张。
*/
#include<cstdio>
#include<cstring>
int mj[20], cnt[35];
const char* mahjong[]={"1T","2T","3T","4T","5T","6T","7T","8T","9T",
    "1S","2S","3S","4S","5S","6S","7S","8S","9S",
    "1W","2W","3W","4W","5W","6W","7W","8W","9W",
    "DONG","NAN","XI","BEI",
    "ZHONG","FA","BAI"};
int getNum(char *str) { //将牌面转换为编号
    for (int i = 0; i < 34; i++) {
        if (!strcmp(mahjong[i], str)) return i;
    }
}
int check2(int n) {
    for (int i = 0; i < 34; i++) { //刻子
        if (cnt[i] >= 3) {
            if (n == 3) return 1;
            cnt[i] -= 3;                      //回溯法,n代表刻字或顺子个数
            if (check2(n + 1)) return 1;
            cnt[i] += 3;
        }
    }
    for (int i = 0; i <= 24; i++) { //顺子
        if (i % 9 <= 6 && cnt[i] && cnt[i + 1] && cnt[i + 2]) {
            if (n == 3) return 1;
            cnt[i]--;
            cnt[i + 1]--;
            cnt[i + 2]--;
            if (check2(n + 1)) return 1;
            cnt[i]++;
            cnt[i + 1]++;
            cnt[i + 2]++;
        }
    }
    return 0;
}
int check() {
    for (int i = 0; i < 34; i++) {
        if (cnt[i] >= 2) {//选两张作为将
            cnt[i] -= 2;
            if (check2(0)) return 1;
            cnt[i] += 2;
        }
    }
    return 0;
}
int main() {
    char str[3];
    int Case = 1;
    while (scanf("%s", str) == 1) {
        if (strcmp(str, "0") == 0) break;
        printf("Case %d:", Case++);
        mj[0] = getNum(str);
        for (int i = 1; i < 13; i++) {
            scanf("%s", str);
            mj[i] = getNum(str);//将牌面转化为编号
        }
        int flag = 0;
        for (int i = 0; i < 34; i++) {//枚举34种可能和的情况
            memset(cnt, 0, sizeof(cnt));
            for (int j = 0; j < 13; j++) {
                cnt[mj[j]]++;//统计每张牌出现次数
            }
            if (cnt[i] >= 4) continue;//已出现四次则不再考虑这张牌
            cnt[i]++;                 //假如加了这张牌
            if (check()) {
                flag = 1;
                printf(" %s", mahjong[i]);
            }
        }
        if (!flag) printf(" Not ready\n");
        else printf("\n");
    }
    return 0;
}
