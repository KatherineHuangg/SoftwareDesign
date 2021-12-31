#include <iostream>
#include <userInfo.h>
#include <string.h>

using namespace std;

class Action{
    public:
        UserInfo userInfo;
        void runMe();
};

class LookAction: public Action{
    public:
        void runMe() {    
            string name;
            cin >> name;
            if (name == "room") { //查看房間
                outroom();
            } else {
                bool is = false;
                for (int i = 0; i < 100; i++) {
                    if (userInfo.inroom.people[i].Englishname == name || userInfo.inroom.people[i].name == name) {
                        color(12);
                        cout << userInfo.inroom.people[i].name << endl;
                        color(16);
                        cout << userInfo.inroom.people[i].tell << endl;
                        is = true;
                        break;
                    }
                }
                for (int i = 0; i < 100; i++) {
                    if (userInfo.inroom.weapon[i].Englishname == name || userInfo.inroom.weapon[i].name == name) {
                        color(userInfo.inroom.weapon[i].lv);
                        cout << userInfo.inroom.weapon[i].name << endl;
                        color(16);
                        if (userInfo.inroom.weapon[i].type == "剑") {
                            color(6);
                            cout << "        ◢" << endl;
                            cout << "        █" << endl;
                            cout << "⊙█████";
                            color(15);
                            cout << "〓〓〓〓〓〓〓〓〓〓>" << endl;
                            color(6);
                            cout << "        █" << endl;
                            cout << "        ◥" << endl;
                            color(16);
                        }
                        if (userInfo.inroom.weapon[i].type == "刀") {
                            color(6);
                            cout << "        ▲  " << endl;
                            cout << "◇████";
                            color(8);
                            cout << "〓〓〓〓〓〓〓◤" << endl;
                            color(6);
                            cout << "        ▼  " << endl;
                            color(16);
                        }
                        if (userInfo.inroom.weapon[i].type == "鞭") {
                            color(6);
                            cout << "〓〓〓";
                            color(8);
                            cout << "=========---------" << endl;
                            color(16);
                        }
                        cout << userInfo.inroom.weapon[i].tell << endl;
                        cout << "武器属性:" << endl;
                        cout << "攻击:" << userInfo.inroom.weapon[i].plusdamage << endl;
                        cout << "防御:" << userInfo.inroom.weapon[i].plusdefense << endl;
                        cout << "躲闪:" << userInfo.inroom.weapon[i].plusdodge << endl;
                        cout << "内力:" << userInfo.inroom.weapon[i].plusforce << endl;
                        cout << "生命:" << userInfo.inroom.weapon[i].plushealth << endl;
                        cout << "命中:" << userInfo.inroom.weapon[i].plushit << endl;
                        cout << "镶嵌宝石:" << endl;
                        if (userInfo.inroom.weapon[i].inlaynum == 0) {
                            cout << "此武器无镶嵌空" << endl;
                        } else {
                            for (int j = 0; j < userInfo.inroom.weapon[i].inlaynum; j++) {
                                if (userInfo.inroom.weapon[i].inlaything[j].name == "") {
                                    cout << "◇" << endl;
                                } else {
                                    cout << "◆" << userInfo.inroom.weapon[i].inlaything[j].name <<
                                        userInfo.inroom.weapon[i].inlaything[j].coin << endl;
                                }
                            }
                        }
                        is = true;
                        break;
                    }
                }
                for (int i = 0; i < 100; i++) {
                    if (userInfo.inroom.book[i].Englishname == name || userInfo.inroom.book[i].name == name) {
                        color(12);
                        cout << userInfo.inroom.book[i].name << endl;
                        color(16);
                        cout << userInfo.inroom.book[i].tell << endl;
                        is = true;
                        break;
                    }
                }
                for (int i = 0; i < 100; i++) {
                    if (userInfo.inroom.thing[i].Englishname == name || userInfo.inroom.thing[i].name == name) {
                        color(12);
                        cout << userInfo.inroom.thing[i].name << endl;
                        color(16);
                        cout << userInfo.inroom.thing[i].tell << endl;
                        is = true;
                        break;
                    }
                }
                if (!is) {
                    cout << "你要看什么？" << endl;
                }
            }
	}
};

class KillAction: public Action{
    public:
        void runMe(){
            string name;
            cin >> name;
            bool is = false;
            for (int i = 0; i < 100; i++) {
                if (userInfo.inroom.people[i].name == name || userInfo.inroom.people[i].Englishname == name) {
                    userInfo.x[0] = userInfo.inroom.people[i];
                    userInfo.y[0] = i;
                    //killall(userInfo.x, 1, userInfo.y);
                    is = true;
                    break;
                }
            }
            if (!is) {
                cout << "你要击杀谁？" << endl;
                cout << "指令格式：kill <某人>" << endl;
            }
        }
};

class KillAllAction: public Action{
    public:
        void runMe(){
            string name;
			int many;
			cin >> many;
			int num = 0;
			bool is = false;
			for (int i = 0; i < many; i++) {
				cin >> name;
				for (int j = 0; j < 100; j++) {
					if (userInfo.inroom.people[j].name == name || userInfo.inroom.people[j].Englishname == name) {
						userInfo.x[num] = userInfo.inroom.people[j];
						userInfo.y[num] = j;
						num++;
						is = true;
						break;
					}
				}
			}
			if (!is) {
				cout << "你要击杀谁？" << endl;
				cout << "指令格式：kill <某人>" << endl;
			} else {
				//killall(userInfo.x, num, userInfo.y);
			}
        }

};

class IdentityAction: public Action{
    public:
        void runMe(){
            color(userInfo.titlecolor);
			cout << userInfo.title;
			if (userInfo.title2 != "") {
				cout << " " << userInfo.title2;
			}
			cout << " " << userInfo.myname << endl;
			color(16);
			int index = userInfo.allskilllevel;
			cout << "你的功夫看起来";

			color(8);
			if(index == 0){
				cout << allskilllevel_vect[0] << endl;
			}
			else{
				cout << allskilllevel_vect[index/500] << endl;
			}
			color(16);
			
			cout << "你装备着:" << endl;
			cout << "·";
			color(nweapon.lv);
			cout << nweapon.name << endl;
			color(16);
			cout << "你有";
			color(14);
			cout << userInfo.gold;
			color(16);
			cout << "金 ";
			color(7);
			cout << userInfo.silver;
			color(16);
			cout << "银 ";
			color(6);
			cout << userInfo.coin;
			color(16);
			cout << "文" << endl;
			cout << "你身上有：" << endl;
			for (int i = 0; i < 200; i++) {
				if (userInfo.bag[i].name != "") {
					color(userInfo.bag[i].lv);
					cout << userInfo.bag[i].name;
					color(16);
					cout << "(";
					color(3);
					cout << userInfo.bag[i].Englishname;
					color(16);
					cout << ")" << endl;
				}
			}
			for (int i = 0; i < 200; i++) {
				if (userInfo.bag2[i].name != "") {
					cout << userInfo.bag2[i].name << "(";
					color(3);
					cout << userInfo.bag2[i].Englishname;
					color(16);
					cout << ")" << endl;
				}
			}
			for (int i = 0; i < 200; i++) {
				if (userInfo.bag3[i].name != "") {
					cout << userInfo.bag3[i].name << "(";
					color(3);
					cout << userInfo.bag3[i].Englishname;
					color(16);
					cout << ")" << endl;
				}
			}
        }
};

