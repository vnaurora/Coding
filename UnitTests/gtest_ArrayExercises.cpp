#include "gtest/gtest.h"
#include "ArrayExercises.h"
#include <math.h>

using namespace std;

/* ======= RotateImage90 ============*/
TEST(RotateImage90_test, Simple22Case)
{
    vector<vector<int>> mat_in{ { 1, 2 }, 
                                { 3, 4 } };
    vector<vector<int>> result{ { 3, 1 }, 
                                { 4, 2 } };
    
    vector<vector<int>> mat_out = mat_in;
    ArrayExercises::RotateImage90(mat_out);

    EXPECT_TRUE(ArrayExercises::compare(mat_out, result));
}

TEST(RotateImage90_test, Simple33Case)
{
    vector<vector<int>> mat_in{ { 1, 2, 3 },
                                { 4, 5, 6 },
                                { 7, 8, 9 } };
    vector<vector<int>> result{ { 7, 4, 1 },
                                { 8, 5, 2 },
                                { 9, 6, 3 } };

    vector<vector<int>> mat_out = mat_in;
    ArrayExercises::RotateImage90(mat_out);
    EXPECT_TRUE(ArrayExercises::compare(mat_out, result));
}
TEST(RotateImage90_test, Simple44Case)
{
    vector<vector<int>> mat_in{ {  1,  2,  3,  4 },
                                {  5,  6,  7,  8 },
                                {  9, 10, 11, 12 },
                                { 13, 14, 15, 16 } };
    vector<vector<int>> result{ { 13,  9, 5, 1 },
                                { 14, 10, 6, 2 },
                                { 15, 11, 7, 3 },
                                { 16, 12, 8, 4 } };

    vector<vector<int>> mat_out = mat_in;
    ArrayExercises::RotateImage90(mat_out);
    EXPECT_TRUE(ArrayExercises::compare(mat_out, result));
}

TEST(RotateImage90_test, Simple55Case)
{
    vector<vector<int>> mat_in{ {  1,  2,  3,  4,  5 },
                                {  6,  7,  8,  9, 10 },
                                { 11, 12, 13, 14, 15 },
                                { 16, 17, 18, 19, 20 },
                                { 21, 22, 23, 24, 25 } };
    vector<vector<int>> result{ { 21, 16, 11, 6, 1 },
    { 22, 17, 12, 7, 2 },
    { 23, 18, 13, 8, 3 },
    { 24, 19, 14, 9, 4 },
    { 25, 20, 15, 10, 5 } };

    vector<vector<int>> mat_out = mat_in;
    ArrayExercises::RotateImage90(mat_out);
    EXPECT_TRUE(ArrayExercises::compare(mat_out, result));
}

/* ======= SetZeroes ============*/

TEST(SetZeroes_test, Simple55Case)
{
    vector<vector<int>> mat_in{ {  0,  2,  3,  4,  5 },
                                {  6,  7,  8,  9, 10 },
                                { 11, 12, 13, 14, 15 },
                                { 16, 17, 18,  0, 20 },
                                { 21, 22, 23, 24, 25 } };

    vector<vector<int>> result{ { 0,  0,  0,  0,  0 },
                                { 0,  7,  8,  0, 10 },
                                { 0, 12, 13,  0, 15 },
                                { 0,  0,  0,  0,  0 },
                                { 0, 22, 23,  0, 25 } };
    vector<vector<int>> mat_out = mat_in;
    ArrayExercises::SetZeroes(mat_out);
    EXPECT_TRUE(ArrayExercises::compare(mat_out, result));
}