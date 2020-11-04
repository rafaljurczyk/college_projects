//event.cpp

#include "event.h"

Event::Event(std::string name, std::string description, Date* date, bool is_approved = false) : name(name), description(description), is_approved(is_approved) {
    this->date = new Date(date->get_day(), date->get_month(), date->get_year());
}

Date* Event::get_date(){
    return this->date;
}

bool Event::get_is_approved(){
    return this->is_approved;
}

void Event::set_is_approved(){
    this->is_approved = true;
}

std::string Event::get_name() const{
    return this->name;
}

std::string Event::get_description() const{
    return this->description;
}

Event::~Event()
{
    delete this->date;
}