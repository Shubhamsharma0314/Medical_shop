//***Standard Libraries***

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <conio.h>
#define max 10

//the header file
using namespace std;

//base class
class medicineType	
{
public:

	//to  take_order-
    void take_order();
    //to delete the order-
    void delete_order();
	//to modify the order- 
    void modify(); 
    //to display the order_list-
	void order_list(); 
	//to display daily_summary-
	void daily_summary(); 
	//function to exit system-
	void exit();  
	//constuctor
	medicineType();

};

//constructor for class MedicineType
 medicineType::medicineType ()
{

}		

//constract node-
struct node 
{
	int reciept_number;
	string customerName;
	string date;
	int quantity[10];
	string type[10] = {"Tablet","Tablet","Capsule","Tablet","Capsule","Tablet","Tablet","Tablet","Capsule","Capsule"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Azel(40mg)","Alecensa(150mg)","Acid(500mg)","Augmentin(625)","Cabotres(40)","Capmide(40mg)",
	"Amino Zinc","Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[10] = {100.00,85.00,150.00,421.00,1.00,510.00,78.00,40.00,32.00,504.00};
	double total;

	node *prev;
	node *next;
	node *link; 

}*q, *temp;				//pointer declaration 


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

bool login();
string getpass();

// Main function-
int main()	
{

		system("cls");
		while(true){
			string select;
			medicineType medicine;
	int menu;
	do
	{
		system("cls");
		
		cout<<"\n\n\n\t\t\t       WELCOME TO SHUBH MEDICARE\n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t\t1. Take new Medicine order \t\t\n";
		cout<<"\t\t\t2. Delete latest Medicine order\t\t\n";
		cout<<"\t\t\t3. Modify Order List \t\t\t \n";
		cout<<"\t\t\t4. Print the Reciept and Make Payment \t\n";
		cout<<"\t\t\t5. Daily Summary of total Sale \t\t \n";
		cout<<"\t\t\t6. Close Application\t\t\t \n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice(Any One): ";

		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				//function to add Medicine-
				medicine.take_order();	
				break;
			}	
		
		
		case 2:
			{
				//function to delete Medicine-
				medicine.delete_order();	
				system("PAUSE");
				break;
			}	
			
		case 3:
			{
				//function to modify medicine-
				medicine.modify();	
				system("PAUSE");
				break;
				}

		case 4:
			{
				//function for order list-
				medicine.order_list();	
				system("PAUSE");
				break;
			}	
		case 5:
			{
				//function to daily_summary-
				medicine.daily_summary();	
				system("PAUSE");
				break;
			}	
        case 6:
			{
				//function to exit-
				medicine.exit();	
				goto a;
				break;
			}	

		
		default:
			{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}
		}
		
	}while(menu!=6);
	
	//goto
	a:
	cout<<"Thank you"<<endl;
	system ("PAUSE");
	return 0;
}//end  main function
}
//}


//function to check login
bool login()
{
	string pass;
	cout << "\n\n\t Enter the password to open a daily report : ";
	pass = getpass();
	if(pass.compare("shubh@123") == 0){ //compare password
		system("cls");
		return true;
	}else
	{
		cout << "\n\n\t\t    WRONG PASSWORD!!!!"<<endl;
		cout << "\t\t    PLEASE TRY AGAIN...";
		getch();
		system("cls");
		login();
	}
}


//function to get input password-
string getpass(){
	const char BACKSPACE = 8;
	const char RETURN = 13;	
	unsigned char ch = 0;
	string password;

	while ((ch = getch()) != RETURN){
		if (ch == BACKSPACE){
        	if (password.length() != 0){
            	cout << "\b \b";
                password.resize(password.length()-1);
            }
        }
    	else{
        	password += ch;
        	cout << '*';
        }
	}
	cout << endl;
	return password;
}


