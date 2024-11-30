#pragma once
#include <string>
#include "DeviceList.h"
#include "Device.h"

class User {
private:
    unsigned int _age;        
    unsigned int _id;          
    std::string _username;   
    DevicesList* _devices;

public:
   
    void init(unsigned int id, std::string username, unsigned int age);
    void clear();
    unsigned int getID() const;
    std::string getUserName()const;
    unsigned int getAge() const;
    DevicesList& getDevices() const;
    void addDevice(Device newDevice);
    bool checkIfDevicesAreOn() const; 

};
