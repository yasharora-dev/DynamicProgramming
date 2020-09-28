//
//  MaxRectangleInMatrix.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 25/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class MaxRectangleInMatrix{
    
public:
    //stack based algo to get max rectangle area in histogram
    //here consider the row as histogram and find max rectangle
    static int getMaxHistogramRectArea(vector<int> &hist)
    {
        stack<int> st;
        st.push(0);
        int index=1;
        int maxArea=0;
        while(index < hist.size() || !st.empty())
        {
            if(st.empty())
                st.push(index++);
            else if( index < hist.size() && (hist[index] >= hist[st.top()]) )
                st.push(index++);
            else
            {
                int top = st.top();
                int area;
                st.pop();
                //stack not empty
                if(!st.empty())
                {
                    area = hist[top] * (index - st.top() -1 );
                    
                }
                //stack empty
                else
                {
                    area = hist[top]*index; //smallest element i.e. last element to be popped from stack
                }
                maxArea = max(maxArea,area);
                
            }
        
        }
        
       
        return maxArea;
    }
    static int getMaxRectangleWithAllOnesInMatrix(vector<vector<int>> &mat)
    {
        vector<int> histogram(mat[0].size(),0);
        int maxRectSizeAll = 0;
        for(int row=0;row<mat.size();row++)
        {
            for(int col=0;col<mat[row].size();col++)
            {
                if(mat[row][col] == 0)
                    histogram[col]=0;
                else
                    histogram[col] += mat[row][col];
            }
            
            int maxRectSize = getMaxHistogramRectArea(histogram);
            maxRectSizeAll = max(maxRectSizeAll,maxRectSize);
        }
        
        return maxRectSizeAll;
    }
    
    static void Test_MaxRectangleInMatrix()
    {
        vector<vector<int>> mat {{1,0,0,1,1,1},
                                {1,0,1,1,0,1},
                                {0,1,1,1,1,1},
                                {0,0,1,1,1,1} };
        
        cout<<"Max Size Rectangle with All 1s in matrix is of size: "<<getMaxRectangleWithAllOnesInMatrix(mat)<<endl;
    }
};

