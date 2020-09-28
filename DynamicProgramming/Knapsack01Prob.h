//
//  Knapsack01Prob.h
//  DynamicProgramming
//
//  Created by Yash Arora on 20/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef Knapsack01Prob_h
#define Knapsack01Prob_h

#include <iostream>
#include <vector>

using namespace std;

class Knapsack01Prob{
public:
    static int getMaxValueKnapSack01(const vector<int> &weight, const vector<int> &value, int Wmax)
    {
        int len = weight.size();
        
        //rows = items (val and weight)
        //cols = 0 to Wmax i.e. available weight
        /*vector<vector<int>> profit(len+1);
        for(int items=0;items<=profit.size();items++)
        {
            profit[items] = vector<int>(Wmax+1,0);
        }*/
        
        int profit[len+1][Wmax+1];
        
        for(int i=0;i<=len;i++)
            for(int j=0;j<=Wmax;j++)
                profit[i][j]=0;
        
        
        for(int item =1;item<=len;item++)
        {
            for(int wt =1;wt<=Wmax;wt++)
            {
                
                if(wt < weight[item-1])
                {
                    profit[item][wt] = profit[item-1][wt];
                }
                else {
                    //max of not selecting the item or selecting the item
                    //selecting item means value of that item plus the max value of previous item with weight subtratacted from current weight
                    //item-1 as any item can be selected at most once
                    //wt-weight[item] = max value with remaining weight, as weight[i] is selected so the rem value max needs to found
                    profit[item][wt] = max(profit[item-1][wt], value[item-1] + profit[item-1][wt-weight[item-1]] );
                }
            }
        }


        return profit[len][Wmax];
        
    }
    static void Test_getMaxValueKnapSack01()
    {
        vector<int> weight {1,3,4,5};
        vector<int> value {1,4,5,7};
        int Wmax = 7;
        cout<<"Max value that can be fitted in knapsack of weight: "<<Wmax<<" : "<<getMaxValueKnapSack01(weight,value,Wmax);
    }

};
#endif /* Knapsack01Prob_h */