//function to take_order-
void medicineType::take_order()		
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	cout <<"\nAdd Order Details\n";
	cout <<"_____________________________________ \n\n";

	node *temp;
	temp=new node;
		cout <<"**************************************************************************\n";
				cout<<"Medicine ID"<<"\tMedicine Type"<<"   \tMedicine Name"<<"       Medicine Price(Rs.)"<<endl;
				cout <<"**************************************************************************\n";
                cout<<"0001"<<"\t"<<"\tTablet"<<"\t\t"<<"    Azel(40mg)"<<"			Rs 100.00"<<endl;
                cout<<"0002"<<"\t"<<"\tTablet"<<"\t\t"<<"    Alecensa(150mg)"<<"		Rs 85.00"<<endl;
                cout<<"0003"<<"\t"<<"\tCapsule"<<"\t\t"<<"    Acid (500mg)"<<"		Rs 150.00"<<endl;
                cout<<"0004"<<"\t"<<"\tTablet"<<"\t\t"<<"    Augmentin(625)"<<"		Rs 421.00"<<endl;
                cout<<"0005"<<"\t"<<"\tCapsule"<<"\t\t"<<"    Cabotres Tablet"<<"	 	Rs 1.00"<<endl;
                cout<<"0006"<<"\t"<<"\tTablet"<<"\t\t"<<"    Capmide Tablet"<<" 		Rs 510.00"<<endl;
                cout<<"0007"<<"\t"<<"\tTablet"<<"\t\t"<<"    Amino Zinc Tablet"<<"		Rs 78.00"<<endl;
                cout<<"0008"<<"\t"<<"\tTablet"<<"\t\t"<<"    Burnex"<<"			Rs 40.00"<<endl;//1353fn
                cout<<"0009"<<"\t"<<"\tCapsule"<<"\t\t"<<"    Fabuloss 5"<<"			Rs 32.00"<<endl;
                cout<<"0010"<<"\t"<<"\tCapsule"<<"\t\t"<<"    Royal Propollen"<<"		Rs 504.00"<<endl;
                cout<<" "<<endl;
				
    
	temp = new node;
	cout << "Type Order no: ";
    cin >> temp->reciept_number;
	cout<< "Enter Customer Name: ";
	cin>> temp->customerName;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your Medicine ID : "<<endl;
		cin>> temp->menu2[i];
        cout<< "Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay is: " << temp->amount[i]<<" Rs."<<endl;
        system("PAUSE");
                      
	}
	cout<<"==========================================================================="<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"==========================================================================="<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
}
}//End function take_order


//Function to display receipt-
void medicineType::order_list()		
{
	int i, num, num2;	
	//variable to search-
	bool found;			
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;
	
	cout<<" Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	

//Invalid receipt code-
	if(temp == NULL) 
	{
		cout << "\tThere is no Order to show\n\t\t\So The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==num2)
		
		{
			found = true;
		}
		else
		{
			cout<<"There is no Order list related to this reciept number.\n";
			temp = temp -> next;
		}
		
		//print the receipt-
        if (found)	
        {
        cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<"\t\tHere is the Order list\n"; 
		cout<<"==========================================================================="<<endl;
		cout <<"\nReciept Number : "<<temp->reciept_number;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;
				
		cout<<"Order Date : "<<temp->date<<endl;
				
		cout<<"_____________________________________________________________________________"<<endl;
			
		cout << "===============================================================================" << endl;
		cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |  Total Price |" << endl;
		cout << "=======++==================++================++===============++===============" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type[i] <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t";
			cout<<temp->quantity[i] <<"\t";
			cout<<" Rs."<< temp->amount[i]<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : "<<" Rs."<<temp->total;
		cout<<"\n";
		cout << "Enter the exact amount You need to pay: "<<" Rs.";
        cin >> num;

		cout <<"\n";

		while(temp->total!=num){
			cout<<"\nXXXX Payment Amount is not correct XXXX\n";
			cout << "Enter the exact amount You need to pay: "<<" Rs. ";
        	cin >> num;
        	
		}
		cout<<"\nPayment Done\nThank You\n";	
		
		}


}
}	//End function order_list


//function to delete_order-
void medicineType::delete_order()	
{
	system("cls");
	int i, num, count;
    cout<<"Enter the data you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(start_ptr->reciept_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"The Reciept is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->reciept_number != num) 
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q) 
				last = temp;
				delete q;
				cout<<"The Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
			}
		} 
}	//End function delete_order


	//function to modify order-
void medicineType::modify()	
{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start_ptr;
 cout<<"Enter Receipt Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Change  Order Number: ";
    cin >> temp->reciept_number;
	cout<< "Change Customer Name: ";
	cin>> temp->customerName;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	//cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "Change Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" Rs."<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");
	
	}

 cout<<"RECORD MODIFIED....!"<<endl;
 }
 else 
 {
 	if(temp != NULL && temp->reciept_number != sid)
 	{
 	cout<<"Invalid Reciept Number...!"<<endl;
    }
 }
}
}
}		//End modify function


//Function to display Daily Summary-
void medicineType::daily_summary()		
{


		if(login()){
		system("cls");
		int i,num;
	system("cls");
	node *temp ;

	temp=start_ptr;
	

//Invalid receipt code-
	if(temp == NULL) 
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL)
		{
		
				cout <<"Reciept Number : "<<temp->reciept_number;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->customerName<<endl;
				
				cout<<"Order Date : "<<temp->date<<endl;
				
				cout<<"____________________________________________________________________________"<<endl;
			
				cout << "==========================================================================" << endl;
				cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "=======++==================++================++===============++==========" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout << temp->type[i] <<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<<" Rs."<< temp->amount[i]<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}
			
			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"Total Bill is : "<<" Rs."<<temp->total;
		
			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";
				
			temp=temp->next;
		}
	}
		
}
	
}		//End daily summary


//Function to exit-
void medicineType::exit() 
{
	cout<<"\nYou choose to exit.\n"<<endl;
}	//end function exit


//************************THE END OF PROGRAM***************************************
