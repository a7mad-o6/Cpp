#include <iostream>
using namespace std;


//************ Variables ***********//
float balance = 1000;
int deposit = 0;
int withdraw = 0;
string password = "0";
string input_password;
int choice;
int attempts = 0;
int language_choice;
//*********** End Variables **********//


void show (){
cout<<"\n************** Menu **************"<<endl;
cout<<"1:Balance"<<endl; //Net worth 
cout<<"2:Withdraw"<<endl; //Take money 
cout<<"3:Deposit"<<endl; //Put money 
cout<<"4:Exit"<<endl; //Take visa card 
cout<<"**********************************"<<endl;
}


bool language() {
    cout << "********* select language *********" << endl;
    cout<<"1:English"<<endl;
    cout<<"2:Arabic"<<endl;
    cout<<"3:Exit"<<endl;
    cout << "***********************************" << endl;

    while (true) {
        cin >> language_choice;
        cout<<endl;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number from the (select language) menu : ";
        }
        else if (language_choice == 1) {
            return true;
        }
        else if (language_choice == 2) {
          cout<<"Arabic language is not available at the moment please try again later, or chose another language from (select language) menu : ";
        }
        else if (language_choice == 3){
          cout<<"Thank you"<<endl;
          return false ;
        }
        else {
            cout << "Please enter a vaild number from the (select language) menu : ";
        }
    }
}


bool pin (){
    
    cout<<"please Enter your password : ";
    cin>>input_password;
    cout<<endl;
    do{ 
    if (password == input_password)  
    {
        return true;
    }
    else
    {
        cout<<"your password is incorrect, please try again : ";                          
        cin>>input_password;
        cout<<endl;
        if(password==input_password)
        {
            return true;
        }
        ++attempts;                      
    }
    }while (attempts < 2);
    
    cout<<"your card will be temporarily blocked for 24 hours"<<endl;
    return false;
}


void process (){
  do{
  if (password == input_password){
    cout<<"Enter your choice : ";
    cin>>choice;
    if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
  }
    cout<<endl;
    switch(choice){
      case 1:
      cout<<"Your balance is "<<balance<<endl;
      cout<<endl;
      break;
      
      case 2:
      cout<<"Enter the amount : ";
      cin>>withdraw;
      cout<<endl;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits <streamsize> :: max(), '\n');
        cout<<"Please enter a vaild number from the menu"<<endl;
        cout<<endl;
        }
        else {
      if (balance>=withdraw){
      balance -= withdraw;
      cout<<"Now : your balance is "<<balance<<endl;
      cout<<endl;
      }
      else
      {
        cout<<"Sorry your balance is less than your withdraw"<<endl;
        cout<<endl;
      }
        }
  break;
      
      case 3:
      cout<<"put the money that you need to deposit : ";
      cin>>deposit;
      cout<<endl;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits <streamsize> :: max(), '\n');
        cout<<"Please enter a vaild number from the menu"<<endl;
        cout<<endl;
        }
        else {
      balance += deposit;
      cout<<"Now : your balance is "<<balance<<endl;
      cout<<endl;
        }
      break;
      
      case 4:
      cout<<"Thank you"<<endl;
      return;
      break;
      
      default :
      cout<<"Please enter a vaild number from the menu"<<endl;
      cout<<endl;
      
    } //End switch 
  }
  }while (true);
  }

  
int main (){
  
  
  if (language () == false){
    return 0;
  }
  if (pin() == false ){
    return 0;
  }
  show ();
  process ();
  
  
  return 0;
}