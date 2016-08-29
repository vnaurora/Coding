/**
* @file ArrayExercises.h
*
* Copyright (c) 2016 NHQ.
*
* @brief
*   Array exercise implementation
*/
#ifndef ARRAY_EXERCISES_H
#define ARRAY_EXERCISES_H

#include <utility>
#include <vector>
#include <algorithm>
using namespace std;


class ArrayExercises
{
public:
    //struct rgba_t
    //{
    //    unsigned char r;
    //    unsigned char g;
    //    unsigned char b;
    //    unsigned char a;
    //};
    typedef std::pair<int, int> Point2i;
    static void RotateImage90(vector < vector<int>>& rMatrix);

    //helper function:
    static bool compare(const vector < vector<int>>& rMatrix1,
                        const vector < vector<int>>& rMatrix2);

};

#endif ARRAY_EXERCISES_H