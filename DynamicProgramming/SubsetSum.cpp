//
//  SubsetSum.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 24/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//
/*
* Given an array of non negative numbers and a total, is there subset of numbers in this array which adds up
* to given total. Another variation is given an array is it possible to split it up into 2 equal
* sum partitions. Partition need not be equal sized. Just equal sum.
*
* Time complexity - O(input.size * total_sum)
* Space complexity - O(input.size*total_sum)
*
* Youtube video - https://youtu.be/s6FhG--P7z0
 
 */

#include <stdio.h>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class SubSetSum{
    
public:
    static bool isSubSetSumPresent(const vector<int> &nums, int total)
    {
        //create a 2d array of size n+1 * k+1 element
        vector<vector<bool>> DP(nums.size()+1);
        for(int i=0;i<DP.size();i++)
            DP[i]=vector<bool>(total+1);
        
        //base case 0th col and 0th row should be T
        for(int i=0;i<DP.size();i++)
        {
            for(int j=0;j<DP[i].size();j++)
            {
                //if total is 0 thn return true
                if(j==0)
                {
                    DP[i][j]=true;
                    continue;
                }
                //if array element is 0 and sum > 0 return false
                else if(i==0 && j>0)
                {
                    DP[0][j]=false;
                    continue;
                }
                //EOC: if the num is geater than j and if you select it
                // then return true if either of not including the element in subset i.e. previous row
                //or including the element and the rest of the number is true
                else if(j >= nums[i-1])
                {
                    DP[i][j]=(DP[i-1][j]||DP[i-1][j-nums[i-1]]);
                }
                //else use the previous result without including current element
                else
                    DP[i][j]=(DP[i-1][j]);
            }
        }
        
        int i=DP.size()-1;
        int j = total;
        
        while(i>0 && j>0 && DP[nums.size()][total])
        {
            if(DP[i][j]!=DP[i-1][j])
            {
                cout<<nums[i-1]<<" ";
                j = j - nums[i-1];
            }
             i = i -1;
        }
        
        
        
        return DP[nums.size()][total];
    }
    
    static void Test_isSubSetSumPresent()
    {
        //vector<int> nums {2,3,7,8,10};
        vector<int> nums {2,3,7,8,16,4};
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int total = 11;
        if(sum%2==0)
            total = sum/2;
        
        
        if(isSubSetSumPresent(nums,total))
        {
            cout<<"Subset sum of total "<<total<<" present in array"<<endl;
        }
        else
            cout<<"Subset sum of total "<<total<<" not present in array"<<endl;
    }
};
