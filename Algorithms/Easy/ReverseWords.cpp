//Reverse words

#include <iostream>
#include <string>
using namespace std;

void ReverseWords(string& str)
{
    if (str.empty()) return;
    //erase beginning spaces:
    string::iterator a = str.begin();
    while ((a!=str.end()) && (*a == ' ')) a++;
    if (a > str.begin()) {
        str.erase(str.begin(), a);
    }

    if (str.empty()) return;
    //erase ending spaces:
    a = str.end() - 1;
    while (a!=str.begin() && (*a == ' ')) a--;
    if (a < str.end() - 1) {
        str.erase(a+1, str.end());
    }
    if (str.empty()) return;

    //start reverse:
    string::iterator b = str.begin();
    string::iterator e = str.end() - 1;
    while (b < e) {
        char tmp = *e;
        *e = *b;
        *b = tmp;
        b++; e--;
    }
    b = str.begin(); //can use str.begin() and str.end() too.
    e = b;
    while (e != str.end()) {
        while ((e != str.end()) && (*e != ' ')) { //Note: crash if put (e!= str.end()) behind.
            e++;
        }
        auto i = b;
        auto j = e - 1;
        while (i < j) {
            char tmp = *i;
            *i = *j;
            *j = tmp;
            i++; j--;
        }
        if (e != str.end()) {
            b = ++e;
            while ((e != str.end()) && (*e == ' ')) {
                e++;
            }
            if (e > b) {
                b = str.erase(b, e);
                e = b;
            }
        }
    }
}

void ReverseAndPrintString(string& str) {
    cout << "\"" << str << "\"";
    ReverseWords(str);
    cout << " -> " << "\"" << str << "\"" << endl;
}

int main()
{
    string a1 = "Today I go to school";
    ReverseAndPrintString(a1);

    string a2 = "";
    ReverseAndPrintString(a2);

    string a3 = "Today";
    ReverseAndPrintString(a3);

    string a4 = "  Today     tomorrow ";
    ReverseAndPrintString(a4);

    string a5 = "I E O U A";
    ReverseAndPrintString(a5);

    string a6 = "   I    ";
    ReverseAndPrintString(a6);
    
    string a7 = "       ";
    ReverseAndPrintString(a7);

    string a8 = " ";
    ReverseAndPrintString(a8);

    return 0;
}