#include<iostream>
#include<algorithm>
#include<vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <time.h>
#include <unistd.h>
#include <ios>
using namespace std;
int main();
vector<string>path;
void admin_menu();

class Admin
{
	string username;
	string password;
	public:
		Admin()
		{
			username = "admin";
			password = "admin";
		}
	void enter_name(string x)
	{
		if(x == username)
		{
			cout << "User name found\nEnter password: ";
		}
		if( x!= username)
		{
			cout << "\t\t\tInvalid username\n \t\t\tChanging to main menu\n";
			sleep(3);
			system("cls");
			main();
		}
	}	
	void enter_password(string s)
	{
		if(s == password)
		{
			admin_menu();
		}
		if( s!= password)
		{
			cout << "\t\t\tInvalid password\n \t\t\tChanging to main menu\n";
			sleep(3);
			system("cls");
			main();	
		}
	}
};
class Customer
{
	string name;
	long long phone_no;
	int days_stay;
	public:
		void enter_name(string x)
		{
			name = x;
		}
		void enter_no(long long x)
		{
			phone_no = x;
		}
		void enter_days(int x)
		{
			days_stay = x;
		}
		string get_name()
		{
			return name;
		}
		long long get_no()
		{
			return phone_no;
		}
		int get_days()
		{
			return days_stay;
		}
};
class room
{
	int rent;
	string hname;
	string name;
	public:
		void set_name(string s)
		{
			name=s;
		}
		string get_name()
		{
			return name;
		}
		void set_hname(string n)
		{
			hname=n;
		}
		string get_hname()
		{
			return hname;
		}
		void set_rent(int x)
		{
			rent = x;
		}
		int get_rent()
		{
			return rent;
		}
		friend class customer;
};
void customer_details(room);
void generate_bill(Customer,room);
class hotel
{
	string name;
	float avg_rent;
	vector<room> r;
	public:
		void set_arent(float x)
		{
			avg_rent = x;
		}
		float get_arent()
		{
			return avg_rent;
		}
		void set_name(string n)
		{
			name=n;
		}
		string get_name()
		{
			return name;
		}
		void add_room(room k)
		{
			r.push_back(k);
		}
		void print_rooms(string x)
		{
			system("cls");
			sleep(1);
			cout << "\n\n\n";
			cout << "\t\t\t=========================================\n\n";
			cout << "\t\t\tHere are the list of rooms availble in the " << x << "\n\n";
			cout << "\t\t\tRoom Type \tRoom Rent\n\n";
			for(int i=0;i<r.size();i++)
			{
				cout<< "\t\t\t"<< i+1 <<". "<< r[i].get_name() << "\t"  << r[i].get_rent()<< endl;
			}
			cout << "\n\t\t\t=========================================\n\n";
		}
		int go(string y)
		{
			system("cls");
			print_rooms(y);
			cout<<"\t\t\tPlease select the required room: ";
			reask:
			int x;
			cin>>x;
			if(x==-1)
			{
				return 0;
			}
			if(x > r.size() || x <=0 && x!=-1)
			{
				cout << "\t\t\tInvalid city code: \n\t\t\tPlease select the City: ";
				goto reask;
			}
			else
			{
				r[x-1].set_hname(y);
				customer_details(r[x-1]);
			}
		}
};
class city{
	string name;
	vector<hotel> h;
	public:
		city(){
			
		}
		city(string s){
			s=name;
		}
		void set_name(string s){
			name=s;
		}
		string get_name(){
			return name;
		}
		void add_hotel(hotel k){
			h.push_back(k);
		}
		void print_hotels(string x)
		{
			system("cls");
			sleep(1);
			cout <<"\n\n\n";
			cout << "\t\t\t====================================================\n\n";
			cout << "\t\t\tHere are the list of Hotels availble in the " << x << "\n\n";
			cout << "\t\t\tHotel Name\t\t\tAverage Rent\n" << endl;;
			for(int i=0;i<h.size();i++)
			{
				cout<<"\t\t\t" << i+1<<"."<<h[i].get_name()<< setw(20) << right <<h[i].get_arent()<< "\n"<<endl;
			}
			cout << "\n";
			cout << "\t\t\t====================================================\n\n";
		}
		bool go(string y)
		{
			int f=0;
			while(f==0)
			{
				f=1;
				print_hotels(y);
				cout<<"\t\t\tPlease Enter Hotel: ";
				hask:
				int x;
				cin>>x;
				if(x==-1)
				{
					return 0;
				}
				if(x > h.size() || x <=0 && x!=-1)
				{
					cout << "\t\t\tInvalid Hotel code: \n\t\t\tPlease Enter Hotel: ";
					goto hask;
				}
				f=h[x-1].go(h[x-1].get_name());
			}
		}
};
void admin_menu()
{
	start:
	system("cls");
	cout << "\n\n\n";
	cout << "\t\t\t============================================\n\n\n";
	cout << "\t\t\tWelcome to admin page\n\n";
	cout << "\t\t\tPress 1 to view customer's list\n\n";
	cout << "\t\t\tPress 2 to logout from admin\n\n";
	cout << "\t\t\t============================================\n\n\n";
	int select;
	reask:
	cin >> select;
	if(select == 1)
	{
		system("cls");
		ifstream cfile;
		cfile.open("customer.txt");
		if(cfile.is_open())
		{
			string line;
			cout << "Customer details: \n\n\n";
			int count =0;
			while(getline(cfile,line))
			{
				cout << line << "\t";
				count+=1;
				if(count %3 == 0)
				{
					cout << "\n\n";
				}
			}
			cfile.close();
			int x;
			cout << "\n\n\n\t\tEnter -1 to go back: ";
			reask2:
			cin>> x;
			if( x== -1)
			{
				goto start;
			}
			else
			{
				cout << "Invalid retry again\n";
				goto reask2;
			}
		}
	}
	else if( select == 2)
	{
		system("cls");
		main();
	}
	else
	{
		cout << "INVALID INPUT\n TRY AGAIN";
		goto reask;
	}
}
int welcome()
{
	cout << "\n\n\n";
	cout << "\t\t\t=========================================\n\n";
	cout << "\t\t\tWelcome to Hotel room booking service\n\n";
	cout << "\t\t\tPress 1 to start Booking\n";
	cout << "\t\t\tPress 2 to login as admin\n";
	cout << "\t\t\tPress 3 to exit\n";
	cout << "\t\t\t=========================================\n\n\n";
	cout << "\t\t\tInstructions\n";
	cout << "\t\t\t->Enter the alloted number for selection\n";
	cout << "\t\t\t->Enter '-1' to navigate to previous menu\n\n\n";
	return 4;
}
void customer_details(room rent)
{
	string s;
	long long x =0;
	int y=0;
	Customer C;
	system("cls");
	sleep(1);
	cout << "Enter your details: \n\n";
	cout << "NOTE: Name without spaces. You can use underscore '_' in place of space\n\n";
	cout <<"Name : ";
	cin >> s;
	cout << "\nPhone no: ";
	cin >> x;
	cout << "\nDays of Stay: ";
	cin >> y;
	C.enter_name(s);
	C.enter_no(x);
	C.enter_days(y);
	sleep(2);
	cout << "\n\nThe total payment amount for the room selected for " << y << " days is " << y*rent.get_rent() << endl;
	cout << "\n\nPress 1 to confirm the payment \n";
	cout << "\nPress 2 to cancel the payment and go back to starting page\n";
	int select;
	cin >> select;
	if(select == 1)
	{
		generate_bill(C,rent);
	}
	if(select == 2)
	{
		system("cls");
		main();
	}
}
void generate_bill(Customer C, room rent)
{
	fstream cfile;
	cfile.open("customer.txt",std::ios::app) ;
	cfile << C.get_name() << "\n";
	cfile << C.get_no() << "\n";
	cfile << C.get_days() << "\n";
	cfile.close();
	system("cls");
	sleep(2);
	cout << "The payment was successful!\n\n";
	sleep(1);
	cout << "\t\t============================================================\n\n\n";
	cout << "\t\t\tHotel name: " << rent.get_hname() << "\n\n";
	cout << "\t\t\tRoom type: " << rent.get_name() << "\n\n";
	cout << "\t\t\tCustomer details:\n\n \t\t\tNAME : " << C.get_name() << "\n\n\t\t\tPHONE NO: " << C.get_no() << "\n\n\t\t\tDAYS OF STAY: " <<C.get_days() << endl;
	cout << "\n\n\t\t\tTotal Amount paid: " << rent.get_rent()*C.get_days() << endl;
	cout << "\n\n\t\t\tThank you for using our services\n" << endl;
	cout << "\t\t============================================================\n\n";
	int select;
	cout << "\t\t\tEnter 1 to book another ticket\n\t\t\tEnter 2 to exit the app\n";
	cin >> select;
	if(select == 1)
	{
		system("cls");
		cout << setw(20) <<"THANK YOU! WAIT TO BOOK ANOTHER TICKET\n";
		sleep(2);
		system("cls");
		main();
	}
	else if(select == 2)
	{
		cout <<"\n\n\n\t\t\t";
		cout << "THANK YOU! HAVE A NICE DAY";
		exit(0);
	}
}
int main()
{
	vector<city> C(5);
	vector<hotel> H(3);
	vector<room> R(3);
	ifstream myfile;
    myfile.open("city.txt");
    if (myfile.is_open()) 
	{
        for (int i = 0; i < 5; i++) 
		{
            string myline;
            {
                getline(myfile, myline);
                C[i].set_name(myline);
            }
        }
    }
    int rent[3];
	srand(time(0));
	for(int i=0;i<3;i++)
	{
	    ifstream rfile;
	    rfile.open("Rooms.txt");
	    float sum =0;
	    string myline;
	    for(int k=0;k<3;k++)
	    {
	        int m = rand() % 400 + 150;
	        sum = sum + m;
	        rent[k] = m;
	    }
	    sort(rent,rent+3);
	    for(int j=0;j<3;j++)
	    {
	        R[j].set_rent(rent[j]);
	        getline(rfile,myline);
	        R[j].set_name(myline);
	        H[i].add_room(R[j]);
	    }
	    H[i].set_arent(sum/3);
	    rfile.close(); 
	}
	for(int i=0;i<5;i++)
    {
    	ifstream hfile;
    	hfile.open((C[i].get_name()+".txt").c_str());
    	string myline;
    	for(int j=0;j<3;j++)
    	{
    		getline(hfile,myline);
    		H[j].set_name(myline);
    		C[i].add_hotel(H[j]);
		}
	}
	start:
	int k = welcome();
	int select;
	while(k == 4)
	{
		cin >> select;
		if(select == 1)
		{
			break;
		}
		else if (select == 2)		
		{
			system("cls");
			Admin A;
			string u,p;
			cout << "Enter user name: ";
			cin >> u;
			A.enter_name(u);
			cin >> p;
			A.enter_password(p);
		}
		else if (select ==3)
		{
			system("cls");
			cout << "Application Closed\n" << endl;
			exit(0);
		}
		else
		{
			cout << "\t\t\tinvalid input\n";
		}
	}
	int f=0;
	while(f==0)
	{
		f=1;
		system("cls");
		sleep(1);
		cout << "\n\n\n";
		cout << "\t\t\t=========================================\n\n";
		cout << "\t\t\tHere are the list of available cities: \n";
		for(int i=0;i<C.size();i++)
		{
			cout<<"\t\t\t" <<i+1 << ". "<< C[i].get_name() << endl;
		}
		cout << "\n";
		cout << "\t\t\t=========================================\n\n";
		cout<<"\t\t\tPlease select the City: ";
		reask: 
		int x;
		cin>>x;
		if(x == -1) 
		{
			system("cls");
			goto start;
		}
		if(x > C.size() || x <=0 && x!=-1)
		{
			cout << "\t\t\tInvalid city code: \n\t\t\tPlease select the City: ";
			goto reask;
		}
		f=C[x-1].go(C[x-1].get_name());
	}
	return 0;
}
