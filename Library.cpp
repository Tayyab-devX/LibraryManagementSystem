#include<iostream>
#include<fstream>
#include <windows.h>
#include<conio.h>
#include<limits>
using namespace std;

void header();
string menu();
string admin();
string librarian();
string student();

void viewBooks(int bdx, string title[], string author[], int id[], bool bookAvail[]);
void addBook(int &bdx, string title[], string author[], int id[], bool bookAvail[]);
void delBook(int &bdx, string title[], string author[], int id[], bool bookAvail[], int wdx, int bBookID[]);
void updBook(int bdx, string title[], string author[], int id[], bool bookAvail[], int wdx, int bBookID[]);
void viewMems(int mdx, string name[], string regID[], string contact[]);
void addMember(int &mdx, string name[], string regID[], string contact[], string pass[]);

void viewBBooks(int wdx, int bdx, int bBookID[], int id[], bool bookAvail[], string bregID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[]);
void viewReqBooks(int &wdx, int bdx, int &rdx, int mdx, string regID[], string name[], string title[], string author[], int id[], bool bookAvail[], string bname[], int bBookID[], string bregID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[], int reqBookID[], string reqMemID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[]);
void appBook(int &wdx, int bdx, int &rdx, int mdx, string regID[], string name[], string title[], string author[], int id[], bool bookAvail[], string bname[], int bBookID[], string bregID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[], int reqBookID[], string reqMemID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[]);
void decBook(int &rdx, int reqBookID[], string reqMemID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[]);
void borrowBooks(int mdx, int bdx, int &wdx, string regID[], string title[], string author[], int id[], bool bookAvail[], string bname[], string bregID[], int bBookID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[]);
void returnBooks(int bdx, int &wdx, string title[], string author[], int id[], int bBookID[], bool bookAvail[], string bname[], string bregID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[]);
void searchBooks(int bdx, string title[], string author[], int id[], bool bookAvail[]);
string toLower(string text)
{
    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = text[i] + 32;
    }
    return text;
}

void changePass(int index, int mdx, string name[], string regID[], string contact[], string pass[]);
void viewBorrow(int index, int wdx, string regID[], string bregID[], int bBookID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[]);
void reqBooks(int index, int bdx, int &rdx, int id[], bool bookAvail[], int reqBookID[], string regID[], string reqMemID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[]);
void viewFine(int index, int wdx, string bregID[], string regID[], int bBookID[], int returnMonth[], int returnDate[]);
// FILE HANDLING
string getField(string record, int fieldNo)
{
	string data = "";
	int commaCount=1;
	for(int idx=0; record[idx]!='\0'; idx++)
	{
		if(record[idx]==',')
			commaCount++;
		else if(commaCount==fieldNo)
			data=data+record[idx];
	}
	return data;
}

void loadBooks(int &bdx, string title[], string author[], int id[], bool bookAvail[]);
void loadMembers(int &mdx, string name[], string regID[], string contact[], string pass[]);
void loadBorrowed(int &wdx, string bname[], string bregID[], int bBookID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[]);
void loadRequests(int &rdx, string reqMemID[], int reqBookID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[]);
void saveBooks(int bdx, string title[], string author[], int id[], bool bookAvail[]);
void saveMembers(int mdx, string name[], string regID[], string contact[], string pass[]);
void saveBorrowed(int wdx, string bname[], string bregID[], int bBookID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[]);
void saveRequests(int rdx, string reqMemID[], int reqBookID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[]);

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void color(int k)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, k);
}

