
#include "AC_KMP.h"

//const int M = 500010;
const int M = 100; // ？？应该是 keyword 的长度之和
int fail[M], ch[M][30], bo[M];
int tot = 1;

//bo存放的编号 -> 单词的 idx
int word_idx[M];


void insert(char *s, int idx) {
    int u = 1;
    for (int i = 0; i < strlen(s); i++) {
        int c = s[i] - 'a';
        if (!ch[u][c]) ch[u][c] = ++tot;
        u = ch[u][c];
    }
    bo[u]++;

//    存放对应位置的单词编号
    word_idx[u] = idx;

}

void build() {
//    不知道多大合适
    Rec_Array *q = Init_REC_ARRAY(M * 2);

    fail[1] = 0;
    Push_Rec_Array(q, 1);
    for (int i = 0; i < 26; i++) { ch[0][i] = 1; }

    while (!Is_Empty_Rec_Array(q)) {
        int u = Pop_Front_Rec_Array(q);
        for (int i = 0; i < 26; i++) {
            if (!ch[u][i]) { ch[u][i] = ch[fail[u]][i]; }
            else {
                fail[ch[u][i]] = ch[fail[u]][i];
                Push_Rec_Array(q, ch[u][i]);
            }
        }
    }
}

void insert_and_build(int len_keywords, char **keywords) {
    memset(ch, 0, sizeof(ch));

    for (int i = 0; i < len_keywords; i++) {
        insert(keywords[i], i);
    }
    build();
}


//返回命中几个，多次命中的不重复计算
//问题是调用一次后，bo矩阵失效
int find_num(char *s) {
    int res = 0;
    int u = 1;
    for (int i = 0; i < strlen(s); i++) {
        int c = s[i] - 'a', k = ch[u][c];
        while (k && bo[k] != -1) {
            res += bo[k];

            bo[k] = -1; // 把已经找到的单词，其叶子标记为无效，这样可以防止重复检索
            k = fail[k];
        }
        u = ch[u][c];
    }
    return res;
}


int find_cnt(char *s) {
    int res = 0;
    int u = 1;
    for (int i = 0; i < strlen(s); i++) {
        int c = s[i] - 'a', k = ch[u][c];
        while (k && bo[k] != -1) {
            res += bo[k];
            k = fail[k];
        }
        u = ch[u][c];
    }
    return res;
}


// 命了哪些单词，返回这些单词的 index
int *find_all(char *s) {
    int *res = malloc(sizeof(int) * (M + 1));
    int idx = 1;
//    res[0] 存放实际长度

    int u = 1;
    for (int i = 0; i < strlen(s); i++) {
        int c = s[i] - 'a', k = ch[u][c];
        while (k && bo[k] != -1) {
            if (bo[k] != 0) {
                res[idx++] = word_idx[k];
            }
            k = fail[k];
        }
        u = ch[u][c];
    }
    res[0] = idx;// 用来记录其长度
    return res;
}

// 命中了哪些单词，返回这些单词的 index，以及对应在s中的位置
int *find_all2(char *s) {
    int *res = malloc(sizeof(int) * (2 * M + 1));
    int idx = 1;
//    res[0] 存放实际长度

    int u = 1;
    for (int i = 0; i < strlen(s); i++) {
        int c = s[i] - 'a', k = ch[u][c];
        while (k && bo[k] != -1) {
            if (bo[k] != 0) {
                res[idx++] = word_idx[k]; // 匹配到哪个词
                res[idx++] = i; //匹配到的单词，其结尾出现在 s 的哪个位置
            }
            k = fail[k];
        }
        u = ch[u][c];
    }
    res[0] = idx;// 用来记录其长度
    return res;
}


int main() {
    int num_keywords = 4;
    char **keywords = malloc(sizeof(char *) * num_keywords);
    keywords[0] = "ab";
    keywords[1] = "bc";
    keywords[2] = "cd";
    keywords[3] = "de";

    insert_and_build(num_keywords, keywords);

    int *all = find_all("abcdcdcd");
    printf("hit = (%d)\n", all[0] - 1);
    for (int i = 1; i < all[0]; i++) {
        printf("%d,", all[i]);
    }
    printf("\n");

    int *all2 = find_all2("abcdcdcd");
    printf("hit = (%d)\n", all2[0] / 2);
    for (int i = 1; i < all2[0]; i += 2) {
        printf("find %s at %d | ", keywords[all2[i]], all2[i + 1]);
    }
    printf("\n");

    assert(find_cnt("abcdcdcd") == 5);
    assert(find_num("abcdcdcd") == 3);

    free(all);
    free(all2);

    return 0;
}

