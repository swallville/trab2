/*
*  funcs.hpp
*  Lab2
*
*  Created by Lukas Ferreira on 14/09/16.
*  Copyright © 2016 Lukas Ferreira. All rights reserved.
*/

#ifndef funcs_hpp
#define funcs_hpp

#include <string>
#include "gtest/gtest.h"

using namespace std;

namespace Add {
    class Addition
    {
    public:
        int value(char roman);
        int from_roman(const string& input);
        string to_roman(int value);
        bool it_contains (string input);
    };
    /* just tell the compiler to expect a class def */
}

#endif /* funcs_hpp */