int main()
{
	int maxBooks=300, maxMems=200, maxBws=200, maxReqs=100;
		//Books
	string title[maxBooks], author[maxBooks]; 
	int id[maxBooks];
	bool bookAvail[maxBooks];
	int bdx=0;
		//Members
	string name[maxMems], contact[maxMems], regID[maxMems], pass[maxMems];
	int mdx=0;
		//Borrowed
	string bname[maxBws], bregID[maxBws];
	int bBookID[maxBws];
	int wdx=0;
	int borrowDate[maxBws], borrowMonth[maxBws];
	int returnDate[maxBws], returnMonth[maxBws];
		//Requested
	int reqBookID[maxReqs];
	string reqMemID[maxReqs];
	int rdx=0;
	int reqBDate[maxReqs], reqBMonth[maxReqs];
	int reqRDate[maxReqs], reqRMonth[maxReqs];
		// LOADING DATA
	loadBooks(bdx, title, author, id, bookAvail);
	loadMembers(mdx, name, regID, contact, pass);
	loadBorrowed(wdx, bname, bregID, bBookID, borrowDate, borrowMonth, returnDate, returnMonth);
	loadRequests(rdx, reqMemID, reqBookID, reqBDate, reqBMonth, reqRDate, reqRMonth);

	string menuOption;
	string password;
	string manageOption;
	while(true)
	{
		system("cls");
		header();
		menuOption = menu();
		if(menuOption=="1") // ADMIN
		{
			cout << "                Enter Password: ";
			cin >> password;
			if(password=="1234")
			{
				while(true)
				{
					system("cls");
					header();
					manageOption = admin();
					if(manageOption=="1")
						viewBooks(bdx, title, author, id, bookAvail);
					else if(manageOption=="2")
						addBook(bdx, title, author, id, bookAvail);
					else if(manageOption=="3")
						delBook(bdx, title, author, id, bookAvail, wdx, bBookID);
					else if(manageOption=="4")
						updBook(bdx, title, author, id, bookAvail, wdx, bBookID);
					else if(manageOption=="5")
						viewMems(mdx, name, regID, contact);
					else if(manageOption=="6")
						addMember(mdx, name, regID, contact, pass);
					else if(manageOption=="7")
						break;
					else
					{
						color(12);
						cout << "=         ==========INVALID--CHOICE==========         =" << endl;
						color(11);
						cout << "-------------------------------------------------------" << endl;
						getch();
					}
				}	
			}
			else
			{
				color(12);
				cout << "=         ========INCORRECT--PASSWORD========         =" << endl;
			}
		}
		else if(menuOption=="2") // LIBRARIAN
		{
			cout << "                Enter Password: ";
			cin >> password;
			if(password=="2345")
			{
				while(true)
				{
					system("cls");
					header();
					manageOption = librarian();
					if(manageOption=="1")
						viewBBooks(wdx, bdx, bBookID, id, bookAvail, bregID, borrowDate, borrowMonth, returnDate, returnMonth);
					else if(manageOption=="2")	
						viewReqBooks(wdx, bdx, rdx, mdx, regID, name, title, author, id, bookAvail, bname, bBookID, bregID, borrowDate, borrowMonth, returnDate, returnMonth, reqBookID, reqMemID, reqBDate, reqBMonth, reqRDate, reqRMonth);
					else if(manageOption=="3")
						borrowBooks(mdx, bdx, wdx, regID, title, author, id, bookAvail, bname, bregID, bBookID, borrowDate, borrowMonth, returnDate, returnMonth);
					else if(manageOption=="4")
						returnBooks(bdx, wdx, title, author, id, bBookID, bookAvail, bname, bregID, borrowDate, borrowMonth, returnDate, returnMonth);
					else if(manageOption=="5")
						searchBooks(bdx, title, author, id, bookAvail);
					else if(manageOption=="6")
						break;
					else
					{
						color(12);
						cout << "=         ==========INVALID--CHOICE==========         =" << endl;
						color(11);
						cout << "-------------------------------------------------------" << endl;
						getch();
					}
				}	
			}
			else
			{
				color(12);
				cout << "=         ========INCORRECT--PASSWORD========         =" << endl;
			}
		}
		else if(menuOption=="3") // STUDENT
		{
			string ID;
			cout << "                Enter Reg. ID: ";
    		cin >> ID;
			
			string pwd;
			cout << "                Enter Password: ";
			cin >> pwd;
			
			int sIndex = -1;
    		for(int i=0; i<mdx; i++)
    		{
        		if(regID[i] == ID && pass[i] == pwd)
        		{
            		sIndex = i;
            		break;
        		}
    		}

    		if(sIndex == -1)
    		{
    			color(12);
       			cout << "=         ===========INVALID--LOGIN==========         =" << endl;
    		}
			else
			{
				while(true)
				{
					system("cls");
					header();
					manageOption = student();
					if(manageOption=="1")
						changePass(sIndex, mdx, name, regID, contact, pass);
					else if(manageOption=="2")
						viewBooks(bdx, title, author, id, bookAvail);
					else if(manageOption=="3")
						viewBorrow(sIndex, wdx, regID, bregID, bBookID, borrowDate, borrowMonth, returnDate, returnMonth);
					else if(manageOption=="4")
						reqBooks(sIndex, bdx, rdx, id, bookAvail, reqBookID, regID, reqMemID, reqBDate, reqBMonth, reqRDate, reqRMonth);
					else if(manageOption=="5")
						searchBooks(bdx, title, author, id, bookAvail);
					else if(manageOption=="6")
						viewFine(sIndex, wdx, bregID, regID, bBookID, returnMonth, returnDate);
					else if(manageOption=="7")
						break;
					else
					{
						color(12);
						cout << "=         ==========INVALID--CHOICE==========         =" << endl;
						color(11);
						cout << "-------------------------------------------------------" << endl;
						getch();
					}
				}	
			}
		}
		else
		{
			color(12);
			cout << "=         ==========INVALID--CHOICE==========         =" << endl;
		}
		color(11);
		cout << "-------------------------------------------------------" << endl;
		getch();
	}
}

				// HEADERS
void header()
{
	color(11);
	cout << "=======================================================" << endl;
	cout << "=======================================================" << endl;
	cout << "==        _     _  _                                 ==" << endl;
	cout << "==       | |   (_)| |__  _ _  __ _  _ _  _  _        ==" << endl;
	cout << "==       | |__ | || '_ \\| '_|/ _` || '_|| || |       ==" << endl;
	cout << "==       |____||_||_.__/|_|  \\__,_||_|   \\_, |       ==" << endl;
    cout << "==                                       |__/        ==" << endl;
    cout << "=======================================================" << endl;                                                                                                       
	cout << "=======================================================" << endl;
	cout << endl;
}

string menu()
{
	
	string option;
	cout << "========================{ROLES}========================" << endl;
	cout << "              1. Admin (Head Librarian)                " << endl;
	cout << "              2. Librarian (Staff Member)              " << endl;
	cout << "              3. Student (User Member)                 " << endl;
	cout << "-------------------------------------------------------" << endl;
	color(14);
	cout << "                Select who you are: ";
	cin >> option;
	return option;
}

string admin()
{
	color(11);
	string option;
	cout << "-------------------------------------------------------" << endl;
	cout << "========================={ADMIN}=======================" << endl;
	cout << "======================HERE YOU CAN=====================" << endl;
	color(7);
	cout << "                1. View All Books    " << endl;
	cout << "                2. Add New Book      " << endl;
	cout << "                3. Delete Book       " << endl;
	cout << "                4. Update Book       " << endl;
	cout << "                5. View Members      " << endl;
	cout << "                6. Add Member        " << endl;
	cout << "                7. Logout            " << endl;
	color(11);
	cout << "-------------------------------------------------------" << endl;
	cout << "                Enter Your Option: ";
	cin >> option;
	cout << "-------------------------------------------------------" << endl;
	return option;
}

