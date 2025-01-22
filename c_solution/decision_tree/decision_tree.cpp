#include <iostream>
#include <vector>
#include "vectorUtilities.cpp"
#include <limits.h> // For INT_MAX
#include "fileHandler.cpp"
#include <map>
using namespace std;

int main()
{
    FileHandler fileHandler;
    StringUtilities stringUtilities;
    std::string fileName = "dataset/weather.csv";
    map<std::string, std::vector<std::string>> csvData = fileHandler.handleCSV(fileHandler, stringUtilities, fileName);
    // for(std::string s : csvData["outlook"]){
    //     cout<<s<<" ";
    // }
}