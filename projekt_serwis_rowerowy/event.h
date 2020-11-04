//event.h
#ifndef EVENT_H
#define EVENT_H
#include <ctime>
#include <iostream>
#include "date_class.h"

/*This class represent single event. */
class Event{
    std::string name;
    std::string description;
    /*When is_approved is true, the event is displayed to every user. Only Employee/Manager can approve events added by Clients.*/
    bool is_approved;
    Date* date;
public:
    Event(std::string name, std::string description, Date* date, bool is_approved);
    Date* get_date();
    bool get_is_approved();
    /*This method changes is_approved to true.*/
    void set_is_approved();
    std::string get_name() const;
    std::string get_description() const;

    ~Event();
};

#endif