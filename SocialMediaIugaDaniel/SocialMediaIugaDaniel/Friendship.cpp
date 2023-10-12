#include "Friendship.h"

Friendship::Friendship(int id1, int id2)
{
	this->id1 = id1;
	this->id2 = id2;
}

Friendship::Friendship(const Friendship& fr)
{
	this->id1 = fr.id1;
	this->id2 = fr.id2;
}

Friendship::Friendship(std::string line, char delim)
{
	std::vector<std::string> tokens = splitLine(line, delim);
	this->id1 =stoi(tokens[0]);
	this->id2 = stoi(tokens[1]);
}

int Friendship::get_id1()
{
	return this->id1;
}

int Friendship::get_id2()
{
	return this->id2;
}

void Friendship::set_id1(int id1)
{
	this->id1 = id1;
}

void Friendship::set_id2(int id2)
{
	this->id2 = id2;
}

bool Friendship::operator==(const Friendship& fr)
{
	return (this->id1 == fr.id1 && this->id2 == fr.id2);
}

Friendship& Friendship::operator=(const Friendship& fr)
{
	if (this != &fr)
	{
		this->id1 = fr.id1;
		this->id2 = fr.id2;
	}
	return (*this);
}

std::string Friendship::toString()
{
	return std::to_string(this->id1) + ',' + std::to_string(this->id2);
}

//std::ostream& operator<<(std::ostream& os, const Friendship& fr)
//{
//}
//
//std::istream& operator>>(std::istream& is, Friendship& fr)
//{
//	// TODO: insert return statement here
//}
