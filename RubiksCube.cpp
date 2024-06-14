// #include<iostream>
#include"RubiksCube.h" 


// in this function give a color name it will return the first character of the color
// eg. getColorLetter(BLUE) return 'B';
char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
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

/*
    * Print the Rubik Cube in Planar format.
     *
     * The cube is laid out as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     * 
     * U = 0, L = 1, F = 2, R = 3, B = 4, D = 5;
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *

*/
void RubiksCube::printRubikCube()
{
    cout<<"Rubiks Cube"<<endl;
    cout<<endl;

    /* for priting the up face */
    for(int row = 0; row<=2; row++)
    {
        // for printing the gap
        for(int gap = 0; gap < 7; gap++)
        {
            cout<<" ";
        }
        for(int col = 0; col <=2; col++)
        {
            cout<<getColorLetter(getColor(FACE :: UP, row, col))<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

   
    for(int row = 0; row <=2; row++)
    {
        /* for priting the LEFT face */
        for(int col = 0; col <=2 ; col++)
        {
            cout<<getColorLetter(getColor(FACE :: LEFT, row, col))<<" ";
        }
        cout<<" ";

        /* for priting the FRONT face */
        for(int col = 0; col <=2 ; col++)
        {
            cout<<getColorLetter(getColor(FACE :: FRONT, row, col))<<" ";
        }
        cout<<" ";


        /* for priting the RIGHT face */
        for(int col = 0; col <=2 ; col++)
        {
            cout<<getColorLetter(getColor(FACE :: RIGHT, row, col))<<" ";
        }
        cout<<" ";

        /* for priting the BACK face */
        for(int col = 0; col <=2 ; col++)
        {
            cout<<getColorLetter(getColor(FACE :: BACK, row, col))<<" ";
        }
        cout<<" ";
        cout<<endl;
    }
     cout<<endl;

    /* for priting the BACK face */
    for(int row = 0; row<=2; row++)
    {
        // for printing the gap
        for(int gap = 0; gap < 7; gap++)
        {
            cout<<" ";
        }
        for(int col = 0; col <=2; col++)
        {
            cout<<getColorLetter(getColor(FACE :: DOWN, row, col))<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

   

    

}

