#include <stdio.h>
#include <string.h>
#include <math.h>

int val2ascii(int val);
int ascii2val(char val);

void fgets_modificada(char *str, int tam, FILE *origem)
{
  int i;
  fflush(stdin);
  fgets(str, tam, origem);
  fflush(stdin);
  for(i=0; str[i]!='\0'; i++) {
    if (str[i] == '\n') 
    {
      str[i] = '\0';
      break;
    }
  }
}

int base2dec(char *num, int base)
{
  int val = 0, i, expoente = 0;
  for(i = strlen(num) - 1; i>=0; i--) {
    val += ascii2val(num[i])*pow(base, expoente++);
  }
  return val;
}

void dec2base(int value, int base, char *num) 
{
  int i = 0, tamanho;
  char aux;
  
  while(1) 
  {
    num[i++] = val2ascii(value%base);
    value = (value - (value%base))/base;

    if(value<base)
    {
      if (value == 0) {num[i] = '\0'; break;}
      num[i++] = val2ascii(value);
      num[i] = '\0';
      break;
    }
  }
  
  tamanho = i - 1;
  for(i = 0; i<=tamanho/2; i++) 
  {
    aux = num[i];
    num[i] = num[tamanho - i];
    num[tamanho - i] = aux;
  }
}


int val2ascii(int val) 
{
    int valor;

    if(val>=0 && val<=9)
    {
      valor = val + 48;
    }
                                   
    //Se for maior ou igual a 10 e menor ou igual a 15, será o valor somando 65 (tabela ascii) - 10 (0 a 9).
    else if(val>=10 && val<=15)
    {
      valor = val + 65 - 10;
    }

    return valor;
}


int ascii2val(char val)
{
    int valor;

    if(val>='0' && val<='9')
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

    return valor;
}

void soma(char *num1, int base1, char *num2, int base2, char *resultado, int base_resultado) 
{
  dec2base(base2dec(num1, base1) + base2dec(num2, base2), base_resultado, resultado); 
}

int main() {
  char num1[20], num2[20], resultado[20];
  int base1, base2, base_resultado;

  printf("num1:\n");
  fgets_modificada(num1, 20, stdin);
  printf("base1:\n");
  scanf("%d", &base1);
  
  printf("num2:\n");
  fgets_modificada(num2, 20, stdin);
  printf("base2:\n");
  scanf("%d", &base2);
  
  printf("base resultado:\n");
  scanf("%d", &base_resultado);

  soma(num1, base1, num2, base2,resultado, base_resultado);
  printf("--------------------------\n");
  printf("RESULTADO DA SOMA:\n");
  printf("%s\n", resultado);
  scanf("na base %d\n", &base_resultado);
}
