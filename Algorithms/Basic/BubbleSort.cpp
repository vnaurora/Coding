#include <iostream>
#include <vector>
using namespace std;
void BubbleSort(vector<int>& v)
{
    bool swapped = false;
    for (int i = 1; i < v.size(); i++) { //Note: i starts from 1
        for (int j = 0; j < v.size() - i; j++) {
            if (v[j] > v[j + 1]) {
                swapped = true;
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
        if (!swapped) break;
    }
    return;
}

int main()
{
    vector <int> v = { 2, 1, 3, 1, 7, 9, 4 };
    //vector <int> v = { 1,1,1,1 };
    BubbleSort(v);
    for (auto i : v) {
        std::cout << i << " ";
    }
}