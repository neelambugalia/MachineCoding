#include "services.cpp"

int main(){

    string userName;
    cout << "Please enter your name : ";
    cin >> userName;
    User user = User(userName);
    vector<Book> books;
    BookStore bookstore = BookStore(books);

    Service service = Service(user, bookstore);
    service.bookService();
    return 0;
}