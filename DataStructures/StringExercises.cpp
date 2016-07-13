// Example program
#include <iostream>
#include <string>
#include <algorithm>

#include "StringExercises.h"

bool MyTestFunc()
{
    return true;
}

bool StringExercises::IsUniqueChar(const std::string& str)
{
    if (str.size() == 0) //check for empty string
    {
        return true;
    }
    const int max_elem_num = 256;
    unsigned char counter[max_elem_num];
    memset(counter, 0, sizeof(unsigned char) * max_elem_num);
    for (auto c : str)
    {
        counter[c]++;
    }
    for (auto i = 0; i < max_elem_num; i++)
    {
        if (counter[i] > 1)
        {
            return false;
        }
    }

    return true;
}
//
//void run_IsUniqueChar()
//{
//    std::string s;
//    while (1)
//    {
//        std::cout << "Input a string? ";
//        getline(std::cin, s);
//        if (StringExercises::IsUniqueChar(s))
//        {
//            std::cout << "Unique!" << std::endl;
//        }
//        else
//        {
//            std::cout << "Duplicated!" << std::endl;
//        }
//        std::cin.get();
//    }
//
//}

//==============================================
bool CheckAnagram(const std::string& str1, const std::string& str2)
{
    std::string s1 = str1;
    std::string s2 = str2;
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1 == s2;
}





