#pragma once
#include "Data_base.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#define random(a,b) a+rand()%(b+1-a)
using namespace std;

class Node_data : public Data_base {
private:
    int id;
    string products_name;
    string category_id;
    static int countId;
    static vector<string> products_names;

public:
    Node_data() = default;
    Node_data(const string& products_name);
    Node_data(int id, const string& name);
    int get_id() const;
    string NodeString() const;
    static Node_data* generate_products();
    static Node_data* find_id( string product_id);
    /*void produts_ids();*/
    void showInterface() const;
    static  vector<string> product_ids;
    static map<string, string> product_map;


};

