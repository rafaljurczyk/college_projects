//storage.cpp
#include "storage.h"


void Storage::show_services() const{
    for(auto service : services) service->show_full_name();
}

double Storage::get_balance() const{
    return this->earnings;
}

void Storage::set_balance(double ammount){
    this->earnings = ammount;
}

void Storage::show_storage() const{
    for(auto p : this->products) p->show_full_name();/*std::cout<<p->get_name()<<"["<<p->get_quantity()<<"] Cost: "<< p->get_price()<<"\n";*/
    for(auto b : this->bikes) b->show_full_name();/*std::cout<<b->get_name()<<"["<<b->get_quantity()<<"] "<<b->get_wheel_size()<<"\' Cost:"<< b->get_price() <<"\n";*/
}

Storage::~Storage(){
    if (products.empty() != true){
        for (int i = 0; i < products.size(); i++) 
            delete products[i];
        products.clear();
    }

    if (bikes.empty() != true){
        for (int i = 0; i < bikes.size(); i++) 
            delete bikes[i];
        bikes.clear();
    }

    if (services.empty() != true){
        for (int i = 0; i < services.size(); i++) 
            delete services[i];
        services.clear();
    }

    if (events.empty() != true){
        for (int i = 0; i < events.size(); i++)
            delete events[i];
        events.clear();
    }
}

void Storage::check_in_storage(std::string& item){
    for(auto p : this->products){
        if(p->get_name() == item && p->get_quantity() > 0){
            p->subtract_quantity(1);
            std::cout<<"Thanks for buying!\n";
            this->set_balance(this->get_balance() + p->get_price());
            return;
        }
    }
    for(int i = 0; i< this->bikes.size(); i++){
        if(this->bikes[i]->get_name() == item){
            std::cout<<"Which wheel size are you looking for?\n";
            int wheel_size;
            std::cin>>wheel_size;
            while(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cout<<"Wrong value. Try again: \n";
                std::cin>>item;
            }
            for(int j = i; j < this->bikes.size(); j++){
                if(this->bikes[j]->get_name() == item && this->bikes[j]->get_wheel_size() == wheel_size && this->bikes[j]->get_quantity() > 0){
                    this->bikes[j]->subtract_quantity(1);
                    std::cout<<"Thanks for buying!\n";
                    this->set_balance(this->get_balance() + this->bikes[j]->get_price());
                    return;
                }
                else{
                    std::cout<<"Not in our storage. Sorry!\n";
                    return;
                }
            }
        }
    }
    std::cout<<"Not in our storage. Sorry!\n";
}

bool Storage::order_a_service(std::string& service){
    for(auto s : this->services){
        if(s->get_name() == service){
            std::cout<<"Thanks for ordering!\n";
            this->set_balance(this->get_balance() + s->get_price());
            return true;
        }
    }
    std::cout<<"Not in our service list. Sorry!\n";
    return false;
}

void Storage::load_storage(){
    std::string file_name = "items.txt";
    std::string name, description;
    double price, wheel_size;
    int days_required_to_complete, quantity;
    int is_approved;
    std::string day, month, year;
    Type type;
    Date* date;
    std::string price_string, wheel_size_string, days_required_to_complete_string, type_string, quantity_string, is_approved_string;
    std::string item_type;
    std::string earnings_string;

    std::fstream file;
    file.open(file_name, std::ios::in);
    if(file.good()){
        std::getline(file, earnings_string);
        earnings = std::stod(earnings_string);
        while(!file.eof()){
            if(std::getline(file, item_type)){
                if(item_type == "PRODUCT"){
                    std::getline(file, name, ';');
                    std::getline(file, price_string, ';');
                    std::getline(file, description, ';');
                    std::getline(file, quantity_string);
                    price = std::stod(price_string);
                    quantity = atoi(quantity_string.c_str());
                    this->products.push_back(new Product(name, price, description, quantity));
                }
                else if(item_type == "BIKE"){
                    std::getline(file, name, ';');
                    std::getline(file, price_string, ';');
                    std::getline(file, description, ';');
                    std::getline(file, type_string, ';');
                    std::getline(file, wheel_size_string, ';');
                    std::getline(file, quantity_string);
                    wheel_size = std::stod(wheel_size_string);
                    price = std::stod(price_string);
                    type = StringToType(type_string);
                    quantity = atoi(quantity_string.c_str());
                    this->bikes.push_back(new Bike(name, price, description, type, wheel_size, quantity));
                }
                else if(item_type == "SERVICE"){
                    std::getline(file, name, ';');
                    std::getline(file, price_string, ';');
                    std::getline(file, description, ';');
                    std::getline(file, days_required_to_complete_string);
                    days_required_to_complete = atoi(days_required_to_complete_string.c_str());
                    price = std::stod(price_string);
                    this->services.push_back(new Service(name, price, description, days_required_to_complete));
                }
                else if(item_type == "EVENT"){
                    std::getline(file, name, ';');
                    std::getline(file, description, ';');
                    std::getline(file, day, ';');
                    std::getline(file, month, ';');
                    std::getline(file, year, ';');
                    std::getline(file, is_approved_string);
                    is_approved = atoi(is_approved_string.c_str());
                    date = new Date(atoi(day.c_str()), atoi(month.c_str()), atoi(year.c_str()));
                    this->add_event(new Event(name, description, date, is_approved));
                    delete date;
                }
            }
        }
        file.close();
    }
    else std::cout<<"Wrong file name.\n";
}

