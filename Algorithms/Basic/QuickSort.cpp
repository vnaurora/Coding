//Quick Sort:
#include <iostream>
#include <vector>
using namespace std;

void QuickSortHelper(vector<int>& a, int begin, int end)
{
    int pivot = a[(begin + end) / 2];
    int i = begin; int j = end;
    while (i <= j) {
        while (a[i] < pivot) i++; //Note: not <=
        while (a[j] > pivot) j--;
        if (i <= j) {
            //swap:
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++; j--; //Note2: need to increase/decrease pointer here.
        }
    }

    if (begin< j) QuickSortHelper(a, begin, j); //Note 3: begin goes with j, end goes with i.
    if (end > i) QuickSortHelper(a, i , end);
}

void QuickSort(vector<int>& a)
{
    if (a.size() <= 1) return;
    QuickSortHelper(a, 0, a.size() - 1);
}

int main()
{
    vector<int> a = { 2, 1, 3, 1, 7, 9, 4 };
    QuickSort(a);
    for (auto i : a) {
        std::cout << i << " ";
    }
}