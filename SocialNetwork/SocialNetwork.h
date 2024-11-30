#include "ProfileList.h"

#include <string>

class SocialNetwork 
{
private:
	std::string _networkName;
	int _minAge;
	ProfileList* _profiles;
public:
	// init
	void init(std::string networkName, int minAge);

	void clear();
	bool addProfile(Profile profile_to_add);
	std::string getWindowsDevices();

	// getters
	int getMinAge() const;
	std::string getNetworkName() const; 
	
};