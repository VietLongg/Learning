#include "class.h"
void user::write_new_user_to_file(user received_user)
{
    ofstream ofs("user_infor.txt");
    for (user i : vecUser)
    {
        ofs << i.account_name << ":" << i.account_password << endl;
    }
    ofs.close();
}

void user::write_user_order_to_file(user &received_user, bool check_voucher)
{
    string filename = received_user.get_account_name() + ".txt";
    float total_expense;
    time_t now = time(0);
    char *current_time = ctime(&now);

    ofstream ofs(filename, ios::app);
    ofs << "============================================ " << current_time;
    ofs << "[*] " << setw(30) << left << "Name" << setw(10) << left << "$ Price" << setw(8) << right << "Servings" << setw(15) << right << "Total" << endl;
    short int food_number = 0;
    for (user_order i : vec_user_order)
    {
        ++food_number;
        i.set_total_price(i.get_food_price() * i.get_user_servings());
        total_expense += i.get_total_price();
        ofs << food_number << ". " << setw(31) << left << i.get_food_name() << "$" << setw(10) << left << i.get_food_price() << setw(7) << right << i.get_user_servings() << setw(11) << right << "$" << setw(6) << left << i.get_total_price() << endl;
    }
    ofs << "----------------------------------------------------------------------" << endl;
    if (check_voucher == false)
    {
        ofs << "0. " << setw(30) << left << "Total" << setw(30) << right << "$" << setw(31) << left << total_expense << endl;
    }
    else
    {
        ofs << "0. " << setw(30) << left << "Merchandise Subtotal" << setw(30) << right << "$" << setw(31) << left << total_expense << endl;
        ofs << "0. " << setw(30) << left << "Voucher Discount" << setw(30) << right << "- $" << setw(31) << left << total_expense * 0.3 << endl;
        ofs << "0. " << setw(30) << left << "Total Payment" << setw(30) << right << "$" << setw(31) << left << total_expense - total_expense * 0.3 << endl;
    }
    ofs << endl;
    ofs.close();
}

void user::show_vector_user(const vector<user> &received_vec_users)
{
    short int user_number = 0;
    for (user i : received_vec_users)
    {
        ++user_number;
        cout << "Account " << user_number << setw(4) << left << ": " << setw(15) << right << i.account_name << ":" << i.account_password << endl;
    }
}

void user_order::show_vector_user_order(const vector<user_order> &received_vec_user_order, bool check_voucher)
{
    short int food_number = 0;
    float total_expense = 0;
    cout << "\n---------------------------- Odering Cart ----------------------------\n";
    cout << "[*] " << setw(30) << left << "Name" << setw(10) << left << "$ Price" << setw(8) << right << "Servings" << setw(15) << right << "Total" << endl;

    for (user_order i : vec_user_order)
    {
        ++food_number;
        i.total_price = i.food_price * i.user_servings;
        cout << food_number << ". ";
        cout << setw(31) << left << i.food_name;
        cout << "$" << setw(10) << left << i.food_price;
        cout << setw(7) << right << i.user_servings;
        cout << setw(11) << right << "$";
        cout << setw(6) << left << i.total_price << endl;
        total_expense += i.total_price;
    }
    cout << "----------------------------------------------------------------------" << endl;
    if (check_voucher == false)
    {
        cout << "0. " << setw(30) << left << "Total" << setw(30) << right << "$" << setw(31) << left << total_expense << endl;
        money_payment = total_expense;
    }
    else
    {
        cout << "0. " << setw(30) << left << "Merchandise Subtotal" << setw(30) << right << "$" << setw(31) << left << total_expense << endl;
        cout << "0. " << setw(30) << left << "Voucher Discount" << setw(30) << right << "- $" << setw(31) << left << total_expense * 0.3 << endl;
        cout << "0. " << setw(30) << left << "Total Payment" << setw(30) << right << "$" << setw(31) << left << total_expense - total_expense * 0.3 << endl;
        money_payment = total_expense - total_expense * 0.3;
    }
}

void user::check_out(user &received_user)
{
    string voucher;
    string choice;
    bool check_voucher = 0;
    do
    {
        system("clear");
        cout << "============================== Check out ==============================\n";

        received_user.show_vector_user_order(vec_user_order, check_voucher);

        cout << "=======================================================================" << endl;
        cout << "[1] Yes, Place Order" << endl;
        cout << "[2] No, Keep Shopping" << endl;
        cout << "[3] Add Voucher" << endl;
        cout << "\n[*]Enter your choice -> ";
        getline(cin, choice);
        if (choice == "1")
        {
            cout << "---------- You pay $" << money_payment << " for your cart ----------" << endl;
            cout << "----------- Thank you for your ordering ----------";
            received_user.write_user_order_to_file(received_user, check_voucher);
            vec_user_order.clear();
            cin.get();
            break;
        }
        else if (choice == "2")
        {
        }
        else if (choice == "3")
        {
            bool temp = false;
            do
            {
                cout << "Enter your voucher: ";
                getline(cin, voucher);
                if (voucher == "DISCOUNT30")
                {
                    check_voucher = 1;
                    temp = true;
                }
                else
                {
                    cout << "---------- This voucher is invalid ----------";
                    cin.get();
                }
            } while (temp == false);
        }
        else
        {
            cout << "You should have chosen an implemented choice";
            cin.get();
            system("clear");
        }
    } while (!bool(choice == "2"));
}

