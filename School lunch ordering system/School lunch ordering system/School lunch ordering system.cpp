#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdlib>
using namespace std;

// functions for login & registration.
void login();
void registr();
void change();
void admin();

int Display_MainMenu(); // main menu display.
void Select_MenuItems(); // displays submenus.

// functions to manage items in menu. Admin access only.
void addMenu();
void change_menuList();
void remove_menuList();
void Display_menuList();

// functions to make order. All acess.
void Add_toCart(int, string, float); // copy function from user input and pass values to function and save to cartlist.txt file. 
void view_cart(); // function to view cart. Reads cartlist.txt file.
void change_qty(); // function to change order qty.
void make_payment(); // function to see totals and proceed with payment.
void receipt();

struct student
{
    string stat;
};
struct users
{
    string uname, password, role;
};

vector<users> user;

struct menuItems
{
    int itemnumber = 0;
    string itemname;
    float price = 0;
};// Structure for menu items. User input in ordering.

vector<menuItems> menu;

struct orderItems
{
    string ordername;
    float orderprice = 0;
    int orderqty = 0;
};// Structure for copy function variables in copying passed values from order menu screen.

vector<orderItems> order;

int main()
{
    int choice;
    cout << "oo=======================================================================================oo" << endl;
    cout << "||     ||      ||    ||  ||\\\\   ||   ///\\\\\\  |||    |||  ||||||    ///\\\\\\   \\\\    //     ||" << endl;
    cout << "||     ||      ||    ||  || \\\\  ||  ||    ||  ||    ||   ||   ||  ||    ||   \\\\  //      ||" << endl;
    cout << "||     ||      ||    ||  ||  \\\\ ||  ||        ||||||||   |||||    ||    ||    >><<       ||" << endl;
    cout << "||     ||      ||    ||  ||   \\\\||  ||    ||  ||    ||   ||   ||  ||    ||   //  \\\\      ||" << endl;
    cout << "||     ||||||  ||||||||  ||    \\\\|   \\\\\\///  |||    |||  ||||||    \\\\\\///   //    \\\\     ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                    ******************* Welcome *********************                  ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                             1. Login                                                  ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                             2. Register                                               ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                             3. Change Password                                        ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                             4. Exit                                                   ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "oo=======================================================================================oo" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "                         Enter your choice: "; cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        change();
        break;
    case 4:
        cout << "Thank you for visiting!!";
        exit(1);
        break;
    }
}
void registr()
{
    system("CLS");
    string u_name, pwd, role, line, data;
    int ch;
    bool rego = true;

    cout << "\n Select your role\t"
        << "1: Student\t 2: Teacher\t 3: Admin\t 4. Back to login page :  ";
    cin >> ch;
    cin.ignore();
    cout << "\n Enter username: ";
    getline(cin, u_name);

    ifstream userFile;
    userFile.open("database.txt", ios::in);
    while (getline(userFile, line))
    {
        if (line.find(u_name) != string::npos)
            rego = false;
    }
    userFile.close();

    if (rego)
    {
        ofstream infile;
        infile.open("database.txt", ios::app);


        cout << " Enter password: ";
        getline(cin, pwd);
        if (ch == 1)
        {
            role = "student";
            cout << "\n Student Registration Successful!!\n";
        }
        else if (ch == 2)
        {
            role = "teacher";
            cout << "\n Teacher Registration Successful!!\n";
        }
        else if (ch == 3)
        {
            role = "Admin";
            cout << "\n Admin Registration Successful!!\n";
        }
        else
        {
            main();
        }


        infile << u_name << " " << pwd << " " << role << endl;
        //user.clear();
        infile.close();
        main();
    }
    else
    {
        cout << "\n Sorry username exist!!\n";
    }

    system("pause");
    system("CLS");

}
void login()
{
    student s;
    int count = 0;
    string user, pass, u, p, last, l, line, role;
    system("cls");
    cout << "Please enter the follwing details: " << endl;
    cout << "Enter first name: ";
    cin >> user;
    cout << "Enter Password: ";
    cin >> pass;

    ifstream inFile("database.txt");

    while (getline(inFile, line))
    {
        if (line.find(user) != string::npos)
        {
            int pos = line.find_last_of(' ') + 1;
            role = line.substr(pos, string::npos);

            count = 1;
            system("cls");
        }
    }
    if (count == 1)
    {
        cout << "<LOGIN SUCCESSFUL> " << "\nHello " << user << " " << "\nRole: " << role << endl;
        cin.get();
        if (role == "Admin")
        {
            admin();
        }
        else
        {
            Select_MenuItems();
        }
    }
    else
    {
        cout << "\nLogin Error!!!\n Please check your username and password!" << endl;
        main();
    }
    inFile.close();
}
void change()
{
    system("CLS");
    users u;
    vector<string> readfile;
    bool success = false;
    string u_name, uName, n_pwd, line, data;

    ifstream userFile;
    userFile.open("database.txt", ios::in);

    cout << "\n Enter Username: ";
    cin >> u_name;

    while (getline(userFile, line))
    {
        istringstream iss(line);
        while (iss >> data)
        {

            readfile.push_back(data);
        }

        u.uname = readfile[0];
        u.password = readfile[1];
        u.role = readfile[2];
        user.push_back(u);
        readfile.clear();
    }
    userFile.close();

    vector<users>::iterator itr;
    for (itr = user.begin(); itr != user.end(); itr++)
    {
        if (u_name == (*itr).uname)
        {
            cout << " Please enter New Password: ";
            cin >> n_pwd;
            (*itr).password = n_pwd;
            success = true;
        }
    }
    ofstream updateFile;
    updateFile.open("users.txt");
    if (success)
    {
        for (auto d : user)
        {
            updateFile << d.uname << "\t" << d.password << "\t" << d.role << endl;
        }
        cout << " ** Password updated !!!!\n";
        user.clear();
        main();
    }
    else
        cout << " Wrong username or username does not exist!\n";

    system("pause");
    system("CLS");
}
void admin()
{
    int n;
    string key;
    string data, line, user, pwd, role;
    ifstream userData("database.txt");

    cout << "1: See users\n2: Add to menu\n3: Change menu\n4: Remove an item\n5: Order food\n6: Exit\nChoice: ";
    cin >> n;
    switch (n)
    {
    case 1:
        while (userData >> user >> pwd >> role)
        {
            cout << user << " " << pwd << " " << role << "\n";
        }

        cout << "Press any key to go back to main menu: ";
        cin >> key;
        admin();
        system("cls");
        break;
    case 2:
        addMenu();
        break;
    case 3:
        change_menuList();
        break;
    case 4:
        remove_menuList();
        break;
    case 5:
        Select_MenuItems();
        break;
    case 6:
        exit(0);
        break;
    }
    userData.close();
    return admin();
}

