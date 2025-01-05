
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>
#include<conio.h>

using namespace std;
int toss=0;
int l=0;
int v=0;
int team1_no_of_ballers=0;
int team2_no_of_ballers=0;

class scorebord
{
private:
    int total_team_runs=0;
    int total_team_wickets=0;
    int total_ball_faced=0;
    int exras=0;


public:
    void set_exras()
    {
        exras=exras+1;
    }
    int get_exras()
    {
        return exras;
    }
    void show_scorebord();

    void set_total_ball_faced()
    {
       total_ball_faced=total_ball_faced+1;
    }
    int get_total_ball_faced()
    {
        return total_ball_faced;
    }
    void set_toatal_team_wickets()
    {
        total_team_wickets=total_team_wickets+1;
    }
    int get_total_team_wickets()
    {
        return total_team_wickets;
    }
    void set_total_team_run(int e)
    {
        total_team_runs=total_team_runs+e;
    }

    int get_total_team_run()
    {
        return total_team_runs;
    }
};

void scorebord::show_scorebord()
{
    cout<<total_team_runs<<"-"<<total_team_wickets<<" ("<<total_ball_faced/6<<"."<<total_ball_faced%6<<")";
}




class player
{
private:
    int out=0;//0 not bat   1 on crease 2 out
    int bat=NULL;//batting skill
    int ball=NULL;//balling skill
    int player_bating_total=0;
    int player_balling_balls=0;
    int player_balling_total=0;
    int player_ball_faced=0;
    int baller_total_wickets=0;
    int over_remain=10;
    int no_of_4=0;
    int no_of_6=0;
    int maidin=0;
    string baller_name1;
    string baller_name2;
    string name1="";
    string name2="";
    player*next= nullptr;
public:
    int get_ball()
    {
        return ball;
    }
    int get_bat()
    {
        return bat;
    }
    void set_maidin()
    {
        maidin=maidin+1;
    }
    void set_baller_total_wickets()
    {
        baller_total_wickets=baller_total_wickets+1;
    }
    string give_name1()
    {
        return name1;
    }
    string give_name2()
    {
        return name2;
    }
    void set_baller_name(string a1,string a2)
    {
        baller_name1=a1;
        baller_name2=a2;
    }
    void set_player_balling_total(int r)
    {
        player_balling_total=player_balling_total+r;
    }
    void set_no_of_4()
    {
        no_of_4=no_of_4+1;
    }
    void set_no_of_6()
    {
        no_of_6=no_of_6+1;
    }
    void set_player_bating_total(int r)
    {
        player_bating_total=player_bating_total+r;
    }
    void set_player_ball_faced()
    {
        player_ball_faced=player_ball_faced+1;
    }
    void set_player_balling_balls()
    {
        player_balling_balls=player_balling_balls+1;
    }
    void set_over_remain()
    {
        over_remain=over_remain-1;
    }
    void give_name()
    {
        cout<<name1<<" "<<name2;
    }
    int give_ball()
    {
        return ball;
    }
    int give_over_remain()
    {
        return over_remain;
    }
    void set_on_crease()
    {
        out=1;
    }
    void set_out()
    {
        out=2;
    }
    player *return_next_player()
    {
        return next;
    }
    void set_player(string Name_1,string Name_2,int Bat1,int Ball1)
    {
        name1=Name_1;
        name2=Name_2;
        bat=Bat1;
        ball=Ball1;

    

    }
    void showdetail();
    void show_baller();
    void set_next_player(player *b)
    {
        next=b;
    }

};

void player::show_baller()
{
    if(ball!=0 && player_balling_balls!=0)
    {
        cout<<name1<<" "<<name2<<"   O-"<<player_balling_balls/6<<"."<<player_balling_balls%6<<"    W-"<<baller_total_wickets<<"    R-"<<player_balling_total;
        cout<<"   m-"<<maidin<<"    "
                               "econ-"<<float(player_balling_total*6)/player_balling_balls<<endl;
    }
}

