#include "ArrayExercises.h"
#include <iostream>
/*
Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees (clockwise) Can you do this in place ?
Ref1: Cracking the Coding Interview 4edition (p48)
Ref2: https://leetcode.com/problems/rotate-image/
*/
//TODO: make in template: accept 1 or 3 channel matrix.
void ArrayExercises::RotateImage90(vector<vector<int>>& rMatrix)
{
    //assume that input matrix is always correct (NxN).
    //Otherwise, check for valid square matrix
    
    //theta clockwise = -90
    //H = offset = (N-1)/2 => shift index to the coordinate of the center
    //Transform the index of a entry in the matrix using rotation matrix;
    // | r_out | =  |cos(-90)    -sin(-90) | * | r_in - H | + | H |
    // | c_out |    |sin(-90)     cos(-90) |   | c_in - H |   | H |
    //           =  | 0   1 | * | r_in | + |-H | + | H | 
    //              | -1  0 |   | c_in |   | H |   | H |
    //           =  |  c_in          |
    //              |  -r_in + (N-1) |
    //lambda function for transform
    auto transform_func = [&](pair<int, int> in)
    {
        pair<int, int> out;
        //row:
        out.first = in.second;
        //col:
        out.second = -in.first + rMatrix.size()-1;
        return out;
    };

    int R_end, C_end;
    if (rMatrix.size() % 2 == 0)
    {
        R_end = rMatrix.size() / 2;
        C_end = R_end;
    }
    else
    {
        R_end = (rMatrix.size() - 1) / 2;
        C_end = R_end + 1;
    }

    int temp_in, temp_out;
    pair<int, int> p_in, p_out;

    for (int r = 0; r < R_end; r++)
    {
        for (int c = 0; c < C_end; c++)
        {
            //TL -> TR
            p_in = pair<int, int>(r, c);
            temp_in = rMatrix[p_in.first][p_in.second];
            //repeat 4 times: TL -> TR; TR -> BR; BR -> BL; BL -> TL
            for (int loop = 1; loop <= 4; loop++)
            {
                p_out = transform_func(p_in);
                temp_out = rMatrix[p_out.first][p_out.second];
                rMatrix[p_out.first][p_out.second] = temp_in;
                p_in = p_out;
                temp_in = temp_out;
            }
        }
    }
}

bool ArrayExercises::compare(const vector < vector<int>>& rMatrix1,
    const vector < vector<int>>& rMatrix2)
{
    //assume that input matrix is always correct (NxN).
    //Otherwise, check for valid square matrix
    for (int r = 0; r < rMatrix1.size(); r++)
    {
        for (int c = 0; c < rMatrix1.size(); c++)
        {
            if (rMatrix1[r][c] != rMatrix2[r][c])
            {
                return false;
            }
        }
    }
    return true;
}