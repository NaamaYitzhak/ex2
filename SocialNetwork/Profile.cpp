#include "Profile.h"
#include "UserList.h"

// init
void Profile::init(User owner) 
{
	this->_owner = owner;

	this->_page = new Page();
	this->_page->init();
	
	this->_friends = new UserList();
	this->_friends->init();
}

// public functions

void Profile::clear()
{
	_owner.clear();
	_friends->clear();
	delete _page;
	delete _friends;
}

void Profile::addPostToProfilePage(std::string post) 
{
	_page->addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
	_friends->add(friend_to_add);
}

std::string Profile::getFriendsWithSameNameLength()
{
	std::string res;
	size_t userLen = this->_owner.getUserName().length();
	UserNode* currentFriend = this->_friends->get_first();

	while (currentFriend != nullptr)
	{
		const User& friendUser = currentFriend->get_data();
		if (friendUser.getUserName().length() == userLen)
		{
			res += friendUser.getUserName() + ",";
		}
		currentFriend = currentFriend->get_next();
	}
	if (!res.empty())
	{
		res.pop_back();
	}

	return res;
}


 // getters
User Profile::getOwner() const
{
	return this->_owner;
}

std::string Profile::getPage() const
{
	std::string page_info = "Status: " + _page->getStatus() + "\n";
	page_info += "*******************\n";
	page_info += "*******************\n";
	page_info += _page->getPosts(); 

	return page_info;
}


std::string Profile::getFriends() const
{
	if (_friends == nullptr)
	{
		return ""; // if no friends
	}
	UserNode* curr = _friends->get_first();
	std::string res;
	
	while (curr != nullptr)
	{
		User user = curr->get_data();
		res += user.getUserName();
		curr = curr->get_next();
		if (curr != nullptr)
		{
			res += ",";
		}
	}
	return res;
}

// setters
void Profile::setStatus(std::string new_status) 
{
	_page->Page::setStatus(new_status);
}