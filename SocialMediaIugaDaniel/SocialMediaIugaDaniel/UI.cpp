#include "UI.h"
#include "UserValidator.h"
#include <conio.h>
#include<windows.h> 
#include <chrono>
#include <thread>



UI::UI(ServiceUser& srv_user, ServiceRequest& srv_req, ServiceMessage srv_msg, ServiceFriendship srv_fr) : srv_user{ srv_user },
srv_req{ srv_req }, srv_msg{ srv_msg }, srv_fr{ srv_fr } { };


template<class T>
void showall_vector(std::vector<T> elems, std::string text) {
	if (elems.size() > 0) {
		std::cout << text << std::endl;
		for (int i = 0; i < elems.size(); i++)
			std::cout << "\t" << elems[i] << std::endl;
	}
	else std::cout << "There is nothing to show !!!" << std::endl;
}

template<class T>
std::vector<T> remove_entity(T temp, std::vector<T> elems) {
	vector<T> result;
	for (int i = 0; i < elems.size(); i++) {
		if (elems[i] != temp) {
			result.push_back(elems[i]);
		}
	}
	return result;
}


void UI::main_menu()
{
	std::cout << std::endl; std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;
	std::cout << "__________________________________________________________________________________________________\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|        |==========================================================================|            |\n";
	std::cout << "|        |   *             *  ******  *      *****  ******  **    **  ******    |   |            |\n";
	std::cout << "|         |   *     *     *   *       *      *      *    *  * *  * *  *         |  |             |\n";
	std::cout << "|         |    *   * *   *    *****   *      *      *    *  *   *  *  *****     |  |             |\n";
	std::cout << "|         |     * *   * *     *       *      *      *    *  *      *  *         |  |             |\n";
	std::cout << "|        |       *     *      ******  *****  *****  ******  *      *  ******    *   |            |\n";
	std::cout << "|        |=======================|====================|=============================|            |\n";
	std::cout << "|                                | [1]. LOGIN         |                                          |\n";
	std::cout << "|                                | [2]. REGISTER      |                                          |\n";
	std::cout << "|                                | [x]. Leave the app |                                          |\n";
	std::cout << "|                                |====================|                                          |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|________________________________________________________________________________________________|\n";
}


void UI::user_interface(User u) {
	std::cout << "\n\n\n\n                                   >>|    Hello  " << u.get_surname() << " !  |<<                             \n";
	std::cout << "__________________________________________________________________________________________________\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "| A. FRIENDSHIP REQUESTS (" << srv_req.find_requests(u.get_id()).size() << ")";
	if (srv_req.find_requests(u.get_id()).size() < 10) std::cout << " ";
	if (srv_req.find_requests(u.get_id()).size() < 100) std::cout << " ";
	std::cout << "                              D.MANAGE/TEXT FRIENDS (" << friends_with(u.get_id()) << " Friends)";
	if (friends_with(u.get_id()) < 10) std::cout << " ";
	if (friends_with(u.get_id()) < 100) std::cout << " ";
	std::cout << "  | \n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "| B. MESSENGER (" << srv_msg.messages_received(u.get_id()) << ")";
	if (srv_msg.messages_received(u.get_id()) < 10) std::cout << " ";
	if (srv_msg.messages_received(u.get_id()) < 100) std::cout << " ";
	std::cout << "                                                                             |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "| C. SHOW PEOPLE (" << not_friends_with(u.get_id()) << " Available People)";
	if (not_friends_with(u.get_id()) < 10) std::cout << " ";
	if (not_friends_with(u.get_id()) < 100) std::cout << " ";
	std::cout << "                                     X.LOGOUT             |\n";
	std::cout << "|                                                                                                |\n";
	std::cout << "|________________________________________________________________________________________________|\n";
}


void UI::user_menu_handling(User u)
{
	string option;
	while (true) {
		user_interface(u);
		std::cout << "\t\tGive the option: "; std::cin >> option;
		if (option == "A" || option == "a") {
			optionA(u.get_id());
		}
		else if (option == "B" || option == "b") {
			optionB(u.get_id());
		}
		else if (option == "C" || option == "c") {
			optionC(u.get_id());
		}
		else if (option == "D" || option == "d") {
			optionD(u.get_id());
		}
		else if (option == "X" || option == "x")
			return;

	}
}

/// <summary>
/// ADMIN MENU
/// </summary>