string librarian()
{
	color(11);
	string option;
	cout << "-------------------------------------------------------" << endl;
	cout << "======================={LIBRARIAN}=====================" << endl;
	cout << "======================HERE YOU CAN=====================" << endl;
	color(7);
	cout << "                1. View Borowed Books  " << endl;	
	cout << "                2. Accept  Requests    " << endl;
	cout << "                3. Borrow  Books       " << endl;
	cout << "                4. Return Books        " << endl;
	cout << "                5. Search Book         " << endl;
	cout << "                6. Logout              " << endl;
	color(11);
	cout << "-------------------------------------------------------" << endl;
	cout << "                Enter Your Option: ";
	cin >> option;
	cout << "-------------------------------------------------------" << endl;
	return option;
}

string student()
{
	color(11);
	string option;
	cout << "-------------------------------------------------------" << endl;
	cout << "========================{STUDENT}======================" << endl;
	cout << "======================HERE YOU CAN=====================" << endl;
	color(7);
	cout << "                1. Change Password     " << endl;
	cout << "                2. View All Books      " << endl;	
	cout << "                3. Borrowed Books      " << endl;
	cout << "                4. Request Books       " << endl;
	cout << "                5. Search Books        " << endl;
	cout << "                6. View Fine           " << endl;
	cout << "                7. Logout              " << endl;
	color(11);
	cout << "-------------------------------------------------------" << endl;
	cout << "                Enter Your Option: ";
	cin >> option;
	cout << "-------------------------------------------------------" << endl;
	return option;
}

                // ADMIN FUNCTIONALITY
void viewBooks(int bdx, string title[], string author[], int id[], bool bookAvail[])
{
	color(14);
	cout << "==================AVAILABLE BOOKS ARE==================" << endl;
	bool check=true;
	for(int idx=0; idx<bdx; idx++)
	{
		if(bookAvail[idx]==true)
		{
			color(15);
			cout << "   ::: \"" << title[idx] << "\" by \"" << author[idx] << "\"" << " and ID: " << id[idx] << endl;
			check=false;
		}
	}
	if(check)
	{
		color(12);
		cout << "\n=         ========NO-BOOKS-AVAILABLE=========         =" << endl;
	}	
	color(11);
	cout << "-------------------------------------------------------" << endl;	
	getch();
}

void addBook(int &bdx, string title[], string author[], int id[], bool bookAvail[])
{
	color(14);
	cout << "======================ADDING BOOK======================" << endl;
	string decision="Yes";
	while(decision=="Yes")
	{
		color(14);
		cout << "  Enter Book Title: ";
		cin >> ws;	//cin.ignore();
		getline(cin, title[bdx]);
		
		cout << "  Enter Book Author: ";
		getline(cin, author[bdx]);
		
		cout << "  Enter Book ID: ";
		cin >> id[bdx];

		bool check=false;
		for(int i=0; i<bdx; i++)
		{
			if(id[bdx]==id[i])
			{
				check=true;
				break;
			}		
		}
		
		if(!check)
		{
			color(10);
			bookAvail[bdx] = true;
			cout << endl << "   ::: \"" << title[bdx] << "\" by \"" << author[bdx] << "\"" 
			<< "\n=         ========ADDED-SUCCESSFULLY=========         =" << endl;
			color(11);
			cout << "-------------------------------------------------------" << endl;
			bdx++;
			saveBooks(bdx, title, author, id, bookAvail);
		}
		else
		{
			color(12);
			cout << "\n=         ========BOOK-ALREADY-EXIST=========         =" << endl;
			color(11);
			cout << "-------------------------------------------------------" << endl;
		}
		
		color(14);
		cout << "         Want to Enter Again (Yes/No): ";
		cin >> decision;
		color(11);
		cout << "-------------------------------------------------------" << endl;
	}
	getch();	
}

void delBook(int &bdx, string title[], string author[], int id[], bool bookAvail[], int wdx, int bBookID[])
{
	color(14);
	cout << "======================DELETE BOOK======================" << endl;
	int delID;
	cout << "  Enter Book ID to Delete: ";
	cin >> delID;
	
	int index=-1;
	for(int i=0; i<bdx; i++)
	{
		if(delID==id[i])
		{
			index = i;
			break;
		}
	}
	if(index == -1)
	{
		color(12);
		cout << "\n=         ==========BOOK-NOT-EXIST===========         =" << endl;
	}
	else
	{
		for(int i=0; i<wdx; i++)
		{
			if(bBookID[i] == delID)
			{
				color(12);
				cout << "\n=         ==BOOK IS BORROWED - CAN'T DELETE==         =" << endl;
				color(11);
				cout << "-------------------------------------------------------" << endl;
				getch();
				return;
			}
		}
		
		for(int j=index; j<bdx-1; j++)
		{
			title[j] = title[j+1];
			author[j] = author[j+1];
			id[j] = id[j+1];
			bookAvail[j] = bookAvail[j+1];
		}
		color(10);
		cout << "\n=         ===========BOOK-DELETED============         =" << endl;
		bdx--;
		saveBooks(bdx, title, author, id, bookAvail);
	}
	color(11);
	cout << "-------------------------------------------------------" << endl;
	getch();
}

