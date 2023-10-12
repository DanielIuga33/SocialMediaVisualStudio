#include "Tests.h"
#include "UI.h"
#include "RepoTemplate.h"
int main() {
	test_all();
	RepoTemplate<User> repo_user("Users.txt");
	RepoTemplate<Request> repo_req("Requests.txt");
	RepoTemplate<Friendship> repo_fr("Friendships.txt");
	RepoTemplate<Message> repo_msg("Messages.txt");
	ServiceUser srv_user = ServiceUser(repo_user);
	ServiceRequest srv_req = ServiceRequest(repo_req);
	ServiceMessage srv_msg = ServiceMessage(repo_msg);
	ServiceFriendship srv_fr = ServiceFriendship(repo_fr);
	UI ui(srv_user, srv_req, srv_msg, srv_fr);
	ui.run();
	return 0;
}