void Select_MenuItems()
{
    int Useroption = -1; // variable for user choice in main menu screen.
    menuItems customerorder;
    ifstream readfile;
    readfile.open("menulist.txt", ios::in); // Opening menulist.txt file to read and scan for user menu choice.
    int order_itemNum, order_quantity = 0;
    string line, data;
    vector<string> orderdata;

    int isNotFinished = true; //loop to display menu and return user option back to switch case and run corresponding function.

    do {


        switch (Display_MainMenu()) // displays 6 menu options for user to choose from.
        {
        case 1:
            system("CLS");
            cout << "oo=======================================================================================oo" << endl;
            cout << "||     ||      ||    ||  ||\\\\   ||   ///\\\\\\  |||    |||  ||||||    ///\\\\\\   \\\\    //     ||" << endl;
            cout << "||     ||      ||    ||  || \\\\  ||  ||    ||  ||    ||   ||   ||  ||    ||   \\\\  //      ||" << endl;
            cout << "||     ||      ||    ||  ||  \\\\ ||  ||        ||||||||   |||||    ||    ||    >><<       ||" << endl;
            cout << "||     ||      ||    ||  ||   \\\\||  ||    ||  ||    ||   ||   ||  ||    ||   //  \\\\      ||" << endl;
            cout << "||     ||||||  ||||||||  ||    \\\\|   \\\\\\///  |||    |||  ||||||    \\\\\\///   //    \\\\     ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                      WARM MAINS                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||         **************             **************             **************          ||" << endl;
            cout << "||        * 1.BEEF BURGER*           *2.MAC & CHEESE*           * 3. LASAGNA   *         ||" << endl;
            cout << "||        *     $7.30    *           *    $7.20     *           *    $7.50     *         ||" << endl;
            cout << "||         **************             **************             **************          ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||       *****************          *****************            **************          ||" << endl;
            cout << "||      *4.AMERICAN HOTDOG*        *5.CHICKEN NOODLES*          *6.BBQ PORK BUN*         ||" << endl;
            cout << "||      *      $6.80      *        *      $6.80      *          *    $7.20     *         ||" << endl;
            cout << "||       *****************          *****************            **************          ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                    7. View Cart    8. Main Menu     9. Logout/Exit                    ||" << endl;
            cout << "oo=======================================================================================oo" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "                                Enter option number: "; cin >> order_itemNum;
            cout << "                                Enter Qty: "; cin >> order_quantity;

            customerorder.itemnumber = order_itemNum; // Takes user input and assigns to structure variable itemnumber.


            while (getline(readfile, line))// >> customerorder.itemnumber >> customerorder.itemname >> customerorder.price)
            {

                if (line.find(to_string(order_itemNum)) != string::npos) // If user order item number is found. Corresponding values are assigned to struct variables. 
                {
                    getline(readfile, line);

                    customerorder.itemname = line;
                    getline(readfile, line);

                    customerorder.price = stof(line);
                    cout << order_quantity << " " << customerorder.itemname << " $" << customerorder.price << " " << "Added to cart" << endl; // struct variables with values are printed here.
                    Add_toCart(order_quantity, customerorder.itemname, customerorder.price); // And then are passed on to this function to be saved to cartlist.txt file.
                    break;

                }
            }
            //readfile.close();
            break;
        case 2:
            system("CLS");
            cout << "oo=======================================================================================oo" << endl;
            cout << "||     ||      ||    ||  ||\\\\   ||   ///\\\\\\  |||    |||  ||||||    ///\\\\\\   \\\\    //     ||" << endl;
            cout << "||     ||      ||    ||  || \\\\  ||  ||    ||  ||    ||   ||   ||  ||    ||   \\\\  //      ||" << endl;
            cout << "||     ||      ||    ||  ||  \\\\ ||  ||        ||||||||   |||||    ||    ||    >><<       ||" << endl;
            cout << "||     ||      ||    ||  ||   \\\\||  ||    ||  ||    ||   ||   ||  ||    ||   //  \\\\      ||" << endl;
            cout << "||     ||||||  ||||||||  ||    \\\\|   \\\\\\///  |||    |||  ||||||    \\\\\\///   //    \\\\     ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                      COLD MAINS                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||         **************             **************             ***************         ||" << endl;
            cout << "||        * 7.MUNCH BOX  *           *8.GREEN SALAD *           *9.BEEF SANDWICH*        ||" << endl;
            cout << "||        *     $6.90    *           *    $5.20     *           *    $4.60      *        ||" << endl;
            cout << "||         **************             **************             ***************         ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||      ******************          *****************            ***************         ||" << endl;
            cout << "||     *10.CHICKEN SANDWICH*       *11.CHICKEN SALAD *          *12.TUNA SANDWICH*       ||" << endl;
            cout << "||     *      $4.60       *        *      $6.20      *          *    $4.60       *       ||" << endl;
            cout << "||      ******************          *****************            ***************         ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                    7. View Cart    8. Main Menu     9. Logout/Exit                    ||" << endl;
            cout << "oo=======================================================================================oo" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "                                Enter option number: "; cin >> order_itemNum;
            cout << "                                Enter Qty: "; cin >> order_quantity;

            customerorder.itemnumber = order_itemNum;


            while (getline(readfile, line))// >> customerorder.itemnumber >> customerorder.itemname >> customerorder.price)
            {

                if (line.find(to_string(order_itemNum)) != string::npos)
                {
                    getline(readfile, line);

                    customerorder.itemname = line;
                    getline(readfile, line);

                    customerorder.price = stof(line);
                    cout << order_quantity << " " << customerorder.itemname << " $" << customerorder.price << " " << "Added to cart" << endl;
                    Add_toCart(order_quantity, customerorder.itemname, customerorder.price);
                    break;

                }
            }
            readfile.close();
            break;
        case 3:
            system("CLS");
            cout << "oo=======================================================================================oo" << endl;
            cout << "||     ||      ||    ||  ||\\\\   ||   ///\\\\\\  |||    |||  ||||||    ///\\\\\\   \\\\    //     ||" << endl;
            cout << "||     ||      ||    ||  || \\\\  ||  ||    ||  ||    ||   ||   ||  ||    ||   \\\\  //      ||" << endl;
            cout << "||     ||      ||    ||  ||  \\\\ ||  ||        ||||||||   |||||    ||    ||    >><<       ||" << endl;
            cout << "||     ||      ||    ||  ||   \\\\||  ||    ||  ||    ||   ||   ||  ||    ||   //  \\\\      ||" << endl;
            cout << "||     ||||||  ||||||||  ||    \\\\|   \\\\\\///  |||    |||  ||||||    \\\\\\///   //    \\\\     ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                       DRINKS                                          ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||         **************             **************             ***************         ||" << endl;
            cout << "||        *13.SPRING WATER*          *14.ORANGE JUICE*          *   15. MILK    *        ||" << endl;
            cout << "||        *     $3.00    *           *    $3.80     *           *    $3.50      *        ||" << endl;
            cout << "||         **************             **************             ***************         ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                    7. View Cart    8. Main Menu     9. Logout/Exit                    ||" << endl;
            cout << "oo=======================================================================================oo" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "                                Enter option number: "; cin >> order_itemNum;
            cout << "                                Enter Qty: "; cin >> order_quantity;

            customerorder.itemnumber = order_itemNum;


            while (getline(readfile, line))// >> customerorder.itemnumber >> customerorder.itemname >> customerorder.price)
            {

                if (line.find(to_string(order_itemNum)) != string::npos)
                {
                    getline(readfile, line);

                    customerorder.itemname = line;
                    getline(readfile, line);

                    customerorder.price = stof(line);
                    cout << order_quantity << " " << customerorder.itemname << " $" << customerorder.price << " " << "Added to cart" << endl;
                    Add_toCart(order_quantity, customerorder.itemname, customerorder.price);
                    break;

                }
            }
            readfile.close();

            break;
        case 4:
            system("CLS");
            cout << "oo=======================================================================================oo" << endl;
            cout << "||     ||      ||    ||  ||\\\\   ||   ///\\\\\\  |||    |||  ||||||    ///\\\\\\   \\\\    //     ||" << endl;
            cout << "||     ||      ||    ||  || \\\\  ||  ||    ||  ||    ||   ||   ||  ||    ||   \\\\  //      ||" << endl;
            cout << "||     ||      ||    ||  ||  \\\\ ||  ||        ||||||||   |||||    ||    ||    >><<       ||" << endl;
            cout << "||     ||      ||    ||  ||   \\\\||  ||    ||  ||    ||   ||   ||  ||    ||   //  \\\\      ||" << endl;
            cout << "||     ||||||  ||||||||  ||    \\\\|   \\\\\\///  |||    |||  ||||||    \\\\\\///   //    \\\\     ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                        SUSHI                                          ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||         **************           *****************            ****************        ||" << endl;
            cout << "||        *16.TUNA ONIGIRI*        *17.CHICKEN ONIGIRI*        *18.SALMON AVOCADO*       ||" << endl;
            cout << "||        *     $4.50    *         *      $4.50       *          *    $8.20      *       ||" << endl;
            cout << "||         **************           *****************            ****************        ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||      ******************          *****************            ***************         ||" << endl;
            cout << "||     *19.CHICKEN AVOCADO *       *20.FRIED CHICKEN *          *21.TUNA AVOCADO *       ||" << endl;
            cout << "||     *      $8.20       *        *      $8.20      *          *    $8.20       *       ||" << endl;
            cout << "||      ******************          *****************            ***************         ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                    7. View Cart    8. Main Menu     9. Logout/Exit                    ||" << endl;
            cout << "oo=======================================================================================oo" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "                                Enter option number: "; cin >> order_itemNum;
            cout << "                                Enter Qty: "; cin >> order_quantity;

            customerorder.itemnumber = order_itemNum;


            while (getline(readfile, line))// >> customerorder.itemnumber >> customerorder.itemname >> customerorder.price)
            {

                if (line.find(to_string(order_itemNum)) != string::npos)
                {
                    getline(readfile, line);

                    customerorder.itemname = line;
                    getline(readfile, line);

                    customerorder.price = stof(line);
                    cout << order_quantity << " " << customerorder.itemname << " $" << customerorder.price << " " << "Added to cart" << endl;
                    Add_toCart(order_quantity, customerorder.itemname, customerorder.price);
                    break;

                }
            }
            readfile.close();
            break;
        case 5:
            system("CLS");
            cout << "oo=======================================================================================oo" << endl;
            cout << "||     ||      ||    ||  ||\\\\   ||   ///\\\\\\  |||    |||  ||||||    ///\\\\\\   \\\\    //     ||" << endl;
            cout << "||     ||      ||    ||  || \\\\  ||  ||    ||  ||    ||   ||   ||  ||    ||   \\\\  //      ||" << endl;
            cout << "||     ||      ||    ||  ||  \\\\ ||  ||        ||||||||   |||||    ||    ||    >><<       ||" << endl;
            cout << "||     ||      ||    ||  ||   \\\\||  ||    ||  ||    ||   ||   ||  ||    ||   //  \\\\      ||" << endl;
            cout << "||     ||||||  ||||||||  ||    \\\\|   \\\\\\///  |||    |||  ||||||    \\\\\\///   //    \\\\     ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                     VALUE PACKS                                       ||" << endl;
            cout << "||                               (Comes with fruit juice)                                ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||        ****************         **********************        *****************       ||" << endl;
            cout << "||       *22.Sausage roll *       * 23.Vegemite Sandich  *      *24.HAM PIZZA BREAD*     ||" << endl;
            cout << "||       *Popcorn & Apple *       *Popcorn & Blackcurrant*      * Popcorn & Apple  *     ||" << endl;
            cout << "||       *     $6.70      *       *        $7.00         *      *      $7.30       *     ||" << endl;
            cout << "||        ****************         **********************        *****************       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                 **********************                                ||" << endl;
            cout << "||                                * 25.VEGE PIZZA BREAD  *                               ||" << endl;
            cout << "||                                *Popcorn & Blackcurrant*                               ||" << endl;
            cout << "||                                *        $7.00         *                               ||" << endl;
            cout << "||                                 **********************                                ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                    7. View Cart    8. Main Menu     9. Logout/Exit                    ||" << endl;
            cout << "oo=======================================================================================oo" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "                                Enter option number: "; cin >> order_itemNum;
            cout << "                                Enter Qty: "; cin >> order_quantity;

            customerorder.itemnumber = order_itemNum;


            while (getline(readfile, line))// >> customerorder.itemnumber >> customerorder.itemname >> customerorder.price)
            {

                if (line.find(to_string(order_itemNum)) != string::npos)
                {
                    getline(readfile, line);

                    customerorder.itemname = line;
                    getline(readfile, line);

                    customerorder.price = stof(line);
                    cout << order_quantity << " " << customerorder.itemname << " $" << customerorder.price << " " << "Added to cart" << endl;
                    Add_toCart(order_quantity, customerorder.itemname, customerorder.price);
                    break;

                }
            }
            readfile.close();
            break;
        case 6:
            system("CLS");
            cout << "oo=======================================================================================oo" << endl;
            cout << "||     ||      ||    ||  ||\\\\   ||   ///\\\\\\  |||    |||  ||||||    ///\\\\\\   \\\\    //     ||" << endl;
            cout << "||     ||      ||    ||  || \\\\  ||  ||    ||  ||    ||   ||   ||  ||    ||   \\\\  //      ||" << endl;
            cout << "||     ||      ||    ||  ||  \\\\ ||  ||        ||||||||   |||||    ||    ||    >><<       ||" << endl;
            cout << "||     ||      ||    ||  ||   \\\\||  ||    ||  ||    ||   ||   ||  ||    ||   //  \\\\      ||" << endl;
            cout << "||     ||||||  ||||||||  ||    \\\\|   \\\\\\///  |||    |||  ||||||    \\\\\\///   //    \\\\     ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                  SNACKS & DESSERTS                                    ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||         **************           *****************            ****************        ||" << endl;
            cout << "||        *26.CHOC MUFFIN*         *27.CHOC BROWNIE  *          *28.FRUIT SALAD  *       ||" << endl;
            cout << "||        *     $2.60    *         *      $3.00      *          *     $5.20      *       ||" << endl;
            cout << "||         **************           *****************            ****************        ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||         ***************          *****************            ***************         ||" << endl;
            cout << "||        *   29.APPLE    *        *   30.BANANA     *          * 31.POP CORN   *        ||" << endl;
            cout << "||        *     $1.70     *        *      $1.90      *          *    $1.50      *        ||" << endl;
            cout << "||         ***************          *****************            ***************         ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "||                    7. View Cart    8. Main Menu     9. Logout/Exit                    ||" << endl;
            cout << "oo=======================================================================================oo" << endl;
            cout << "||                                                                                       ||" << endl;
            cout << "                                Enter option number: "; cin >> order_itemNum;
            cout << "                                Enter Qty: "; cin >> order_quantity;

            customerorder.itemnumber = order_itemNum;


            while (getline(readfile, line))// >> customerorder.itemnumber >> customerorder.itemname >> customerorder.price)
            {

                if (line.find(to_string(order_itemNum)) != string::npos)
                {
                    getline(readfile, line);

                    customerorder.itemname = line;
                    getline(readfile, line);

                    customerorder.price = stof(line);
                    cout << order_quantity << " " << customerorder.itemname << " $" << customerorder.price << " " << "Added to cart" << endl;
                    Add_toCart(order_quantity, customerorder.itemname, customerorder.price);
                    break;

                }
            }
            readfile.close();
            break;
        case 7:
            system("CLS");
            view_cart();
            break;
        case 8:
            system("CLS");
            change_menuList();
            break;
        case 9:
            system("CLS");
            remove_menuList();

        case 10:
            isNotFinished = false;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
            break;
        }

    } while (isNotFinished);
}

