#include<bits/stdc++.h>
using namespace std;

class Contact{

    private:

    string firstName;
    string lastName;
    long contactNumber;


    public:

    Contact(string firstName, string lastName, long contactNumber){
        this->firstName = firstName;
        this->lastName = lastName;
        this->contactNumber = contactNumber;
    }

    void setfirstName(string firstName){
        this->firstName = firstName;
    }

    void setlastName(string lastName){
        this->lastName = lastName;
    }

    void setContactNumber(long contactNumber){
        this->contactNumber = contactNumber;
    }

    string getFirstName(){
        return firstName;
    }

    string getLastName(){
        return lastName;
    }

    long getContactNumber(){
        return contactNumber;
    }


};

class ContactList{
    private:

    vector<Contact> listOfContacts;

    public:

    ContactList(){

    }

    vector<Contact> getContactList(){
        return this->listOfContacts;
    }

    void addContact(Contact contact){
        listOfContacts.push_back(contact);
    }


};