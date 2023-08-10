#include<iostream>
using namespace std;


//************ Variables ***********//
float balance = 1000;
int deposit = 0;
int withdraw = 0;
int state_password = 0;
int password;
int choice;
int trying=1;
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

void language(){
  cout<<"********* select language *********"<<endl;
  cout<<"1:English"<<endl;
  cout<<"2:Arabic"<<endl;
  cout<<"***********************************"<<endl;
}

void process (){
  language();
  do{
  cin>>language_choice;
  switch (language_choice){
    case 2:
    cout<<"Sorry Arabic language doesn't exist right now, you can select English language"<<endl;
    break;
  }
  }while(language_choice>1);
  cout<<"Enter your PIN : ";
  cin>>password;
  do{
  if (password == state_password){
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice){
      case 1:
      cout<<"Your balance is "<<balance<<endl;
      break;
      
      case 2:
      cout<<"Enter the amount : ";
      cin>>withdraw;
      if (balance>=withdraw){
      balance -= withdraw;
      cout<<"Now : your balance is "<<balance<<endl;
      }
      else{
        cout<<"Sorry your balance is less than your withdraw"<<endl;
      }
      break;
      
      case 3:
      cout<<"put the money that you need to deposit : ";
      cin>>deposit;
      balance += deposit;
      cout<<"Now : your balance is "<<balance<<endl;
      break;
      
      case 4:
      cout<<"Thank you "<<endl;
      break;
    } //End switch 
  }
    else{
      cout<<"your password is incorrect "<<endl;
      if (trying<=2){
        cout<<"Enter your password : ";
        cin>>password;
        trying ++;
      }
      else{
        choice =4;
      }
    }
  }while(choice<4);
  }

int main(){
  show();
  process ();
    
    
    return 0;
}