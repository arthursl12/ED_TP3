#include "arvore.h"

node_t::node_t(){
    for (int i = 0; i < ALFABETO; i++)
        filhos[i] = nullptr;
    folha = false;
}
node_t::node_t(const node_t& outro){
    for (int i = 0; i < ALFABETO; i++)
        filhos[i] = outro.filhos[i];
    symbol = outro.symbol;
    folha = outro.folha;
}
node_t::~node_t(){
    for (int i = 0; i < ALFABETO; i++){
        if (filhos[i] != nullptr)
            delete filhos[i];
    }
}



Trie::Trie(){
    raiz = new node_t();
}
Trie::Trie(const Trie& outra){
    this->raiz = outra.raiz;
}
Trie::~Trie(){
    if (raiz != nullptr){
        for (int i = 0; i < ALFABETO; i++){
            if (raiz->filhos[i] != nullptr)
                delete raiz->filhos[i];
        }
    }
}

void Trie::Insere(char registro, std::string chave){
    node_t* atual = raiz;
    for (int i = 0; i < (int)chave.length(); i++){
        int idx = abs(chave[i] - CHAR_INICIAL);
        if(!atual->filhos[idx]){ /* Checa se a chave com essa terminação existe */
            /* Não existe essa chave temos que criá-la */
            atual->filhos[idx] = new node_t();
        }
        atual = atual->filhos[idx];
    }
    atual->symbol = registro;
    atual->folha = true; /* Marca que ali é o fim de uma palavra (código) válido */
}
void Trie::pre_ordem(node_t* node, std::string subchave){
    if (node != nullptr){
        if (node->folha == true)
            std::cout << node->symbol << " " << subchave << std::endl;
        for (int i = 0; i < ALFABETO; i++){
            std::string subchave2 = subchave;
            int idx = (-1)*i + CHAR_INICIAL;
            subchave2 += (char)(idx);
            pre_ordem(node->filhos[i], subchave2);
        }
    }
}
void Trie::Imprime(){
    pre_ordem(raiz, "");
}

/* Retorna True se encontrar a chave 'chave', False do contrário;
   Coloca o caractere equivalente à chave 'chave' encontrada em 'result'*/
bool Trie::Pesquisa(char& result, std::string chave){
    node_t* atual = raiz;
    for (int i = 0; i < (int)chave.length(); i++){
        int idx = abs(chave[i] - CHAR_INICIAL);
        atual = atual->filhos[idx];
    }
    if (atual->folha){
        /* Chegamos numa folha = código válido */
        result = atual->symbol;
        return true;
    }
    
    /* Não chegamos numa folha, código não existe/inválido */
    return false;
}