#pragma once
#include <string>
#include <vector>
#include "Utils.h"
#include <iostream>
class Message {
private:
	int id1;
	int id2;
	std::string msg;
public:
	//constructor
	Message() = default;
	Message(int id1, int id2, std::string msg);
	Message(const  Message& fr);
	Message(std::string line, char delim);
	//getteri + setteri
	int get_id1();
	int get_id2();
	std::string get_message();
	void set_id1(int id);
	void set_id2(int id2);
	void set_message(std::string msg);
	//operators
	bool operator ==(const  Message& fr);
	bool operator !=(const  Message& fr);
	Message& operator =(const  Message& fr);
	//friend operators
	friend std::ostream& operator <<(std::ostream& os, const Message& msg);
	//friend std::istream& operator >>(std::istream& is, Friendship& fr);
	std::string toString();
	//destructor
	~Message() = default;
};
