#include<RubiksCube.h>
using namespace std; 

// in this function give a color name it will return the first character of the color
// eg. getColorLetter(BLUE) return 'B';
char RubiksCube :: getColorLetter(COLOR c)
{
    switch (c)
    {
        /* standard way to use switch is 
            case 1 : 
            return Monday;

        */
        case COLOR::BLUE:
            return 'B';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::YELLOW:
            return 'Y';
        case COLOR::WHITE:
            return 'W';
        case COLOR::ORANGE:
            return 'O';
    }
}