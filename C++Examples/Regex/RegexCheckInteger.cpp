//C++ Examples:
//Regex Check integer
//Ref: https://solarianprogrammer.com/2011/10/12/cpp-11-regex-tutorial/
#include <iostream>
#include <regex>
#include <string>


//Pattern to check real number:
//regex rr("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
//check real number with scientific format (e.g. -1.23e+06, 0.245e10, 1E5)
//regex rr("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");

using namespace std;

int main()
{
    string input;
    regex integer("(\\+|-)?[[:digit:]]+");
    //As long as the input is correct ask for another number
        while (true)
        {
        	cout << "Give me an integer!" << endl;
        	cin >> input;
        	if (!cin) break;
        	//Exit when the user inputs q
            if (input == "q")
            	break;
        	if (regex_match(input, integer))
                cout << "integer" << endl;
        	else
            {
        	    cout << "Invalid input" << endl;
            }
        }
}