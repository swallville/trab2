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
