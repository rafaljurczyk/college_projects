//structs_enums.cpp
#include "date_class.h"
#include <ctime>

Date::Date(){
    //this short code below was inspired by stackOverflow member 'milleniumbug' (https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c)
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    this->year = 1900 + now->tm_year;
    this->month = 1 + now->tm_mon;
    this->day = now->tm_mday;
}

Date::Date(const int& day, const int& month, const int& year) : day(day), month(month), year(year) {}

int Date::get_year() const{
    return this->year;
}

int Date::get_month() const{
    return this->month;
}

int Date::get_day() const{
    return this->day;
}

//returns true when 'date' has is taking place earlier
bool Date::compare_dates(Date date){
    if(date.year < this->year) return true;
    else if(date.year > this->year) return false;
    else{
        if(date.month < this->month) return true;
        else if(date.month > this->month) return false;
        else{
            if(date.day < this->day) return true;
            else return false;
        }
    }
}

Date::~Date(){}