#include "library.h"

class food
{
protected:
    string food_name;
    float food_price;
    float serving_number;

public:
    string get_food_name()
    {
        return food_name;
    }
    float get_food_price()
    {
        return food_price;
    }
    float get_serving_number()
    {
        return serving_number;
    }
    void set_food_name(string food_name)
    {
        this->food_name = food_name;
    }
    void set_food_price(float food_price)
    {
        this->food_price = food_price;
    }
    void set_serving_number(float serving_number)
    {
        this->serving_number = serving_number;
    }

    void show_food(const vector<food> &received_vec_food);
    void start_appetizer();
    void start_main_course();
    void start_desserts();
    void load_food(const string &received_filename);
};

class user_order : public food
{
private:
    float user_servings;
    float total_price = 0;

public:
    float get_user_servings()
    {
        return user_servings;
    }
    float get_total_price()
    {
        return total_price;
    }
    void set_user_servings(float user_servings)
    {
        this->user_servings = user_servings;
    }
    void set_total_price(float total_price)
    {
        this->total_price = total_price;
    }

    void show_vector_user_order(const vector<user_order> &received_vec_user_order, bool check_voucher);
    void get_food_from_list(vector<food> &received_vec_food, short int received_ordinal_food_numbers);
    void check_deleted_food(short int &received_choice);
};

class user : public user_order
{
private:
    string account_name;
    string account_password;

public:
    string get_account_name()
    {
        return account_name;
    }
    string get_account_password()
    {
        return account_password;
    }
    void set_account_name(string account_name)
    {
        this->account_name = account_name;
    }
    void set_account_password(string account_password)
    {
        this->account_password = account_password;
    }

    void start_user();
    void show_vector_user(const vector<user> &received_vec_users);
    void start_menu(user &received_user);
    void sign_in();
    void sign_up();
    void write_new_user_to_file(user received_user);
    void write_user_order_to_file(user &received_user, bool check_voucher);
    void select_food(vector<food> &received_vec_food, string &received_list_name, user &received_user);
    void delete_food(user &received_user);
    void check_out(user &received_user);
};

static float money_payment;
static vector<user> vecUser;
static vector<user_order> vec_user_order;
static vector<food> vec_appetizer;
static vector<food> vec_main_course;
static vector<food> vec_desserts;