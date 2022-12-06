#include<iostream>
#include <time.h>
#include"credentials.h"
using namespace credentials;
using namespace std;



int main()
{

    cout<<endl;
    cout<<"                                                           WELCOME TO BANKING MANAGEMENT SYSTEM "<<endl;
    cout<<endl;
    cout<<"                                                                    DATE : "<< __DATE__<<endl;
    Credentials c;
    c.main_page();
}