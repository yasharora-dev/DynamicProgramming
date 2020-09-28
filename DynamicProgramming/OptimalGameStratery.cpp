//
//  OptimalGameStratery.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 26/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//https://www.youtube.com/watch?v=WxpIHvsu1RI&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=25


#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class OptimalGameStratery{
public:
    static int getMaxGoldPots(vector<int> &pots)
    {
        int len = pots.size();
        
        //player1 and player2 turns each pair represents
        //first = player1 picks profit
        //second = player2 picks profit
        vector<vector<pair<int,int>>> moves(len);
        for(int i=0;i<moves.size();i++)
            moves[i]=vector<pair<int,int>>(len);
        
        //for len=1 i.e. for ith single pot max
        for(int i=0;i<len;i++)
            moves[i][i]=make_pair(pots[i],0);
        
        for(int l=2;l<=len;l++)
        {
            for(int i=0;i<=len-l;i++)
            {
                for(int j=i+l-1;j<len;j++)
                {
                    //i denotes one end i.e. left end
                    //j denotes right end
                    //you need to select max of both considering remaining values also
                    //i.e. if you pick gold[i] then you need to consider what happens after players 2 turns
                    //and consider that whole to take a decision to chose i or j
                    int leftGold = pots[i]+ moves[i+1][j].second;
                    int rightGold = pots[j] +  moves[i][j-1].second;
                    
                    if(leftGold>rightGold)
                    {
                        //picked i
                        //so here pots[i] i.e. val at i + whatever is remaining after second player's turn
                        //for e.g. l=2, 1..3, if i pick 1 then player2 will pickup max from moves[2][3]
                        //and moves[2][3].second denotes whaever is remaining after player2 has picked
                        moves[i][j].first=pots[i]+ moves[i+1][j].second;
                        //here player2 will get whatever value that was remaining without pots[i]
                        //so player2 will get a chance
                        //for e.g. l=2, 1..3, if 1 has been picked by player1
                        //then for player2, moves[2][3].first determines the max/best possible value that player2 can pick
                        moves[i][j].second = moves[i+1][j].first;
                    }
                    else
                    {
                        moves[i][j].first = pots[j] +  moves[i][j-1].second;
                        moves[i][j].second = moves[i][j-1].first;
                    }
                    
                    
                }
            }
        }
        
        
            
        return moves[0][len-1].first;
    }
    static void Test_OptimalGameStratery(){
        //vector<int> pots = {3,1,5,6,2,9,3};
        vector<int> pots = {3,9,1,2};
        
        cout<<"Max gold that can be achoved by selecting first move is: "<<getMaxGoldPots(pots)<<endl;
    }
};