void updBook(int bdx, string title[], string author[], int id[], bool bookAvail[], int wdx, int bBookID[])
{
	color(14);
	cout << "======================UPDATE BOOK======================" << endl;
	int updID;
	cout << "  Enter Book ID to Update: ";
	cin >> updID;
	
	int index=-1;
	for(int i=0; i<bdx; i++)
	{
		if(updID==id[i])
		{
			index = i;
			break;
		}
	}
	if(index == -1)
	{
		color(12);
		cout << "\n=         ==========BOOK-NOT-EXIST===========         =" << endl;
	}
	else
	{
		for(int i=0; i<wdx; i++)
		{
			if(bBookID[i] == updID)
			{
				color(12);
				cout << "\n=         ==BOOK IS BORROWED - CAN'T UPDATE==         =" << endl;
				color(11);
				cout << "-------------------------------------------------------" << endl;
				getch();
				return;
			}
		}
		
		string newTitle, newAuthor;
		int newID;
		
		cout << "\n   Enter Book Title: ";
		cin >> ws;
		getline(cin, newTitle);
		
		cout << "   Enter Book Author: ";
		getline(cin, newAuthor);
		
		cout << "   Enter Book ID: ";
		cin >> newID;
		
		bool check=false;
		for(int i=0; i<bdx; i++)
		{
			if(i != index && newID==id[i])
			{
				check=true;
				break;
			}		
		}
		
		if(check)
		{
			color(12);
			cout << "\n=         ========BOOK-ALREADY-EXIST=========         =" << endl;	
		}
		else
		{
			title[index] = newTitle;
			author[index] = newAuthor;
			id[index] = newID;
			color(10);
			cout << "\n=         ===========BOOK-UPDATED============         =" << endl;
			saveBooks(bdx, title, author, id, bookAvail);
		}
	}
	
	color(11);
	cout << "-------------------------------------------------------" << endl;
	getch();
}

void viewMems(int mdx, string name[], string regID[], string contact[])
{
	color(14);
	cout << "================REGISTERED MEMBERS ARE=================" << endl;
	bool check=true;
	for(int idx=0; idx<mdx; idx++)
	{
		color(15);
		cout << "   " << idx+1 << ". \"" << name[idx] << "\"    \"" << regID[idx] << "\"    \"" << contact[idx] << "\"" << endl;
		check = false;
	}
	if(check)
	{
		color(12);
		cout << "\n=         =========NO-ONE-REGISTERED=========         =" << endl;
	}
	color(11);
	cout << "-------------------------------------------------------" << endl;
	getch();
}

void addMember(int &mdx, string name[], string regID[], string contact[], string pass[])
{
	color(14);
	cout << "=====================ADDING MEMBER=====================" << endl;
	string decision="Yes";
	while(decision=="Yes")
	{
		color(14);
		cout << "  Enter Member Name: ";
		cin >> ws;	//cin.ignore();
		getline(cin, name[mdx]);
		
		cout << "  Enter Contact Number: ";
		getline(cin, contact[mdx]);
		
		cout << "  Enter Member REG. ID: ";
		cin >> regID[mdx];
		
		cout << "  Create Password: ";
		cin >> pass[mdx];
		
		bool check=false;               // Member Searching
		for(int i=0; i<mdx; i++)
		{
			if(regID[mdx]==regID[i])
			{
				check=true;
				break;
			}	
			
		}
		
		if(!check)
		{
			color(10);
			cout << "\n=         ========ADDED-SUCCESSFULLY=========         =" << endl;
			color(11);
			cout << "-------------------------------------------------------" << endl;
			mdx++;	
			saveMembers(mdx, name, regID, contact, pass);
		}
		else
		{
			color(12);
			cout << "\n=         =======MEMBER-ALREADY-EXIST========         =" << endl;
			color(11);
			cout << "-------------------------------------------------------" << endl;
		}

		color(14);
		cout << "         Want to Enter Again (Yes/No): ";
		cin >> decision;
		color(11);
		cout << "-------------------------------------------------------" << endl;
	}
	getch();
}

                // LIBRARIAN FUNCTIONALITY
void viewBBooks(int wdx, int bdx, int bBookID[], int id[], bool bookAvail[], string bregID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[])
{
	color(14);
	cout << "==================BORROWED BOOKS ARE===================" << endl;

	int bookIndex;
	bool check=true;
	for (int idx=0; idx<wdx; idx++)
	{
		bookIndex = -1;
		for(int i = 0; i < bdx; i++)
		{
	    	if(bBookID[idx] == id[i])
			{
	        	bookIndex = i;
	        	break;
	    	}
		}
		if(bookIndex != -1 && bookAvail[bookIndex] == false)
		{
			color(15);
			cout << " ::: Book ID:" << bBookID[idx] << " is Borrowed by Reg. ID: " << bregID[idx] << "\n     at " << borrowDate[idx] << "-" << borrowMonth[idx]
				<< "-2025 and will be returned at " << returnDate[idx] << "-" << returnMonth[idx] << "-2025." << endl;
			check = false;	
		}	
	}
	if(check)
	{
		color(12);
		cout << "\n=         ========NOTHING-IS-BORROWED========         =" << endl;
	}	
	color(11);
	cout << "-------------------------------------------------------" << endl;
	getch();
}

