//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include<iostream> 
#include<fstream>   
#include<iomanip>
#include<stdlib.h>  
#include<string.h>
using namespace std;
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class acc     //Class definition starts 
{
    long ano;
    char name[100];
    int dep;
    char type;
public:
    void create_acc();           //Function to create a new account
    void show_acc() const;       //  Function to show account details
    void modify();               //Function to modify account details
    void adep(int);               //Function to accept deposit amount
    void draw(int) ;             //Function to subtract withdrawal amount
    void report() const;         //Function to show data in tabular format
    int retano() const;         //For returning account number
    int retbal() const;        //For returning balance amount
    char qtype() const;         //For returning type of account
};         //Class definition ends

void acc::create_acc()
{
	acc ac;
    system("cls");
    cout<<"\n\nEnter Name of The Account Holder : ";
    cin.ignore();
    cin.getline(name,100);
    cout<<"\n\nWELCOME "<<name<<". Enter the Account Number you wish to have : ";
    cin>>ano;
    l4: cout<<"\nEnter Type of Account you want to have(C for current or S for Savings) : ";
    cin>>type;
    if(type!='C'&&type!='c'&&type!='S'&&type!='s')
    {
    	cout<<"\n\nINVALID INPUT!!! TYPE AGAIN\n";
    	goto l4;
    }
    cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current) : ";
    cin>>dep;     //We have set the minimum initial amount for savings be 500 & for current be 1000 
    if(type=='c'||type=='C')
    {
    	if(dep<1000)
    	{
    		cout<<"\n\nYou cannot set initial amount less than 1000 in a current account. Please try again.";
    		goto l4;
    	}
    }
    else if(type=='s'||type=='S')
    {
    	if(dep<500)
    	{
    		cout<<"\n\nYou cannot set initial amount less than 500 in a savings account. Please try again.";
    		goto l4;
    	}
    }
    cout<<"\n\n\nCongratulation, Your Account Has Been Created.";
    cout<<"\n\n\tYour account details are as follows:\n";
    show_acc();
}

void acc::show_acc() const
{
    cout<<"\nAccount Number : "<<ano;
    cout<<"\nAccount Holder Name : "<<name;
    cout<<"\nType of Account : "<<type;
    cout<<"\nBalance amount : "<<dep;
}

void acc::modify()
{
	
	cout<<"\nEnter the Account Number you wish to have : ";
    cin>>ano;
    cout<<"\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name,100);
    cout<<"\nModify Type of Account : ";
    cin>>type;
    cout<<"\nModify Balance amount : ";
    cin>>dep;
}

void acc::adep(int x)
{
    dep+=x;
}
    
void acc::draw(int x)
{
    dep-=x;
}
    
void acc::report() const
{
    cout<<ano<<setw(12)<<" "<<name<<setw(12)<<"  "<<type<<setw(12)<<" "<<dep<<endl;
}
    
int acc::retano() const
{
    return ano;
}

int acc::retbal() const
{
    return dep;
}

char acc::qtype() const
{
    return type;
}


//***************************************************************
//      function declaration
//****************************************************************

