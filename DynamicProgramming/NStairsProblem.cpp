//
//  NStairsProblem.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 18/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "NStairsProblem.hpp"

#include <iostream>
#include <vector>

using namespace std;

int NStairsProblem::countWaysToReachStairs_Rec(int n)
{
    if(n==1||n==2)
        return n;
    
    return countWaysToReachStairs_Rec(n-1)+countWaysToReachStairs_Rec(n-2);
}

int NStairsProblem::countWaysToReachStairs_Mem(int n)
{
    vector<int> DP(n+1,-1);
    if(n==1||n==2)
        return DP[n]=n;
    
    int stepOne = ((DP[n-1] != -1) ? DP[n-1] : countWaysToReachStairs_Mem(n-1));
    int stepTwo = ((DP[n-2] != -1) ? DP[n-2] : countWaysToReachStairs_Mem(n-2));
    
    return stepOne + stepTwo;
}

int NStairsProblem::countWaysToReachStairs_DP(int n)
{
    vector<int> DP(n+1,-1);
    
    DP[1]=1;
    DP[2]=2;
    
    int oneStep;
    int twoStep;
    for(int i=3;i<=n;i++)
    {
        DP[i] = DP[i-1]+DP[i-2];
    }
    return DP[n];
}


void NStairsProblem::Test_countWaysToReachStairs()
{
    int n = 7;
    
    cout<<"No of ways to reach "<<n<< "steps by Recursion : "<< countWaysToReachStairs_Rec(n)<<endl;
    
    cout<<"No of ways to reach "<<n<< "steps by DP : "<< countWaysToReachStairs_DP(n)<<endl;
    
    cout<<"No of ways to reach "<<n<< "steps by Memoization : "<< countWaysToReachStairs_Mem(n)<<endl;
}
