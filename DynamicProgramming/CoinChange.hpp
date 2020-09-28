//
//  CoinChange.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 21/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  // Write your code here.
    if(denoms.size()<1)
        return -1;
    
    vector<int> Change(n+1,INT_MAX);
    Change[0]=0;
    
    for(int coins=0;coins<denoms.size();coins++)
    {
        for(int amount=1;amount<=n;amount++)
        {
            if(amount >= denoms[coins])
            {
                if(Change[amount - denoms[coins]]!=INT_MAX)
                    Change[amount] = min( Change[amount],(1 + Change[amount-denoms[coins]]) );
                else
                    Change[amount] = INT_MAX;
            }
        }
    }
    
  return Change[n]!=INT_MAX?Change[n]:-1;
}


void Test_minNumberOfCoinsForChange()
{
    vector<int> denoms{3,4,5};
    int change =9;
    
    cout<<"============ Coin Change Problem =================="<<endl;
    cout<<"Input"<<endl;
    for(auto x:denoms)
        cout<<x<<" ";
    cout<<endl;
    cout<< "change required: "<<change<<endl;
    
    cout<<"Output: "<<endl;
    cout<<"Min no of coins required are: "<<minNumberOfCoinsForChange(change, denoms);
}

