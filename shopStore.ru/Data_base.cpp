#include "Data_base.h"
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <iomanip>
using namespace std;

Data_base::Data_base(string path) {
    this->path = path;
}

string Data_base::addLine(const string& line) {
    ofstream out(path, ios::app);
    if (out.is_open()) {
        out << setw(30) << line << endl;
        out.close();
    }
    else {
        throw runtime_error("�� ������� ������� ���� ��� ������: " + path);
    }
    return line;
}

bool Data_base::removeLines(const vector<int>& ids) {
    string buf;
    string allLines = "";
    set<int> idsSet(ids.begin(), ids.end()); // ��� �������� ������
    ifstream in(path);
    if (in.is_open()) {
        while (getline(in, buf)) {
            vector<string> split = splitStr(buf, ';');
            if (!split.empty()) {
                try {
                    int currentId = stoi(split[0]); // ����������� ������ ������� � int
                    if (idsSet.find(currentId) == idsSet.end()) {
                        allLines += buf + "\n";
                    }
                }
                catch (const invalid_argument& e) {
                    // ��������� ������, ����� �������������� �� �������
                    cerr << "������ �������������� ������ � int: " << split[0] << endl;
                }
            }
        }
        in.close();

        ofstream out(path);
        if (!out.is_open()) {
            throw runtime_error("�� ������� ������� ���� ��� ������: " + path);
        }
        out << allLines;
        out.close();
    }
    else {
        throw runtime_error("���� �� ������: " + path);
    }
    return true;
}

void Data_base::showDoc() {
    string buf;
    ifstream in(path);
    if (in.is_open()) {
        while (getline(in, buf)) {
            cout << buf << endl;
        }
        in.close();
    }
    else {
        throw runtime_error("���� �� ������: " + path);
    }
}

vector<string> Data_base::splitStr(string str, char del) {
    vector<string> result;
    string buf = "";
    for (char ch : str) {
        if (ch != del) {
            buf += ch;
        }
        else {
            result.push_back(buf);
            buf = "";
        }
    }
    result.push_back(buf);
    return result;
}


