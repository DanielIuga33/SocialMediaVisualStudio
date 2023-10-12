#include "Request.h"

Request::Request()
{
	this->id1 = 0;
	this->id2 = 0;
}

Request::Request(int i1, int i2)
{
	this->id1 = i1;
	this->id2 = i2;
}

Request::Request(const Request& rq)
{
	this->id1 = rq.id1;
	this->id2 = rq.id2;
}

Request::Request(std::string line, char delim)
{
	std::vector<std::string> tokens = splitLine(line, delim);
	this->id1 = stoi(tokens[0]);
	this->id2 = stoi(tokens[1]);
}

int Request::get_id1()
{
	return this->id1;
}

int Request::get_id2()
{
	return this->id2;
}

void Request::set_id1(int id1)
{
	this->id1 = id1;
}

void Request::set_id2(int id2)
{
	this->id2 = id2;
}

bool Request::operator==(const Request& rq)
{
	return (this->id1 == rq.id1) && (this->id2 == rq.id2);
}

Request& Request::operator=(const Request& rq)
{
	if (this != &rq)
	{
		this->id1 = rq.id1;
		this->id2 = rq.id2;
	}
	return *this;
}

std::string Request::toString()
{
	return std::to_string(this->id1) + ',' + std::to_string(this->id2);
}

std::ostream& operator<<(std::ostream& os, const Request& rq)
{
	os << "<<< REQUEST-> ID1: " << rq.id1 << ", ID2: " << rq.id2;
	return os;
}

std::istream& operator>>(std::istream& is, Request& rq)
{
	int id1, id2;
	std::cout << "Give the request's id1: ";
	is >> id1;
	rq.set_id1(id1);
	std::cout << "Give the request's id1: ";
	is >> id2;
	rq.set_id2(id2);
	return is;
}
