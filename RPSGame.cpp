#include <bits/stdc++.h>
using namespace std;
class Tool{
    int strength;
    char type;
    public: void settype(char type){this->type=type;}
            char gettype(){return this->type;}
            void setstrength(int strength){this->strength=strength;}
            int getstrength(){return this->strength;}
            virtual int fight(Tool){};
            ~Tool(){}
};
class Rock:public Tool{
    public:
    Rock(){setstrength(1);settype('r');}
    Rock(int strength){setstrength(strength);settype('r');}
    int fight(Tool t){
        if(t.gettype()=='s')this->setstrength(2*getstrength());
        else if(t.gettype()=='p')this->setstrength(0.5*getstrength());
        if(this->getstrength()>t.getstrength())return 1;
        else if(this->getstrength()<t.getstrength())return 2;
        else return 3;
        }
    ~Rock(){}
};
class Scissors:public Tool{
    public:
    Scissors(){setstrength(1);settype('s');}
    Scissors(int strength){setstrength(strength);settype('s');}
    int fight(Tool t){
        if(t.gettype()=='p')this->setstrength(2*getstrength());
        else if(t.gettype()=='r')this->setstrength(0.5*getstrength());
        if(this->getstrength()>t.getstrength())return 1;
        else if(this->getstrength()<t.getstrength())return 2;
        else return 3;
        }
    ~Scissors(){}
};
class Paper:public Tool{
    public:
    Paper(){setstrength(1);settype('p');}
    Paper(int strength){setstrength(strength);settype('p');}
    int fight(Tool t){
        if(t.gettype()=='r')this->setstrength(2*getstrength());
        else if(t.gettype()=='s')this->setstrength(0.5*getstrength());
        if(this->getstrength()>t.getstrength())return 1;
        else if(this->getstrength()<t.getstrength())return 2;
        else return 3;
        }
    ~Paper(){}
};

class RPSGame{
    public :
    Tool *tool1,*tool2;
    int computer_wins,human_wins,ties;
    RPSGame(){
    computer_wins=0;human_wins=0;ties=0;}
    void settool(char t1,char t2,int strength,int cstrength){
    if(t1=='r')
        tool1=new Rock(strength);
    else if(t1=='s')
        tool1=new Scissors(strength);
    else
        tool1=new Paper(strength);

    if(t2=='r')
        tool2=new Rock(cstrength);
    else if(t2=='s')
        tool2=new Scissors(cstrength);
    else
        tool2=new Paper(cstrength);
    }
    ~RPSGame()
    {
        cout<<"\nThanks for playing!\n";
        delete tool1;
        delete tool2;
    }
};
int main()
{
        RPSGame game;
        char choice,hchoice,choice_arr[3]={'r','p','s'},choice_arr2[3][20]={"rock","paper","scissors"};
        int cchoice,strength,cstrength;
        cout<<"Hello and welcome to the finals of the 37th edition of the rock-paper-scissors tournament. To signify the rapid rate at which AI is taking over our world, we are going to replace one of our finalists with his AI counterpart. Thank you.\n";
        cout<<"\nDo you want to choose different strengths for the tools because the normal version is too boring, and you're a 'rebel'?(y-yes n-no) (Note-Entering y will also randomize the computer's strength, so beware)\n";
        label1:
        cin>>choice;
        if(choice!='y' && choice!='n')
        {
            cout<<"Invalid choice, Enter y or n\n";
            goto label1;
        }
        do
        {
            label3:
            cout<<"Choose your tool (r-rock, p-paper, s-scissors, e-exit)\n";
            cin>>hchoice;
            if(hchoice!='r' &&hchoice!='p' && hchoice!='s' && hchoice!='e')
            {
                cout<<"Invalid choice, enter a valid choice\n";
                goto label3;
            }
            if(hchoice=='e')
                break;
            if(choice=='y')
            {
                label2:
                cout<<"Enter your preferred strength (1-5)\n";
                cin>>strength;
                if(strength<1 || strength>5)
                    {
                        cout<<"Invalid strength, enter a number between 1 and 5\n";
                        goto label2;
                    }
                    cstrength=rand()%5;
                    cout<<"Your strength is "<<strength<<"\nComputer's strength is "<<cstrength+1<<"\n\n";
            }
            else
            {
                strength=1;
                cstrength=0;
            }
            cchoice=rand()%3;
            game.settool(hchoice,choice_arr[cchoice],strength,cstrength+1);
            cout<<"Computer chose "<<choice_arr2[cchoice]<<endl;
            game.tool1->fight(*(game.tool2));
            if(game.tool1->getstrength()>game.tool2->getstrength())
            {
                cout<<"You win! Congrats on getting one over your eventual overlords! Hopefully they won't remember it.\n\n";
                game.human_wins++;
            }
            else if(game.tool1->getstrength()<game.tool2->getstrength())
            {
                cout<<"Computer wins! Good on you for letting them take one so you're not seen as a threat.\n\n";
                game.computer_wins++;
            }
            else
            {
                cout<<"Tie!They're onto you!\n\n";
                game.ties++;
            }
            cout<<"RESULT\nHuman wins - "<<game.human_wins<<"\nComputer wins - "<<game.computer_wins<<"\nTies - "<<game.ties<<"\n\n";
        }while(1);
            return 0;
}



