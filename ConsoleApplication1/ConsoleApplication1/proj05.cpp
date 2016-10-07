#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//STRUCTURE
struct ebooks {

	string title;
	string author;
	string publisher;
	int year;
	int pages;
	double cost;
};

//PROTOTYPES
ebooks input();											//user inputs properties for each book
int fill(ebooks[], int);								//calls previous function to do for multiple books
void print(ebooks);										//couts information for book
void output(ebooks[], int);								//calls function to cout information for each book
void authorSorter(ebooks[], int);						//sorts ebook list by author name
void titleSorter(ebooks[], int);						//sorts ebook list by title name
void costSorter(ebooks[], int);							//sorts ebook list by cost
void pageSorter(ebooks[], int);							//sorts ebook list by no. of pages
void costCalc(ebooks[], int, double&, double&);			//calculates total and average cost of ebook list

/*
Divya Jagadeesh
CMPSC 121 - Spring 2015
Sec 004

Purpose:	The purpose of the main function is to create a menu system in which the user may select from a series of options as to what
			they'd like to do to their ebook list. The options include: making a new ebook list, ouputting the list, sorting the list by 
			author/title/cost/no.pgs, and calculating the total/average cost of the book list.
Input:		books[50] (array of ebooks with ebooks data type)
			actualNumofBooks (actual number of user inputted books into the array)
			tot (total cost of books) *passed by reference*
			avg (average cost of books) *passed by reference*
			option (user inputted option)
Output:		actualNumofBooks
			fill(books, 50)
			output(books, actualNumofBooks) (function that outputs book list) 
			authorSorter(books, actualNumofBooks) (function that sorts ebook list based on authors' names)
			titleSorter(books, actualNumofBooks) (function that sorts ebook list based on titles)
			costSorter(books, actualNumofBooks) (function that sorts ebook list based on cost of books)
			pageSorter(books, actualNumofBooks) (function that sorts ebook list based on number of pages)
			costCalc(books, actualNumofBooks, tot, avg) (function that calculates the total and average cost of all the books)
Processing: A switch statement is used to detmermine what functions should output.
			The switch statement is in a while loop that keeps running until the user decides to quit the program.
			cout << "E-book tracker options:\n"
			<< "1. To make a new e-book list type 'F'\n"
			<< "2. To output your e-book list type 'O'\n"
			<< "3. To sort the list by ascending author names type 'A'\n"
			<< "4. To sort the list by ascending titles names type 'T'\n"
			<< "5. To sort the list by descending cost type 'C'\n"
			<< "6. To sort the list by descending number of pages type 'P'\n"
			<< "7. To calculate the total and average cost of all your e-books type 'L'\n"
			<< "Type 'Q' to quit.\n"
			<< "What would you like to do? ";
			cin >> option;
*/

int main() {

	ebooks books[50];
	int actualNumofBooks = 0;			//number of user inputted books
	double tot = 0;						//total cost
	double avg = 0;						//average cost
	char option = 'f';					//user inputted option for menu

	cout << "Welcome to your e-book tracker! " << endl << endl;

	while (option != 'q' && option != 'Q') //menu keeps going until user wants to quit
	{
		switch (option) {
		case 'f':
		case 'F':
			actualNumofBooks = fill(books, 50);			//asks user for ebook info
			break;
		case 'o':
		case 'O':
			output(books, actualNumofBooks);				//outputs ebook list
			break;
		case 'a':
		case 'A':
			authorSorter(books, actualNumofBooks);			//sorts list by author names
			output(books, actualNumofBooks);				//outputs list sorted by author names
			break;
		case 't':
		case 'T':
			titleSorter(books, actualNumofBooks);			//sorts list by title names
			output(books, actualNumofBooks);				//outputs list sorted by title names
			break;
		case 'c':
		case 'C':
			costSorter(books, actualNumofBooks);			//sorts list by cost
			output(books, actualNumofBooks);				//outputs list by cost
			break;
		case 'p':
		case 'P':
			pageSorter(books, actualNumofBooks);			//sorts list by no. of pages
			output(books, actualNumofBooks);				//outputs list by no. of pages
			break;
		case 'l':
		case 'L':
			costCalc(books, actualNumofBooks, tot, avg);	//calculates total and average cost
			cout << "The total cost of the books is $" << tot << "." <<
				endl << "The average cost of the books is $" << avg << ".\n\n";
		default:
			cout << "PLEASE ENTER A VIABLE OPTION!!!\n\n";
			break;
		}
		//menu list
		cout << "E-book tracker options:\n"
			<< "1. To make a new e-book list type 'F'\n"
			<< "2. To output your e-book list type 'O'\n"
			<< "3. To sort the list by ascending author names type 'A'\n"
			<< "4. To sort the list by ascending titles names type 'T'\n"
			<< "5. To sort the list by descending cost type 'C'\n"
			<< "6. To sort the list by descending number of pages type 'P'\n"
			<< "7. To calculate the total and average cost of all your e-books type 'L'\n"
			<< "Type 'Q' to quit.\n"
			<< "What would you like to do? ";
		cin >> option;
		cin.ignore(1, '\n');
		cout << endl;
	}

	cout << "Thank you for using e-book tracker." << endl;

	return 0;
}

