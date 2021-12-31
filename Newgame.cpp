#include <iostream>
#include <stdio.h>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <string>
#include <cstring>
#include <unistd.h>

//#include <conio.h>
#include <fstream>
#include <ctime>
#include <map>
#include <climits>
#include <algorithm>
#include <vector>
#include <iomanip>
#define edition "1.1.2"

#include <thing.h>
#include <weapon.h>
#include <book.h>
#include <room.h>
#include <people.h>
#include <skill.h>
#include <action.h>
#include <userInfo.h>

using namespace std;
////new
vector<string> allskilllevel_vect {"一无所知", "不知所以", "略知一二", "出入武林", "半生不熟", "渐入高深", "平淡无奇", 
"似有所悟", "心神领会", "运用自如", "熟能生巧", "驾轻就熟", "高深莫测", "万人之上", "出神入化", "惊天动地", 
"旷古绝伦", "举世无双", "绝世高深", "万年不朽", "返璞归真"};


map<string, void (Action::*)()> InputMap;
Action action;
#define userInfo action.userInfo

/*std::map<std::string, void (Scene::*)()> sfMap;
    Scene scene;
    sfMap["runMe"] = &Scene::runMe;

    // call via reference to object
    (scene.*sfMap["runMe"])();
*/

////new

void color(short x) {
	if (x >= 0 && x <= 15) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	} else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

map<string, string> GeneralAttack = {
	{"刀","a挥起手中x一刀朝b砍来"},
	{"剑","a提起手中x朝b刺来"},
	{"拳","a一拳朝b挥来"},
	{"鞭","a拿起手中x朝b抽来"},
	{"棍","a抡起手中x冲b一扫"},
	{"抓","a一手往b抓来"}
};