int Display_MainMenu()
{
    int UserOption = -1;

    cout << "oo=======================================================================================oo" << endl;
    cout << "||     ||      ||    ||  ||\\\\   ||   ///\\\\\\  |||    |||  ||||||    ///\\\\\\   \\\\    //     ||" << endl;
    cout << "||     ||      ||    ||  || \\\\  ||  ||    ||  ||    ||   ||   ||  ||    ||   \\\\  //      ||" << endl;
    cout << "||     ||      ||    ||  ||  \\\\ ||  ||        ||||||||   |||||    ||    ||    >><<       ||" << endl;
    cout << "||     ||      ||    ||  ||   \\\\||  ||    ||  ||    ||   ||   ||  ||    ||   //  \\\\      ||" << endl;
    cout << "||     ||||||  ||||||||  ||    \\\\|   \\\\\\///  |||    |||  ||||||    \\\\\\///   //    \\\\     ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                                      MAIN MENU                                        ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||         **************             **************             **************          ||" << endl;
    cout << "||        * 1.WARM MAINS *           * 2.COLD MAINS *           * 3. DRINKS    *         ||" << endl;
    cout << "||         **************             **************             **************          ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||         **************             **************             **************          ||" << endl;
    cout << "||        * 4. SUSHI     *           * 5.VALUE PACKS*           * 6. SNACKS    *         ||" << endl;
    cout << "||         **************             **************             **************          ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                 7. View Cart        8. Add items         9. Logout/Exit               ||" << endl;
    cout << "oo=======================================================================================oo" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                               Enter option 1 - 9: ", cin >> UserOption;
    cout << "||                                                                                       ||" << endl;
    cout << "oo=======================================================================================oo" << endl;
    return UserOption;
}

