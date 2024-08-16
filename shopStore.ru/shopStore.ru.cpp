#include <iostream>
#include "Data_base.h"
#include "Node_data.h"
#include <iomanip>
#include <set>
#include <Windows.h>
using namespace std;

int main() {

    Node_data data;
    data.showInterface();

    try {
        
        Data_base path("Node.txt");


        for (int i = 0; i < 10; i++) {
            Node_data* node = Node_data::generate_products();
            string nodeString = node->NodeString();  // Используем NodeString для форматированного вывода
            auto result = path.addLine(nodeString);
            cout << left << setw(35) << nodeString << endl;  // Выводим форматированную строку
            delete node;
        }
        path.showDoc();
        
        /*Удаляем строку с id */
        /*vector<int>idsToRemove = { 1,2 };
        path.removeLines(idsToRemove);*/

        string pid;

        for (const auto& pair : Node_data::product_map) {
            // Ищем продукт с идентификатором, равным значению из product_map
            Node_data* foundProduct = Node_data::find_id(pair.second);

            if (foundProduct) {
                string productString = foundProduct->NodeString();
                cout << left << setw(35) << productString << endl;  // Форматированный вывод
                pid.append(productString + "\n");
                delete foundProduct;
            }
        }

        // Добавляем результат в файл через addLine
        if (!pid.empty()) {
            auto res = path.addLine(pid);
            cout << res << endl;
        }
        else {
            cout << "No products found for concatenation." << endl;
        }

        
        
   }
   catch (const exception& e) {
      /*  Обработка исключений*/
       cerr << "Ошибка: " << e.what() << endl;
   }



    
}