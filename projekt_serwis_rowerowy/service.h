//service.h
#ifndef SERVICE_H
#define SERVICE_H
#include "date_class.h"
#include "basic_product.h"
#include <iostream>
#include <string>

//this is service that our bike company provide
//it's supposed to be almost like simple product but services needs to be done in some range of time so that's why this class is created with extra variable (and also services don't have quantity!)
class Service : public Basic_Product{
    int required_days;
public:
    Service(const std::string& name, const double price, const std::string& description, const int required_days);
    virtual void show_full_name() override;
    bool compare(Service* service);
    int get_required_days() const;
    ~Service();
};

#endif