void viewReqBooks(int &wdx, int bdx, int &rdx, int mdx, string regID[], string name[], string title[], string author[], int id[], bool bookAvail[], string bname[], int bBookID[], string bregID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[], int reqBookID[], string reqMemID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[])
{
	color(14);
	cout << "=====================BOOK APPROVAL=====================" << endl;

	bool check=true;
	for(int i=0; i<rdx; i++)
	{
		color(15);
		cout << "   " << i+1 << ":: BookID: " << reqBookID[i] << " is requested by RegID: " << reqMemID[i] << endl;
		check=false;
	}
	if(check)
	{
		color(12);
		cout << "\n=         ========NOTHING-IS-PENDING=========         =" << endl;
		color(11);
		cout << "-------------------------------------------------------" << endl;
		getch();
		return;
	}
	color(14);
	cout << "\n   Now, Approve OR Decline:" << endl;
	int temp = rdx;
	for(int i=0; i<temp; i++)
	{
		color(14);
		string response;
		cout << "  Request " << i+1 << " (A/D): ";
		cin >> response;
		if(response=="A")
		{
			color(10);
			appBook(wdx, bdx, rdx, mdx, regID, name, title, author, id, bookAvail, bname, bBookID, bregID, borrowDate, borrowMonth, returnDate, returnMonth, reqBookID, reqMemID, reqBDate, reqBMonth, reqRDate, reqRMonth);
		}
		else if(response=="D")
		{
			color(12);
			decBook(rdx, reqBookID, reqMemID, reqBDate, reqBMonth, reqRDate, reqRMonth);
		}
		else
		{
			color(12);
			cout << "=         ==========INVALID--CHOICE==========         =" << endl;
			i--;
		}	
	}

	color(11);
	cout << "-------------------------------------------------------" << endl;
	getch();
}
void appBook(int &wdx, int bdx, int &rdx, int mdx, string regID[], string name[], string title[], string author[], int id[], bool bookAvail[], string bname[], int bBookID[], string bregID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[], int reqBookID[], string reqMemID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[])
{
	for(int i=0; i<mdx; i++)
	{
		if(regID[i] == reqMemID[0])
		{
    		bname[wdx] = name[i];
    		break;
		}
	}

	bBookID[wdx] = reqBookID[0];
	bregID[wdx] = reqMemID[0];
	borrowDate[wdx] = reqBDate[0];
	borrowMonth[wdx] = reqBMonth[0];
	returnDate[wdx] = reqRDate[0];
	returnMonth[wdx] = reqRMonth[0];
	wdx++;
	
	for(int i=0; i<bdx; i++)
	{
    	if(id[i] == reqBookID[0])
		{
			bookAvail[i] = false;
			break;
		}
	}

	for(int j=0; j<rdx-1; j++) 
	{
		reqBookID[j] = reqBookID[j+1];
		reqMemID[j] = reqMemID[j+1];
		reqBDate[j] = reqBDate[j+1];
		reqBMonth[j] = reqBMonth[j+1];
		reqRDate[j] = reqRDate[j+1];
		reqRMonth[j] = reqRMonth[j+1];
	}
	rdx--;
	saveBooks(bdx, title, author, id, bookAvail);
	saveBorrowed(wdx, bname, bregID, bBookID, borrowDate, borrowMonth, returnDate, returnMonth);
	saveRequests(rdx, reqMemID, reqBookID, reqBDate, reqBMonth, reqRDate, reqRMonth);
	cout << "=         ===========BOOK-APPROVED===========         =" << endl;
}
void decBook(int &rdx, int reqBookID[], string reqMemID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[])
{
	for(int j=0; j<rdx-1; j++) 
	{
		reqBookID[j] = reqBookID[j+1];
		reqMemID[j] = reqMemID[j+1];
		reqBDate[j] = reqBDate[j+1];
		reqBMonth[j] = reqBMonth[j+1];
		reqRDate[j] = reqRDate[j+1];
		reqRMonth[j] = reqRMonth[j+1];
	}
	rdx--;
	saveRequests(rdx, reqMemID, reqBookID, reqBDate, reqBMonth, reqRDate, reqRMonth);
	cout << "=         ===========BOOK-DECLINED===========         =" << endl;
}

void borrowBooks(int mdx, int bdx, int &wdx, string regID[], string title[], string author[], int id[], bool bookAvail[], string bname[], string bregID[], int bBookID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[])
{
	color(14);
	cout << "======================BORROW BOOK======================" << endl;
	string decision="Yes";
	while(decision=="Yes")
	{
		color(14);
		string name, reg;
		cout << "  Enter Member Name: ";
		cin >> ws;	//cin.ignore();
		getline(cin, name);                                            
		
		cout << "  Enter Member REG. ID: ";
		cin >> reg;                                                    
		
		bool check0=false;
		for(int idx=0; idx<mdx; idx++)
		{
			if(reg==regID[idx])
			{
				check0=true;
				break;	
			}	
		}
		
		if(check0)
		{
			int book;
			cout << "  Enter Book ID: ";
			cin >> book;                                               
			
			bool check1=false;
			int jdx=0;          
			for(jdx; jdx<bdx; jdx++)
			{
				if(book==id[jdx] && bookAvail[jdx]==true)
				{
					check1=true;
					break;	
				}
			}
			
			if(check1)
			{
				while(true)
				{
					color(14);
					cout << "   Enter Borrow Date (1-30): ";
					cin >> borrowDate[wdx];
					cout << "   Enter Borrow Month (1-12): ";
					cin >> borrowMonth[wdx];
					cout << "   Enter Return Date (1-30): ";
					cin >> returnDate[wdx];
					cout << "   Enter Return Month (1-12): ";
					cin >> returnMonth[wdx];
				
					if(borrowDate[wdx]>0&&borrowDate[wdx]<31 && borrowMonth[wdx]>0&&borrowMonth[wdx]<13 && returnDate[wdx]>0&&returnDate[wdx]<31 && returnMonth[wdx]>0&&returnMonth[wdx]<13)
					{
						bname[wdx] = name;
						bregID[wdx] = reg;
						bBookID[wdx] = book;
						bookAvail[jdx]=false;
						color(10);
						wdx++;
						cout << "\n=         =======BORROWED-SUCCESSFULLY=======         =" << endl;
						saveBooks(bdx, title, author, id, bookAvail);
						saveBorrowed(wdx, bname, bregID, bBookID, borrowDate, borrowMonth, returnDate, returnMonth);
						color(11);
						cout << "-------------------------------------------------------" << endl;
						break;
					}
					else
					{
						color(12);
						cout << "\n=         ===========INVALID--DATE===========         =\n" << endl;
						color(11);
						cout << "-------------------------------------------------------" << endl;
						continue;
					}
				}	
			}
			else
			{
				color(12);
				cout << "\n=         ========BOOK-NOT-AVAILABLE=========         =" << endl;
				color(11);
				cout << "-------------------------------------------------------" << endl;
			}
		}
		else
		{
			color(12);
			cout << "\n=         =======MEMBER-NOT-REGISTERED=======         =" << endl;
			color(11);
			cout << "-------------------------------------------------------" << endl;
		}

		color(14);
		cout << "         Want to Enter Again (Yes/No): ";
		cin >> decision;
		color(11);
		cout << "-------------------------------------------------------" << endl;
	}	
	getch();
}

