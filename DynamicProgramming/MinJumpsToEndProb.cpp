//
//  MinJumpsToEndProb.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 25/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//


#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class MinJumpsToEndProb{
    public:
    static int getMinNumJumpsToEnd(const vector<int> &arr)
    {
        //two dp arrays
        //1 to store jumps
        //2 to store path of jumps
        
        vector<int> jumps(arr.size(),INT_MAX);
        vector<int> path(arr.size());
        
        jumps[0]=0;
        for(int i=1;i<arr.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                //it can reach i or not
                if(arr[j]+j>=i)
                {
                    if(jumps[j]+1 < jumps[i])
                    {
                        jumps[i]=jumps[j]+1;
                        path[i]=j;
                    }
                }
            }
        }
        
        int i=arr.size()-1;
        while(i>0)
        {
            cout<<path[i]<<" - ";
            i=path[i];
        }
        cout<<endl;
        return jumps[arr.size()-1];
    }
    static void Test_MinJumpsToEndProb()
    {
        vector<int> jumps{2,3,1,1,2,4,2,0,1,1};
        
        int minJumps = getMinNumJumpsToEnd(jumps);
        cout<<"Min number of jmps to reach end :"<<minJumps<<endl;
    }
};