void write_acc();    //function to write record in binary file
void display_sp(int);    //function to display account details given by user
void modify_acc(int);    //function to modify record of file
void delete_acc(int);    //function to delete record of file
void display_all();        //function to display all account details
void dep_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();    //introductory screen function
void instructions();          //function to display some general instruction to user
int login();                 //function to check how the user want to login
//***************************************************************
//      THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	char name[100];
    long ch;
    int a,num;
    char b;
    intro();
    instructions();
    l3: system("cls");
    system("color 9A");
    a=login();
    switch(a)
    {
    	case 1:
    		system("cls");	
    		system("color 4A");
            cout<<"Are you sure you want to make a new account?\nPress Y or y for yes. Otherwise press any key : ";
		    cin>>b;
		    if(b=='Y'||b=='y')
		    {
		        write_acc();
		        cout<<"\n\nDo you want to avail services right now? Press Y or y for yes. Otherwise press any key : ";
		        cin>>b;
		        if(b=='Y'||b=='y')
		        {
			       goto l2;
		        }
		        else
		        { 
				system("cls");
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tThanks For Visiting Our Bank!";
			       exit(0);
		        }
    	    }
            else
            {
         	    goto l3;
            }
    	break;
    case 2:  
		l2:  do
    {
    	system("color 5B");
        system("cls");  //Clear The Screen
        cout<<"\n\n\n\t\t WE ARE PLEASED TO HAVE YOU!!!!";
        cout<<"\n\n\n\tPLEASE ENTER YOUR NAME : ";
        cin>>name;
        system("cls");
        l5:cout<<"\n\n\t\t\tWELCOME "<<name;
        cout<<"\n\n\n\tWHAT SERVICES WOULD YOU LIKE TO AVAIL?";
        cout<<"\n\n\t01. DEPOSIT";
        cout<<"\n\n\t02. WITHDRAW";
        cout<<"\n\n\t03. ACCOUNT DETAILS";
        cout<<"\n\n\t04. CLOSE AN ACCOUNT";
        cout<<"\n\n\t05. MODIFY AN ACCOUNT";
        cout<<"\n\n\t06. EXIT";
        cout<<"\n\n\tSelect Your Option (1-6) : ";
        cin>>ch ;
        system("cls");   //Clear The Screen
        if(ch==1)
        {
           	cout<<"\n\n\tAre you sure you want to deposit money? Press Y or y for yes. Otherwise press any key : ";
        	cin>>b;
        	if(b=='Y'||b=='y')
        	{
        		system("cls");
        	   cout<<"\n\n\tEnter The Account Number : "; cin>>num;
               dep_withdraw(num, 1);
               cout<<"\n\nPress ENTER to go back...";
               cin.ignore();
               cin.get();
               system("cls");
               goto l5;
            }
			else
			{
			   system("cls");
			   goto l5;
			}
        }
   else if(ch==2)
        {
        
        	cout<<"\n\n\tAre you sure you want to withdraw money? Press Y or y for yes. Otherwise press any key : ";
        	cin>>b;
        	if(b=='Y'||b=='y')
        	{
        			system("cls");
        	   cout<<"\n\n\tEnter The Account Number : "; cin>>num;
               dep_withdraw(num, 2);
               cout<<"\n\nPress ENTER to go to the main menu...";
               cin.ignore();
               cin.get();
               system("cls");
               goto l5;
            }
            else
            {
        	   system("cls");
        	   goto l5;
            }
        }
        else if(ch==3)
        {
        	cout<<"\n\nAre you sure you want to see an account's details? Press Y or y for yes. Otherwise press any key : ";
        	cin>>b;
        	if(b=='Y'||b=='y')
        	{
        		system("cls");
        	   cout<<"\n\n\tEnter The Account Number : "; cin>>num;
               display_sp(num);
               cout<<"\n\nPress ENTER to go back...";
               cin.ignore();
               cin.get();
               system("cls");
               goto l5;
            }
            else
            {
            	system("cls");
            	goto l5;
            }
        }
        else if(ch==4)
        {
        	cout<<"\n\n\tDo you really want to delete an account? Press Y or y for yes. Otherwise press any key : ";
        	cin>>b;
        	if(b=='Y'||b=='y')
        	{
        		system("cls");
        	   cout<<"\n\n\tEnter The Account Number : "; cin>>num;
               delete_acc(num);
               cout<<"\n\nPress ENTER to go back...";
               cin.ignore();
               cin.get();
               system("cls");
               goto l5;
            }
            else
            {
               system("cls");
               goto l5;
            }
        }
        else if(ch==5)
        {   
		   cout<<"\n\n\tDo you really want to modify an account? Press Y or y for yes. Otherwise press any key : ";
           cin>>b;
           if(b=='Y'||b=='y')
           {
              cout<<"\n\n\tEnter The Account Number : "; cin>>num;
              modify_acc(num);
              cout<<"\n\nPress ENTER to go back...";
              cin.ignore();
              cin.get();
              system("cls");
              goto l5;
           }
           else
           {
              system("cls");
              goto l5;
           }
        }
        else if(ch==6)
        {
        	cout<<"\n\n\tDo you really want to exit? Press Y or y for yes. Otherwise press any key : ";
        	cin>>b;
        	if(b=='Y'||b=='y')
        	{
            	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tThanks For Visiting Our Bank!";
        	    cin.get();
                cin.ignore();
        	    exit(0);
            }
            else
		    {
        	   system("cls");
        	   goto l5;
            }
        }
        else 
        {
        	cout<<"INVALID CHOICE!!!";
        	cout<<"\n\n\tDo you want to choose again? Press Y or y for yes. Otherwise press any key : ";
        	cin>>b;
        	if(b=='Y'||b=='y')
        	{
        		system("cls");
        		goto l5;
        	}
        	else
			{
        		exit(0);
        	}
        }
        cin.ignore();
        cin.get();
    }while(ch!=5);
    return 0;
    break;
    case 3:
    l7:	int pas;
    	system("cls");
    	cout<<"\n\n\n\n\n\n\t\tEnter the password:";
    	cin>>pas;
    	if(pas!=1412)
    	{
    		cout<<"WRONG PASSWORD!!WANT TO TRY AGAIN?Press Y or y for YES.Otherwise press any key : ";
    		cin>>b;
    		if(b=='Y'||b=='y')
    		goto l7;
    		else
    		{
    			cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tThanks For Visiting Our Bank!";
    			exit(0);
    		}
    	}
    	else
    	{
    	l8:
		system("cls");
		system("color 70");
			cout<<"\n\n\n\t\t\tWELCOME EZAZ MANDAL"<<endl;
    		cout<<"\n\n\tWhat do you wish to do?";
    		cout<<"\n\n\t01. ACCOUNT DETAILS";
            cout<<"\n\n\t02. COMPLETE ACCOUNT HOLDERS LIST";
            cout<<"\n\n\t03. EXIT\n\n\t->";
            cin>>ch;
            system("cls");
        if(ch==1)
        {
        	cout<<"\n\n\tAre you sure you want to see an account's details? Press Y or y for yes. Otherwise press any key : ";
        	cin>>b;
        	if(b=='Y'||b=='y')
        	{
        		system("cls");
        	   cout<<"\n\n\tEnter The Account Number : "; cin>>num;
               display_sp(num);
               cout<<"\n\nPress ENTER to go back...";
               cin.ignore();
               cin.get();
               goto l8;
            }
            else
            {
            	goto l8;
            }
        }
        else if(ch==2)
        {
        	cout<<"\n\nDo you really want to see complete account holder's list? Press Y or y for yes. Otherwise press any key : ";
        	cin>>b;
        	if(b=='Y'||b=='y')
        	{
        		system("cls");
        	   	display_all();
        	   	cout<<"\n\nPress ENTER to go back...";
        	   	cin.ignore();
        	   	cin.get();
        	    goto l8;
            }
            else
			{
            	goto l8;
            }
        }
        else if(ch==3)
        {
        	cout<<"Are you sure that you want to exit? Press Y or y for yes. Otherwise press any key : ";
        	cin>>b;
        	if(b=='Y'||b=='y')
        	{
        		cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tThanks For Visiting Our Bank!";
        		exit(0);
        	}
        	else
        	{
        		goto l8;
        	}
        }
        else
        {
        	cout<<"\n\n\tYou have choose a wrong choice.Want to choose again?\n\n\tPress Y or y for YES.Otherwise press any key : ";
        	cin>>b;
        	if(b=='Y'||b=='y')
        	{
        		goto l8;
        	}
        	else
        	{
        		exit(0);
        	}
        }
    }
  case 4: 
  system("cls");
          cout<<"\n\nAre you sure that you want to exit ? Press Y or y for yes.Otherwise press any \nkey : ";
          cin>>b;
          if(b=='Y'||b=='y')
          {
 	         cout<<"\n\n\n\n\n\t\tThanks For Visiting Our Bank!";
 	         cin.ignore();
	         cin.get();
             exit(0);
  break;
          }
          else
          {
 	         goto l3;
          }
  default: cout<<"\n\n\t\tINVALID CHOICE!!!Want to choose again?\n\n\tPress Y or y for YES.Otherwise press any key : ";
  cin>>b;
  if(b=='Y'||b=='y')
  {
  	goto l3;
  }
  else
  {
  	   system("cls");
  	   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tThanks for visiting our bank!";
  	   cin.get();
  	   cin.ignore();
  	   exit(0);
  }
  break;
    }
}
//***************************************************************
//      function to write in file
//****************************************************************

