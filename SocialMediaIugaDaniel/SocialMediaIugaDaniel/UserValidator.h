#pragma once
#include "User.h"

class UserValidator {
public:
	bool validate_email(std::string email) {
		std::string errors = "";
		bool ok = false;
		for (int i = 0; i < email.size(); i++)
			if (email[i] == '@' && email[email.size() - 1] == 'm' && email[email.size() - 2] == 'o' && email[email.size() - 3] == 'c' && email[email.size() - 4] == '.')
				ok = true;
		if (ok == false)
			errors.append("The email is invalid !");
		if (errors != "") {
			std::cout << "	" << errors << std::endl;
			return false;
		}
		return true;
	}
	bool good_email(std::string email) {
		std::string errors = "";
		bool ok = false;
		for (int i = 0; i < email.size(); i++)
			if (email[i] == '@' && email[email.size() - 1] == 'm' && email[email.size() - 2] == 'o' && email[email.size() - 3] == 'c' && email[email.size() - 4] == '.')
				ok = true;
		if (ok == false)
			errors.append("The email is invalid !!!\n");
		if (errors != "") {
			return false;
		}
		return true;
	}
	bool validate_age(std::string age) {
		std::string errors = "";
		try {
			int a = stoi(age);
			if (a < 0)
				errors.append("The age can't be negative !!!\n");
		}
		catch (std::exception& exc) {
			errors.append("The age must be a number !!!\n");
		}
		if (errors != "") {
			std::cout << "Error: " << errors << std::endl;
			return false;
		}
		return true;
	}
	bool validate_password(std::string password) {
		std::string errors = "";
		int i = 0;
		if (password.length() < 8) {
			errors.append("The password must have the minimum of 8 characters !!!\n");
			i++;
		}
		bool ok = false;
		for (int i = 0; i < password.length(); i++)
			if (isupper(password[i]))
				ok = true;
		if (ok == false) {
			errors.append("The password must have at least 1 upper character !!!\n");
			i++;
		}
		if (errors != "") {
			if (i == 2)
				std::cout << "Errors: \n" << errors << std::endl;
			else std::cout << "Error: " << errors << std::endl;
			return false;
		}
		return true;
	}
};