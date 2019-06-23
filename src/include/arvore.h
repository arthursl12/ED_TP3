#ifndef ARVORE_H
#define ARVORE_H

#define ALFABETO 2
#define CHAR_FINAL 46

#include <string>
#include <iostream>
#include <cstdlib>

struct node_t{
    node_t* filhos[ALFABETO];
    std::string symbol;
    bool folha;

    node_t();
    node_t(const node_t& outro);
    ~node_t();
};

class Trie{
public:
    Trie();
    Trie(const Trie& outro);
    ~Trie();

    void Insere(std::string registro, std::string chave);
    void pre_ordem(node_t* raiz, std::string subchave);
    void Imprime();
    bool Pesquisa(std::string& result, std::string chave);

private:
    node_t* raiz;
};

#endif /* ARVORE_H */