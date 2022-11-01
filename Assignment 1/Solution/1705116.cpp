#include <iostream>
#include <cmath>
#include <sstream>
#include<cstdlib>
#include<cstdio>


using namespace std;

#define GRIDSIZE 4
#define UP      0
#define DOWN    2
#define LEFT    3
#define RIGHT   1
#define MAX_SHOTS 3


string to_string(int x)
{
    std::string out_string;
    std::stringstream ss;
    ss << x;
    return ss.str();
}


class Position
{

    int x, y;

public:

    Position (int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Position()
    {
        x=0;
        y=0;

    }

    // Modify the following four so that the resulting position does not leave the grid
    void moveRight()
    {

        if(x<3)
            x++;
    }

    void moveLeft()
    {
        if(x>0)
            x--;
    }

    void moveUp()
    {
        if(y<3)
            y++;
    }

    void moveDown()
    {
        if(y>0)
            y--;
    }

    bool isAdjacent(Position p)
    {
        //implement the function/

        if(this->x==p.x && ((this->y==p.y+1)||(this->y==p.y-1)))
            return true;
        else if(this->y==p.y &&((this->x==p.x+1)||(this->x==p.x-1)))
            return true;
        else
            return false;
    }

    bool isSamePoint(Position p)
    {
        //implement the function
        if(this->x==p.x && this->y==p.y)
            return true;
        else
            return false;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

};


class Wumpus
{

    bool killed;
    Position p;

public:

    Wumpus(int x, int y)
    {
        p = Position(x, y);
        killed = false;
    }

    Wumpus()
    {
        //...
        killed=false;

    }

    Position getPosition()
    {
        return p;
    }

    bool kill()
    {

        if(killed==false)
        {
            cout<<"Wumpus is killed succesfully"<<endl;
        }
        killed=true;

    }
    bool w_kill()
    {
        return killed;
    }

};


class Player
{

    int direction;
    int t_shots;
    bool killed;
    Position p;

public:

    Player()
    {
        //...
        direction=UP;
        t_shots =3;
        killed=false;
    }

    void turnLeft()
    {

        direction =(direction+LEFT)%4;
        //...

    }

    void turnRight()
    {
        //...
        direction =(direction+RIGHT)%4;
    }

    void moveForward()
    {
        //...
        if(direction==UP)
            p.moveUp();
        else if(direction==DOWN)
            p.moveDown();
        else if(direction==RIGHT)
            p.moveRight();
        else
            p.moveLeft();
    }


    bool isAdjacent(Position pos)
    {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos)
    {
        return p.isSamePoint(pos);
    }

    bool kill()
    {
        killed = true;
    }

    Position getPosition()
    {
        return p;
    }

    int getDirection()
    {
        return direction;
    }
    int getshot()
    {
        t_shots=t_shots-1;
        return t_shots;
    }

    string getPositionInfo()
    {
        return "Player is now at " + to_string(p.getX()) + ", " + to_string(p.getY());
    }

    string getDirectionInfo()
    {
        string s;
        if (direction == UP)
            s = "up";
        if (direction == DOWN)
            s = "down";
        if (direction == LEFT)
            s = "left";
        if (direction == RIGHT)
            s = "right";
        return "Player is moving at direction: " + s;
    }

};



class WumpusWorld
{

private:

    Player player;
    Wumpus wumpus;
    Position gold_position;
    Position pit_position;
    bool ended;

public:

    WumpusWorld()
    {
        //...

        wumpus=Wumpus(rand()%4,rand()%4);
        gold_position=Position(rand()%4,rand()%4);
        pit_position=Position (rand()%4,rand()%4);
    }

    WumpusWorld(int wumpus_x, int wumpus_y)
    {
        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        gold_position=Position(rand()%4,rand()%4);
        pit_position=Position (rand()%4,rand()%4);


    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y)
    {
        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        gold_position= Position(gold_x,gold_y);
        pit_position= Position(rand()%4,rand()%4);

    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y)
    {

        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        gold_position= Position(gold_x,gold_y);
        pit_position= Position(pit_x,pit_y);


    }

    void moveForward()
    {
        player.moveForward();
        return showGameState();
    }

    void turnLeft()
    {
        player.turnLeft();
        return showGameState();
    }

    void turnRight()
    {
        player.turnRight();
        return showGameState();
    }

    void shot()
    {
        //...
        Position w1=wumpus.getPosition();
        Position p1=player.getPosition();

        if((p1.getX()==w1.getX())&& w1.getY()>p1.getY() &&player.getDirection()==UP &&player.getshot()>=0)
            wumpus.kill();

        else if((p1.getX()==w1.getX())&& w1.getY()< p1.getY() &&player.getDirection()==DOWN &&player.getshot()>=0)
            wumpus.kill();

        else if((p1.getY()==w1.getY())&& w1.getX()< p1.getX() &&player.getDirection()==LEFT &&player.getshot()>=0)
            wumpus.kill();

        else if((p1.getY()==w1.getY())&& w1.getX()> p1.getX() &&player.getDirection()==RIGHT &&player.getshot()>=0)
            wumpus.kill();
        else if(player.getshot()<0)
        {
            cout<<"Not sufficient shot"<<endl;
        }
        else
            cout<<"Shot missed"<<endl;
        return showGameState();

    }

    void showGameState()
    {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;

        if (player.isAdjacent(wumpus.getPosition()) && wumpus.w_kill()==false )
        {
            cout << "stench!" << endl;
        }
        if (player.isAdjacent(pit_position)==true)
        {
            cout << "Breeze" << endl;
        }

        if (player.isSamePoint(wumpus.getPosition())&& wumpus.w_kill()==false )
        {
            cout << "Player is killed!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;;
        }

        if (player.isSamePoint(pit_position)==true)
        {

            cout<<"Getting pit"<<endl;
            cout << "Player is killed!" << endl;

            player.kill();
            cout << "Game over!" << endl;
            ended = true;;
        }

        if (player.isSamePoint(gold_position))
        {
            cout << "Got the gold!" << endl;
            cout << "Game ended, you won!" << endl;
            ended = true;
        }
    }

    bool isOver()
    {
        return ended;
    }

};


int main()
{
    int c, wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y;
    // take the six integers input from file
    FILE*fe;
    fe=fopen("information.txt","r");
    fscanf(fe,"%d %d %d %d %d %d",&wumpus_x,&wumpus_y,&gold_x,&gold_y,&pit_x,&pit_y);
    WumpusWorld w(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);
    //WumpusWorld w(0, 3,1,2,3,0);
    w.showGameState();
    while (!w.isOver())
    {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shot" << endl;
        cin >> c;
        if (c == 1)
        {
            w.moveForward();
        }
        else if (c == 2)
        {
            w.turnLeft();
        }
        else if (c == 3)
        {
            w.turnRight();
        }
        else if (c == 4)
        {
            w.shot();
        }
    }
    return 0;

}

