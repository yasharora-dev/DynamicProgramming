//
//  LIS.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 22/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>


// Longest increasing subsequence is find the longest striclty increasing sequence which need not to be contigous
// 3 4 -1 0 6 2 3
//ans: -1 0 2 3 so return 4
// take 1 d dp arary to store the LIS at i
// LIS[i] : longest increasing subquence from 0 to i
// E.O.C: either include the element in the LIS or not
// if not included then
//LIS at i { max { LIS[j] : if nums[j] < nums[i]} + 1
//else 1 because every number is atlst 1 length LIS in itself

//e.g.
// 3 4 -1 0 6 2 3
// 1 1  1 1 1 1 1
//
using namespace std;

class LIS{
    
public:
    static int getLISLength(vector<int> &nums)
    {
        int n = nums.size();
        
        vector<int> LIS(n,1);
        int result=1;
        for(int i=1;i<LIS.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    LIS[i]=max(LIS[i],1+LIS[j]);
                }
            }
                
            
        result= max(result,LIS[i]);
        }
        
        return result;
    }
    
    static void getLIS(vector<int> &nums)
    {
        int n = nums.size();
        
        vector<vector<int>> LIS(n);
        
        LIS[0].push_back(nums[0]);
        
        int result=1;
        for(int i=1;i<LIS.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && LIS[i].size() < LIS[j].size()+1)
                {
                    //LIS[i]=max(LIS[i],1+LIS[j]);
                    LIS[i]=LIS[j];
                }
            }
                
            LIS[i].push_back(nums[i]);
        //result= max(result,LIS[i]);
        }
         vector<int> max = LIS[0];
        
          // LIS will be max of all increasing sub-
          // sequences of arr
          for (vector<int> x : LIS)
              if (x.size() > max.size())
                  max = x;
        
        for (auto x : max)
            cout<<x<<" ";
        cout<<endl;
        

    }
    
    static void Test_LIS()
    {
        cout<<"=============== LIS: Longest Increasing Subsequence ======================"<<endl;
        
        vector<int> nums {3,4,-1,0,6,2,3};
        cout<<"Input: "<<endl;
        for(int num: nums)
            cout<<num<<" ";
        cout<<endl;
        
        cout<<"LIS of above input is of length: "<<getLISLength(nums)<<endl;
        
        cout<<"LIS of above input is : "<<endl;
        getLIS(nums);
    }
};
