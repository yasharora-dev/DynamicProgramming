//
//  LongestpalindromicSubsequence.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 22/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class LongestPalindromicSubsequence{
public:
    static int getLongestPalindromicSubSequence(string str)
    {
        int len = str.length();
        
        vector<vector<int>> DP(len);
        for(int i=0;i<DP.size();i++)
            DP[i]=vector<int>(len,0);
        //base case: longest palindromic length of string with start and end of length 1 0..0 1..1 etc is 1
        for(int st=0;st<len;st++)
        {
            DP[st][st]=1;
        }
        
        //from length 1 to len
        for(int l=1;l<=len;l++)
        {
            for(int i=0;i<len-l;i++)
            {
                int j= i+l;
                
                if(str[i]==str[j])
                {
                    DP[i][j]=2 + DP[i+1][j-1];
                }
                else
                    DP[i][j]=max(DP[i+1][j],DP[i][j-1]);
            }
        }
        
        return DP[0][len-1];
    }
    static void Test_LongestPalindromicSubsequence()
    {
        string str = "agbdba"; //anser abdba
        
        cout<<"Longest palindromic subsequence in string: " <<str<<" :"<<getLongestPalindromicSubSequence(str)<<endl;
        
    }
};
