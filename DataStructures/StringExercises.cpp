// Example program
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "StringExercises.h"
#include <unordered_map>

bool StringExercises::IsUniqueChar(const string& str)
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

/* 
* Ransom Note
* https://leetcode.com/problems/ransom-note/
* Given an arbitrary ransom note string and another string containing letters 
* from all the magazines, write a function that will return true if the ransom  
* note can be constructed from the magazines ; otherwise, it will return false. 
* Each letter in the magazine string can only be used once in your ransom note.
* Return: true if can construct. Otherwise, false.
*/

bool StringExercises::constructRansomNote(const std::string& ransomNote,
    const string magazine)
{
    //check conditions:
    if (ransomNote.size() > magazine.size())
    {
        return false; //early terminate
    }
    std::vector<int> magazine_count(255, 0);
    std::vector<int> note_count(255, 0);
    //OR: int noteContents[26] = {0};

    //traverse through magazine string:
    for (int i = 0; i < magazine.size(); i++)
    {
        magazine_count[magazine[i]]++;
        //Note: noteContents[ransomNote[i]-'a']++;
    }

    for (int i = 0; i < ransomNote.size(); i++)
    {
        note_count[ransomNote[i]]++;
    }

    for (int i = 0; i < note_count.size(); i++)
    {
        if (note_count[i] > magazine_count[i])
        {
            //lack of this character:
            //std::cout << "Need more " << static_cast<char>(i) << std::endl;
            return false;
        }
    }
    return true;
}

/*
 * Write a method to replace all spaces in a string with �%20�
 * Ref: Cracking the Coding Interview 4edition (p48)
 */
void StringExercises::ReplaceSpace(const std::string& rStrIn, std::string& rStrOut)
{
    int space_count = 0;
    for (int i = 0; i < rStrIn.length(); i++)
    {
        if (rStrIn[i] == ' ')
        {
            space_count++;
        }
    }

    rStrOut.resize(rStrIn.length() + 2 * space_count);
    int i2 = 0;
    for (int i = 0; i < rStrIn.length(); i++)
    {
        if (rStrIn[i] == ' ')
        {
            rStrOut[i2++] = '%';
            rStrOut[i2++] = '2';
            rStrOut[i2++] = '0';
        }
        else
        {
            rStrOut[i2++] = rStrIn[i];
        }
    }
}
/**
FindTheDifference
https://leetcode.com/problems/find-the-difference/
Given two strings s and t which consist of only lowercase letters.
String t is generated by random shuffling string s and then add one more letter at a random position.
Find the letter that was added in t.

Example:

Input :
    s = "abcd"
    t = "abcde"

Output :
       e

   Explanation :
      'e' is the letter that was added.

Good Solution: https://discuss.leetcode.com/topic/55940/concise-c-solution-using-xor
(similar problem: https://leetcode.com/problems/single-number/)
**/

char StringExercises::FindTheDifference(string s, string t)
{
    std::unordered_map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        if (m.find(s[i]) == m.end())
        {
            char a = s[i];
            m.insert(std::make_pair(a, 1)); //Note: std::make_pair doesn't need to specify a type.
        }
        else
        {
            m[s[i]]++;
        }
    }

    for (int i = 0; i < t.length(); i++)
    {
        if ((m.find(t[i]) == m.end()) || (m[t[i]] == 0))
        {
            return t[i];
        }
        else
        {
            m[t[i]]--;
        }
    }
    return NULL;
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





