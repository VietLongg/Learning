#include "class.h"

void user::startUser()
{
    string fileName("user_information.txt");
    user *tempUser = new user;

    ifstream inputFile(fileName);
    if (!inputFile.is_open())
        cerr << "Could not open the file " << fileName << "!" << endl;

    while (!inputFile.eof())
    {
        getline(inputFile, tempUser->mail, ':');
        inputFile >> tempUser->password;
        inputFile.ignore(1);
        vecUser.push_back(*tempUser);
    }

    inputFile.close();
    delete tempUser;
    tempUser = nullptr;
}

void user::showVectorUser(const vector<user> &recVecUser)
{
    short int userNumber = 0;
    for (user i : recVecUser)
    {
        ++userNumber;
        cout << "Account " << userNumber << setw(4) << left << ": " << setw(15) << right << i.mail << ":" << i.password << endl;
    }
}