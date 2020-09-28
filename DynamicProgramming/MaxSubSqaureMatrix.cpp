//
//  MaxSubSqaureMatrix.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 22/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class MaxSubSqaureMatrix{
public:
    static int getMaxSubSqaureMatrixSize_Rec(vector<vector<int>> &matrix,int row,int col)
    {
        if(row < 0 || col <0)
            return INT_MAX;
        
        else if(row == 0 && col == 0)
            return matrix[row][col];
        
        else
        {
                return (matrix[row][col]?1:0) + min (min(getMaxSubSqaureMatrixSize_Rec(matrix, row-1, col),getMaxSubSqaureMatrixSize_Rec(matrix, row, col-1)),getMaxSubSqaureMatrixSize_Rec(matrix, row-1, col-1));
        
        }
        
    }
    static int getMaxSubSqaureMatrixSize(vector<vector<int>> &matrix)
    {
        //this copies the 0th row and col as its original value which is our base case
        vector<vector<int>> subSquares = matrix;
        int maxSize=0;
        for(int i=1;i<subSquares.size();i++)
        {
            for(int j=1;j<subSquares[0].size();j++)
            {
                if(matrix[i][j]==1)
                {
                    subSquares[i][j]= matrix[i][j] + min(min(subSquares[i-1][j],subSquares[i][j-1]),subSquares[i-1][j-1]);
                    maxSize = max(maxSize,subSquares[i][j]);
                }
            }
        }
        
        return maxSize;
    }
    
    //find the max sub square with 1
    // now a square can be made if all the 3 previous cells are 1
    // i.e. if i-1,j-1 i-1,j and i,j-1 are 1 then the current cell forms a aqaure of size 2*2
    //and if any one of it is 0 then 0
    //and if the current cell is 0 do nothing
    
    static void Test_MaxSubSqaureMatrix()
    {
        vector<vector<int>> matrix {{0, 1, 1, 0, 1},
                                    {1, 1, 0, 1, 0},
                                    {0, 1, 1, 1, 0},
                                    {1, 1, 1, 1, 0},
                                    {1, 1, 1, 1, 1},
                                    {0, 0, 0, 0, 0}};
        
        
        cout<<"=============== Maximum Sub Sqaure Matrix =================="<<endl;
        
        cout<<"Max Sub Square with give input is of size: "<< getMaxSubSqaureMatrixSize_Rec(matrix, matrix.size()-1, matrix[0].size()-1)<<endl;
        cout<<"Max Sub Square with give input is of size: "<< getMaxSubSqaureMatrixSize(matrix)<<endl;
        
    }
    
};