void write_acc()
{
    acc ac;
    ofstream outFile;
    outFile.open("info.dat",ios::binary|ios::app);
    ac.create_acc();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(acc));
    outFile.close();
}
//***************************************************************
//      function to read specific record from file
//****************************************************************

void display_sp(int n)      
{
    acc ac;
    bool flag=false;
    ifstream x;
    x.open("info.dat",ios::binary);
    if(!x)
    {
        cout<<"File could not be opened!! Press any Key to exit...";
        return;
    }
    for( ;ac.retano()<=n; )
    {
    if(ac.retano()!=n)
	{
        cout<<"\n\nAccount number does not exist";
    }
  
	}
        while(x.read(reinterpret_cast<char *> (&ac), sizeof(acc)))
    {
        if(ac.retano()==n)
        {
        	flag=true;
        	cout<<"\nACCOUNT DETAILS:\n";
            ac.show_acc();
            
        }
    }
    x.close();
    if(flag==false)
    {
    	cout<<"Account number does not exist";
    }
}
//***************************************************************
//      function to modify record of file
//****************************************************************

void modify_acc(int n)
{
    bool found=false;
    acc ac;
    fstream x;
    x.open("info.dat",ios::binary|ios::in|ios::out);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!x.eof() && found==false)
    {
        x.read(reinterpret_cast<char *> (&ac), sizeof(acc));
        if(ac.retano()==n)
        {
            ac.show_acc();
            cout<<"\n\nEnter The New Details of account"<<endl;
            ac.modify();
            int pos=(-1)*static_cast<int>(sizeof(acc));
            x.seekp(pos,ios::cur);
            x.write(reinterpret_cast<char *> (&ac), sizeof(acc));
            cout<<"\n\n\t Record Updated";
            found=true;
          }
    }
    x.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}
