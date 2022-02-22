#include "Monster2.h" // header file
#include "Game.h" // header file
int main()
{
    // dragon is object of class Monster1
    Monster2 dragon; // access fields, run methods (not just the pointer/structs)
    // before we create it , it has garbage values in those fields

    srand((unsigned)time(NULL)); // set random seed
    dragon.create();
    dragon.draw();
    dragon.set_name("Puff");
    dragon.moveto(10, 25);
    dragon.draw();

    Monster2 baddy("Wolf"); //functional way to call constr - simplest way
    baddy.draw();
    //constructor with 1 arg can also use assingment way

    Monster2 wolf = "Babby"; //only works with 1 arg
    wolf.draw();

    //uniform way to call constructor  hard to confuse it 
    Monster2 wow = { "Puffy" };
    wow.draw();
    //podlike way to call constructor
    Monster2 *puffy = new Monster2("Puffy");

    //pod like way to call constructor
    Monster2 *puffy2 = new Monster2;
    Game aGame;
    aGame.start();
    aGame.display();
    
    return 0;
}


