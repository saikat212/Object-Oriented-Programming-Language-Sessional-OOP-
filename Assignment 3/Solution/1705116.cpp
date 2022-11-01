#include<iostream>

using namespace std;


class Unit
{
protected:
    int range,health,cost,damage,position;


public:
    void set_health(int h)
    {
        health=h;
    }

    void set_position(int p)
    {
        position=p;
    }


    void set_range(int r)
    {
        range=r;
    }

    void set_damage(int d)
    {
        damage=d;
    }

    void set_cost(int c)
    {
        cost=c;
    }


    int  get_health()
    {
        return health;
    }


    int get_position()
    {
        return position;
    }



    int  get_range()
    {
        return range;
    }



    int  get_damage()
    {
        return damage;
    }


    int  get_cost()
    {
        return cost;
    }



    void Archer_status()
    {
        cout<<"Archer ."<<" "<<"Health: "<<health<<" "<<".Running ."<<"Positioned at "<<position;
    }



    void AdvancedArcher_status()
    {
        cout<<"Advanced Archer."<<" "<<"Health: "<<health<<" "<<".Riding Horse."<<"Positioned at "<<position;
    }



    void Bowman_status()
    {
        cout<<"Bowman."<<"Health:"<<health<<" . StationaryPositioned at "<<position<<". Bowman is shooting Basic Arrow.";
    }



    void AdvancedBowman_status()
    {
        cout<<"Advanced Bowman."<<" Health:"<<health<<" .StationaryPositioned at "<<position<<".Advanced Bowman is shooting Canon.";
    }



    void Enemy_status()
    {
        cout<<"\nEnemyTower's Health :"<<health<<". EnemyTower is shooting Fire Arrow.";
    }
};



///Here Base class -(Unit) is  hierarchycally inherited by derived class-(Archer ,AdvancedArcher ,Boman,AdvancedBowman)

class Archer:public Unit
{
public:

    Archer(int r,int h,int c,int d,int p)
    {
        set_health(h);
        set_position(p);
        set_damage(d);
        set_cost(c);
        set_range(r);
    }
};



class AdvancedArcher:public Unit
{
public:

    AdvancedArcher(int r,int h,int c,int d,int p)
    {
        set_health(h);
        set_position(p);
        set_damage(d);
        set_cost(c);
        set_range(r);
    }
};




class Bowman:public Unit
{
public:

    Bowman(int r,int h,int c,int d,int p)
    {
        set_health(h);
        set_position(p);
        set_damage(d);
        set_cost(c);
        set_range(r);
    }
};




class AdvancedBowman:public Unit
{
public:

    AdvancedBowman(int r,int h,int c,int d,int p)
    {
        set_health(h);
        set_position(p);
        set_damage(d);
        set_cost(c);
        set_range(r);
    }
};





