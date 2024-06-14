
#include "RubiksCube.h"


class RubiksCube3dArray : public RubiksCube
{
    public: 

    char cube [6][3][3] {};
    RubiksCube3dArray()
    {

        // this input contain the solve rubiks cube. 
        for(int fce = 0; fce< 6; fce++)
        {
            for(int rw = 0; rw < 3; rw++)
            {
                for(int cl = 0; cl < 3; cl++)
                {
                    // need a color in char type having fce, rw, cl; 
                    /* COLOR(fce) will create the variable of color type and assign interger value , enum underlying hold the interger, this is the important concept of enum*/
                    cube[fce][rw][cl] = getColorLetter(COLOR(fce));
                }
            }
        }
    }

    COLOR getColor(FACE fce, int row, int col) const override
    { 

        int faceIndex = (int)fce;
        char color = cube[faceIndex][row][col];
        switch (color)
        {
            case 'B':
            return COLOR :: BLUE; 
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }

    }

};