void UI::admin_menu()
{
	std::cout << std::endl;
	std::cout << "(1). User menu" << std::endl;
	std::cout << "(x). Exit" << std::endl;
	while (true) {
		std::string option_ad;
		std::cout << "Give the option: "; std::cin >> option_ad;
		if (option_ad == "1")
			while (true) {
				print_user_menu();
				std::string option_u;
				std::cout << "Give the option you want: "; std::cin >> option_u;
				if (option_u == "1")
					add_user();
				else if (option_u == "2")
					del_user();
				else if (option_u == "3")
					modify_user();
				else if (option_u == "a")
					showall_vector(srv_user.get_all(), "The users are: ");
				else if (option_u == "x")
					break;
				else std::cout << "Wrong option !!!" << std::endl;
			}
		else if (option_ad == "x")
			return;
		else std::cout << "Wrong option !!!" << std::endl;
	}
}

void UI::print_user_menu()
{
	std::cout << std::endl;
	std::cout << "(1). Add User" << std::endl;
	std::cout << "(2). Delete User" << std::endl;
	std::cout << "(3). Modify User" << std::endl;
	std::cout << "(a). Show all the Users" << std::endl;
	std::cout << "(x). Exit" << std::endl;
}

void UI::add_user()
{
	UserValidator validator;
	int id; std::string n, sn, e, p, age;
	id = srv_user.size() + 1;
	std::cout << "Give the name of the user: "; cin >> n;
	std::cout << "Give the surname of the user: "; std::getline(std::cin >> ws, sn);
	std::cout << "Give the email of the user: "; cin >> e;
	if (validator.validate_email(e)) {
		std::cout << "Give the password of the user: "; //cin >> p;
		char p[100] = { 0 };
		int i;
		for (i = 0; i < 100; i++) {
			p[i] = _getch(); _putch('*');
			if (p[i] == 13) break;
		};
		std::cout << std::endl;
		if (validator.validate_password(p)) {
			std::cout << "Give the age of the user: "; cin >> age;
			if (validator.validate_age(age))
				srv_user.add(id, n, sn, e, p, stoi(age));
		}
	}
}

void UI::del_user()
{
	int id;
	std::cout << "Give the id of the User you want to delete: "; cin >> id;
	srv_user.del(id);
	std::cout << "User deleted succesfuly\n";
}

void UI::modify_user()
{
	int id;
	std::cout << "Give the id of the User you want to modify: "; cin >> id;
	if (srv_user.exists(id)) {
		User u;
		std::cin >> u;
	}
	else std::cout << "This User does not exist !!!" << std::endl;
}


bool UI::admin_login() {
	std::string pass;
	std::cout << "Enter the password: "; std::cin >> pass;
	while (pass != "admin") {
		std::cout << "The Password is incorect !, try again or press x to exit: "; std::cin >> pass;
		if (pass == "x" || pass == "X")
			return false;
	}
	return true;
}


// ADMIN END





/// <summary>
///  USER MENU
/// </summary>


User UI::user_login() {
	UserValidator validator;
	std::string email;
	std::cout << "\t\tEmail: "; std::cin >> email;
	while (!validator.validate_email(email) || srv_user.find_by_email(email) == User()) {
		if (validator.good_email(email))
			std::cout << "\tThis email does not exist!\n\tPlease try again or press x to quit\n";
		else cout << "\tPlease try again or press x to quit\n";
		email = "";
		std::cout << "\t\tEmail : "; std::cin >> email;
		if (email == "x")
			return User();
	}
	User u = srv_user.find_by_email(email);
	std::cout << "\t\tPassword: "; //cin >> p;
	char p[100] = { 0 };
	int i;
	for (i = 0; i < 100; i++) {
		p[i] = _getch(); _putch('*');
		if (p[i] == 13) break;
	};
	std::cout << std::endl;
	if (u.get_password() == p) {
		std::cout << "\n\t\tYou succesfully logged in !\n\n\n\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return u;
	}
	std::cout << "\t\t\t\n        The password is incorrect !\n\tPlease try again !\n";
	std::cout << "\t\tPassword : "; //cin >> p;
	char q[100] = { 0 };
	for (i = 0; i < 100; i++) {
		q[i] = _getch(); _putch('*');
		if (q[i] == 13) break;
	};
	if (u.get_password() == q) {
		std::cout << "\n\t\tYou succesfully logged in !\n\n\n\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return u;
	}
	std::cout << "\t\t\t\n        The password is incorrect !\n\tPlease try again\n";
	std::cout << "\t\tPassword : "; //cin >> p;
	char s[100] = { 0 };
	for (i = 0; i < 100; i++) {
		s[i] = _getch(); _putch('*');
		if (s[i] == 13) break;
	};
	if (u.get_password() == s) {
		std::cout << "\n\t\tYou succesfully logged in !\n\n\n\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return u;
	}
	std::cout << "Too many attempts !\n";
	return User();
}

