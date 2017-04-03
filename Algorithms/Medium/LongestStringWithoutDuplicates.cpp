//Longest Substring Without Repeating Characters
//
//Given a string, find the length of the longest substring without repeating characters.
//Examples:
//Given "abcabcbb", the answer is "abc", which the length is 3.
//Given "bbbbb", the answer is "b", with the length of 1.
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//Ref: https://tenderleo.gitbooks.io/leetcode-solutions-/content/GoogleMedium/3.html

#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int LongestSubstringWithoutDuplicates(string& str)
{
    if (str.empty()) return 0;
    //if (str.size() == 1) return 1;
    map<char, int> m;
    int maxLength = -1;
    int lastDupIndex = -1;
    for (int i = 0; i < str.length(); i++) {
        if (m.find(str[i]) != m.end()) {
            int lastIndex = m[str[i]];
            if (lastDupIndex < m[str[i]]) {
                lastDupIndex = lastIndex; //move up last dup index
            }           
        }
        m[str[i]] = i; //add element or update last index in the map.
        maxLength = max(maxLength, i - lastDupIndex);
    }
    return maxLength;
}

int main()
{
    string a = "abcabcdab";
    cout << "max length of " << a << " = " << LongestSubstringWithoutDuplicates(a) << endl;
    a = "bbbbbbb";
    cout << "max length of " << a << " = " << LongestSubstringWithoutDuplicates(a) << endl;
    a = "pwwkew";
    cout << "max length of " << a << " = " << LongestSubstringWithoutDuplicates(a) << endl;
    a = "";
    cout << "max length of " << a << " = " << LongestSubstringWithoutDuplicates(a) << endl;
    a = "a";
    cout << "max length of " << a << " = " << LongestSubstringWithoutDuplicates(a) << endl;
}