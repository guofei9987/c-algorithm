//
// Created by 郭飞 on 2023/3/18.
//

#ifndef C_ALGORITHM_CONVERTOR_H
#define C_ALGORITHM_CONVERTOR_H
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Hash.h"


DynamicArray *LinkedList2DynamicArray(LinkedList *linkedList);

DynamicArray *HashSet2Array(HashSet *obj);
#endif //C_ALGORITHM_CONVERTOR_H