User UI::user_register()
{
	UserValidator validator;
	string name, surname, email,age;
	std::cout << "\t\t>| HELLO AND WELCOME TO OUR SOCIAL APPLICATION ! |<" << std::endl;
	int id = srv_user.size() + 1;
	std::cout << "\tName: "; std::cin >> name;
	std::cout << "\tSurname: "; std::getline(std::cin >> ws, surname);
	std::cout << "\tEmail: "; std::cin >> email;
	while (!validator.validate_email(email) || srv_user.exists_by_email(email)) {
		std::cout << "This email already exists!\n Please try another one or press x to quit\n";
		email = "";
		std::cout << "\tEmail: "; std::cin >> email;
		if (email == "x")
			return User();
	}
	if (validator.validate_email(email)) {
		std::cout << "\tPassword:"; //cin >> p;
		char p[100] = { 0 };
		int i;
		for (i = 0; i < 100; i++) {
			p[i] = _getch(); _putch('*');
			if (p[i] == 13) break;
		};
		std::cout << std::endl;
		if (validator.validate_password(p)) {
			std::cout << "\tConfirm Password:"; //cin >> p;
			char c[100] = { 0 };
			int i;
			for (i = 0; i < 100; i++) {
				c[i] = _getch(); _putch('*');
				if (c[i] == 13) break;
			};
			std::cout << std::endl;
			int x = 0;
			while (strcmp(c,p) != 0 && x < 3) {
				std::cout << "\n\tPassword doesn't match, try again !!!" << std::endl;
				x++;
				std::cout << "\tConfirm Password:"; //cin >> p;
				char s[100] = { 0 };
				int i;
				for (i = 0; i < 100; i++) {
					s[i] = _getch(); _putch('*');
					if (s[i] == 13) break;
				};
				if (strcmp(s, p) == 0) x = 4;
			}
			if (x == 3) return User();
			std::cout << "\tGive your age: "; cin >> age;
			if (validator.validate_age(age)) {
				srv_user.add(id, name, surname, email, p, stoi(age));
				std::cout << "\n\t\tYou succesfully registered !\n\n\n\n";
				this_thread::sleep_for(chrono::milliseconds(1000));
				return User(id, name, surname, email, p, stoi(age));
			}
		}
	}
	return User();
}




// USER END



/// <summary>
/// REQUEST MENU
/// </summary>

void UI::optionA(int id)
{
	std::vector<User> requests;
	int k, n; std::string opt,n1;
	for (int i = 0; i < srv_req.size(); i++) {
		if (srv_req.get_all()[i].get_id2() == id) {
			User u = srv_user.find_by_id(srv_req.get_all()[i].get_id1());
			requests.push_back(u);
		}
	}
	if (requests.size() == 0) {
		std::cout << "\tYou don't have any requests !\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return;
	}
	if (requests.size() == 1) {
		std::cout << requests[0].get_name() << " " << requests[0].get_surname() << " wants to be your friend\n";
		std::cout << "\t[1]Accept\n\t[2]Decline\n\t[x]Exit\n\tYour option: "; std::cin >> opt;
		if (opt == "1") {
			srv_fr.add(id, requests[0].get_id());
			std::cout << "\tFriend was added succesfully !\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			srv_req.del(requests[0].get_id(), id);
		}
		else if (opt == "2") {
			std::cout << "\tDeclined succesfully !\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			srv_req.del(requests[0].get_id(), id);
		}
		return;
	}
	std::cout << "\t Requests: \n";
	for (int i = 0; i < requests.size(); i++) {
		std::cout << "[" << i + 1 << "]. " << requests[i].get_name() << " " << requests[i].get_surname() << "\n";
	}
	std::cout << "\tChoose how many requests you want to answer: "; std::cin >> n1;
	if (!integer_validator(n1)) {
		cout << "\tYou needed to put a number here !\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return;
	}
	n = stoi(n1);
	if (n > requests.size()) {
		std::cout << "There are not that much requests !!\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return;
	}
	for (int i = 0; i < n; i++) {
		std::cout << "\t Requests: \n";
		for (int j = 0; j < requests.size(); j++) {
			std::cout << "[" << j + 1 << "]. " << requests[j].get_name() << " " << requests[j].get_surname() << "\n";
		}
		std::cout << "Choose which one do you want to answer: "; std::cin >> n1;
		if (!integer_validator(n1)) {
			cout << "\tYou needed to put a number here !\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			return;
		}
		k = stoi(n1);
		k = k - 1;
		std::cout << "\t[1]Accept\n\t[2]Decline\n\t[x]Exit\n\tYour option: "; std::cin >> opt;
		if (opt == "1") {
			srv_fr.add(id, requests[k].get_id());
			std::cout << "Friend was added succesfully !\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			srv_req.del(requests[k].get_id(), id);
			requests = remove_entity(requests[k], requests);
		}
		else if (opt == "2") {
			srv_req.del(requests[k].get_id(), id);
			std::cout << "\tDeclined succesfully !\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			requests = remove_entity(requests[k], requests);
		}
	}
}



