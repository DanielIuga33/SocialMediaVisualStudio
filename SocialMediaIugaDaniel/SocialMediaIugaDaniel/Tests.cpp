#include "Tests.h"

void test_user()
{
	User u(1, "Iuga", "Daniel", "danieliuga33@yahoo.com", "cremesel", 19);
	assert(u.get_id() == 1);
	assert(u.get_name() == "Iuga");
	assert(u.get_surname() == "Daniel");
	assert(u.get_email() == "danieliuga33@yahoo.com");
	assert(u.get_password() == "cremesel");
	assert(u.get_age() == 19);
	u.set_id(2); u.set_name("Szasz"); u.set_surname("Andrei"); u.set_email("andreiszasz@yahoo.com"); u.set_password("szaszu"); u.set_age(18);
	assert(u.get_id() == 2);
	assert(u.get_name() == "Szasz");
	assert(u.get_surname() == "Andrei");
	assert(u.get_email() == "andreiszasz@yahoo.com");
	assert(u.get_password() == "szaszu");
	assert(u.get_age() == 18);
}

void test_integer_vlidator()
{
	std::string x = "1", a = "10", z = "a", f = "zece";
	assert(integer_validator(x) == true);
	assert(integer_validator(a) == true);
	assert(integer_validator(z) == false);
	assert(integer_validator(f) == false);
}

void test_all()
{
	test_user();
	test_integer_vlidator();
}
