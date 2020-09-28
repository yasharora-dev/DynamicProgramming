//
//  EnjoyPartyProblem.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 18/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "EnjoyPartyProblem.hpp"
#include <iostream>
#include <vector>

using namespace std;

int EnjoyPartyProblem::getUniqueWaysToEnjoyParty_Rec(int n)
{
    if(n==1 || n==2)
        return n;
    
    //element of choice
    return ( getUniqueWaysToEnjoyParty_DP(n-1) + (getUniqueWaysToEnjoyParty_DP(n-2)*(n-1)) );
    
}

int EnjoyPartyProblem::getUniqueWaysToEnjoyParty_DP(int n)
{

    vector<int> DP(n+1);
    DP[1]=1;
    DP[2]=2;
    
    for(int i=3;i<=n;i++)
    {
        //element of choice
        //enjoy alone or pair up with any of (n-1) persons
        //so
        DP[i] = ( (DP[i-1]*1) + ((i-1)*DP[i-2]) );
    }
    
    
    return DP[n];
}

//there are n people in the party
//now every person has the option to either enjoy the party or to pair up with some one
// i.e. enjoy alone noofways(n-1)*1 + (or) pair up( n-1 * (nofofways(n-2))
// for pairing up each person has n-1 options
// so (n-1) * nofoways(n-2) persons paired up
void EnjoyPartyProblem::Test_getUniqueWaysToEnjoyParty()
{
    int n = 5;
    
    cout<<"No of Unique ways "<<n<<" people can enjoy the party are by Recursion: "<<getUniqueWaysToEnjoyParty_Rec(n)<<endl;
    
    cout<<"No of Unique ways "<<n<<" people can enjoy the party are by DP: "<<getUniqueWaysToEnjoyParty_DP(n)<<endl;
    
}
