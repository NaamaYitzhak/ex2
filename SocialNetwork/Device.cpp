#include "Device.h"

void Device::init(unsigned int id, DeviceType type, std::string os)
{
	this->_id = id;
	this->_type = type;
	this->_os = os;
	this->_active = true;
}
bool Device::isActive() const
{
	return _active;
}
void Device::activate()
{
	 this->_active = true;
}
void  Device::deactivate()
{
	this->_active = false;
}
unsigned int Device::getID() const
{
	return this->_id;
}
DeviceType Device::getType() const
{
	return this->_type;
}
std::string Device::getOS() const
{
	 return this->_os;
}
