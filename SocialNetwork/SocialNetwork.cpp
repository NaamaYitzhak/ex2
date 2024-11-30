#include "SocialNetwork.h"
#include "ProfileList.h"


// init
void SocialNetwork::init(std::string networkName, int minAge)
{
	this->_networkName = networkName;
	this->_minAge = minAge;
	
	this->_profiles = new ProfileList();
	this->_profiles->init();
}

void SocialNetwork::clear()
{
	_minAge = 0;
	_networkName.clear();
	_profiles->clear();
	delete _profiles;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < _minAge)
	{
		return false;
	}
	else
	{
		_profiles->add(profile_to_add);
		
	}
	return _profiles;
}


// getters
int SocialNetwork::getMinAge() const
{
	return this->_minAge;
}

std::string SocialNetwork::getWindowsDevices()
{
	std::string res = "";
	ProfileNode* curr = _profiles->get_first();
	while (curr != nullptr)
	{
		DeviceNode* current = curr->get_data().getOwner().getDevices().get_first();
		while (current != nullptr)
		{
			Device dev = current->get_data();
			if (dev.getOS() == WINDOWS7 || dev.getOS() == WINDOWS10 || dev.getOS() == WINDOWS11)
			{
				if (res != "")
				{
					res += ", ";
				}
				res += "[" + std::to_string(dev.getID()) + ", " + dev.getOS() + "]";
			}
			current = current->get_next();
		}
		curr = curr->get_next();
	}
	
	return res;
	
}

std::string SocialNetwork::getNetworkName() const
{
	return this->_networkName;
}