void food::show_food(const vector<food> &received_vec_food)
{
    short int food_number = 0;
    cout << "[*] " << setw(30) << left << "Name" << setw(10) << left << "$ Price" << setw(5) << right << "Servings" << endl;
    for (food i : received_vec_food)
    {
        ++food_number;
        cout << "[" << food_number << "] " << setw(30) << left << i.food_name << "$" << setw(10) << left << i.food_price << setw(7) << right << i.serving_number << endl;
    }
}

void food::load_food(const string &received_filename)
{
    food temp_food;

    ifstream input_file(received_filename);
    if (!input_file.is_open())
        cerr << "Could not open the file " << received_filename << "!" << endl;

    while (!input_file.eof())
    {

        getline(input_file, temp_food.food_name, ':');
        input_file >> temp_food.food_price;
        input_file.ignore(1);
        input_file >> temp_food.serving_number;
        input_file.ignore(1);

        if (received_filename == "appetizer.txt")
            vec_appetizer.push_back(temp_food);
        else if (received_filename == "main_course.txt")
            vec_main_course.push_back(temp_food);
        else if (received_filename == "desserts.txt")
            vec_desserts.push_back(temp_food);
    }
    input_file.close();
}

void food::start_appetizer()
{
    string filename("appetizer.txt");
    load_food(filename);
}

// Same operation with the above function
void food::start_main_course()
{
    string filename("main_course.txt");
    load_food(filename);
}

// Same operation with the above function
void food::start_desserts()
{
    string filename("desserts.txt");
    load_food(filename);
}

void user_order::get_food_from_list(vector<food> &received_vec_food, short int received_ordinal_food_numbers)
{
    bool check_servings = false;
    float temp_user_servings;
    do
    {
        user_order *temp_user_order = new user_order;

        cout << "\n[*]Enter your servings -> ";
        cin >> temp_user_servings;
        fflush(stdin);
        temp_user_order->set_user_servings(temp_user_servings);
        if (received_vec_food[received_ordinal_food_numbers].get_serving_number() < temp_user_order->get_user_servings())
        {
            cout << received_vec_food[received_ordinal_food_numbers].get_food_name() << " is not enough servings for your order" << endl;
            cin.get();
            break;
        }
        temp_user_order->food_name = received_vec_food[received_ordinal_food_numbers].get_food_name();
        temp_user_order->food_price = received_vec_food[received_ordinal_food_numbers].get_food_price();
        received_vec_food[received_ordinal_food_numbers].set_serving_number(received_vec_food[received_ordinal_food_numbers].get_serving_number() - temp_user_order->user_servings);
        vec_user_order.push_back(*temp_user_order);

        check_servings = true;
        delete temp_user_order;
    } while (check_servings != true);
}

void user_order::check_deleted_food(short int &received_choice)
{
    for (auto &i : vec_appetizer)
    {
        if (i.get_food_name() == vec_user_order[received_choice].food_name)
        {
            i.set_serving_number(i.get_serving_number() + vec_user_order[received_choice].user_servings);
            break;
        }
    }
    for (auto &i : vec_main_course)
    {
        if (i.get_food_name() == vec_user_order[received_choice].food_name)
        {
            i.set_serving_number(i.get_serving_number() + vec_user_order[received_choice].user_servings);
            break;
        }
    }
    for (auto &i : vec_desserts)
    {
        if (i.get_food_name() == vec_user_order[received_choice].food_name)
        {
            i.set_serving_number(i.get_serving_number() + vec_user_order[received_choice].user_servings);
            break;
        }
    }
}

void user::delete_food(user &received_user)
{
    short int choice;
    bool check_valid_choice = false;
    do
    {
        cout << "Enter the food ordinal number need deleting: ";
        cin >> choice;
        fflush(stdin);
        if (choice <= vec_user_order.size() && choice > 0)
        {
            choice = choice - 1;
            received_user.check_deleted_food(choice);
            vec_user_order.erase(vec_user_order.begin() + choice);
            check_valid_choice = true;
        }
        else
        {
            cout << "Your choice is not valid, please try again";
            cin.get();
            break;
        }
    } while (check_valid_choice != true);
}

