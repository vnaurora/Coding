//Reverse digits of an integer.
//Example1: x = 123, return 321
//      Example2 : x = -123, return -321
//Ref: https://tenderleo.gitbooks.io/leetcode-solutions-/content/GoogleEasy/7.html

//Have you thought about this ? Here are some good questions to ask before coding.Bonus points for you if you have already thought through this!
//If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//Did you notice that the reversed integer might overflow ? Assume the input is a 32 - bit integer, then the reverse of 1000000003 overflows.How should you handle such cases ?
//For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
#include <iostream>
#include <limits> 
using namespace std;
int ReserseInt(int in)
{
    int out = 0;
    const int max_int = std::numeric_limits<int>::max();

    int sign = (in > 0) ? 1 : -1;
    in = abs(in);
    while (in > 0) {
        if (out > max_int / 10) return 0;
        out = out*10 + (in %10);
        in /= 10;
    }
    return out*sign;
}
int main()
{
    int a = 123;
    cout << a << " -> " << ReserseInt(a) << endl;
    a = -200;
    cout << a << " -> " << ReserseInt(a) << endl;
}
