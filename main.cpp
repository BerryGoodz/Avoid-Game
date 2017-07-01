#include <SFML/Graphics.hpp>
#include <Attack.h>
#include <Random.h>
#include <time.h>
#include <string>
#include <sstream>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(810, 810), "Avoid");
    window.setFramerateLimit(60);
    RectangleShape player(Vector2f(90,90));
    player.setFillColor(Color::Green);
    player.setPosition(360,360);

    std::vector<Attack>::const_iterator iter;
    std::vector<Attack>::const_iterator iter2;
    std::vector<Attack> attackArray;
    Attack attack;

    Font font;
    if (!font.loadFromFile("word.ttf"))
    {
    }
    Text score, number, level, number2;

    score.setFont(font);
    score.setString("Score:");
    score.setCharacterSize(24);
    score.setFillColor(Color::White);
    score.setPosition(30,30);
    number.setFont(font);
    number.setCharacterSize(24);
    number.setFillColor(Color::White);
    number.setPosition(100,30);
    level.setFont(font);
    level.setString("Level:");
    level.setCharacterSize(24);
    level.setFillColor(Color::White);
    level.setPosition(30,70);
    number2.setFont(font);
    number2.setCharacterSize(24);
    number2.setFillColor(Color::White);
    number2.setPosition(100,70);


    int energy=0;
    int points =0;
    int levels=1;
    int counter=0;
    int counter2=0;
    int counter3=0;
    int counter4=0;
    int gameStart = 0;
    int levelCheck=0;
    int levelUp = 10;
    int difficulty= 50;
    bool gameOver=false;
    srand(time(NULL));





    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }


if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&energy>30)
{
    player.move(-90, 0);
    energy=0;
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&energy>30)
{
    player.move(90, 0);
    energy=0;
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&energy>30)
{
    player.move(0, -90);
    energy=0;
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&energy>30)
{
    player.move(0, 90);
    energy=0;
}
if(player.getPosition().x>720)
{

    player.move(-90,0);
}
if(player.getPosition().x<0)
{

    player.move(90,0);
}
if(player.getPosition().y<0)
{

    player.move(0,90);
}
if(player.getPosition().y>720)
{
    player.move(0,-90);
}

counter4=0;
for(iter= attackArray.begin(); iter != attackArray.end(); iter++)
{
    if(player.getGlobalBounds().intersects(attackArray[counter4].rect.getGlobalBounds())&&attackArray[counter4].hitAble)
    {
        gameOver=true;

        }
        counter4++;
    }





energy++;

        window.clear();
        counter2++;
         if (counter2==difficulty&&gameOver==false)
    {
        attack.rect.setPosition(generateRandom(9)*90,generateRandom(9)*90);
        attackArray.push_back(attack);
        counter2 = 0;
    }
        counter=0;
        for(iter= attackArray.begin(); iter != attackArray.end(); iter++)
        {


            window.draw(attackArray[counter].rect);
            attackArray[counter].update();
            counter++;
        }
  counter3=0;
    for(iter= attackArray.begin(); iter != attackArray.end(); iter++)
        {
        if(attackArray[counter3].destroy==true)
        {
        attackArray.erase(iter);
        points++;
        levelCheck++;
        break;
        }
            counter3++;
        }

             for(iter2= attackArray.begin(); iter2 != attackArray.end(); iter2++)
        {
            if(gameOver){

              attackArray.erase(iter2);
        break;

        }
        }
if(levelCheck==levelUp&&difficulty>5)
{
    levelCheck=0;
    levelUp+=5*levels;
    levels+=1;
    difficulty-=5;
    counter2=0;
}
if(levelCheck==levelUp&&levels>7)
{
    levelUp+=20;
}

if(levelCheck==levelUp&&difficulty<=5&&difficulty>2)
{
    levelCheck=0;
    levelUp+=10*levels;
    levels+=1;
    difficulty-=1;
    counter2=0;
}
        if(gameOver)
        {
            gameStart++;
            if(gameStart==100)
            {
                gameStart=0;
                counter2=0;
                points=0;
                difficulty=50;
                levels= 1;
                levelUp= 10;
                levelCheck = 0;
                gameOver=false;
            }
        }

    int np= points;
    string sp;
    stringstream ssp;
    ssp << np;
    ssp >> sp;
    int npp= levels;
    string spp;
    stringstream sspp;
    sspp << npp;
    sspp >> spp;
    number.setString(sp);
    number2.setString(spp);
        window.draw(score);
        window.draw(number);
        window.draw(level);
        window.draw(number2);
        window.draw(player);

        window.display();
    }

    return 0;
}
