
#//$$$$$$$$$$$$ THIS CODE WAS WRITTEN ON ANDROID DEVICE $$$$$$$$$$$$\\#

#it's my first project in python 
# I used "Acode" for writing this code
#It's not that hard coding on android but still weird :|


#//************ Variables ***********//
balance = 1000
deposit = 0
withdraw = 0
password = "0"
input_password = None
choice = None
attempts = 0
language_choice = None
#//*********** End Variables **********//


def show () :
  print ("""\n************** Menu **************
1:Balance
2:Withdraw
3:Deposit
4:Exit
***********************************""")


def language () :
  print("""********* select language *********
1:English
2:Arabic
3:Exit
************************************""")

  while True : 
    language_choice = input()
    if language_choice == "1" :
      return True
    
    elif language_choice == "2" :
      print ("Arabic language is not available at the moment please try again later, or chose another language from (select language) menu : ")
    
    elif language_choice == "3" :
      print ("Thank you")
      return False
    
    else : 
      print ("Please enter a vaild number from the (select language) menu : ")
    
    
def pin () :
  global attempts 
  input_password = input("please Enter your password : ")
  if input_password == password :
    return True
    
  else :
    while input_password != password and attempts < 2 :
      
      input_password = input("your password is incorrect, please try again : ")
      attempts = attempts + 1
      if input_password == password :
        return True
        
  print ("your card will be temporarily blocked for 24 hours")
  return False


def process () :
  global balance
  while True :
    
    choice = input("Enter your choice : ")
    if choice == "1" :
      print ("you balance is ",balance)
      
    elif choice == "2" :
      
      withdraw = int(input("Enter the amount : "))
      if balance >= withdraw :
        balance = balance - withdraw
        print("Now : your balance is ",balance)
      else :
        print ("Sorry your balance is less than your withdraw")
        
    elif choice == "3" :
        
        deposit = int(input ("put the money that you need to deposit : "))
        balance = balance + deposit
        print ("Your balance is ",balance)
      
    elif choice == "4" :
        print ("Thank you")
        return False
    
    else :
        print ("Please enter a vaild number from the menu")


if language () == True :
  if pin () == True :
    show ()
    process ()
  