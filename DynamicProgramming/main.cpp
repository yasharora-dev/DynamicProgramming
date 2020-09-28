//
//  main.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 31/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//
#include "MinimumCoinChange.hpp"
#include "LongestCommonSubsequence.hpp"
#include "NStairsProblem.hpp"
#include "GoldRobberyProblem.hpp"
#include "EnjoyPartyProblem.hpp"
#include "Triangle.hpp"
#include "KTimes_StockBuySell.hpp"
#include "Knapsack01Prob.h"
#include "LCS.cpp"
#include "CoinChange.hpp"
#include "LIS.cpp"
#include "MinCostPath.cpp"
#include "MaxSubSqaureMatrix.cpp"
#include "LongestpalindromicSubsequence.cpp"
#include "BoxStackingProblem.cpp"
#include "SubsetSum.cpp"

#include "MinimumEditDistanceString.cpp"
#include "MaxSubSquareWithSidesX.cpp"
#include "MaxRectangleInMatrix.cpp"
#include "MaxSumRectangleInMatrix.cpp"
#include "MinJumpsToEndProb.cpp"
#include "OptimalGameStratery.cpp"
#include "CountOccurencesOfPatternInText.cpp"
#include <iostream>

#define ROW 4
#define COL 5

using namespace std;


void dfs(vector<vector<int> >& matrix,
         vector<vector<bool> >& visited,
         int x, int y, int n, int m)
{
    // If the land is already visited
    // or there is no land or the
    // coordinates gone out of matrix
    // break function as there
    // will be no islands
    if (x < 0 || y < 0 || x >= n || y >= m
        || visited[x][y] == true
        || matrix[x][y] == 0)
        return;
  
    // Mark land as visited
    visited[x][y] = true;
  
    // Traverse to all adjacent elements
    dfs(matrix, visited, x + 1, y, n, m);
    dfs(matrix, visited, x, y + 1, n, m);
    dfs(matrix, visited, x - 1, y, n, m);
    dfs(matrix, visited, x, y - 1, n, m);
}

    // Function that counts the closed island
    int countClosedIsland(vector<vector<int> >& matrix,
                          int n, int m)
    {
      
        // Create boolean 2D visited matrix
        // to keep track of visited cell
      
        // Initially all elements are
        // unvisited.
        vector<vector<bool> > visited(
            n, vector<bool>(m, false));
      
        // Mark visited all lands
        // that are reachable from edge
       /* for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
      
                // Traverse corners
                if ((i * j == 0
                     || i == n - 1
                     || j == m - 1)
                    and matrix[i][j] == 1
                    and visited[i][j] == false)
                    dfs(matrix, visited, i, j, n, m);
            }
        }*/
      
        // To stores number of closed islands
        int result = 0;
      
           for (int i = 0; i < n; ++i) {
         
               for (int j = 0; j < m; ++j) {
         
                   // If the land not visited
                   // then there will be atleast
                   // one closed island
                   if (visited[i][j] == false
                       and matrix[i][j] == 1) {
         
                       result++;
         
                       // Mark all lands associated
                       // with island visited.
                       dfs(matrix, visited, i, j, n, m);
                   }
               }
           }
         
           // Return the final count
           return result;
       }

// A function to check if a given
// cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col,
           bool visited[][COL])
{
    // row number is in range, column
    // number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}
  
// A utility function to do DFS for a
// 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(int M[][COL], int row, int col,
         bool visited[][COL])
{
    // These arrays are used to get
    // row and column numbers of 8
    // neighbours of a given cell
    static int rowNbr[] = { -1, 0, 1, 0 };
    static int colNbr[] = { 0, -1, 0, 1 };
  
    // Mark this cell as visited
    visited[row][col] = true;
  
    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
}
  
// The main function that returns
// count of islands in a given boolean
// 2D matrix
int countIslands(int M[][COL])
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
  
    // Initialize count as 0 and
    // travese through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
  
            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new island found
                // Visit all cells in this island.
                DFS(M, i, j, visited);
  
                // and increment island count
                ++count;
            }
  
    return count;
}



int main(int argc, const char * argv[]) {
    //MinimumCoinChange::Test_findMinCoins();
    //LCS::Test_findLCS();
    
    // Given size of Matrix
        int N = 5, M = 8;
      
        // Given Matrix
        /*vector<vector<int> > matrix
            = { { 0, 0, 0, 0, 0, 0, 0, 1 },
                { 0, 1, 1, 1, 1, 0, 0, 1 },
                { 0, 1, 0, 1, 0, 0, 0, 1 },
                { 0, 1, 1, 1, 1, 0, 1, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 1 } };*/
      
    vector<vector<int> > matrix = {  { 1, 1, 0, 0 },
                        { 0, 0, 1, 0 },
                        { 0, 0, 0, 0},
                        { 1, 0, 1, 1 },
                        { 1, 1, 1, 1 } };
    
        // Function Call
        cout << countClosedIsland(matrix, N, M)<<endl;
    
    
    int mat[][COL] = {  { 1, 1, 0, 0 },
                        { 0, 0, 1, 0 },
                        { 0, 0, 0, 0},
                        { 1, 0, 1, 1 },
                        { 1, 1, 1, 1 } };
    
    cout << countIslands(mat)<<endl;
        
    
    NStairsProblem::Test_countWaysToReachStairs();
    
    GoldRobberyProblem::Test_maxGoldRobbing();
    
    EnjoyPartyProblem::Test_getUniqueWaysToEnjoyParty();
    
    Triangle::Test_minimumTotal();
    
    KTimes_StockBuySell::Test_KTimes_StockBuySell();
    
    Knapsack01Prob::Test_getMaxValueKnapSack01();
    
    LCSLength::Test_LCS();
    
    Test_minNumberOfCoinsForChange();
    
    LIS::Test_LIS();
    
    MinCostPath::Test_MinCostPath();
    
    MaxSubSqaureMatrix::Test_MaxSubSqaureMatrix();
    
    LongestPalindromicSubsequence::Test_LongestPalindromicSubsequence();
    
    BoxStackingProblem::Test_BoxStackingProblem();
    
    SubSetSum::Test_isSubSetSumPresent();
    
    MinimumEditDistanceString::Test_MinimumEditDistanceString();
    
    MaxSubSquareWithSidesX::Test_MaxSubSquareWithSidesX();
    
    MaxRectangleInMatrix::Test_MaxRectangleInMatrix();
    
    MaxSumRectangleInMatrix::Test_MaxSumRectangleInMatrix();
    
    MinJumpsToEndProb::Test_MinJumpsToEndProb();
    
    OptimalGameStratery::Test_OptimalGameStratery();
    
    CountOccurencesOfPatternInText::Test_CountOccurencesOfPatternInText();
    return 0;
   
}
