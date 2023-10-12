#pragma once
#include <iostream>
#include <string>
#include "Utils.h"
class User {
private:
	int id;
	std::string name;
	std::string surname;
	std::string email;
	std::string password;
	int age;
public:
	//constructors
	User();
	User(int id, std::string name, std::string surname, std::string email, std::string password, int age);
	User(const User& u);
	User(std::string line, char delim);
	//getteri
	int get_id();
	int get_age();
	std::string get_name();
	std::string get_surname();
	std::string get_email();
	std::string get_password();
	//setteri
	void set_id(int id);
	void set_age(int a);
	void set_name(std::string n);
	void set_surname(std::string s);
	void set_email(std::string e);
	void set_password(std::string p);
	//operators
	bool operator ==(const User& u);
	bool operator !=(const User& u);
	User& operator =(const User& u);
	//friend operators
	friend std::ostream& operator <<(std::ostream& os, const User& u);
	friend std::istream& operator >>(std::istream& is, User& u);
	std::string toString();
	//destructor
	~User() = default;
};