#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void add_book()
{
	char isbn[15];
	char book_name[32];
	char author_name[35];
	char publisher_name[35];
	char year[4];
	char edition_number[15];
	int popularity = 0;	
	
	char old_isbn[15];
	char old_book_name[32];
	char old_author_name[35];
	char old_publisher_name[35];
	char old_year[4];
	char old_edition_number[15];
	char old_popularity[15];	
	int flag = 0;
	
	fstream book1;
	book1.open("Books.txt",ios::in);
	
	cin.ignore();
	cout << "Enter ISBN:";
	cin.getline(isbn,16);
	
	while (!book1.eof())
	{
		book1.getline(old_isbn,16,'|');
		book1.getline(old_book_name,33,'|');
		book1.getline(old_author_name,36,'|');
		book1.getline(old_publisher_name,36,'|');
		book1.getline(old_year,5,'|');
		book1.getline(old_edition_number,16,'|');
		book1.getline(old_popularity,'\n');
		if (strcmp(isbn,old_isbn) == 0)
		{
			flag = 1;
			break;
		}
	}
	
	book1.close();
	
	fstream book;
	book.open("Books.txt",ios::app|ios::out);	
	
	if (flag == 0)
	{
		cout << "Enter Book Name:";
		cin.getline(book_name,33);
		
		cout << "Enter Author Name:";
		cin.getline(author_name,36);
		
		cout << "Enter Publisher Name:";
		cin.getline(publisher_name,36);
		
		cout << "Enter The Year Of Publish:";
		cin.getline(year,5);
			
		cout << "Enter Edition Number:";
		cin.getline(edition_number,16);	
	
		book << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << popularity << endl;
		cout << endl;
		cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
		cout << endl << "Added To The File" << endl;
	}
	else
	{
		cout << endl;
		cout << "ISBN Inserted Is Already Exists..." << endl;
	}
		
	book.close();
	cout << endl;
}

void delete_book()
{
	char isbn[15];
	char book_name[32];
	char author_name[35];
	char publisher_name[35];
	char year[4];
	char edition_number[15];
	char popularity[15];
	
	int flag = 0;
	
	char Key[35];
	fstream book_in;
	book_in.open("Books.txt",ios::in);
	fstream book_out;
	book_out.open("temp.txt",ios::out);

	cin.ignore();
	cout << "Enter ISBN: ";
	cin.getline(Key,15);
	cout << endl;
	while (!book_in.eof())
	{
		book_in.getline(isbn,16,'|');
		book_in.getline(book_name,33,'|');
		book_in.getline(author_name,36,'|');
		book_in.getline(publisher_name,36,'|');
		book_in.getline(year,5,'|');
		book_in.getline(edition_number,16,'|');
		book_in.getline(popularity,'\n');
		
		if (strcmp(isbn,Key) != 0)
		{
			if (isbn[0] != 0)
			{
				book_out << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << popularity << endl;
			}
		}
		else
		{
			flag = 1;
			cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
			cout << endl << "Deleted" << endl;
		}
	}
	
	if (flag == 0)
	{
		cout << "Sorry...Record Not Found" << endl;
	}	
	
	book_in.close();
	book_out.close();
	remove("Books.txt");
	rename("temp.txt","Books.txt");
	cout << endl;
}

