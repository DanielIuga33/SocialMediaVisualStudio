#include "ServiceMessage.h"
#include <iostream>

void ServiceMessage::add(int id1, int id2, std::string msg)
{
	Message msga(id1, id2, msg);
	Message msga1(id2, id1, msg);
	vector<Message> temp;
	for (Message mess : get_all()) {
		if (mess != msga && mess != msga1) {
			temp.push_back(mess);
		}
	}
	for (Message mess : get_all()) {
		this->repo.deleteElem(mess);
	}
	for (Message mess : temp) {
		this->repo.addElem(mess);
	}
	this->repo.addElem(msga);
}

void ServiceMessage::del(int id1, int id2)
{
	/*if (exists(id1, id2)) {
		Message msg = find_message(id1, id2);
		this->repo.deleteElem(msg);
	}
	if (exists(id2, id1)) {
		Message msg = find_message(id2, id1);
		this->repo.deleteElem(msg);
	}*/
	Message msga(id1, id2, "");
	Message msga1(id2, id1, "");
	vector<Message> temp;
	for (Message mess : get_all()) {
		if (mess != msga && mess != msga1) {
			temp.push_back(mess);
		}
	}
	for (Message mess : get_all()) {
		this->repo.deleteElem(mess);
	}
	for (Message mess : temp) {
		this->repo.addElem(mess);
	}

}

void ServiceMessage::modify(int id1, int id2, std::string new_msg)
{
	Message msg_old = find_message(id1, id2);
	Message msg_new(id1, id2, new_msg);
	repo.updateElem(msg_old, msg_new);

}

std::vector<Message> ServiceMessage::get_all()
{
	return this->repo.getAll();
}

int ServiceMessage::size()
{
	return this->repo.getAll().size();
}

bool ServiceMessage::exists(int id1, int id2)
{
	if (size() == 0) return false;
	/*for (int i = 0; i < size(); i++) {
		if (get_all()[i].get_id1() == id1 || get_all()[i].get_id2() == id1)
			if (get_all()[i].get_id1() == id2 || get_all()[i].get_id2() == id2)
				return true;
	}*/
	Message m(id1, id2, "");
	for (Message msg : get_all()) {
		if (msg == m) {
			return true;
		}
	}
	return false;

}

int ServiceMessage::messages_received(int id2)
{
	int j = 0;
	for (int i = 0; i < size(); i++) {
		if (get_all()[i].get_id2() == id2)
			j++;
	}
	return j;
}


Message ServiceMessage::find_message(int id1, int id2)
{
	if (exists(id1, id2)) {
		/*for (int i = 0; i < size(); i++) {
			if (get_all()[i].get_id1() == id1 || get_all()[i].get_id2() == id1)
				if (get_all()[i].get_id1() == id2 || get_all()[i].get_id2() == id2)
					return get_all()[i];
		}*/
		Message m(id1, id2, "");
		for (Message msg : get_all()) {
			if (msg == m) {
				return msg;
			}
		}
	}
	return Message();
}

void ServiceMessage::send_message(int id1, int id2, std::string text)
{
	Message msg = find_message(id1, id2);
	Message msg1(id2, id1, "");
	std::string msj = msg.get_message() + text;
	msg.set_message(msj);
	//	del(id1, id2);
	//	add(id1, id2, msj);
	//del(id1, id2);
	add(id1, id2, msj);
}
