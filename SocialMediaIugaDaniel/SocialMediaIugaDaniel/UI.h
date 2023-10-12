#pragma once
#include "ServiceUser.h"
#include "ServiceRequest.h"
#include "ServiceFriendship.h"
#include "ServiceMessage.h"
class UI {
private:
	ServiceUser srv_user;
	ServiceRequest srv_req;
	ServiceMessage srv_msg;
	ServiceFriendship srv_fr;
public:
	UI(ServiceUser& srv_user, ServiceRequest& srv_req, ServiceMessage srv_msg, ServiceFriendship srv_fr);

	void run();

	// Prints
	void main_menu();
	void admin_menu();
	void print_user_menu();

	//Admin
	bool admin_login();
	void add_user();
	void del_user();
	void modify_user();


	// User
	User user_login();
	User user_register();
	void user_interface(User u);
	void user_menu_handling(User u);

	// Requests
	void optionA(int id);

	//Friendships
	void optionC(int id);
	void optionD(int id);
	int not_friends_with(int id);
	int friends_with(int id);

	//Messages
	void write_a_message(int id1, int id2);
	void optionB(int id);
};