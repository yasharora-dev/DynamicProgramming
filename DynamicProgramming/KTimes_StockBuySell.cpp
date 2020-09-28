//
//  KTimes_StockBuySell.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 20/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "KTimes_StockBuySell.hpp"

//=========================================================================================================
/* here the question is you have to find the max profit tht can be done, if you have the option to buy and sell stocks K at most k times
 now if this was to be done for k=1 time, then problem becomes find local minima and maxima at every point and at whatever day there maximum diff between local minima and maxima is the max profit that can be achived
 local minima is minimim at i from 0 to i and local maxima is maximum at i from i to end

 now here this approach cant wokr i.e. greedy solution doesnt work

 we have xexplore each and every option to get maximum profit so DP comes into picture

// now here the state is transaction i.e. k and day
// final state is when transaction becomes k DP[k][N]
// element of choice here at every point is
// 1. to not sell at that day i, i.e. DP[T][d-1] //by not selling at that day you will get max profit equal to last day's profit as nothing has changed
//2. sell at that particular day
// now to sell you need to buy it before the day d, so you have 0 to d-1 days options to buy the sell
// now we need to maximize the profit so from all the options you will have to chose the one which gives
//maximum profit
// if you sell at day d, price[d] - price[m] + DP[T][m]
//here if you sell at day d, sp you get price[d]-price[m] profit for the current transaction
// and also whatever max profit was there before in the earlier transaction so DP[t-1][m]
//t-1 denotes previous transaction's max profit
*/

//=========================================================================================================

//Time Complexity: O(n*k), Space: O(n*k)

int KTimes_StockBuySell::getMaxProfitTransactions(const vector<int> &stockPrices, int k)
{
    int len = stockPrices.size();
    int maxProfit =0;
    
    if(len < 2 || k < 1)
        return maxProfit;
    
    //DP table to store K+1 transactions as rows and stockPrices at ech day as columns of length len
    vector<vector<int>> profit(k+1);
    for(int i=0;i<profit.size();i++)
    {
        profit[i] =  vector<int> (len,0);
    }
    
    //for each transaction
    for(int t=1;t<profit.size();t++)
    {
        int maxdiff=INT_MIN;
        for(int d=1;d<len;d++)
        {
            int NotSell = profit[t][d-1];
            maxdiff = max(maxdiff, ((-1)*stockPrices[d-1]) + profit[t-1][d-1]);
            //this can be avoided as its recomputing the last d-2 computations again and again for every
            //day in every transaction
            
            /*for(int m=0;m<d;m++)
            {
                int mProfit = ((-1)*stockPrices[m]) + profit[t-1][m];
                MaxbuyDayPrice = max(MaxbuyDayPrice,mProfit);
            }*/

            profit[t][d] = max ( NotSell, stockPrices[d] + maxdiff);
            
        }
    }
    
    return profit[k][len-1];
}


//now above algo uses O(n*k) space to store the dp table
//if observed it becomes clear that we can only use the current row and previous row in reccurence formula
//so other rows are not required


int KTimes_StockBuySell::getMaxProfitTransactions_SpaceOpt(const vector<int> &stockPrices, int k)
{
    int len = stockPrices.size();
    int maxProfit =0;
    
    if(len < 2 || k < 1)
        return maxProfit;
    
    //DP table to store K+1 transactions as rows and stockPrices at ech day as columns of length len
   // vector<vector<int>> profit(k+1);
    
    //you need to store only two rows for recurence relation below
    vector<int> oddTransaction(len,0);
    vector<int> evenTransaction(len,0);
    
    vector<int> *current;
    vector<int> *previous;

    /*for(int i=0;i<profit.size();i++)
    {
        profit[i] =  vector<int> (len,0);
    }*/
    
    //for each transaction
    for(int t=1;t<k+1;t++)
    {
        
        int maxdiff=INT_MIN;
        if(t%2==0)
        {
            current = &evenTransaction;
            previous = &oddTransaction;
        }
        else
        {
            current = &oddTransaction;
            previous = &evenTransaction;
        }
        for(int d=1;d<len;d++)
        {
            
            //int NotSell = profit[t][d-1];
            int NotSell = (*current)[d-1];
            maxdiff = max(maxdiff, ((-1)*stockPrices[d-1]) + (*previous)[d-1]);
            //this can be avoided as its recomputing the last d-2 computations again and again for every
            //day in every transaction
            
            /*for(int m=0;m<d;m++)
            {
                int mProfit = ((-1)*stockPrices[m]) + profit[t-1][m];
                MaxbuyDayPrice = max(MaxbuyDayPrice,mProfit);
            }*/

            (*current)[d] = max ( NotSell, stockPrices[d] + maxdiff);
            
        }
        
        
    }
    
    return (k%2==0)?evenTransaction[len-1]:oddTransaction[len-1];
}
void KTimes_StockBuySell::Test_KTimes_StockBuySell()
{
    
    vector<int> Prices {5,11,3,50,60,90};
    int k =2;
    
    cout<<"::::::: Maximum profit that can be achived by atmost K Buy Sell Stock transactions ::::::::::"<<endl;
    
    cout<<"INPUT: "<<endl;
    cout<<"Prices: "<<endl;
    for(auto price: Prices)
        cout<<price<<" ";
    cout<<endl;
    cout<<"K Transactions: "<<k<<endl;
    
    cout<<"Output: "<<endl;
    //cout<<getMaxProfitTransactions(Prices, k)<<endl;
    cout<<getMaxProfitTransactions_SpaceOpt(Prices, k)<<endl;
    
}