class MoveAction: public Action{
    public:
        void runMe(){
            string dir;
			bool is = false;
			cin >> dir;
			for (int i = 0; i < 100; i++) {
				if (userInfo.inroom.dir[i] == dir) {
					if (userInfo.inroom.name == "财主家入口" && dir == "east") {
						bool iskey = false;
						for (int i = 0; i < 200; i++) {
							if (userInfo.bag3[i].Englishname == "key") {
								iskey = true;
								break;
							}
						}
						if (iskey) {
							userInfo.nowroomi = userInfo.inroom.cango[i];
							userInfo.inroom = room[userInfo.inroom.cango[i]];
							outroom();
						} else {
							color(11);
							cout << "你试图打开大门，但发现大门被人上了锁..." << endl;
							color(16);
						}
					} else if (userInfo.inroom.name == "道路" && dir == "east") {
						bool iskey = false;
						for (int i = 0; i < 200; i++) {
							if (userInfo.bag3[i].Englishname == "key") {
								iskey = true;
								break;
							}
						}
						if (iskey) {
							userInfo.nowroomi = userInfo.inroom.cango[i];
							userInfo.inroom = room[userInfo.inroom.cango[i]];
							outroom();
						} else {
							color(11);
							cout << "你试图打开宝库的大门，但发现大门被人上了锁..." << endl;
							color(16);
						}
					} else if (userInfo.inroom.name == "客栈" && dir == "up") {
						if (userInfo.mymenpai == "武当") {
							userInfo.inroom = room[26];
							userInfo.nowroomi = 26;
							outroom();
						} else if (userInfo.mymenpai == "丐帮") {
							userInfo.inroom = room[27];
							userInfo.nowroomi = 27;
							outroom();
						} else if (userInfo.mymenpai == "铸剑山庄") {
							userInfo.inroom = room[41];
							userInfo.nowroomi = 41;
							outroom();
						} else if (userInfo.mymenpai == "道家") {
							userInfo.inroom = room[43];
							userInfo.nowroomi = 43;
							outroom();
						} else {
							color(6);
							cout << "这个入口是门派入口，你还没有拜入门派..." << endl;
							color(16);
						}
					} else if (userInfo.inroom.name == "武道塔" && dir == "up") {
						if (userInfo.inroom.people[0].name == "") {
							userInfo.wudaotalevel++;
							color(4);
							cout << ">>>成功进入武道塔第" << userInfo.wudaotalevel << "层" << endl;
							cout << ">>>增加1.5银，" << userInfo.wudaotalevel - 1 << "点潜能" << endl;
							color(16);
							userInfo.silver += 1;
							userInfo.potential += userInfo.wudaotalevel - 1;
							userInfo.experience += (userInfo.wudaotalevel - 1) / 2;
							userInfo.inroom.tell = "你现在处于" + to_string(userInfo.wudaotalevel) + "层";
							userInfo.inroom.people[0] = lvpeople[userInfo.wudaotalevel];
							room[userInfo.nowroomi].tell = "你现在处于" + to_string(userInfo.wudaotalevel) + "层";
							room[userInfo.nowroomi].people[0] = lvpeople[userInfo.wudaotalevel];
							userInfo.ta[1] = true;
							outroom();
						} else {
							color(6);
							cout << userInfo.inroom.people[0].name <<
								"飞快的拦在了你的面前，说「打败我，就可以上去！」" << endl;
							color(16);
						}
					} else {
						userInfo.nowroomi = userInfo.inroom.cango[i];
						userInfo.inroom = room[userInfo.inroom.cango[i]];
						outroom();
					}
					is = true;
					break;
				}
			}
			if (!is) {
				cout << "你要去哪里？" << endl;
				cout << "指令格式：move <方向>" << endl;
			}
        }
};

class GetAction: public Action{
    public:
        void runMe(){
            string type;
			string thing;
			cin >> type;
			cin >> thing;
			bool is = false;
			for (int i = 0; i < 100; i++) {
				if (type == "weapon") {
					if ((userInfo.inroom.weapon[i].name == thing || userInfo.inroom.weapon[i].Englishname == thing
						|| thing == "all") && userInfo.inroom.weapon[i].name != "") {
						for (int j = 0; j < 1000; j++) {
							if (userInfo.bag[j].name == "") {
								userInfo.bag[j] = userInfo.inroom.weapon[i];
								break;
							}
						}
						cout << "你捡起一个";
						color(userInfo.inroom.weapon[i].lv);
						cout << userInfo.inroom.weapon[i].name << endl;
						color(16);
						userInfo.inroom.weapon[i] = {};
						room[userInfo.nowroomi].weapon[i] = {};
						is = true;
						if (thing != "all") {
							break;
						}
					}
				} else if (type == "book") {
					if ((userInfo.inroom.book[i].name == thing || userInfo.inroom.book[i].Englishname == thing
						|| thing == "all") && userInfo.inroom.book[i].name != "") {
						bool isspace = false;
						for (int j = 0; j < 1000; j++) {
							if (userInfo.bag2[j].name == "") {
								userInfo.bag2[j] = userInfo.inroom.book[i];
								isspace = true;
								break;
							}
						}
						cout << "你捡起一本" << userInfo.inroom.book[i].name << endl;
						userInfo.inroom.book[i] = {};
						room[userInfo.nowroomi].book[i] = {};
						is = true;
						if (thing != "all") {
							break;
						}
					}
				} else if (type == "thing") {
					if (userInfo.inroom.thing[i].name == thing || userInfo.inroom.thing[i].Englishname == thing
						|| thing == "all") {
						is = true;
						if (userInfo.inroom.thing[i].name == "富人家副本[建议经验1000时进入]") {
							cout << userInfo.myname << "进入富人家副本成功..." << endl;
							cout << endl << endl;
							cout << "这村子的财主这几夜来突然变得疯疯癫癫，不像人样，然而后几天突然就没了人影，你打算去调查一番"
								<< endl;
							cout << "你来到了财主家..." << endl;
							cout << endl;
							for (int j = 0; j < 12; j++) {
								room[j + 8] = instancesroom1[j];
							}
							userInfo.inroom = room[8];
							userInfo.nowroomi = 8;
							outroom();
						} else if (userInfo.inroom.thing[i].name == "森林副本[建议经验500时进入]") {
							cout << userInfo.myname << "进入森林副本成功..." << endl;
							cout << endl << endl;
							cout << "最近村子里的猎手越来越少，基本上一去树林就回不来了，村里人让你去树林里查看一下"
								<< endl;
							cout << "你来到了树林..." << endl;
							cout << endl;
							for (int j = 0; j < 6; j++) {
								room[j + 20] = instancesroom2[j];
							}
							userInfo.inroom = room[20];
							userInfo.nowroomi = 20;
							outroom();
						} else if (userInfo.inroom.thing[i].name == "胡斐副本[建议经验2500时进入]") {
							cout << userInfo.myname << "进入胡斐副本成功..." << endl;
							cout << endl << endl;
							cout << "你来到了胡斐居住地点..." << endl;
							cout << endl;
							for (int j = 0; j < 11; j++) {
								room[j + 28] = instancesroom3[j];
							}
							userInfo.inroom = room[28];
							userInfo.nowroomi = 28;
							outroom();
						} else if (userInfo.inroom.thing[i].name == "练习室[无条件即可进入]") {
							cout << userInfo.myname << "进入练习室成功..." << endl;
							cout << endl;
							room[42] = instancesroom4[0];
							userInfo.inroom = room[42];
							userInfo.nowroomi = 42;
							outroom();
						} else if (userInfo.inroom.thing[i].name != "") {
							bool isspace = false;
							for (int j = 0; j < 1000; j++) {
								if (userInfo.bag3[j].name == "") {
									userInfo.bag3[j] = userInfo.inroom.thing[i];
									isspace = true;
									break;
								}
							}
							cout << "你捡起一个" << userInfo.inroom.thing[i].name << endl;
							userInfo.inroom.thing[i] = {};
							room[userInfo.nowroomi].thing[i] = {};
							if (thing != "all") {
								break;
							}
						}
					}
				}
			}
			if (!is) {
				cout << "你要拿什么？" << endl;
				cout << "指令格式：get <型号> <某物>" << endl;
			}
        }
};

class DropAction: public Action{
    public:
        void runMe(){
            string type;
			string thing;
			cin >> type;
			cin >> thing;
			bool is = false;
			if (type == "weapon") {
				for (int i = 0; i < 100; i++) {
					if (userInfo.bag[i].name == thing || userInfo.bag[i].Englishname == thing) {
						for (int j = 0; j < 100; j++) {
							if (userInfo.inroom.weapon[j].name == "") {
								userInfo.inroom.weapon[j] = userInfo.bag[i];
								room[userInfo.nowroomi].weapon[j] = userInfo.bag[i];
								break;
							}
						}
						cout << "你丢掉一个";
						color(userInfo.bag[i].lv);
						cout << userInfo.bag[i].name << endl;
						color(16);
						userInfo.bag[i] = {};
						is = true;
						break;
					}
				}
			} else if (type == "book") {
				for (int i = 0; i < 100; i++) {
					if (userInfo.bag2[i].name == thing || userInfo.bag2[i].Englishname == thing) {
						for (int j = 0; j < 100; j++) {
							if (userInfo.inroom.book[j].name == "") {
								userInfo.inroom.book[j] = userInfo.bag2[i];
								room[userInfo.nowroomi].book[j] = userInfo.bag2[i];
								break;
							}
						}
						cout << "你丢掉一个" << userInfo.bag2[i].name << endl;
						userInfo.bag2[i] = {};
						is = true;
						break;
					}
				}
			} else if (type == "thing") {
				for (int i = 0; i < 100; i++) {
					if (userInfo.bag3[i].name == thing || userInfo.bag3[i].Englishname == thing) {
						for (int j = 0; j < 100; j++) {
							if (userInfo.inroom.thing[j].name == "") {
								userInfo.inroom.thing[j] = userInfo.bag3[i];
								room[userInfo.nowroomi].thing[j] = userInfo.bag3[i];
								break;
							}
						}
						cout << "你丢掉一个" << userInfo.bag3[i].name << endl;
						userInfo.bag3[i] = {};
						is = true;
						break;
					}
				}
			}
			if (!is) {
				cout << "你要丢什么？" << endl;
				cout << "指令格式：drop <型号> <某物>" << endl;
			}
        }
};

