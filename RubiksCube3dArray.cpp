#include<bits/stdc++.h>
#include<RubiksCube.h>
using namespace std; 

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
};
