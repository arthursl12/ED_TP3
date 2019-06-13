#include "arvore.h"

node_t::node_t(){
    esq = nullptr; 
    dir = nullptr;
}
node_t::node_t(const node_t& outro){
    dir = outro.dir; 
    esq = outro.esq; 
    symbol = outro.symbol;
}
node_t& node_t::operator=(const node_t& outro){
    if (this != &outro){
        this->dir = outro.dir;
        this->esq = outro.esq;
        this->symbol = outro.symbol;
    }
    return *this;
}
node_t::~node_t(){
    if (esq != nullptr)
        delete esq;
    if (dir != nullptr)
        delete dir;
}



Trie::Trie(){
    raiz = nullptr;
}
Trie::Trie(const Trie& outra){
    this->raiz = outra.raiz;
}
Trie& Trie::operator=(const Trie& outra){
    if (this != &outra)
        this->raiz = outra.raiz;
    return *this;
}
Trie::~Trie(){
    if (raiz != nullptr){
        delete raiz->esq;
        delete raiz->dir;
    }
}

void Trie::Insere(char registro, std::string chave){}
void Trie::Imprime(){}
bool Trie::Pesquisa(std::string& result, std::string chave){}