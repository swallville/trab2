/*
*  AddTest.cpp
*  Lab2
*
*  Created by Lukas Ferreira on 14/09/16.
*  Copyright © 2016 Lukas Ferreira. All rights reserved.
*/

#include "funcs.hpp"
using namespace Add;
using namespace testing;

class AddTest : public::Test
{
    void SetUp(){}
    virtual void TearDown(){}
    
};
/* Teste da funcao from_roman():
  Descrição:
    Converte um numero romano para decimal
  Parâmetros:
    input - referencia para a string do numero romano
  Retorno:
    int - numero romano em sua forma decimal
*/

TEST_F(AddTest, from_roman){
   string num   = "MDCC"; /* 1700 */
   string num1  = "LXXIX"; /* 79 */
   string num2  = "DCCCXCIX"; /* 899 */
   //string momo = "MDXLIX";
   string num3  = "MCMXLIX"; /* 1949 */
   string num4  = "MCMLXXXIV"; /* 1984 */
   string num5  = "MCMXCIX"; /* 1999 */
   string num6  = "MMDCCCLXXXVIII"; /* 2888 */
   string num7  = "MMCMXCIX"; /* 2999 */
   string emp   = ""; /* string vazia */
   /* Strings com numeros ou conteudo invalido */
   string wrng  = "VV";
   string wrng2 = "VVV";
   string wrng3 = "CCCC";
   string wrng4 = "DD";
   string wrng5 = "iiiii";
   string wrng6 = "ll";
   string wrng7 = "iiv";
   string err   = "MCMXDXCIX";
   string err2  = "MCMXDXCIX";
   string err3  = "21421";
   string err4  = "HOMEMPASSARO";
   string err5  = "MMMX"; /* 3010 */
   string err6  = "MMC MXCIX"; /* 2999, mas com caracter invalido */
   string err7  = "!MMCMXCIX"; /* 2999, mas com caracter invalido */

   Addition addition;
   /* Testes */
   EXPECT_EQ(1700, addition.from_roman(num));
   EXPECT_EQ(79, addition.from_roman(num1));
   EXPECT_EQ(899, addition.from_roman(num2));
   EXPECT_EQ(1949, addition.from_roman(num3));
   EXPECT_EQ(1984, addition.from_roman(num4));
   EXPECT_EQ(1999, addition.from_roman(num5));
   EXPECT_EQ(2888, addition.from_roman(num6));
   EXPECT_EQ(2999, addition.from_roman(num7));
   EXPECT_EQ(-1, addition.from_roman(emp));
   EXPECT_EQ(-1, addition.from_roman(wrng));
   EXPECT_EQ(-1, addition.from_roman(wrng2));
   EXPECT_EQ(-1, addition.from_roman(wrng3));
   EXPECT_EQ(-1, addition.from_roman(wrng4));
   EXPECT_EQ(-1, addition.from_roman(wrng5));
   EXPECT_EQ(-1, addition.from_roman(wrng6));
   EXPECT_EQ(-1, addition.from_roman(wrng7));
   EXPECT_EQ(-1, addition.from_roman(err));
   EXPECT_EQ(-1, addition.from_roman(err2));
   EXPECT_EQ(-1, addition.from_roman(err3));
   EXPECT_EQ(-1, addition.from_roman(err4));
   EXPECT_EQ(-1, addition.from_roman(err5));
   EXPECT_EQ(-1, addition.from_roman(err6));
   EXPECT_EQ(-1, addition.from_roman(err7));
}

/* Teste da funcao to_roman():
 Descrição:
    Converte um numero decimal para romano
 Parâmetros:
    value - inteiro a ser convertido para romano
 Retorno:
    string - numero decimal em sua forma romana
 */

TEST_F(AddTest, to_roman){
    int momo = 1786;
    int momo2 = 400;
    int momo3 = 2547;
    
    Addition addition;
    
    EXPECT_EQ("MDCCLXXXVI", addition.to_roman(momo));
    EXPECT_EQ("CD", addition.to_roman(momo2));
    EXPECT_EQ("MMDXLVII", addition.to_roman(momo3));
    EXPECT_NE("CCCC", addition.to_roman(400));
}

/* Teste da funcao it_contains():
 Descrição:
    Verifica se o numero romano e 900 ou 400 ou 90 ou 9 ou 4
 Parâmetros:
    input - numero romano a ser verificado
 Retorno:
    True se o numero romano existir, False do contrario
 */


TEST_F(AddTest, it_contains){
    string caseA = "CM";
    string caseB = "CD";
    string caseC = "XC";
    string caseD = "XL";
    string caseE = "IX";
    string caseF = "IV";
    string err1  = "MCMXDXCIX";
    string emp   = ""; /* string vazia */
    string num   = "MDCC"; /* 1700 */
    
    Addition addition;
    
    EXPECT_EQ(true, addition.it_contains(caseA));
    EXPECT_EQ(true, addition.it_contains(caseB));
    EXPECT_EQ(true, addition.it_contains(caseC));
    EXPECT_EQ(true, addition.it_contains(caseD));
    EXPECT_EQ(true, addition.it_contains(caseF));
    EXPECT_EQ(true, addition.it_contains(caseE));
    EXPECT_EQ(true, addition.it_contains(caseF));
    EXPECT_NE(true, addition.it_contains(err1));
    EXPECT_NE(true, addition.it_contains(emp));
    EXPECT_NE(true, addition.it_contains(num));
}