int outroom() {
	cout << "\t" << userInfo.inroom.name << "(";
	color(9);
	cout << userInfo.inroom.Englishname;
	color(16);
	cout << ")" << endl;
	cout << userInfo.inroom.tell << endl;
	cout << endl;
	if (userInfo.inroom.dir[0] == "") {
		cout << "这里没有任何明显出口";
	} else {
		cout << "这里明显的出口有：";
		cout << userInfo.inroom.dir[0];
		for (int i = 1; i < 100; i++) {
			if (userInfo.inroom.dir[i] != "") {
				cout << "," << userInfo.inroom.dir[i];
			}
		}
	}
	cout << endl << endl;
	for (int i = 0; i < 100; i++) {
		if (userInfo.inroom.people[i].name != "") {
			cout << userInfo.inroom.people[i].name << "(";
			color(3);
			cout << userInfo.inroom.people[i].Englishname;
			color(16);
			cout << ")";
			cout << "[";
			if (userInfo.inroom.people[i].health > userInfo.inroom.people[i].maxhealth / 6 * 5) color(10);
			else if (userInfo.inroom.people[i].health > userInfo.inroom.people[i].maxhealth / 6 * 4) color(
				14);
			else if (userInfo.inroom.people[i].health > userInfo.inroom.people[i].maxhealth / 6 * 3) color(
				14);
			else if (userInfo.inroom.people[i].health > userInfo.inroom.people[i].maxhealth / 6 * 2) color(
				12);
			else if (userInfo.inroom.people[i].health > userInfo.inroom.people[i].maxhealth / 6) color(12);
			else color(4);
			cout << userInfo.inroom.people[i].health;
			color(16);
			cout << "/";
			color(10);
			cout << userInfo.inroom.people[i].maxhealth;
			color(16);
			cout << "]" << endl;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (userInfo.inroom.weapon[i].name != "") {
			color(userInfo.inroom.weapon[i].lv);
			cout << userInfo.inroom.weapon[i].name;
			color(16);
			cout << "(";
			color(3);
			cout << userInfo.inroom.weapon[i].Englishname;
			color(16);
			cout << ")" << endl;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (userInfo.inroom.book[i].name != "") {
			cout << userInfo.inroom.book[i].name << "(";
			color(3);
			cout << userInfo.inroom.book[i].Englishname;
			color(16);
			cout << ")" << endl;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (userInfo.inroom.thing[i].name != "") {
			cout << userInfo.inroom.thing[i].name << "(";
			color(3);
			cout << userInfo.inroom.thing[i].Englishname;
			color(16);
			cout << ")" << endl;
		}
	}
	return 0;
}
int conversion() {
	if (coin >= 100) {
		silver += coin / 100;
		coin %= 100;
	}
	if (silver >= 100) {
		gold += silver / 100;
		silver %= 100;
	}
	return 0;
}
int make_corpse(pe people, we weapon) {
	th corpse = { people.name + "的尸体","corpse","这是" + people.name + "的尸体",10 };
	we weap = weapon;
	weap.name = people.name + "的" + weapon.name;
	weap.tell = weapon.tell + "，它原来是" + people.name + "的，但" + people.name +
		"已经被杀了，这个" + weapon.type + "就传到你手中了";
	for (int j = 0; j < 100; j++) {
		if (inroom.people[j].name == people.name) {
			inroom.people[j] = {};
			room[nowroomi].people[j] = {};
			break;
		}
	}
	for (int j = 0; j < 100; j++) {
		if (inroom.thing[j].name == "") {
			inroom.thing[j] = corpse;
			room[nowroomi].thing[j] = corpse;
			break;
		}
	}
	for (int j = 0; j < 100; j++) {
		if (inroom.weapon[j].name == "") {
			inroom.weapon[j] = weap;
			room[nowroomi].weapon[j] = weap;
			break;
		}
	}
	return 0;
}
int killall(pe people[100], int peoplenum, int peoplei[100]) {
	bool cm[100];
	for (int i = 0; i < peoplenum; i++) {
		cm[i] = userInfo.inroom.people[peoplei[i]].canmove;
		room[userInfo.nowroomi].people[peoplei[i]].canmove = false;
		userInfo.inroom.people[peoplei[i]].canmove = false;
	}
	int yell = rand() % 3;
	int lastpeople = peoplenum;
	bool die[100];
	pe me = { userInfo.myname,userInfo.myEnglishname,"",0,0,0,0,0,0,0,0,nweapon,{},0,{},{},{},false,false };
	for (int i = 0; i < 100; i++) {
		die[i] = false;
	}
	if (yell == 0) {
		cout << "你大叫一声：「";
		color(12);
		cout << "死鬼子！每年的今天，就是你的忌日！";
		color(16);
		cout << "」" << endl;
	} else if (yell == 1) {
		cout << "你大喝一声：「";
		color(12);
		cout << "今天不是你死，就是我活！";
		color(16);
		cout << "」" << endl;
	} else if (yell == 2) {
		cout << "你大叫一声：「";
		color(12);
		cout << "小子！你的坟墓就定在着了！";
		color(16);
		cout << "」" << endl;
	}
	color(12);
	for (int i = 0; i < peoplenum; i++) {
		cout << people[i].name << "看起来想要杀死你！" << endl;
	}
	color(16);
	int cooldown[100];
	int hcooldown[100];
	userInfo.experience += rand() % 3;
	userInfo.potential += rand() % 6;
	for (int i = 0; i < 100; i++) {
		cooldown[i] = 0;
		hcooldown[i] = 0;
	}
	while (1) {
		for (int i = 0; i < peoplenum; i++) {
			if (!die[i]) {
				cout << people[i].Englishname << "[" << people[i].health << "/" <<
					people[i].maxhealth << "]" << endl;
			}
		}
		cout << "请输入攻击者：";
		string who;
		cin >> who;
		int attackwho = 0;
		for (int i = 0; i < peoplenum; i++) {
			if (!die[i]) {
				attackwho = i;
				break;
			}
		}
		for (int i = 0; i < peoplenum; i++) {
			if (people[i].Englishname == who && !die[i]) {
				attackwho = i;
				break;
			}
		}
		cout << "-1,普攻 技能：名字<冷却>[内力使用]" << endl;
		for (int i = 0; i < 100; i++) {
			if ((nweapon.type == myskill[i].weapon || myskill[i].weapon == "无")
				&& myskill[i].isattack == true) {
				cout << i << "," << myskill[i].name << "<" << cooldown[i] << ">[" <<
					myskill[i].forceneed << "]  ";
			}
		}
		int which;
		cin >> which;
		if (which == -1) {
			for (int i = 0; i < GeneralAttack[nweapon.type].size(); i++) {
				if (GeneralAttack[nweapon.type][i] == 'a') {
					cout << "你";
				} else if (GeneralAttack[nweapon.type][i] == 'x') {
					color(nweapon.lv);
					cout << nweapon.name;
					color(16);
				} else if (GeneralAttack[nweapon.type][i] == 'b') {
					cout << people[attackwho].name;
				} else {
					cout << GeneralAttack[nweapon.type][i];
				}
			}
			cout << endl << endl;
			if (rand() % 10000 < people[attackwho].dodge - hit) {
				cout << people[attackwho].name << "轻轻一跳，躲过了着一招" << endl;
			} else {
				int ran = rand() % 40 - 20;
				if (nweapon.type == "拳") {
					if (damage + ran - people[attackwho].defense < 0) {
						cout << "你在对方身上照成了一块於，造成0点伤害！" << endl;
					} else {
						cout << "你在对方身上照成了一块於，造成" << damage + ran -
							people[attackwho].defense << "点伤害！" << endl;
						people[attackwho].health -= damage + ran - people[attackwho].defense;
						inroom.people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
						room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
					}
				} else {
					if (damage + ran - people[attackwho].defense < 0) {
						cout << "你手中";
						color(nweapon.lv);
						cout << nweapon.name;
						color(16);
						cout << "击中对方手部，造成0点伤害！" << endl;
					} else {
						cout << "你手中";
						color(nweapon.lv);
						cout << nweapon.name;
						color(16);
						cout << "击中对方手部，造成" << damage + ran - people[attackwho].defense <<
							"点伤害！" << endl;
						people[attackwho].health -= damage + ran - people[attackwho].defense;
						inroom.people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
						room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
					}
				}
				if (people[attackwho].health > people[attackwho].maxhealth / 6 * 5) {
					cout << "(";
					color(10);
					cout << people[attackwho].name << "看起来一点也不累，充满了活力";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 4) {
					cout << "(";
					color(14);
					cout << people[attackwho].name << "看上去受了一点小伤，但并不碍事";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 3) {
					cout << "(";
					color(14);
					cout << people[attackwho].name << "气喘吁吁，有点累了";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 2) {
					cout << "(";
					color(12);
					cout << people[attackwho].name << "摇头晃脑，但还能支撑一会";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6) {
					cout << "(";
					color(12);
					cout << people[attackwho].name << "已经力不从心，随时都可能倒下";
					color(16);
					cout << ")" << endl;
				} else {
					cout << "(";
					color(4);
					cout << people[attackwho].name << "已如风中残烛，生命危在旦夕";
					color(16);
					cout << ")" << endl;
				}
				if (people[attackwho].health <= 0) {
					cout << people[attackwho].name << "大叫一声，倒在地上，死了！" << endl;
					killnum++;
					make_corpse(people[attackwho], people[attackwho].weapon);
					for (int i = 0; i < 100; i++) {
						if (inroom.weapon[i].name == "") {
							inroom.weapon[i] = people[attackwho].dropweapon;
							room[nowroomi].weapon[i] = people[attackwho].dropweapon;
							break;
						}
					}
					for (int i = 0; i < 100; i++) {
						if (inroom.thing[i].name == "") {
							inroom.thing[i] = people[attackwho].dropthing;
							room[nowroomi].thing[i] = people[attackwho].dropthing;
							break;
						}
					}
					for (int i = 0; i < 100; i++) {
						if (inroom.book[i].name == "") {
							inroom.book[i] = people[attackwho].dropbook;
							room[nowroomi].book[i] = people[attackwho].dropbook;
							break;
						}
					}
					die[attackwho] = true;
					lastpeople--;
					if (lastpeople == 0) {
						for (int i = 0; i < peoplenum; i++) {
							room[nowroomi].people[peoplei[i]].canmove = cm[i];
							inroom.people[peoplei[i]].canmove = cm[i];
						}
						return 0;
					}
				}
			}
		} else if (cooldown[which] == 0 && myskill[which].weapon == nweapon.type
			&& myskill[which].forceneed <= force) {
			force -= myskill[which].forceneed;
			cooldown[which] = myskill[which].cooldown;
			for (int i = 0; i < myskill[which].use.size(); i++) {
				if (myskill[which].use[i] == 'w') {
					color(nweapon.lv);
					cout << nweapon.name;
					color(16);
				} else if (myskill[which].use[i] == 'e') {
					cout << people[attackwho].name;
				} else if (myskill[which].use[i] == 'q') {
					color(people[attackwho].weapon.lv);
					cout << people[attackwho].weapon.name;
					color(16);
				} else if (myskill[which].use[i] == '1') {
					color(1);
				} else if (myskill[which].use[i] == '2') {
					color(2);
				} else if (myskill[which].use[i] == '3') {
					color(3);
				} else if (myskill[which].use[i] == '4') {
					color(4);
				} else if (myskill[which].use[i] == '5') {
					color(5);
				} else if (myskill[which].use[i] == '6') {
					color(6);
				} else if (myskill[which].use[i] == '7') {
					color(7);
				} else if (myskill[which].use[i] == '8') {
					color(8);
				} else if (myskill[which].use[i] == '9') {
					color(9);
				} else if (myskill[which].use[i] == 's') {
					color(16);
				} else {
					cout << myskill[which].use[i];
				}
			}
			cout << endl;
			cout << "使用了";
			color(1);
			cout << myskill[which].forceneed;
			color(16);
			cout << "点内力，剩余";
			color(6);
			cout << force;
			color(16);
			cout << "点";
			cout << endl;
			for (int i = 0; i < myskill[which].attacknum; i++) {
				if (rand() % 10000 < people[attackwho].dodge - hit) {
					cout << "对方轻轻一跳，躲过了着一招" << endl;
				} else {
					int ran = rand() % 40 - 20;
					if (nweapon.type == "拳") {
						if (myskill[which].damage + ran - people[attackwho].defense < 0) {
							cout << "你在对方身上照成了一块於，造成0点伤害！" << endl;
						} else {
							cout << "你在对方身上照成了一块於，造成" << myskill[which].damage + ran -
								people[attackwho].defense << "点伤害！" << endl;
							people[attackwho].health -= myskill[which].damage + ran -
								people[attackwho].defense;
							inroom.people[peoplei[attackwho]].health -= damage + ran -
								people[attackwho].defense;
							room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
								people[attackwho].defense;
						}
					} else {
						if (myskill[which].damage + ran - people[attackwho].defense < 0) {
							cout << "你手中";
							color(nweapon.lv);
							cout << nweapon.name;
							color(16);
							cout << "击中对方手部，造成0点伤害！" << endl;
						} else {
							cout << "你手中";
							color(nweapon.lv);
							cout << nweapon.name;
							color(16);
							cout << "击中对方手部，造成" << myskill[which].damage + ran -
								people[attackwho].defense << "点伤害！" << endl;
							people[attackwho].health -= myskill[which].damage + ran -
								people[attackwho].defense;
							inroom.people[peoplei[attackwho]].health -= damage + ran -
								people[attackwho].defense;
							room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
								people[attackwho].defense;
						}
					}
					if (people[attackwho].health > people[attackwho].maxhealth / 6 * 5) {
						cout << "(";
						color(10);
						cout << people[attackwho].name << "看起来一点也不累，充满了活力";
						color(16);
						cout << ")" << endl;
					} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 4) {
						cout << "(";
						color(14);
						cout << people[attackwho].name << "看上去受了一点小伤，但并不碍事";
						color(16);
						cout << ")" << endl;
					} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 3) {
						cout << "(";
						color(14);
						cout << people[attackwho].name << "气喘吁吁，有点累了";
						color(16);
						cout << ")" << endl;
					} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 2) {
						cout << "(";
						color(12);
						cout << people[attackwho].name << "摇头晃脑，但还能支撑一会";
						color(16);
						cout << ")" << endl;
					} else if (people[attackwho].health > people[attackwho].maxhealth / 6) {
						cout << "(";
						color(12);
						cout << people[attackwho].name << "已经力不从心，随时都可能倒下";
						color(16);
						cout << ")" << endl;
					} else {
						cout << "(";
						color(4);
						cout << people[attackwho].name << "已如风中残烛，生命危在旦夕";
						color(16);
						cout << ")" << endl;
					}
					if (people[attackwho].health <= 0) {
						cout << people[attackwho].name << "大叫一声，倒在地上，死了！" << endl;
						make_corpse(people[attackwho], people[attackwho].weapon);
						killnum++;
						for (int i = 0; i < 100; i++) {
							if (inroom.weapon[i].name == "") {
								inroom.weapon[i] = people[attackwho].dropweapon;
								room[nowroomi].weapon[i] = people[attackwho].dropweapon;
								break;
							}
						}
						for (int i = 0; i < 100; i++) {
							if (inroom.thing[i].name == "") {
								inroom.thing[i] = people[attackwho].dropthing;
								room[nowroomi].thing[i] = people[attackwho].dropthing;
								break;
							}
						}
						for (int i = 0; i < 100; i++) {
							if (inroom.book[i].name == "") {
								inroom.book[i] = people[attackwho].dropbook;
								room[nowroomi].book[i] = people[attackwho].dropbook;
								break;
							}
						}
						die[attackwho] = true;
						lastpeople--;
						if (lastpeople == 0) {
							for (int i = 0; i < peoplenum; i++) {
								room[nowroomi].people[peoplei[i]].canmove = cm[i];
								inroom.people[peoplei[i]].canmove = cm[i];
							}
							return 0;
						}
						break;
					}
				}
			}
		} else {
			for (int i = 0; i < GeneralAttack[nweapon.type].size(); i++) {
				if (GeneralAttack[nweapon.type][i] == 'a') {
					cout << "你";
				} else if (GeneralAttack[nweapon.type][i] == 'x') {
					color(nweapon.lv);
					cout << nweapon.name;
					color(16);
				} else if (GeneralAttack[nweapon.type][i] == 'b') {
					cout << people[attackwho].name;
				} else {
					cout << GeneralAttack[nweapon.type][i];
				}
			}
			cout << endl << endl;
			if (rand() % 10000 < people[attackwho].dodge - hit) {
				cout << people[attackwho].name << "轻轻一跳，躲过了着一招" << endl;
			} else {
				int ran = rand() % 40 - 20;
				if (nweapon.type == "拳") {
					if (damage + ran - people[attackwho].defense < 0) {
						cout << "你在对方身上照成了一块於，造成0点伤害！" << endl;
					} else {
						cout << "你在对方身上照成了一块於，造成" << damage + ran -
							people[attackwho].defense << "点伤害！" << endl;
						people[attackwho].health -= damage + ran - people[attackwho].defense;
						inroom.people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
						room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
					}
				} else {
					if (damage + ran - people[attackwho].defense < 0) {
						cout << "你手中";
						color(nweapon.lv);
						cout << nweapon.name;
						color(16);
						cout << "击中对方手部，造成0点伤害！" << endl;
					} else {
						cout << "你手中";
						color(nweapon.lv);
						cout << nweapon.name;
						color(16);
						cout << "击中对方手部，造成" << damage + ran - people[attackwho].defense <<
							"点伤害！" << endl;
						people[attackwho].health -= damage + ran - people[attackwho].defense;
						inroom.people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
						room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
					}
				}
				if (people[attackwho].health > people[attackwho].maxhealth / 6 * 5) {
					cout << "(";
					color(10);
					cout << people[attackwho].name << "看起来一点也不累，充满了活力";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 4) {
					cout << "(";
					color(14);
					cout << people[attackwho].name << "看上去受了一点小伤，但并不碍事";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 3) {
					cout << "(";
					color(14);
					cout << people[attackwho].name << "气喘吁吁，有点累了";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 2) {
					cout << "(";
					color(12);
					cout << people[attackwho].name << "摇头晃脑，但还能支撑一会";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6) {
					cout << "(";
					color(12);
					cout << people[attackwho].name << "已经力不从心，随时都可能倒下";
					color(16);
					cout << ")" << endl;
				} else {
					cout << "(";
					color(4);
					cout << people[attackwho].name << "已如风中残烛，生命危在旦夕";
					color(16);
					cout << ")" << endl;
				}
				if (people[attackwho].health <= 0) {
					cout << people[attackwho].name << "大叫一声，倒在地上，死了！" << endl;
					make_corpse(people[attackwho], people[attackwho].weapon);
					killnum++;
					for (int i = 0; i < 100; i++) {
						if (inroom.weapon[i].name == "") {
							inroom.weapon[i] = people[attackwho].dropweapon;
							room[nowroomi].weapon[i] = people[attackwho].dropweapon;
							break;
						}
					}
					for (int i = 0; i < 100; i++) {
						if (inroom.thing[i].name == "") {
							inroom.thing[i] = people[attackwho].dropthing;
							room[nowroomi].thing[i] = people[attackwho].dropthing;
							break;
						}
					}
					for (int i = 0; i < 100; i++) {
						if (inroom.book[i].name == "") {
							inroom.book[i] = people[attackwho].dropbook;
							room[nowroomi].book[i] = people[attackwho].dropbook;
							break;
						}
					}
					die[attackwho] = true;
					lastpeople--;
					if (lastpeople == 0) {
						for (int i = 0; i < peoplenum; i++) {
							room[nowroomi].people[peoplei[i]].canmove = cm[i];
							inroom.people[peoplei[i]].canmove = cm[i];
						}
						return 0;
					}
				}
			}
		}
		bool canuse = false;
		int i;
		for (i = 0; i < people[attackwho].skillsnum; i++) {
			if (hcooldown[i] == 0) {
				canuse = true;
				break;
			}
		}
		cout << endl;
		for (int x = 0; x < peoplenum; x++) {
			if (!die[x]) {
				if (canuse) {
					hcooldown[i] = people[x].skills[i].cooldown;
					for (int j = 0; j < people[x].skills[i].use.size(); j++) {
						if (people[x].skills[i].use[j] == 'w') {
							color(nweapon.lv);
							cout << nweapon.name;
							color(16);
						} else if (people[x].skills[i].use[j] == 'e') {
							cout << people[x].name;
						} else if (people[x].skills[i].use[j] == 'q') {
							color(people[x].weapon.lv);
							cout << people[x].weapon.name;
							color(16);
						} else if (people[x].skills[i].use[j] == '1') {
							color(1);
						} else if (people[x].skills[i].use[j] == '2') {
							color(2);
						} else if (people[x].skills[i].use[j] == '3') {
							color(3);
						} else if (people[x].skills[i].use[j] == '4') {
							color(4);
						} else if (people[x].skills[i].use[j] == '5') {
							color(5);
						} else if (people[x].skills[i].use[j] == '6') {
							color(6);
						} else if (people[x].skills[i].use[j] == '7') {
							color(7);
						} else if (people[x].skills[i].use[j] == '8') {
							color(8);
						} else if (people[x].skills[i].use[j] == '9') {
							color(9);
						} else if (people[x].skills[i].use[j] == 's') {
							color(16);
						} else {
							cout << people[x].skills[i].use[j];
						}
					}
					cout << endl;
					for (int j = 0; j < people[x].skills[i].attacknum; j++) {
						if (rand() % 10000 < dodge - people[x].hit) {
							if (nowdodgeskill.name != "") {
								for (int k = 0; k < nowdodgeskill.use.size(); k++) {
									if (nowdodgeskill.use[k] == 'w') {
										color(nweapon.lv);
										cout << nweapon.name;
										color(16);
									} else if (nowdodgeskill.use[k] == 'e') {
										cout << people[x].name;
									} else if (nowdodgeskill.use[k] == 'q') {
										color(people[x].weapon.lv);
										cout << people[x].weapon.name;
										color(16);
									} else if (nowdodgeskill.use[k] == '1') {
										color(1);
									} else if (nowdodgeskill.use[k] == '2') {
										color(2);
									} else if (nowdodgeskill.use[k] == '3') {
										color(3);
									} else if (nowdodgeskill.use[k] == '4') {
										color(4);
									} else if (nowdodgeskill.use[k] == '5') {
										color(5);
									} else if (nowdodgeskill.use[k] == '6') {
										color(6);
									} else if (nowdodgeskill.use[k] == '7') {
										color(7);
									} else if (nowdodgeskill.use[k] == '8') {
										color(8);
									} else if (nowdodgeskill.use[k] == '9') {
										color(9);
									} else if (nowdodgeskill.use[k] == 's') {
										color(16);
									} else {
										cout << nowdodgeskill.use[k];
									}
								}
								cout << endl;
							} else {
								cout << " 你轻轻一跳，躲过了着一招" << endl;
							}
						} else {
							int ran = rand() % 40 - 20;
							if (people[x].weapon.type == "拳") {
								if (people[x].skills[i].damage + ran - defense < 0) {
									cout << people[x].name << "在你身上照成了一块於，造成0点伤害！" << endl;
								} else {
									cout << people[x].name << "在你身上照成了一块於，造成" <<
										people[x].skills[i].damage + ran - defense << "点伤害！" << endl;
									health -= people[x].skills[i].damage + ran - defense;
								}
							} else {
								if (people[x].skills[i].damage + ran - defense < 0) {
									cout << people[x].name << "手中";
									color(people[x].weapon.lv);
									cout << people[x].weapon.name;
									color(16);
									cout << "击中对方手部，造成0点伤害！" << endl;
								} else {
									cout << people[x].name << "手中";
									color(people[x].weapon.lv);
									cout << people[x].weapon.name;
									color(16);
									cout << "击中对方手部，造成" << people[x].skills[i].damage + ran - defense <<
										"点伤害！" << endl;
									health -= people[x].skills[i].damage + ran - defense;
								}
							}
							if (health > maxhealth / 6 * 5) {
								cout << "(";
								color(10);
								cout << "你看起来一点也不累，充满了活力";
								color(16);
								cout << ")" << endl;
							} else if (health > maxhealth / 6 * 4) {
								cout << "(";
								color(14);
								cout << "你看上去受了一点小伤，但并不碍事";
								color(16);
								cout << ")" << endl;
							} else if (health > maxhealth / 6 * 3) {
								cout << "(";
								color(14);
								cout << "你气喘吁吁，有点累了";
								color(16);
								cout << ")" << endl;
							} else if (health > maxhealth / 6 * 2) {
								cout << "(";
								color(12);
								cout << "你摇头晃脑，但还能支撑一会";
								color(16);
								cout << ")" << endl;
							} else if (health > maxhealth / 6) {
								cout << "(";
								color(12);
								cout << "你已经力不从心，随时都可能倒下";
								color(16);
								cout << ")" << endl;
							} else {
								cout << "(";
								color(4);
								cout << "你已如风中残烛，生命危在旦夕";
								color(16);
								cout << ")" << endl;
							}
							if (health <= 0) {
								cout << "你大叫一声，倒在地上，死了！" << endl;
								make_corpse(me, nweapon);
								for (int i = 0; i < peoplenum; i++) {
									room[nowroomi].people[peoplei[i]].canmove = cm[i];
									inroom.people[peoplei[i]].canmove = cm[i];
								}
								return 1;
							} else if (isrebound) {
								int att = people[x].skills[i].damage * reboundnum / 1000 + ran -
									people[x].defense;
								if (att < 0) {
									att = 0;
								}
								cout << "你抽出";
								color(nweapon.lv);
								cout << nweapon.name;
								color(16);
								cout << "一挡，对方手中";
								color(people[x].weapon.lv);
								cout << people[x].weapon.name;
								color(16);
								cout << "往后一弹，把伤害打到了自己身上，造成" << att << "点伤害！" << endl;
								people[x].health -= att;
								inroom.people[peoplei[x]].health -= att;
								room[nowroomi].people[peoplei[x]].health -= att;
								if (people[x].health > people[x].maxhealth / 6 * 5) {
									cout << "(";
									color(10);
									cout << people[x].name << "看起来一点也不累，充满了活力";
									color(16);
									cout << ")" << endl;
								} else if (people[x].health > people[x].maxhealth / 6 * 4) {
									cout << "(";
									color(14);
									cout << people[x].name << "看上去受了一点小伤，但并不碍事";
									color(16);
									cout << ")" << endl;
								} else if (people[x].health > people[x].maxhealth / 6 * 3) {
									cout << "(";
									color(14);
									cout << people[x].name << "气喘吁吁，有点累了";
									color(16);
									cout << ")" << endl;
								} else if (people[x].health > people[x].maxhealth / 6 * 2) {
									cout << "(";
									color(12);
									cout << people[x].name << "摇头晃脑，但还能支撑一会";
									color(16);
									cout << ")" << endl;
								} else if (people[x].health > people[x].maxhealth / 6) {
									cout << "(";
									color(12);
									cout << people[x].name << "已经力不从心，随时都可能倒下";
									color(16);
									cout << ")" << endl;
								} else {
									cout << "(";
									color(4);
									cout << people[x].name << "已如风中残烛，生命危在旦夕";
									color(16);
									cout << ")" << endl;
								}
								if (people[x].health <= 0) {
									cout << people[x].name << "大叫一声，倒在地上，死了！" << endl;
									killnum++;
									make_corpse(people[x], people[x].weapon);
									for (int i = 0; i < 100; i++) {
										if (inroom.weapon[i].name == "") {
											inroom.weapon[i] = people[x].dropweapon;
											room[nowroomi].weapon[i] = people[x].dropweapon;
											break;
										}
									}
									for (int i = 0; i < 100; i++) {
										if (inroom.thing[i].name == "") {
											inroom.thing[i] = people[x].dropthing;
											room[nowroomi].thing[i] = people[x].dropthing;
											break;
										}
									}
									for (int i = 0; i < 100; i++) {
										if (inroom.book[i].name == "") {
											inroom.book[i] = people[x].dropbook;
											room[nowroomi].book[i] = people[x].dropbook;
											break;
										}
									}
									die[x] = true;
									lastpeople--;
									if (lastpeople == 0) {
										for (int i = 0; i < peoplenum; i++) {
											room[nowroomi].people[peoplei[i]].canmove = cm[i];
											inroom.people[peoplei[i]].canmove = cm[i];
										}
										return 0;
									}
								}
							}
						}
					}
				} else {
					for (int j = 0; j < GeneralAttack[people[x].weapon.type].size(); j++) {
						if (GeneralAttack[people[x].weapon.type][j] == 'a') {
							cout << people[x].name;
						} else if (GeneralAttack[people[x].weapon.type][j] == 'x') {
							color(people[x].weapon.lv);
							cout << people[x].weapon.name;
							color(16);
						} else if (GeneralAttack[people[x].weapon.type][j] == 'b') {
							cout << "你";
						} else {
							cout << GeneralAttack[people[x].weapon.type][j];
						}
					}
					cout << endl << endl;
					if (rand() % 10000 < dodge - people[x].hit) {
						if (nowdodgeskill.name != "") {
							for (int k = 0; k < nowdodgeskill.use.size(); k++) {
								if (nowdodgeskill.use[k] == 'w') {
									color(nweapon.lv);
									cout << nweapon.name;
									color(16);
								} else if (nowdodgeskill.use[k] == 'e') {
									cout << people[x].name;
								} else if (nowdodgeskill.use[k] == 'q') {
									color(people[x].weapon.lv);
									cout << people[x].weapon.name;
									color(16);
								} else if (nowdodgeskill.use[k] == '1') {
									color(1);
								} else if (nowdodgeskill.use[k] == '2') {
									color(2);
								} else if (nowdodgeskill.use[k] == '3') {
									color(3);
								} else if (nowdodgeskill.use[k] == '4') {
									color(4);
								} else if (nowdodgeskill.use[k] == '5') {
									color(5);
								} else if (nowdodgeskill.use[k] == '6') {
									color(6);
								} else if (nowdodgeskill.use[k] == '7') {
									color(7);
								} else if (nowdodgeskill.use[k] == '8') {
									color(8);
								} else if (nowdodgeskill.use[k] == '9') {
									color(9);
								} else if (nowdodgeskill.use[k] == 's') {
									color(16);
								} else {
									cout << nowdodgeskill.use[k];
								}
							}
							cout << endl;
						} else {
							cout << " 你轻轻一跳，躲过了着一招" << endl;
						}
					} else {
						int ran = rand() % 40 - 20;
						if (people[x].weapon.type == "拳") {
							if (people[x].damage + ran - defense < 0) {
								cout << people[x].name << "在你身上照成了一块於，造成0点伤害！" << endl;
							} else {
								cout << people[x].name << "在你身上照成了一块於，造成" << people[x].damage + ran
									- defense << "点伤害！" << endl;
								health -= people[x].damage + ran - defense;
							}
						} else {
							if (people[x].damage + ran - defense < 0) {
								cout << people[x].name << "手中";
								color(people[x].weapon.lv);
								cout << people[x].weapon.name;
								color(16);
								cout << "击中对方手部，造成0点伤害！" << endl;
							} else {
								cout << people[x].name << "手中";
								color(people[x].weapon.lv);
								cout << people[x].weapon.name;
								color(16);
								cout << "击中对方手部，造成" << people[x].damage + ran - defense << "点伤害！"
									<< endl;
								health -= people[x].damage + ran - defense;
							}
						}
						if (health > maxhealth / 6 * 5) {
							cout << "(";
							color(10);
							cout << "你看起来一点也不累，充满了活力";
							color(16);
							cout << ")" << endl;
						} else if (health > maxhealth / 6 * 4) {
							cout << "(";
							color(14);
							cout << "你看上去受了一点小伤，但并不碍事";
							color(16);
							cout << ")" << endl;
						} else if (health > maxhealth / 6 * 3) {
							cout << "(";
							color(14);
							cout << "你气喘吁吁，有点累了";
							color(16);
							cout << ")" << endl;
						} else if (health > maxhealth / 6 * 2) {
							cout << "(";
							color(12);
							cout << "你摇头晃脑，但还能支撑一会";
							color(16);
							cout << ")" << endl;
						} else if (health > maxhealth / 6) {
							cout << "(";
							color(12);
							cout << "你已经力不从心，随时都可能倒下";
							color(16);
							cout << ")" << endl;
						} else {
							cout << "(";
							color(4);
							cout << "你已如风中残烛，生命危在旦夕";
							color(16);
							cout << ")" << endl;
						}
						if (health <= 0) {
							cout << "你大叫一声，倒在地上，死了！" << endl;
							make_corpse(me, nweapon);
							for (int i = 0; i < peoplenum; i++) {
								room[nowroomi].people[peoplei[i]].canmove = cm[i];
								inroom.people[peoplei[i]].canmove = cm[i];
							}
							return 1;
						} else if (isrebound) {
							int att = people[x].damage * reboundnum / 1000 + ran - people[x].defense;
							if (att < 0) {
								att = 0;
							}
							cout << "你抽出";
							color(nweapon.lv);
							cout << nweapon.name;
							color(16);
							cout << "一挡，对方手中";
							color(people[x].weapon.lv);
							cout << people[x].weapon.name;
							color(16);
							cout << "往后一弹，把伤害打到了自己身上，造成" << att << "点伤害！" << endl;
							people[x].health -= att;
							inroom.people[peoplei[x]].health -= att;
							room[nowroomi].people[peoplei[x]].health -= att;
							if (people[x].health > people[x].maxhealth / 6 * 5) {
								cout << "(";
								color(10);
								cout << people[x].name << "看起来一点也不累，充满了活力";
								color(16);
								cout << ")" << endl;
							} else if (people[x].health > people[x].maxhealth / 6 * 4) {
								cout << "(";
								color(14);
								cout << people[x].name << "看上去受了一点小伤，但并不碍事";
								color(16);
								cout << ")" << endl;
							} else if (people[x].health > people[x].maxhealth / 6 * 3) {
								cout << "(";
								color(14);
								cout << people[x].name << "气喘吁吁，有点累了";
								color(16);
								cout << ")" << endl;
							} else if (people[x].health > people[x].maxhealth / 6 * 2) {
								cout << "(";
								color(12);
								cout << people[x].name << "摇头晃脑，但还能支撑一会";
								color(16);
								cout << ")" << endl;
							} else if (people[x].health > people[x].maxhealth / 6) {
								cout << "(";
								color(12);
								cout << people[x].name << "已经力不从心，随时都可能倒下";
								color(16);
								cout << ")" << endl;
							} else {
								cout << "(";
								color(4);
								cout << people[x].name << "已如风中残烛，生命危在旦夕";
								color(16);
								cout << ")" << endl;
							}
							if (people[x].health <= 0) {
								cout << people[x].name << "大叫一声，倒在地上，死了！" << endl;
								killnum++;
								make_corpse(people[x], people[x].weapon);
								for (int i = 0; i < 100; i++) {
									if (inroom.weapon[i].name == "") {
										inroom.weapon[i] = people[x].dropweapon;
										room[nowroomi].weapon[i] = people[x].dropweapon;
										break;
									}
								}
								for (int i = 0; i < 100; i++) {
									if (inroom.thing[i].name == "") {
										inroom.thing[i] = people[x].dropthing;
										room[nowroomi].thing[i] = people[x].dropthing;
										break;
									}
								}
								for (int i = 0; i < 100; i++) {
									if (inroom.book[i].name == "") {
										inroom.book[i] = people[x].dropbook;
										room[nowroomi].book[i] = people[x].dropbook;
										break;
									}
								}
								die[x] = true;
								lastpeople--;
								if (lastpeople == 0) {
									for (int i = 0; i < peoplenum; i++) {
										room[nowroomi].people[peoplei[i]].canmove = cm[i];
										inroom.people[peoplei[i]].canmove = cm[i];
									}
									return 0;
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			if (cooldown[i] != 0) {
				cooldown[i] -= 1;
			}
			if (hcooldown[i] != 0) {
				hcooldown[i] -= 1;
			}
		}
	}
	return 0;
}
int fightall(pe people[100], int peoplenum, int peoplei[100]) {
	bool cm[100];
	for (int i = 0; i < peoplenum; i++) {
		cm[i] = userInfo.inroom.people[peoplei[i]].canmove;
		room[userInfo.nowroomi].people[peoplei[i]].canmove = false;
		userInfo.inroom.people[peoplei[i]].canmove = false;
	}
	int yell = rand() % 3;
	int lastpeople = peoplenum;
	bool die[100];
	for (int i = 0; i < 100; i++) {
		die[i] = false;
	}
	cout << "你说：「";
	color(12);
	cout << "在下" << userInfo.myname << "，敢问大侠是否愿意跟我比试一下？";
	color(16);
	cout << "」" << endl;
	int cooldown[100];
	int hcooldown[100];
	experience += rand() % 3;
	potential += rand() % 6;
	for (int i = 0; i < 100; i++) {
		cooldown[i] = 0;
		hcooldown[i] = 0;
	}
	while (1) {
		for (int i = 0; i < peoplenum; i++) {
			if (!die[i]) {
				cout << people[i].Englishname << "[" << people[i].health << "/" <<
					people[i].maxhealth << "]" << endl;
			}
		}
		cout << "请输入攻击者：";
		string who;
		cin >> who;
		int attackwho;
		for (int i = 0; i < peoplenum; i++) {
			if (!die[i]) {
				attackwho = i;
				break;
			}
		}
		for (int i = 0; i < peoplenum; i++) {
			if (people[i].Englishname == who && !die[i]) {
				attackwho = i;
				break;
			}
		}
		cout << "-1,普攻 技能：名字<冷却>[内力使用]" << endl;
		for (int i = 0; i < 100; i++) {
			if ((nweapon.type == myskill[i].weapon || myskill[i].weapon == "无")
				&& myskill[i].isattack == true) {
				cout << i << "," << myskill[i].name << "<" << cooldown[i] << ">[" <<
					myskill[i].forceneed << "]  ";
			}
		}
		int which;
		cin >> which;
		if (which == -1) {
			for (int i = 0; i < GeneralAttack[nweapon.type].size(); i++) {
				if (GeneralAttack[nweapon.type][i] == 'a') {
					cout << "你";
				} else if (GeneralAttack[nweapon.type][i] == 'x') {
					color(nweapon.lv);
					cout << nweapon.name;
					color(16);
				} else if (GeneralAttack[nweapon.type][i] == 'b') {
					cout << people[attackwho].name;
				} else {
					cout << GeneralAttack[nweapon.type][i];
				}
			}
			cout << endl << endl;
			if (rand() % 10000 < people[attackwho].dodge - hit) {
				cout << people[attackwho].name << "轻轻一跳，躲过了着一招" << endl;
			} else {
				int ran = rand() % 40 - 20;
				if (nweapon.type == "拳") {
					if (damage + ran - people[attackwho].defense < 0) {
						cout << "你在对方身上照成了一块於，造成0点伤害！" << endl;
					} else {
						cout << "你在对方身上照成了一块於，造成" << damage + ran -
							people[attackwho].defense << "点伤害！" << endl;
						people[attackwho].health -= damage + ran - people[attackwho].defense;
						inroom.people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
						room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
					}
				} else {
					if (damage + ran - people[attackwho].defense < 0) {
						cout << "你手中";
						color(nweapon.lv);
						cout << nweapon.name;
						color(16);
						cout << "击中对方手部，造成0点伤害！" << endl;
					} else {
						cout << "你手中";
						color(nweapon.lv);
						cout << nweapon.name;
						color(16);
						cout << "击中对方手部，造成" << damage + ran - people[attackwho].defense <<
							"点伤害！" << endl;
						people[attackwho].health -= damage + ran - people[attackwho].defense;
						inroom.people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
						room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
					}
				}
				if (people[attackwho].health > people[attackwho].maxhealth / 6 * 5) {
					cout << "(";
					color(10);
					cout << people[attackwho].name << "看起来一点也不累，充满了活力";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 4) {
					cout << "(";
					color(14);
					cout << people[attackwho].name << "看上去受了一点小伤，但并不碍事";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 3) {
					cout << "(";
					color(14);
					cout << people[attackwho].name << "气喘吁吁，有点累了";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 2) {
					cout << "(";
					color(12);
					cout << people[attackwho].name << "摇头晃脑，但还能支撑一会";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6) {
					cout << "(";
					color(12);
					cout << people[attackwho].name << "已经力不从心，随时都可能倒下";
					color(16);
					cout << ")" << endl;
				} else {
					cout << "(";
					color(4);
					cout << people[attackwho].name << "已如风中残烛，生命危在旦夕";
					color(16);
					cout << ")" << endl;
				}
				if (people[attackwho].health <= 0) {
					cout << people[attackwho].name << "说：在下武艺实在不如大侠！" << endl;
					inroom.people[peoplei[attackwho]].health =
						inroom.people[peoplei[attackwho]].maxhealth / 2;
					room[nowroomi].people[peoplei[attackwho]].health =
						inroom.people[peoplei[attackwho]].health;
					lastpeople--;
					die[attackwho] = true;
					if (lastpeople == 0) {
						for (int i = 0; i < peoplenum; i++) {
							room[nowroomi].people[peoplei[i]].canmove = cm[i];
							inroom.people[peoplei[i]].canmove = cm[i];
						}
						return 0;
					}
				}
			}
		} else if (cooldown[which] == 0 && myskill[which].weapon == nweapon.type
			&& myskill[which].forceneed <= force) {
			force -= myskill[which].forceneed;
			cooldown[which] = myskill[which].cooldown;
			for (int i = 0; i < myskill[which].use.size(); i++) {
				if (myskill[which].use[i] == 'w') {
					color(nweapon.lv);
					cout << nweapon.name;
					color(16);
				} else if (myskill[which].use[i] == 'e') {
					cout << people[attackwho].name;
				} else if (myskill[which].use[i] == 'q') {
					color(people[attackwho].weapon.lv);
					cout << people[attackwho].weapon.name;
					color(16);
				} else if (myskill[which].use[i] == '1') {
					color(1);
				} else if (myskill[which].use[i] == '2') {
					color(2);
				} else if (myskill[which].use[i] == '3') {
					color(3);
				} else if (myskill[which].use[i] == '4') {
					color(4);
				} else if (myskill[which].use[i] == '5') {
					color(5);
				} else if (myskill[which].use[i] == '6') {
					color(6);
				} else if (myskill[which].use[i] == '7') {
					color(7);
				} else if (myskill[which].use[i] == '8') {
					color(8);
				} else if (myskill[which].use[i] == '9') {
					color(9);
				} else if (myskill[which].use[i] == 's') {
					color(16);
				} else {
					cout << myskill[which].use[i];
				}
			}
			cout << endl;
			cout << "使用了";
			color(1);
			cout << myskill[which].forceneed;
			color(16);
			cout << "点内力，剩余";
			color(6);
			cout << force;
			color(16);
			cout << "点";
			cout << endl;
			for (int i = 0; i < myskill[which].attacknum; i++) {
				if (rand() % 10000 < people[attackwho].dodge - hit) {
					cout << "对方轻轻一跳，躲过了着一招" << endl;
				} else {
					int ran = rand() % 40 - 20;
					if (nweapon.type == "拳") {
						if (myskill[which].damage + ran - people[attackwho].defense < 0) {
							cout << "你在对方身上照成了一块於，造成0点伤害！" << endl;
						} else {
							cout << "你在对方身上照成了一块於，造成" << myskill[which].damage + ran -
								people[attackwho].defense << "点伤害！" << endl;
							people[attackwho].health -= myskill[which].damage + ran -
								people[attackwho].defense;
							inroom.people[peoplei[attackwho]].health -= damage + ran -
								people[attackwho].defense;
							room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
								people[attackwho].defense;
						}
					} else {
						if (myskill[which].damage + ran - people[attackwho].defense < 0) {
							cout << "你手中";
							color(nweapon.lv);
							cout << nweapon.name;
							color(16);
							cout << "击中对方手部，造成0点伤害！" << endl;
						} else {
							cout << "你手中";
							color(nweapon.lv);
							cout << nweapon.name;
							color(16);
							cout << nweapon.name << "击中对方手部，造成" << myskill[which].damage + ran -
								people[attackwho].defense << "点伤害！" << endl;
							people[attackwho].health -= myskill[which].damage + ran -
								people[attackwho].defense;
							inroom.people[peoplei[attackwho]].health -= damage + ran -
								people[attackwho].defense;
							room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
								people[attackwho].defense;
						}
					}
					if (people[attackwho].health > people[attackwho].maxhealth / 6 * 5) {
						cout << "(";
						color(10);
						cout << people[attackwho].name << "看起来一点也不累，充满了活力";
						color(16);
						cout << ")" << endl;
					} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 4) {
						cout << "(";
						color(14);
						cout << people[attackwho].name << "看上去受了一点小伤，但并不碍事";
						color(16);
						cout << ")" << endl;
					} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 3) {
						cout << "(";
						color(14);
						cout << people[attackwho].name << "气喘吁吁，有点累了";
						color(16);
						cout << ")" << endl;
					} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 2) {
						cout << "(";
						color(12);
						cout << people[attackwho].name << "摇头晃脑，但还能支撑一会";
						color(16);
						cout << ")" << endl;
					} else if (people[attackwho].health > people[attackwho].maxhealth / 6) {
						cout << "(";
						color(12);
						cout << people[attackwho].name << "已经力不从心，随时都可能倒下";
						color(16);
						cout << ")" << endl;
					} else {
						cout << "(";
						color(4);
						cout << people[attackwho].name << "已如风中残烛，生命危在旦夕";
						color(16);
						cout << ")" << endl;
					}
					if (people[attackwho].health <= 0) {
						cout << people[attackwho].name << "说：在下武艺实在不如大侠！" << endl;
						inroom.people[peoplei[attackwho]].health =
							inroom.people[peoplei[attackwho]].maxhealth / 2;
						room[nowroomi].people[peoplei[attackwho]].health =
							inroom.people[peoplei[attackwho]].health;
						lastpeople--;
						die[attackwho] = true;
						if (lastpeople == 0) {
							for (int i = 0; i < peoplenum; i++) {
								room[nowroomi].people[peoplei[i]].canmove = cm[i];
								inroom.people[peoplei[i]].canmove = cm[i];
							}
							return 0;
						}
						break;
					}
				}
			}
		} else {
			for (int i = 0; i < GeneralAttack[nweapon.type].size(); i++) {
				if (GeneralAttack[nweapon.type][i] == 'a') {
					cout << "你";
				} else if (GeneralAttack[nweapon.type][i] == 'x') {
					color(nweapon.lv);
					cout << nweapon.name;
					color(16);
				} else if (GeneralAttack[nweapon.type][i] == 'b') {
					cout << people[attackwho].name;
				} else {
					cout << GeneralAttack[nweapon.type][i];
				}
			}
			cout << endl << endl;
			if (rand() % 10000 < people[attackwho].dodge - hit) {
				cout << people[attackwho].name << "轻轻一跳，躲过了着一招" << endl;
			} else {
				int ran = rand() % 40 - 20;
				if (nweapon.type == "拳") {
					if (damage + ran - people[attackwho].defense < 0) {
						cout << "你在对方身上照成了一块於，造成0点伤害！" << endl;
					} else {
						cout << "你在对方身上照成了一块於，造成" << damage + ran -
							people[attackwho].defense << "点伤害！" << endl;
						people[attackwho].health -= damage + ran - people[attackwho].defense;
						inroom.people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
						room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
					}
				} else {
					if (damage + ran - people[attackwho].defense < 0) {
						cout << "你手中";
						color(nweapon.lv);
						cout << nweapon.name;
						color(16);
						cout << "击中对方手部，造成0点伤害！" << endl;
					} else {
						cout << "你手中";
						color(nweapon.lv);
						cout << nweapon.name;
						color(16);
						cout << "击中对方手部，造成" << damage + ran - people[attackwho].defense <<
							"点伤害！" << endl;
						people[attackwho].health -= damage + ran - people[attackwho].defense;
						inroom.people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
						room[nowroomi].people[peoplei[attackwho]].health -= damage + ran -
							people[attackwho].defense;
					}
				}
				if (people[attackwho].health > people[attackwho].maxhealth / 6 * 5) {
					cout << "(";
					color(10);
					cout << people[attackwho].name << "看起来一点也不累，充满了活力";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 4) {
					cout << "(";
					color(14);
					cout << people[attackwho].name << "看上去受了一点小伤，但并不碍事";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 3) {
					cout << "(";
					color(14);
					cout << people[attackwho].name << "气喘吁吁，有点累了";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6 * 2) {
					cout << "(";
					color(12);
					cout << people[attackwho].name << "摇头晃脑，但还能支撑一会";
					color(16);
					cout << ")" << endl;
				} else if (people[attackwho].health > people[attackwho].maxhealth / 6) {
					cout << "(";
					color(12);
					cout << people[attackwho].name << "已经力不从心，随时都可能倒下";
					color(16);
					cout << ")" << endl;
				} else {
					cout << "(";
					color(4);
					cout << people[attackwho].name << "已如风中残烛，生命危在旦夕";
					color(16);
					cout << ")" << endl;
				}
				if (people[attackwho].health <= 0) {
					cout << people[attackwho].name << "说：在下武艺实在不如大侠！" << endl;
					inroom.people[peoplei[attackwho]].health =
						inroom.people[peoplei[attackwho]].maxhealth / 2;
					room[nowroomi].people[peoplei[attackwho]].health =
						inroom.people[peoplei[attackwho]].health;
					lastpeople--;
					die[attackwho] = true;
					if (lastpeople == 0) {
						for (int i = 0; i < peoplenum; i++) {
							room[nowroomi].people[peoplei[i]].canmove = cm[i];
							inroom.people[peoplei[i]].canmove = cm[i];
						}
						return 0;
					}
				}
			}
		}
		bool canuse = false;
		int i;
		for (i = 0; i < people[attackwho].skillsnum; i++) {
			if (hcooldown[i] == 0) {
				canuse = true;
				break;
			}
		}
		cout << endl;
		for (int x = 0; x < peoplenum; x++) {
			if (!die[x]) {
				if (canuse) {
					hcooldown[i] = people[x].skills[i].cooldown;
					for (int j = 0; j < people[x].skills[i].use.size(); j++) {
						if (people[x].skills[i].use[j] == 'w') {
							color(nweapon.lv);
							cout << nweapon.name;
							color(16);
						} else if (people[x].skills[i].use[j] == 'e') {
							cout << people[x].name;
						} else if (people[x].skills[i].use[j] == 'q') {
							color(people[x].weapon.lv);
							cout << people[x].weapon.name;
							color(16);
						} else if (people[x].skills[i].use[j] == '1') {
							color(1);
						} else if (people[x].skills[i].use[j] == '2') {
							color(2);
						} else if (people[x].skills[i].use[j] == '3') {
							color(3);
						} else if (people[x].skills[i].use[j] == '4') {
							color(4);
						} else if (people[x].skills[i].use[j] == '5') {
							color(5);
						} else if (people[x].skills[i].use[j] == '6') {
							color(6);
						} else if (people[x].skills[i].use[j] == '7') {
							color(7);
						} else if (people[x].skills[i].use[j] == '8') {
							color(8);
						} else if (people[x].skills[i].use[j] == '9') {
							color(9);
						} else if (people[x].skills[i].use[j] == 's') {
							color(16);
						} else {
							cout << people[x].skills[i].use[j];
						}
					}
					cout << endl;
					for (int j = 0; j < people[x].skills[i].attacknum; j++) {
						if (rand() % 10000 < dodge - people[x].hit) {
							if (nowdodgeskill.name != "") {
								for (int k = 0; k < nowdodgeskill.use.size(); k++) {
									if (nowdodgeskill.use[k] == 'w') {
										color(nweapon.lv);
										cout << nweapon.name;
										color(16);
									} else if (nowdodgeskill.use[k] == 'e') {
										cout << people[x].name;
									} else if (nowdodgeskill.use[k] == 'q') {
										color(people[x].weapon.lv);
										cout << people[x].weapon.name;
										color(16);
									} else if (nowdodgeskill.use[k] == '1') {
										color(1);
									} else if (nowdodgeskill.use[k] == '2') {
										color(2);
									} else if (nowdodgeskill.use[k] == '3') {
										color(3);
									} else if (nowdodgeskill.use[k] == '4') {
										color(4);
									} else if (nowdodgeskill.use[k] == '5') {
										color(5);
									} else if (nowdodgeskill.use[k] == '6') {
										color(6);
									} else if (nowdodgeskill.use[k] == '7') {
										color(7);
									} else if (nowdodgeskill.use[k] == '8') {
										color(8);
									} else if (nowdodgeskill.use[k] == '9') {
										color(9);
									} else if (nowdodgeskill.use[k] == 's') {
										color(16);
									} else {
										cout << nowdodgeskill.use[k];
									}
								}
								cout << endl;
							} else {
								cout << " 你轻轻一跳，躲过了着一招" << endl;
							}
						} else {
							int ran = rand() % 40 - 20;
							if (people[x].weapon.type == "拳") {
								if (people[x].skills[i].damage + ran - defense < 0) {
									cout << people[x].name << "在你身上照成了一块於，造成0点伤害！" << endl;
								} else {
									cout << people[x].name << "在你身上照成了一块於，造成" <<
										people[x].skills[i].damage + ran - defense << "点伤害！" << endl;
									health -= people[x].skills[i].damage + ran - defense;
								}
							} else {
								if (people[x].skills[i].damage + ran - defense < 0) {
									cout << people[x].name << "手中";
									color(people[x].weapon.lv);
									cout << people[x].weapon.name;
									color(16);
									cout << "击中对方手部，造成0点伤害！" << endl;
								} else {
									cout << people[x].name << "手中";
									color(people[x].weapon.lv);
									cout << people[x].weapon.name;
									color(16);
									cout << "击中对方手部，造成" << people[x].skills[i].damage + ran - defense <<
										"点伤害！" << endl;
									health -= people[x].skills[i].damage + ran - defense;
								}
							}
							if (health > maxhealth / 6 * 5) {
								cout << "(";
								color(10);
								cout << "你看起来一点也不累，充满了活力";
								color(16);
								cout << ")" << endl;
							} else if (health > maxhealth / 6 * 4) {
								cout << "(";
								color(14);
								cout << "你看上去受了一点小伤，但并不碍事";
								color(16);
								cout << ")" << endl;
							} else if (health > maxhealth / 6 * 3) {
								cout << "(";
								color(14);
								cout << "你气喘吁吁，有点累了";
								color(16);
								cout << ")" << endl;
							} else if (health > maxhealth / 6 * 2) {
								cout << "(";
								color(12);
								cout << "你摇头晃脑，但还能支撑一会";
								color(16);
								cout << ")" << endl;
							} else if (health > maxhealth / 6) {
								cout << "(";
								color(12);
								cout << "你已经力不从心，随时都可能倒下";
								color(16);
								cout << ")" << endl;
							} else {
								cout << "(";
								color(4);
								cout << "你已如风中残烛，生命危在旦夕";
								color(16);
								cout << ")" << endl;
							}
							if (health <= 0) {
								cout << "你说：在下实力实在不如大侠！" << endl;
								health = maxhealth / 2;
								for (int i = 0; i < peoplenum; i++) {
									room[nowroomi].people[peoplei[i]].canmove = cm[i];
									inroom.people[peoplei[i]].canmove = cm[i];
								}
								return 1;
							} else if (isrebound) {
								int att = people[x].skills[i].damage * reboundnum / 1000 + ran -
									people[x].defense;
								if (att < 0) {
									att = 0;
								}
								cout << "你抽出";
								color(nweapon.lv);
								cout << nweapon.name;
								color(16);
								cout << "一挡，对方手中";
								color(people[x].weapon.lv);
								cout << people[x].weapon.name;
								color(16);
								cout << "往后一弹，把伤害打到了自己身上，造成" << att << "点伤害！" << endl;
								people[x].health -= att;
								inroom.people[peoplei[x]].health -= att;
								room[nowroomi].people[peoplei[x]].health -= att;
								if (people[x].health > people[x].maxhealth / 6 * 5) {
									cout << "(";
									color(10);
									cout << people[x].name << "看起来一点也不累，充满了活力";
									color(16);
									cout << ")" << endl;
								} else if (people[x].health > people[x].maxhealth / 6 * 4) {
									cout << "(";
									color(14);
									cout << people[x].name << "看上去受了一点小伤，但并不碍事";
									color(16);
									cout << ")" << endl;
								} else if (people[x].health > people[x].maxhealth / 6 * 3) {
									cout << "(";
									color(14);
									cout << people[x].name << "气喘吁吁，有点累了";
									color(16);
									cout << ")" << endl;
								} else if (people[x].health > people[x].maxhealth / 6 * 2) {
									cout << "(";
									color(12);
									cout << people[x].name << "摇头晃脑，但还能支撑一会";
									color(16);
									cout << ")" << endl;
								} else if (people[x].health > people[x].maxhealth / 6) {
									cout << "(";
									color(12);
									cout << people[x].name << "已经力不从心，随时都可能倒下";
									color(16);
									cout << ")" << endl;
								} else {
									cout << "(";
									color(4);
									cout << people[x].name << "已如风中残烛，生命危在旦夕";
									color(16);
									cout << ")" << endl;
								}
								if (people[x].health <= 0) {
									cout << people[x].name << "说：在下实力实在不如大侠！" << endl;
									inroom.people[x].health = inroom.people[x].maxhealth;
									room[nowroomi].people[x] = inroom.people[x];
									die[x] = true;
									lastpeople--;
									if (lastpeople == 0) {
										for (int i = 0; i < peoplenum; i++) {
											room[nowroomi].people[peoplei[i]].canmove = cm[i];
											inroom.people[peoplei[i]].canmove = cm[i];
										}
										return 0;
									}
								}
							}
						}
					}
				} else {
					for (int j = 0; j < GeneralAttack[people[x].weapon.type].size(); j++) {
						if (GeneralAttack[people[x].weapon.type][j] == 'a') {
							cout << people[x].name;
						} else if (GeneralAttack[people[x].weapon.type][j] == 'x') {
							color(people[x].weapon.lv);
							cout << people[x].weapon.name;
							color(16);
						} else if (GeneralAttack[people[x].weapon.type][j] == 'b') {
							cout << "你";
						} else {
							cout << GeneralAttack[people[x].weapon.type][j];
						}
					}
					cout << endl << endl;
					if (rand() % 10000 < dodge - people[x].hit) {
						if (nowdodgeskill.name != "") {
							for (int k = 0; k < nowdodgeskill.use.size(); k++) {
								if (nowdodgeskill.use[k] == 'w') {
									color(nweapon.lv);
									cout << nweapon.name;
									color(16);
								} else if (nowdodgeskill.use[k] == 'e') {
									cout << people[x].name;
								} else if (nowdodgeskill.use[k] == 'q') {
									color(people[x].weapon.lv);
									cout << people[x].weapon.name;
									color(16);
								} else if (nowdodgeskill.use[k] == '1') {
									color(1);
								} else if (nowdodgeskill.use[k] == '2') {
									color(2);
								} else if (nowdodgeskill.use[k] == '3') {
									color(3);
								} else if (nowdodgeskill.use[k] == '4') {
									color(4);
								} else if (nowdodgeskill.use[k] == '5') {
									color(5);
								} else if (nowdodgeskill.use[k] == '6') {
									color(6);
								} else if (nowdodgeskill.use[k] == '7') {
									color(7);
								} else if (nowdodgeskill.use[k] == '8') {
									color(8);
								} else if (nowdodgeskill.use[k] == '9') {
									color(9);
								} else if (nowdodgeskill.use[k] == 's') {
									color(16);
								} else {
									cout << nowdodgeskill.use[k];
								}
							}
							cout << endl;
						} else {
							cout << " 你轻轻一跳，躲过了这一招" << endl;
						}
					} else {
						int ran = rand() % 40 - 20;
						if (people[x].weapon.type == "拳") {
							if (people[x].damage + ran - defense < 0) {
								cout << people[x].name << "在你身上照成了一块於，造成0点伤害！" << endl;
							} else {
								cout << people[x].name << "在你身上照成了一块於，造成" << people[x].damage + ran
									- defense << "点伤害！" << endl;
								health -= people[x].damage + ran - defense;
							}
						} else {
							if (people[x].damage + ran - defense < 0) {
								cout << people[x].name << "手中";
								color(people[x].weapon.lv);
								cout << people[x].weapon.name;
								color(16);
								cout << "击中对方手部，造成0点伤害！" << endl;
							} else {
								cout << people[x].name << "手中";
								color(people[x].weapon.lv);
								cout << people[x].weapon.name;
								color(16);
								cout << "击中对方手部，造成" << people[x].damage + ran - defense << "点伤害！"
									<< endl;
								health -= people[x].damage + ran - defense;
							}
						}
						if (health > maxhealth / 6 * 5) {
							cout << "(";
							color(10);
							cout << "你看起来一点也不累，充满了活力";
							color(16);
							cout << ")" << endl;
						} else if (health > maxhealth / 6 * 4) {
							cout << "(";
							color(14);
							cout << "你看上去受了一点小伤，但并不碍事";
							color(16);
							cout << ")" << endl;
						} else if (health > maxhealth / 6 * 3) {
							cout << "(";
							color(14);
							cout << "你气喘吁吁，有点累了";
							color(16);
							cout << ")" << endl;
						} else if (health > maxhealth / 6 * 2) {
							cout << "(";
							color(12);
							cout << "你摇头晃脑，但还能支撑一会";
							color(16);
							cout << ")" << endl;
						} else if (health > maxhealth / 6) {
							cout << "(";
							color(12);
							cout << "你已经力不从心，随时都可能倒下";
							color(16);
							cout << ")" << endl;
						} else {
							cout << "(";
							color(4);
							cout << "你已如风中残烛，生命危在旦夕";
							color(16);
							cout << ")" << endl;
						}
						if (health <= 0) {
							cout << "你说：在下实力实在不如大侠！" << endl;
							health = maxhealth / 2;
							for (int i = 0; i < peoplenum; i++) {
								room[nowroomi].people[peoplei[i]].canmove = cm[i];
								inroom.people[peoplei[i]].canmove = cm[i];
							}
							return 1;
						} else if (isrebound) {
							int att = people[x].skills[i].damage * reboundnum / 1000 + ran -
								people[x].defense;
							if (att < 0) {
								att = 0;
							}
							cout << "你抽出";
							color(nweapon.lv);
							cout << nweapon.name;
							color(16);
							cout << "一挡，对方手中";
							color(people[x].weapon.lv);
							cout << people[x].weapon.name;
							color(16);
							cout << "往后一弹，把伤害打到了自己身上，造成" << att << "点伤害！" << endl;
							people[x].health -= att;
							inroom.people[peoplei[x]].health -= att;
							room[nowroomi].people[peoplei[x]].health -= att;
							if (people[x].health > people[x].maxhealth / 6 * 5) {
								cout << "(";
								color(10);
								cout << people[x].name << "看起来一点也不累，充满了活力";
								color(16);
								cout << ")" << endl;
							} else if (people[x].health > people[x].maxhealth / 6 * 4) {
								cout << "(";
								color(14);
								cout << people[x].name << "看上去受了一点小伤，但并不碍事";
								color(16);
								cout << ")" << endl;
							} else if (people[x].health > people[x].maxhealth / 6 * 3) {
								cout << "(";
								color(14);
								cout << people[x].name << "气喘吁吁，有点累了";
								color(16);
								cout << ")" << endl;
							} else if (people[x].health > people[x].maxhealth / 6 * 2) {
								cout << "(";
								color(12);
								cout << people[x].name << "摇头晃脑，但还能支撑一会";
								color(16);
								cout << ")" << endl;
							} else if (people[x].health > people[x].maxhealth / 6) {
								cout << "(";
								color(12);
								cout << people[x].name << "已经力不从心，随时都可能倒下";
								color(16);
								cout << ")" << endl;
							} else {
								cout << "(";
								color(4);
								cout << people[x].name << "已如风中残烛，生命危在旦夕";
								color(16);
								cout << ")" << endl;
							}
							if (people[x].health <= 0) {
								cout << people[x].name << "说：在下实力实在不如大侠！" << endl;
								inroom.people[x].health = inroom.people[x].maxhealth;
								room[nowroomi].people[x] = inroom.people[x];
								die[x] = true;
								lastpeople--;
								if (lastpeople == 0) {
									for (int i = 0; i < peoplenum; i++) {
										room[nowroomi].people[peoplei[i]].canmove = cm[i];
										inroom.people[peoplei[i]].canmove = cm[i];
									}
									return 0;
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			if (cooldown[i] != 0) {
				cooldown[i] -= 1;
			}
			if (hcooldown[i] != 0) {
				hcooldown[i] -= 1;
			}
		}
	}
	return 0;
}
void choose(){
	int _health, _damage, _defense, _dodge, _hit;
	color(10);
	cout << "生命";
	color(16);
	cout << "> <";
	color(4);
	cout << "攻击";
	color(16);
	cout << "> <";
	color(14);
	cout << "防御";
	color(16);
	cout << "> <";
	color(11);
	cout << "躲避";
	color(16);
	cout << "> <";
	color(13);
	cout << "命中";
	color(16);
	cout << "> 加起来等于";
	color(4);
	cout << "100";
	color(16);
	cout << "，选择后你的属性为" << endl;
	cout << "生命 = 你选择的生命×50" << endl;
	cout << "攻击 = 你选择的×5" << endl;
	cout << "防御 = 你选择的防御" << endl;
	cout << "躲避 = 你选择的躲避×5" << endl;
	cout << "命中 = 你选择的命中×5" << endl;
	cout << "现在，请选择：";
	cin >> _health>> _damage>> _defense>> _dodge>> _hit;
	if (_health + _damage + _defense + _dodge + _hit == 100) {
		cout << "选择完毕..." << endl;
		health = _health * 50;
		maxhealth = _health * 50;
		damage = _damage * 5;
		defense = _defense;
		dodge = _dodge * 5;
		hit = _hit * 5;
	}
	else {
		cout << "你选择的数的和不等于100" << endl;
		choose();
	}
}

int walk() {
	while (1) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (room[i].people[j].canmove && rand() % 10000 == 0 && rand() % 100 == 0) {
					int dirnum = 0;
					for (int k = 0; room[i].dir[k] != ""; k++) {
						dirnum++;
					}
					int wh = rand() % dirnum;
					for (int k = 0; k < 100; k++) {
						if (room[room[i].cango[wh]].people[k].name == "") {
							if (room[i].cango[wh] == nowroomi) {
								color(11);
								cout << room[i].people[j].name << "走了过来。" << endl;
								inroom.people[k] = room[i].people[j];
								color(16);
							}
							if (i == nowroomi) {
								color(11);
								cout << room[i].people[j].name << "向" << room[i].dir[wh] << "离去。" << endl;
								color(16);
								inroom.people[j] = {};
							}
							room[room[i].cango[wh]].people[k] = room[i].people[j];
							room[i].people[j] = {};
							break;
						}
					}
				}
			}
		}
	}
}
int main() {
	
	int _health, _damage, _defense, _dodge, _hit;
	srand((unsigned)time(NULL));
	cout << "初始值加载完成(12951324/12951324)" << endl;
	ofstream outdata("update.txt", ios::binary | ios::app | ios::in | ios::out);
	ifstream fin("update.txt");
	string od;
	fin >> od;
	if (od != edition) {
		cout << "发现新版本，是否更新？(y/n)" << endl;
		cin >> od;
		if (od == "y" || od == "yes" || od == "Y") {
			ofstream clear("update.txt", ios::trunc);
			outdata << edition;
			outdata.close();
			for (int i = 0; i < 100; i++) {
				system("cls");
				cout << "更新中(" << edition << ")...[" << i << "/100]" << endl;
				sleep(rand() * 10);
			}
		} else {
			return 0;
		}
	}
	userInfo.inroom = room[0];
	for (int i = 0; i <= 146; i++) {
		system("cls");
		cout << "初始值加载完成(12951324/12951324)" << endl;
		cout << "加载数据中...(";
		cout << i;
		cout << "/146)" << endl;
		sleep(rand() % 50000);
	}
	system("cls");
	cout << "初始值加载完成(12951324/12951324)" << endl;
	cout << "加载数据完成...(146/146)" << endl;
	system("pause");
	system("cls");
	color(11);
	cout << edition << "无存档游玩版                                  " << endl;
	color(6);
	cout << "                                                  " << endl;
	cout << "         4&(                                      " << endl;
	cout << "         ' ~&&\\yM#1                              " << endl;
	cout << "          ,_'Q!!NMW&        ";
	color(16);
	color(14);
	cout << "龙  的  传  人" << endl;
	color(6);
	cout << "        WCb 7N@4D Q%,,        ";
	color(4);
	cout << "Legend of the Dragon" << endl;
	color(6);
	cout << "          PM'*MDk#M0p,                            " << endl;
	cout << "              J@J0&e~~4r' ,bQEQ                   " << endl;
	cout << "               F8I&#'   _&B$$bW#&$                " << endl;
	cout << "              &0A1   L#DE&E~!QEQ,                 " << endl;
	cout << " _=,        ,#ORN1  _T@O$'   ZN$Q.   grNq5        " << endl;
	cout << " ^ 'd     ,OKOpK^  g*QOg'    #Q4p&,/g9X*&#,_/ (q  " << endl;
	cout << "  TA1   ,sDQWh4^  x&NMO' _   #FQ#K#fA#   '*K#XWP~-" << endl;
	cout << "   ^&p,wNMMOqD: /HE#EN' ..#g)~'@NGOQx,     '=X*   " << endl;
	cout << "   '   '43$'hEk##mOD04f_g  ~^ ~  '-OO**O          " << endl;
	cout << "           ''=0#0Nq2WOBF^#, _           P,,       " << endl;
	cout << "             .  ^,,~    ~b''       **R3'          " << endl;
	cout << "                        ow,F        +#F~'         " << endl;
	cout << "                        /-9!         ' \\         " << endl;
	color(10);
	cout << "by Evan_song";
	color(6);
	cout << "             R                        " << endl;
	color(16);
	_getch();
	cout << "请输入你的英文名:";
	cin >>  userInfo.myEnglishname;
	cout << "请输入你的中文名:";
	cin >> userInfo.myname;
	cout << "请选择你的属性：<";
	
	choose();
	
	cout << endl << endl;
	color(4);
	cout << "______.-=+:/'";
	color(11);
	cout << "游戏公告";
	color(4);
	cout << "'\\:+=-.______" << endl;
	color(10);
	cout << "一，游戏更新v" << edition << endl;
	cout << " 1，减少代码长度" << endl;
	cout << " 2，修复武道塔BUG" << endl;
	cout << " 3，新增镶嵌宝石" << endl;
	cout << " 3，新增任务(task)，可在任务地点或店小二那里接任务" << endl;
	color(16);
	cout << endl << endl;
	outroom();
	string po = ">";
	thread thread_walk(walk);
	while (1) {
		if (!userInfo.baishi) {
			color(4);
			cout << "作者建议你迅速拜师，用menpai来查询门派" << endl;
			color(16);
		}
		if (userInfo.health <= 0) {
			color(4);
			cout << "你眼前一黑，就什么也不知道了..." << endl;
			color(16);
			userInfo.dienum++;
			sleep(1);
			userInfo.nowroomi = 4;
			userInfo.inroom = room[4];
			outroom();
			userInfo.health = userInfo.maxhealth;
		}
		cout << po;
		string ins1;
		color(15);
		cin >> ins1;
		color(16);
	
		if (ins1 == "l" || ins1 == "look"){
			lookAction.runMe();
		} else if (ins1 == "kill" || ins1 == "k") {
			killAction.runMe();
		} else if (ins1 == "killall") {
			killAllAction.runMe();
		} else if (ins1 == "i") {
			identityAction.runMe();
		} else if (ins1 == "move" || ins1 == "m") {
			moveAction.runMe();
		} else if (ins1 == "get" || ins1 == "g") {
			getAction.runMe();
		} else if (ins1 == "drop") {
			dropAction.runMe();
		} else if (ins1 == "help") {
			helpAction.runMe();
		} else if (ins1 == "hp") {
			hpAction.runMe();
		} else if (ins1 == "skills") {
			skillsAction.runMe();
		} else if (ins1 == "wield" || ins1 == "w") {
			wieldAction.runMe();
		} else if (ins1 == "unwield" || ins1 == "uw") {
			unwieldAction.runMe();
		} else if (ins1 == "study") {
			studyAction.runMe();
		} else if (ins1 == "say") {
			sayAction.runMe();
		} else if (ins1 == "yell") {
			yellAction.runMe();
		} else if (ins1 == "bury") {
			buryAction.runMe();
		} else if (ins1 == "set") {
			string which;
			cin >> which;
			setAction.runMe(which);
		} else if (ins1 == "sell") {
			sellAction.runMe();
		} else if (ins1 == "list") {
			listAction.runMe();
		} else if (ins1 == "buy") {
			buyAction.runMe();
		} else if (ins1 == "fight" || ins1 == "f") {
			fightAction.runMe();
		} else if (ins1 == "fightall") {
			fightAllAction.runMe();
		} else if (ins1 == "AboutGame") {
			aboutGameAction.runMe();
		} else if (ins1 == "save") {
			saveAction.runMe();
		} else if (ins1 == "UpToWizard-1" || ins1 == "UTW-1" || ins1 == "wizard-1") {
			int pass;
			cout << "请输入密码:";
			int realpass = rand();
			ofstream outdata("data2.txt", ios::binary | ios::app | ios::in | ios::out);
			outdata << realpass << endl;
			cin >> pass;
			if (pass == realpass) {
				IDEN = "wizard-1";
				cout << "您成功提升为";
				color(2);
				cout << "小巫师" << endl;
				color(16);
			}
		} else if (ins1 == "UpToWizard-2" || ins1 == "UTW-2" || ins1 == "wizard-2") {
			int pass;
			cout << "请输入密码:";
			int realpass = rand();
			ofstream outdata("data2.txt", ios::binary | ios::app | ios::in | ios::out);
			outdata << realpass << endl;
			cin >> pass;
			if (pass == realpass) {
				IDEN = "wizard-2";
				cout << "您成功提升为";
				color(1);
				cout << "中巫师" << endl;
				color(16);
			}
		} else if (ins1 == "UpToWizard-3" || ins1 == "UTW-3" || ins1 == "wizard-3") {
			int pass;
			cout << "请输入密码:";
			int realpass = rand();
			ofstream outdata("data2.txt", ios::binary | ios::app | ios::in | ios::out);
			outdata << realpass << endl;
			cin >> pass;
			if (pass == realpass) {
				IDEN = "wizard-3";
				cout << "您成功提升为";
				color(5);
				cout << "大巫师" << endl;
				color(16);
			}
		} else if (ins1 == "UpToWizard-4" || ins1 == "UTW-4" || ins1 == "wizard-4") {
			int pass;
			cout << "请输入密码:";
			int realpass = rand();
			ofstream outdata("data2.txt", ios::binary | ios::app | ios::in | ios::out);
			outdata << realpass << endl;
			cin >> pass;
			if (pass == realpass) {
				IDEN = "wizard-4";
				cout << "您成功提升为";
				color(6);
				cout << "天神" << endl;
				color(16);
			}
		} else if (ins1 == "UpToWizard-5" || ins1 == "UTW-5" || ins1 == "wizard-5") {
			int pass;
			cout << "请输入密码:";
			int realpass = rand();
			ofstream outdata("data2.txt", ios::binary | ios::app | ios::in | ios::out);
			outdata << realpass << endl;
			cin >> pass;
			if (pass == realpass) {
				IDEN = "wizard-5";
				cout << "您成功提升为";
				color(4);
				cout << "创世主" << endl;
				color(16);
			}
		} else if (ins1 == "goto") {
			gotoAction.runMe();
		} else if (ins1 == "smash") {
			smashAction.runMe();
		} else if (ins1 == "ls") {
			lsAction.runMe();
		} else if (ins1 == "make_weapon") {
			makeWeaponAction.runMe();
		} else if (ins1 == "make_thing") {
			makeThingAction.runMe();
		} else if (ins1 == "make_book") {
			makeBookAction.runMe();
		} else if (ins1 == "call") {
			
		} else if (ins1 == "clone") {
			
		} else if (ins1 == "throw") {
			
		} else if (ins1 == "conjure") {
			
		} else if (ins1 == "enable") {
			
		} else if (ins1 == "score") {
			
		} else if (ins1 == "menpai") {
			
		} else if (ins1 == "bai") {
			
		} else if (ins1 == "dazuo") {
			
		} else if (ins1 == "liaoshang") {
			
		} else if (ins1 == "home") {
			int a;
			cin >> a;
			if (((((a % 2) * 3) / 2) * 9816) % 102 == 0) {
				inroom = room[39];
				nowroomi = 39;
				outroom();
			}
		} else if (ins1 == "mine") {
			if (inroom.name == "矿洞") {
				int time;
				cin >> time;
				color(8);
				cout << "你拿起矿镐，走进矿洞深处，开始挖矿..." << endl;
				color(16);
				for (int i = 0; i < time; i++) {
					sleep(10);
					int ran = rand() % 44 + 1;
					switch (ran) {
						case 1:
						case 2:
						case 3:
						case 4:
						case 5:
						case 6:
						case 7:
						case 8:
							cout << "你挖到了煤矿...";
							minebag[1].coin++;
							break;
						case 9:
						case 10:
						case 11:
						case 12:
						case 13:
						case 14:
						case 15:
						case 16:
							cout << "你挖到了铜矿...";
							minebag[4].coin++;
							break;
						case 17:
						case 18:
						case 19:
						case 20:
						case 21:
						case 22:
							cout << "你挖到了铁矿...";
							minebag[0].coin++;
							break;
						case 23:
						case 24:
						case 25:
						case 26:
						case 27:
						case 28:
							cout << "你挖到了金矿...";
							minebag[2].coin++;
							break;
						case 29:
						case 30:
						case 31:
							cout << "你挖到了黑曜石...";
							minebag[5].coin++;
							break;
						case 32:
						case 33:
						case 34:
						case 35:
							cout << "你挖到了精铁矿...";
							minebag[6].coin++;
							break;
						case 36:
							cout << "你挖到了钻石...";
							minebag[7].coin++;
							break;
						case 37:
						case 38:
						case 39:
						case 40:
							cout << "你挖到了银矿...";
							minebag[8].coin++;
							break;
						case 41:
						case 42:
						case 43:
							cout << "你挖到了钢矿...";
							minebag[3].coin++;
							break;
						case 44:
							cout << "你挖到了钛矿...";
							minebag[9].coin++;
							break;
						default:
							break;
					}
					cout << endl;
					ran = rand() % 5 + 5;
					cout << "增加" << ran << "点潜能，" << ran / 2 << "点经验！！！" << endl;
					potential += ran;
					experience += ran / 2;
				}
				color(8);
				cout << "你挖完了矿，准备去别的地方。" << endl;
				color(16);
			} else {
				cout << "什么？" << endl;
			}
		} else if (ins1 == "minebag") {
			cout << "你有以下矿石：" << endl;
			for (int i = 0; i < 13; i++) {
				cout << minebag[i].name;
				for (int j = 0; j < 20 - minebag[i].name.size(); j++) {
					cout << " ";
				}
				cout << minebag[i].coin << "个" << endl;
			}
		} else if (ins1 == "blend") {
			string a, b;
			cin >> a >> b;
			for (int i = 0; i < 20; i++) {
				if (a == minebag[i].Englishname) {

				}
			}
		} else if (ins1 == "makesword") {
			if (mymenpai == "铸剑山庄") {
				cout << "[1级]弱铁剑 [2级]铁剑 [3级]精铁剑 [4级]钢剑 [5级]强之剑 [6级]精之剑 [7级]钻之剑 [8级]昂之剑 [9级]神之剑 [10级]倚天剑"
					<< endl;
				cout << "造剑等级：" << buildlevel << endl;
				cout << "你要造几级剑：" << endl;
				int level;
				cin >> level;
				if (level > buildlevel) {
					color(12);
					cout << "你的造剑等级不足！" << endl;
					color(16);
				} else {
					switch (level) {
						case 1:
							if (minebag[0].coin < 10 || minebag[1].coin < 10 || minebag[4].coin < 10) {
								cout << "造弱铁剑需要10x铁，10x煤，还有10x铜" << endl;
							} else {
								cout << "制造成功，使用了10x铁，10x煤，还有10x铜" << endl;
								buildexp += 75;
								cout << "你的造剑经验增加了";
								color(4);
								cout << "75" << endl;
								color(16);
								minebag[0].coin -= 10;
								minebag[1].coin -= 10;
								minebag[4].coin -= 10;
								for (int i = 0; i < 100; i++) {
									if (bag[i].name == "") {
										bag[i] = { "弱铁剑","weakiron_sword","剑","用铁铸成的剑，比铁剑稍微弱一点",30,30,0,0,0,-5,5 };
										break;
									}
								}
							}
							if (buildexp > buildlevel * 500 + 1000) {
								cout << "你的";
								color(4);
								cout << "造剑技能";
								color(16);
								cout << "等级提升了" << endl;
								buildlevel++;
								buildexp = 0;
							}
							break;
						case 2:
							if (minebag[0].coin < 20 || minebag[1].coin < 20 || minebag[4].coin < 15
								|| minebag[2].coin < 10) {
								cout << "造铁剑需要20x铁，20x煤，15x铜，还有10x金" << endl;
							} else {
								cout << "制造成功，使用了20x铁，20x煤，15x铜，还有10x金" << endl;
								minebag[0].coin -= 20;
								minebag[1].coin -= 20;
								minebag[4].coin -= 15;
								minebag[2].coin -= 10;
								buildexp += 150;
								cout << "你的造剑经验增加了";
								color(4);
								cout << "150" << endl;
								color(16);
								for (int i = 0; i < 100; i++) {
									if (bag[i].name == "") {
										bag[i] = { "铁剑","iron_sword","剑","用铁铸成的剑",50,50,0,0,0,-6,8 };
										break;
									}
								}
							}
							if (buildexp > buildlevel * 500 + 1000) {
								cout << "你的";
								color(4);
								cout << "造剑技能";
								color(16);
								cout << "等级提升了" << endl;
								buildlevel++;
								buildexp = 0;
							}
							break;
						case 3:
							if (minebag[0].coin < 35 || minebag[1].coin < 35 || minebag[4].coin < 25
								|| minebag[2].coin < 20) {
								cout << "造精铁剑需要35x铁，35x煤，25x铜，还有20x金" << endl;
							} else {
								cout << "制造成功，使用了35x铁，35x煤，25x铜，还有20x金" << endl;
								minebag[0].coin -= 35;
								minebag[1].coin -= 35;
								minebag[4].coin -= 25;
								minebag[2].coin -= 20;
								buildexp += 250;
								cout << "你的造剑经验增加了";
								color(4);
								cout << "250" << endl;
								color(16);
								for (int i = 0; i < 100; i++) {
									if (bag[i].name == "") {
										bag[i] = { "精铁剑","iron_sword","剑","用精铁铸成的剑，很坚硬",100,100,0,0,0,-10,10 };
										break;
									}
								}
							}
							if (buildexp > buildlevel * 500 + 1000) {
								cout << "你的";
								color(4);
								cout << "造剑技能";
								color(16);
								cout << "等级提升了" << endl;
								buildlevel++;
								buildexp = 0;
							}
							break;
					}
				}
			}
		} else if (ins1 == "baishi") {
			string name;
			cin >> name;
			for (int i = 0; i < 100; i++) {
				if (inroom.people[i].Englishname == name) {
					if (inroom.people[i].canbai) {
						cout << inroom.people[i].name << "：好，我就收你这个徒弟！" << endl;
						cout << "你向" << inroom.people[i].name <<
							"恭恭敬敬地磕了三下头，并喊出声来：师父，师父！" << endl;
						myshifu = inroom.people[i].name;
					} else {
						cout << inroom.people[i].name << "：拜师？不敢当不敢当" << endl;
					}
					break;
				}
			}
		} else if (ins1 == "masterskill") {
			if (myshifu != "你还未拜师...") {
				for (int i = 0; i < 100; i++) {
					if (inroom.people[i].name == myshifu) {
						cout << inroom.people[i].name << "学会了以下技能：" << endl;
						for (int j = 0; inroom.people[i].skills[j].name != ""; j++) {
							cout << inroom.people[i].skills[j].name << "(";
							color(3);
							cout << inroom.people[i].skills[j].Englishname;
							color(16);
							cout << ")     ";
							cout << inroom.people[i].skills[j].level;
							if (inroom.people[i].skills[j].level < 100) {
								color(2);
								cout << "  初学乍练" << endl;
								color(16);
							} else if (inroom.people[i].skills[j].level < 200) {
								color(2);
								cout << "  略知一二" << endl;
								color(16);
							} else if (inroom.people[i].skills[j].level < 300) {
								color(9);
								cout << "  半生不熟" << endl;
								color(16);
							} else if (inroom.people[i].skills[j].level < 400) {
								color(9);
								cout << "  平淡无奇" << endl;
								color(16);
							} else if (inroom.people[i].skills[j].level < 500) {
								color(9);
								cout << "  心神领会" << endl;
								color(16);
							} else if (inroom.people[i].skills[j].level < 600) {
								color(14);
								cout << "  熟能生巧" << endl;
								color(16);
							} else if (inroom.people[i].skills[j].level < 700) {
								color(14);
								cout << "  高深莫测" << endl;
								color(16);
							} else if (inroom.people[i].skills[j].level < 800) {
								color(14);
								cout << "  出神入化" << endl;
								color(16);
							} else if (inroom.people[i].skills[j].level < 900) {
								color(12);
								cout << "  旷古绝伦" << endl;
								color(16);
							} else if (inroom.people[i].skills[j].level < 1000) {
								color(12);
								cout << "  绝世高深" << endl;
								color(16);
							} else {
								color(12);
								cout << "  返璞归真" << endl;
								color(16);
							}
						}
						break;
					}
				}
			} else {
				cout << "你还未拜师..." << endl;
			}
		} else if (ins1 == "learn") {
			string ski;
			int num;
			cin >> ski >> num;
			if (myshifu == "你还未拜师...") {
				cout << myshifu << endl;
			} else {
				bool ishere = false;
				for (int i = 0; i < 100; i++) {
					if (inroom.people[i].name == myshifu) {
						ishere = true;
						bool isskill = false;
						for (int j = 0; inroom.people[i].skills[j].name != ""; j++) {
							if (inroom.people[i].skills[j].Englishname == ski) {
								isskill = true;
								for (int k = 0; k < num; k++) {
									bool have = false;
									for (int l = 0; l < myskilli; l++) {
										if (inroom.people[i].skills[j].name == myskill[l].name) {
											if (potential >= myskill[l].level) {
												if (inroom.people[i].skills[j].level <= myskill[l].level) {
													cout << "你这项技能等级已经不输你的师父了！！" << endl;
												} else {
													potential -= myskill[l].level;
													myskill[l].level++;
													damage += myskill[l].plusattack;
													dodge += myskill[l].plusdodge;
													hit += myskill[l].plushit;
													maxhealth += myskill[l].plushealth;
													health += myskill[l].plushealth;
													maxforce += myskill[l].plusforce;
													force += myskill[l].plusforce;
													cout << "你";
													color(4);
													cout << myskill[l].name;
													color(16);
													cout << "的等级提升了！" << endl;
													allskilllevel++;
													if (inroom.people[i].skills[j].name == "「反弹剑法」") {
														reboundnum += 1;
													}
												}
											} else {
												cout << "可能是缺乏实战经验，你实在理解不了" << inroom.people[i].name <<
													"所讲的东西" << endl;
											}
											have = true;
											break;
										}
									}
									if (!have) {
										myskill[myskilli] = inroom.people[i].skills[j];
										myskill[myskilli].damage = damage * inroom.people[i].skills[j].timedamage;
										myskill[myskilli++].level = 1;
										if (inroom.people[i].skills[j].name == "「反弹剑法」") {
											isrebound = true;
											reboundnum = 10;
										}
										cout << "你";
										color(4);
										cout << inroom.people[i].skills[j].name;
										color(16);
										cout << "的等级提升了！" << endl;
										allskilllevel++;
									}
								}
								break;
							}
						}
						if (!isskill) {
							cout << "这项技能你可能要找别人学了..." << endl;
						}
						break;
					}
				}
				if (!ishere) {
					cout << "你的师父不在这啊..." << endl;
				}
			}
		} else if (ins1 == "introduction") {
			system("start https://paste.ubuntu.com/p/nDK6hkY4xJ/");
			cout << "开启副本攻略成功" << endl;
		} else if (ins1 == "uplv") {
			if (nowroomi == 3) {
				cout << "你恭恭敬敬地问武神：「贫僧武功境界如何？」" << endl;
				sleep(1);
				if (title == "普通百姓") {
					cout << "武神说：「贫僧武功正式武士之境界。继续努力即可到达武师境界」" << endl;
					title = "武士";
					titlecolor = 10;
				} else if (title == "武士") {
					if (allskilllevel >= 2000 && maxforce >= 2000) {
						cout << "武神说：「贫僧武功正式武师之境界。继续努力即可到达宗师境界」" << endl;
						title = "武师";
						titlecolor = 9;
					} else {
						cout << "武神说：「要到达武师境界，需要所有技能的等级之和到达2000和最大内力到达2000」"
							<< endl;
					}
				}
			} else {
				cout << "武神不在这" << endl;
			}
		} else if (ins1 == "wudaota") {
			cout << "进入武道塔成功！";
			inroom = room[44];
			nowroomi = 44;
			outroom();
		} else if (ins1 == "build") {
			bool ishave = false;
			for (int i = 0; i < 100; i++) {
				if (inroom.people[i].name == "师傅") {
					ishave = true;
				}
			}
			if (ishave) {
				cout << "类型：剑，刀，鞭（注意：拂尘也算鞭），拳，棍" << endl;
				cout << "输入武器类型:";
				we makeweapon;
				cin >> makeweapon.type;
				cout << "起好名：断空剑，斩铁刀，随缘鞭，千年尘，凝碧刀，斩人无血，无双棍，阴阳棍，七煞刀，月无影，嗜血鞭"
					<< endl;
				cout << "输入武器名字:";
				cin >> makeweapon.name;
				cout << "输入武器英文名:";
				cin >> makeweapon.Englishname;
				makeweapon.tell = "这是" + myname + "的专属武器，名叫" + makeweapon.name + "。";
				makeweapon.plusdamage = 100;
				makeweapon.plusdefense = 50;
				makeweapon.plusdodge = 100;
				makeweapon.plusforce = 100;
				makeweapon.plushealth = 100;
				makeweapon.plushit = 100;
				makeweapon.lv = 4;
				makeweapon.inlaynum = 10;
				makeweapon.inlaything[0] = {};
				makeweapon.inlaything[1] = {};
				makeweapon.inlaything[2] = {};
				makeweapon.inlaything[3] = {};
				makeweapon.inlaything[4] = {};
				makeweapon.inlaything[5] = {};
				makeweapon.inlaything[6] = {};
				makeweapon.inlaything[7] = {};
				makeweapon.inlaything[8] = {};
				makeweapon.inlaything[9] = {};
				cout << "需要10*铁矿，10*煤，10*金矿，10*铜矿，10*钢矿，10*黑曜石去打造" <<
					endl;
				if (minebag[0].coin < 10 || minebag[1].coin < 10 || minebag[2].coin < 10
					|| minebag[3].coin < 10 || minebag[4].coin < 10 || minebag[5].coin < 10) {
					cout << "材料不足" << endl;
				} else {
					cout << "制造成功" << endl;
					minebag[0].coin -= 10;
					minebag[1].coin -= 10;
					minebag[2].coin -= 10;
					minebag[3].coin -= 10;
					minebag[4].coin -= 10;
					minebag[5].coin -= 10;
					for (int i = 0; i < 100; i++) {
						if (bag[i].name == "") {
							bag[i] = makeweapon;
							break;
						}
					}
				}
			} else {
				cout << "这里没有可以帮你打造武器的人啊！" << endl;
			}
		} else if (ins1 == "refine") {
			bool ishave = false;
			for (int i = 0; i < 100; i++) {
				if (inroom.people[i].name == "师傅") {
					ishave = true;
				}
			}
			if (ishave) {
				cout << "精炼需要3*黑曜石" << endl;
				if (minebag[5].coin >= 3) {
					color(nweapon.lv);
					cout << nweapon.name;
					color(16);
					cout << "精炼至";
					for (int i = 0; i < 100; i++) {
						if (bag[i].name == nweapon.name) {
							if (bag[i].name[bag[i].name.size() - 2] == -95
								&& bag[i].name[bag[i].name.size() - 1] == -13) {
								bag[i].name[bag[i].name.size() - 1] = -12;
								nweapon.name[nweapon.name.size() - 1] = -12;
							} else {
								bag[i].name += "◇";
								nweapon.name += "◇";
							}
							nweapon.plusdamage += 20;
							nweapon.plusdefense += 10;
							nweapon.plusdodge += 20;
							nweapon.plusforce += 20;
							nweapon.plushealth += 100;
							nweapon.plushit += 20;
							damage += 20;
							defense += 10;
							dodge += 20;
							force += 20;
							maxforce += 20;
							health += 100;
							maxhealth += 100;
							hit += 20;
							bag[i].plusdamage += 20;
							bag[i].plusdefense += 10;
							bag[i].plusdodge += 20;
							bag[i].plusforce += 20;
							bag[i].plushealth += 100;
							bag[i].plushit += 20;
							break;
						}
					}
					color(nweapon.lv);
					cout << nweapon.name << endl;
					color(16);
					bag[5].coin -= 3;
				} else {
					color(4);
					cout << "黑曜石不足！" << endl;
					color(16);
				}
			} else {
				cout << "这里没有可以帮你精炼武器的人啊！" << endl;
			}
		} else if (ins1 == "inlay") {
			bool ishave = false;
			for (int i = 0; i < 100; i++) {
				if (inroom.people[i].name == "师傅") {
					ishave = true;
				}
			}
			if (ishave) {
				int inlayplace;
				for (inlayplace = 0; inlayplace < nweapon.inlaynum; inlayplace++) {
					if (nweapon.inlaything[inlayplace].name == "") {
						break;
					}
				}
				if (inlayplace == nweapon.inlaynum) {
					color(6);
					cout << "此武器已经没有可以镶嵌宝石的地方了" << endl;
					color(16);
				} else {
					cout << "请问你要镶嵌什么宝石在";
					color(nweapon.lv);
					cout << nweapon.name;
					color(16);
					cout << "上" << endl;
					for (int i = 0; i < 100; i++) {
						if (bag3[i].tell == "这是一个宝石") {
							cout << bag3[i].name << "(" << bag3[i].Englishname << ")" << endl;
						}
					}
					string name;
					cin >> name;
					ishave = false;
					for (int i = 0; i < 100; i++) {
						if (bag3[i].tell == "这是一个宝石" && bag3[i].Englishname == name) {
							ishave = true;
							nweapon.inlaything[inlayplace] = bag3[i];
							nweapon.plusdamage += bag3[i].coin * 10;
							nweapon.plusdefense += bag3[i].coin * 5;
							nweapon.plusdodge += bag3[i].coin * 10;
							nweapon.plusforce += bag3[i].coin * 10;
							nweapon.plushealth += bag3[i].coin * 100;
							nweapon.plushit += bag3[i].coin * 10;
							damage += bag3[i].coin * 10;
							defense += bag3[i].coin * 5;
							dodge += bag3[i].coin * 10;
							force += bag3[i].coin * 10;
							maxforce += bag3[i].coin * 10;
							health += bag3[i].coin * 100;
							maxhealth += bag3[i].coin * 100;
							hit += bag3[i].coin * 10;
							for (int j = 0; j < 100; j++) {
								if (bag[j].Englishname == nweapon.Englishname) {
									bag[j].inlaything[inlayplace] = bag3[i];
									bag[j].plusdamage += bag3[i].coin * 10;
									bag[j].plusdefense += bag3[i].coin * 5;
									bag[j].plusdodge += bag3[i].coin * 10;
									bag[j].plusforce += bag3[i].coin * 10;
									bag[j].plushealth += bag3[i].coin * 100;
									bag[j].plushit += bag3[i].coin * 10;
									break;
								}
							}
							bag3[i] = {};
							break;
						}
					}
					if (!ishave) {
						color(6);
						cout << "没有这个宝石" << endl;
						color(16);
					} else {
						color(4);
						cout << "镶嵌成功" << endl;
						color(16);
					}
				}
			} else {
				cout << "这里没有可以帮强化武器的人啊！" << endl;
			}
		} else if (ins1 == "pray") {
			if (nowroomi == 0) {
				int ran = rand() % 10;
				if (ran == 0) {
					color(4);
					cout << "天上突然打下一道雷，正中";
					color(11);
					cout << myname << endl;
					color(4);
					cout << "你眼前一黑，晕了过去..." << endl;
					color(16);
					sleep(10);
					color(6);
					cout << "慢慢地，你有了知觉..." << endl;
					color(16);
				} else if (ran == 9) {
					color(6);
					cout << "祈祷完了，你感觉自己全身闪着金光..." << endl;
					color(8);
					cout << "（金色传说！！！）" << endl;
					color(16);
				} else {
					color(8);
					cout << "祈祷完了，你感觉什么都没发生..." << endl;
					color(16);
				}
			} else {
				cout << "这里不是客栈..." << endl;
			}
		} else if (ins1 == "task") {
			string someone;
			cin >> someone;
			if (someone == "XiaoEr" && !ta[0] && nowroomi == 0) {
				if (task == "XiaoEr") {
					for (int i = 0; i < 100; i++) {
						if (bag3[i].name == "野狗的尸体") {
							color(6);
							cout << "店小二跟你说：大侠，多谢你的帮助" << endl;
							cout << "店小二给你了100文钱" << endl;
							ta[0] = true;
							coin += 100;
							color(16);
							break;
						}
					}
				}
				if (!ta[0]) {
					color(6);
					cout << "店小二跟你说：大侠，您可以去杀些野狗，为民除害吗？" << endl;
					color(16);
					task = "XiaoEr";
				}
			}
			if (someone == "notice1" && !ta[1] && nowroomi == 46) {
				if (task == "notice1") {
					if (!ta[1]) {
						color(6);
						cout << "你看了看告示，再次决定要去闯武道塔" << endl;
						color(16);
						task = "notice1";
					} else {
						color(6);
						cout << "士兵：你去了武道塔，皇帝叫我赏你5银" << endl;
						cout << "士兵给你了5银" << endl;
						color(16);
						coin += 500;
					}
				} else if (!ta[1]) {
					color(6);
					cout << "你撕下了告示，准备去闯闯武道塔" << endl;
					color(16);
					task = "notice1";
				} else {
					color(6);
					cout << "士兵：你去了武道塔，皇帝叫我赏你1银" << endl;
					cout << "士兵给你了100文钱" << endl;
					color(16);
					ta[1] = true;
					coin += 100;
				}
			}
		} else if (ins1 == "gift") {
			if (nowroomi == 47) {
				if (gift[0] == false) {
					cout << "你领取了登录礼包，获得了1银" << endl;
					coin += 100;
					gift[0] = true;
				}
				if (gift[1] == false) {
					cout << "你领取了夏日礼包，获得了";
					color(4);
					cout << "钟馗道剑" << endl;
					color(16);
					color(4);
					cout << "钟馗道剑" << endl;
					color(16);
					cout << "品质【";
					color(4);
					cout << "红";
					color(16);
					cout << "】" << endl;
					cout << "镶嵌槽: ◇◇◇◇◇" << endl;
					gift[1] = true;
					for (int i = 0; i < 100; i++) {
						if (bag[i].name == "") {
							bag[i] = zhongkui;
							break;
						}
					}
				}
			} else {
				cout << "什么？" << endl;
				cout << "如果你不知道指令，请输入 help 查询" << endl;
			}
		} else {
			cout << "什么？" << endl;
			cout << "如果你不知道指令，请输入 help 查询" << endl;
		}
		conversion();
		for (int i = 0; i < myskilli; i++) {
			if (myskill[i].name != "绝世武功") {
				myskill[i].damage = myskill[i].timedamage * damage;
			}
		}
	}
	return 0;
}