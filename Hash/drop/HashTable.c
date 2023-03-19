#include "HashTable.h"
#include <limits.h>
#include <assert.h>
#include <stdlib.h>


struct HashTable HashTable_new(int hint,
                               int cmp(const void *key1, const void *key2),
                               unsigned hash(const void *key)) {

    struct HashTable hashTable;
    int i;
    static int primes[] = {509, 509, 2021, 2053, 4093, 8191, 16381, 32771, 65521, INT_MAX};

    assert(hint > 0);

    for (i = 1; primes[i] < hint; i++);

    hashTable = malloc(sizeof(*hashTable) + primes[i - 1] * sizeof(hashTable.buckets[0]));
    hashTable.size = primes[i - 1];
    hashTable.cmp = cmp ? cmp : cmpatom;
    hashTable.hash = hash ? hash : hashatom;
    hashTable.buckets = (struct binding **) (hashTable + 1);
    for (i = 0; i < hashTable.size; i++) {
        hashTable.buckets[i] = NULL;
    }
    hashTable.size = 0;
    return hashTable;
}

static int cmpatom(const void *key1, const void *key2) {
    return key1 != key2;
}

static unsigned hashatom(const void *key) {
    return (unsigned long) key >> 2;
}