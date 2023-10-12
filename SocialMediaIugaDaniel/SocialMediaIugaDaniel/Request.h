#pragma once
#include <string>
#include <vector>
#include "Utils.h"
#include <iostream>


class Request {
private:	
	int id1;
	int id2;
public:
	//Constructori
	Request();
	Request(int i1, int i2);
	Request(const Request& rq);
	Request(std::string line, char delim);
	//Getteri + Setteri
	int get_id1();
	int get_id2();
	void set_id1(int id1);
	void set_id2(int id2);
	//Operators
	bool operator ==(const Request& rq);
	Request& operator =(const Request& rq);
	//friend operators
	friend std::ostream& operator <<(std::ostream& os, const Request& rq);
	friend std::istream& operator >>(std::istream& is, Request& rq);
	std::string toString();
	//destructor
	~Request() = default;
};