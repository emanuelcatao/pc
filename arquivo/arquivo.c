#include <stdio.h>
#include <string.h>

int main() {
    //1- Qual a funcionalidade da linha a seguir?
        /** R : a linha cria um ponteiro de arquivo que recebe a função para
            abrir o arquivo "ex1_arq1.txt" em read only mode, já que a ideia é buscar uma 
            determinada palavra
        **/
    FILE *arq = fopen("ex1_arq1.txt", "r");
    char buffer[120];
    char *token;
    // 2- Qual a funcionalidade da linha a seguir?
        /** R : a linha cria um declara e define a string busca, ou seja,
            em "ex1_arq1.txt", deve ser buscada a palavra "lorem".
        **/
    char busca[] = "lorem";
    int contagem = 0;
    //3- Qual a funcionalidade do laço de repetição a seguir?
        /** R : a função fgets vai ser executada em cada linha do arquivo,
             a linha é armazenada em buffer e, em cada linha, são feitas as operações
             de busca. O laço só para quando chegar ao final do arquivo arq 
         **/
    while(1) {
        fgets(buffer, 120, arq);
        if(feof(arq)) break;

        // 4- Qual a funcionalidade da linha a seguir?
            /** R : token recebe a primeira palavra em buffer, 
                 delimitada pelos caracteres " .,!?"
             */
        token = strtok(buffer, " .,!?");
        //5- Qual a funcionalidade do laço de repetição a seguir?
            /** R : Se token for != NULL, então compara a palavra em token com
                    a palavra buscada, caso a palavra em token seja igual a palavra em busca
                    o contador é incrementado. Se for diferente, token passa a receber a próxima
                    palavra em buffer que é delimitada pelo caracteres " .,!?"
             **/
        while(token != NULL) {
            // se igual cont++
            if(strcmp(token, busca) == 0) {
                contagem++;
            }
            token = strtok(NULL, " .,!?");
        }
    }
    //6- Qual a saída do código?
        /** R : É printada a quantidade de vezes quem "lorem" aparece no arquivo de texto. 
            Ex: 
                entrada:
                    "lorem coisa palavra mais uma outra lorem aqui outra la lorem isso loren aquilo lorem aqui
                    lorem coisa palavra mais uma outra lorem aqui outra la lorem isso loren aquilo lorem aqui
                    lorem coisa palavra mais uma outra lorem aqui outra la lorem isso loren aquilo lorem aqui
                    lorem coisa palavra mais uma outra lorem aqui outra la lorem isso loren aquilo lorem aqui
                    "
                saída:
                    ocorrencias de lorem: 16
        **/
    printf("ocorrencias de %s: %d\n", busca, contagem);
    fclose(arq);
    return 0;
}