void addMenu()
{
    menuItems menulist;
    ofstream infile;
    infile.open("menulist.txt", ios::app);
    int list_itemnumber;
    string list_itemname;
    float list_price;
    char choice;

    do
    {
        cin.ignore();
        cout << "\n Enter item number: ";
        cin >> list_itemnumber;
        cin.ignore();
        cout << "\n Enter item name: ";
        getline(cin, list_itemname);
        cout << "\n Enter item price: ";
        cin >> list_price;
        menulist.itemnumber = list_itemnumber;
        menulist.itemname = list_itemname;
        menulist.price = list_price;
        menu.push_back(menulist);
        cout << "\nDo you wish to enter more items? (y/n): ";
        cin >> choice;

    } while (choice != 'n');
    for (auto data : menu)
        infile << data.itemnumber << "\n" << data.itemname << "\n" << data.price << endl;
    menu.clear();

}

void Display_menuList()
{
    ifstream outfile;
    outfile.open("menulist.txt", ios::in);
    string line;
    while (getline(outfile, line))
    {
        cout << line << endl;



    }

    outfile.close();

}

void Add_toCart(int qty, string name, float price)
{
    orderItems ordercopy;
    ofstream copyto;
    copyto.open("cartlist.txt", ios::app);
    ordercopy.orderqty = qty;
    ordercopy.ordername = name;
    ordercopy.orderprice = price;
    order.push_back(ordercopy);
    for (auto data : order)
        copyto << data.orderqty << "\n" << data.ordername << "\n" << data.orderprice << endl;
    order.clear();

}

