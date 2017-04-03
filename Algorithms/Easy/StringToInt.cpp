//convert String to Interger:
//Ref: https://leetcode.com/problems/string-to-integer-atoi/
//Solution: https://discuss.leetcode.com/topic/2666/my-simple-solution
#include <string>
#include <iostream>
using namespace std;

#ifndef MAX_INT
#define MAX_INT 2147483647
#endif
#ifndef MIN_INT
#define MIN_INT -2147483648
#endif

int StringToInt(const string & str)
{
    if (str.empty()) return 0;
    int i = 0;
    while (str[i] == ' ') i++;

    //first non-space character:
    int sign = 1;
    if (str[i] == '-') {
        sign = -1; 
        i++;
    }
    else if (str[i] == '+') {
        i++;
    }
    int num = 0;
    int max_limit = MAX_INT / 10;
    while (i< str.size()) {
        if ((str[i] >= '0') && (str[i] <= '9')) { //valid number
            if ((num < max_limit) || ((num == max_limit) && (str[i] <= '7'))) { //check max value
                num = num * 10 + (str[i] - '0');
            }
            else {
                return (sign == 1) ? MAX_INT : MIN_INT;
            }
        }
        else {
            break;
        }
        i++;
    }

    return sign*num;
}

int main()
{
    string a0 = "";
    string a1 = "  1005";
    string a2 = "9b343";
    string a3 = "-027281";
    string a4 = "9999123123124342";
    string a5 = "-34324924239428982";

    cout << a0 << " = " << StringToInt(a0) << endl;
    cout << a1 << " = " << StringToInt(a1) << endl;
    cout << a2 << " = " << StringToInt(a2) << endl;
    cout << a3 << " = " << StringToInt(a3) << endl;
    cout << a4 << " = " << StringToInt(a4) << endl;
    cout << a5 << " = " << StringToInt(a5) << endl;
}