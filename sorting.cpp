#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class EmployeeInformation
{
public:
    string firstName;
    string lastName;
    string number;
    EmployeeInformation(const string &_lastName, const string &_firstName, const string &_number) : lastName(_lastName),
                                                                                                    firstName(_firstName),
                                                                                                    number(_number)
    {
    }
};

int main()
{
    string filename, line;
    string firstname, lastname, number;
    vector<EmployeeInformation> employees;
    ifstream file;
    int choice;

    cout << "Filename: ";
    cin >> filename;

    if (file.fail())
    {
        cout << "File failed to open." << endl;
        return 1;
    }
    file.open("C:\\" + filename);

    while (getline(file, line))
    {
        line.erase(line.begin() + line.find(":"));
        istringstream iss(line);
        iss >> lastname >> firstname >> number;
        EmployeeInformation employee(lastname, firstname, number);
        employees.push_back(employee);
    }

    cout << "1: Sort by name\n2: Sort by lastname\n3: Sort by number\nYour choice:";
    cin >> choice;

    if (choice == 1)
    {
        for (EmployeeInformation i : employees)
        {
            cout << i.firstName << " " << i.lastName << ": " << i.number << endl;
        }
    }

    if (choice == 2)
    {
        for (EmployeeInformation i : employees)
        {
            cout << i.lastName << " " << i.firstName << ": " << i.number << endl;
        }
    }

    if (choice == 3)
    {
        for (EmployeeInformation i : employees)
        {
            cout << i.number << ": " << i.lastName << " " << i.firstName << endl;
        }
    }
    file.close();
    return 0;
}