#include "decodificador.h"

/* Particiona a string 'str' pelo delimitador 'delimiter' e guarda o token particionado na string 'token' (o token é removido da string original);
Se não encontrar o token, apenas coloca a string original no 'token';
Retorna 'True' se foi possível fazer a operação, 'False' se não encontrar o delimitador e não conseguir fazer o particionamento; */
bool str_tok(std::string& str, std::string delimiter, std::string& token){
    std::size_t idx = str.find(delimiter);
    token = str.substr(0, idx);

    if (idx == std::string::npos){
        /* Não achou o token: não faz nada e coloca a string original no token*/
        token = str;
        return false;
    }
    str.erase(0, idx+1); /* Remove o token e o delimitador da string original */
    return true;;
}

void carrega_Trie(Trie& codigo_morse){
    std::ifstream morse;
    morse.open("morse.txt",std::ios::in);


    while (!morse.eof()){
        std::string input;
        std::getline(morse, input);

        std::string character;
        std::string code;
        str_tok(input, " ", character);
        code = input;

        codigo_morse.Insere(character, code);
    }
}

/* Recebe uma string 'codigo' em código morse e decodifica ela para o alfabeto, retornando o caractere correspondente  */
std::string decodificador(Trie& codigo_morse, std::string codigo){
    std::string decode;
    codigo_morse.Pesquisa(decode, codigo);
    return decode;
}

/* Decodifica a palavra 'palavra' e imprime a expressão decodificada;
Se 'espaco' for 'True', um espaço será impresso ao final */
void decode_palavra(Trie& codigo_morse, std::string palavra, bool espaco){
    std::string letra;
    while(str_tok(palavra, " ", letra)){
        std::string decode = decodificador(codigo_morse, letra);
        std::cout << decode;
    }
    /* Última letra da palavra */
    std::string decode = decodificador(codigo_morse, letra);
    std::cout << decode;

    /* Colocação do espaço */
    if (espaco == true)
        std::cout << " ";
}

/* Decodifica uma frase, com palavras separadas por '/' e letras separadas por espaços simples,
imprindo a tradução na saída padrão */
void decode_frase(Trie& codigo_morse, std::string frase){
    std::string palavra;
    std::string letra;
    while(str_tok(frase, "/", palavra)){
        decode_palavra(codigo_morse, palavra, true);
    }
    /* Última palavra da frase */
    decode_palavra(codigo_morse, frase, false);
    std::cout << std::endl;
}