void returnBooks(int bdx, int &wdx, string title[], string author[], int id[], int bBookID[], bool bookAvail[], string bname[], string bregID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[])
{
	color(14);
	cout << "======================RETURN BOOK======================" << endl;
	int reDate, reMonth, reBookID;
	string bookName;

	cout << "  Enter Book Title: ";
	cin >> ws;	//cin.ignore();
	getline(cin, bookName);
	
	cout << "  Enter Book ID to return: ";
	cin >> reBookID;
	
	int bookIndex = -1;    // Index Searching
	for(int i=0; i<bdx; i++)
	{
    	if(id[i] == reBookID) 
		{
        	bookIndex = i;
      		break;
    	}
	}
	
	if(bookIndex == -1)
    {
    	color(12);
        cout << "\n=         ==========BOOK-NOT-EXIST===========         =" << endl;
        color(11);
        cout << "-------------------------------------------------------" << endl;
        getch();
        return;
    }

	bool check1=false;
	int jdx=0;          
	for(jdx; jdx<wdx; jdx++)
	{
		if(reBookID == bBookID[jdx] && bookAvail[bookIndex] == false)
		{
			check1=true;
			break;	
		}
	}
			
	if(check1)
	{
		cout << "   Enter Return Date (1-30): ";
		cin >> reDate;
		cout << "   Enter Return Month (1-12): ";
		cin >> reMonth;
		
		int fpd = 50, currentFine;
		if(reMonth==returnMonth[jdx])
		{
			if(reDate==returnDate[jdx])
				currentFine=0;
			else if(reDate<returnDate[jdx])
				currentFine=0;
			else
				currentFine= (reDate-returnDate[jdx])*fpd;
		}
		else
		{
			if((reMonth < returnMonth[jdx]))
				currentFine=0;
			else
				currentFine= (reMonth-returnMonth[jdx]-1)*30*fpd + ((30-returnDate[jdx]) + reDate)*fpd;
		}
				
		bookAvail[bookIndex]=true;
		for(int j=jdx; j < wdx-1; j++)
        {
            bBookID[j] = bBookID[j+1];
            bname[j] = bname[j+1];
            bregID[j] = bregID[j+1];
            borrowDate[j] = borrowDate[j+1];
            borrowMonth[j] = borrowMonth[j+1];
            returnDate[j] = returnDate[j+1];
            returnMonth[j] = returnMonth[j+1];
        }
        wdx--;
        color(10);
        saveBooks(bdx, title, author, id, bookAvail);
        saveBorrowed(wdx, bname, bregID, bBookID, borrowDate, borrowMonth, returnDate, returnMonth);
        cout << "\n=         =======RETURNED-SUCCESSFULLY=======         =" << endl;
		cout << "\n                    FINE IS :: " << currentFine << endl;
	}
	else
	{
		color(12);
		cout << "\n=         =========BOOK-NOT-BORROWED=========         =" << endl;
	}
	
	color(11);
	cout << "-------------------------------------------------------" << endl;
	getch();
}

