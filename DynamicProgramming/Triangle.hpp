//
//  Triangle.hpp
//  DynamicProgramming
//
//  Created by Yash Arora on 18/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
class Triangle {
public:
    static int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        //int cols = triangle[].size();
        
        vector<int> DP[rows];
    
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                DP[i].push_back(-1);
            }
        }
    
        
        DP[0][0] = triangle[0][0];
        DP[1][0] = triangle[0][0]+triangle[1][0];
        DP[1][1] = triangle[0][0]+triangle[1][1];
        
        for(int i=2;i<rows;i++)
        {
            int colsz = triangle[i].size();
            for(int j=0;j<colsz;j++)
            {
                if(j==0)
                {
                    DP[i][j]= triangle[i][j]+DP[i-1][j];
                }
                else if(j==colsz-1)
                {
                    DP[i][j] = triangle[i][j] + DP[i-1][j-1];
                }
                else if(j==colsz-2)
                {
                    DP[i][j] = min(triangle[i][j] + DP[i-1][j-1] , triangle[i][j] + DP[i-1][j]) ;
                }
                else
                {
                    DP[i][j] = min( min(triangle[i][j] + DP[i-1][j-1] , triangle[i][j] + DP[i-1][j]),
                                  triangle[i][j] + DP[i-1][j+1] );
                }
                
            }
        }
        
        int minSum = *min_element(DP[rows-1].begin(),DP[rows-1].end());
        return minSum;
    }
    
    
    static void Test_minimumTotal()
    {
        vector<vector<int>> triangle { {2},{3,4},{6,5,7},{4,1,8,3}};
        
        cout<<endl<<endl<<"ans:::::" <<minimumTotal(triangle)<<endl;
    }
};
#endif /* Triangle_hpp */
