#pragma once
#include "User.h"
#include "RepoTemplate.h"
class ServiceUser {
private:
	RepoTemplate<User> repo;
public:
	ServiceUser(RepoTemplate<User> repo) : repo(repo) {};

	void add(int id, std::string name, std::string surname, std::string email, std::string password, int age);
	void del(int id);
	void modify(int id_mod, int new_id, std::string new_name, std::string new_surname, std::string new_email, std::string new_password, int new_age);

	std::vector<User> get_all();
	int size();
	bool exists(int id);
	User find_by_id(int id);
	bool exists_by_email(std::string email);
	User find_by_email(std::string email);
};