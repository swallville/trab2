/*
*  funcs.cpp
*  Lab2
*
*  Created by Lukas Ferreira on 14/09/16.
*  Copyright © 2016 Lukas Ferreira. All rights reserved.
*/

#include "funcs.hpp"
using namespace Add;

/* Descrição:
 Retorna o numero decimal de acordo com o caracter romano
 Parâmetros:
 roman - char romano a ser convertido para decimal
 Retorno:
 int - decimal do numero romano
 */

int Addition::value(char roman)
{
    switch(roman)
    {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
        case 'i':return 1;
        case 'v':return 5;
        case 'x':return 10;
        case 'l':return 50;
        case 'c':return 100;
        case 'd':return 500;
        case 'm':return 1000;
            
        default: return 0;  /* Se o caracter nao for valido */
    }
}

/* Descrição:
 Converte um numero romano para decimal
 Parâmetros:
 input - referencia para a string do numero romano
 Retorno:
 int - numero romano em sua forma decimal
 */

int Addition::from_roman(const string& input)
{
    int sum = 0;
    int count = 1;
    char prev = input[input.length() - 1];
    char aux;
    string result = "";
    
    if ((value(prev) < 1) || ((input.length() - 1) > 30) || ((input.length() - 1) < 1)) {
        return -1;
    }
    
    for(int i = int((input.length() - 2)); i >= 0; i--)
    {
        /* Caracter Invalido */
        
        if (value(prev) < 1)
        {
            return  -1;
        }
        
        if (prev == input[i])
        {
            count++;
        } else {
            count = 1;
        }
        
        if ((toupper(input[i]) == 'V' || toupper(input[i]) == 'L' || toupper(input[i]) == 'D') && count > 1)
        {
            return -1;
        }
        
        if ((toupper(input[i]) == 'I' || toupper(input[i]) == 'X' || toupper(input[i]) == 'C' || toupper(input[i]) == 'M') && count > 3)
        {
            return -1;
        }
        
        
        /* Verifica com o auxilio de it_contains se
         a sequencia de numeros romanos desejada existe
         */
        if(value(input[i]) < value(prev)) {
            aux = input[i];
            result += aux;
            result += prev;
            
            if (((it_contains(result)) == false)) {
                return -1;
            }
            result = "";
        }
        /* Verifica se a sequencia de numeros romanos e do tipo
         CM, CD, XC, XL, IX, IV ou se e outro qualquer numero romano.
         
         No primeiro caso, subtraimos o segundo numero romano do primeiro, ou seja,
         M - C = 900
         D - C = 400
         C - X = 90
         L - X = 40
         X - I = 9
         V - I = 4
         
         No segundo caso, apenas somamos o numero romano na soma total dado por sum
         */
        if((value(input[i]) < value(prev)) && (input[i] != prev)) {
            sum += (value(prev) - value(input[i]));
            prev = input[i];
        } else {
            if (i == int((input.length() - 2))) {
                sum += value(prev) + value(input[i]);
            } else if ((value(input[i - 1]) < value(input[i])) && ((i - 1) >= 0)) {
                sum += 0;
            } else {
                sum += value(input[i]);
            }
            prev = input[i];
        }
    }
    /* Retorna -1 se a soma for maior que 3000, a soma do contrario */
    return (sum > 3000 ? -1 : sum);
}

/* Descrição:
 Verifica se o numero romano e 900 ou 400 ou 90 ou 9 ou 4
 Parâmetros:
 input - numero romano a ser verificado
 Retorno:
 True se o numero romano existir, False do contrario
 */

bool Addition::it_contains (string input)
{
    string result;
    struct romandata_t { int value; char const* numeral; };
    /* Look-up table para os numeros validos */
    static romandata_t const romandata[] = {
        {900, "CM"},
        {400, "CD"},
        {90, "XC"},
        {40, "XL"},
        {9, "IX"},
        {4, "IV"},
        {0, NULL} };

    for (romandata_t const* current = romandata; current->numeral != NULL; ++current)
    {
        
        if (input == current->numeral)
        {
            return true;
        }
    }

    return false;
}

/* Descrição:
 Converte um numero decimal para romano
 Parâmetros:
 value - inteiro a ser convertido para romano
 Retorno:
 string - numero decimal em sua forma romana 
 */

string Addition::to_roman(int value)
{
    struct romandata_t { int value; char const* numeral; };
    /* Look-up table para os numeros validos */
    static romandata_t const romandata[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
        {0, NULL} };
    string result;
    
    for (romandata_t const* current = romandata; current->value > 0; ++current)
    {
        while (value >= current->value)
        {
            result += current->numeral;
            value  -= current->value;
        }
    }
    return result;
}
