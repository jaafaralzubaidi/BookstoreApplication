#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(string title, int isbn, string author, string publisher){
    m_title = title;
    m_isbn = isbn;
    m_author = author;
    m_publisher = publisher;
}
Book::Book(int isbn) : Book(){
    m_isbn = isbn;
}



void Book:: setTitle(string title){
    m_title = title;
}
void Book::setAuthor(string author){
    m_author = author;
}
void Book::setPublisher(string publisher){
    m_publisher = publisher;
}
void Book::setIsbn(int isbn){
    m_isbn = isbn;
}

string Book::getTitle(){
    return m_title;
}
string Book::getAuthor(){
    return m_author;
}
string Book::getPublisher(){
    return m_publisher;
}
int Book::getIsbn(){
    return m_isbn;
}