void player::showdetail()
{
    if(out==0 )// yet to bat
    {
        cout << name1 << " " << name2  << endl;
    }

    else if(out==1)//not out
    {
        cout << name1 << " " << name2 << " " <<player_bating_total <<"("<<player_ball_faced <<")*    4s-"<<no_of_4<<"   6s-";
        cout<<no_of_6<<"    S/R-"<<float(player_bating_total*100)/player_ball_faced<< endl;

    }

    else//out
    {
        cout << name1 << " " << name2 << " " <<player_bating_total <<"("<<player_ball_faced <<")    4s-"<<no_of_4<<"   6s-";
        cout<<no_of_6<<"    S/R-"<<float(player_bating_total*100)/player_ball_faced<<"          ";

        cout<<baller_name1<<" "<<baller_name2<< endl;
    }

}



class Baller
{
private:
    player *Baller_pointer= nullptr;
public:
    void set_baller_pointer(player *b)
    {
     Baller_pointer=b;
    }
     player *retunn_pointer()
     {
        return Baller_pointer;
     }
};


class batter
{
private:
    player*batter_pointer= nullptr;
public:
    void set_batter_pointer(player *b)
    {
        batter_pointer=b;
    }
    player *return_batter_pointer()
    {
        return batter_pointer;
    }

};


























fstream teamA_card("teamA.txt",ios::in);//file stream for teamA
fstream teamB_card("teamB.txt",ios::in);//file stream for teamB

