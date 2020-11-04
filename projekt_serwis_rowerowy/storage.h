//storage.h
#ifndef STORAGE_H
#define STORAGE_H
#include "product.h"
#include "basic_product.h"
#include "service.h"
#include "bike.h"
//#include "events.h"
#include "event.h"
#include "date_class.h"
#include "enum.h"
#include <iostream>
#include <vector>
#include <fstream>

//this class is supposed to store our every product/bike/service and our shop earnings
//we can check if the product we're looking for is avaible
//we can check our balance and add/subtract money
//this is core of our shop
class Storage{
    std::vector<Product*> products;
    std::vector<Bike*> bikes;
    std::vector<Service*> services;
    std::vector<Event*> events;
    //EventList event_list;
    double earnings;
public:
    //void add_event(Event* event);
    //void show_events();
    //void show_unapproved_events();
    //void approve_event(std::string name);
    void show_storage() const;
    void show_services() const;
    //
    void add_event(Event* event);
    void show_events();
    void show_unapproved_events();
    void approve_event(std::string name);
    //void delete_event(std::string name);
    //void update_events();
    //
    /*we can check how much money our store earned*/
    double get_balance() const;
    /*every time somebody buys something our we have to pay salary to our employee we can do it with this method*/
    void set_balance(double ammount);
    /*if we want to buy product/bike this method checks if it's in our store and if it is it buys it (subtract quantity and add it's price to our balance)*/
    void check_in_storage(std::string& item);
    /*if we want to order service this method checks if it's in our store and if it is it orders it (adding to our ordered servces list and add it's price to out balance)*/
    bool order_a_service(std::string& service);
    /*load whole products/bikes/services database*/
    void load_storage();
    /*save whole products/bikes/services database*/
    void save_storage();
    
    ~Storage();
    
    //void product_supply(std::string name, int ammount);
    //void bike_supply(const std::string& name,const double& wheel_size, const int& ammount);
    //void add_product(Product* product);
    //void add_bike(Bike* bike);
    //void add_service(Service* service);
};

#endif