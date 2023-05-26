#include <iostream>
#include <string.h>
using namespace std;

class hero
{

    // Properties
private:
    int health;

public:
    char *name;
    char level;
    // static keyword
    static int timetocomplete;
    // Default constructor
    hero()
    {
        cout << "Constructor called." << endl;
        name = new char[1000];
    }
    // Parameterised constructor
    hero(int health, char level)
    {
        cout << "Address ->" << this << endl;
        this->health = health;
        this->level = level;
    }

    // Copy constructor

    // hero& temp this is pass by reference
    hero(hero &temp)
    {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print()
    {
        cout << "Name is->" << this->name << endl;
        cout << "Health is->" << this->health << endl;
        cout << "Level is->" << this->level << endl;
    }

    int gethealth()
    {
        return health;
    }
    char getlevel()
    {
        return level;
    }
    void sethealth(int h)
    {
        health = h;
    }
    void setlevel(char l)
    {
        level = l;
    }
    void setname(char name[])
    {
        strcpy(this->name, name);
    }
    static int random()
    {
        return timetocomplete;
    }
    ~hero()
    {
        cout << " Destructor called->" << endl;
    }
};

int hero::timetocomplete = 5;

int main()
{
    cout << hero::random() << endl;

    /*
    // Static
    hero a;

    // Dynamic
    hero *b = new hero;
    // manually called
    delete b;

    hero hero1;
    hero1.sethealth(70);
    hero1.setlevel('B');
    char name[7] = "Babbar";
    hero1.setname(name);

    hero1.print();

    hero hero2(hero1);
    hero1.name[0] = 'G';
    hero1.print();

    hero2.print();

    // copy assignment operator
    hero1 = hero2;
    hero1.print();

    hero2.print();

    /*
        hero s(90, 'B', "Babbar");
        s.print();

        // Copy constructor
        hero R(s);
        R.print();

        hero ramesh(70,'B');
         cout << "Adress of ramesh->" << ramesh.gethealth() << endl;
         cout<<"Ramesh level is->"<<ramesh.getlevel()<<endl;


          // Statically allocation
          hero a;
          a.sethealth(80);
          a.setlevel('B');
          cout << "A health is->" << a.gethealth() << endl;
          cout << "A level is->" << a.getlevel() << endl;

          // Dynamically allocation
          hero *b = new hero;
          b->sethealth(70);
          b->setlevel('A');
          cout << "B health is->" << b->gethealth() << endl;
          cout << "B level is->" << b->getlevel() << endl;
          /* Creation of Object
          hero ramesh;
          cout << "Ramesh health is ->" << ramesh.gethealth() << endl;
          ramesh.sethealth(70);
          ramesh.level = 'A';

          cout << "Ramesh health ->" << ramesh.gethealth() << endl;
          cout << "Ramesh Level ->" << ramesh.level << endl;
          */

    return 0;
}