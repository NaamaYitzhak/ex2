#include "User.h"
#include "DeviceList.h"

void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->_id = id;
	this->_username = username;
	this->_age = age;
	this->_devices = new DevicesList;
	_devices->init();
}

void User::clear()
{
	this->_age = 0;
	this->_id = 0;
	this->_username = "";
	this->_devices = 0;
}

unsigned int User::getID() const
{
	return this->_id;
}
std::string User::getUserName() const
{
	return this->_username;
}
unsigned int User::getAge() const
{
	return this->_age;
}
DevicesList& User::getDevices() const
{
	return *_devices;
}
void User::addDevice(Device newDevice)
{
	if (this->_devices)
	{
		this->_devices->add(newDevice);
	}
}
bool User::checkIfDevicesAreOn() const
{
	if (_devices == nullptr)
		return true; 

	DeviceNode* current = _devices->get_first();
	while (current != nullptr)
	{
		if (!current->get_data().isActive())
			return false;
		current = current->get_next();
	}
	return true;
}

