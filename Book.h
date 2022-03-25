#pragma once 
#include <iostream>

using namespace std;

class Book{

private:
    string m_title, m_author, m_publisher;
    int m_isbn;

public:
    Book(string = "No Title", int = 0, string = "No Author", string = "No Publisher");
    Book(int) ;
    
    void setTitle(string);
    string getTitle();

    void setAuthor(string);
    string getAuthor();

    void setPublisher(string);
    string getPublisher();

    void setIsbn(int);
    int getIsbn();

};