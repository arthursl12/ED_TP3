#ifndef ARVORE_H
#define ARVORE_H

#include <string>

struct node_t{
    node_t* esq;
    node_t* dir;
    char symbol;

    node_t();
    node_t(const node_t& outro);
    node_t& operator=(const node_t& outro);
    ~node_t();
};

class Trie{
public:
    Trie();
    Trie(const Trie& outro);
    Trie& operator=(const Trie& outro);
    ~Trie();

    void Insere(char registro, std::string chave);
    void Imprime();
    bool Pesquisa(std::string& result, std::string chave);
private:
    node_t* raiz;
};

#endif /* ARVORE_H */