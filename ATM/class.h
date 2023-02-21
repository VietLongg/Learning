#include "library.h"

class information
{
protected:
    string accountNumber;
    string accountFirstName;
    string accountLastName;
};

class user : protected information
{
private:
    string mail;
    string password;
    

public:
    void startUser();
    void showVectorUser(const vector<user> &received_vec_users);
};

static vector<user> vecUser;