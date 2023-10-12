#include "ServiceUser.h"




void ServiceUser::add(int id, std::string name, std::string surname, std::string email, std::string password, int age)
{
	User u(id, name, surname, email, password, age);
	repo.addElem(u);
}

void ServiceUser::del(int id)
{
	User u = find_by_id(id);
	repo.deleteElem(u);
}

void ServiceUser::modify(int id_mod, int new_id, std::string new_name, std::string new_surname, std::string new_email, std::string new_password, int new_age)
{
	User u = find_by_id(id_mod);
	User u1(new_id, new_name, new_surname, new_email, new_password, new_age);
	repo.updateElem(u, u1);
}

std::vector<User> ServiceUser::get_all()
{
	return this->repo.getAll();
}

int ServiceUser::size()
{
	return repo.getLength();
}

bool ServiceUser::exists(int id)
{
	for (int i = 0; i < size(); i++)
		if (repo.getAll()[i].get_id() == id)
			return true;
	return false;
}

User ServiceUser::find_by_id(int id)
{
	if (exists(id))
		for (int i = 0; i < size(); i++)
			if (repo.getAll()[i].get_id() == id)
				return repo.getAll()[i];
}

bool ServiceUser::exists_by_email(std::string email)
{
	for (int i = 0; i < size(); i++)
		if (repo.getAll()[i].get_email() == email)
			return true;
	return false;
}

User ServiceUser::find_by_email(std::string email)
{
	if (exists_by_email(email))
		for (int i = 0; i < size(); i++)
			if (repo.getAll()[i].get_email() == email)
				return repo.getAll()[i];
	return User();
}
