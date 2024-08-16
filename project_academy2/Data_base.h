#pragma once
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Data_base {
private:
    string path;
    vector<string> splitStr(string str, char del);

public:
    Data_base() = default;
    Data_base(string path);
    string addLine(const string& line);
    bool removeLines(const vector<int>& ids);
    void showDoc();
};

