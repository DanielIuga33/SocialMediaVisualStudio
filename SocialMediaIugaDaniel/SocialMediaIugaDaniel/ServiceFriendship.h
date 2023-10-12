#pragma once
#include "Friendship.h"
#include "RepoTemplate.h"
class ServiceFriendship {
private:
	RepoTemplate<Friendship> repo;
public:
	ServiceFriendship(RepoTemplate<Friendship> repo) : repo(repo) {};

	void add(int id1, int id2);
	void del(int id1, int id2);
	//void modify(int id1, int id2);

	std::vector<Friendship> get_all();
	int size();
	bool exists(int id1, int id2);
	Friendship find_friendship(int id1, int id2);
};