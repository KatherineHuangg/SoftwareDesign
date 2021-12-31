#include<room.h>

class UserInfo{
    public:
        int health=1000,maxhealth=1000,damage=100,defense=20,force=100,maxforce=100,dodge=10,hit=10;
        string myEnglishname,myname,IDEN,mymenpai="你还未拜师或创建门派",myshifu = "你还未拜师...";
        int dienum=0,nowroomi=0;
        bool baishi=false;
        ro inroom;//in which room
        pe x[100];
        we bag[200];
        bo bag2[200];
        th bag3[200];
        int y[100];
        
        string title = "普通百姓", title2 = "", task = "";
        bool baishi, isrebound;//拜师,
        int reboundnum, titlecolor = 16, wudaotalevel = 1;
        int nowroomi = 0, experience = 0, potential = 0, literate = 0, dienum = 0,
        killnum = 0, buildlevel = 1;
        int coin = 0, silver = 0, gold = 0, buildexp = 0;
        int password;
        bool gift[100];
        bool ta[100];
        int myskilli = 0;
        int mixed[20][20];
        int allskilllevel = 0;

};