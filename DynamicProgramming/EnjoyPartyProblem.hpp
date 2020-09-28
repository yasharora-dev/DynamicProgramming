//
//  EnjoyPartyProblem.hpp
//  DynamicProgramming
//
//  Created by Yash Arora on 18/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef EnjoyPartyProblem_hpp
#define EnjoyPartyProblem_hpp

#include <stdio.h>
class EnjoyPartyProblem{
public:
    static int getUniqueWaysToEnjoyParty_Rec(int n);
    static int getUniqueWaysToEnjoyParty_DP(int n);
    static void Test_getUniqueWaysToEnjoyParty();
};
#endif /* EnjoyPartyProblem_hpp */
