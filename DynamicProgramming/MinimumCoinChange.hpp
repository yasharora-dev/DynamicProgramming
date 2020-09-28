//
//  MinimumCoinChange.hpp
//  DynamicProgramming
//
//  Created by Yash Arora on 31/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef MinimumCoinChange_hpp
#define MinimumCoinChange_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class MinimumCoinChange{
public:
    static int findMinCoins_Rec(vector<int> coins,int val);
    static int findMinCoins_DP(vector<int> coins,int val);
    static int findMinCoins_BFS(vector<int> coins,int val);
    static void Test_findMinCoins();
    
};
#endif /* MinimumCoinChange_hpp */