void view_cart()
{
    double sum = 0;
    ifstream viewcart;
    viewcart.open("cartlist.txt", ios::in);
    string line;
    string qty, name, price;
    char choice;

    cout << "oo=======================================================================================oo" << endl;
    cout << "||     ||      ||    ||  ||\\\\   ||   ///\\\\\\  |||    |||  ||||||    ///\\\\\\   \\\\    //     ||" << endl;
    cout << "||     ||      ||    ||  || \\\\  ||  ||    ||  ||    ||   ||   ||  ||    ||   \\\\  //      ||" << endl;
    cout << "||     ||      ||    ||  ||  \\\\ ||  ||        ||||||||   |||||    ||    ||    >><<       ||" << endl;
    cout << "||     ||      ||    ||  ||   \\\\||  ||    ||  ||    ||   ||   ||  ||    ||   //  \\\\      ||" << endl;
    cout << "||     ||||||  ||||||||  ||    \\\\|   \\\\\\///  |||    |||  ||||||    \\\\\\///   //    \\\\     ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||                                       MY CART                                         ||" << endl;
    cout << "||                                                                                       ||" << endl;
    cout << "||\t\t\t\t" << "Qty: " << "\t " << "Item: " << "\t\t" << "Price: \t\t\t\t ||\n";

    while (getline(viewcart, line)) // loop to display items as Qty << itemname << itemprice.
    {
        cout << "||\t\t\t\t" << " " << line << "\t";

        getline(viewcart, line);

        cout << " " << line << "\t";

        getline(viewcart, line);

        cout << "$" << line << "\t\t\t\t || " << endl;


    }
    cout << "||                                                                                       ||" << endl;
    cout << "||                   1. Make Payment    2. Change Qty     3. Main Menu                   ||" << endl;
    cout << "oo=======================================================================================oo" << endl;
    cout << "                                Enter option number: "; cin >> choice;

    switch (choice) // takes user choice and go to corresponding function.
    {
    case '1':
        make_payment();
        break;
    case '2':
        change_qty();
        break;
    case '3':
        Select_MenuItems();
        break;
    default:
        cout << "Invalid option! Try again." << endl;
        break;
    }


    viewcart.close();


}

