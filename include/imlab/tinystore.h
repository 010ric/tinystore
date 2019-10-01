// ---------------------------------------------------------------------------
// IMLAB
// ---------------------------------------------------------------------------

#ifndef INCLUDE_IMLAB_TINYSTORE_H_
#define INCLUDE_IMLAB_TINYSTORE_H_

#include <array>
#include <cstdint>
#include <vector>

namespace imlab {

struct Row {
    /// Attribute a
    uint64_t a;
    /// Attribute b
    uint64_t b;
    /// Attribute c
    uint64_t c;
    /// The next pointer for linking rows that have the same hash value in the hash table
    Row* next;
};

class Relation {
 public:
    /// Number of rows in relation
    uint64_t size;
    /// Size of the hash table, must be a power of two
    uint64_t index_size;

    /// Hash table
    std::vector<Row*> index;

    /// Construct a relation
    explicit Relation(uint64_t index_size);
    /// Destroy the relation (free all memory)
    ~Relation();

    /// Insert a new row
    void Insert(uint64_t a, uint64_t b, uint64_t c);
    /// Find a row using the index
    Row* Lookup(uint64_t a);
    // Remove a row
    void Remove(Row* row);

    /// Computes index into hash table for attribute value a
    uint64_t Hash(uint64_t a);
};

}  // namespace imlab

#endif  // INCLUDE_IMLAB_TINYSTORE_H_
