#include "ServiceRequest.h"

void ServiceRequest::add(int id1, int id2)
{
	Request rq(id1, id2);
	repo.addElem(rq);
}

void ServiceRequest::del(int id1, int id2)
{
	if (this->repo.getAll().size() > 0) {
		Request rq(id1, id2);
		this->repo.deleteElem(rq);
	}
}

std::vector<Request> ServiceRequest::get_all()
{
	return this->repo.getAll();
}

int ServiceRequest::size()
{
	return this->repo.getLength();
}

bool ServiceRequest::exists(int id1, int id2)
{
	Request fr(id1, id2);
	for (int i = 0; i < repo.getLength(); i++) {
		if (repo.getAll()[i] == fr)
			return true;
	}
	return false;
}

bool ServiceRequest::exists_requests(int id2)
{
	for (int i = 0; i < size(); i++) {
		if (this->repo.getAll()[i].get_id2() == id2)
			return true;
	}
	return false;
}

vector<int> ServiceRequest::find_requests(int id2)
{
	vector<int> requests;
	if (exists_requests(id2)) {
		for (int i = 0; i < size(); i++) {
			if (this->repo.getAll()[i].get_id2() == id2)
				requests.push_back(this->repo.getAll()[i].get_id1());
		}
	}
	return requests;
}
