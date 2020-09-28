//
//  LCS.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 21/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class LCSLength{
  
public:
    static int lcsLength(string X, string Y)
    {
        int xLen = X.length();
        int yLen = Y.length();
        
        vector<vector<int>> DP(xLen+1);
        
        for(int i=0;i<DP.size();i++)
            DP[i] = vector<int>(yLen+1);
        
        for(int i=1;i<=xLen;i++)
        {
            for(int j=1;j<=yLen;j++)
            {
                if(X[i-1]==Y[j-1])
                    DP[i][j] = 1+DP[i-1][j-1];
                else
                    DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
                    
            }
        }
        
        return DP[xLen][yLen];
    }
    static int lcsLength_Rec(string X,int i, string Y, int j)
    {
        if(i==X.length() || j==Y.length())
            return 0;
        
        if(X[i]==Y[j])
            return 1+lcsLength_Rec(X, i+1, Y, j+1);
        else
            return max(lcsLength_Rec(X, i+1, Y, j),lcsLength_Rec(X, i, Y, j+1));
        
    }
    static void Test_LCS()
    {
        string X = "abcdaf";
        string Y = "abccf";
        
        cout<<endl;
        cout<<"LCS of string: "<<X<<" and string: "<<Y<<" is :"<<lcsLength_Rec(X,0, Y,0)<<endl;
        cout<<"LCS of string: "<<X<<" and string: "<<Y<<" is :"<<lcsLength(X, Y)<<endl;
        cout<<endl;
    }
};
