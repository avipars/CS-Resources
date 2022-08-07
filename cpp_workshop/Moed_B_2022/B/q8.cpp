#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class Student
{
    private:
        string name;
        float avg;

    public:
        Student(string sName, float sAvg) : avg(sAvg)
        {
            name = sName;
        };
        float getAvg() { return avg; }
};

bool honors(Student s) { return s.getAvg() >= 90; }

void init(vector<Student> &vec) {
    // vec.push_back(Student("Alex", 100));
    vec.push_back(Student("John", 90));
    vec.push_back(Student("Mary", 80));
    vec.push_back(Student("Jane", 70));
    vec.push_back(Student("Joe", 60));
    vec.push_back(Student("Mark", 50));
    vec.push_back(Student("Paul", 40));
    vec.push_back(Student("Peter", 30));
    vec.push_back(Student("Paul", 20));
    vec.push_back(Student("Paul", 10));

}
// הפעולה תקינה, ולא מוצגת כאן
int main()
{
    vector<Student> students;
    init(students);

    // if at least 1 student has perfect gpa (avg of 100)
    if (any_of(students.begin(), students.end(), [](Student s)
               { return s.getAvg() >= 100; }))
    {
        cout << count_if(students.begin(), students.end(), [](Student s)
                         { return s.getAvg() >= 90; })
             << endl;
    }

    return 0;
}