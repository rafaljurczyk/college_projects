//service_class.cpp
#include "service.h"

Service::Service(const std::string& name, const double price, const std::string& description, const int required_days) : Basic_Product(name, price, description){
    this->required_days = required_days;
}

void Service::show_full_name(){
    std::cout<<"\n> "<<this->name<<"["<<this->price<<"zl] - "<<"days to complete: "<<this->required_days<<"\n"<<this->description<<std::endl;
}

bool Service::compare(Service* service){
    if(Basic_Product::get_name() == service->get_name())
        return true;
    else
        return false;
}

int Service::get_required_days() const{
    return this->required_days;
}

Service::~Service(){}