void update_book()
{
	char isbn[15];
	char book_name[32];
	char author_name[35];
	char publisher_name[35];
	char year[4];
	char edition_number[15];
	char popularity[15];
	
	char new_isbn[15];
	char new_book_name[32];
	char new_author_name[35];
	char new_publisher_name[35];
	char new_year[4];
	char new_edition_number[15];
	int new_popularity = 0;	
	
	int flag = 0;
	int Key;
	char k[15];
	bool canprocess = false;
	
	cin.ignore();
	cout << "Enter ISBN: ";
	cin.getline(k,15);
	cout << endl;
	
	fstream Temp;
	Temp.open("Books.txt",ios::in);	
	
	while (!Temp.eof())
	{
		Temp.getline(isbn,16,'|');
		Temp.getline(book_name,33,'|');
		Temp.getline(author_name,36,'|');
		Temp.getline(publisher_name,36,'|');
		Temp.getline(year,5,'|');
		Temp.getline(edition_number,16,'|');
		Temp.getline(popularity,'\n');
				
		if (strcmp(isbn,k) == 0)
		{
			flag = 1;
			cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
			cout << endl;
			break;
		}
	}
	
	Temp.close();
	
	if (flag == 1)	
	{
		cout << "Update By: " << endl;
		cout << "1-ISBN" << endl;
		cout << "2-Book Name" << endl;
		cout << "3-Author Name" << endl;
		cout << "4-Publisher Name" << endl;
		cout << "5-Year Published" << endl;
		cout << "6-Edition Number" << endl;
		cout << "7-All" << endl;
		cout << "Otherwise-Back" << endl << endl;
		cout << "Choose Process: ";
		
		cin >> Key;
		
		if (Key == 1)
		{
			cin.ignore();
			cout << endl;
			cout << "Enter New ISBN: ";
			cin.getline(new_isbn,16);
			cout << endl;
			canprocess = true;
		}
		else if (Key == 2)
		{
			cin.ignore();
			cout << endl;
			cout << "Enter New Book Name: ";
			cin.getline(new_book_name,33);
			cout << endl;
			canprocess = true;
		}
		else if (Key == 3)
		{
			cin.ignore();
			cout << endl;
			cout << "Enter New Author Name: ";
			cin.getline(new_author_name,36);
			cout << endl;
			canprocess = true;
		}
		else if (Key == 4)
		{
			cin.ignore();
			cout << endl;
			cout << "Enter New Publisher Name: ";
			cin.getline(new_publisher_name,36);
			cout << endl;
			canprocess = true;
		}
		else if (Key == 5)
		{
			cin.ignore();
			cout << endl;
			cout << "Enter New Year Published: ";
			cin.getline(new_year,5);
			cout << endl;
			canprocess = true;
		}		
		else if (Key == 6)
		{
			cin.ignore();
			cout << endl;
			cout << "Enter New Edition Number: ";
			cin.getline(new_edition_number,16);
			cout << endl;
			canprocess = true;
		}
		else if (Key == 7)
		{
			cin.ignore();
			cout << endl;
			cout << "Enter New ISBN: ";
			cin.getline(new_isbn,16);
			
			cout << "Enter New Book Name:";
			cin.getline(new_book_name,33);
			
			cout << "Enter New Author Name:";
			cin.getline(new_author_name,36);
			
			cout << "Enter New Publisher Name:";
			cin.getline(new_publisher_name,36);
			
			cout << "Enter New The Year Of Publish:";
			cin.getline(new_year,5);
				
			cout << "Enter New Edition Number:";
			cin.getline(new_edition_number,16);
			cout << endl;
			canprocess = true;
		}
		else
		{
			cout << endl;
			canprocess = false;
		}
		
		if (canprocess)
		{
			fstream book_in;
			book_in.open("Books.txt",ios::in);
			fstream book_out;
			book_out.open("temp.txt",ios::out);
		
			while (!book_in.eof())
			{
				book_in.getline(isbn,16,'|');
				book_in.getline(book_name,33,'|');
				book_in.getline(author_name,36,'|');
				book_in.getline(publisher_name,36,'|');
				book_in.getline(year,5,'|');
				book_in.getline(edition_number,16,'|');
				book_in.getline(popularity,'\n');
				
				if (strcmp(isbn,k) != 0)
				{
					if (isbn[0] != 0)
					{
						book_out << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << popularity << endl;
					}
				}
				else
				{
					if (Key == 1)
					{
						book_out << new_isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << new_popularity << endl;
						cout << new_isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
						cout << endl << "Updated" << endl;
						cout << endl;
					}
					else if (Key == 2)
					{
						book_out << isbn << '|' << new_book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << new_popularity << endl;
						cout << isbn << ' ' << new_book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
						cout << endl << "Updated" << endl;
						cout << endl;
					}
					else if (Key == 3)
					{
						book_out << isbn << '|' << book_name << '|' << new_author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << new_popularity << endl;
						cout << isbn << ' ' << book_name << ' ' << new_author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
						cout << endl << "Updated" << endl;
						cout << endl;
					}
					else if (Key == 4)
					{
						book_out << isbn << '|' << book_name << '|' << author_name << '|' << new_publisher_name << '|' << year << '|' << edition_number << '|' << new_popularity << endl;
						cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << new_publisher_name << ' ' << year << ' ' << edition_number << endl;
						cout << endl << "Updated" << endl;
						cout << endl;
					}
					else if (Key == 5)
					{
						book_out << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << new_year << '|' << edition_number << '|' << new_popularity << endl;
						cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << new_year << ' ' << edition_number << endl;
						cout << endl << "Updated" << endl;
						cout << endl;
					}
					else if (Key == 6)
					{
						book_out << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << new_edition_number << '|' << new_popularity << endl;
						cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << new_edition_number << endl;
						cout << endl << "Updated" << endl;
						cout << endl;
					}
					else if (Key == 7)
					{
						book_out << new_isbn << '|' << new_book_name << '|' << new_author_name << '|' << new_publisher_name << '|' << new_year << '|' << new_edition_number << '|' << new_popularity << endl;
						cout << new_isbn << ' ' << new_book_name << ' ' << new_author_name << ' ' << new_publisher_name << ' ' << new_year << ' ' << new_edition_number << endl;
						cout << endl << "Updated" << endl;
						cout << endl;
					}																				
				}
			}
			
			book_in.close();
			book_out.close();
			remove("Books.txt");
			rename("temp.txt","Books.txt");
		}
	}
	else
	{
		cout << "Sorry...Record Not Found" << endl << endl;
	}
}

