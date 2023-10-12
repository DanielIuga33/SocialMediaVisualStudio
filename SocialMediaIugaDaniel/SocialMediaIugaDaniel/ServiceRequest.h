#pragma once
#include "Request.h"
#include "RepoTemplate.h"
class ServiceRequest {
private:
	RepoTemplate<Request> repo;
public:
	ServiceRequest(RepoTemplate<Request> repo) : repo(repo) {};

	void add(int id1, int id2);
	void del(int id1, int id2);
	//void modify(int id1, int id2);

	std::vector<Request> get_all();
	int size();
	bool exists(int id1, int id2);
	bool exists_requests(int id2);
	vector<int> find_requests(int id2);
};