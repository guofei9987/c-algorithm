#include "AC_DAT.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "RecurrentArray.h"


AC_DAT *AC_DAT_Init(int M, int n_chars) {
    AC_DAT *acDat = malloc(sizeof(AC_DAT));
    acDat->M = M;
    acDat->n_chars = n_chars;
    acDat->fail = calloc(M, sizeof(int));
    acDat->ch = calloc(M * n_chars, sizeof(int));
    acDat->bo = calloc(M, sizeof(int));
    acDat->word_idx = calloc(M, sizeof(int));
    acDat->tot = 1;
    return acDat;
}

void AC_DAT_Free(AC_DAT *acDat) {
    free(acDat->fail);
    free(acDat->ch);
    free(acDat->bo);
    free(acDat->word_idx);
    free(acDat);
}

void AC_DAT_Insert(AC_DAT *acDat, char *s, int idx) {
    int *ch = acDat->ch;

    int u = 1;
    for (int i = 0; i < strlen(s); i++) {
        int c = s[i] - 'a';
        if (!ch[u * acDat->n_chars + c]) {
            ch[u * acDat->n_chars + c] = ++(acDat->tot);
        }

        u = ch[u * acDat->n_chars + c];
    }
    acDat->bo[u]++;

//    存放对应位置的单词编号
    acDat->word_idx[u] = idx;
}

void AC_DAT_Build(AC_DAT *acDat) {
    int *fail = acDat->fail;
    int *ch = acDat->ch;
    int n_chars = acDat->n_chars;

    //    不知道多大合适
    Rec_Array *q = RecArray_Init(acDat->M * 2);

    fail[1] = 0;
    RecArray_Push(q, 1);
    for (int i = 0; i < 26; i++) {
        ch[0 + i] = 1;
    }

    while (!RecArray_IsEmpty(q)) {
        int u = Pop_Front_Rec_Array(q);
        for (int i = 0; i < 26; i++) {
            if (!ch[u * n_chars + i]) {
                ch[u * n_chars + i] = ch[acDat->fail[u] * n_chars + i];
            } else {
                fail[ch[u * acDat->n_chars + i]] = ch[fail[u] * n_chars + i];
                RecArray_Push(q, ch[u * n_chars + i]);
            }
        }
    }
    RecArray_Free(q);
}


AC_DAT *AC_DAT_Build_From_Words(int len_keywords, char **keywords) {
    AC_DAT *acDat = AC_DAT_Init(100, 26);

    for (int i = 0; i < len_keywords; i++) {
        AC_DAT_Insert(acDat, keywords[i], i);
    }
    AC_DAT_Build(acDat);
    return acDat;
}


// 命中了哪些单词，返回这些单词的 index，以及对应在s中的位置
int *AC_DAT_Find_All(AC_DAT *acDat, char *s) {
    int *ch = acDat->ch;
    int *bo = acDat->bo;
    int *word_idx = acDat->word_idx;
    int *fail = acDat->fail;
    int n_chars = acDat->n_chars;


    int *res = malloc(sizeof(int) * (2 * acDat->M + 1));
    int idx = 1;
//    res[0] 存放实际长度

    int u = 1;
    for (int i = 0; i < strlen(s); i++) {
        int c = s[i] - 'a', k = ch[u * n_chars + c];
        while (k && bo[k] != -1) {
            if (bo[k] != 0) {
                res[idx++] = word_idx[k]; // 匹配到哪个词
                res[idx++] = i; //匹配到的单词，其结尾出现在 s 的哪个位置
            }
            k = fail[k];
        }
        u = ch[u * n_chars + c];
    }
    res[0] = idx;// 用来记录其长度
    return res;
}