void searchBooks(int bdx, string title[], string author[], int id[], bool bookAvail[])
{
	color(14);
	cout << "======================BOOK SEARCH======================" << endl;
	color(7);
	cout << "                      SEARCH BY: " << endl;
	cout << "                     1. Title    " << endl;
	cout << "                     2. Author   " << endl;
	cout << "                     3. Book ID  " << endl;
	color(11);
	cout << "-------------------------------------------------------" << endl;

	color(14);
	int opt;
	cout << "                   Enter Option: ";
	cin >> opt;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	bool found = false;
	if(opt == 1)
	{
		string t;
		cout << "\n  Enter Book Title: ";
		cin >> ws;
		getline(cin, t);
		
		t = toLower(t);
		
		for(int i=0; i<bdx; i++)
		{
			string bookTitle = toLower(title[i]);
			if(bookTitle.find(t) != string::npos)
			{
				cout << "\n        FOUND:" << endl;
				cout << "        Title       : " << title[i] << endl;
				cout << "        Author      : " << author[i] << endl;
				cout << "        Book ID     : " << id[i] << endl;
				cout << "        Availability: ";
				
				if(bookAvail[i])
					cout << "Available" << endl;
				else
					cout << "Not Available" << endl;
				
				found = true;
			}
		}
	}

	else if(opt == 2)
	{
		string a;
		cout << "  Enter Author Name: ";
		cin >> ws;
		getline(cin, a);
		
		a = toLower(a);

		for(int i=0; i<bdx; i++)
		{
			string bookAuthor = toLower(author[i]);
			if(bookAuthor.find(a) != string::npos)
			{
				cout << "\n       FOUND:" << endl;
				cout << "        Title       : " << title[i] << endl;
				cout << "        Author      : " << author[i] << endl;
				cout << "        Book ID     : " << id[i] << endl;
				cout << "        Availability: ";
				
				if(bookAvail[i])
					cout << "Available" << endl;
				else
					cout << "Not Available" << endl;
				
				found = true;
			}
		}
	}

	else if(opt == 3)
	{
		int ID;
		cout << "  Enter Book ID: ";
		cin >> ID;

		for(int i=0; i<bdx; i++)
		{
			if(id[i] == ID)
			{
				cout << "\n        FOUND:" << endl;
				cout << "        Title       : " << title[i] << endl;
				cout << "        Author      : " << author[i] << endl;
				cout << "        Book ID     : " << id[i] << endl;
				cout << "        Availability: ";
				
				if(bookAvail[i])
					cout << "Available" << endl;
				else
					cout << "Not Available" << endl;
				
				found = true;
				break;
			}
		}
	}

	else
	{
		color(12);
		cout << "\n=         ==========INVALID--CHOICE==========         =" << endl;
		color(11);
		cout << "-------------------------------------------------------" << endl;
		getch();
		return;
	}

	if(!found)
	{
		color(12);
		cout << "\n=         ==========BOOK-NOT-EXIST===========         =" << endl;
	}

	color(11);
	cout << "-------------------------------------------------------" << endl;
	getch();
}

                // STUDENT FUNCTIONALITY
void changePass(int index, int mdx, string name[], string regID[], string contact[], string pass[])
{
	color(14);
	cout << "====================CHANGE PASSWORD====================" << endl;
	string newPass;
	cout << "  Enter New Password: ";
	cin >> newPass;
	
	pass[index] = newPass;
	color(10);
	cout << "\n               Successfully Changed!" << endl;
	saveMembers(mdx, name, regID, contact, pass);
	color(11);
	cout << "-------------------------------------------------------" << endl;
	getch();
}

void viewBorrow(int index, int wdx, string regID[], string bregID[], int bBookID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[])
{
	color(14);
	cout << "====================BORROWED BOOKS=====================" << endl;
	
	bool check = false;
	for(int i=0; i<wdx; i++)
	{
		if(regID[index]==bregID[i])
		{
			check = true;
			color(15);
			cout << " ::: BookID: " << bBookID[i] << endl;
			cout << "     Borrowed at " << borrowDate[i] << "-" << borrowMonth[i]  
			<< "-2025 and return till " << returnDate[i] << "-" << returnMonth[i] << "-2025." << endl;
		}	
	}
	if(!check)
	{
		color(12);
		cout << "\n=         ========NOTHING-IS-BORROWED========         =" << endl;
	}
	color(11);
	cout << "-------------------------------------------------------" << endl;
	getch();
}

void reqBooks(int index, int bdx, int &rdx, int id[], bool bookAvail[], int reqBookID[], string regID[], string reqMemID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[])
{
	color(14);
	cout << "=====================REQUEST BOOK======================" << endl;
	string decision="Yes";
	while(decision=="Yes")
	{
		color(14);
		int reqBook;
		cout << "  Enter Book ID to Request: ";
		cin >> reqBook;
		
		bool check=true;
		for(int i=0; i<bdx; i++)
		{
			if(reqBook==id[i] && bookAvail[i]==true)
			{
				check=false;
				break;
			}
		}
		if(check)
		{
				color(12);
				cout << "\n=         ========BOOK-NOT-AVAILABLE=========         =" << endl;
				color(11);
				cout << "-------------------------------------------------------" << endl;
		}
		else
		{
			bool check0=false; 
			for(int i=0; i<rdx; i++)
			{
				if(reqBook==reqBookID[i])
				{
					check0=true;
					break;
				}			
			}
			if(check0)
			{
				color(12);
				cout << "\n=         ======BOOK-ALREADY-REQUESTED=======         =" << endl;
				color(11);
				cout << "-------------------------------------------------------" << endl;
			}
			else
			{
				while(true)
				{
					color(14);
					cout << "   Enter Borrow Date (1-30): ";
					cin >> reqBDate[rdx];
					cout << "   Enter Borrow Month (1-12): ";
					cin >> reqBMonth[rdx];
					cout << "   Enter Return Date (1-30): ";
					cin >> reqRDate[rdx];
					cout << "   Enter Return Month (1-12): ";
					cin >> reqRMonth[rdx];
					
					if(reqBDate[rdx]>0&&reqBDate[rdx]<31 && reqBMonth[rdx]>0&&reqBMonth[rdx]<13 && reqRDate[rdx]>0&&reqRDate[rdx]<31 && reqRMonth[rdx]>0&&reqRMonth[rdx]<13)
					{
						reqBookID[rdx] = reqBook;
						reqMemID[rdx] = regID[index];
						rdx++;
						saveRequests(rdx, reqMemID, reqBookID, reqBDate, reqBMonth, reqRDate, reqRMonth);
						color(10);
						cout << "\n=         ========BOOK-IS-REQUESTED==========         =" << endl;
						color(11);
						cout << "-------------------------------------------------------" << endl;
						break;	
					}
					else
					{
						color(12);
						cout << "\n=         ===========INVALID--DATE===========         =" << endl;
						color(11);
						cout << "-------------------------------------------------------" << endl;
						continue;
					}
				}	
			}	
		}
		color(14);
		cout << "         Want to Enter Again (Yes/No): ";
		cin >> decision;
		color(11);
		cout << "-------------------------------------------------------" << endl;
	}
	getch();
}

