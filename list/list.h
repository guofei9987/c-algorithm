
#ifndef C_ALGORITHM_LIST_H
#define C_ALGORITHM_LIST_H
typedef enum {
    ATOM, LIST
} ElemTag; //ATOM=0 原子，ATOM=1 子表

typedef struct GLNode {
    ElemTag tag;
    union {
        AtomType atom; //原子节点的值，用户指定
        struct {
            struct GLNode *hp, *tp; //子表指针，hp和tp指向表头和表尾
        } ptr;
    };
} *GList;


#endif //C_ALGORITHM_LIST_H