void change_menuList()
{
    menuItems menulist;
    vector<menuItems> filedata;
    int list_itemnumber;
    string list_itemname, n_item, n_price, line, data;
    float list_price = 0;
    bool success = false;

    ifstream menuList;
    menuList.open("menulist.txt", ios::in);

    while (getline(menuList, line))
    {
        menulist.itemnumber = stoi(line);
        getline(menuList, line);
        menulist.itemname = line;
        getline(menuList, line);
        menulist.price = stof(line);
        filedata.push_back(menulist);
    }

    cout << "\n Enter item number: ";
    cin >> list_itemnumber;

    menuList.close();

    vector<menuItems>::iterator itr;

    for (itr = filedata.begin(); itr != filedata.end(); itr++)
    {
        if (list_itemnumber == (*itr).itemnumber)
        {
            cout << "\nPlease enter new item: ";
            cin >> n_item;
            (*itr).itemname = n_item;

            cout << "\nPlease enter new price: ";
            cin >> n_price;
            (*itr).price = stof(n_price);
            success = true;            //change success status when password is changed

        }
    }


    ofstream updateFile;
    updateFile.open("menulist.txt");
    for (auto data : filedata)
    {
        updateFile << data.itemnumber << "\n" << data.itemname << "\n" << data.price << endl;
    }
    cout << " ** Password updated !!!!\n";
    filedata.clear();

    updateFile.close();
}

