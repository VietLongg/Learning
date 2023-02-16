#include "class.h"

int main()
{
    user *newuser = new user;

    newuser->start_user();
    newuser->start_appetizer();
    newuser->start_main_course();
    newuser->start_desserts();

    string choice;
    do
    {
        system("clear");
        cout << "============ Welcome to food ordering ============\n"
             << endl;
        cout << "[1] Login" << endl;
        cout << "[2] Register" << endl;
        cout << "[3] Exit" << endl;
        cout << "\n[*]Enter your choice -> ";
        getline(cin, choice);
        if (choice == "1")
        {
            system("clear");
            newuser->sign_in();
        }
        else if (choice == "2")
        {
            system("clear");
            newuser->sign_up();
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

    delete newuser;
    newuser = nullptr;
    cin.get();
}
