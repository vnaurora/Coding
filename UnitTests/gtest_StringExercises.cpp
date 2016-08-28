#include "gtest/gtest.h"
#include "StringExercises.h"
#include <math.h>

/* ======= IsUniqueChar ============*/
TEST(IsUniqueChar_test, SimpleCase)
{
    EXPECT_TRUE(StringExercises::IsUniqueChar("abcd"));
    EXPECT_FALSE(StringExercises::IsUniqueChar("abbcd"));
}

/* ======= constructRansomNote ============*/
TEST(constructRansomNote_test, SimpleCase)
{
    EXPECT_FALSE(StringExercises::constructRansomNote("a", "b"));
    EXPECT_TRUE(StringExercises::constructRansomNote("aa", "aab"));
    EXPECT_TRUE(StringExercises::constructRansomNote("ab", "ba"));
}

TEST(constructRansomNote_test, EmptyCase)
{
    EXPECT_TRUE(StringExercises::constructRansomNote("", ""));
}
/* ======= ReplaceSpace ============*/
TEST(ReplaceSpace_test, SimpleString)
{
    std::string sin = "I have a dream.";
    std::string sout;
    StringExercises::ReplaceSpace(sin, sout);
    EXPECT_EQ(sout, "I%20have%20a%20dream.");
}
TEST(ReplaceSpace_test, EmptyString)
{
    std::string sin = "";
    std::string sout;
    StringExercises::ReplaceSpace(sin, sout);
    EXPECT_EQ(sout, "");
}

TEST(ReplaceSpace_test, EndWithSpace)
{
    std::string sin = "AAA ";
    std::string sout;
    StringExercises::ReplaceSpace(sin, sout);
    EXPECT_EQ(sout, "AAA%20");
}

TEST(ReplaceSpace_test, MultiContSpace)
{
    std::string sin = "A   ";
    std::string sout;
    StringExercises::ReplaceSpace(sin, sout);
    EXPECT_EQ(sout, "A%20%20%20");
}

TEST(ReplaceSpace_test, AllSpace)
{
    std::string sin = "   ";
    std::string sout;
    StringExercises::ReplaceSpace(sin, sout);
    EXPECT_EQ(sout, "%20%20%20");
}
TEST(Addition, CanAddTwoNumbers)
{
    EXPECT_TRUE((2+2) == 4);
}