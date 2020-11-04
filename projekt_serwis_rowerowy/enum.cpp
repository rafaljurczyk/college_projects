//enum.cpp
#include "enum.h"

std::string TypeToString(const Type type){
    switch(type){
        case mountain: return "mountain bike";
        case city: return "city bike";
        case universal: return "universal bike";
        default: return "";
    }
}

std::string EmployeePositionToString(const EmployeePosition employee_position){
    switch (employee_position){
        case warehouseman: return "warehouseman";
        case adviser: return "adviser";
        case service_technician: return "service_technician";
        case manager: return "manager";
        default: return "";
    }
}

EmployeePosition StringToEmployeePosition(const std::string& employee_position){
    if(employee_position == "warehouseman") return warehouseman;
    else if(employee_position == "adviser") return adviser;
    else if(employee_position == "service_technician") return service_technician;
    else if(employee_position == "manager") return manager;
    else return warehouseman;
}

Type StringToType(const std::string& type){
    if(type == "mountain") return mountain;
    else if(type == "city") return city;
    else if(type == "universal") return universal;
    else return universal;
}