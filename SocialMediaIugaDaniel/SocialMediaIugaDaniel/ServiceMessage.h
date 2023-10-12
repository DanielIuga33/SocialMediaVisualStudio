#pragma once
#include "Message.h"
#include "RepoTemplate.h"
class ServiceMessage {
private:
	RepoTemplate<Message> repo;
public:
	ServiceMessage(RepoTemplate<Message> repo) : repo(repo) {};

	void add(int id1, int id2, std::string msg);
	void del(int id1, int id2);
	void modify(int id1, int id2, std::string new_msg);

	std::vector<Message> get_all();
	int size();
	bool exists(int id1, int id2);
	int messages_received(int id2);
	Message find_message(int id1, int id2);
	void send_message(int id1, int id2, std::string text);
};