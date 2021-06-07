#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string>

class teacher
{
	char name[10],depart[10],subject[10],contact[10];
	int absent , present , holiday , dd, mm, yy;
    public:
    teacher() { absent = 0; present = 0; holiday = 0 ;}
	void get();
	void put();
	void names(int q);
	void date();
	void check();
	void mark();
	void display();
};

void teacher :: get()
{
	cout<<"Enter teacher's name : "; cin>>name;
	cout<<"Enter teacher's department : "; cin>>depart;
	cout<<"Enter teacher's subject : "; cin>>subject;
	cout<<"Enter teacher's contact : "; cin>>contact;
	cout<<"\n";
}

void teacher :: put()
{
	cout<<"Name : "<<name<<endl;
	cout<<"Department : "<<depart<<endl;
	cout<<"Subject : "<<subject<<endl;
	cout<<"Contact : "<<contact<<endl;
	cout<<"\n";
}

void teacher :: names(int q)
{
	cout<<q<<") "<<name<<"\n";
}

void teacher :: date()
{
	cout<<"Enter date for which you want to mark attendance in form of dd, mm, yy \n";
	cin>>dd>>mm>>yy;
	check();
}

void teacher :: check()
{
	if(mm>=1 && mm<=12)
	{
		if(mm==2)
		{
			if(yy%4==0)
			{
				if(dd<1 || dd>29)
				{
					cout<<"Wrong date \n";
					exit(0);
				}
			}
			else if(dd<1 || dd>28)
			{
				cout<<"Wrong date \n";
				exit(0);
			}
		}
		if(mm==4 || mm==6 || mm==9 || mm==11)
		{
			if(dd<1 || dd>30)
			{
				cout<<"Wrong date \n";
				exit(0);
			}
		}
		if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)
		{
			if(dd<1 || dd>31)
			{
				cout<<"Wrong date \n";
				exit(0);
			}
		}
	}
	else
	{
		cout<<"Wrong month \n";
		exit(0);
	}
}

void teacher :: mark()
{
	cout<<"\n";
	cout<<"Select attendance option for "<<dd<<"/"<<mm<<"/"<<yy<<endl;
	cout<<"Absent = A \n";
	cout<<"Present = P \n";
	cout<<"Holiday/no class = H \n";
	char z;
	cin>>z;


		if(z == 'A')
		{
			absent++ ;
		}

		else if (z == 'P')
		{
			present++;
		}

		else if (z == 'H')
		{
			holiday++;
		}
		else {
		cout<<"Not a valid option \n\n";
	}
}

void teacher :: display()
{
	cout<<"Total attendance : "<<present<<endl;
	cout<<"Total leave/absent : "<<absent<<endl;
	cout<<"Total holidays : "<<holiday<<endl;
	cout<<"\n";
}

