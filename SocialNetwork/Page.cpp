#include "Page.h"
#include "UserList.h"

void Page::init()
{
	this->_status = "";
	this->_posts = "";
}

std::string Page::getPosts() const
{
	return this->_posts; 
}

std::string Page::getStatus() const 
{
	return this->_status;
}
void Page::clearPage()
{
	this->_posts = "";
}
void Page::setStatus(std::string status)
{
	this->_status = status;

}
void Page::addLineToPosts(std::string new_line)
{
	this->_posts += new_line + "\n";
}
