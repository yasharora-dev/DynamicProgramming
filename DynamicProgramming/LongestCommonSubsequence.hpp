//
//  LongestCommonSubsequence.hpp
//  DynamicProgramming
//
//  Created by Yash Arora on 05/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef LongestCommonSubsequence_hpp
#define LongestCommonSubsequence_hpp

#include <stdio.h>
#include <string>

using namespace std;

class LCS{
public:
    static int findLCS_BTMUP(const string &in1,const string &in2,int len1,int len2);
    static int findLCS_DP_BTMUP(const string &in1,const string &in2,int len1,int len2);
    static int findLCS_TPDWN(const string &in1,const string &in2,int index1,int index2);
    static int findLCS_DP_TPDWN(const string &in1,const string &in2,int index1,int index2);
    static void Test_findLCS();
};
#endif /* LongestCommonSubsequence_hpp */
