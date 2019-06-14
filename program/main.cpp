#include "arvore.h"

int main(int argc, char* argv[]){
    /* Coleta os argumentos */
    bool impr = false;
    if (argc == 2)
        impr = true;
    std::cout << (int) '-' << std::endl;
    std::cout << (int) '.' << std::endl;
    std::cout << (char)(0+'-') << std::endl;
    std::string subchave2 = "";
    subchave2 += (char)(0+'-');
    std::cout << subchave2 << std::endl;
    
    Trie T;
    T.Insere('D',"-");
    T.Insere('E',".");
    T.Insere('F',".-");
    T.Insere('G',"--");
    if (impr)
        T.Imprime();
    
    return 0;
}