int main()
{



    player *baseplayerA;//importion for initialize variable of team A

    //create players of team 1************************************************************
    player player1;
    player player2;
    player player3;
    player player4;
    player player5;
    player player6;
    player player7;
    player player8;
    player player9;
    player player10;
    player player11;


//create teamA as a curculer link list*************************
    player1.set_next_player(&player2);
    player2.set_next_player(&player3);
    player3.set_next_player(&player4);
    player4.set_next_player(&player5);
    player5.set_next_player(&player6);
    player6.set_next_player(&player7);
    player7.set_next_player(&player8);
    player8.set_next_player(&player9);
    player9.set_next_player(&player10);
    player10.set_next_player(&player11);
    player11.set_next_player(&player1);


    player *baseplayerB;//importion for initialize variable of team B

    //create players of team 2************************************************************
    player player12;
    player player13;
    player player14;
    player player15;
    player player16;
    player player17;
    player player18;
    player player19;
    player player20;
    player player21;
    player player22;


//create teamB as a curculer link list*************************
    player12.set_next_player(&player13);
    player13.set_next_player(&player14);
    player14.set_next_player(&player15);
    player15.set_next_player(&player16);
    player16.set_next_player(&player17);
    player17.set_next_player(&player18);
    player18.set_next_player(&player19);
    player19.set_next_player(&player20);
    player20.set_next_player(&player21);
    player21.set_next_player(&player22);
    player22.set_next_player(&player12);


    baseplayerA=&player1;
    baseplayerB=&player12;

//get player details from team a teamcard



//toss
try {
    srand(time(0));
    toss = rand();


    if (toss % 2 == 1) {
        if (toss % 100 > 50) {
            l=1;
        } else {
            l=2;
        }


        for (int i = 0; i < 11; i++) {
            string Name1;
            string Name2;
            int bat1 = 0;
            int ball1 = 0;
            teamA_card >> Name1 >> Name2 >> bat1 >> ball1;
            baseplayerA->set_player(Name1, Name2, bat1, ball1);
            baseplayerA = baseplayerA->return_next_player();

            if(Name1=="" or Name2=="" or ball1==NULL or bat1==NULL or ball1<1 or ball1>100 or bat1<1 or bat1>100)
            {
                throw 555;
            }

            if(ball1>1)
            {
                team1_no_of_ballers++;
            }

            if(i==10 && team1_no_of_ballers<5)
            {
                throw 5555;
            }


        }


//get player details from team B teamcard
        for (int i = 0; i < 11; i++)
        {
            string Name1 = "";
            string Name2 = "";
            int bat1 = 0;
            int ball1 = 0;
            teamB_card >> Name1 >> Name2 >> bat1 >> ball1;
            baseplayerB->set_player(Name1, Name2, bat1, ball1);
            baseplayerB = baseplayerB->return_next_player();

            if(Name1=="" or Name2=="" or ball1==NULL or bat1==NULL or ball1<1 or ball1>100 or bat1<1 or bat1>100)
            {
                throw 666;
            }
            if(ball1>1)
            {
                team2_no_of_ballers++;
            }

            if(i==10 && team2_no_of_ballers<5)
            {
                throw 6666;
            }
        }


team1_no_of_ballers=0;
        team2_no_of_ballers=0;

    } else {
        if (toss % 100 > 50) {
           l=3;
        } else {
           l=4;
        }


        for (int i = 0; i < 11; i++) {
            string Name1;
            string Name2;
            int bat1 = NULL;
            int ball1 = NULL;
            teamB_card >> Name1 >> Name2 >> bat1 >> ball1;
            baseplayerA->set_player(Name1, Name2, bat1, ball1);
            baseplayerA = baseplayerA->return_next_player();

            if(Name1=="" or Name2=="" or ball1==NULL or bat1==NULL or ball1<1 or ball1>100 or bat1<1 or bat1>100)
            {
                throw 666;
            }
            if(ball1>1)
            {
                team2_no_of_ballers++;
            }

            if(i==10 && team2_no_of_ballers<5)
            {
                throw 6666;
            }

        }


//get player details from team B teamcard
        for (int i = 0; i < 11; i++) {
            string Name1 = "";
            string Name2 = "";
            int bat1 = NULL;
            int ball1 = NULL;
            teamA_card >> Name1 >> Name2 >> bat1 >> ball1;
            baseplayerB->set_player(Name1, Name2, bat1, ball1);
            baseplayerB = baseplayerB->return_next_player();

            if(Name1=="" or Name2=="" or ball1==NULL or bat1==NULL or ball1<1 or ball1>100 or bat1<1 or bat1>100)
            {
                throw 555;
            }
            if(ball1>1)
            {
                team1_no_of_ballers++;
            }

            if(i==10 && team1_no_of_ballers<5)
            {
                throw 5555;
            }

        }

    }

    {

    }
}

catch (int x)
{
    if(x==555)
    {
        cout << "\n\n*******************************************************************************" << endl;
        cout << "         player details are not correct in Team A. check the input file." << endl;
        cout << "*******************************************************************************" << endl;
    }

    if(x==666)
    {
        cout << "\n\n*******************************************************************************" << endl;
        cout << "         player details are not correct in Team B. check the input file." << endl;
        cout << "*******************************************************************************" << endl;

    }

    if(x==5555)
    {
        cout << "\n\n*******************************************************************************" << endl;
        cout << "         player details are not correct in Team A. check the input file." << endl;
        cout<<"                Team A dont have 5 ballers"<<endl;
        cout << "*******************************************************************************" << endl;
    }

    if(x==6666)
    {
        cout << "\n\n*******************************************************************************" << endl;
        cout << "         player details are not correct in Team B. check the input file." << endl;
        cout<<"                Team B dont have 5 ballers"<<endl;
        cout << "*******************************************************************************" << endl;

    }



    return 0;
}

catch (...)
{
    cout<<"unhandled error"<<endl;
    return 0;
}

    cout<<"*******************************************************************************"<<endl;
    cout<<"                                   GAME DAY                                    "<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    cout<<"                                  TOSS "<<endl;

    if(l==1)
    {
        cout << "\tteram A won the toss and chose the bat frist" << endl;
    }

    else if(l==2)
    {
        cout << "\tteram B won the toss and chose the ball frist" << endl;
    }
    else if(l==3)
    {
        cout << "\tteram b won the toss and chose the bat frist" << endl;
    }
    else
    {
        cout << "\tteram A won the toss and chose the ball frist" << endl;
    }

    cout<<"*******************************************************************************\n"<<endl;




cout<<"\n**************************************************************************"<<endl;
    cout<<"                            LETS PLAY"<<endl;
    cout<<"**************************************************************************"<<endl;
    cout<<"                              1ST INNING        "<<endl;
    cout<<"**************************************************************************\n"<<endl;



























//both team created sucsesfully cheacked*****


//creat scorebord for two teams
    scorebord team1_scorebord;
    scorebord team2_scorebord;

    int k=0;
    int chance_of_ball;


    batter tempplayer;//object for swap batters
    tempplayer.set_batter_pointer(NULL);

    batter stricker;
    stricker.set_batter_pointer(&player1);

    batter nonstricker;
    nonstricker.set_batter_pointer(&player2);

    batter next_batter;
    next_batter.set_batter_pointer(&player3);


   // player*baller=&player12;
  //  player*baller_before=NULL;


    Baller baller;
    Baller baller_before;

    baller.set_baller_pointer(&player12);
    baller_before.set_baller_pointer(NULL);


//choose 1st bowlewr;
    int p;




    stricker.return_batter_pointer()->set_on_crease();//piayer 1 and 2 come to creese
    nonstricker.return_batter_pointer()->set_on_crease();
    int runs_in_over=0;



    srand(time(0));

    while(k<300 && team1_scorebord.get_total_team_wickets()<10)
    {
        // select the baller
        if(k%6==0) {
            //swap batsmen for new over
            if(k!=0)
            {
                tempplayer=stricker;
                stricker=nonstricker;
                nonstricker=tempplayer;
            }
            int t=0;
            runs_in_over=0;

            while(t<1)
            {
                p=rand()%9;
                for(int r=0;r<p;r++)
                {
                    baller.set_baller_pointer(baller.retunn_pointer()->return_next_player());
                }
                if(baller.retunn_pointer()!=baller_before.retunn_pointer() && baller.retunn_pointer()->give_over_remain()!=0 && baller.retunn_pointer()->give_ball()>1 )
                {
                    t=100;
                }

            }


            baller_before.set_baller_pointer(baller.retunn_pointer());

            baller.retunn_pointer()->set_over_remain();

        }






        chance_of_ball=rand()%1000;

        if(chance_of_ball<920+(baller.retunn_pointer()->get_ball())/5) {
            stricker.return_batter_pointer()->set_player_ball_faced();//+1for batter faced ball
            k++;//+1 for k
            team1_scorebord.set_total_ball_faced();//+1 ball for team
            baller.retunn_pointer()->set_player_balling_balls();//+1ball for baller
        }

        v=(stricker.return_batter_pointer()->get_bat()-baller.retunn_pointer()->get_ball())*2/10;

        if(chance_of_ball<25+v)//6 runs
        {
            stricker.return_batter_pointer()->set_player_bating_total(6);
            stricker.return_batter_pointer()->set_no_of_6();
            team1_scorebord.set_total_team_run(6);
          baller.retunn_pointer()->set_player_balling_total(6);
            runs_in_over=runs_in_over+6;

        }
        else if(chance_of_ball>50 && chance_of_ball<100+v)//4 runs
        {
            stricker.return_batter_pointer()->set_player_bating_total(4);
            stricker.return_batter_pointer()->set_no_of_4();
            team1_scorebord.set_total_team_run(4);
            baller.retunn_pointer()->set_player_balling_total(4);
            runs_in_over=runs_in_over+4;
        }

        else if(chance_of_ball>130 && chance_of_ball<170+v)//3 runs
        {
            stricker.return_batter_pointer()->set_player_bating_total(3);
            team1_scorebord.set_total_team_run(3);
            baller.retunn_pointer()->set_player_balling_total(3);
            runs_in_over=runs_in_over+3;
            tempplayer=stricker;
            stricker=nonstricker;
            nonstricker=tempplayer;
        }

        else if(chance_of_ball>200 && chance_of_ball<270+v)//2 runs
        {
            stricker.return_batter_pointer()->set_player_bating_total(2);
            team1_scorebord.set_total_team_run(2);
            baller.retunn_pointer()->set_player_balling_total(2);
            runs_in_over=runs_in_over+2;
        }

        else if(chance_of_ball>300 && chance_of_ball<450+(2*v))//1 runs
        {
            stricker.return_batter_pointer()->set_player_bating_total(1);
            team1_scorebord.set_total_team_run(1);
            baller.retunn_pointer()->set_player_balling_total(1);
            runs_in_over=runs_in_over+1;
            tempplayer=stricker;
            stricker=nonstricker;
            nonstricker=tempplayer;
        }


        else if(chance_of_ball>500 && chance_of_ball<530-(v/2) )//wicket
        {
            cout<<team1_scorebord.get_total_team_run()<<"-"<<team1_scorebord.get_total_team_wickets()+1<<" ("<<team1_scorebord.get_total_ball_faced()/6<<"."<<team1_scorebord.get_total_ball_faced()%6<<")";
            stricker.return_batter_pointer()->give_name();
            cout<<"   ";
            baller.retunn_pointer()->give_name();



            stricker.return_batter_pointer()->set_baller_name(baller.retunn_pointer()->give_name1(),baller.retunn_pointer()->give_name2());
            cout<<endl;

            stricker.return_batter_pointer()->set_out();
            stricker=next_batter;
            stricker.return_batter_pointer()->set_on_crease();
            next_batter.set_batter_pointer(next_batter.return_batter_pointer()->return_next_player());
            team1_scorebord.set_toatal_team_wickets();
            baller.retunn_pointer()->set_baller_total_wickets();

        }

        else if(chance_of_ball>560 && chance_of_ball<565 )//run out nonstriker
        {
            cout<<team1_scorebord.get_total_team_run()<<"-"<<team1_scorebord.get_total_team_wickets()+1<<" ("<<team1_scorebord.get_total_ball_faced()/6<<"."<<team1_scorebord.get_total_ball_faced()%6<<")";
            nonstricker.return_batter_pointer()->give_name();
            cout<<"   Run out";




            nonstricker.return_batter_pointer()->set_baller_name("Run","out");
            cout<<endl;

            nonstricker.return_batter_pointer()->set_out();
            nonstricker=next_batter;
            nonstricker.return_batter_pointer()->set_on_crease();
            next_batter.set_batter_pointer(next_batter.return_batter_pointer()->return_next_player());
            team1_scorebord.set_toatal_team_wickets();

        }

        else if(chance_of_ball>566 && chance_of_ball<570 )//run out striker
        {
            cout<<team1_scorebord.get_total_team_run()<<"-"<<team1_scorebord.get_total_team_wickets()+1<<" ("<<team1_scorebord.get_total_ball_faced()/6<<"."<<team1_scorebord.get_total_ball_faced()%6<<")";
            stricker.return_batter_pointer()->give_name();
            cout<<"   Run out stricker";




            stricker.return_batter_pointer()->set_baller_name("Run","out stricker");
            cout<<endl;

            stricker.return_batter_pointer()->set_out();
            stricker=next_batter;
            stricker.return_batter_pointer()->set_on_crease();
            next_batter.set_batter_pointer(next_batter.return_batter_pointer()->return_next_player());
            team1_scorebord.set_toatal_team_wickets();

        }
        else if(chance_of_ball>=920+(baller.retunn_pointer()->get_ball())/5)
        {
            team1_scorebord.set_exras();
            team1_scorebord.set_total_team_run(1);
            baller.retunn_pointer()->set_player_balling_total(1);

        }
        else
        {
            //dot ball;
        }

        if(k%6==0 && runs_in_over==0)
        {
            baller.retunn_pointer()->set_maidin();
        }





    }


    cout<<"\n\n\n***************************************************************************\n\n\t\t\tEND OF 1ST INNING"<<endl;
    if(l==1 or l==2)
    {
        cout<<"\n\t\tTEAM A   ";
    }
    else
    {
        cout<<"\t\tTEAM B   ";
    }

    team1_scorebord.show_scorebord();

    cout<<"    R.R "<<float (team1_scorebord.get_total_team_run()*6)/team1_scorebord.get_total_ball_faced();
    cout<<"\n";


    cout<<"\n****************************BATING PERFORMANCE****************************\n"<<endl;
    player1.showdetail();
    player2.showdetail();
    player3.showdetail();
    player4.showdetail();
    player5.showdetail();
    player6.showdetail();
    player7.showdetail();
    player8.showdetail();
    player9.showdetail();
    player10.showdetail();
    player11.showdetail();
   cout<<"Exras "<<team1_scorebord.get_exras();



    cout<<"\n\n****************************BALLING PERFORMANCE****************************\n\n"<<endl;
    player12.show_baller();
    player13.show_baller();
    player14.show_baller();
    player15.show_baller();
    player16.show_baller();
    player17.show_baller();
    player18.show_baller();
    player19.show_baller();
    player20.show_baller();
    player21.show_baller();
    player22.show_baller();
cout<<"\n\n\n";
cout<<"***************************************************************************\n"<<endl;

if(l==1 or l==2)
{
    cout<<"\tTeam B needed "<<team1_scorebord.get_total_team_run()+1<<" runs in 50.0 overs";
}
else
{
    cout<<"\tTeam A needed "<<team1_scorebord.get_total_team_run()+1<<" runs in 50.0 overs";
}

cout<<"\t\tR.R.R "<<float (team1_scorebord.get_total_team_run()+1)/50;
    cout<<"\n\n***************************************************************************"<<endl;
    cout<<"                            LETS PLAY"<<endl;
    cout<<"**************************************************************************"<<endl;
    cout<<"                              2ST INNING        "<<endl;
    cout<<"**************************************************************************\n"<<endl;

    //////////////////////////////////////code for 2nd ining

    k=0;

    tempplayer.set_batter_pointer(NULL);

    stricker.set_batter_pointer(&player12);
    nonstricker.set_batter_pointer(&player13);
    next_batter.set_batter_pointer(&player14);

    baller.set_baller_pointer(&player1);
    baller_before.set_baller_pointer(NULL);


    stricker.return_batter_pointer()->set_on_crease();//piayer 1 and 2 come to creese
    nonstricker.return_batter_pointer()->set_on_crease();
    runs_in_over=0;



    srand(time(0));

    while(k<300 && team2_scorebord.get_total_team_wickets()<10 && team1_scorebord.get_total_team_run()>=team2_scorebord.get_total_team_run())
    {
        // select the baller
        if(k%6==0) {
            //swap batsmen for new over
            if(k!=0)
            {
                tempplayer=stricker;
                stricker=nonstricker;
                nonstricker=tempplayer;
            }
            int t=0;
            runs_in_over=0;

            while(t<1)
            {
                p=rand()%9;
                for(int r=0;r<p;r++)
                {
                    baller.set_baller_pointer(baller.retunn_pointer()->return_next_player());
                }
                if(baller.retunn_pointer()!=baller_before.retunn_pointer() && baller.retunn_pointer()->give_over_remain()!=0 && baller.retunn_pointer()->give_ball()>1 )
                {
                    t=100;
                }

            }


            baller_before.set_baller_pointer(baller.retunn_pointer());

            baller.retunn_pointer()->set_over_remain();

        }


        chance_of_ball=rand()%1000;
        if(chance_of_ball<920+(baller.retunn_pointer()->get_ball())/5) {
            stricker.return_batter_pointer()->set_player_ball_faced();
            baller.retunn_pointer()->set_player_balling_balls();
            k++;
            team2_scorebord.set_total_ball_faced();
        }


        v=(stricker.return_batter_pointer()->get_bat()-baller.retunn_pointer()->get_ball())*2/10;


        if(chance_of_ball<25+v)//6 runs
        {
            stricker.return_batter_pointer()->set_player_bating_total(6);
            stricker.return_batter_pointer()->set_no_of_6();
            team2_scorebord.set_total_team_run(6);
            baller.retunn_pointer()->set_player_balling_total(6);
            runs_in_over=runs_in_over+6;

        }
        else if(chance_of_ball>50 && chance_of_ball<100+v)//4 runs
        {
            stricker.return_batter_pointer()->set_player_bating_total(4);
            stricker.return_batter_pointer()->set_no_of_4();
            team2_scorebord.set_total_team_run(4);
            baller.retunn_pointer()->set_player_balling_total(4);
            runs_in_over=runs_in_over+4;
        }

        else if(chance_of_ball>130 && chance_of_ball<170+v)//3 runs
        {
            stricker.return_batter_pointer()->set_player_bating_total(3);
            team2_scorebord.set_total_team_run(3);
            baller.retunn_pointer()->set_player_balling_total(3);
            runs_in_over=runs_in_over+3;
            tempplayer=stricker;
            stricker=nonstricker;
            nonstricker=tempplayer;
        }

        else if(chance_of_ball>200 && chance_of_ball<270+v)//2 runs
        {
            stricker.return_batter_pointer()->set_player_bating_total(2);
            team2_scorebord.set_total_team_run(2);
            baller.retunn_pointer()->set_player_balling_total(2);
            runs_in_over=runs_in_over+2;
        }

        else if(chance_of_ball>300 && chance_of_ball<450+(2*v))//1 runs
        {
            stricker.return_batter_pointer()->set_player_bating_total(1);
            team2_scorebord.set_total_team_run(1);
            baller.retunn_pointer()->set_player_balling_total(1);
            runs_in_over=runs_in_over+1;
            tempplayer=stricker;
            stricker=nonstricker;
            nonstricker=tempplayer;
        }

        else if(chance_of_ball>500 && chance_of_ball<530-(v/2) )//wicket
        {
            cout<<team2_scorebord.get_total_team_run()<<"-"<<team2_scorebord.get_total_team_wickets()+1<<" ("<<team2_scorebord.get_total_ball_faced()/6<<"."<<team2_scorebord.get_total_ball_faced()%6<<")";
            stricker.return_batter_pointer()->give_name();
            cout<<"   ";
            baller.retunn_pointer()->give_name();



            stricker.return_batter_pointer()->set_baller_name(baller.retunn_pointer()->give_name1(),baller.retunn_pointer()->give_name2());
            cout<<endl;

            stricker.return_batter_pointer()->set_out();
            stricker=next_batter;
            stricker.return_batter_pointer()->set_on_crease();
            next_batter.set_batter_pointer(next_batter.return_batter_pointer()->return_next_player());
            team2_scorebord.set_toatal_team_wickets();
            baller.retunn_pointer()->set_baller_total_wickets();

        }

        else if(chance_of_ball>560 && chance_of_ball<565 )//run out
        {
            cout<<team2_scorebord.get_total_team_run()<<"-"<<team2_scorebord.get_total_team_wickets()+1<<" ("<<team2_scorebord.get_total_ball_faced()/6<<"."<<team2_scorebord.get_total_ball_faced()%6<<")";
            nonstricker.return_batter_pointer()->give_name();
            cout<<"   Run out";




            nonstricker.return_batter_pointer()->set_baller_name("Run","out");
            cout<<endl;

            nonstricker.return_batter_pointer()->set_out();
            nonstricker=next_batter;
            nonstricker.return_batter_pointer()->set_on_crease();
            next_batter.set_batter_pointer(next_batter.return_batter_pointer()->return_next_player());
            team2_scorebord.set_toatal_team_wickets();

        }

        else if(chance_of_ball>566 && chance_of_ball<570 )//run out striker
        {
            cout<<team2_scorebord.get_total_team_run()<<"-"<<team2_scorebord.get_total_team_wickets()+1<<" ("<<team2_scorebord.get_total_ball_faced()/6<<"."<<team2_scorebord.get_total_ball_faced()%6<<")";
            nonstricker.return_batter_pointer()->give_name();
            cout<<"   Run out stricker";




            stricker.return_batter_pointer()->set_baller_name("Run","out striker");
            cout<<endl;

            stricker.return_batter_pointer()->set_out();
            stricker=next_batter;
            stricker.return_batter_pointer()->set_on_crease();
            next_batter.set_batter_pointer(next_batter.return_batter_pointer()->return_next_player());
            team2_scorebord.set_toatal_team_wickets();

        }

        else if(chance_of_ball>=920+(baller.retunn_pointer()->get_ball())/5)
        {
            team2_scorebord.set_exras();
            team2_scorebord.set_total_team_run(1);
            baller.retunn_pointer()->set_player_balling_total(1);

        }
        else
        {
            //dot ball;
        }








        if(k%6==0 && runs_in_over==0)
        {
            baller.retunn_pointer()->set_maidin();
        }
    }





    cout<<"\n\n\n***************************************************************************\n\n\t\t\tEND OF 2ND INNING"<<endl;
    if(l==1 or l==2)
    {
        cout<<"\n\t\tTEAM B   ";
    }
    else
    {
        cout<<"\t\tTEAM A   ";
    }

    team2_scorebord.show_scorebord();

    cout<<"    R.R "<<float (team2_scorebord.get_total_team_run()*6)/team2_scorebord.get_total_ball_faced();
    cout<<"\n";


    cout<<"\n****************************BATING PERFORMANCE****************************\n"<<endl;
    player12.showdetail();
    player13.showdetail();
    player14.showdetail();
    player15.showdetail();
    player16.showdetail();
    player17.showdetail();
    player18.showdetail();
    player19.showdetail();
    player20.showdetail();
    player21.showdetail();
    player22.showdetail();
    cout<<"Exras "<<team2_scorebord.get_exras();


    cout<<"\n****************************BALLING PERFORMANCE****************************\n"<<endl;
    player1.show_baller();
    player2.show_baller();
    player3.show_baller();
    player4.show_baller();
    player5.show_baller();
    player6.show_baller();
    player7.show_baller();
    player8.show_baller();
    player9.show_baller();
    player10.show_baller();
    player11.show_baller();

cout<<"\n\n*****************************************************************************"<<endl;
    cout<<"*****************************************************************************"<<endl;
cout<<"\t\t\tMATCH RESULT"<<endl;

if(team1_scorebord.get_total_team_run()>team2_scorebord.get_total_team_run())
{
    if(l==1 or l==2) {
        cout << "                   Team A won by " << team1_scorebord.get_total_team_run() - team2_scorebord.get_total_team_run() << " runs"
             << endl;
    }

    else
    {
        cout << "                   Team B won by " << team1_scorebord.get_total_team_run() - team2_scorebord.get_total_team_run() << " runs"
             << endl;

    }
}

else if(team1_scorebord.get_total_team_run()<team2_scorebord.get_total_team_run())
{
    if(l==1 or l==2) {
        cout << "\tTeam B won by " << 10 - team2_scorebord.get_total_team_wickets() << " wickets and "
             << (300 - team2_scorebord.get_total_ball_faced()) / 6 << "."
             << (300 - team2_scorebord.get_total_ball_faced()) % 6 << " overs remaining." << endl;
    }
    else
    {
        cout << "\tTeam A won by " << 10 - team2_scorebord.get_total_team_wickets() << " wickets and "
             << (300 - team2_scorebord.get_total_ball_faced()) / 6 << "."
             << (300 - team2_scorebord.get_total_ball_faced()) % 6 << " overs remaining." << endl;

    }
}

else
{
    cout<<"match is drown."<<endl;
}

cout<<"\t\t       end of the match.";
    cout<<"\n*****************************************************************************"<<endl;
    cout<<"*****************************************************************************"<<endl;





return 0;
}


