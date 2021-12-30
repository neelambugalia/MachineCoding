#include "models.cpp"

class Service{
    private:
    User user;
    BookStore bookstore;
    public:

    Service(){}

    Service(User user, BookStore bookstore){
        this->user = user;
        this->bookstore = bookstore;
    }

    vector<string> getPages(string content){
        string str;
        vector<string> ans;

        for(auto i : content){
            if(i == ' '){
                ans.push_back(str);
                str = "";
            }
            else
                str+= i;
        }
        if(str.size() > 0)
            ans.push_back(str);
        return ans;
    }

    void bookService(){
        string curBookName;
        int curPage;
        while(1){
            cout << "What facility you want : ";
            string command;
            cin >> command;
            if(command == "AddBook"){
                if(!user.adminUser()){
                    cout << "Only admin can add books.\n";
                    continue;
                }
                string title;
                string author = user.getName();
                string content;
                cout << "Please enter title of the book : ";
                getchar();
                getline(cin, title);
                cout << "Please enter content of the book : ";
                getline(cin, content);
                vector<string> pages = getPages(content);

                Book book = Book(title, author, content, pages);
                bookstore.addBook(book);
                cout << "Book added successfully.\n";
            }

            else if(command == "Register"){
                if(user.isRegistered()){
                    cout << "You are already registered\n";
                }
                else{
                    user.registerUser();
                    cout << "You have successfully registered.\n";
                }
            }

            else if(command == "Login"){
                if(user.loggedIn()){
                    cout << "You are alraedy logged in.\n";
                }
                else{
                    if(user.login())
                        cout << "You have successfully logged in.\n";
                    else
                        cout << "You are not registered. Please register first.\n";
                }
            }

            else if(command == "Logout"){
                if(user.loggedOut()){
                    cout << "You are alraedy logged out.\n";
                }
                else{
                    user.logout();
                    cout << "You have successfully logged out.\n";
                }
            }

            else if(command == "StartRead"){
                cout << "Pleast Enter the book name : ";
                string bookName;
                getchar();
                getline(cin, bookName);
                Book &book = bookstore.findByTitle(bookName);
                curBookName = bookName;
                curPage = 0;
                if(book.getTitle().size() > 0){
                    cout << book.getPages()[0] << "\n";
                }
                else
                    cout << "No such book present.\n";

            }

            else if(command == "ResumeRead"){
                Book &book = bookstore.findByTitle(curBookName);
                string res = book.goTo(curPage);
                cout << res << "\n";
            }

            else if(command == "GoTo"){
                cout << "Enter the page you want to go to : ";
                int page;
                cin >> page;
                Book &book = bookstore.findByTitle(curBookName);
                string res = book.goTo(page);
                cout << res << "\n";
                curPage = page;
            }

            else if(command == "previous"){
                Book &book = bookstore.findByTitle(curBookName);
                if(curPage == 0){
                    cout << "You are at first page of book.\n";
                    continue;
                }
                curPage--;
                string res = book.getPage(curPage);
                cout << res<< "\n";
            }

            else if(command == "next"){
                Book &book = bookstore.findByTitle(curBookName);
                if(curPage == book.getPages().size()-1){
                    cout << "You are at last page of book.\n";
                    continue;
                }
                curPage++;
                string res = book.getPage(curPage);
                cout << res<< "\n";
            }

            else if(command == "BeAdmin"){
                if(user.adminUser()){
                    cout << "You are alraedy an Admin.\n";
                }
                else{
                    if(user.makeAdmin())
                        cout << "You are now an Admin.\n";
                    else
                        cout << "You are not logged in. Please login first.\n";
                }
            }

            else if(command == "exit")
                break;
            else
                cout << "Invalid Command.\n";
        }
    }
};