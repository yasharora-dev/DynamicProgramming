//
//  BoxStackingProblem.cpp
//  DynamicProgramming
//
//  Created by Yash Arora on 23/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//


#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

// Data structure to store a box (L x W x H)
struct Box {
    // enforce constraint: width is never more than length
    int length, width, height;
};

class BoxStackingProblem{
public:
    

     
    // Function to generate rotations of all the boxes
    static vector<Box> createAllRotations(const vector<Box> &boxes)
    {
        // stores all rotations of each box
        vector<Box> rotations;
     
        // do for each box
        for (const Box &box: boxes)
        {
            // push the original box: {L x W x H}
            rotations.push_back(box);
     
            // push the first rotation: {max(L, H) x min(L, H) x W}
            rotations.push_back({ max(box.length, box.height),
                            min(box.length, box.height),
                            box.width });
     
            // push the second rotation: {max(W, H) x min(W, H) x L}
            rotations.push_back({ max(box.width, box.height),
                            min(box.width, box.height),
                            box.length });
        }
     
        return rotations;
    }
        
    bool comp(const Box &b1,const Box &b2)
    {
        //decreasing order
        return ((b1.length * b2.width) >= (b2.length * b2.width));
    }
    static int getMaxBoxStackHeight(vector<Box> &boxes)
    {
        vector<Box> rotations = createAllRotations(boxes);
        //decreasing order
        // sort the boxes in descending order of base area(L x W)
        /*sort(rotations.begin(),
            rotations.end(),
            [](const Box &x, const Box &y) {
                return x.length * x.width > y.length * y.width;
            });*/
        
            sort(rotations.begin(),
               rotations.end(),
               [](const Box &x, const Box &y) {
                   return x.length * x.width > y.length * y.width;
               });
        
        
        vector<int> maxHeight(rotations.size());
        vector<int> order(rotations.size());
        
        //base case ech box is atleast of its own height
        for(int i=0;i<maxHeight.size();i++)
            maxHeight[i]=rotations[i].height;
        
        for(int i=0;i<order.size();i++)
            order[i]=i;
        
        for(int i=0;i<rotations.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if (rotations[i].length < rotations[j].length &&
                        rotations[i].width < rotations[j].width) {
                    maxHeight[i] = max(maxHeight[i], maxHeight[j]);
                }
            }
            maxHeight[i] += rotations[i].height;
        }
        
        return *max_element(maxHeight.begin(), maxHeight.end());
    }
    static void Test_BoxStackingProblem()
    {
        vector<Box> boxes {
            { 4, 2, 5 },
            { 3, 1, 6 },
            { 3, 2, 1 },
            { 6, 3, 8 }
        };
        cout<<"Max Height can be achived by stacking is: "<<getMaxBoxStackHeight(boxes)<<endl;
    }
};