//***************************************************************
//      function to delete record of file
//****************************************************************


void delete_acc(int n)
{
    acc ac;
    ifstream x;
    ofstream y;
    x.open("info.dat",ios::binary);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    y.open("Temp.dat",ios::binary);
    x.seekg(0,ios::beg);
    while(x.read(reinterpret_cast<char *> (&ac), sizeof(acc)))
    {
        if(ac.retano()!=n)
        {
            y.write(reinterpret_cast<char *> (&ac), sizeof(acc));
        }
    }
    x.close();
    y.close();
    remove("info.dat");
    rename("Temp.dat","info.dat");
    cout<<"\n\n\tRecord Deleted ..";
}
//***************************************************************
//      function to display all accounts deposit list
//****************************************************************

void display_all()
{
	cout<<"\n\n\t\t\tACCOUNT HOLDER LIST\n\n";
    cout<<"====================================================\n";
    cout<<"A/c no.      NAME           Type       Balance\n";
    cout<<"====================================================\n";
    acc ac;
    ifstream x;
    x.open("info.dat",ios::binary);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
   while(x.read(reinterpret_cast<char *> (&ac), sizeof(acc)))
    {
        ac.report();
    }
    x.close();
}
//***************************************************************
//      function to deposit and withdraw amounts
//****************************************************************

