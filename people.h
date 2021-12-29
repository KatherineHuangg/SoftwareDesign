#include <cstring>
#include <string>
#include <skill.h>
#include <weapon.h>
#include <book.h>
#include <thing.h>

using namespace std;

struct pe {
	string name;
	string Englishname;
	string tell;
	int health, maxhealth;
	int damage;
	int defense;
	int dodge, hit;
	int force, maxforce;
	we weapon;
	sk skills[100];
	int skillsnum;
	bo dropbook;
	we dropweapon;
	th dropthing;
	bool canbai;
	bool canmove;
};