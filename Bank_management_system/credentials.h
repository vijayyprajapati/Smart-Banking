
#include<bits/stdc++.h>
#include"saveing.h"
using namespace saveing;
using namespace std;

namespace credentials
{
    class Credentials  // credentials class
    {
        string password;  // to store password
        string username; // to store  username
        public:
        void Register();
        void Login();
        void main_page();
    };
    
    void Credentials :: Login() // Login method
    {
        cout<<endl;
        cout<<endl;
        ifstream ifs;
        ifs.open("credentials.txt"); // open file to get password.
        ifstream ifs1;
        ifs1.open("credentials1.txt"); // open file to get username.

    cout<<"                             WELCOME TO LOGIN PAGE PLEASE LOGIN YOURSELF."<<endl;
    cout<<endl;
    cout<<"                                        DATE : "<<__DATE__ <<endl; 
    cout<<endl; 
        string uname , pword;
        cout<<"                                    Enter your Username :- ";
                                                   cin>>uname;
        cout<<"                                    Enter your Password :- ";
                                                   cin>>pword; 
        cout<<endl;
        string u , p; // storing password and username fronm file.
        bool check; // checking for correct username and password.
        while(ifs,ifs1)  // seraching password upto end of file
        {
            ifs>>p; // geting password from file.
            ifs1>>u; // geting username from file.
            if(p.compare(pword)==0 && u.compare(uname)==0)  // compareing of stored password and entered password.
            {
                check = true;  // flag variable
            }
        }
        ifs.close();
        ifs1.close();
        if(check==true)  // if password match 
        {
            cout<<"                                     Your Login is successful."<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"                             WELCOME TO SAVEING ACCOUNT OPENING PAGE"<<endl;
            cout<<endl;
            cout<<"                                       DATE : "<<__DATE__ <<endl; 
            saveing::landing_page();
        }
        else // if password does not match.
        {
            cout<<"                                    Your Login is unsuccessful please provide correct username and password."<<endl;
            Login();
        }
    }
    void Credentials :: Register() // register method
    {
        cout<<endl;
        cout<<"                     WELCOME TO REGISTER PAGE PLEASE REGISTER YOURSELF."<<endl;
        cout<<endl;
        ofstream ofs("credentials.txt", ios::app); // Use file to store passwoed parmanentaily.
        ofstream ofs1("credentials1.txt",ios::app);  // use file to store username parmanently.
        cout<<"                               Enter Username :- ";
                                              cin>>username;
        cout<<"                               Enter Password :- ";
                                              cin>>password;
                                              cout<<endl;
        cout<<"                               Your Registreation is sucessful"<<endl;
        cout<<"                               Please remember your username and password."<<endl;
        ofs<<password<<endl;
        ofs1<<username<<endl;
        ofs.close(); // close file
        ofs1.close(); // close file
        main_page();
    }
    void Credentials :: main_page()  // main page method.
    {
        cout<<endl;
        cout<<endl;
        int choice =0;
        cout<<"Press 1 to Register."<<endl;
        cout<<"Press 2 to Login."<<endl;
        cout<<"Press 3 to Exit."<<endl;
        cout<<endl;
        while(choice != 3)
        {
            cout<<"      Enter your Choice :- ";
                         cin>>choice;
                         cout<<endl;
            switch(choice)
            {
                case 1:
                    Register();
                    break;
                case 2:
                    Login();
                    break;
                case 3:
                cout<<endl;
                cout<<"                                                                 THANK YOU FOR VISITING"<<endl;
                exit(0);
                default:
                    cout<<"      Please enter correct choice."<<endl;
                    main_page();
            }
        }
    }
} // namespace credentials
