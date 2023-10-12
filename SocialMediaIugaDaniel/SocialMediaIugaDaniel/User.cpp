#include "User.h"

User::User()
{
	this->id = 0;
	this->age = 0;
	this->email = "";
	this->password = "";
	this->name = "";
	this->surname = "";
}

User::User(int id, std::string name, std::string surname, std::string email, std::string password, int age)
{
	this->id = id;
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->password = password;
	this->age = age;
}

User::User(const User& u)
{
	this->id = u.id;
	this->name = u.name;
	this->surname = u.surname;
	this->email = u.email;
	this->password = u.password;
	this->age = u.age;
}

User::User(std::string line, char delim)
{
	std::vector<std::string> tokens = splitLine(line, delim);
	this->id = stoi(tokens[0]);
	this->name = tokens[1];
	this->surname = tokens[2];
	this->email = tokens[3];
	this->password = tokens[4];
	this->age = stoi(tokens[5]);
}

int User::get_id()
{
	return this->id;
}

int User::get_age()
{
	return this->age;
}

std::string User::get_name()
{
	return this->name;
}

std::string User::get_surname()
{
	return this->surname;
}

std::string User::get_email()
{
	return this->email;
}

std::string User::get_password()
{
	return this->password;
}

void User::set_id(int id)
{
	this->id = id;
}

void User::set_age(int a)
{
	this->age = a;
}

void User::set_name(std::string n)
{
	this->name = n;
}

void User::set_surname(std::string s)
{
	this->surname = s;
}

void User::set_email(std::string e)
{
	this->email = e;
}

void User::set_password(std::string p)
{
	this->password = p;
}

bool User::operator==(const User& u)
{
	return ((this->id == u.id) && (this->name == u.name) && (this->surname == u.surname) && (this->email == u.email) && (this->password == u.password) && (this->age == u.age));
}

bool User::operator!=(const User& u)
{
	return ((this->id != u.id) || (this->name != u.name) || (this->surname != u.surname) || (this->email != u.email) || (this->password != u.password) || (this->age != u.age));
}

User& User::operator=(const User& u)
{
	if (this != &u)
	{
		this->id = u.id;
		this->name = u.name;
		this->surname = u.surname;
		this->email = u.email;
		this->password = u.password;
		this->age = u.age;
	}
	return *this;
}

std::string User::toString()
{
	return std::to_string(this->id) + ',' + this->name + ',' + this->surname + ',' + this->email + ',' + this->password + ',' + std::to_string(this->age);
}

std::ostream& operator<<(std::ostream& os, const User& u)
{
	os << "<<< USER: ID: " << u.id << ", NAME: " << u.name << ", SURNAME: " << u.surname << ", EMAIL: " << u.email << ", AGE: " << u.age;
	return os;
}

std::istream& operator>>(std::istream& is, User& u)
{
	std::string name, surname, email, password; int id, age;
	std::cout << "Give the user's personal ID: ";
	is >> id;
	u.set_id(id);
	std::cout << "Give the user's name: ";
	is >> name;
	u.set_name(name);
	std::cout << "Give the user's surname: ";
	is >> surname;
	u.set_surname(surname);
	std::cout << "Give the user's email: ";
	is >> email;
	u.set_email(email);
	std::cout << "Give the user's password: ";
	is >> password;
	u.set_password(password);
	std::cout << "Give the user's age: ";
	is >> age;
	u.set_age(age);
	return is;
}
