/**
 * @file inverte_palavra.c
 * @author Emanuel Catão Montenegro (emanuel.montenegro@mail.uft.edu.br)
 * @brief Inverte a ordem das palavras em uma frase:
 * 1 - Inverte toda a string de modo que a última palavra passa a ocupar as primeiras posições da string
 * 2 - Inverte as palavras, palavra por palavra, de modo que a primeira palavra passa a ser a última palavra da string
 * original;
 * obs: a string original é modificada
 * @version 0.1
 * @date 2022-06-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>

/**
 * @brief percorre a string até que ache um backspace, o fim
 * da string ou mesmo uma quebra de linha (por estarmos usando o fgets :sadvibes:)
 * 
 * @param str 
 * @return int tamanho da próxima palavra na string
 */
int TamanhoPalavra(char *str) {
    int i;
    for (i = 0; *str != '\0' && *str != ' ' && *str != '\n'; i++) str++;
    return i;
}

/**
 * @brief Permuta os caracteres
 * 
 * @param char1 
 * @param char2 
 */
void TrocaCaracteres(char* char1, char* char2) {
    char temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}

/**
 * @brief Inverte os caracteres das substrings da string
 * 
 * @param str 
 * @param len 
 */
void InverteSubstrings(char *str, int len) {
    char *i = str;
    char *j = str + len;

    //aqui talvez fosse mais conveniente o uso de um for, por questão organizacional
    while(i < j) {
        TrocaCaracteres(i, j);
        i++; 
        j--;
    }
}

/**
 * @brief inverte os caracteres de uma palavra da string
 * 
 * @param str 
 */
void InvertePalavras(char *str) {
    //subtraímos 2 do tamanho da string para eliminarmos também o \n capturado no final da entrada
    //e não acabarmos não entrando no while
    InverteSubstrings(str, strlen(str) - 2);
    
    while (TamanhoPalavra(str) != 0) {
        InverteSubstrings(str, TamanhoPalavra(str) - 1);
        str += TamanhoPalavra(str) + 1;
    }
}

/**
 * @brief main :?
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
    char str[640];
    printf("Informe a string a ser invertida (max 640 caracteres): \n");
    fflush(stdin);
    //usamos o fgets para ter o controle do tamanho da entrada e não ter problema com buffer
    fgets (str, 640, stdin);
    InvertePalavras(str);
    printf("%s", str);
}