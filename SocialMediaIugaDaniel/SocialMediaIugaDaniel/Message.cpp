#include "Message.h"

Message::Message(int id1, int id2, std::string msg)
{
	this->id1 = id1;
	this->id2 = id2;
	this->msg = msg;
}

Message::Message(const Message& fr)
{
	this->id1 = fr.id1;
	this->id2 = fr.id2;
	this->msg = fr.msg;

}

Message::Message(std::string line, char delim)
{
	std::vector<std::string> tokens = splitLine(line, delim);
	this->id1 = stoi(tokens[0]);
	this->id2 = stoi(tokens[1]);
	this->msg = tokens[2];
}

int Message::get_id1()
{
	return this->id1;
}

int Message::get_id2()
{
	return this->id2;
}

std::string Message::get_message()
{
	return this->msg;
}

void Message::set_id1(int id)
{
	this->id1 = id;
}

void Message::set_id2(int id2)
{
	this->id2 = id2;
}

void Message::set_message(std::string msg)
{
	this->msg = msg;
}

bool Message::operator==(const Message& fr)
{
	return (this->id1 == fr.id1 || this->id1 == fr.id2) && (this->id2 == fr.id2 || this->id2 == fr.id1);
}

bool Message::operator!=(const Message& fr)
{
	return (this->id1 != fr.id1) || (this->id2 != fr.id2);
}

Message& Message::operator=(const Message& fr)
{
	if (this != &fr)
	{
		this->id1 = fr.id1;
		this->id2 = fr.id2;
	}
	return *this;
}

std::string Message::toString()
{
	return std::to_string(this->id1) + ',' + std::to_string(this->id2) + "," + this->msg;
}

std::ostream& operator<<(std::ostream& os, const Message& msg)
{
	os << "<<< MESSAGE: ID1: " << msg.id1 << ", ID2: " << msg.id2 << ", Message: " << msg.msg;
	return os;
}