int main()
{
    Unit *w;


    Unit *enemy;
    enemy=new Unit;
    enemy->set_health(300);  ///set health for enemy
    enemy->set_damage(40);   ///set damage for enemy to unit

    static int total_coin=1600;
    int Round=1;


    while(1)
    {
        cout<<"Coin Remaining: "<<total_coin<<endl;
        cout<<"Choose Your option:\n";
        cout<<"1. Archer (Cost 150)\n";
        cout<<"2. Advanced Archer (Cost 600)\n";
        cout<<"3. Bowman (Cost 100)\n";
        cout<<"4. Advanced Boman (Cost 200)\n";


        int choice;
        cin>>choice;


        switch(choice)
        {


        case 1:
            w =new Archer(50,100,150,25,25); ///sequence parameter:(range,health,cost,damage,position)

            ///Changing coins for deploying Unit
            total_coin=total_coin - w->get_cost();


            ///Rounding loop to show Round

            while (1)
            {
                cout<<"\nRound : "<<Round<<endl;



                ///Unit died condition
                if(w->get_health()<=0)
                {
                    cout<<"Archer. "<<"Health:"<<w->get_health()<<". Unit died!!"<<endl;
                    break;
                }



                ///Losing condition
                if(total_coin<=0)
                {
                    cout<<"You Lose"<<endl;
                    return 0;
                }




                ///unit  status
                w->Archer_status();



                ///shooting function for unit & enemy health change
                if(w->get_position()>=w->get_range())
                {
                    cout<< ".Archer is shooting Advanced Arrow.";
                    enemy->set_health(enemy->get_health()-w->get_damage());
                }




                ///enemy status

                if(enemy->get_health()>0)
                {
                    enemy->Enemy_status();
                }




                ///Winning condition
                else if(enemy->get_health()<=0)
                {
                    cout<<"\nEnemy died!!--->> You win"<<endl;
                    return 0;

                }




                ///health change for unit after damaging
                w->set_health(w->get_health()-enemy->get_damage());


                ///position change for unit
                if(w->get_position() <100)
                {
                    w->set_position(w->get_position()+25);
                }


                Round++;
            }
            break;



        case 2:
            w =new AdvancedArcher(50,120,600,50,30); ///sequence parameter:(range,health,cost,damage,position)


            ///Changing coins for deploying Unit
            total_coin=total_coin - w->get_cost();



            while (1)
            {
                cout<<"\nRound : "<<Round<<endl;

                ///Unit died condition
                if(w->get_health()<=0)
                {
                    cout<<"Advanced Archer. "<<"Health:"<<w->get_health()<<". Unit died!!"<<endl;
                    break;
                }



                ///Losing condition
                if(total_coin<=0)
                {
                    cout<<"You Lose"<<endl;
                    return 0;
                }



                ///unit  status
                w->AdvancedArcher_status();


                ///shooting function for unit & enemy health change

                if(w->get_position()>=w->get_range())
                {
                    cout<< ".Advanced Archer is shooting Improved Arrow.";
                    enemy->set_health(enemy->get_health()-w->get_damage());
                }



                ///enemy status

                if(enemy->get_health()>0)
                {
                    enemy->Enemy_status();
                }




                ///Winning condition

                else if(enemy->get_health()<=0)
                {
                    cout<<"\nEnemy died!!--->> You win"<<endl;
                    return 0;

                }



                ///health change for unit after damaging
                w->set_health(w->get_health()-enemy->get_damage());


                ///position change for unit
                if(w->get_position() <100)
                {
                    w->set_position(w->get_position()+30);
                }


                Round++;
            }
            break;




        case 3:
            w =  new Bowman(110,60,100,10,0); ///sequence parameter:(range,health,cost,damage,position)

            total_coin=total_coin - w->get_cost();

            while (1)
            {
                cout<<"\nRound : "<<Round<<endl;

                ///Unit died condition
                if(w->get_health()<=0)
                {
                    cout<<"Bowman. "<<"Health:"<<w->get_health()<<". Unit died!!"<<endl;
                    cout<<"Bowman gave 40 coins while dying."<<endl;
                    total_coin+=40;
                    break;
                }




                ///Losing condition
                if(total_coin<=0)
                {
                    cout<<"You Lose"<<endl;
                    return 0;
                }




                ///unit  status
                w->Bowman_status();


                /// enemy health change
                enemy->set_health(enemy->get_health()-w->get_damage());


                ///enemy status

                if(enemy->get_health()>0)
                {
                    enemy->Enemy_status();
                }



                ///Winning condition
                else if(enemy->get_health()<=0)
                {
                    cout<<"\nEnemy died!!--->> You win"<<endl;
                    return 0;

                }




                ///health change for unit after damaging
                w->set_health(w->get_health()-enemy->get_damage());
                Round++;
            }

            break;




        default :
            w = new AdvancedBowman(130,85,200,15,0); ///sequence parameter:(range,health,cost,damage,position)

            total_coin=total_coin - w->get_cost();

            while (1)
            {
                cout<<"\nRound : "<<Round<<endl;

                ///Unit died condition
                if(w->get_health()<=0)
                {
                    cout<<"Advanced Bowman. "<<"Health:"<<w->get_health()<<". Unit died!!"<<endl;
                    cout<<"Advanced Bowman gave 60 coins while dying."<<endl;
                    total_coin+=60;
                    break;
                }



                ///Losing condition
                if(total_coin<=0)
                {
                    cout<<"You Lose"<<endl;
                    return 0;
                }



                ///unit  status
                w->AdvancedBowman_status();

                /// enemy health change
                enemy->set_health(enemy->get_health()-w->get_damage());


                ///enemy status

                if(enemy->get_health()>0)
                {
                    enemy->Enemy_status();
                }

                ///Winning condition
                else if(enemy->get_health()<=0)
                {
                    cout<<"\nEnemy died!!--->> You win"<<endl;
                    return 0;

                }


                ///health change for unit after damaging
                w->set_health(w->get_health()-enemy->get_damage());
                Round++;
            }

            break;

        }

    }
}


