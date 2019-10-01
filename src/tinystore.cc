// ---------------------------------------------------------------------------
// IMLAB
// ---------------------------------------------------------------------------

#include "imlab/tinystore.h"
#include <cassert>
#include "imlab/error.h"
#include <stdio.h>

using Relation = imlab::Relation;
using Row = imlab::Row;
using NotImplementedException = imlab::NotImplementedException;

// Construct a relation
Relation::Relation(uint64_t index_size) : size(0), index_size(index_size) {
    // Make sure the index size is a power of two
    assert((index_size & (index_size - 1)) == 0);
    index = std::vector<Row*>(index_size, nullptr);
}

// Destruct a relation
Relation::~Relation() {
    for (size_t i = 0; i< index.size(); i++) {
        if(index[i] != NULL) {
            Row *cachePtr = index[i]->next, *cachePtr2;
            while (cachePtr != nullptr) {
                cachePtr2 = cachePtr->next;
                delete cachePtr;
                cachePtr = cachePtr2;
            }
        }
    }
}

// Insert a new row
void Relation::Insert(uint64_t a, uint64_t b, uint64_t c) {
    Row* r1 = new Row;r1->a = a;r1->b = b;r1->c = c;r1->next = nullptr;
    Row* rPtr = index[Hash(a)];
    if( rPtr != nullptr){
        while (rPtr->next != NULL) {
            rPtr = rPtr->next;
        }
        rPtr->next = r1;
    } else {
        index[Hash(a)] = r1;
    }
    size += 1;
}

Row* Relation::Lookup(uint64_t a) {
    Row* rPtr = index[Hash(a)];
    while (rPtr != nullptr) {
        if(rPtr->a == a){
            return rPtr;
        }
        rPtr = rPtr->next;
    }
    return nullptr;
}

// Remove a row
void Relation::Remove(Row* row) {
    Row* prevPtr = index[Hash(row->a)];
    Row* cPtr;
    if(index[Hash(row->a)] == row){
        cPtr = index[Hash(row->a)]->next;
        delete index[Hash(row->a)];
        index[Hash(row->a)] = cPtr;
    }
    while(prevPtr->next != nullptr){
        if(prevPtr->next == row){
            cPtr = prevPtr->next->next;
            delete prevPtr->next;
            prevPtr->next = cPtr;
        }
        else{
            prevPtr = prevPtr->next;
        }
    }
}

// Computes index into hash table for attribute value a
uint64_t Relation::Hash(uint64_t a) {
    return a & (index_size - 1);
}
