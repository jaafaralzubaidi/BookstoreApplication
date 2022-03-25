//Name: Jaafar Alzubaidi
//Class: CS300
//Task: BookStore manager,Dynamic Array 
#include <iostream>
#include <string>
#include "Book.h"
#include "BookstoreManager.h"

using namespace std;

int main() { 
    BookstoreManager bookstoreManager;

    //prints true if the bookstore is empty
    
    bookstoreManager.isEmpty();
    cout << boolalpha << bookstoreManager.isEmpty() << endl;
    

    //insert 4 books
    string title, authors, publisher,temp;
    int isbn;
    for(int i = 0; i < 4; i++){
        cout<<"Enter book title: ";
        getline(cin,title);

        cout<<"Enter authors: ";
        getline(cin,authors);
        
        cout<<"Enter isbn: "; 
        cin>>isbn;
        cin.ignore();

        cout<<"Enter publisher: ";
        getline(cin,publisher);

        Book aBook(title, isbn, authors, publisher);
        bookstoreManager.insert(aBook); 
        cout<<endl;
    }

    //print bookstore
    cout<<"Printing Books" <<endl;
    bookstoreManager.print();

    //search for books
    cout<<"Searching..."<<endl;
    cout<<"ISBN:";
    cin>>isbn;
    Book b2(isbn);

    
    bookstoreManager.search(b2);

    //remove a book
    cout<<"Removing..."<<endl;
    cout<<"ISBN:";
    cin>>isbn;
    Book b1(isbn);
    bookstoreManager.remove(b1);

    //print bookstoreB
    cout<<"Printing Books" <<endl;
    bookstoreManager.print();

    //remove books from a particular publisher
    cout<<"Removing all books for a publisher"<<endl;
    cout<<"Publisher:";
    cin.ignore();
    getline(cin,publisher); 
    bookstoreManager.removePublisher(publisher);

    //print bookstore
    cout<<"Printing Books" <<endl;
    bookstoreManager.print();


    //prints the number of books 
    cout << bookstoreManager.listSize();

}
