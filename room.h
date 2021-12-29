#include <cstring>
#include <string>
#include <people.h>
#include <map>

using namespace std;

struct ro { //room
	string name;
	string Englishname;
	string tell;
	pe people[100];
	we weapon[100];
	bo book[100];
	th thing[100];
	string dir[100];
	int cango[100];
	we weaponsell[100];
	bo booksell[100];
	th thingsell[100];
	bool isshop;
};



