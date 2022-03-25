#include "BookstoreManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

BookstoreManager::BookstoreManager(int size){
    arraySize = size;
    numberOfBooks = 0;
    bookArray  = new Book[arraySize];
}

BookstoreManager::~BookstoreManager(){
    delete[] bookArray;
}


bool BookstoreManager::isEmpty(){
    if(numberOfBooks == 0)
        return true;
    
    return false;
}


bool BookstoreManager::isFull(){
    if(numberOfBooks == arraySize)
        return true;
    
    return false;
}

//Inserts a Book object
void BookstoreManager::insert(Book book){
    if(isFull()){
        cout << isFull() << endl;
        doubleArraySize();
    }
        

    int index = -1;
    //finding the index of the smallest element
    for(int i = 0; i < numberOfBooks; i++){
        if(book.getIsbn() < bookArray[i].getIsbn() ){
            index = i;
            break;
        }
    }
    //shifting the books form the back of the array
    if(index >= 0){
        for(int i = numberOfBooks;  i > index; i--)
            bookArray[i] =  bookArray[i-1];
        
        addBook(book, index);
    }
    else{
        index = numberOfBooks;
        addBook(book, index);
    }
}

//Adds a book at a specift index
void BookstoreManager::addBook(Book book, int index){

       
    bookArray[index].setTitle(book.getTitle());
    bookArray[index].setAuthor(book.getAuthor());
    bookArray[index].setPublisher(book.getPublisher());
    bookArray[index].setIsbn(book.getIsbn());
    numberOfBooks++;
}

//Printing the content of the array
void BookstoreManager::print(){
    for (int i = 0; i < numberOfBooks; i++){
        cout << bookArray[i].getTitle() << endl;
        cout << bookArray[i].getAuthor() << endl;
        cout << bookArray[i].getIsbn() << endl;
        cout << bookArray[i].getPublisher() << endl << endl; 
        
    }
    
}

//Search for a Book object
void BookstoreManager::search(Book book){
    int isbn = book.getIsbn();
    int index = binarySearch(bookArray, 0, numberOfBooks, isbn);
    
    if(index < 0)
        cout << "No book was found" << endl;

    else{
        cout << bookArray[index].getTitle() << endl;
        cout << bookArray[index].getAuthor() << endl;
        cout << bookArray[index].getIsbn() << endl;
        cout << bookArray[index].getPublisher() << endl;
    }
}

//BinarySearch to find the position of an element with isbn, returns -1 if not found
int BookstoreManager::binarySearch(Book array[], int first, int last, int value){
    if(first > last)
        return -1;
    
    int mid = (first + last) / 2;

    if(value == array[mid].getIsbn())
        return mid;
    
    if(value > array[mid].getIsbn() )
        return binarySearch(array, (mid + 1), last, value);
    else
        return binarySearch(array, first, (mid - 1), value );

}

//Removes a Book object
void BookstoreManager::remove(Book book){
    int isbnNum = book.getIsbn();
    //Calling binarySearch to find the index 
    int index = binarySearch(bookArray,0, numberOfBooks, isbnNum);

    if(index < 0)
        cout << "No book was found" << endl;

    else{//Shifting the elements
        for(int i = index; i < numberOfBooks -1 ; i++)
            bookArray[i] =  bookArray[i+1];

        numberOfBooks--;
    }
}

//Removes a Book object based on publisher string parameter
void BookstoreManager::removePublisher(string publisher){
    // Temp array to store arrayBook objects
    Book *temp = new Book[arraySize]; 

    int tempIndex = 0;
    bool isFound = false;
    //Adds objects from original arrayBook to temp Array that are not equal to the parameter stirng
    for(int i = 0; i < numberOfBooks; i++){
        if(bookArray[i].getPublisher() != publisher){
            temp[tempIndex] = bookArray[i];
            tempIndex++;
            
        }else
            isFound = true;
        
    }
    //if a publisher was found
    if(isFound){
        numberOfBooks = tempIndex;
        delete[] bookArray;
        bookArray = temp;
    
    }else
        cout << "No book was found" << endl;
}

//Prints number of books
int BookstoreManager::listSize(){
    return numberOfBooks;
}

//Doubling the size of the array 
void BookstoreManager::doubleArraySize(){
    arraySize = arraySize * 2;
    Book *temp = new Book[arraySize];

    for(int i = 0; i < arraySize/2; i++)
        temp[i] = bookArray[i];

    delete[] bookArray;
    bookArray = temp;
}


