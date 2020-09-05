//
//  LongestCommonSubsequence.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 05/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "LongestCommonSubsequence.hpp"
#include <iostream>
#include <vector>

//bottom up approach
int LCS::findLCS_BTMUP(const string &in1, const string &in2, int n, int m)
{
    if(n == 0 || m ==0)
        return 0;
    
    else if(in1[n-1] == in2[m-1])
        return 1 + findLCS_BTMUP(in1, in2, n-1, m-1);
    
    else
        return max(findLCS_BTMUP(in1, in2, n-1, m),findLCS_BTMUP(in1, in2, n, m-1));
    
}

int LCS::findLCS_DP_BTMUP(const string &in1, const string &in2, int n, int m)
{
    int lcs=0;
    
    return lcs;
    
}


int LCS::findLCS_TPDWN(const string &in1, const string &in2, int index1, int index2)
{
    if(index1 == in1.size() || index2 == in2.size())
        return 0;
    
    else if(in1[index1]==in2[index2])
        return 1 + findLCS_TPDWN(in1, in2, index1+1, index2+1);
    
    else
        return max( findLCS_TPDWN(in1, in2, index1+1, index2) , findLCS_TPDWN(in1, in2, index1, index2+1));
    
}

int LCS::findLCS_DP_TPDWN(const string &in1, const string &in2, int n, int m)
{
    vector<int> DP[n+1];
    
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            DP[i].push_back(0);
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(in1[i-1]==in2[j-1])
                DP[i][j]= 1+ (DP[i-1][j-1]);
            else
                DP[i][j]= max(DP[i-1][j],DP[i][j-1]);
        }
    }
    cout<<endl;
    cout<<"Input 1:     "<<in1<<endl;
    cout<<"Input2:      "<<in2<<endl;
    
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
    
    string lcs;
    int len = DP[n][m];
    int i = n;
    int j=m;
    while(i >=0 && j>=0 && len > 0)
    {
        if( (DP[i-1][j] < DP[i][j]) && (DP[i][j-1] < DP[i][j]) )
        {
            lcs.push_back( in1[i-1]);
            i = i-1;
            j = j-1;
            len--;
        }
        else if(DP[i][j] == DP[i-1][j])
        {
            i = i-1;
        }
        else
            j =j-1;
          
    }
    
    cout<<"LCS String is :"<<lcs<<endl;
    return DP[n][m];
}

void LCS::Test_findLCS()
{
    string in1 = "abcdaf";
    string in2 = "acbcf";
    
    cout<<"Bottom Up LCS of strings is "<<findLCS_BTMUP(in1, in2, in1.size(), in2.size())<<endl;
    cout<<"Top Down LCS of strings is "<<findLCS_TPDWN(in1, in2, 0, 0)<<endl;
    cout<<"Top Down DP LCS of string is "<<findLCS_DP_TPDWN(in1,in2,in1.size(),in2.size())<<endl;
}
