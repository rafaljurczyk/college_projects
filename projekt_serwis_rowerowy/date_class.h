//structs_enums.h
#ifndef DATE_CLASS_H
#define DATE_CLASS_H

#include <iostream>

/*Class representing date. Name of methods speaks for themself.*/
class Date{
    int day;
    int month;
    int year;
public:
    Date();
    Date(const int& day, const int& month, const int& year);
    /*Method that returns true if our passed Date is closer date to our current time.*/
    bool compare_dates(Date date);
    int get_year() const;
    int get_month() const;
    int get_day() const;
    ~Date();
};

#endif
