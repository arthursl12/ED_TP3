#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "decodificador.h"

TEST_CASE("str_tok"){
    std::string teste = "--. .-. ..-/... .. ./.- .-.-.- .- .-/./././.-";
    std::string token;
    std::string token1;
    CHECK(str_tok(teste,"/",token) == true);
    CHECK(token == "--. .-. ..-");
    token1 = token;

    CHECK(str_tok(teste,"/",token) == true);
    CHECK(token == "... .. .");

    CHECK(str_tok(teste,"/",token) == true);
    CHECK(token == ".- .-.-.- .- .-");

    CHECK(str_tok(teste,"/",token) == true);
    CHECK(token == ".");

    CHECK(str_tok(teste,"/",token) == true);
    CHECK(token == ".");

    CHECK(str_tok(teste,"/",token) == true);
    CHECK(token == ".");

    CHECK(str_tok(teste,"/",token) == false);
    CHECK(token == ".-");
    CHECK(teste == ".-");

    CHECK(str_tok(teste,"/",token) == false);
    CHECK(token == ".-");
    CHECK(teste == ".-");

    CHECK(str_tok(token1," ",token) == true);
    CHECK(token == "--.");

    CHECK(str_tok(token1," ",token) == true);
    CHECK(token == ".-.");

    CHECK(str_tok(token1," ",token) == false);
    CHECK(token == "..-");

    CHECK(str_tok(token1," ",token) == false);
    CHECK(token == "..-");
}

TEST_CASE("carrega_Trie"){
    Trie T;
    std::string resp = "E .\nU ..\nS ...\nH ....\n5 .....\n4 ....-\nV ...-\n3 ...--\nI ..-\nA ..-.\n2 ..---\n";
    resp += "F .-\nR .-.\nL .-..\nW .--\nP .--.\nJ .---\n1 .----\nD -\nM -.\nT -..\nB -...\n6 -....\nX -..-\nK -.-\n";
    resp += "C -.-.\nY -.--\nG --\nN --.\nZ --..\n7 --...\nQ --.-\nO ---\n8 ---..\n9 ----.\n0 -----\n";

    carrega_Trie(T);

    std::stringstream ss;
    //change the underlying buffer and save the old buffer
    auto old_buf = std::cout.rdbuf(ss.rdbuf()); 

    T.Imprime();

    std::cout.rdbuf(old_buf); //reset
    CHECK(ss.str() == resp);    
    
}

TEST_CASE("decodificador"){
    Trie T;
    carrega_Trie(T);
    
    CHECK(decodificador(T, "..-.") == "A");
    CHECK(decodificador(T, "-") == "D");
    CHECK(decodificador(T, ".") == "E");
    CHECK(decodificador(T, "-.-.") == "C");
}

TEST_CASE("decodifica palavra e frase"){
    SUBCASE("palavra: com espaço"){
        Trie codigo_morse;
        carrega_Trie(codigo_morse);

        std::stringstream ss;
        //change the underlying buffer and save the old buffer
        auto old_buf = std::cout.rdbuf(ss.rdbuf()); 

        decode_palavra(codigo_morse, ".-.. ..- ...- .-. .", true);

        std::cout.rdbuf(old_buf); //reset
        CHECK(ss.str() == "LIVRE ");  
    }
    SUBCASE("palavra: sem espaço"){
        Trie codigo_morse;
        carrega_Trie(codigo_morse);

        std::stringstream ss;
        //change the underlying buffer and save the old buffer
        auto old_buf = std::cout.rdbuf(ss.rdbuf()); 

        decode_palavra(codigo_morse, ". ... -.. --- ..", false);

        std::cout.rdbuf(old_buf); //reset
        CHECK(ss.str() == "ESTOU");  
    }
    SUBCASE("frase"){
        Trie codigo_morse;
        carrega_Trie(codigo_morse);

        std::stringstream ss;
        //change the underlying buffer and save the old buffer
        auto old_buf = std::cout.rdbuf(ss.rdbuf()); 

        decode_frase(codigo_morse, "..-. / --. . ...- . / -... .-. ..-. --. -.-. ..-. / -... .-. ..- .-.. .... ..-. --. - --- / --. --- / -.-. .... ..-. ---");

        std::cout.rdbuf(old_buf); //reset
        CHECK(ss.str() == "A NEVE BRANCA BRILHANDO NO CHAO\n");  
    } 
}