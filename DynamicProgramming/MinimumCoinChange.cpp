//
//  MinimumCoinChange.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 31/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "MinimumCoinChange.hpp"
#include <queue>
#include <iostream>



int MinimumCoinChange::findMinCoins_Rec(vector<int> coins,int val)
{
    //base case
    if(val == 0) return 0;
    int minAtCurrentLevel = INT_MAX;
    
    for(int i=0;i<coins.size();i++)
    {
        if(val - coins[i] >= 0)
        {
            int res = 1 + findMinCoins_Rec(coins,val-coins[i]);
            if(res != INT_MAX && res  < minAtCurrentLevel)
                minAtCurrentLevel = res;
        }
    }
    return minAtCurrentLevel;
}


int MinimumCoinChange::findMinCoins_DP(vector<int> coins,int val)
{
        //base case
       if(val == 0) return 0;
       int minAtCurrentLevel = INT_MAX;
        vector<int> DP(val+1,-1);
        DP[0]=0;
       for(int i=0;i<coins.size();i++)
       {
           if(val - coins[i] >= 0)
           {
               int res = 0;
               
               if(DP[val - coins[i]]!=-1)
               {
                   res = DP[val - coins[i]];
               }
               else
               {
                   res = 1 + findMinCoins_Rec(coins,val-coins[i]);
                   if(res != INT_MAX && res  < minAtCurrentLevel)
                       minAtCurrentLevel = res;
               }
           }
       }
    DP[val]=minAtCurrentLevel;
       return minAtCurrentLevel;
}

int MinimumCoinChange::findMinCoins_BFS(vector<int> coins,int val)
{
    queue<int> bfs;
    bfs.push(val);
    int depth = 0;
    
    vector<bool> visited(val+1,false);
    
    while(!bfs.empty())
    {
        
        int numOfNodes = bfs.size();
        while(numOfNodes > 0)
        {
            numOfNodes--;
            int rem_val = bfs.front();
            if(rem_val==0)
                return depth;
            bfs.pop();
            
            if(rem_val > 0 && !visited[rem_val] )
            {
                visited[rem_val]=true;
                for(int i=0;i<coins.size();i++)
                    bfs.push(rem_val-coins[i]);
            }
            
        
        }
        depth++;
    }
    
    return -1;
}

void MinimumCoinChange::Test_findMinCoins()
{
    vector<int> coins {1,5,7};
    int val =18;
    
    cout<<"Min Coins required for change "<< val<<" : "<<findMinCoins_Rec(coins, val)<<endl;
    cout<<"Min Coins required for change "<< val<<" : "<<findMinCoins_DP(coins, val)<<endl;
    cout<<"Min Coins required for change "<< val<<" : "<<findMinCoins_BFS(coins, val)<<endl;
    
    
}
