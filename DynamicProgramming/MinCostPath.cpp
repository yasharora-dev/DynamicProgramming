//
//  MinCostPath.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 22/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class MinCostPath{
    public:
    static int getMinCostPath_Rec(const vector<vector<int>> &cost,int row, int col)
    {
       /* if (n < 0 || m < 0)
            return INT_MAX;
        
        else if(n == 0 && m == 0)
            return cost[m][n];
        
        else
            return cost[m][n] + min(getMinCostPath_Rec(cost, m-1, n) , getMinCostPath_Rec(cost, m, n-1));
            */
        if(row >= cost.size() || col >= cost[0].size())
            return INT_MAX;
        else if(row==cost.size()-1 && col == cost[0].size()-1)
            return cost[row][col];
        
        else return cost[row][col] + min(getMinCostPath_Rec(cost, row+1, col), getMinCostPath_Rec(cost, row, col+1));
    }
    
    static void printMinCostPath(const vector<vector<int>> &minCost, const vector<vector<int>> &cost)
    {
        int rows = minCost.size();
        int cols = minCost[0].size();
        
        int row=rows-1,col=cols-1;
        
        while( (row>=0) && (col>=0))
        {
            cout<<cost[row][col]<<" ";
            if(row == 0)
                col = col-1;
            else if(col == 0)
                row = row-1;
            else if(minCost[row-1][col] < minCost[row][col-1])
                row=row-1;
            else
                col=col-1;
        }
        cout<<endl;
    }
    static int getMinCostPath(const vector<vector<int>> &cost){
        int rows = cost.size();
        int cols = cost[0].size();
        
        vector<vector<int>> minCost(rows);
        for(int i=0;i<minCost.size();i++)
        {
            minCost[i] = vector<int>(cols);
        }
        minCost[0][0]=cost[0][0];
        for(int i=1;i<rows;i++)
        {
            minCost[i][0] = cost[i][0]+minCost[i-1][0];
        }
        for(int col=1;col<cols;col++)
        {
            minCost[0][col] = cost[0][col]+minCost[0][col-1];
        }
        
        for(int row =1;row<rows;row++)
        {
            for(int col=1;col<cols;col++)
            {
                minCost[row][col]=cost[row][col]+min(minCost[row-1][col],minCost[row][col-1]);
            }
        }
        
        printMinCostPath(minCost,cost);
        return minCost[rows-1][cols-1];
    }
                       
    //a grid is given and you have to find out the min cost path to reach from [0][0] to [n][m]
    static void Test_MinCostPath()
    {
        vector<vector<int>> costMat { {1, 2, 3},
                                    {4, 8, 2},
                                    {1, 5, 3} };
        
        cout<<"=================== Min Cost Path in a matrix ===================="<<endl;
        
        cout<<"Input Matrix: "<<endl;
        
        for(int i=0;i<costMat.size();i++)
        {
            for(int j=0;j<costMat[i].size();j++)
                cout<<costMat[i][j]<<" ";
            cout<<endl;
        }
        
        cout<<"Min Cost Path total is: "<<getMinCostPath_Rec(costMat,0,0)<<endl;
        cout<<"Min Cost Path total is: "<<getMinCostPath(costMat)<<endl;
    }
};
