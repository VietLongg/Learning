#include "class.h"

int main()
{
    string choice;
    do
    {
        system("clear");
        cout << "============ Welcome to ATM Banking ============\n"
             << endl;
        cout << "[1] Login" << endl;
        cout << "[2] Register" << endl;
        cout << "[3] Exit" << endl;
        cout << "\n[*]Enter your choice -> ";
        getline(cin, choice);
        if (choice == "1")
        {
            system("clear");
        }
        else if (choice == "2")
        {
            system("clear");
        }
        else if (choice == "3")
        {
            cout << endl
                 << "---------- Thank for choosing us ----------" << endl;
        }
        else
        {
            cout << "You should have chosen an implemented choice";
            cin.get();
            system("clear");
        }
    } while (!bool(choice == "3"));
    cin.get();
}