// REQUEST END

/// <summary>
/// FRIENDSHIP MENU
/// </summary>

void UI::optionC(int id)
{
	std::string opt, n1; int k, n;
	std::vector<User> not_friends;
	for (int i = 0; i < srv_user.get_all().size(); i++) {
		if (!srv_fr.exists(id, srv_user.get_all()[i].get_id()) && srv_user.get_all()[i].get_id() != id && !srv_req.exists(id, srv_user.get_all()[i].get_id()))
			not_friends.push_back(srv_user.get_all()[i]);
	}
	if (not_friends.size() == 0) {
		std::cout << "\tThere are no users available !\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return;
	}
	std::cout << "\t Available Users: \n";
	for (int i = 0; i < not_friends.size(); i++) {
		std::cout << "[" << i+1 << "]. " << not_friends[i].get_name() << " " << not_friends[i].get_surname() << "\n";
	}

	if (not_friends.size() == 1) {
		std::cout << "Do you want to add this Use?\n\t[1] Yes\n\t[2] No\n\tYour option: ";
		std::cin >> opt;
		if (opt == "1") {
			srv_req.add(id, not_friends[0].get_id());
			std::cout << "The friend request was succesfully sent !\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
	}
	std::cout << "Choose how many users you want to add or press x to exit: "; std::cin >> n1;
	if (n1 == "x") return;
	if (!integer_validator(n1)) {
		cout << "\tYou needed to put a number here !\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return;
	}
	n = stoi(n1);
	if (n > not_friends.size()) {
		std::cout << "\tThere are not that much users available !!\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return;
	}
	if (n == not_friends.size()) {
		for (User u : not_friends) {
			srv_req.add(id, u.get_id());
		}
		std::cout << "\tSuccesfully added the entire list !\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i > 3)
		std::cout << "\t Available Users: \n";
		for (int j = 0; j < not_friends.size(); j++) {
			std::cout << "[" << j + 1 << "]. " << not_friends[j].get_name() << " " << not_friends[j].get_surname() << "\n";
		}
		std::cout << "User number:"; std::cin >> n1;
		if (!integer_validator(n1)) {
			cout << "\tYou needed to put a number here !\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			return;
		}
		k = stoi(n1);
		k--;
		if (k >= 0 && k < not_friends.size()) {
			srv_req.add(id, not_friends[k].get_id());
			not_friends = remove_entity(not_friends[k], not_friends);
		}
		else std::cout << "\tInvalid number!\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	
}

void UI::optionD(int id)
{
	std::vector<User> friends;
	int k; std::string option, quit;
	for (int i = 0; i < srv_user.get_all().size(); i++) {
		if (srv_fr.exists(id, srv_user.get_all()[i].get_id()))
			friends.push_back(srv_user.get_all()[i]);
	}
	if (friends.size() == 0) {
		std::cout << "\tYou have no friends yet!\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return;
	}
	if (friends.size() == 1) {
		std::cout << "Your friend " << friends[0].get_name() << " " << friends[0].get_surname() << "\n";
		std::cout << "\t[1] TEXT/START A CONVERSATION\n\t[2] REMOVE FRIEND\n\t[x] EXIT\n\tYour option: "; std::cin >> option;
		if (option == "1") {
			write_a_message(id, friends[0].get_id());
		}
		else if (option == "2") {
			srv_fr.del(id, friends[0].get_id());srv_msg.del(id, friends[0].get_id());
		}
		return;
	}
	std::cout << "\t Your friends: \n";
	for (int i = 0; i < friends.size(); i++) {
		std::cout << "[" << i + 1 << "]. " << friends[i].get_name() << " " << friends[i].get_surname() << "\n";
	}
	std::cout << "Choose who you want to manage or press x to quit: "; std::cin >> quit;
	if (quit == "x") return;
	if (!integer_validator(quit)) {
		cout << "\tYou needed to put a number here !\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		return;
	}
	k = stoi(quit);
	k--;
	if (k >= 0 && k < friends.size()) {
		std::cout << "\t[1] TEXT/START A CONVERSATION\n\t[2] REMOVE FRIEND\n\t[x] EXIT\n\tYour option: ";std::cin >> option;
		if (option == "1") {
			write_a_message(id, friends[k].get_id());
		}
		else if (option == "2") {
			srv_fr.del(id, friends[k].get_id());
			std::cout << "\tFriend removed succesfully !\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			srv_msg.del(id, friends[k].get_id());
		}
		else return;
	}

}

int UI::not_friends_with(int id) {
	int j = 0;
	for (int i = 0; i < srv_user.get_all().size(); i++) {
		if (!srv_fr.exists(id, srv_user.get_all()[i].get_id()) && srv_user.get_all()[i].get_id() != id && !srv_req.exists(id, srv_user.get_all()[i].get_id()))
			j++;
	}
	return j;
}

int UI::friends_with(int id)
{
	int j = 0;
	for (int i = 0; i < srv_user.get_all().size(); i++) {
		if (srv_fr.exists(id, srv_user.get_all()[i].get_id()))
			j++;
	}
	return j;
}



//FRIENDSHIP END

/// <summary>
/// MESSAGE MENU
/// </summary>

void read_message(std::string text) {
	if (text.size() > 0) {
		std::cout << endl;
		std::vector<std::string> messages = splitLine(text, '^');
		for (std::string line : messages)
			std::cout << line << std::endl;
		std::cout << endl;
		return;
	}
	cout << "\n\n\tThere is no conversation yet !\n\n";
}

void UI::write_a_message(int id1, int id2)
{
	std::string text, intro;
	read_message(srv_msg.find_message(id1, id2).get_message());
	if (srv_msg.find_message(id1, id2).get_id1() == id2) {
		intro = srv_user.find_by_id(id1).get_surname() + "-> ";
	}
	else {
		intro = "  ";
		for (int i = 0; i < srv_user.find_by_id(id1).get_surname().size(); i++)
			intro = intro + " ";
	}
	if (!srv_msg.exists(id1, id2)) {
		intro = srv_user.find_by_id(id1).get_surname() + "->";
	}
	std::cout << "Write the message: "; std::getline(std::cin >> ws, text);
	std::string message = intro + text + "^";
	srv_msg.send_message(id1, id2, message);
	std::cout << "\tThe message was succesfully sent !\n";
	this_thread::sleep_for(chrono::milliseconds(1000));
}


void UI::optionB(int id)
{
	std::vector<int> friends;
	std::string choice;
	while (true) {
		int i = 1;
		for (Message msg : srv_msg.get_all()) {
			if (msg.get_id2() == id) {
				User u = srv_user.find_by_id(msg.get_id1());
				friends.push_back(msg.get_id1());
				std::cout << "\n [" << i << "] " << u.get_surname() << " " << u.get_name() << " sent you a message\n";
				i++;
			}
		}
		if (friends.size() == 1) {
			std::cout << "Press anything if you want to answer or press x to exit: "; std::cin >> choice;
			if (choice == "x") return;
			write_a_message(id, friends[0]);
			return;
		}
		if (friends.size() == 0) { 
			std::cout << "You haven't received any messages yet !\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			return; 
		}
		std::cout << "Choose who you want to answer or press x to exit: "; std::cin >> choice;
		if (choice == "x") return;
		if (!integer_validator(choice)) {
			cout << "\tYou needed to put a number here !\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			return;
		}
		int k = stoi(choice);
		k--;
		if (k < 0 || k > i - 1) {
			std::cout << "\tYour choice is incorrect !";
			this_thread::sleep_for(chrono::milliseconds(1000));
			return;
		}
		write_a_message(id, friends[k]);
		friends.clear();
	}
}


//MESSAGE END
void UI::run()
{
	while (true) {
		main_menu();
		string optiune;
		std::cout << "\t\t\tGive the option you want: "; std::cin >> optiune;
		if (optiune == "1") {
			User u = user_login();
			if (u != User()) user_menu_handling(u);;
		}
		else if (optiune == "2")
			User u = user_register();
		else if (optiune == "admin") {
			if (admin_login()) admin_menu();
		}
		else if (optiune == "x")
			return;
		else std::cout << "Wrong option !!!" << std::endl;
	}
}
