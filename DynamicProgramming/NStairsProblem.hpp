//
//  NStairsProblem.hpp
//  DynamicProgramming
//
//  Created by Yash Arora on 18/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef NStairsProblem_hpp
#define NStairsProblem_hpp

#include <stdio.h>
class NStairsProblem{
public:
    static int countWaysToReachStairs_Rec(int n);
    static int countWaysToReachStairs_Mem(int n);
    static int countWaysToReachStairs_DP(int n);
    static void Test_countWaysToReachStairs();
};
#endif /* NStairsProblem_hpp */
