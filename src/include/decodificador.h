#ifndef DECODIFICADOR_H
#define DECODIFICADOR_H

#include <string>
#include <fstream>
#include "arvore.h"

bool str_tok(std::string& str, std::string delimiter, std::string& token);
void carrega_Trie(Trie& codigo_morse);
std::string decodificador(Trie& codigo_morse, std::string codigo);
void decode_palavra(Trie& codigo_morse, std::string palavra, bool espaco);
void decode_frase(Trie& codigo_morse, std::string frase);

#endif /* DECODIFICADOR_H */