class HelpAction: public Action{
    public:
        void runMe(){
            cout << "所有指令都可使用" << endl;
			cout << "指令个数：50" << endl;
			cout << " _____________战斗指令_____________" << endl;
			cout << "|跟某人比试: fight <某人>          |" << endl;
			cout << "|击杀某人: kill <某人>             |" << endl;
			cout << "|跟群人比试: fightall <人数><人名> |" << endl;
			cout << "|击杀群人: killall <人数><人名>    |" << endl;
			cout << "|使用技能: <数字>                  |" << endl;
			cout << "|__________________________________|" << endl;
			cout << " _____________装备指令_____________" << endl;
			cout << "|装备武器: wield <某武器>          |" << endl;
			cout << "|卸下武器: unwield <某武器>        |" << endl;
			cout << "|精炼武器: refine <装备武器>       |" << endl;
			cout << "|打造武器: build <某武器>          |" << endl;
			cout << "|自造武器: makesword(铸剑山庄可用) |" << endl;
			cout << "|__________________________________|" << endl;
			cout << " _____________冒险指令_____________" << endl;
			cout << "|捡东西: get <型号> <某物>         |" << endl;
			cout << "|丢掉东西: drop <型号> <某物>      |" << endl;
			cout << "|询问某人: ask <某人> about <某事> |" << endl;
			cout << "|移动: move <方向>                 |" << endl;
			cout << "|用东西砸人: throw <某物> to <某人>|" << endl;
			cout << "|查看状态: hp                      |" << endl;
			cout << "|看: l/look <...>                  |" << endl;
			cout << "|查看自己的东西: i                 |" << endl;
			cout << "|查看自己的技能: skills            |" << endl;
			cout << "|买东西: buy <某物>                |" << endl;
			cout << "|卖东西: sell <某物>               |" << endl;
			cout << "|查看所卖物品: list                |" << endl;
			cout << "|查看矿石: minebag                 |" << endl;
			cout << "|合成矿石: blend <两个材料>        |" << endl;
			cout << "|拜师: baishi <某人>               |" << endl;
			cout << "|查看师父技能: masterskill         |" << endl;
			cout << "|提升境界: uplv                    |" << endl;
			cout << "|进入武道塔: wudaota               |" << endl;
			cout << "|__________________________________|" << endl;
			cout << " _____________武功指令_____________" << endl;
			cout << "|研读: study <某书> <次数>         |" << endl;
			cout << "|学习: learn <技能> <次数>         |" << endl;
			cout << "|使用: enable <轻功技能>           |" << endl;
			cout << "|打坐: dazuo <次数>                |" << endl;
			cout << "|疗伤: liaoshang <次数>            |" << endl;
			cout << "|__________________________________|" << endl;
			cout << " _____________聊天指令_____________" << endl;
			cout << "|说话: say <...>                   |" << endl;
			cout << "|大喊: yell <...>                  |" << endl;
			cout << "|__________________________________|" << endl;
			cout << " _____________其他指令_____________" << endl;
			cout << "|埋葬尸体: bury corpse/allcorpse   |" << endl;
			cout << "|帮助: help                        |" << endl;
			cout << "|设置: set <...> to <...>          |" << endl;
			cout << "|关于游戏: AboutGame               |" << endl;
			cout << "|保存: save                        |" << endl;
			cout << "|提升至X级巫师: UTW-X              |" << endl;
			cout << "|副本攻略: introduction            |" << endl;
			cout << "|__________________________________|" << endl;
			if (userInfo.IDEN == "wizard-1") {
				cout << " ____________小巫师指令____________" << endl;
				cout << "|去: goto <某地>                   |" << endl;
				cout << "|__________________________________|" << endl;
			}
			if (userInfo.IDEN == "wizard-2") {
				cout << " ____________中巫师指令____________" << endl;
				cout << "|去: goto <某地>                   |" << endl;
				cout << "|雷劈: smash <某人>                |" << endl;
				cout << "|复制东西: clone <某物>            |" << endl;
				cout << "|查看某物值: score <某物>          |" << endl;
				cout << "|变出东西: conjure <某物>          |" << endl;
				cout << "|查看变出物品: ls                  |" << endl;
				cout << "|创造武器: make_weapon             |" << endl;
				cout << "|__________________________________|" << endl;
			}
			if (userInfo.IDEN == "wizard-3") {
				cout << " ____________大巫师指令____________" << endl;
				cout << "|去: goto <某地>                   |" << endl;
				cout << "|雷劈: smash <某人>                |" << endl;
				cout << "|复制东西: clone <某物>            |" << endl;
				cout << "|查看某物值: score <某物>          |" << endl;
				cout << "|变出东西: conjure <某物>          |" << endl;
				cout << "|查看变出物品: ls                  |" << endl;
				cout << "|创造武器: make_weapon             |" << endl;
				cout << "|更改值: call<某人><set+东西><值>  |" << endl;
				cout << "|__________________________________|" << endl;
			}
        }
};

class HPAction: public Action{
    public:
        void runMe(){
            cout << "__________________________" << endl;
			cout << "==========================" << endl;
			cout << "|气血:" << userInfo.health << "/" << userInfo.maxhealth << endl;
			cout << "|内力:" << userInfo.force << "/" << userInfo.maxforce << endl;
			cout << "|经验:" << userInfo.experience << endl;
			cout << "|潜能:" << userInfo.potential << endl;
			cout << "|攻击:" << userInfo.damage << endl;
			cout << "|防御:" << userInfo.defense << endl;
			cout << "|躲避:" << userInfo.dodge << endl;
			cout << "|命中:" << userInfo.hit << endl;
			cout << "|文化:" << userInfo.literate << endl;
			cout << "|杀人" << userInfo.killnum << "次" << endl;
			cout << "|死亡" << userInfo.dienum << "次" << endl;
			cout << "|门派：" << userInfo.mymenpai << endl;
			cout << "|师父：" << userInfo.myshifu << endl;
			cout << "|身份：";
			if (userInfo.IDEN == "wizard-1") cout << "小巫师" << endl;
			else if (userInfo.IDEN == "wizard-2") cout << "中巫师" << endl;
			else if (userInfo.IDEN == "wizard-3") cout << "大巫师" << endl;
			else if (userInfo.IDEN == "wizard-4") cout << "天神" << endl;
			else if (userInfo.IDEN == "wizard-5") cout << "创世主" << endl;
			else cout << "平民" << endl;
			cout << "==========================" << endl;
			cout << "**************************" << endl;
        }
};

