#ifndef C_ALGORITHM_AC_DAT_H
#define C_ALGORITHM_AC_DAT_H

typedef struct {
//    M 应当是 keyword 的长度之和
    int M;

    // 字母的数量
    int n_chars;
    int *fail;
    int *ch;
    int *bo;
    int tot;

    //bo存放的编号 -> 单词的 idx
    int *word_idx;
} AC_DAT;


AC_DAT *AC_DAT_Init(int M, int n_chars);

void AC_DAT_Free(AC_DAT *acDat);

AC_DAT *AC_DAT_Build_From_Words(int len_keywords, char **keywords);


// 命中了哪些单词，返回这些单词的 index，以及对应在s中的位置
int *AC_DAT_Find_All(AC_DAT *acDat, char *s);


#endif //C_ALGORITHM_AC_DAT_H
