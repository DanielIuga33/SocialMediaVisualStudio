#include "ServiceFriendship.h"

void ServiceFriendship::add(int id1, int id2)
{
	Friendship fr(id1, id2);
	this->repo.addElem(fr);
}

void ServiceFriendship::del(int id1, int id2)
{
	if (exists(id1, id2)) {
		Friendship fr(id1, id2);
		Friendship fr2(id2, id1);
		repo.deleteElem(fr);
		repo.deleteElem(fr2);
	}
}

std::vector<Friendship> ServiceFriendship::get_all()
{
	return this->repo.getAll();
}

int ServiceFriendship::size()
{
	return this->repo.getLength();
}

bool ServiceFriendship::exists(int id1, int id2)
{
	Friendship fr(id1, id2);
	Friendship fr1(id2, id1);
	for (int i = 0; i < repo.getLength(); i++){
		if (repo.getAll()[i] == fr || repo.getAll()[i] == fr1)
			return true;
	}
	return false;
}


Friendship ServiceFriendship::find_friendship(int id1, int id2)
{
	if (exists(id1, id2)) {
		for (int i = 0; i < repo.getLength(); i++) {
			if (repo.getAll()[i].get_id1() == id1 && repo.getAll()[i].get_id2() == id2)
				return repo.getAll()[i];
		}
	}
	return Friendship();
}