class SkillsAction: public Action{
    public:
        void runMe(){
            cout << "你学会了以下技能：" << endl;
			for (int i = 0; i < 9; i++) {
				cout << mybasicskill[i].name;
				for (int j = 0; j < (20 - mybasicskill[i].name.size()); j++) {
					cout << " ";
				}
				cout << mybasicskill[i].level;
				if (mybasicskill[i].level == 0) {
					color(8);
					cout << "  一无所知" << endl;
					color(16);
				} else if (mybasicskill[i].level < 100) {
					color(2);
					cout << "  初学乍练" << endl;
					color(16);
				} else if (mybasicskill[i].level < 200) {
					color(2);
					cout << "  略知一二" << endl;
					color(16);
				} else if (mybasicskill[i].level < 300) {
					color(9);
					cout << "  半生不熟" << endl;
					color(16);
				} else if (mybasicskill[i].level < 400) {
					color(9);
					cout << "  平淡无奇" << endl;
					color(16);
				} else if (mybasicskill[i].level < 500) {
					color(9);
					cout << "  心神领会" << endl;
					color(16);
				} else if (mybasicskill[i].level < 600) {
					color(14);
					cout << "  熟能生巧" << endl;
					color(16);
				} else if (mybasicskill[i].level < 700) {
					color(14);
					cout << "  高深莫测" << endl;
					color(16);
				} else if (mybasicskill[i].level < 800) {
					color(14);
					cout << "  出神入化" << endl;
					color(16);
				} else if (mybasicskill[i].level < 900) {
					color(12);
					cout << "  旷古绝伦" << endl;
					color(16);
				} else if (mybasicskill[i].level < 1000) {
					color(12);
					cout << "  绝世高深" << endl;
					color(16);
				} else {
					color(12);
					cout << "  返璞归真" << endl;
					color(16);
				}
			}
			for (int i = 0; i < 100; i++) {
				if (myskill[i].name == "") {
					break;
				}
				cout << myskill[i].name;
				for (int j = 0; j < (20 - myskill[i].name.size()); j++) {
					cout << " ";
				}
				cout << myskill[i].level;
				if (myskill[i].level < 100) {
					color(2);
					cout << "  初学乍练" << endl;
					color(16);
				} else if (myskill[i].level < 200) {
					color(2);
					cout << "  略知一二" << endl;
					color(16);
				} else if (myskill[i].level < 300) {
					color(9);
					cout << "  半生不熟" << endl;
					color(16);
				} else if (myskill[i].level < 400) {
					color(9);
					cout << "  平淡无奇" << endl;
					color(16);
				} else if (myskill[i].level < 500) {
					color(9);
					cout << "  心神领会" << endl;
					color(16);
				} else if (myskill[i].level < 600) {
					color(14);
					cout << "  熟能生巧" << endl;
					color(16);
				} else if (myskill[i].level < 700) {
					color(14);
					cout << "  高深莫测" << endl;
					color(16);
				} else if (myskill[i].level < 800) {
					color(14);
					cout << "  出神入化" << endl;
					color(16);
				} else if (myskill[i].level < 900) {
					color(12);
					cout << "  旷古绝伦" << endl;
					color(16);
				} else if (myskill[i].level < 1000) {
					color(12);
					cout << "  绝世高深" << endl;
					color(16);
				} else {
					color(12);
					cout << "  返璞归真" << endl;
					color(16);
				}
			}
        }
};

class WieldAction: public Action{
    public:
        void runMe(){
            string weapon;
			cin >> weapon;
			bool isweapon = false;
			if (nweapon.name == "拳") {
				for (int i = 0; i < 1000; i++) {
					if (userInfo.bag[i].name == weapon || userInfo.bag[i].Englishname == weapon) {
						isweapon = true;
						cout << "你「刷」的抽出一把";
						color(userInfo.bag[i].lv);
						cout << userInfo.bag[i].name;
						color(16);
						cout << "拿在手上" << endl;
						nweapon = userInfo.bag[i];
						userInfo.health += userInfo.bag[i].plushealth;
						userInfo.maxhealth += userInfo.bag[i].plushealth;
						userInfo.damage += userInfo.bag[i].plusdamage;
						userInfo.defense += userInfo.bag[i].plusdefense;
						userInfo.force += userInfo.bag[i].plusforce;
						userInfo.maxforce += userInfo.bag[i].plusforce;
						userInfo.dodge += userInfo.bag[i].plusdodge;
						userInfo.hit += userInfo.bag[i].plushit;
						break;
					}
				}
				if (!isweapon) {
					cout << "你没有这个武器。" << endl;
				}
			} else {
				cout << "你已经装备着" << nweapon.type << "了" << endl;
			}
        }
};

class UnwieldAction: public Action{
    public:
        void runMe(){
           string weapon;
			cin >> weapon;
			if (nweapon.name != "拳") {
				if (nweapon.name == weapon || nweapon.Englishname == weapon) {
					cout << "你把";
					color(nweapon.lv);
					cout << nweapon.name;
					color(16);
					cout << "放回背包" << endl;
					userInfo.health -= nweapon.plushealth;
					userInfo.maxhealth -= nweapon.plushealth;
					userInfo.damage -= nweapon.plusdamage;
					userInfo.defense -= nweapon.plusdefense;
					userInfo.force -= nweapon.plusforce;
					userInfo.maxforce -= nweapon.plusforce;
					userInfo.dodge -= nweapon.plusdodge;
					userInfo.hit -= nweapon.plushit;
					nweapon = { "拳","fist","拳","这是一个拳",0,0,0,0,0,0,16 };
				} else {
					cout << "你没有装备着" << weapon << "啊" << endl;
				}
			} else {
				cout << "你没有装备着任何武器啊" << endl;
			} 
        }
};

class StudyAction: public Action{
    public:
        void runMe(){
            string book;
			int time;
			cin >> book;
			cin >> time;
			bool is = false;
			for (int i = 0; i < 200; i++) {
				if (userInfo.bag2[i].name == book || userInfo.bag2[i].Englishname == book) {
					if (userInfo.bag2[i].literate_need > userInfo.literate) {
						cout << "你看着书上那些文字，发现自己一点也读不懂" << endl;
						break;
					}
					if (userInfo.bag2[i].name[0] == -69 && userInfo.bag2[i].name[1] == -7) {
						for (int j = 0; j < 9; j++) {
							if (userInfo.bag2[i].skill.name == mybasicskill[j].name) {
								for (int k = 0; k < time; k++) {
									if (userInfo.potential >= mybasicskill[j].level / 2) {
										userInfo.potential -= mybasicskill[j].level / 2;
										mybasicskill[j].level++;
										userInfo.damage += mybasicskill[j].plusattack;
										userInfo.dodge += mybasicskill[j].plusdodge;
										userInfo.hit += mybasicskill[j].plushit;
										userInfo.maxhealth += mybasicskill[j].plushealth;
										userInfo.health += mybasicskill[j].plushealth;
										userInfo.force += mybasicskill[j].plusforce;
										userInfo.maxforce += mybasicskill[j].plusforce;
										cout << "你";
										color(4);
										cout << mybasicskill[j].name;
										color(16);
										cout << "的等级提升了！" << endl;
										userInfo.allskilllevel++;
									} else {
										cout << "可能是你缺乏实战经验，你实在理解不了" << userInfo.bag2[i].name << "上所讲的东西"
											<< endl;
										break;
									}
								}
							}
						}
						is = true;
						break;
					} else {
						for (int j = 0; j < time; j++) {
							bool have = false;
							bool canstudy = true;
							for (int k = 0; k < userInfo.myskilli; k++) {
								if (userInfo.bag2[i].skill.name == myskill[k].name) {
									canstudy = (userInfo.potential >= myskill[k].level);
									for (int a = 0; a < 100; a++) {
										if (userInfo.bag2[i].needskill[a] == "") {
											break;
										} else {
											bool ishave = false;
											for (int b = 0; b < 100; b++) {
												if (userInfo.bag2[i].needskill[a] == myskill[b].name) {
													ishave = true;
													canstudy &= (userInfo.bag2[i].needlevel[a] <= myskill[b].level);
													break;
												}
											}
											for (int b = 0; b < 100; b++) {
												if (userInfo.bag2[i].needskill[a] == mybasicskill[b].name) {
													ishave = true;
													canstudy &= (userInfo.bag2[i].needlevel[a] <= mybasicskill[b].level);
													break;
												}
											}
											canstudy &= ishave;
										}
									}
									if (canstudy) {
										userInfo.potential -= myskill[k].level;
										myskill[k].level++;
										userInfo.damage += myskill[k].plusattack;
										userInfo.dodge += myskill[k].plusdodge;
										userInfo.hit += myskill[k].plushit;
										userInfo.maxhealth += myskill[k].plushealth;
										userInfo.health += myskill[k].plushealth;
										userInfo.maxforce += myskill[k].plusforce;
										userInfo.force += myskill[k].plusforce;
										cout << "你";
										color(4);
										cout << myskill[k].name;
										color(16);
										cout << "的等级提升了！" << endl;
										userInfo.allskilllevel++;
										if (userInfo.bag2[i].skill.name == "「反弹剑法」") {
											userInfo.reboundnum += 1;
										}
									} else {
										cout << "可能是缺乏实战经验，你实在理解不了" << userInfo.bag2[i].name << "上所讲的东西"
											<< endl;
									}
									have = true;
									break;
								}
							}
							if (!canstudy) {
								break;
							}
							if (!have) {
								myskill[userInfo.myskilli++] = userInfo.bag2[i].skill;
								if (userInfo.bag2[i].skill.name == "「反弹剑法」") {
									userInfo.isrebound = true;
									userInfo.reboundnum = 10;
								}
								cout << "你";
								color(4);
								cout << userInfo.bag2[i].skill.name;
								color(16);
								cout << "的等级提升了！" << endl;
								userInfo.allskilllevel++;
							}
						}
						is = true;
						break;
					}
				}
			}
			if (!is) {
				cout << "你要读什么书？" << endl;
				cout << "指令格式:study <书> <次数>" << endl;
			}
        }
};