int main()
{
	system("cls");
	teacher T[5] ;

	cout<<"\n \n \n \n \n \n";
	cout<<"\t \t \t ------------------------------------- \n";
	cout<<"\t \t \t Teachers attendence management system \n";
	cout<<"\t \t \t ------------------------------------- \n";
	cout<<"\n \n \n";
	cout<<"\t \t \t \t -by Kashish Ahuja";
	cout<<"\n \n \n";
	cout<<"Press any key to continue...\n";
	getch();
	system("cls");
	int i=1;

	fstream file;
	file.open("TEST5",ios::in | ios::out | ios::ate | ios::binary);
	cout<<"Do you want to add a new teacher's data? [Y/N] : ";
	char ch; cin>>ch;
	system("cls");
	if(ch=='Y' || ch=='y')
	{
		again:
		T[i].get();
		file.write((char *) & T[i], sizeof(T[i]));
		cout<<"Do you want to add more teacher's data? [Y/N] :  ";
		char ch; cin>>ch;
		system("cls");
		if(ch=='Y' || ch=='y')
		{
			system("cls");
			 goto again;
		}
		else if(ch=='N' || ch=='n')
			goto first;
		system("cls");
	}

	first:
	cout<<"Select a teacher whose activity you want by entering its position number \n\n";
	cout<<"Teacher's list \n";
	cout<<"--------------------- \n";
	file.seekp(0);
	int q=1;
	while(file.read((char *) & T[i], sizeof(T[i])))
	{
		T[i].names(q);
		q++;
	}
	file.clear();
	cout<<"---------------------- \n\n";
	cout<<"Add another teacher's data = 100 \n";
	cout<<"Modify a teacher's data = 200 \n";
	cout<<"Exit = 500 \n";
	int n; cin>>n;
	system("cls");

	if(n==100)
	{
		add:
		T[i].get();
		file.write((char *) & T[i], sizeof(T[i]));
		cout<<"Successfully added \n\n";
		cout<<"Do you want to add more teacher's data? [Y/N] :  ";
		char ch; cin>>ch;
		system("cls");
		if(ch=='Y' || ch=='y')
			 goto add;
		else if(ch=='N' || ch=='n')
			goto first;
	}
	else if(n==200)
	{
		modify:
		cout<<"Select a teacher whose data you want to modify by entering its position number \n\n";
		cout<<"Teacher's list \n";
		cout<<"--------------------- \n";
		file.seekp(0);
		int q=1;
		while(file.read((char *) & T[i], sizeof(T[i])))
		{
			T[i].names(q);
			q++;
		}
		file.clear();
		cout<<"---------------------- \n\n";

		int mod; cin>>mod;
		i=mod;
		int location = (mod-1)*sizeof(T[i]);
		file.seekg(location);
		cout<<"Enter new data. \n";
		T[i].get();
		file.write((char *) & T[i], sizeof(T[i]));
		cout<<"Successfully modified \n\n";
		cout<<"Do you want to modify more data? [Y/N] : ";
		char ch; cin>>ch;
		system("cls");
		if(ch=='Y' || ch=='y')
			 goto modify;
		else if(ch=='N' || ch=='n')
			goto first;
	}
	else if(n==500)
		exit(0);
	else
	{
		i=n;
		second:
		cout<<"\n";
		cout<<"Select an activity by entering its position number \n\n";
		cout<<"Activity list \n";
		cout<<"------------------- \n";
		cout<<"1) Show teacher's data \n";
		cout<<"2) Mark attendance \n";
		cout<<"3) Display attendance \n";
		cout<<"-------------------- \n\n";
		cout<<"Go back = 300 \n";
		cout<<"Exit = 500 \n\n";
		int num; cin>>num;
		system("cls");
		if(num==1)
		{
			T[i].put();
			cout<<"\n";
			cout<<"Go back = 300 \n";
			cout<<"Go to main menu = 100 \n";
			cout<<"Exit = 500 \n\n";
			int r; cin>>r;
			system("cls");
			if(r==300)
				goto second;
			if(r==100)
				goto first;
			if(r==500)
				exit(0);
		}
		else if(num==2)
		{
			T[i].date();
			T[i].mark();
			cout<<"\n";
			cout<<"Go back = 300 \n";
			cout<<"Go to main menu = 100 \n";
			cout<<"Exit = 500 \n\n";
			int r; cin>>r;
			system("cls");
			if(r==300)
				goto second;
			if(r==100)
				goto first;
			if(r==500)
				exit(0);
		}
		else if(num==3)
		{
			T[i].display();
			cout<<"\n";
			cout<<"Go back = 300 \n";
			cout<<"Go to main menu = 100 \n";
			cout<<"Exit = 500 \n\n";
			int r; cin>>r;
			system("cls");
			if(r==300)
				goto second;
			if(r==100)
				goto first;
			if(r==500)
				exit(0);
		}
		else if(num==300)
			goto first;
		else if(num==500)
			exit(0);
	}

	getch();
	return 0;
}
