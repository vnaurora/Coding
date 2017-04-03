//Helper functions

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

#ifndef MAX_INT
#define MAX_INT 2147483647
#endif

template<class T>
void PrintVector(const string& name, const vector<T>& input)
{
    std::cout << name << ": [";
    for (auto i : input) {
        std::cout << i << ", ";
    }
    std::cout << "]" << std::endl;
}

//parse string, convert into integer vector:
vector<int> ParseStringToVector(const string& in_str)
{
    vector<int> out_vect;
    string::size_type start = 1; //skip the first char "["
    string::size_type end;
    while (((end = in_str.find(",", start)) != string::npos) || ((end = in_str.find("]", start)) != string::npos)) {
        string & sub_string = in_str.substr(start, end - start);
        if (sub_string.find("null") != string::npos) {
            out_vect.push_back(MAX_INT); //use MAX_INT for null val.
        }
        else
        {
            try{
                int val = stoi(sub_string);
                out_vect.push_back(val);
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
                std::cout << "ERROR: Unable to convert " << sub_string <<
                    " to integers! Use \"null\" for empty node. Insert empty node here." << std::endl;
                out_vect.push_back(MAX_INT);
            }
        }
        start = end + 1;
    }
    return out_vect; //guaranteed no vector copy (see here: https://mbevin.wordpress.com/2012/11/20/move-semantics/)
}

#endif //HELPER_FUNCTIONS_H