class SayAction: public Action{
    public:
        void runMe(){
            string say;
			cin >> say;
			cout << "你说：“";
			color(8);
			cout << say;
			color(16);
			cout << "”" << endl;
        }
};

class YellAction: public Action{
    public:
        void runMe(){
            string yell;
			cin >> yell;
			cout << "你大喊：“";
			color(4);
			cout << yell;
			color(16);
			cout << "”" << endl;
			if (yell == "我太难了！" || yell == "我太难了。" || yell == "我太难了") {
				sleep(1);
				color(6);
				cout << "天下掉下来一本武功秘籍..." << endl;
				color(16);
				color(6);
				cout << "【东拉西扯】某人：听说有一本武功秘籍掉在了" << userInfo.inroom.name << "" <<
					endl;
				color(16);
				for (int i = 0; i < 100; i++) {
					if (userInfo.inroom.book[i].name == "") {
						userInfo.inroom.book[i] = { "绝世武功秘籍","book",{"绝世武功","你拿起手中w胡乱舞几招，再一看，e已经死了...","kongfu",2000000000,1,"剑",0,0,0,10000000,0,1,0,0,true,0},0,{},{},"神：现在不难了吧...",0 };
						break;
					}
				}
			}
			if (yell == "我想死！" || yell == "我想死。" || yell == "我想死") {
				color(6);
				cout << "天上传来一个沉闷的声音：“那就死吧！”" << endl;
				color(16);
				userInfo.health = 0;
			}
        }
};

class BuryAction: public Action{
    public:
        void runMe(){
           string a;
			cin >> a;
			if (a == "allcorpse") {
				bool ishave = false;
				for (int i = 0; i < 100; i++) {
					if (userInfo.inroom.thing[i].Englishname == "corpse") {
						cout << "你埋葬了" << userInfo.inroom.thing[i].name << endl;
						userInfo.inroom.thing[i] = {};
						room[userInfo.nowroomi].thing[i] = {};
						ishave = true;
					}
				}
				if (!ishave) {
					cout << "这里没有尸体啊？";
				}
			} else if (a == "corpse") {
				bool ishave = false;
				for (int i = 0; i < 100; i++) {
					if (userInfo.inroom.thing[i].Englishname == "corpse") {
						cout << "你埋葬了" << userInfo.inroom.thing[i].name << endl;
						userInfo.inroom.thing[i] = {};
						room[userInfo.nowroomi].thing[i] = {};
						ishave = true;
						break;
					}
				}
				if (!ishave) {
					cout << "这里没有尸体啊？";
				}
			} else {
				cout << "什么？" << endl;
				cout << "如果你不知道指令，请输入 help 查询" << endl;
			} 
        }
};

class SetAction: public Action{
    public:
        void runMe(string _which){
			string what;
			if (_which == "?") {
				cout << "set <...> to <...>" << endl;
				cout << "现在可以设置指针(pointer)就是这个：" << endl;
				cout << "↓" << endl;
				cout << ">set ?" << endl;
			} else {
				cin >> what >> what;
				if (_which == "pointer") {
					po = what;
					color(6);
					cout << "设置成功..." << endl;
					color(16);
				}
			}
        }
};

class SellAction: public Action{
    public:
        void runMe(){
            string thing;
			cin >> thing;
			bool issell = false;
			if (userInfo.inroom.isshop == true) {
				for (int i = 0; i < 200; i++) {
					if (userInfo.bag[i].Englishname == thing || userInfo.bag[i].name == thing) {
						cout << "你买掉了";
						color(8);
						cout << userInfo.bag[i].name;
						color(16);
						cout << ",获得了";
						color(6);
						cout << userInfo.bag[i].coin / 2;
						color(16);
						cout << "个铜钱" << endl;
						userInfo.coin += userInfo.bag[i].coin / 2;
						userInfo.bag[i] = {};
						issell = true;
						break;
					}
				}
				if (!issell) {
					for (int i = 0; i < 200; i++) {
						if (userInfo.bag2[i].Englishname == thing || userInfo.bag2[i].name == thing) {
							cout << "你买掉了";
							color(8);
							cout << userInfo.bag2[i].name;
							color(16);
							cout << ",获得了";
							color(6);
							cout << userInfo.bag2[i].coin / 2;
							color(16);
							cout << "个铜钱" << endl;
							userInfo.coin += userInfo.bag2[i].coin / 2;
							userInfo.bag2[i] = {};
							issell = true;
							break;
						}
					}
				}
				if (!issell) {
					for (int i = 0; i < 200; i++) {
						if (userInfo.bag3[i].Englishname == thing || userInfo.bag3[i].name == thing) {
							cout << "你买掉了";
							color(8);
							cout << userInfo.bag3[i].name;
							color(16);
							cout << ",获得了";
							color(6);
							cout << userInfo.bag3[i].coin / 2;
							color(16);
							cout << "个铜钱" << endl;
							userInfo.coin += userInfo.bag3[i].coin / 2;
							userInfo.bag3[i] = {};
							issell = true;
							break;
						}
					}
				}
				if (!issell) {
					cout << "你没有这东西啊" << endl;
				}
			} else {
				cout << "这里不是商店啊？" << endl;
			}
        }
};

class ListAction: public Action{
    public:
        void runMe(){
            if (userInfo.inroom.isshop == false) {
				cout << "这里没有任何摆摊的商人" << endl;
			} else {
				cout << "这里现在出售以下物品：" << endl;
				cout << "_________________________" << endl;
				for (int i = 0; i < 100; i++) {
					if (userInfo.inroom.booksell[i].name != "") {
						cout << userInfo.inroom.booksell[i].name << "(";
						color(3);
						cout << userInfo.inroom.booksell[i].Englishname;
						color(16);
						cout << ")";
						for (int j = 0;
							j < 28 - userInfo.inroom.booksell[i].name.size() - userInfo.inroom.booksell[i].Englishname.size();
							j++) {
							cout << " ";
						}
						color(6);
						cout << userInfo.inroom.booksell[i].coin;
						color(16);
						cout << "文" << endl;
					}
				}
				for (int i = 0; i < 100; i++) {
					if (userInfo.inroom.thingsell[i].name != "") {
						cout << userInfo.inroom.thingsell[i].name << "(";
						color(3);
						cout << userInfo.inroom.thingsell[i].Englishname;
						color(16);
						cout << ")";
						for (int j = 0;
							j < 28 - userInfo.inroom.thingsell[i].name.size() -
							userInfo.inroom.thingsell[i].Englishname.size(); j++) {
							cout << " ";
						}
						color(6);
						cout << userInfo.inroom.thingsell[i].coin;
						color(16);
						cout << "文" << endl;
					}
				}
				for (int i = 0; i < 100; i++) {
					if (userInfo.inroom.weaponsell[i].name != "") {
						cout << userInfo.inroom.weaponsell[i].name << "(";
						color(3);
						cout << userInfo.inroom.weaponsell[i].Englishname;
						color(16);
						cout << ")";
						for (int j = 0;
							j < 28 - userInfo.inroom.weaponsell[i].name.size() -
							userInfo.inroom.weaponsell[i].Englishname.size(); j++) {
							cout << " ";
						}
						color(6);
						cout << userInfo.inroom.weaponsell[i].coin;
						color(16);
						cout << "文" << endl;
					}
				}
				cout << "_________________________" << endl;
			}
        }
};

