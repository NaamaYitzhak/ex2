#include "Page.h"
#include "UserList.h"

#include <string>

class Profile {
private:
		User _owner;
		Page* _page;
		UserList* _friends;
public:
		// init
		void init(User owner);
		
		void clear();
		void addPostToProfilePage(std::string post);
		void addFriend(User friend_to_add);
		std::string getFriendsWithSameNameLength();

		// getters
		User getOwner() const;
		std::string getPage() const;
		std::string getFriends() const;

		// setters
		void setStatus(std::string new_status);
};