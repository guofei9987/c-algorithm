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

// 0:关键词匹配，1：正则匹配
    int ac_type;
} AC_DAT;

int (*util_build_func)(char s);

int (*util_find_func)(char s);


AC_DAT *AC_DAT_Init(int M, int n_chars, int ac_type);

void AC_DAT_Free(AC_DAT *acDat);

int util_build_from_pattern(char s);

int util_build_from_words(char s);

void AC_DAT_Insert(AC_DAT *acDat, char *s, int idx);

void AC_DAT_Build(AC_DAT *acDat);

AC_DAT *AC_DAT_Build_From_Words(int len_keywords, char **keywords, int ac_type);

int *AC_DAT_Find_All(AC_DAT *acDat, char *s);

#endif //C_ALGORITHM_AC_DAT_H