void dep_withdraw(int n, int option)
{
    int amt;
    bool found=false;
    acc ac;
    fstream x;
    x.open("info.dat", ios::binary|ios::in|ios::out);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!x.eof() && found==false)
    {
        x.read(reinterpret_cast<char *> (&ac), sizeof(acc));
        if(ac.retano()==n)
        {
            ac.show_acc();
            if(option==1)
            {
                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                cout<<"\n\nEnter The amount to be deposited : ";
                cin>>amt;
                ac.adep(amt);
            }
            if(option==2)
            {
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                cout<<"\n\nEnter The amount to be withdraw : ";
                cin>>amt;
                int bal=ac.retbal()-amt;
                if((bal<500 && ac.qtype()=='S'||bal<500 && ac.qtype()=='s') || (bal<1000 && ac.qtype()=='C'||bal<1000 && ac.qtype()=='c'))
                    cout<<"Sorry... Insufficience balance!You must have atleast Rs.500 for S type account or Rs.1000 for C type account.";
                else
                    ac.draw(amt);
            }
            int pos=(-1)*static_cast<int>(sizeof(ac));
            x.seekp(pos,ios::cur);
            x.write(reinterpret_cast<char *> (&ac), sizeof(acc));
            cout<<"\n\n\t\t\t Record Updated";
            cout<<"\n\n\t\t Your current account balance is: "<<ac.retbal();
            found=true;
           }
         }
    x.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}
//***************************************************************
//      INTRODUCTION FUNCTION
//****************************************************************


void intro()
{
    system("color 0A");
	int password;
    char a,username[100],x[100]="Ezaz";            // x is the admin name
	l1:cout<<"\n\t\t\t    KENDRIYA VIDYALAYA BURDWAN";
    cout<<"\n\n\n\n\t\t\tWELCOME TO BANK MANAGEMENT SYSTEM";
    cout<<"\n\n\n\t\t A C++ PROJECT MADE AND COMPILED BY IBTIEZAZ MANDAL";
    
    //All the data of the new account entered will be stored in the disk
    //Please use with Admin Privilage for the compiled .exe, so that it could access the disk space
    
	cout<<"\n\n\n\n\n\tENTER YOUR USERNAME :  ";
    cin>>username;
	 cout<<"\n\n\tENTER YOUR PASSWORD TO LOGIN :  ";
    cin>>password;
    if(strcmp(username,x)!=0||password!=5212)
	{
    cout<<"\n\n\t\t   OOPS!! USERNAME OR PASSWORD DO NOT MATCH";
    cout<<"\n\nDo you want to try again? Press Y or y for yes. Otherwise press any key. ";
    cin>>a;
    if (a=='Y'||a=='y')
    {
    	system("cls");
		         goto l1;
	}
		else{
		
	             cin.get();
                 exit(0);		     
			}
    }
}

void instructions()
{    
    system("cls");
    system("color 0C");
    char a;
    cout<<"Here some instructions for you.Please obey these instructions for the proper \nrunning of the program.\n\n";
    cout<<"1.Please enter the data carefully i.e. Enter numbers in place of numbers and \nletters in place of letters.\n\n";
    cout<<"2.Please don't enter special symbols like &,*,! etc. unless said to.\n\n";
    cout<<"If you don't follow these instructions then program may display unexpected or \nabsurd outputs.";
    cout<<"\n\nHave you understood the instructions properly and ready to use this program?\nPress Y or y if you want to continue. Otherwise press any key : ";
    cin>>a;
    if(a=='Y'||a=='y')
    {
    	
    }
    else
    {
	    system("cls");
    	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tThanks for visiting our bank!";
    	cin.get();
    	cin.ignore();
    	exit(0);
    }
}
int login()
{
	system("color 0B");
	int a;
    cout<<"\n\n\n\t\t\t\tHOW DO YOU WISH TO LOGIN? ";
    cout<<"\n\n\n\t1.NEW CUSTOMER";
    cout<<"\n\n\t2.EXISTING CUSTOMER";
    cout<<"\n\n\t3.ADMINISTRATOR";
    cout<<"\n\n\t4.EXIT";
    cout<<"\n\n\tEnter your choice(1-4) : ";
    cin>>a;	
    return a;
}
//***************************************************************
//              END OF PROJECT
//***************************************************************
