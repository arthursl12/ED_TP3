#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "arvore.h"

TEST_CASE("node_t: construtores"){
    CHECK_NOTHROW(node_t());
    node_t T;
    CHECK_NOTHROW(node_t T1());
    CHECK_NOTHROW(node_t T2 = T);
    node_t T3;
    CHECK_NOTHROW(T3 = T);
}

TEST_CASE("node_t: acesso"){
    node_t node;
    node_t* node1 = new node_t;
    node_t* node2 = new node_t;
    
    
    node.filhos[0] = node1;
    node.filhos[1] = node2;
    node.symbol = ".";

    CHECK(node.filhos[0] == node1);
    CHECK(node.filhos[1] == node2);
    CHECK(node.symbol == ".");
    
    CHECK(node1->filhos[0] == nullptr);
    CHECK(node1->filhos[1] == nullptr);
    
    node_t* node4 = new node_t(node);
    CHECK(node4->filhos[0] == node1);
    CHECK(node4->filhos[1] == node2);
    CHECK(node4->symbol == ".");
}

TEST_CASE("Trie: construtores"){
    CHECK_NOTHROW(Trie());
    Trie T;
    CHECK_NOTHROW(Trie T1());
}

TEST_CASE("Trie: insere e imprime"){
    Trie T;
    T.Insere("D","-");
    T.Insere("E",".");
    T.Insere("F",".-");
    T.Insere("G","--");
    T.Insere("U","..");
    T.Insere("M","-.");

    std::stringstream ss;
    //change the underlying buffer and save the old buffer
    auto old_buf = std::cout.rdbuf(ss.rdbuf()); 

    T.Imprime();

    std::cout.rdbuf(old_buf); //reset
    CHECK(ss.str() == "E .\nU ..\nF .-\nD -\nM -.\nG --\n");    
}

TEST_CASE("Trie: pesquisa"){
    Trie T;
    T.Insere("A","..-.");
    T.Insere("B","-...");
    T.Insere("C","-.-.");
    T.Insere("D","-");
    T.Insere("E",".");
    T.Insere("F",".-");
    T.Insere("G","--");
    // T.Imprime();

    std::string res1;
    CHECK(T.Pesquisa(res1, "..-.") == true);
    CHECK(res1 == "A");
    CHECK(T.Pesquisa(res1, "-") == true);
    CHECK(res1 == "D");
    CHECK(T.Pesquisa(res1, ".") == true);
    CHECK(res1 == "E");
    CHECK(T.Pesquisa(res1, "-.-.") == true);
    CHECK(res1 == "C");
    CHECK(T.Pesquisa(res1, "....") == false);
    CHECK(res1 == "C");
}