/*
Divya Jagadeesh
CMPSC 121 - Spring 2015
Sec 004

Purpose:	The purpose of this function is to receive user inputted information for the ebook structure.
Input:		book (data type ebook)
			MORE SPECIFICALLY:
			book.title
			book.author
			book.publisher
			book.year
			book.pages
			book.cost
Output:		book (returned)
Processing:	The user is asked to enter a title, an author, a publisher, a copyright year, the number of pages, and book cost to the variable
			book with data types ebooks.
			e.g.	cout << "Enter the title of the book: ";
					getline(cin, book.title);
*/

ebooks input() {

	ebooks book;

	cout << "Enter the title of the book: ";	
	getline(cin, book.title);					//asks user for title of book

	cout << "Enter the name of the author: ";
	getline(cin, book.author);					//asks user for author of book

	cout << "Enter the name of the publisher: ";
	getline(cin, book.publisher);				//asks user for publisher of book

	cout << "Enter the copyright year: ";
	cin >> book.year;							//asks user for year of book

	cout << "Enter the number of pages in the book: ";
	cin >> book.pages;							//asks user for no. of pages of book

	cout << "Enter the cost of the book: $";
	cin >> book.cost;							//asks user for cost of book

	return book;
}

/*
Divya Jagadeesh
CMPSC 121 - Spring 2015
Sec 004

Purpose:	The purpose of this function is to have the user inputted books stored into an ebook array.
Input:		fillbooks[50] (array of ebooks with ebooks data type)
			max (maximum size array is allowed to be)
Output:		actually (actual number of user inputted ebooks in array)
Processing:	A while loop is used to keep reasking user whether they'd like to add another book to their ebook list. 
			The input function is called.
			fillBooks[actually] = input();
			An if statement confirms that once the list has reached its max size (50 books), the user will not be asked the option of whether
			they'd like to add another ebook to their list.
			cout << "Would you like to add another ebook to your list? (Y or N): ";
			cin >> user;
*/

int fill(ebooks fillBooks[50], int max) {

	int actually = 0;		//number of elements actually stored in array
	char user = 'y';		//user inputted yes or no

	while ((user == 'y' || user == 'Y') && actually < max)
	{
		fillBooks[actually] = input();		//fills array with ebook information
		actually++;
		if (actually <= max - 1) {
			cout << "Would you like to add another ebook to your list? (Y or N): ";		//asks user if they'd like to add another book
			cin >> user;
			cin.ignore(1, '\n');
		}
		cout << endl;
	}

	return actually;		//number of user inputted books
}

/*
Divya Jagadeesh
CMPSC 121 - Spring 2015
Sec 004

Purpose:	The purpose of this function is to print the properties of the ebook to the console screen.
Input:		thisBook (variable of ebooks data type)
Output:		thisBook.title
			thisBook.author
			thisBook.publisher
			thisBook.year
			thisBook.pages
			thisBook.cost
Processing:	The properties of the ebook are coutted.
			e.g. cout << "The title of the book is " << thisBook.title << "." << endl;
*/

void print(ebooks thisBook) {		//thisBook - just used to output each property

	cout << "The title of the book is " << thisBook.title << "." << endl;				//couts user inputted title
	cout << "The author of the book is " << thisBook.author << "." << endl;				//couts user inputted author
	cout << "The publisher of the book is " << thisBook.publisher << "." << endl;		//couts user inputted publisher
	cout << "The copyright year of the book is " << thisBook.year << "." << endl;		//couts user inputted year
	cout << "The number of pages in the book is " << thisBook.pages << "." << endl;		//couts user inputted pages
	cout << "The cost of the book is $" << setprecision(2) << fixed << showpoint << thisBook.cost << "." << endl;	//couts user inputted cost

}

/*
Divya Jagadeesh
CMPSC 121 - Spring 2015
Sec 004

Purpose:	The purpose of this function is to call the print function on each book in the ebooks array and print the book information.
Input:		outputBooks[] (array of books with ebooks data type)
			actual (actual number of user inputted books into the array)
Output:		print(outputBooks[i]) (the print function)
Processing:	In a for loop, the print function is called on each user inputted ebook to print the property details of the ebook.
			print(outputBooks[i]);
*/

void output(ebooks outputBooks[], int actual) {		//actual = actual number of books

	for (int i = 0; i < actual; i++) {		//outputs information for each user inputted book
		print(outputBooks[i]);
		cout << endl;
	}

}

/*
Divya Jagadeesh
CMPSC 121 - Spring 2015
Sec 004

Purpose:	The purpose of this function is to sort the ebooks array by authors in ascending order.
Input:		authorBooks[] (array of books with ebooks data type)
			actualAuthor (actual number of user inputted books into the array)
Output:		
Processing:	A do-while loop, for loop, and if statement are used to sort the array of books by ascending author names, using bubble sort.
			temp = authorBooks[i + 1];                    
			authorBooks[i + 1] = authorBooks[i];
			authorBooks[i] = temp;
*/

