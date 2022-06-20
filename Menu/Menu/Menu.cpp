// Testing console 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

int Display_MainMenu(); // main menu display.

// functions to manage items in menu. Admin access only.
void addMenu();
void change_menuList();
void remove_menuList();
void Display_menuList();

void Add_toCart(int, string, float); // copy function from user input and pass values to function and save to cartlist.txt file. 
void view_cart(); // function to view cart. Reads cartlist.txt file.
void change_qty(); // function to change order qty.



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
            readfile.close();
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
    cout << "||\t\t\t\t" << "Qty: " << "\t " << "Item " << "\t\t" << "Price: \t\t\t\t ||\n";

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
    case 1:
        cout << "This is where payment function will be: \n";
        break;
    case 2:
        cout << "This is where change Qty function will be: \n";
        break;
    case 3:
        Display_MainMenu();
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

    for (itr = menudata.begin(); itr != menudata.erase(itr); itr++)
    {
        if (list_itemnumber == (*itr).itemnumber)
        {

            success = true;            //change success status when password is changed

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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

