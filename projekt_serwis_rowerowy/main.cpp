//main.cpp
#include "interface.h"
#include "client.h"

int main(){
    std::system("clear");
    Interface* interface = new Interface();
    interface->load_interface();
    interface->show_client_interface(new Client());
    delete interface;
    return 0;
}

/*
g++ -o projekt basic_product.h product.h bike.h service.h person.h client.h employee.h manager.h enum.h date_class.h event.h storage.h people_database.h interface.h storage.cpp service_class.cpp product_class.cpp person.cpp people_database.cpp manager.cpp main.cpp interface.cpp event.cpp enum.cpp employee.cpp date_class.cpp client.cpp bike_class.cpp basic_product_class.cpp 
*/