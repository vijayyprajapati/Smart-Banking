
#include <bits/stdc++.h>
using namespace std;
namespace saveing
{
    #define MIN_BALANCE 1000
    class saveing_Account
    {
    private:
        long accountNumber;
        string firstName;
        string lastName;
        float balance;
        static int NextAccountNumber;

    public:
        saveing_Account() {}  // Non perametrized Constructor of class Account
        saveing_Account(string fname, string lname, float balance);  // Parametrized Constructor of class Account.
        long getAccNo() { return accountNumber; }  //Accessor membor function.
        string getFirstName() { return firstName; }  //Accessor membor function.
        string getLastName() { return lastName; }  //Accessor membor function.
        float getBalance() { return balance; }  //Accessor membor function.

        void Deposit(float amount);  // faclitator member function. 
        void Withdraw(float amount);  // faclitator member function.
        static void setLastAccountNumber(long accountNumber); //mutator member function.
        static long getLastAccountNumber(); //mutator member function.
        friend ofstream &operator<<(ofstream &, saveing_Account &); // serialization. 
        friend ifstream &operator>>(ifstream &, saveing_Account &); // serialization.
        friend ostream &operator<<(ostream &, saveing_Account &); // serialization.
    };
    int saveing_Account::NextAccountNumber = 0;
    class Bank
    {
    private:
        map<long, saveing_Account> accounts;

    public:
        Bank();
        saveing_Account OpenAccount(string fname, string lname, float balance);
        saveing_Account BalanceEnquiry(long accountNumber);
        saveing_Account Deposit(long accountNumber, float amount);
        saveing_Account Withdraw(long accountNumber, float amount);
        void CloseAccount(long accountNumber);
        void ShowAllAccounts();
        ~Bank();
    };

    //  Defination of all member function.
    saveing_Account::saveing_Account(string fname, string lname, float balance)
    {
        NextAccountNumber++;
        accountNumber = NextAccountNumber;
        firstName = fname;
        lastName = lname;
        this->balance = balance;
    }
    void saveing_Account::Deposit(float amount)
    {
        balance += amount;
    }
    void saveing_Account::Withdraw(float amount)
    {
        balance -= amount;
    }
    void saveing_Account::setLastAccountNumber(long accountNumber)
    {
        NextAccountNumber = accountNumber;
    }
    long saveing_Account::getLastAccountNumber()
    {
        return NextAccountNumber;
    }
    ofstream &operator<<(ofstream &ofs, saveing_Account &sacc)
    {
        ofs <<"                                                            "<<sacc.accountNumber << endl;
        ofs <<"                                                            "<<sacc.firstName << endl;
        ofs <<"                                                            "<<sacc.lastName << endl;
        ofs <<"                                                            "<<sacc.balance << endl;
        return ofs;
    }
    ifstream &operator>>(ifstream &ifs, saveing_Account &sacc)
    {
        ifs >> sacc.accountNumber;
        ifs >> sacc.firstName;
        ifs >> sacc.lastName;
        ifs >> sacc.balance;
        return ifs;
    }
    ostream &operator<<(ostream &os, saveing_Account &sacc)
    {
        cout<<endl;
        cout<<"                                                  Account detail are:-"<<endl;
        os <<"                                                             First Name:" << sacc.getFirstName() << endl;
        os <<"                                                             Last Name:" << sacc.getLastName() << endl;
        os <<"                                                             Account Number:" << sacc.getAccNo() << endl;
        os <<"                                                             Balance:" << sacc.getBalance() << endl;
        return os;
    }
    Bank::Bank()
    {

        saveing_Account account;
        ifstream infile;
        infile.open("bank.txt");
        if (!infile)
        {
            cout<<"File is not open"<<endl;
            return;
        }
        while (infile)
        {
            infile >> account;
            accounts.insert(pair<long, saveing_Account>(account.getAccNo(), account));
        }
        saveing_Account::setLastAccountNumber(account.getAccNo());

        infile.close();
    }
    saveing_Account Bank::OpenAccount(string fname, string lname, float balance)
    {
        ofstream outfile;
        saveing_Account account(fname, lname, balance);
        accounts.insert(pair<long, saveing_Account>(account.getAccNo(), account));

        outfile.open("bank.txt", ios::trunc);

        map<long, saveing_Account>::iterator itr;
        for (itr = accounts.begin(); itr != accounts.end(); itr++)
        {
            outfile<<itr->second;
        }
        outfile.close();
        return account;
    }
    saveing_Account Bank::BalanceEnquiry(long accountNumber)
    {
        map<long, saveing_Account>::iterator itr = accounts.find(accountNumber);
        return itr->second;
    }
    saveing_Account Bank::Deposit(long accountNumber, float amount)
    {
        map<long, saveing_Account>::iterator itr = accounts.find(accountNumber);
        itr->second.Deposit(amount);
        return itr->second;
    }
    saveing_Account Bank::Withdraw(long accountNumber, float amount)
    {
        map<long, saveing_Account>::iterator itr = accounts.find(accountNumber);
        itr->second.Withdraw(amount);
        return itr->second;
    }
    void Bank::CloseAccount(long accountNumber)
    {
        
        map<long, saveing_Account>::iterator itr = accounts.find(accountNumber);
        cout <<"                                                       Account Deleted" << itr->second;
        accounts.erase(accountNumber);
    }
    void Bank::ShowAllAccounts()
    {
        map<long, saveing_Account>::iterator itr;
        for (itr = accounts.begin(); itr != accounts.end(); itr++)
        {
            cout <<"                                                  Account " << itr->first << endl<< itr->second << endl;
        }
    } Bank::~Bank()
    {
        ofstream outfile;
        outfile.open("bank.txt", ios::trunc);

        map<long, saveing_Account>::iterator itr;
        for (itr = accounts.begin(); itr != accounts.end(); itr++)
        {
            outfile<<itr->second;
        }
        outfile.close();
    }

