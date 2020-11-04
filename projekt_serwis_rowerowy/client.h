//client.h
#ifndef CLIENT_H
#define CLIENT_H
#include "person.h"
#include "storage.h"
#include "event.h"
#include "date_class.h"


/*Class representing our customer.  Default customer is Anonymous User and it can only look what's in the store.
After signing in our client can also buy stuff and add unapproved events.*/
class Client : public Person{
    std::string login;
    std::string password;
public:
    Client();
    Client(const std::string& name, const std::string& login, const std::string& password);
    Client(const std::string& name, const std::string& login, const std::string& password, Date& date);
    std::string get_login();
    std::string get_password();
    /*The Client can add event using this method, but the event still have to be confirmed by Employee to be displayed in event lists.*/
    virtual void add_event(Storage& storage) override;
    
};

#endif