class BuyAction: public Action{
    public:
        void runMe(){
            string thing;
			cin >> thing;
			bool isfind = false;
			for (int i = 0; i < 100; i++) {
				if (thing == userInfo.inroom.weaponsell[i].Englishname
					|| thing == userInfo.inroom.weaponsell[i].name) {
					if (userInfo.gold * 10000 + userInfo.silver * 100 + userInfo.coin < userInfo.inroom.weaponsell[i].coin) {
						cout << "你的钱不够" << endl;
					} else {
						cout << "你买下了" << userInfo.inroom.weaponsell[i].name << endl;
						userInfo.coin = userInfo.gold * 10000 + userInfo.silver * 100 + userInfo.coin;
						userInfo.gold = 0;
						userInfo.silver = 0;
						userInfo.coin -= userInfo.inroom.weaponsell[i].coin;
						for (int j = 0; j < 200; j++) {
							if (userInfo.bag[j].name == "") {
								userInfo.bag[j] = userInfo.inroom.weaponsell[i];
								break;
							}
						}
					}
					isfind = true;
					break;
				}
			}
			for (int i = 0; i < 100; i++) {
				if (thing == userInfo.inroom.booksell[i].Englishname
					|| thing == userInfo.inroom.booksell[i].name) {
					if (userInfo.gold * 10000 + userInfo.silver * 100 + userInfo.coin < userInfo.inroom.booksell[i].coin) {
						cout << "你的钱不够" << endl;
					} else {
						cout << "你买下了" << userInfo.inroom.booksell[i].name << endl;
						userInfo.coin = userInfo.gold * 10000 + userInfo.silver * 100 + userInfo.coin;
						userInfo.gold = 0;
						userInfo.silver = 0;
						userInfo.coin -= userInfo.inroom.booksell[i].coin;
						for (int j = 0; j < 200; j++) {
							if (userInfo.bag2[j].name == "") {
								userInfo.bag2[j] = userInfo.inroom.booksell[i];
								break;
							}
						}
					}
					isfind = true;
					break;
				}
			}
			for (int i = 0; i < 100; i++) {
				if (thing == userInfo.inroom.thingsell[i].Englishname
					|| thing == userInfo.inroom.thingsell[i].name) {
					if(userInfo.gold * 10000 + userInfo.silver * 100 + userInfo.coin < userInfo.inroom.thingsell[i].coin) {
						cout << "你的钱不够" << endl;
					} else {
						cout << "你买下了" << userInfo.inroom.thingsell[i].name << endl;
						userInfo.coin = userInfo.gold * 10000 + userInfo.silver * 100 + userInfo.coin;
						userInfo.gold = 0;
						userInfo.silver = 0;
						userInfo.coin -= userInfo.inroom.thingsell[i].coin;
						for (int j = 0; j < 200; j++) {
							if (userInfo.bag3[j].name == "") {
								userInfo.bag3[j] = userInfo.inroom.thingsell[i];
								break;
							}
						}
					}
					isfind = true;
					break;
				}
			}
			if (!isfind) {
				cout << "这里不卖这样东西" << endl;
			}
        }
};

class FightAction: public Action{
	public:
		void runMe(){
			string name;
			cin >> name;
			bool is = false;
			for (int i = 0; i < 100; i++) {
				if (inroom.people[i].name == name || inroom.people[i].Englishname == name) {
					x[0] = inroom.people[i];
					y[0] = i;
					fightall(x, 1, y);
					is = true;
					break;
				}
			}
			if (!is) {
				cout << "你要击杀谁？" << endl;
				cout << "指令格式：kill <某人>" << endl;
			}
		}
};