void viewFine(int index, int wdx, string bregID[], string regID[], int bBookID[], int returnMonth[], int returnDate[])
{
	color(14);
	cout << "=====================PENDING FINE======================" << endl;

	int currDate, currMonth;
	cout << "  Enter Today's Date (1-30): ";
	cin >> currDate;
	cout << "  Enter Today's Month (1-12): ";
	cin >> currMonth;

	bool anyFine = false;
	int totalFine = 0;
	int fpd = 50; 

	for(int i=0; i<wdx; i++)
	{
		color(14);
		if(bregID[i] == regID[index])
		{
			int fine = 0;
			if(currMonth == returnMonth[i])
			{
				if(currDate > returnDate[i])
					fine = (currDate - returnDate[i]) * fpd;
			}
			else if(currMonth > returnMonth[i])
			{
				fine = ((currMonth - returnMonth[i] - 1) * 30 * fpd)
					 + ((30 - returnDate[i] + currDate) * fpd);
			}

			if(fine > 0)
			{
				anyFine = true;
				totalFine += fine;
				color(15);
				cout << "\n   Book ID: " << bBookID[i] << " -- Fine: " << fine << endl;
			}
		}
	}

	if(!anyFine)
	{
		color(10);
		cout << "\n=         =======NO--PENDING--FINES==========         =" << endl;
	}
		
	else
	{
		color(12);
		cout << "\n              TOTAL FINE TO PAY: " << totalFine << endl;
	}
	color(11);
	cout << "-------------------------------------------------------" << endl;
	getch();
}

                // FILE HANDLING
void loadBooks(int &bdx, string title[], string author[], int id[], bool bookAvail[])
{
	fstream file;
	file.open("books.txt", ios::in);
	if(!file) return;

	string record;
	while(getline(file, record))
	{
		title[bdx] = getField(record,1);
		author[bdx] = getField(record,2);
		id[bdx] = stoi(getField(record,3));
		bookAvail[bdx] = stoi(getField(record,4));
		bdx++;
	}
	file.close();
}

void loadMembers(int &mdx, string name[], string regID[], string contact[], string pass[])
{
	fstream file;
	file.open("members.txt", ios::in);
	if(!file) return;

	string record;
	while(getline(file, record))
	{
		name[mdx] = getField(record,1);
		regID[mdx] = getField(record,2);
		contact[mdx] = getField(record,3);
		pass[mdx] = getField(record,4);
		mdx++;
	}
	file.close();
}

void loadBorrowed(int &wdx, string bname[], string bregID[], int bBookID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[])
{
	fstream file;
	file.open("borrowed.txt", ios::in);
	if(!file) return;

	string record;
	while(getline(file, record))
	{
		bname[wdx] = getField(record,1);
		bregID[wdx] = getField(record,2);
		bBookID[wdx] = stoi(getField(record,3));
		borrowDate[wdx] = stoi(getField(record,4));
		borrowMonth[wdx] = stoi(getField(record,5));
		returnDate[wdx] = stoi(getField(record,6));
		returnMonth[wdx] = stoi(getField(record,7));
		wdx++;
	}
	file.close();
}

void loadRequests(int &rdx, string reqMemID[], int reqBookID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[])
{
	fstream file;
	file.open("requests.txt", ios::in);
	if(!file) return;

	string record;
	while(getline(file, record))
	{
		reqMemID[rdx] = getField(record,1);
		reqBookID[rdx] = stoi(getField(record,2));
		reqBDate[rdx] = stoi(getField(record,3));
		reqBMonth[rdx] = stoi(getField(record,4));
		reqRDate[rdx] = stoi(getField(record,5));
		reqRMonth[rdx] = stoi(getField(record,6));
		rdx++;
	}
	file.close();
}

void saveBooks(int bdx, string title[], string author[], int id[], bool bookAvail[])
{
	fstream file;
	file.open("books.txt", ios::out);
	for(int i=0;i<bdx;i++)
		file << title[i] << "," << author[i] << "," << id[i] << "," << bookAvail[i] << endl;
	file.close();
}

void saveMembers(int mdx, string name[], string regID[], string contact[], string pass[])
{
	fstream file;
	file.open("members.txt", ios::out);
	for(int i=0;i<mdx;i++)
	{
		file << name[i] << "," << regID[i] << "," << contact[i] << "," << pass[i] << endl;
	}
	file.close();
}

void saveBorrowed(int wdx, string bname[], string bregID[], int bBookID[], int borrowDate[], int borrowMonth[], int returnDate[], int returnMonth[])
{
	fstream file;
	file.open("borrowed.txt", ios::out);
	for(int i=0;i<wdx;i++)
	{
		file << bname[i] << "," << bregID[i] << "," << bBookID[i] << "," << borrowDate[i] << "," << borrowMonth[i] << "," << returnDate[i] << "," << returnMonth[i] << endl;
	}
	file.close();
}

void saveRequests(int rdx, string reqMemID[], int reqBookID[], int reqBDate[], int reqBMonth[], int reqRDate[], int reqRMonth[])
{
	fstream file;
	file.open("requests.txt", ios::out);
	for(int i=0;i<rdx;i++)
		file << reqMemID[i] << "," << reqBookID[i] << "," << reqBDate[i] << "," << reqBMonth[i] << "," << reqRDate[i] << "," << reqRMonth[i] << endl;
	file.close();
}
