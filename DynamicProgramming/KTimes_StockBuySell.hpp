//
//  KTimes_StockBuySell.hpp
//  DynamicProgramming
//
//  Created by Yash Arora on 20/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef KTimes_StockBuySell_hpp
#define KTimes_StockBuySell_hpp

#include <stdio.h>
#include <vector>

#include <iostream>

using namespace std;

class KTimes_StockBuySell{
  
public:
    static int getMaxProfitTransactions_SpaceOpt(const vector<int> &stockPrices, int k);
    static int getMaxProfitTransactions(const vector<int> &stockPrices, int k);
    static void Test_KTimes_StockBuySell();
};

#endif /* KTimes_StockBuySell_hpp */
