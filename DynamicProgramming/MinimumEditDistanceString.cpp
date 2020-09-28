//
//  MinimumEditDistanceString.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 24/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//


#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class MinimumEditDistanceString{
public:
    static int getMinEditDistanceBtwnStrings(string &str1, string &str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();
        
        //here dist[i][j] means no of operations required to convert string str1 till i and str2 till j equal
        vector<vector<int>> dist(len1+1);
        for(int i=0;i<dist.size();i++)
            dist[i]=vector<int>(len2+1);
        
        for(int i=0;i<dist.size();i++)
        {
            for(int j=0;j<dist[i].size();j++)
            {
                //if A's char is null
                if(i==0)
                    dist[i][j] = j;
                else if(j==0)
                    dist[i][j]=i;
                // 0 + remaining strings operations as both ths chars are same
                else if(str1[i-1] == str2[j-1])
                    dist[i][j] = 0 + dist[i-1][j-1];
                //if not same then min of all operations that we previously calculated withd delete replace and insert
                else
                    dist[i][j] = 1 + min(min(dist[i-1][j],dist[i][j-1]),dist[i-1][j-1] );
                
            }
        }
        
        int i = dist.size()-1;
        int j = dist[0].size()-1;
        
        while(i>0 && j>0)
        {
            
            if(str1[i-1]==str2[j-1])
            {
                i--;
                j--;
            }
            else if(dist[i][j] == 1 + dist[i-1][j-1])
            {
                
                    cout<<str1[i-1]<<" and "<<str2[j-1]<<" replaced"<<endl;
                j = j - 1;
                i=i-1;
            }
            else if(dist[i][j] == 1 + dist[i][j-1])
            {
                cout<<str1[i-1]<<" or "<<str2[j-1]<<" deleted"<<endl;
                j = j-1;
            }
           
        }
        
        return dist[len1][len2];
    }
    static void Test_MinimumEditDistanceString()
    {
        string str1 ="azced";
        string str2 = "abcdef";
        
        int editDistance = getMinEditDistanceBtwnStrings(str1,str2);
        cout<<"Minimum edit distance between both strings "<<str1 <<" and "<<str2<<" is "<<editDistance<<endl;
    }
};
