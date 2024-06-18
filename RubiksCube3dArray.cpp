
#include "RubiksCube.h"


class RubiksCube3dArray : public RubiksCube
{
    public: 

    char cube [6][3][3];
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

    void RotateFace(int face)
    {
        char store0 = cube[face][0][0];
        char store1 = cube[face][1][0];
        
        cube[face][0][0] = cube[face][2][0];
        cube[face][2][0] = cube[face][2][2];
        cube[face][2][2] = cube[face][0][2];
        cube[face][0][2] = store0;

        cube[face][1][0] = cube[face][2][1];
        cube[face][2][1] = cube[face][1][2];
        cube[face][1][2] = cube[face][0][1];
        cube[face][0][1] = store1;

        // return *this;
        //  char temp_arr[3][3] = {};
        // for (int i = 0; i < 3; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         temp_arr[i][j] = cube[ind][i][j];
        //     }
        // }
        // for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
        // for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
        // for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
        // for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];

    }

    RubiksCube &L() {

        this->RotateFace(1);
        int moves[] = {0, 2, 4, 5};
        char stateSave[3];

        for(int i = 0; i< 3; i++) {
            stateSave[i] = cube[0][i][0];
        }
        // after L move 4th face values become 0th face value
        for(int i = 0; i< 3; i++) {
            cube[0][i][0] = cube[4][i][0];
        }


        for(int i = 0; i< 3; i++)
        {
            cube[4][i][2] = cube[5][i][0];
        }

        for(int i = 0; i< 3; i++)
        {
            cube[5][i][0] = cube[2][i][0];
        }

        for(int i = 0; i< 3; i++)
        {
            cube[2][i][0] = stateSave[i];
        }
        return *this;
        //   this->RotateFace(1);

        // char temp_arr[3] = {};
        // for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        // for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        // for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        // for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        // for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        // return *this;

    }

     RubiksCube &U() override {
        this->RotateFace(0);
        char stateSave[3];

        for(int i = 0; i< 3; i++) {
            stateSave[i] = cube[2][0][i];
        }
        for(int i = 0; i< 3; i++) {
            cube[2][0][i] = cube[3][0][i];
        }

        for(int i = 0; i< 3; i++)
        {
           cube[3][0][i] = cube[4][0][i];
        }

        for(int i = 0; i< 3; i++)
        {
           cube[4][0][i] = cube[1][0][i];
        }

        for(int i = 0; i< 3; i++)
        {
           cube[1][0][i] = stateSave[i];
        }
        return *this;
        // this->RotateFace(0);

        // char temp_arr[3] = {};
        // for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        // for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        // for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        // for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        // for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        // return *this;

    }

};