void search_book()
{
	char isbn[15];
	char book_name[32];
	char author_name[35];
	char publisher_name[35];
	char year[4];
	char edition_number[15];
	char popularity[15];
	
	bool canprocess = false;	
	
	int flag = 0;
	int Key;
	char k[36];
	
	cout << "Search By: " << endl;
	cout << "1-ISBN" << endl;
	cout << "2-Book Name" << endl;
	cout << "3-Author Name" << endl;
	cout << "4-Publisher Name" << endl;
	cout << "5-Year Published" << endl;
	cout << "6-Edition Number" << endl;
	cout << "Otherwise-Back" << endl << endl;
	cout << "Choose Process: ";
	cin >> Key;
	
	if (Key == 1)
	{
		cin.ignore();
		cout << endl;
		cout << "Enter ISBN: ";
		cin.getline(k,16);
		cout << endl;
		canprocess = true;
	}
	else if (Key == 2)
	{
		cin.ignore();
		cout << endl;
		cout << "Enter Book Name: ";
		cin.getline(k,33);
		cout << endl;
		canprocess = true;
	}
	else if (Key == 3)
	{
		cin.ignore();
		cout << endl;
		cout << "Enter Author Name: ";
		cin.getline(k,36);
		cout << endl;
		canprocess = true;
	}
	else if (Key == 4)
	{
		cin.ignore();
		cout << endl;
		cout << "Enter Publisher Name: ";
		cin.getline(k,36);
		cout << endl;
		canprocess = true;
	}
	else if (Key == 5)
	{
		cin.ignore();
		cout << endl;
		cout << "Enter Year Published: ";
		cin.getline(k,5);
		cout << endl;
		canprocess = true;
	}		
	else if (Key == 6)
	{
		cin.ignore();
		cout << endl;
		cout << "Enter Edition Number: ";
		cin.getline(k,16);
		cout << endl;
		canprocess = true;
	}
	else {flag = 2;canprocess = false;cout << endl;}
	
	if (canprocess)	
	{
		fstream Book;
		fstream Temp;
		Book.open("Books.txt",ios::in);	
		Temp.open("temp.txt",ios::app|ios::out);
		
		while (!Book.eof())
		{
			Book.getline(isbn,16,'|');
			Book.getline(book_name,33,'|');
			Book.getline(author_name,36,'|');
			Book.getline(publisher_name,36,'|');
			Book.getline(year,5,'|');
			Book.getline(edition_number,16,'|');
			Book.getline(popularity,'\n');
			
			int new_popularity = atoi(popularity);
			
			if (Key == 1)
			{	
				if (strcmp(isbn,k) == 0)
				{
					flag = 1;
					cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
					Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << new_popularity+1 << endl;
				}
				else
				{
					if (isbn[0] != 0)
					{
						Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << popularity << endl;
					}
				}
			}
			else if (Key == 2)
			{	
				if (strcmp(book_name,k) == 0)
				{
					flag = 1;
					cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
					Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << new_popularity+1 << endl;
				}
				else
				{
					if (isbn[0] != 0)
					{
						Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << popularity << endl;
					}
				}
			}
			else if (Key == 3)
			{	
				if (strcmp(author_name,k) == 0)
				{
					flag = 1;
					cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
					Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << new_popularity+1 << endl;
				}
				else
				{
					if (isbn[0] != 0)
					{
						Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << popularity << endl;
					}
				}
			}
			else if (Key == 4)
			{	
				if (strcmp(publisher_name,k) == 0)
				{
					flag = 1;
					cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
					Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << new_popularity+1 << endl;
				}
				else
				{
					if (isbn[0] != 0)
					{
						Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << popularity << endl;
					}
				}
			}
			else if (Key == 5)
			{	
				if (strcmp(year,k) == 0)
				{
					flag = 1;
					cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
					Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << new_popularity+1 << endl;
				}
				else
				{
					if (isbn[0] != 0)
					{
						Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << popularity << endl;
					}
				}
			}
			else if (Key == 6)
			{	
				if (strcmp(edition_number,k) == 0)
				{
					flag = 1;
					cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
					Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << new_popularity+1 << endl;
				}
				else
				{
					if (isbn[0] != 0)
					{
						Temp << isbn << '|' << book_name << '|' << author_name << '|' << publisher_name << '|' << year << '|' << edition_number << '|' << popularity << endl;
					}
				}
			}										
		}
		
		Book.close();
		Temp.close();
		
		remove("Books.txt");
		rename("temp.txt","Books.txt");
		cout << endl;
	}
	
	if (flag == 0)
	{
		cout << "Sorry...Record Not Found" << endl << endl;
	}
}

