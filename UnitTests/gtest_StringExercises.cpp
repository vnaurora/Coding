#include "gtest/gtest.h"
#include "StringExercises.h"
#include <math.h>

TEST(StringExercises_test, NormalString)
{
    EXPECT_TRUE(StringExercises::IsUniqueChar("abcd"));
    EXPECT_FALSE(StringExercises::IsUniqueChar("abbcd"));
    EXPECT_TRUE(MyTestFunc());
}

TEST(Addition, CanAddTwoNumbers)
{
    EXPECT_TRUE((2+2) == 4);
}