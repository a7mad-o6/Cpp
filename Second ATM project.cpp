#include <iostream>
using namespace std;


//************ Variables ***********//
float balance = 1000;
int deposit = 0;
int withdraw = 0;
string password = "0"; //the password is string because the errors of entering a string in a int variable
string input_password; 
int choice; //choice of menu
int attempts = 0; //attempts of password 
int language_choice;
//*********** End Variables **********//


void show (){
  //main menu
cout<<"\n************** Menu **************"<<endl;
cout<<"1:Balance"<<endl;
cout<<"2:Withdraw"<<endl;
cout<<"3:Deposit"<<endl; 
cout<<"4:Exit"<<endl;
cout<<"**********************************"<<endl;
}


bool language() {
  //language menu
    cout << "********* select language *********" << endl;
    cout<<"1:English"<<endl;
    cout<<"2:Arabic"<<endl;
    cout<<"3:Exit"<<endl;
    cout << "***********************************" << endl;

   //language choice input 
    while (true) {
        cin >> language_choice;
        cout<<endl;
        //checking if it's int
        if (cin.fail()) { //this if (cin.fail()) from chatGPT ,
        //to handle errors if the input was string
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number from the (select language) menu : ";
        }
        
        
        // English language 
        else if (language_choice == 1) {
            return true;
        }
        
        
        // Arabic language 
        else if (language_choice == 2) {
          cout<<"Arabic language is not available at the moment please try again later, or chose another language from (select language) menu : ";
        }
        
        
        //Exit choice 
        else if (language_choice == 3){
          cout<<"Thank you"<<endl;
          return false ; 
        }
        
        
        //if language choice input wasn't int
        else {
            cout << "Please enter a vaild number from the (select language) menu : ";
        }
    } // End while (true)
}


// password function
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


//process function where the menu choice is
void process (){
  do{
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
//I don't know if the PIN should be first :)

  return 0;
}