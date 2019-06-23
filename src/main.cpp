#include "arvore.h"
#include "decodificador.h"

int main(int argc, char* argv[]){
    /* Coleta os argumentos */
    bool impr = false;
    if (argc == 2)
        impr = true;
    
    /* Carrega as definições do Código Morse do arquivo 'morse.txt' */
    Trie codigo_morse;
    carrega_Trie(codigo_morse);


    /* Lê as entradas */
    std::string frase;
    while (std::getline(std::cin, frase)){
        decode_frase(codigo_morse, frase);
    }

    /* Imprime a Trie, se requisitado */
    if (impr == true){
        std::cout << std::endl;
        codigo_morse.Imprime();
    }
    return 0;
}