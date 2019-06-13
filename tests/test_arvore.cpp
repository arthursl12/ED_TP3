#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "arvore.h"

TEST_CASE("Trie: construtores"){
    CHECK_NOTHROW(Trie());
    Trie T;
    CHECK_NOTHROW(Trie T1());
    CHECK_NOTHROW(Trie T2 = T);
    Trie T3;
    CHECK_NOTHROW(T3 = T);
}