void authorSorter(ebooks authorBooks[], int actualAuthor) {		//ascending author, bubble sort

	ebooks temp;	//temperary variable
	int counter;	//counts every time a swap is made

	do {
		counter = 0;
		for (int i = 0; i < actualAuthor - 1; i++) {
			if (authorBooks[i + 1].author < authorBooks[i].author) {
				//swap
				temp = authorBooks[i + 1];                    
				authorBooks[i + 1] = authorBooks[i];
				authorBooks[i] = temp;
				counter++; //increment counter
			}
		}
	} while (counter != 0);	//stops when counter isn't incremented anymore
	
}

/*
Divya Jagadeesh
CMPSC 121 - Spring 2015
Sec 004

Purpose:	The purpose of this function is to sort the ebooks array by titles in ascending order.
Input:		titleBooks[] (array of books with ebooks data type)
			actualTitle (actual number of user inputted books into the array)
Output:
Processing:	A for loop and while loop are used to sort the array of books by ascending title names, using insertion sort.
			temp = titleBooks[j];
			titleBooks[j] = titleBooks[j - 1];
			titleBooks[j - 1] = temp;
*/

void titleSorter(ebooks titleBooks[], int actualTitle) {			//ascending title, insertion sort

	int j;				//index marker
	ebooks temp;		//temperary variable

	for (int i = 1; i < actualTitle; i++){
		j = i;
		while (j > 0 && titleBooks[j].title < titleBooks[j - 1].title){
			//swap
			temp = titleBooks[j];
			titleBooks[j] = titleBooks[j - 1];
			titleBooks[j - 1] = temp;
			j--;	//decrementer
		}
	}

}

/*
Divya Jagadeesh
CMPSC 121 - Spring 2015
Sec 004

Purpose:	The purpose of this function is to sort the ebooks array by cost in descending order.
Input:		costBooks[] (array of books with ebooks data type)
			actualCost (actual number of user inputted books into the array)
Output:
Processing:	A nested for loop and if statement are used to sort the array of books by descending cost, using selection sort.
			temp = costBooks[maxindex];
			costBooks[maxindex] = costBooks[i];
			costBooks[i] = temp;
*/

void costSorter(ebooks costBooks[], int actualCost){			//descending cost, selection sort

	ebooks temp;		//temperary variable
	int maxindex;		//index marker
	//int counter;

	for (int i = 0; i < actualCost - 1; i++) {
		maxindex = i;				//setting maxindex
		for (int j = i + 1; j < actualCost; j++) {
			if (costBooks[j].cost > costBooks[maxindex].cost) {
				maxindex = j;		//swaps maxindex if finds a bigger value
			}
		}
		//swap
		temp = costBooks[maxindex];
		costBooks[maxindex] = costBooks[i];
		costBooks[i] = temp;
	}

}

/*
Divya Jagadeesh
CMPSC 121 - Spring 2015
Sec 004

Purpose:	The purpose of this function is to sort the ebooks array by pages in descending order.
Input:		pageBooks[] (array of books with ebooks data type)
			actualPage (actual number of user inputted books into the array)
Output:
Processing:	A nested for loop and if statement are used to sort the array of books by descending number of pages, using selection sort.
			temp = pageBooks[maxindex];
			pageBooks[maxindex] = pageBooks[i];
			pageBooks[i] = temp;
*/

void pageSorter(ebooks pageBooks[], int actualPage) {			//descending # of pages, selection sort

	ebooks temp;		//temperary variable
	int maxindex;
	//int counter;

	for (int i = 0; i < actualPage - 1; i++) {
		maxindex = i;				//setting maxindex
		for (int j = i + 1; j < actualPage; j++) {
			if (pageBooks[j].pages > pageBooks[maxindex].pages) {
				maxindex = j;		//swaps maxindex if finds a bigger value
			}
		}
		//swap
		temp = pageBooks[maxindex];
		pageBooks[maxindex] = pageBooks[i];
		pageBooks[i] = temp;
	}

}

/*
Divya Jagadeesh
CMPSC 121 - Spring 2015
Sec 004

Purpose:	The purpose of this function is to calculate the total cost and average cost of all the user inputted ebooks.
Input:		calcBooks[] (array of books with ebooks data type)
			actualCalc (actual number of user inputted books into the array)
			total (total cost) *passed by reference*
			average (average cost) *passed by reference*
Output:		total
			average
Processing:	A for loop is used to calculate the total cost of all the books. 
			total += calcBooks[i].cost;
			Outside the for loop the average cost is calculated.
			average = total / actualCalc;
*/

void costCalc(ebooks calcBooks[], int actualCalc, double& total, double& average) {

	for (int i = 0; i < actualCalc; i++) {
		total += calcBooks[i].cost;			//adds cost to total every time it goes through loop
	}
	average = total / actualCalc;	//divides cost by number of elements to get average

}