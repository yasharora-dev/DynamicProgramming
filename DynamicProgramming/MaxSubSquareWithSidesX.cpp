//
//  MaxSubSquareWithSidesX.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 25/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//


/*
 https://www.youtube.com/watch?v=vi_1eHCsR9A&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=41
 
 find maximum subbqaure with all X in its sides..other cells dont matter inside the square
 1. now divide the question into two parts
 1.1 first we have to find all the sub square of size>=2
 and 1.2 then count the size and find max subsquare
 
 now to find the subsqaure i.e. whose all sides are equal
 we need to find the rightmost bottommost cell (i,j) of a square and
 1. if there is some side lets of size m with all X'es along its path i.e. from i,j to i,j-m all cells are X
 2. also from i,j-m there are m cells above it whose cells are also X
 3. and now from i,j also if there are m X cells above it, i,j to i-m,j all cells are X'es
 4. and last from i-m,j to i-m,j-m all cells are X'es
 if all 4 are true then we have a found a subsquare of size m
 
 now to do this in brute force is very time expensive to check for every m cells in 4 directions whiil give 4^n complexity
 
 
 so use DP to store the results of every cell the count of vertical(continous X'es above the cell including itself) and horizontal(contiguos X'es on left of X including X)
 
 storing these in matrix of same size of original matrix we can use the above 4 steps to find the subswaure and also max subsquare
 
 */
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class MaxSubSquareWithSidesX{
public:
    static void Test_MaxSubSquareWithSidesX()
    {
        vector<vector<char>> mat   {{'0','0','0','0','X', '0'},
                                    {'X','0','X','X','X','X'},
                                    {'X','0','X','0','X','X'},
                                    {'X','X','X','X','X','X'},
                                    {'0','0','X','X','X','X'}};
        
        char x ='X';
        cout<<"Max SubSwqaure with sides X: "<<getMaxSubSquareWithSidesX(mat, x)<<endl;
    }
    static int getMaxSubSquareWithSidesX(vector<vector<char>> &mat, char X)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        
        //pair of count of vertical & horizontal contigous X'es including current cell
        vector<vector<pair<int,int>>> subSq(rows);
        for(int i=0;i<rows;i++)
            subSq[i]=vector<pair<int, int>>(cols);
        
        subSq[0][0]= mat[0][0]=='X'?make_pair(1, 1):make_pair(0, 0);
        for(int i=1;i<rows;i++)
        {
            subSq[i][0] = mat[i][0]=='X'?make_pair(1 + subSq[i-1][0].first, 1) :make_pair(0, 0);
        }
        for(int j=1;j<cols;j++)
        {
            subSq[0][j] = mat[0][j]=='X'?make_pair(1, 1 + subSq[0][j].second) :make_pair(0, 0);
        }
        
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(mat[i][j]=='X')
                {
                    subSq[i][j] = make_pair(1+subSq[i-1][j].first, 1 + subSq[i][j-1].second);
                }
            }
        }
        
        
        int i = rows-1;
        int j = cols-1;
        
        int maxSize=0;
        while(i>=0 && j>=0)
        {
            //min bcz the square possible will be of min size out of two as square requires both sides to be equal, so the possible subsquare will be of size min(vertical,horixontal)
            int size = min(subSq[i][j].first,subSq[i][j].second);
            
            for(int m=size;m>=2;m--)
            {
                //find left side cell
                //find upper cell of size m
                //and if both have vertical and horizontal as size then it is forming a square
                int leftRow = i;
                int leftCol = (j - m)+1;
                int upRow = (i-m)+1;
                int upCol = j;
                
                if( m > maxSize && leftRow >=0 && leftCol>=0 && upCol>=0 && upRow>=0 && (subSq[leftRow][leftCol].first) >= m && (subSq[upRow][upCol].second >= m) )
                    maxSize = max(maxSize,m);
                    
            }
            if(j<=0)
            {
                i--;
                j=cols-1;
            }
            else
            {
                j--;
            }
                
        }
        
        
        
        return maxSize;
    }
};
