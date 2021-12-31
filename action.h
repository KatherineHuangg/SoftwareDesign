#include <iostream>

using namespace std;

class Action{

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
                    if (inroom.people[i].Englishname == name || inroom.people[i].name == name) {
                        color(12);
                        cout << inroom.people[i].name << endl;
                        color(16);
                        cout << inroom.people[i].tell << endl;
                        is = true;
                        break;
                    }
                }
                for (int i = 0; i < 100; i++) {
                    if (inroom.weapon[i].Englishname == name || inroom.weapon[i].name == name) {
                        color(inroom.weapon[i].lv);
                        cout << inroom.weapon[i].name << endl;
                        color(16);
                        if (inroom.weapon[i].type == "剑") {
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
                        if (inroom.weapon[i].type == "刀") {
                            color(6);
                            cout << "        ▲  " << endl;
                            cout << "◇████";
                            color(8);
                            cout << "〓〓〓〓〓〓〓◤" << endl;
                            color(6);
                            cout << "        ▼  " << endl;
                            color(16);
                        }
                        if (inroom.weapon[i].type == "鞭") {
                            color(6);
                            cout << "〓〓〓";
                            color(8);
                            cout << "=========---------" << endl;
                            color(16);
                        }
                        cout << inroom.weapon[i].tell << endl;
                        cout << "武器属性:" << endl;
                        cout << "攻击:" << inroom.weapon[i].plusdamage << endl;
                        cout << "防御:" << inroom.weapon[i].plusdefense << endl;
                        cout << "躲闪:" << inroom.weapon[i].plusdodge << endl;
                        cout << "内力:" << inroom.weapon[i].plusforce << endl;
                        cout << "生命:" << inroom.weapon[i].plushealth << endl;
                        cout << "命中:" << inroom.weapon[i].plushit << endl;
                        cout << "镶嵌宝石:" << endl;
                        if (inroom.weapon[i].inlaynum == 0) {
                            cout << "此武器无镶嵌空" << endl;
                        } else {
                            for (int j = 0; j < inroom.weapon[i].inlaynum; j++) {
                                if (inroom.weapon[i].inlaything[j].name == "") {
                                    cout << "◇" << endl;
                                } else {
                                    cout << "◆" << inroom.weapon[i].inlaything[j].name <<
                                        inroom.weapon[i].inlaything[j].coin << endl;
                                }
                            }
                        }
                        is = true;
                        break;
                    }
                }
                for (int i = 0; i < 100; i++) {
                    if (inroom.book[i].Englishname == name || inroom.book[i].name == name) {
                        color(12);
                        cout << inroom.book[i].name << endl;
                        color(16);
                        cout << inroom.book[i].tell << endl;
                        is = true;
                        break;
                    }
                }
                for (int i = 0; i < 100; i++) {
                    if (inroom.thing[i].Englishname == name || inroom.thing[i].name == name) {
                        color(12);
                        cout << inroom.thing[i].name << endl;
                        color(16);
                        cout << inroom.thing[i].tell << endl;
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
        string name;
        /*cin >> name;
        bool is = false;
        for (int i = 0; i < 100; i++) {
            if (inroom.people[i].name == name || inroom.people[i].Englishname == name) {
                x[0] = inroom.people[i];
                y[0] = i;
                killall(x, 1, y);
                is = true;
                break;
            }
        }
        if (!is) {
            cout << "你要击杀谁？" << endl;
            cout << "指令格式：kill <某人>" << endl;
        }*/
    
}