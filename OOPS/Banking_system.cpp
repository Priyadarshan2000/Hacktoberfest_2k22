#include <iostream>
#include<iomanip>
using namespace std;
class Bank
{
    char acctype[30];  //Account type
    int accno;        //account number
    int bal;          // balance
    char name[30];    //name of Depositer
    public:
    void OPbalance(void);
    void Deposit(void);
    void Withdraw(void);
    void Display(void);
};
void Bank::OPbalance(void)
{
    cout<<"ENTER THE DEPOSITER NAME:"<<endl;
    cin>>name;
    cout<<"ENTER THE ACCOUNT NUMBER :"<<endl;
    cin>>accno;
    cout<<"ENTER THE ACCOUNT TYPE (LIKE SAVING,CURRENT,BANKING..ECT):"<<endl;
    cin>>acctype;
    cout<<"ENTER THE AMOUNT FOR OPENING BALANCE :"<<endl;
    cin>>bal;
}
void Bank::Deposit(void)
{
    int deposit=0;
    cout<<"ENTER THE AMOUNT YOU WANT TO DEPOSIT :"<<endl;
    cin>>deposit;
    bal=deposit+bal;
    cout<<"AFTER DEPSOIT YOUR TOTAL BALANCE ARE :\t"<<bal<<endl;
}
void Bank::Withdraw(void)
{
    int minmumbal=1000;
    int withdraw;
    cout<<"TOTAL AVAILABLE AMOUNT ARE: "<<bal<<endl;
    cout<<"ENTER THE AMOUNT YOU WANT TO WITHDRAW: "<<endl;
    cin>>withdraw;
    if(bal>withdraw&& bal>minmumbal)
    {
        bal=bal-withdraw;
        cout<<"AFTER THE WITHDRAWING AMOUNT YOUR REMAINING BALANCE ARE : "<<bal<<endl;
    }
    else{
        cout<<"NOT ENOUGH AMOUNT TO WITHDRAW!!! \n firstly you deposit minimum balance then after that you are eligible to withdraw amount:"<<endl;
    }
}
void Bank::Display(void)
{
    cout<<endl;
    cout<<setw(25)<<"ACCOUNT DETAILS"<<endl;
    cout<<setw(25)<<"DEPOSITER NAME :"<<name<<endl;
    cout<<setw(25)<<"ACCOUNT TYPE :"<<acctype<<endl;
    cout<<setw(25)<<"ACCOUNT NUMBER :"<<accno<<endl;
    cout<<setw(25)<<"BALANCE :"<<bal<<endl;
}
int main()
{
   Bank b;
   int choice;
   char ch='y';
   while(ch=='y'||ch=='y')
   {
       cout<<"\n\n----BANKING SYSTEM PROGRAM----"<<endl;
       cout<<"\n\nMAIN MENU:"<<endl;
       cout<<"1.TO ASSIGN INITIAL DETAILS :"<<endl;
       cout<<"2.TO DEPOSIT AMOUNT :"<<endl;
       cout<<"3.TO WITHDRAW AMOUNT :"<<endl;
       cout<<"4.TO DISPLAY : "<<endl;
       cout<<"5.exit"<<endl;
       cout<<"ENTER YOUR CHOICE BETWEEN(1-5)"<<endl;
       cin>>choice;
       switch(choice)
       {
           case 1:b.OPbalance();
           break;
           case 2:b.Deposit();
           break;
           case 3:b.Withdraw();
           break;
           case 4: b.Display();
           break;
           default:cout<<"INVALID OPTION!!!, TRY TO ENTER VALID OPTION"<<endl;
       }
       cout<<"DO YOU WANT TO CONTINUE?(y/n)"<<endl;
       cin>>ch;
   }

    return 0;
}
