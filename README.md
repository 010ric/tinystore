# IMLAB

## Task 0

In this preliminary test, you should implement the storage backend *tinystore* for a relation with three attributes
(*a*, *b*, and *c*). Each row is dynamically allocated on the heap. For attribute *a*, the relation maintains a hash index
which stores pointers to the rows. Rows with the same hash value are linked using the *next* field and can only be accessed
through the hash table (to scan all rows, one has to iterate through the hash table).
This storage format is used in Hekaton, the main-memory engine of Microsoft SQL Server 2014.

Implement the constructor, destructor, `Insert`, `Lookup` and `Remove` functions of the `Relation` and make yourself familar with GitLab.

For each commit, our build agents will execute the [build script](./.gitlab-ci.yml) which runs tests and a linter.
The linter will check if your code (roughly) conforms to the
[Google C++ style guide](https://google.github.io/styleguide/cppguide.html).

Relevant files:
- [Tinystore header](./include/imlab/tinystore.h)
- [Tinystore implementation](./src/tinystore.cc)
- [Tinystore test](./test/tinystore_test.cc)

Fork this project into your namespace and commit your solution.
The total code required is less than 50 lines.

*Please do not create a merge request!*
