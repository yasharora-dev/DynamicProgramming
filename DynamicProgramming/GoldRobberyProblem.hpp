//
//  GoldRobberyProblem.hpp
//  DynamicProgramming
//
//  Created by Yash Arora on 18/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef GoldRobberyProblem_hpp
#define GoldRobberyProblem_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class GoldRobberyProblem{
    
public:
    static int maxGoldRobbing_Rec(const vector<int> &houseGolds,int n);
    static int maxGoldRobbing_DP(const vector<int> &houseGolds, int n);
    static void Test_maxGoldRobbing();
};
#endif /* GoldRobberyProblem_hpp */
