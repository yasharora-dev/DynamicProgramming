//
//  GoldRobberyProblem.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 18/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "GoldRobberyProblem.hpp"
#include <iostream>

int GoldRobberyProblem::maxGoldRobbing_Rec(const vector<int> &houseGolds, int n)
{
    if(n==1)
        return houseGolds[0];
    if(n==2)
        return max(houseGolds[0], houseGolds[1]);
    
    return max(maxGoldRobbing_Rec(houseGolds ,n-1), maxGoldRobbing_Rec(houseGolds, n-2) + houseGolds[n-1]);
}

int GoldRobberyProblem::maxGoldRobbing_DP(const vector<int> &houseGolds, int n)
{
    if(n < 1)
        return houseGolds[0];
    
    vector<int> DP(n,-1);
    DP[0] = houseGolds[0];
    DP[1] = max (houseGolds[1],houseGolds[0]);
    
    for(int i=2;i<n;i++)
    {
        DP[i] = max(DP[i-1], DP[i-2] + houseGolds[i]);
    }
        
    return DP[n-1];
}

void GoldRobberyProblem::Test_maxGoldRobbing()
{
    vector<int> goldHousesStreet1 {2,7,9,3,1};
   
    vector<int> goldHousesStreet2 {2,7,9,3,1,4};
    
    vector<int> goldHousesStreet3 {3, 5, 1, 3, 4, 5, 1};
    
    cout<<"Max Gold that can be robbed in street1: "<< maxGoldRobbing_Rec(goldHousesStreet1,goldHousesStreet1.size())<<endl;
    
    cout<<"Max Gold that can be robbed in street2: "<< maxGoldRobbing_Rec(goldHousesStreet2,goldHousesStreet2.size())<<endl;
    
    cout<<"Max Gold that can be robbed in street3: "<< maxGoldRobbing_Rec(goldHousesStreet3,goldHousesStreet3.size())<<endl;

    
    cout<<"Max Gold that can be robbed in street1: "<< maxGoldRobbing_DP(goldHousesStreet1,goldHousesStreet1.size())<<endl;
    
    cout<<"Max Gold that can be robbed in street2: "<< maxGoldRobbing_DP(goldHousesStreet2,goldHousesStreet2.size())<<endl;
    
    cout<<"Max Gold that can be robbed in street3: "<< maxGoldRobbing_DP(goldHousesStreet3,goldHousesStreet3.size())<<endl;
    
}