void remove_menuList()
{
    menuItems menulist;
    vector<menuItems> menudata;
    int list_itemnumber;
    string list_itemname, n_item, n_price, line, data;
    float list_price = 0;
    bool success = false;

    ifstream menuList;
    menuList.open("menulist.txt", ios::in);

    while (getline(menuList, line))
    {
        menulist.itemnumber = stoi(line);
        getline(menuList, line);
        menulist.itemname = line;
        getline(menuList, line);
        menulist.price = stof(line);
        menudata.push_back(menulist);
    }

    cout << "\n Enter item number: ";
    cin >> list_itemnumber;

    menuList.close();

    vector<menuItems>::iterator itr;

    for (itr = menudata.begin(); itr != menudata.end(); itr++)
    {
        if (list_itemnumber == (*itr).itemnumber)
        {
            menudata.begin(); menudata.erase(itr);
            success = true;

        }
    }


    ofstream updateFile;
    updateFile.open("menulist.txt");
    for (auto data : menudata)
    {
        updateFile << data.itemnumber << "\n" << data.itemname << "\n" << data.price << endl;
    }
    cout << " ** Menu updated !!!!\n";
    menudata.clear();

    updateFile.close();

}

void change_qty()
{
    orderItems orderlist;
    vector<orderItems> orderdata;
    string order_itemname, order_qty, line;
    bool success = false;

    ifstream orderlistfile;
    orderlistfile.open("cartlist.txt");

    while (getline(orderlistfile, line))
    {
        orderlist.orderqty = stoi(line);
        getline(orderlistfile, line);
        orderlist.ordername = line;
        getline(orderlistfile, line);
        orderlist.orderprice = stof(line);
        orderdata.push_back(orderlist);
    }

    cout << "\n Enter item to change qty: ";
    cin >> order_itemname;

    orderlistfile.close();

    vector<orderItems>::iterator itr;

    for (itr = orderdata.begin(); itr != orderdata.end(); itr++)
    {
        if (order_itemname == (*itr).ordername)
        {
            cout << "\nPlease enter new qty: ";
            cin >> order_qty;
            (*itr).orderqty = stoi(order_qty);
            success = true;            //change success status when password is changed

        }
    }

    ofstream updateFile;
    updateFile.open("cartlist.txt");
    for (auto data : orderdata)
    {
        updateFile << data.orderqty << "\n" << data.ordername << "\n" << data.orderprice << endl;
    }
    cout << " ** Qty updated !!!!\n";
    orderdata.clear();

    updateFile.close();
}

