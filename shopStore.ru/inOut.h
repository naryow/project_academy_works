#pragma once
#include <iostream>
#include <vector>
#include "Data_base.h"
#include "Node_data.h"
using namespace std;
class inOut
{
private:
	vector<Node_data*> nodedata;
	Data_base* time = new Data_base("TimeMangeer.txt");
public:
	void inComeStore(Node_data* nodeData);
	void outComeStore(int id);
};