void Storage::save_storage(){
    std::string file_name = "items.txt";
    std::fstream file;
    file.open(file_name, std::ios::out | std::ios::trunc | std::ios::ate);
    if(file.good() == true){
        file<<earnings<<'\n';
        for(auto p : products){
            file<<"PRODUCT\n"<<p->get_name()<<';'<<std::to_string(p->get_price())<<';'<<p->get_description()<<';'<<std::to_string(p->get_quantity())<<'\n';
        }
        for(auto b : bikes){
            file<<"BIKE\n"<<b->get_name()<<';'<<std::to_string(b->get_price())<<';'<<b->get_description()<<';'<<TypeToString(b->get_bike_type())<<';'<<std::to_string(b->get_wheel_size())<<';'<<std::to_string(b->get_quantity())<<'\n';
        }
        for(auto s : services){
            file<<"SERVICE\n"<<s->get_name()<<';'<<std::to_string(s->get_price())<<';'<<s->get_description()<<';'<<std::to_string(s->get_required_days())<<'\n';
        }
        for(auto e : events){
            int is_approved;
            if(e->get_is_approved()) is_approved = 1;
            else is_approved = 0;
            file<<"EVENT\n"<<e->get_name()<<';'<<e->get_description()<<';'<<e->get_date()->get_day()<<';'<<e->get_date()->get_month()<<';'<<e->get_date()->get_year()<<';'<<is_approved<<'\n';
        }
        file.close();
    }
}

void Storage::add_event(Event* event){
    for(auto e : this->events){
        if(event->get_name() == e->get_name()){
            std::cout<<"This event is already in our database.\n";
            return;
        }
    }
    
    for(int i = -1; i<(this->events.size()-1); i++){
        if(this->events[i+1]->get_date()->compare_dates(*(event->get_date()))) 
        {
            this->events.insert(this->events.begin()+i, event); //if our 'event' has "lower" date it's gonna be inserted in right place
            return;
        }
    }
    this->events.push_back(event);
}

void Storage::show_events(){
    for(auto e : this->events) 
        if(e->get_is_approved()) std::cout<<"!"<<e->get_name()<<"! ["<<e->get_date()->get_day()<<"."<<e->get_date()->get_month()<<"."<<e->get_date()->get_year()<<"r] - "<<e->get_description()<<"\n";
}

void Storage::show_unapproved_events(){
    for(auto e : this->events) 
        if(!e->get_is_approved()) std::cout<<"!"<<e->get_name()<<"! ["<<e->get_date()->get_day()<<"."<<e->get_date()->get_month()<<"."<<e->get_date()->get_year()<<"r] - "<<e->get_description()<<"\n";
}

void Storage::approve_event(std::string name){
    for(auto e : this->events){
        if(e->get_name() == name){
            e->set_is_approved();
            return;
        } 
    }
    std::cout<<"There isn't any event with that name in our database\n";
}

/*
void Storage::delete_event(std::string name){
    for(int i = 0; i<this->events.size(); i++){
        if(name == this->events[i]->get_name()) this->events.erase(this->events.begin()+i);
    }
}

void Storage::update_events(){
    Date temp_date;
    for(int i = 0; i<this->events.size(); i++){
        if(temp_date.compare_dates(this->events[i]->get_date())) this->events.erase(this->events.begin()+i);
    }
}

void Storage::add_product(Product* product){
    for(auto p : products){
        if(p->get_name() == product->get_name()){
            std::cout<<"Product/Bike like this already exists!\n";
            delete product;
            return;
        }
    }
    for(auto b : bikes){
        if(b->get_name() == product->get_name()){
            std::cout<<"Product/Bike like this already exists!\n";
            delete product;
            return;
        }
    }
    this->products.push_back(product);
}

void Storage::add_bike(Bike* bike){
    for(auto p : products){
        if(p->get_name() == bike->get_name()){
            std::cout<<"Product/Bike like this already exists!\n";
            delete bike;
            return;
        }
    }
    for(auto b : bikes){
        if(b->get_name() == bike->get_name() && b->get_wheel_size() == bike->get_wheel_size()){
            std::cout<<"Product/Bike like this already exists!\n";
            delete bike;
            return;
        }
    }
    this->bikes.push_back(bike);
}

void Storage::product_supply(std::string name, int ammount){
    for(auto p : this->products){
        if(p->get_name() == name){
            p->add_quantity(ammount);
                return;
        }
    }
    std::cout<<"Such product isn't in database.\n";
}

void Storage::bike_supply(const std::string& name,const double& wheel_size, const int& ammount){
    for(auto b : this->bikes){
        if(b->get_name() == name && b->get_wheel_size() == wheel_size){
            b->add_quantity(ammount);
            return;
        }
    }
    for(auto b : this->bikes){
        if(b->get_name() == name){
            Bike* temp_bike = new Bike(b->get_name(), b->get_price(), b->get_description(), b->get_bike_type(), wheel_size);
            temp_bike->add_quantity(ammount);
            this->add_bike(temp_bike);
            return;
        }
    }
    std::cout<<"Such bike isn't in database.\n";
}

void Storage::add_service(Service* service){
    for(auto s : services){
        if(s->compare(service)){
            std::cout<<"Service like this already exists!\n";
            return;
        }
    }
    this->services.push_back(service);
}
*/