void make_payment()
{
    float sum = 0;
    int ch;
    orderItems order_payment;
    vector <orderItems> payment_data;
    string line, item_name;
    int item_qty;
    float item_price;
    ifstream payment_total;
    payment_total.open("cartlist.txt", ios::in);

    while (getline(payment_total, line))
    {
        order_payment.orderqty = stoi(line);
        getline(payment_total, line);
        order_payment.ordername = line;
        getline(payment_total, line);
        order_payment.orderprice = stof(line);
        payment_data.push_back(order_payment);
    }

    payment_total.close();

    vector<orderItems>::iterator itr;

    for (itr = payment_data.begin(); itr != payment_data.end(); itr++)
    {
        cout << "\n\t\t" << (*itr).orderqty << "\t" << (*itr).ordername << "\t   " << "$" << (*itr).orderprice << endl;
        sum += (*itr).orderprice;


    }
    cout << "\n\n\n\t\t\t\tTotal = " << "$" << sum;

    cout << "\n\n\t\t\t\t    Payment type: " << endl;
    cout << "\t\t\t       1: Cash\n\t\t\t       2: Efpos";
    cout << "\n\t\t\t       Choice: ";
    cin >> ch;
    if (ch == 1 || 2)
    {
        receipt();
        exit(0);
        system("cls");
    }
    else
    {
        cout << "Invalid!! Please enter 1 or 2";
    }

}
void receipt()
{
    int ch;
    float sum = 0;
    orderItems order_payment;
    vector <orderItems> payment_data;
    string line, item_name;
    int item_qty;
    float item_price;
    ifstream payment_total;
    payment_total.open("cartlist.txt", ios::in);

    while (getline(payment_total, line))
    {
        order_payment.orderqty = stoi(line);
        getline(payment_total, line);
        order_payment.ordername = line;
        getline(payment_total, line);
        order_payment.orderprice = stof(line);
        payment_data.push_back(order_payment);
    }

    payment_total.close();

    vector<orderItems>::iterator itr;




    char title[20] = "LunchBox";
    srand((unsigned)time(NULL));
    int random = rand();

    system("cls");
    ofstream fout("receipt.txt");
    cout << "\n\t";

    for (int i = 0; i < 45; i++)
    {
        cout << "_";
    }

    cout << endl;
    cout << "\n\t\t\tConfirmation\n";
    cout << "\t\t   _____________________\n";
    cout << "\n\t\t     TITLE..." << title << "\n";

    cout << "\n\n\t\t  Order NO..........." << random << "\n\n";

    cout << "\n\t  Date and Time........" << __DATE__ << " " << __TIME__ "\n";

    for (itr = payment_data.begin(); itr != payment_data.end(); itr++)
    {
        cout << "\n\t\t" << (*itr).orderqty << "\t" << (*itr).ordername << "\t   " << "$" << (*itr).orderprice << endl;
        sum += (*itr).orderprice;


    }
    cout << "\n\t\t\tTotal = " << "$" << sum;
    cout << "\n\n\t\t >>Thank You For Visiting<<\n";

    cout << "\t______________________________________________";


    cout << "\n\t\t\t " << "\n";

}

