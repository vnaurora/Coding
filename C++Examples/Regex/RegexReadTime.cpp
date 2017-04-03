//Ref: http://stackoverflow.com/questions/12908534/retrieving-a-regex-search-in-c
#include <iostream>
#include <string>
#include <regex>

void test_regex_search(const std::string& input)
{
    std::regex rgx("((1[0-2])|(0?[1-9])):([0-5][0-9])((am)|(pm))");
    std::smatch match;

    if (std::regex_search(input.begin(), input.end(), match, rgx))
    {
        std::cout << "Match\n";

        //for (auto m : match)
        //  std::cout << "  submatch " << m << '\n';

        std::cout << "match[1] = " << match[1] << '\n';
        std::cout << "match[4] = " << match[4] << '\n';
        std::cout << "match[5] = " << match[5] << '\n';
    }
    else
        std::cout << "No match\n";
}

int convert_time_to_min(const std::string& input)
{
    std::regex rgx("((2[0-3])|((0|1)?[0-9])):([0-5][0-9])");
    std::smatch match;

    if (std::regex_match(input, match, rgx))
    {
        std::cout << "Match\n";
        std::cout << "hh = " << match[1] << '\n';
        std::cout << "mm = " << match[5] << '\n';
        return stoi(match[1]) * 60 + stoi(match[5]);
    }
    else {
        std::cout << "No match\n";
        return -1;
    }

}


int main()
{
    const std::string time1 = "9:45pm";
    const std::string time2 = "11:53am";

    test_regex_search(time1);
    test_regex_search(time2);

    std::vector<std::string> time_list = { "01:23", "0:00", "1:25", "23:59", "01:01", "02:02"};
    for (auto s : time_list) {
        int min = convert_time_to_min(s);
        std::cout << "min = " << min << std::endl;
        //int min2 = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        //std::cout << "min2 = " << min2 << std::endl;
    }    

    
}