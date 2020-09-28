
//
//  CountOccurencesOfPatternInText.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 26/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
//here count num of times string Pattern exists in string Text
//EOC:
 1. either both chars not match: then recur for remaining text
 2. both match then recur for remaining text again as other occurence may also be there
 plus one char of pattern is found so now look for next i+1 th character with j+1 th character now
 
 recurence;
 if(pat[i-1]==text[i-1]) : DP[i][j] = DP[i-1][j-1] + DP[i-1][j]
 else DP[i][j] = DP[i-1][j]
 
*/
class CountOccurencesOfPatternInText{
public:
    
    static int countOccurencesOfPatternInText(string &text,string &pattern)
    {

        
        vector<vector<int>> OccTable(pattern.length()+1);
        for(int i=0;i<=pattern.length();i++)
            OccTable[i]=vector<int>(text.length()+1);
        
        //if Text is null/empty then no occurence is possible
        for(int i=0;i<OccTable.size();i++)
            OccTable[i][0]=0;
        
        //if pattern is null/empty then one occurence is possible
        for(int i=0;i<OccTable[0].size();i++)
            OccTable[0][i]=1;
        
        //and if both empty/null then also one occcurence is possible which is already 1 after above operation
        
        for(int pat=1;pat<OccTable.size();pat++)
        {
            for(int txt=1;txt<OccTable[pat].size();txt++)
            {
                if(pattern[pat-1] ==  text[txt-1])
                    OccTable[pat][txt] = OccTable[pat-1][txt-1] + OccTable[pat][txt-1];
                else
                    OccTable[pat][txt] = OccTable[pat][txt-1];
            }
        }
        
        
        
        return OccTable[pattern.length()][text.length()];
        
        
    }
    static void Test_CountOccurencesOfPatternInText()
    {
        string text="GeeksforGeeks";
        string pattern ="Gks";
        
        cout<<"Number of occurences of pattern: "<<pattern<<" in Text: "<<text<<" are: "<<countOccurencesOfPatternInText(text,pattern)<<endl;
    }
};