void charhandler(char c1[],char c2[],int s)
{
	for (int i = 0;i < s;i ++)
	{
		c1[i] = c2[i];
	}
}


void display_book()
{
	char isbn1[15];
	char book_name1[32];
	char author_name1[35];
	char publisher_name1[35];
	char year1[4];
	char edition_number1[15];
	char popularity1[15];
	
	char isbn2[15];
	char book_name2[32];
	char author_name2[35];
	char publisher_name2[35];
	char year2[4];
	char edition_number2[15];
	char popularity2[15];
	
	char isbn[15];
	char book_name[32];
	char author_name[35];
	char publisher_name[35];
	char year[4];
	char edition_number[15];
	char popularity[15];				
	
	bool canprocess = false;	
	
	int Key;
	
	cout << "Sort By: " << endl;
	cout << "1-ISBN" << endl;
	cout << "2-Book Name" << endl;
	cout << "3-Author Name" << endl;
	cout << "4-Publisher Name" << endl;
	cout << "5-Year Published" << endl;
	cout << "6-Edition Number" << endl;
	cout << "Otherwise-Back" << endl << endl;
	cout << "Choose Process: ";
	cin >> Key;	
	cout << endl;
	
	if (Key > 0 && Key < 7) {canprocess = true;}
	
	if (canprocess)
	{
		fstream Book1;
		Book1.open("Books.txt",ios::in);
		fstream Book2;
		Book2.open("Books.txt",ios::in);
		fstream Temp1;
		fstream Temp2;
		Temp1.open("temp.txt",ios::out);		
		
		while(!Book1.eof())
		{
			Book1.getline(isbn1,16,'|');
			Book1.getline(book_name1,33,'|');
			Book1.getline(author_name1,36,'|');
			Book1.getline(publisher_name1,36,'|');
			Book1.getline(year1,5,'|');
			Book1.getline(edition_number1,16,'|');
			Book1.getline(popularity1,'\n');
			
			if (isbn1[0] != 0)
			{
				Temp1 << isbn1 << '|' << book_name1 << '|' << author_name1 << '|' << publisher_name1 << '|' << year1 << '|' << edition_number1 << '|' << popularity1 << endl;
			}
		}
		
		Temp1.close();
		Book1.close();	
		
		int read = 0;	
		Book1.open("Books.txt",ios::in);
		
		while(!Book1.eof())
		{
			Book1.getline(isbn1,16,'|');
			Book1.getline(book_name1,33,'|');
			Book1.getline(author_name1,36,'|');
			Book1.getline(publisher_name1,36,'|');
			Book1.getline(year1,5,'|');
			Book1.getline(edition_number1,16,'|');
			Book1.getline(popularity1,'\n');
			
			charhandler(isbn,isbn1,15);
			charhandler(book_name,book_name1,32);
			charhandler(author_name,author_name1,35);
			charhandler(publisher_name,publisher_name1,35);
			charhandler(year,year1,4);
			charhandler(edition_number,edition_number1,15);						

			if (isbn1[0] != 0)
			{					
				read = 0;			
				Temp2.open("temp.txt",ios::in);
				while(!Temp2.eof())
				{	
					Temp2.getline(isbn2,16,'|');
					Temp2.getline(book_name2,33,'|');
					Temp2.getline(author_name2,36,'|');
					Temp2.getline(publisher_name2,36,'|');
					Temp2.getline(year2,5,'|');
					Temp2.getline(edition_number2,16,'|');
					Temp2.getline(popularity2,'\n');										

					if (isbn2[0] != 0)
					{
						if (read == 0)
						{
							charhandler(isbn,isbn2,15);
							charhandler(book_name,book_name2,32);
							charhandler(author_name,author_name2,35);
							charhandler(publisher_name,publisher_name2,35);
							charhandler(year,year2,4);
							charhandler(edition_number,edition_number2,15);	
							read = 1;					
						}
												
						if (Key == 1)
						{
							if (strcmp(isbn,isbn2) > 0) 
							{
								charhandler(isbn,isbn2,15);
								charhandler(book_name,book_name2,32);
								charhandler(author_name,author_name2,35);
								charhandler(publisher_name,publisher_name2,35);
								charhandler(year,year2,4);
								charhandler(edition_number,edition_number2,15);
							}
						}
						else if (Key == 2)
						{
							if (strcmp(book_name,book_name2) > 0) 
							{
								charhandler(isbn,isbn2,15);
								charhandler(book_name,book_name2,32);
								charhandler(author_name,author_name2,35);
								charhandler(publisher_name,publisher_name2,35);
								charhandler(year,year2,4);
								charhandler(edition_number,edition_number2,15);
							}
						}
						else if (Key == 3)
						{
							if (strcmp(author_name,author_name2) > 0) 
							{
								charhandler(isbn,isbn2,15);
								charhandler(book_name,book_name2,32);
								charhandler(author_name,author_name2,35);
								charhandler(publisher_name,publisher_name2,35);
								charhandler(year,year2,4);
								charhandler(edition_number,edition_number2,15);
							}
						}
						else if (Key == 4)
						{
							if (strcmp(publisher_name,publisher_name2) > 0) 
							{
								charhandler(isbn,isbn2,15);
								charhandler(book_name,book_name2,32);
								charhandler(author_name,author_name2,35);
								charhandler(publisher_name,publisher_name2,35);
								charhandler(year,year2,4);
								charhandler(edition_number,edition_number2,15);
							}
						}
						else if (Key == 5)
						{
							if (strcmp(year,year2) > 0) 
							{
								charhandler(isbn,isbn2,15);
								charhandler(book_name,book_name2,32);
								charhandler(author_name,author_name2,35);
								charhandler(publisher_name,publisher_name2,35);
								charhandler(year,year2,4);
								charhandler(edition_number,edition_number2,15);
							}
						}
						else if (Key == 6)
						{
							if (strcmp(edition_number,edition_number2) > 0) 
							{
								charhandler(isbn,isbn2,15);
								charhandler(book_name,book_name2,32);
								charhandler(author_name,author_name2,35);
								charhandler(publisher_name,publisher_name2,35);
								charhandler(year,year2,4);
								charhandler(edition_number,edition_number2,15);
							}
						}																														
					}
					else {break;}				
				}
				Temp2.close();
				cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
				
				Temp2.open("temp.txt",ios::in);
				Temp1.open("temp1.txt",ios::out);
				while(!Temp2.eof())
				{
					Temp2.getline(isbn1,16,'|');
					Temp2.getline(book_name1,33,'|');
					Temp2.getline(author_name1,36,'|');
					Temp2.getline(publisher_name1,36,'|');
					Temp2.getline(year1,5,'|');
					Temp2.getline(edition_number1,16,'|');
					Temp2.getline(popularity1,'\n');
					
					if (isbn1[0] != 0)
					{
						if (strcmp(isbn,isbn1) != 0)
						{
							Temp1 << isbn1 << '|' << book_name1 << '|' << author_name1 << '|' << publisher_name1 << '|' << year1 << '|' << edition_number1 << '|' << popularity1 << endl;
						}
					}
				}
				
				Temp2.close();
				Temp1.close();
				remove("temp.txt");
				rename("temp1.txt","temp.txt");		
			}
			else {break;}			
		}
		Book1.close();
		Temp1.close();
		remove("temp.txt");				
	}
	cout << endl;	
}

