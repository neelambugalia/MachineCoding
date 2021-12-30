#include<bits/stdc++.h>
using namespace std;

class Book{
    private:
    string title;
    string author;
    string content;
    float rating;
    vector<string> pages;

    public:

    Book(){
        this->title = "";
    }

    Book(string title, string author, string content, vector<string>pages){
        this->title = title;
        this-> author = author;
        this->content = content;
        this->pages = pages;
        this->rating = 0;
    }

    string getTitle(){
        return title;
    }

    string getPage(int page){
        return pages[page];
    }

    string goTo(int page){
        if(page < 0 || page >= pages.size()){
            return "Entered page out of bound";
        }
        return pages[page];
    }

    void rate(int rating){
        rating = rating;
    }

    vector<string> getPages(){
        return pages;
    }
};

class User{
    private:
    string name;
    bool admin;
    bool registered;
    bool logged_in;
    vector<Book> books;

    public:

    User(){}

    User(string name){
        this->name = name;
        this->admin = 0;
        this->registered = 0;
        this->logged_in = 0;
    }

    string getName(){
        return name;
    }

    void registerUser(){
        registered = 1;
    }

    bool login(){
        return logged_in = registered;
    }

    void logout(){
        logged_in = 0;
    }

    bool makeAdmin(){
        return admin =logged_in;
    }

    bool adminUser(){
        return admin;
    }

    bool isRegistered(){
        return registered;
    }

    bool loggedIn(){
        return logged_in;
    }

    bool loggedOut(){
        return !logged_in;
    }

    void rateBook(int bookID, float rating){
        Book book = books[bookID];
        book.rate(rating);
    }
    
};


class BookStore{
    private:
    vector<Book> books;
    public:

    BookStore(){}
    
    BookStore(vector<Book> books){
        this->books = books;
    }

    void addBook(Book book)
    {
        books.push_back(book);
    }

    vector<Book> &getBooks(){
        return books;
    }

     Book& findByTitle(string title){
        for(auto &book : books){
            if(book.getTitle() == title)
                return book;
        }
        Book book = Book();
        Book &book1 = book;
        return book1;
    }
};