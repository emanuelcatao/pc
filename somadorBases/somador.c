#include <stdio.h>
#include <string.h>
#include <math.h>

void soma(char *num1, int base1, char *num2, int base2, char *resultado, int base_resultado);

/*recebe o caractere na base de origem, bem como o valor da base origem e converte para decimal, retornando*/
int char2decimal(char val, int base);
/*recebe um valor em decimal e a base de destino e retorna o valor na base fim*/
void decimal2base(int val, int base, char * num);

int main() 
{
    char num1[20], num2[20], resultado[20];
    int base1, base2, base_resultado;

    printf("num1:\n");
    scanf("%s", &num1);
    printf("base1:\n");
    scanf("%d", &base1);
  
    printf("num2:\n");
    scanf("%s", &num1);
    printf("base2:\n");
    scanf("%d", &base2);
  
    printf("base resultado:\n");
    scanf("%d", &base_resultado);

    soma(num1, base1, num2, base2, resultado, base_resultado);
    printf("--------------------------\n");
    printf("RESULTADO DA SOMA:\n");
    printf("%s\n", resultado);
    scanf("na base %d\n", &base_resultado);
    return 0;
}

void soma(char *num1, int base1, char *num2, int base2, char *resultado, int base_resultado) 
{
    int tam1 = strlen(num1) - 1, tam2 = strlen(num2) - 1;
    int i, j, soma, expoente;

    expoente = 0;
    for(i = tam1; i>=0; i--) {
        soma += char2decimal(num1[i], base1)*pow(base1, expoente++);
    }
    expoente = 0;
    for(i = tam2; i>=0; i--) {
        soma += char2decimal(num2[i], base2)*pow(base2, expoente++);
    }

    decimal2base(soma, base_resultado, resultado);
}

int char2decimal(char val, int base)
{   
    int valor;

    if (base == 16) 
    {
        if(val>='0' && val  <='9')
        {
            valor = val - 48;
        }
                    
        //Se for maior ou igual a a e menor ou igual a f, será o valor retirando 97 (tabela ascii) + 10 (0 a 9)
        else if(val>='a' && val<='f')
        {
            valor = val - 97 + 10;
        }
                    
        //Se for maior ou igual a A e menor ou igual a F, será o valor retirando 65 (tabela ascii) + 10 (0 a 9)
        else if(val>='A' && val<='F')
        {
            valor = val - 65 + 10;
        }
    }
    else if(base == 2 || base == 8)
    {
        valor = val - 48;
    }

    return valor;
}

void decimal2base(int val, int base, char *num)
{
    int resto, i, expoente;
    if (base == 16) 
    {
        i = 0;
        expoente = 0;
        while(1) {
            resto = val % base;

            if(resto>=0 && resto<=9)
            {
                num[i++] = resto + 48;
            }

            else if(resto>=10 && resto<=15)
            {       
                num[i++] = resto + 65 - 10;
            }

            val = val - (resto)/base;

            if(val<base)
            {
                num[i++] = base + 48;
                num[i] = '\0';
                break;
            }
        }
    }
    else if(base == 2 || base == 8)
    {
        i = 0;
        expoente = 0;
        while(1) {
            resto = val % base;
            num[i++] = resto + 48;
            val = val - (resto)/base;

            if(val<base)
            {
                num[i++] = base + 48;
                num[i] = '\0';
                break;
            }
        }
    }
}