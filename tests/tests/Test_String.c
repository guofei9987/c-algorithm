#include <stdio.h>
#include <stdlib.h>
#include "AC_DAT.h"
#include "Test_String.h"

//int test_AC_DAT() {
//
//    int num_keywords = 4;
//    char **keywords = malloc(sizeof(char *) * num_keywords);
//    keywords[0] = "ab";
//    keywords[1] = "bc";
//    keywords[2] = "cd";
//    keywords[3] = "de";
//
//    AC_DAT *acDat = AC_DAT_Build_From_Words(num_keywords, keywords);
//
//
//    int *all2 = AC_DAT_Find_All(acDat, "abcdcdcd");
//    printf("hit = (%d)\n", all2[0] / 2);
//    for (int i = 1; i < all2[0]; i += 2) {
//        printf("find %s at %d | ", keywords[all2[i]], all2[i + 1]);
//    }
//    printf("\n");
//
//    free(all2);
//
//    AC_DAT_Free(acDat);
//
//    printf("finished: test_ac_dat\n");
//
//    return 0;
//}



int test_ac_dat_keywords() {
    int num_keywords = 4;
    char **keywords = malloc(sizeof(char *) * num_keywords);
    keywords[0] = "ab";
    keywords[1] = "bc";
    keywords[2] = "ff";
    keywords[3] = "123";
//    keywords[4] = "ff";

    AC_DAT *acDat = AC_DAT_Build_From_Words(num_keywords, keywords, 0);


    int *all2 = AC_DAT_Find_All(acDat, "ababcdcdcd123aaa123ffaff");
    printf("hit = (%d)\n", all2[0] / 2);
    for (int i = 1; i < all2[0]; i += 2) {
        printf("find %s at %d | ", keywords[all2[i]], all2[i + 1]);
    }
    printf("\n");

    free(all2);

    AC_DAT_Free(acDat);

    return 0;
}



//正则匹配
int test_ac_dat_pattern() {
    int num_keywords = 3;
    char **keywords = malloc(sizeof(char *) * num_keywords);
    keywords[0] = "dddd";
    keywords[1] = "wdddw";
    keywords[2] = "www";
//    keywords[3] = "123";
//    keywords[4] = "ff";

    AC_DAT *acDat = AC_DAT_Build_From_Words(num_keywords, keywords, 1);


    int *all2 = AC_DAT_Find_All(acDat, "1234aa123aab");
    printf("hit = (%d)\n", all2[0] / 2);
    for (int i = 1; i < all2[0]; i += 2) {
        printf("find %s at %d | ", keywords[all2[i]], all2[i + 1]);
    }
    printf("\n");

    free(all2);

    AC_DAT_Free(acDat);
    return 0;
}

