//Lets consider an Array filled with balls of one of these three colors Red/Green/Blue. Sort this array in O(n) time.
//https://rahulkumar4.wordpress.com/2014/07/16/algorithm-problem-sort-an-array-of-three-color-balls/
//https://en.wikipedia.org/wiki/Dutch_national_flag_problem
#include <string>
#include <vector>
#include <iostream>
using namespace std;
void Sort3ColorBalls(vector<string>& ar)
{
    if ((ar.empty()) || (ar.size() == 1)) return;

    int pRed = 0;
    int pBlue = ar.size() - 1;
    for (int i = 0; i < pBlue; i++) {
        if (pRed < pBlue) {
            if (ar[i] == "R") {
                auto tmp = ar[i];
                ar[i] = ar[pRed];
                ar[pRed++] = tmp;
            }
            else if (ar[i] == "B") {
                auto tmp = ar[i];
                ar[i--] = ar[pBlue];
                ar[pBlue--] = tmp;
            }
        }
    }
}

int main()
{
    vector<string> ar{ "G", "R", "B", "R", "G", "R", "B", "G", "G", "B" };
    Sort3ColorBalls(ar);
    for (auto i : ar) {
        cout << i << " ";
    }
}