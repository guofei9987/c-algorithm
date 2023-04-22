#include "KMP.h"


#include<string.h>
#include<stdlib.h>


void KMP_BuildNext(int *next, int len_p, const char *p) {
    int j = 0, k = -1;
    next[0] = -1;
    while (j < len_p) {
        if (k == -1 || p[j] == p[k]) {
            next[++j] = ++k;
        } else {
            k = next[k];
        }
    }
}


KMP *KMP_Init(char *pattern) {

    KMP *kmp_data = malloc(sizeof(KMP));

    kmp_data->len = (int) strlen(pattern);
    kmp_data->next = malloc(sizeof(int) * kmp_data->len);
    // 不用 kmp_data->pattern = pattern; 是因为输入值 pattern 可能随后被用户 free
    kmp_data->pattern = malloc(sizeof(char) * kmp_data->len);
    strcpy(kmp_data->pattern, pattern);

    KMP_BuildNext(kmp_data->next, kmp_data->len - 1, pattern);

    return kmp_data;
};

void KMP_Free(KMP *kmp_data) {
    free(kmp_data->next);
    free(kmp_data);
};

int KMP_Search(KMP *kmp_data, const char *str1) {

    int len_p = kmp_data->len;
    int *next = kmp_data->next;
    char *str2 = kmp_data->pattern;

    int i = 0, j = 0;
    while (i < strlen(str1) && j < len_p) {
        if (j == -1 || str1[i] == str2[j])
            //j为-1:代表模式串的第一个字符就和当前测试的字符不相等；
            // S[i]==T[j],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移
        {
            i++;
            j++;
        } else {
            j = next[j];//j进行回退
        }
    }
    if (j >= strlen(str2)) {//匹配成功
        return i - len_p;
    }
    return -1;
}