class FightAllAction: public Action{
	public:
		void runMe(){
			string name;
			int many;
			cin >> many;
			int num = 0;
			bool is = false;
			for (int i = 0; i < many; i++) {
				cin >> name;
				for (int j = 0; j < 100; j++) {
					if (inroom.people[j].name == name || inroom.people[j].Englishname == name) {
						x[num] = inroom.people[j];
						y[num] = j;
						num++;
						is = true;
						break;
					}
				}
			}
			if (!is) {
				cout << "你要击杀谁？" << endl;
				cout << "指令格式：kill <某人>" << endl;
			} else {
				fightall(x, num, y);
			}
		}
};
class AboutGameAction: public Action{
	public:
		void runMe(){
			color(4);
			cout << "-========================================================" << endl;
			color(16);
			cout << "|版本:" << edition << "无存档" << endl;
			cout << "|作者:Evan_song" << endl;
			cout << "|游戏特色：模仿武林，可以创建各门派，拜师学武" << endl;
			cout << "|本版本修复了战斗BUG，新增人物自动走动" << endl;
			cout << "|本游戏正处于游玩版中" << endl;
			color(4);
			cout << "-========================================================" << endl;
			color(16);
		}
};
class SaveAction: public Action{
	public:
		void runMe(){
			cout << "本版本是无存档游玩版..." << endl;
		}
};
class GotoAction: public Action{
	public:
		void runMe(){
			if (IDEN == "wizard-1" || IDEN == "wizard-2" || IDEN == "wizard-3"
				|| IDEN == "wizard-4" || IDEN == "wizard-5") {
				string w;
				bool is = false;
				cin >> w;
				for (int i = 0; i < 100; i++) {
					if (room[i].Englishname == w) {
						color(6);
						cout << "你化作长虹而去" << endl;
						color(16);
						nowroomi = i;
						inroom = room[i];
						outroom();
						color(6);
						cout << "你见到了地方，收起金光，稳稳地站在了地上" << endl;
						color(16);
						is = true;
						break;
					}
				}
				if (!is) {
					cout << "你要去哪里？" << endl;
					cout << "指令格式：goto <某地>" << endl;
				}
			} else {
				cout << "什么？" << endl;
			}	
		}
};
class SmashAction: public Action{
	public:
		void runMe(){
			if (IDEN == "wizard-2" || IDEN == "wizard-3" || IDEN == "wizard-4"
				|| IDEN == "wizard-5") {
				string w;
				bool is = false;
				cin >> w;
				for (int i = 0; i < 100; i++) {
					if (inroom.people[i].Englishname == w) {
						color(4);
						cout << "突然，乌云密布，天空中劈下一道闪电..." << endl;
						cout << "正中";
						color(6);
						cout << inroom.people[i].name << endl << inroom.people[i].name;
						color(4);
						cout << "大叫一声，口吐鲜血，倒在地上，死了！" << endl;
						color(16);
						make_corpse(inroom.people[i], inroom.people[i].weapon);
						break;
					}
				}
				if (!is) {
					cout << "你要劈谁？" << endl;
					cout << "指令格式：smash <某人>" << endl;
				}
			} else {
				cout << "什么？" << endl;
			}
		}
};
class LsAction: public Action{
	public:
		void runMe(){
			if (IDEN == "wizard-2" || IDEN == "wizard-3" || IDEN == "wizard-4"
				|| IDEN == "wizard-5") {
				cout << "屠龙刀(tulongdao) 倚天剑(yitianjian) 射日弓(sherigong)" << endl;
				cout << "战神弓(zhanshengong) 战神剑(zhanshengjian) 战神甲(zhanshenjia) 战神靴(zhanshenjian) 战神刀(zhanshendao)"
					<< endl;
				cout << "战神棍(zhanshengun) 战神鞭(zhanshenbian)" << endl;
				cout << "钢刀(blade) 剑(sword) 长剑(longsword) 凝碧剑(greensword) 斩铁刀(zhantiedao)"
					<< endl;
				cout << "齐眉棍(qimeigun) 打狗棍(dagougun)" << endl;
			} else {
				cout << "什么？" << endl;
			}
		}
};
class MakeWeaponAction: public Action{
	public:
		void runMe(){
			if (IDEN == "wizard-2" || IDEN == "wizard-3" || IDEN == "wizard-4"
				|| IDEN == "wizard-5") {
				int i;
				for (i = 0; i < 100; i++) {
					if (inroom.thing[i].name == "") {
						break;
					}
				}
				cout << "武器类型有：{剑，刀，鞭，棍，拳}" << endl;
				cout << "格式: make<名字><英文名><武器类型><武器描述><价格><攻击><增加生命><增加内力><增加防御><增加轻功><增加命中>"
					<< endl;
				cin >> inroom.weapon[i].name >> inroom.weapon[i].Englishname >>
					inroom.weapon[i].type >> inroom.weapon[i].tell >> inroom.weapon[i].coin >>
					inroom.weapon[i].plusdamage >> inroom.weapon[i].plushealth >>
					inroom.weapon[i].plusforce >> inroom.weapon[i].plusdefense >>
					inroom.weapon[i].plusdodge >> inroom.weapon[i].plushit;
				inroom.weapon[i].lv = 16;
				room[nowroomi].weapon[i] = inroom.weapon[i];
				color(6);
				cout << "创造成功。" << endl;
				color(16);
			} else {
				cout << "什么？" << endl;
			}
		}
};
class MakeThingAction: public Action{
	public:
		void runMe(){
			if (IDEN == "wizard-2" || IDEN == "wizard-3" || IDEN == "wizard-4"
				|| IDEN == "wizard-5") {
				int i;
				for (i = 0; i < 100; i++) {
					if (inroom.thing[i].name == "") {
						break;
					}
				}
				cout << "格式: make<名字><英文名><物品描述><价格>" << endl;
				cin >> inroom.thing[i].name >> inroom.thing[i].Englishname >>
					inroom.thing[i].tell >> inroom.thing[i].coin;
				room[nowroomi].thing[i] = inroom.thing[i];
				color(6);
				cout << "创造成功。" << endl;
				color(16);
			} else {
				cout << "什么？" << endl;
			}
		}
};
class MakeBookAction: public Action{
	public:
		void runMe(){
			if (IDEN == "wizard-2" || IDEN == "wizard-3" || IDEN == "wizard-4"
				|| IDEN == "wizard-5") {
				color(4);
				cout << "暂不支持创造书" << endl;
				color(16);
			} else {
				cout << "什么？" << endl;
			}
		}
};
class CallAction: public Action{
	public:
		void runMe(){
			if (IDEN == "wizard-3" || IDEN == "wizard-4" || IDEN == "wizard-5") {
				string who;
				int value;
				string setwhat;
				cin >> who >> setwhat >> value;
				if (myEnglishname == who) {
					if (setwhat == "sethealth") {
						health = value;
						if (health > maxhealth) {
							maxhealth = health;
						}
						color(4);
						cout << "设置成功" << endl;
						color(16);
					} else if (setwhat == "setdamage") {
						damage = value;
						color(4);
						cout << "设置成功" << endl;
						color(16);
					} else if (setwhat == "setforce") {
						force = value;
						if (force > maxforce) {
							maxforce = force;
						}
						color(4);
						cout << "设置成功" << endl;
						color(16);
					} else if (setwhat == "setdefense") {
						defense = value;
						color(4);
						cout << "设置成功" << endl;
						color(16);
					} else if (setwhat == "setdodge") {
						dodge = value;
						color(4);
						cout << "设置成功" << endl;
						color(16);
					} else if (setwhat == "sethit") {
						hit = value;
						color(4);
						cout << "设置成功" << endl;
						color(16);
					} else if (setwhat == "setpotential") {
						potential = value;
						color(4);
						cout << "设置成功" << endl;
						color(16);
					} else {
						cout << "输入错误";
					}
				} else {
					bool isfind = false;
					for (int i = 0; i < 100; i++) {
						if (inroom.people[i].name == who) {
							isfind = true;
							if (setwhat == "sethealth") {
								inroom.people[i].health = value;
								room[nowroomi].people[i].health = value;
								if (inroom.people[i].health > inroom.people[i].maxhealth) {
									inroom.people[i].maxhealth = inroom.people[i].health;
									room[nowroomi].people[i].maxhealth = room[nowroomi].people[i].health;
								}
								color(4);
								cout << "设置成功" << endl;
								color(16);
							} else if (setwhat == "setdamage") {
								inroom.people[i].damage = value;
								room[nowroomi].people[i].damage = value;
								color(4);
								cout << "设置成功" << endl;
								color(16);
							} else if (setwhat == "setforce") {
								inroom.people[i].force = value;
								room[nowroomi].people[i].force = value;
								if (inroom.people[i].force > inroom.people[i].maxforce) {
									inroom.people[i].maxforce = inroom.people[i].force;
									room[nowroomi].people[i].force = room[nowroomi].people[i].force;
								}
								color(4);
								cout << "设置成功" << endl;
								color(16);
							} else if (setwhat == "setdefense") {
								inroom.people[i].defense = value;
								room[nowroomi].people[i].defense = value;
								color(4);
								cout << "设置成功" << endl;
								color(16);
							} else if (setwhat == "setdodge") {
								inroom.people[i].dodge = value;
								room[nowroomi].people[i].dodge = value;
								color(4);
								cout << "设置成功" << endl;
								color(16);
							} else if (setwhat == "sethit") {
								inroom.people[i].hit = value;
								room[nowroomi].people[i].hit = value;
								color(4);
								cout << "设置成功" << endl;
								color(16);
							} else {
								cout << "输入错误";
							}
							break;
						}
					}
					if (!isfind) {
						cout << "你要设谁？" << endl;
					}
				}
			} else {
				cout << "什么？" << endl;
			}
		}
};
class CloneAction: public Action{
	public:
		void runMe(){
			if (IDEN == "wizard-2" || IDEN == "wizard-3" || IDEN == "wizard-4"
				|| IDEN == "wizard-5") {
				string what;
				cin >> what;
				bool isfind = false;
				for (int i = 0; i < 100; i++) {
					if (inroom.weapon[i].Englishname == what) {
						isfind = true;
						for (int j = 0; j < 100; j++) {
							if (inroom.weapon[j].name == "") {
								inroom.weapon[j] = inroom.weapon[i];
								room[nowroomi].weapon[j] = inroom.weapon[i];
								color(6);
								cout << inroom.weapon[j].name << "克隆成功！" << endl;
								color(16);
								break;
							}
						}
						break;
					}
				}
				if (!isfind) {
					for (int i = 0; i < 100; i++) {
						if (inroom.thing[i].Englishname == what) {
							isfind = true;
							for (int j = 0; j < 100; j++) {
								if (inroom.thing[j].name == "") {
									inroom.thing[j] = inroom.thing[i];
									room[nowroomi].thing[j] = inroom.thing[i];
									color(6);
									cout << inroom.thing[j].name << "克隆成功！" << endl;
									color(16);
									break;
								}
							}
							break;
						}
					}
				}
				if (!isfind) {
					for (int i = 0; i < 100; i++) {
						if (inroom.book[i].Englishname == what) {
							isfind = true;
							for (int j = 0; j < 100; j++) {
								if (inroom.book[j].name == "") {
									inroom.book[j] = inroom.book[i];
									room[nowroomi].book[j] = inroom.book[i];
									color(6);
									cout << inroom.book[j].name << "克隆成功！" << endl;
									color(16);
									break;
								}
							}
							break;
						}
					}
				}
				if (!isfind) {
					for (int i = 0; i < 100; i++) {
						if (inroom.people[i].Englishname == what) {
							isfind = true;
							for (int j = 0; j < 100; j++) {
								if (inroom.people[j].name == "") {
									inroom.people[j] = inroom.people[i];
									room[nowroomi].people[j] = inroom.people[i];
									color(6);
									cout << inroom.people[j].name << "克隆成功！" << endl;
									color(16);
									break;
								}
							}
							break;
						}
					}
				}
				if (!isfind) {
					cout << "没有这样东西" << endl;
				}
			} else {
				cout << "什么？" << endl;
			}
		}
};
class ThrowAction: public Action{
	public:
		void runMe(){
			string thing;
			cin >> thing;
			string who;
			cin >> who >> who;
			bool isthing = false, ispeople = false;
			for (int i = 0; i < 100; i++) {
				if (bag3[i].Englishname == thing) {
					isthing = true;
					for (int j = 0; j < 100; j++) {
						if (inroom.people[j].Englishname == who) {
							ispeople = true;
							if (rand() % 10000 >= inroom.people[j].dodge - hit) {
								cout << "你的" << bag3[i].name << "正中" << inroom.people[j].name << "的头！" <<
									endl;
								inroom.people[j].health -= rand() % 1000 + 200;
								room[nowroomi].people[j].health = inroom.people[j].health;
								if (inroom.people[j].health < 1) {
									cout << inroom.people[j].name << "大叫一声，倒在地上，死了" << endl;
									make_corpse(inroom.people[j], inroom.people[j].weapon);
								} else {
									cout << inroom.people[j].name << "看起来想要杀了你！" << endl;
									x[0] = inroom.people[j];
									y[0] = j;
									killall(x, 1, y);
								}
							} else {
								cout << "对方轻轻一跳，躲了过去" << endl;
								cout << inroom.people[j].name << "看起来想要杀了你！" << endl;
								x[0] = inroom.people[j];
								y[0] = j;
								killall(x, 1, y);
							}
							break;
						}
					}
					break;
				}
			}
			if (!isthing) {
				cout << "没有这个东西" << endl;
			} else if (!ispeople) {
				cout << "没有这个人" << endl;
			}
		}
};
class ConjureAction: public Action{
	public:
		void runMe(){
			string which;
			cin >> which;
			map<string, we>::iterator it = weap.find(which);
			if (it != weap.end()) {
				for (int i = 0; i < 100; i++) {
					if (inroom.weapon[i].name == "") {
						inroom.weapon[i] = it->second;
						color(6);
						cout << "只见" << myname << "挥手一指，凭空变出一个" << it->second.name << endl;
						color(16);
						break;
					}
				}
			} else {
				cout << "没有这个武器" << endl;
			}
		}
};
class EnableAction: public Action{
	public:
		void runMe(){
			string whichskill;
			cin >> whichskill;
			bool isfind = false;
			for (int i = 0; i < 100; i++) {
				if (myskill[i].Englishname == whichskill) {
					isfind = true;
					if (myskill[i].isattack == true) {
						cout << "你要enable的技能不是轻功技能" << endl;
					} else {
						cout << "你打算使用" << myskill[i].name << "作为战斗时使用的轻功" << endl;
						nowdodgeskill = myskill[i];
					}
				}
			}
			if (!isfind) {
				cout << "没有这种技能" << endl;
			}
		}
};
class ScoreAction: public Action{
	public:
		void runMe(){
			if (IDEN == "wizard-2" || IDEN == "wizard-3" || IDEN == "wizard-4"
				|| IDEN == "wizard-5") {
				string who;
				cin >> who;
				bool isfind = false;
				for (int i = 0; i < 100; i++) {
					if (inroom.people[i].Englishname == who) {
						isfind = true;
						cout << "攻击:";
						color(4);
						cout << inroom.people[i].damage << endl;
						color(16);
						cout << "防御:";
						color(14);
						cout << inroom.people[i].defense << endl;
						color(16);
						cout << "生命:";
						if (inroom.people[i].health > inroom.people[i].maxhealth / 6 * 5) color(10);
						else if (inroom.people[i].health > inroom.people[i].maxhealth / 6 * 4) color(
							14);
						else if (inroom.people[i].health > inroom.people[i].maxhealth / 6 * 3) color(
							14);
						else if (inroom.people[i].health > inroom.people[i].maxhealth / 6 * 2) color(
							12);
						else if (inroom.people[i].health > inroom.people[i].maxhealth / 6) color(12);
						else color(4);
						cout << inroom.people[i].health;
						color(16);
						cout << "/";
						color(10);
						cout << inroom.people[i].maxhealth << endl;
						color(16);
						cout << "内功:";
						if (inroom.people[i].force > inroom.people[i].maxforce / 6 * 5) color(10);
						else if (inroom.people[i].force > inroom.people[i].maxforce / 6 * 4) color(14);
						else if (inroom.people[i].force > inroom.people[i].maxforce / 6 * 3) color(14);
						else if (inroom.people[i].force > inroom.people[i].maxforce / 6 * 2) color(12);
						else if (inroom.people[i].force > inroom.people[i].maxforce / 6) color(12);
						else color(4);
						cout << inroom.people[i].force;
						color(16);
						cout << "/";
						color(10);
						cout << inroom.people[i].maxforce << endl;
						color(16);
						cout << "命中:";
						cout << inroom.people[i].hit << endl;
						color(16);
						cout << "躲避:";
						color(10);
						cout << inroom.people[i].dodge << endl;
						color(16);
						break;
					}
				}
				if (!isfind) {
					cout << "没有这个人" << endl;
				}
			}
		}
};
class MenpaiAction: public Action{
	public:
		void runMe(){
			color(4);
			cout << "正派";
			color(16);
			cout << ":";
			color(8);
			cout << "武当，丐帮，少林" << endl;
			color(1);
			cout << "中立";
			color(16);
			cout << ":";
			color(8);
			cout << "道家，铸剑山庄，空桑派，小学生帮，初中会，大学派" << endl;
			color(5);
			cout << "邪教";
			color(16);
			cout << ":";
			color(8);
			cout << "古墓，灵鹫宫，神龙教" << endl;
			color(11);
			cout << "要拜师，请输入：bai<门派中文名>" << endl;
			color(16);
		}
};
class BaiAction: public Action{
	public:
		void runMe(){
			string men;
			cin >> men;
			if (men != "武当" && men != "丐帮" && men != "少林" && men != "道家"
				&& men != "铸剑山庄" && men != "空桑派" && men != "古墓" && men != "灵鹫宫"
				&& men != "神龙教") {
				cout << "没有这个门派" << endl << endl;
				color(4);
				cout << "正派";
				color(16);
				cout << ":";
				color(8);
				cout << "武当，丐帮，少林" << endl << endl;
				color(1);
				cout << "中立";
				color(16);
				cout << ":";
				color(8);
				cout << "道家，铸剑山庄，空桑派" << endl << endl;
				color(5);
				cout << "邪教";
				color(16);
				cout << ":";
				color(8);
				cout << "古墓，灵鹫宫，神龙教" << endl;
			} else if (!baishi) {
				cout << men << "：嗯，欢迎你加入。" << endl;
				cout << "你成功拜入" << men << endl;
				mymenpai = men;
				if (mymenpai == "武当") {
					inroom = room[26];
					nowroomi = 26;
					outroom();
				}
				if (mymenpai == "丐帮") {
					inroom = room[27];
					nowroomi = 27;
					outroom();
				}
				if (mymenpai == "铸剑山庄") {
					inroom = room[41];
					nowroomi = 41;
					outroom();
				}
				if (mymenpai == "道家") {
					inroom = room[43];
					nowroomi = 43;
					outroom();
				}
				baishi = true;
			} else {
				cout << "你已经是" << mymenpai << "的学生了" << endl;
			}
		}
};
class DazuoAction: public Action{
	public:
		void runMe(){
			int time;
			cin >> time;
			color(8);
			cout << "你盘腿坐下，静下心来，开始打坐..." << endl;
			color(16);
			for (int i = 0; i < time; i++) {
				sleep(3);
				if (force < maxforce) {
					if (force + 100 > maxforce) {
						cout << "你的内力补充了";
						color(10);
						cout << maxforce - force;
						color(16);
						cout << "点" << endl;
						force = maxforce;
						color(1);
						cout << "内力补充完毕" << endl;
						color(16);
					} else {
						cout << "你的内力补充了";
						color(10);
						cout << "100";
						color(16);
						cout << "点" << endl;
						force += 100;
					}
				} else {
					cout << "你的最大内力提升了";
					color(6);
					cout << "10";
					color(16);
					cout << "点" << endl;
					cout << "你的内力提升了";
					color(6);
					cout << "10";
					color(16);
					cout << "点" << endl;
					maxforce += 10;
					force += 10;
				}
			}
			color(8);
			cout << "你站了起来，准备去别的地方。" << endl;
			color(16);
		}
};
class LiaoShangAction: public Action{
	public:
		void runMe(){
			color(8);
			cout << "你盘腿坐下，开始医疗伤口..." << endl;
			color(16);
			while (1) {
				sleep(3);
				if (health + 100 > maxhealth) {
					cout << "你的气血恢复了";
					color(10);
					cout << maxhealth - health;
					color(16);
					cout << "点" << endl;
					health = maxhealth;
					color(1);
					cout << "气血恢复完毕" << endl;
					color(16);
					break;
				} else {
					cout << "你的气血恢复了";
					color(10);
					cout << "100";
					color(16);
					cout << "点" << endl;
					health += 100;
				}
			}
			color(8);
			cout << "你站了起来，准备去别的地方。" << endl;
			color(16);
		}
};


LookAction lookAction;
KillAction killAction;
KillAllAction killAllAction;
IdentityAction identityAction;
MoveAction moveAction;
GetAction getAction;
DropAction dropAction;
HelpAction helpAction;
HPAction hpAction;
SkillsAction skillsAction;
WieldAction wieldAction;
UnwieldAction unwieldAction;
StudyAction studyAction;
SayAction sayAction;
YellAction yellAction;
BuryAction buryAction;
SetAction setAction;
SellAction sellAction;
ListAction listAction;
BuyAction buyAction;
FightAction fightAction;
FightAllAction fightAllAction;
AboutGameAction aboutGameAction;
SaveAction saveAction; 
GotoAction gotoAction;
SmashAction smashAction;
LsAction lsAction;
MakeWeaponAction makeWeaponAction;
MakeThingAction makeThingAction;
MakeBookAction makeBookAction;

