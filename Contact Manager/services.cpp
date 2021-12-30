#include"models.cpp"

class Service{
    private:
    vector<Contact> contacts;

    public:
    Service(ContactList contactList){
        this->contacts = contactList.getContactList();
    }


    Contact searchByFirstName(string firstName){
        for(auto contact : contacts){
            if(contact.getFirstName() == firstName)
                return contact;
        }
    }

    Contact searchByLastName(string lastName){
        for(auto contact : contacts){
            if(contact.getLastName() == lastName)
                return contact;
        }

    }

    Contact searchContactNumber(long contactNumber){
        for(auto contact : contacts){
            if(contact.getContactNumber() == contactNumber)
                return contact;
        }

    }

    void updateContact(Contact contact){
        
    }


};
