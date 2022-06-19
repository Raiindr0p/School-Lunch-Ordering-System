#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void login();
void registr();
void change();

struct student
{
    string stat;
};
struct users
{
    string uname, password, role;
};

vector<users> user;

int main()
{
    int choice;
    cout << "*************************************************" << endl;
    cout << "******************* Welcome *********************" << endl;
    cout << "Menu: " << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Change Password" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;
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
    string u_name, pwd, role, line, data;
    int ch;
    bool rego = true;

    cout << "\n Select your role\t"
        << "1: Student\t 2: Teacher\t 3: Admin :  ";
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
        else if (ch == 1)
        {
            role = "teacher";
            cout << "\n Teacher Registration Successful!!\n";
        }
        else
        {
            role = "admin";
            cout << "\n Admin Registration Successful!!\n";
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