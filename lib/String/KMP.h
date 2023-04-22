#ifndef C_ALGORITHM_KMP_H
#define C_ALGORITHM_KMP_H

typedef struct {
    int *next;
    char *pattern;
    int len;
} KMP;

KMP *KMP_Init(char *pattern);

void KMP_Free(KMP *kmp_data);

int KMP_Search(KMP *kmp_data, const char *str1);

#endif //C_ALGORITHM_KMP_H
