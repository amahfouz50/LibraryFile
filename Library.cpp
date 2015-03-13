#include <fstream.h>
#include <iostream.h>
#include <cstring>

/*
 *   I am Ahmed Reda Mahfouz
 *   Student at the Faculty of Computing and Information Menoufia University 
 *   Department of Computer Science
 *
 *   *       Please Visit us at www.github.com/amahfouz50     *
 *  This Program was Developed by www.github.com/amahfouz50 forums Team
 *  *           Please Don't Remove This Comment       *
 */  

/**
 *
 *   @author Ahmed Mahfouz
 */

class Library
{
public:
	char ISBN[12];
	char BookName[20];
	char AutherName[15];
	char PublisherName[15];
	char YearOfPublishing[4];
	char EditionNumber[3];

	Library()
	{
		ISBN[0]=0;
	    BookName[0]=0;
	    AutherName[0]=0;
	    PublisherName[0]=0;
	    YearOfPublishing[0]=0;
	    EditionNumber[0]=0;
	}

// ENTERING A NEW BOOK
void EnterBook()
{
	fstream f;
	Library x;
	char LibraryFile[30];
	char ch;
	f.open(LibraryFile , ios::app);
	do
	{
		cout<<"Enter the ISBN :";
		cin>>x.ISBN;
		cout<<"Enter the Book Name :";
		cin>>x.BookName;
		cout<<"Enter the Auther Name :";
		cin>>x.AutherName;
		cout<<"Enter the Publisher Name :";
		cin>>x.PublisherName;
		cout<<"Enter the Year of Publishing :";
		cin>>x.YearOfPublishing;
		cout<<"Enter the Edition Number :";
		cin>>x.EditionNumber;
		cout<<"Do you want to add another Book [Y , N] ?";
		cin>>ch;
	}
	while(ch=='Y');
	f.close();
}

// CHECKING FOR ISBN
void CheckISBN()
{
	fstream f;
	Library x;
	char LibraryFile[30];
	f.open(LibraryFile , ios::in);
	while(!f.eof())
	{
		f.getline(x.ISBN , 12);
		if(!strcmp(ISBN , x.ISBN))
		{
			cout<<"This ISBN is already in the file , Please check it \n";
		}
	}
	f.close();
}

// DISPLAYING THE CONTENTS OF THE FILE
void DisplayBook()
{
	fstream f;
	Library x;
	char LibraryFile[30];
	f.open(LibraryFile , ios::in);
	while(!f.eof())
	{
		f<<x.ISBN<<"|"<<x.BookName<<"|"<<x.AutherName<<"|"<<x.PublisherName<<"|"
			<<x.YearOfPublishing<<"|"<<x.EditionNumber<<"/n";
	}
	f.close();
}

// SEARCHING FOR BOOK
void SearchBook()
{
fstream f;
Library x;
char LibraryFile[30];
int flag = 0;
char ISBN[12];
cout<<"Enter the ISBN :";
cin>>ISBN;
f.open(LibraryFile , ios::in);
while(!f.eof())
{
	f.getline(x.ISBN , 12 , '|');
	f.getline(x.BookName , 20 , '|');
	f.getline(x.AutherName , 15 , '|');
	f.getline(x.YearOfPublishing , 4);
	if(!strcmp(ISBN , x.ISBN))
	{
		cout<<"The Book is Founded :"<<"/n";
		cout<<x.ISBN<<"/t";
		cout<<x.BookName<<"/t";
		cout<<x.AutherName<<"/t";
		cout<<x.PublisherName<<"/t";
		cout<<x.YearOfPublishing<<"/t";
		cout<<x.EditionNumber<<endl;
		flag = 1;
	}
}
f.close();
if(flag == 0)
cout<<"\n The Book is not in the Library : \n";
}

// DELETING A BOOK USING ISBN
void DeleteBook()
{
	fstream f;
	Library x;
	char LibraryFile[30];
	char newfile[30];
	char ISBN[12];
	cout<<"Enter the ISBN :";
	cin>>ISBN;
	f.open(LibraryFile , ios::in);
	while(!f.eof())
	{
		f.open(newfile , ios::app);
		if(strcmp(ISBN , x.ISBN))
		{
			f<<x.ISBN<<" "<<x.BookName<<" "<<x.AutherName<<" "<<x.PublisherName<<" "
			<<x.YearOfPublishing<<" "<<x.EditionNumber<<"/n";
		}
		f.close();
	}
	f.close();
	f.open(newfile , ios::in);
	while(!f.eof())
	{
		f.open(LibraryFile , ios::out);
		f<<x.ISBN<<" "<<x.BookName<<" "<<x.AutherName<<" "<<x.PublisherName<<" "
		<<x.YearOfPublishing<<" "<<x.EditionNumber<<"/n";
		f.close();
	}
	f.close();
}
};

// MAIN METHOD
int main()
{
Library c;
int ch;
cout<<"1) Add a new Book \n";
cout<<"2) Read the entire Library \n";
cout<<"3) Search for a Book \n";
cout<<"4) Delete a Book \n";
cout<<"Enter your choise :";
cin>>ch;
switch(ch)
{
case 1:
	c.EnterBook();
	break;
case 2:
	c.DisplayBook();
	break;
case 3:
	c.SearchBook();
	break;
case 4:
	c.DeleteBook();
	break;
default :
	cout<<"Wrong cloise \n";
	break;
}
}