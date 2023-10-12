#pragma once
#include <string>
#include <vector>
#include "Utils.h"
class Friendship {
private:
	int id1;
	int id2;
public:
	//constructor
	Friendship() = default;
	Friendship(int id1,int fr);
	Friendship(const Friendship& fr);
	Friendship(std::string line, char delim);
	//getteri + setteri
	int get_id1();
	int get_id2();
	void set_id1(int id);
	void set_id2(int id2);
	//operators
	bool operator ==(const Friendship& fr);
	Friendship& operator =(const Friendship & fr);
	//friend operators
	/*friend std::ostream& operator <<(std::ostream& os, const Friendship& fr);
	friend std::istream& operator >>(std::istream& is, Friendship& fr);*/
	std::string toString();
	//destructor
	~Friendship() = default;
};