#include <cstring>
#include <string>
#include <weapon.h>
#include <book.h>

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

pe lvpeople[100] = {
	{"张慧文","guard","他是武道塔1层的守卫者，你需要打败他，才能进入2层",1000,1000,100,10,1000,1000,0,0,{"精铁剑","iron_sword","剑","用精铁铸成的剑，很坚硬",100,100,0,0,0,-10,10,16},{},0,{},{},{},false},
	{"张楚嫣","guard","她是武道塔2层的守卫者，你需要打败她，才能进入3层",2658,2658,158,27,2521,913,0,0,{"精铁剑","iron_sword","剑","用精铁铸成的剑，很坚硬",100,100,0,0,0,-10,10,16},{},0,{},{},{},false},
	{"张晓彤","guard","她是武道塔3层的守卫者，你需要打败她，才能进入4层",3479,3479,227,38,3042,1013,1000,1000,{"精铁剑","iron_sword","剑","用精铁铸成的剑，很坚硬",100,100,0,0,0,-10,10,16},{{"「武当剑法」", "e一式「2三环套月s」，连续三招，手中q化作三道光朝你飞来", "wudang-sword", 454, 10, "剑", 2, 2, 2, 2, 2, 3, 3, 1, true, 2}},1,{},{},{},false},
	{"张楚涵","guard","她是武道塔4层的守卫者，你需要打败她，才能进入5层",7332,7332,348,75,2328,3328,1000,1000,{"精铁剑","iron_sword","剑","用精铁铸成的剑，很坚硬",100,100,0,0,0,-10,10,16},{{"「武当剑法」", "e一式「2三环套月s」，连续三招，手中q化作三道光朝你飞来", "wudang-sword", 696, 20, "剑", 2, 2, 2, 2, 2, 3, 3, 1, true, 2}},1,{},{},{},false},
	{"张鸿瑞","guard","他是武道塔5层的守卫者，你需要打败他，才能进入6层",3479,3479,227,38,3042,1013,1000,1000,{"精铁剑","iron_sword","剑","用精铁铸成的剑，很坚硬",100,100,0,0,0,-10,10,16},{{"「武当剑法」", "e一式「2三环套月s」，连续三招，手中q化作三道光朝你飞来", "wudang-sword", 454, 10, "剑", 2, 2, 2, 2, 2, 3, 3, 1, true, 2}},1,{},{},{},false},
};