void user::select_food(vector<food> &received_vec_food, string &received_list_name, user &received_user)
{
    string choice;
    do
    {
        system("clear");
        cout << "----------------- " << received_list_name << " -----------------\n"
             << endl;
        received_user.show_food(received_vec_food);
        cout << "[" << received_vec_food.size() + 1 << "]"
             << " Delete food" << endl;
        cout << "[" << received_vec_food.size() + 2 << "]"
             << " Go back" << endl;
        received_user.show_vector_user_order(vec_user_order, 0);
        cout << "\n[*]Enter your choice -> ";
        getline(cin, choice);
        if (choice == "1")
        {
            received_user.get_food_from_list(received_vec_food, 0);
        }
        else if (choice == "2")
        {
            received_user.get_food_from_list(received_vec_food, 1);
        }
        else if (choice == "3")
        {
            received_user.get_food_from_list(received_vec_food, 2);
        }
        else if (choice == "4")
        {
            received_user.get_food_from_list(received_vec_food, 3);
        }
        else if (choice == "5")
        {
            if (vec_user_order.empty())
            {
                cout << "There is nothing to delete";
                cin.get();
            }
            else
                received_user.delete_food(received_user);
        }
        else if (choice == "6")
        {
        }
        else
        {
            cout << "You should have chosen an implemented choice";
            cin.get();
            system("clear");
        }
    } while (!bool(choice == "6"));
}

void user::start_user()
{
    string filename("user_infor.txt");
    user *temp_user = new user;

    ifstream input_file(filename);
    if (!input_file.is_open())
        cerr << "Could not open the file " << filename << "!" << endl;

    while (!input_file.eof())
    {
        getline(input_file, temp_user->account_name, ':');
        input_file >> temp_user->account_password;
        input_file.ignore(1);
        vecUser.push_back(*temp_user);
    }

    input_file.close();
    delete temp_user;
    temp_user = nullptr;
}

void user::start_menu(user &received_user)
{
    string choice;
    do
    {
        system("clear");
        cout << "<<<<<<<<<<<<<<<<<<<<< User: " << received_user.account_name << " >>>>>>>>>>>>>>>>>>>>>" << endl;
        cout << "===================== Food ordering list =====================\n"
             << endl;
        cout << "[1] Appetizer" << endl;
        cout << "[2] Main Course" << endl;
        cout << "[3] Dessert" << endl;
        cout << "[4] Check out" << endl;
        cout << "[5] Delete food" << endl;
        cout << "[6] Log out" << endl;
        received_user.show_vector_user_order(vec_user_order, 0);
        cout << "\n[*]Enter your choice -> ";
        getline(cin, choice);
        if (choice == "1")
        {
            string list_name = "Appetizer";
            received_user.select_food(vec_appetizer, list_name, received_user);
        }
        else if (choice == "2")
        {
            string list_name = "Main Course";
            received_user.select_food(vec_main_course, list_name, received_user);
        }
        else if (choice == "3")
        {
            string list_name = "Dessert";
            received_user.select_food(vec_desserts, list_name, received_user);
        }
        else if (choice == "4")
        {
            received_user.check_out(received_user);
        }
        else if (choice == "5")
        {
            if (vec_user_order.empty())
            {
                cout << "There is nothing to delete";
                cin.get();
            }
            else
                received_user.delete_food(received_user);
        }
        else if (choice == "6")
        {
            cout << "\n---------- Thank you " << received_user.account_name << " ----------";
            cin.get();
        }
        else
        {
            cout << "You should have chosen an implemented choice";
            cin.get();
            system("clear");
        }
    } while (!bool(choice == "6"));
}

void user::sign_in()
{
    string *tempAccountName = new string;
    string *tempAccountPassword = new string;

    cout << "---------- Welcome to login board ----------" << endl;
    cout << "Enter your account name: ";
    getline(cin, *tempAccountName);
    cout << "Enter your account password: ";
    getline(cin, *tempAccountPassword);
    short int check_loop = 0;

    for (user i : vecUser)
    {
        if (i.account_name == *tempAccountName && i.account_password == *tempAccountPassword)
        {
            cout << "---------- You've already login in ---------" << endl;
            vec_user_order.clear();
            cin.get();
            i.start_menu(i);
            break;
        }
        check_loop++;
        if (check_loop == vecUser.size())
        {
            cout << "---------- Your account name or password is not correct ----------" << endl;
            cout << "------------------ Press any thing to continue -------------------";
            cin.get();
            break;
        }
    }
}

void user::sign_up()
{
    bool check_existed_account_name = false;
    user temp_user;
    cout << "---------- New user registration ----------" << endl;

    do
    {
        cout << "Enter your account name: ";
        getline(cin, temp_user.account_name);

        for (auto i : vecUser)
        {
            if (temp_user.account_name == i.account_name)
            {
                cout << "This account name has already existed";
                cout << " | Please choose another one" << endl;
                check_existed_account_name = true;
                break;
            }
            check_existed_account_name = false;
        }
    } while (check_existed_account_name != false);

    cout << "----- You can get this account name -----" << endl;

    cout << "Enter your account password: ";
    getline(cin, temp_user.account_password);

    vecUser.push_back(temp_user);
    temp_user.write_new_user_to_file(temp_user);

    cout << endl
         << "---------- Successful account registration ----------";
    cin.get();
}