    // End of defination of all member function.
     
    void landing_page() // Landing page method.
    {
        Bank b;
        saveing_Account acc;

        int choice;
        string fname, lname;
        long accountNumber;
        float balance;
        float amount;
        while(choice != 7)
        {
            cout<<endl;
            cout<<endl;
            
            cout<<"                                     Press 1 to Open an Account."<<endl;
            cout<<"                                     Press 2 for Balance Enquiry."<<endl;
            cout<<"                                     Press 3 for Deposit."<<endl;
            cout<<"                                     Press 4 to Withdrawal."<<endl;
            cout<<"                                     Press 5 to Close an Account."<<endl;
            cout<<"                                     Press 6 to Show All Accounts."<<endl;
            cout<<"                                     Press 7 to Exit."<<endl;
                                                        cout<<endl;
        cout<<"                                                  Enter your choice: ";
                                                                 cin>>choice;
                                                                 cout<<endl;
            switch (choice)
            {
            case 1:
                cout<<"                                                       Enter First Name: ";
                                                                              cin>>fname;
                cout<<"                                                       Enter Last Name: ";
                                                                              cin>>lname;
                cout<<"                                                       Enter initil Balance: ";
                                                                              cin>>balance;
                acc = b.OpenAccount(fname, lname, balance);
                cout<<"                                                       Congradulation Account is Created."<<endl;
                cout<<endl;
                cout <<acc;
                break;
            case 2:
                cout<<"                                                       Enter Account Number: ";
                                                                              cin>>accountNumber;
                acc = b.BalanceEnquiry(accountNumber);
                // cout<<"                                                       Your Account Details" << endl;
                cout<<acc;
                break;
            case 3:
                cout<<"                                                       Enter Account Number: ";
                                                                              cin>>accountNumber;
                cout<<"                                                       Enter Balance: ";
                                                                              cin>>amount;
                acc = b.Deposit(accountNumber, amount);
                cout<<"                                                       Amount is Deposited." << endl;
                cout<<acc;
                break;
            case 4:
                cout<<"                                                       Enter Account Number: ";
                                                                              cin>>accountNumber;
                cout<<"                                                       Enter Balance: ";
                                                                              cin>>amount;
                acc = b.Withdraw(accountNumber, amount);
                cout<<"                                                       Amount Withdrawn." << endl;
                cout<<acc;
                break;
            case 5:
                cout<<"                                                       Enter Account Number: ";
                                                                              cin>>accountNumber;
                b.CloseAccount(accountNumber);
                cout<<"                                                       Account is Closed." <<endl;
                cout<<acc;
            case 6:
                b.ShowAllAccounts();
                break;
            case 7:
                cout<<"                                                                 THANK YOU FOR VISITING"<<endl;
                exit(0);
                break;
            default:
                cout<<"                                                       Enter correct choice"<<endl;
                landing_page();
            }
        } 
    }
    
}