void display_popular()
{
	char isbn1[15];
	char book_name1[32];
	char author_name1[35];
	char publisher_name1[35];
	char year1[4];
	char edition_number1[15];
	char popularity1[15];
	
	char isbn2[15];
	char book_name2[32];
	char author_name2[35];
	char publisher_name2[35];
	char year2[4];
	char edition_number2[15];
	char popularity2[15];
	
	char isbn[15];
	char book_name[32];
	char author_name[35];
	char publisher_name[35];
	char year[4];
	char edition_number[15];
	char popularity[15];					
	
	int flag = 0;
	
	fstream Book1;
	Book1.open("Books.txt",ios::in);
	fstream Book2;
	Book2.open("Books.txt",ios::in);
	fstream Temp1;
	fstream Temp2;
	Temp1.open("temp.txt",ios::out);		
	
	while(!Book1.eof())
	{
		Book1.getline(isbn1,16,'|');
		Book1.getline(book_name1,33,'|');
		Book1.getline(author_name1,36,'|');
		Book1.getline(publisher_name1,36,'|');
		Book1.getline(year1,5,'|');
		Book1.getline(edition_number1,16,'|');
		Book1.getline(popularity1,'\n');
		
		if (isbn1[0] != 0)
		{
			Temp1 << isbn1 << '|' << book_name1 << '|' << author_name1 << '|' << publisher_name1 << '|' << year1 << '|' << edition_number1 << '|' << popularity1 << endl;
		}
	}
	
	Temp1.close();
	Book1.close();	
	
	int read = 0;	
	Book1.open("Books.txt",ios::in);
	
	int newpopularity;
	
	while(!Book1.eof())
	{
		Book1.getline(isbn1,16,'|');
		Book1.getline(book_name1,33,'|');
		Book1.getline(author_name1,36,'|');
		Book1.getline(publisher_name1,36,'|');
		Book1.getline(year1,5,'|');
		Book1.getline(edition_number1,16,'|');
		Book1.getline(popularity1,'\n');
		
		charhandler(isbn,isbn1,15);
		charhandler(book_name,book_name1,32);
		charhandler(author_name,author_name1,35);
		charhandler(publisher_name,publisher_name1,35);
		charhandler(year,year1,4);
		charhandler(edition_number,edition_number1,15);	
		charhandler(popularity,popularity1,15);					
	
		if (isbn1[0] != 0)
		{					
			read = 0;			
			Temp2.open("temp.txt",ios::in);
			while(!Temp2.eof())
			{
				
				Temp2.getline(isbn2,16,'|');
				Temp2.getline(book_name2,33,'|');
				Temp2.getline(author_name2,36,'|');
				Temp2.getline(publisher_name2,36,'|');
				Temp2.getline(year2,5,'|');
				Temp2.getline(edition_number2,16,'|');
				Temp2.getline(popularity2,'\n');
			
				if (isbn2[0] != 0)
				{
					if (read == 0)
					{
						charhandler(isbn,isbn2,15);
						charhandler(book_name,book_name2,32);
						charhandler(author_name,author_name2,35);
						charhandler(publisher_name,publisher_name2,35);
						charhandler(year,year2,4);
						charhandler(edition_number,edition_number2,15);	
						charhandler(popularity,popularity2,15);
						read = 1;					
					}
											
					if (atoi(popularity) < atoi(popularity2)) 
					{
						charhandler(isbn,isbn2,15);
						charhandler(book_name,book_name2,32);
						charhandler(author_name,author_name2,35);
						charhandler(publisher_name,publisher_name2,35);
						charhandler(year,year2,4);
						charhandler(edition_number,edition_number2,15);
						charhandler(popularity,popularity2,15);
					}
																														
				}
				else {break;}
			}
			
			Temp2.close();
			if (atoi(popularity) > 4)
			{
				flag = 1;
				cout << isbn << ' ' << book_name << ' ' << author_name << ' ' << publisher_name << ' ' << year << ' ' << edition_number << endl;
			}
			
			if (flag == 1)
			{	
				Temp2.open("temp.txt",ios::in);
				Temp1.open("temp1.txt",ios::out);
				while(!Temp2.eof())
				{
					Temp2.getline(isbn1,16,'|');
					Temp2.getline(book_name1,33,'|');
					Temp2.getline(author_name1,36,'|');
					Temp2.getline(publisher_name1,36,'|');
					Temp2.getline(year1,5,'|');
					Temp2.getline(edition_number1,16,'|');
					Temp2.getline(popularity1,'\n');
					
					if (isbn1[0] != 0)
					{
						if (strcmp(isbn,isbn1) != 0)
						{
							Temp1 << isbn1 << '|' << book_name1 << '|' << author_name1 << '|' << publisher_name1 << '|' << year1 << '|' << edition_number1 << '|' << popularity1 << endl;
						}
					}
				}
				
				Temp2.close();
				Temp1.close();
				remove("temp.txt");
				rename("temp1.txt","temp.txt");
			}
			
		}
		else {break;}			
	}
	Book1.close();
	Temp1.close();
	remove("temp.txt");	
	
	if (flag == 0) {cout << "No Books Were Found" << endl;}
					
	cout << endl;	
}
void process(int n)
{
	char del_by[15];
	switch (n)
	{
		case 1: add_book();break;
		case 2: delete_book();break;
		case 3: update_book();break;
		case 4: search_book();break;
		case 5: display_book();break;
		case 6: display_popular();break;
	}
}

void menu()
{
	cout <<'\t'<<"****************" << endl;
	cout <<'\t'<<"*Library System*" << endl;
	cout <<'\t'<<"****************" << endl;
	int key;
	int quitkey = 7;
	char k = 'n';
	while (k == 'n')
	{
		key = -1;
		while (key != quitkey)
		{
			int pnum = 1;
			cout <<"What Do You Want To Do?" << endl;
			cout << pnum << "-Add Book" << endl;
			pnum++;
			cout << pnum << "-Delete Book" << endl;
			pnum++;
			cout << pnum << "-Update Book" << endl;
			pnum++;
			cout << pnum << "-Search Book" << endl;
			pnum++;
			cout << pnum << "-Display All Books" << endl;
			pnum++;
			cout << pnum << "-Display The Most Popular Books" << endl;
			pnum++;
			cout << pnum << "-Quit" << endl << endl;
			
			cout << "Choose Process: ";
			cin >> key;
			cout << endl;
			process(key);				
		}
		
		cout << "Are You Sure?(y/n)?: ";
		cin >> k;
		cout << endl;
	}
}

int main()
{
	menu();
	return 0;
}
