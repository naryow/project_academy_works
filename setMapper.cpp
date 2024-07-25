#include <iostream>
#include <set>
#include <map>
using namespace std;

#define random(a,b) a+rand()%(b+1-a)

class Student {
    string name;
    string surname;
    int age;

public:
    Student(string name, string surname) {
        this->name = name;
        this->surname = surname;
        age = random(20, 45);
    }

    string getName() {
        return name;
    }
    string getSurname() {
        return surname;
    }
    int getAge() {
        return age;
    }

};

ostream& operator << (ostream& os, Student& st) {
    return os << st.getName() << " " << st.getSurname() << " " << st.getAge();
}


void printAllStudents(const map<string, set<Student*>>& studentMap) {
    for (const auto& group : studentMap) {
        cout << "Group: " << group.first << endl;
        for (const auto& student : group.second) {
            cout << *student << endl;
        }
    }
}


int main()
{
    map<string, set<Student*>> studentMap;
    Student* student1 = new Student("Kamala", "Harris");
    studentMap["1A"].insert(student1);
   
    Student* student2 = new Student("Daeneris", "Storeborn");
    studentMap["2A"].insert(student2);

    Student* student3 = new Student("Night", "King");
    studentMap["3A"].insert(student3);
    printAllStudents(studentMap);
    return 0;
}