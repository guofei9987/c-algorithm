#ifndef C_ALGORITHM_HASHTABLE_H
#define C_ALGORITHM_HASHTABLE_H


struct HashTable {
    struct binding {
        struct binding *link;
        const void *key;
        void *val;
    } **buckets;
    int size;
    int (*cmp)(const void *key1, const void *key2);
    unsigned (*hash)(const void *key);
};




struct HashTable HashTable_new(int hint,
        int cmp(const void *key1, const void *key2),
        unsigned hash(const void *key));

#endif //C_ALGORITHM_HASHTABLE_H
