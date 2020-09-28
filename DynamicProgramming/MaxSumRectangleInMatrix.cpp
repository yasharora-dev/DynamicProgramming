//
//  MaxSumRectangleInMatrix.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 25/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//
/*
 
 https://www.youtube.com/watch?v=yCQN096CwWM
 
 Time: O(n^3) and space O(n)
 */
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class MaxSumRectangleInMatrix{
public:
    
    //kadane's algo to find Max sum sub sequence from array
    //algo: if there are atlst one positive number in the array then keep on adding elements
    //and whenever the sum becomes less than zero reset the sum to zero
    //kep MSS and keep on updating it whenever the sum increases
    static int getMaxSumSubSequence(vector<int> &arr,int &MSS_st,int &MSS_end)
    {
        int MSS=0;
        int sum=0;
        MSS_st=0;
        for(int i=0;i<arr.size();i++)
        {
            if(sum+arr[i]>0)
            {
                sum+=arr[i];
            }
            else
            {
                sum=0;
                MSS_st=i+1;
            }
            if(sum>MSS)
            {
                MSS=sum;
                MSS_end=i;
            }
            
        }
        return MSS;
    }
    
    //here we need to traverse all the cols one by one vertically from i=0 and j=i+1 in n^2 times
    //to check out all possible combinations
    //now for each L column keep on adding R and using kadane's find MSS for each column
    //keep on storing maxleft maxright maxup(MSS_st) maxdown(MSS_end) and maxSum for every column whenever you see new greater sum by adding any new column
    
    static int getMaxSumRectangleInMatrix(vector<vector<int>> &mat)
    {
        //store column wise/vertical sum one by one for every column for every combination i.e. n^2 times
        //same as row size
        vector<int> sum(mat.size(),0);
        int result=0;
        int maxLeft=-1;
        int maxRight=-1;
        int maxUp=-1;
        int maxDown=-1;
        
        for(int L=0;L<mat[0].size();L++)
        {
            for(int i=0;i<mat.size();i++)
                sum[i]=mat[i][L];
            int local_sum=0;
            for(int R=L+1;R<mat[0].size();R++)
            {
                //now for each row add it in sum and then find max sum sub array using kadane's algo
                for(int i=0;i<mat.size();i++)
                    sum[i]+=mat[i][R];
                int MSS_st=-1;
                int MSS_end=-1;
                local_sum = getMaxSumSubSequence(sum,MSS_st,MSS_end);
                
                if(local_sum > result)
                {
                    result = local_sum;
                    maxLeft =L;
                    maxRight = R;
                    maxUp=MSS_st;
                    maxDown=MSS_end;
                }
            }
        }
        
        return result;
        
        
    }
    static void Test_MaxSumRectangleInMatrix()
    {
        vector<vector<int>> mat{{2,1,-3,-4,5},
                             {0,6,3,4,1},
                            {2,-2,-1,4,-5},
                            {-3,3,1,0,3}};
        
        cout<<"Max Sum Rectangle in Matrix is: "<<getMaxSumRectangleInMatrix(mat)<<endl;
    }
};


