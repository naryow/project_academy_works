#include "Node_data.h"
#include <iomanip>
#include <sstream>

using namespace std;

int Node_data::countId = 1;
vector<string> Node_data::products_names = { "other", "meat", "milk", "grocery" };

map<string, string> Node_data::product_map = {
    {"meat", "1"},
    {"grocery", "2"},
    {"milk", "3"},
    {"other", "4"}
};

Node_data::Node_data(const string& products_name) {
    this->products_name = products_name;
    this->id = countId++;
    this->category_id = Node_data::product_map[products_name];
}

Node_data::Node_data(int id, const string& name) {
    this->id = id;
    this->products_name = name;
    this->category_id = Node_data::product_map[name];
}

int Node_data::get_id() const {
    return id;
}



string Node_data::NodeString() const {
    stringstream ss;
    ss << setw(10) <<  left << id << " "
        << setw(15) << left << to_string(id)+ ";" +products_name << "   "
        << setw(10) << left << category_id;
    return ss.str();
}

Node_data* Node_data::generate_products() {
    Node_data* node = new Node_data(products_names[random(0, products_names.size() - 1)]);
    return node;
}

Node_data* Node_data::find_id(string product_id) {
    for (const auto& pair : Node_data::product_map) {
        if (pair.second == product_id) {
            return new Node_data(stoi(product_id), pair.first);
        }
    }
    return nullptr;
}

void Node_data::showInterface() const {
    cout << left << setw(10) << "product_id" << "|"
        << left << setw(15) << "product_name" << "|"
        << left << setw(10) << "category_id" << "|" << endl;

    cout << string(10, '-') << "|"
        << string(15, '-') << "|"
        << string(10, '-') << "|" << endl;
}

