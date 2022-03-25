#pragma once
#include "Book.h"
#include <iostream>

using namespace std;

class BookstoreManager{

private:
    Book *bookArray;
    int arraySize;
    int numberOfBooks;

public:
    BookstoreManager(int = 4);
    ~BookstoreManager();

    bool isEmpty();
    bool isFull();
    void insert(Book);
    void search(Book);
    int binarySearch(Book[], int, int, int);
    void addBook(Book, int);
    void print();
    void remove(Book);
    void removePublisher(string);
    int listSize();
    void doubleArraySize();
  
    
};