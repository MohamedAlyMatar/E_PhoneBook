#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "Hello PhoneMan!\nWellcome to your digital phonebook\n";
    cout << "\nWhat do you want to do?\n\n";
    cout << "1-Add new record\n2-Display all records\n3-Search telephone number\n";
    cout << "4-Search person's name\n5-Update telephone number\n";

    int answer;
    cout << "\nChoose an option: ";
    cin >> answer;
    
    if (answer == 1)
    {
        int id;
        string name;
        int number;

        ofstream MyBook("Phonebook.txt", ios::app);
        cout << "\nEnter ID: ";
        cin >> id;
        MyBook << "ID: " << id << "\n";

        cout << "Enter First Name Only: ";
        cin >> name;
        MyBook << "Name: " << name << "\n";

        cout << "Enter Number (ignore the first zero of the number): ";
        cin >> number;
        MyBook << "Number: " << number << "\n";

        MyBook.close();
    }
    else if (answer == 2)
    {
        string MyLine;
        ifstream MyBook("Phonebook.txt");
        while (getline(MyBook, MyLine))
        {
            cout << MyLine << endl;
        }
        MyBook.close();
    }

    else if (answer == 3)
    {
        int  target;
        cout << "Enter number to get the name: ";
        cin >> target;

        ifstream MyBook("Phonebook.txt");

        string title;
        int id;
        string name;
        int number;

        while (MyBook >> title >> id >> title >> name >> title >> number)
        {
            if (number == target)
                cout << "The number " << target << " belongs to " << name;
        }
        MyBook.close();
    }

    else if (answer == 4)
    {
        string target;
        cout << "Enter name to get the number: ";
        cin >> target;

        ifstream MyBook("Phonebook.txt");

        string title;
        int id;
        string name;
        int number;

        while (MyBook >> title >> id >> title >> name >> title >> number)
        {
            if (name == target)
                cout << "The number of "<< target << " is " << number;
        }
        MyBook.close();
    }

    else if (answer == 5)
    {
        int target, newNum;
        cout << "Enter the number you want to change: ";
        cin >> target;

        cout << "Enter the new number: ";
        cin >> newNum;
        
        ofstream TBook("tPhonebook.txt"); //Temporary file
        ifstream MyBook("Phonebook.txt");

        string title;
        int id;
        string name;
        int number;

        while (MyBook >> title >> id >> title >> name >> title >> number)
        {
            TBook << "ID: " << id << "\n";
            TBook << "Name: " << name << "\n";
            if (number == target)
            {
                TBook << "Number: " << newNum << "\n";
            }
            else
            {
                TBook << "Number: " << number << "\n";
            }
        }
        
        TBook.close();
        MyBook.close();
        remove("PhoneBook.txt");
        rename("tPhoneBook.txt", "PhoneBook.txt");
    }
    return 0;
}