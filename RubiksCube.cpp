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


string RubiksCube::getMove(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return "L";
        case MOVE::LPRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RPRIME:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::UPRIME:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DPRIME:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::FPRIME:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BPRIME:
            return "B'";
        case MOVE::B2:
            return "B2";
    }
}


// action perfomed when someon called move(move)
RubiksCube &RubiksCube::move(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->L();
        case MOVE::LPRIME:
            return this->Lprime();
        case MOVE::L2:
            return this->L2();
        case MOVE::R:
            return this->R();
        case MOVE::RPRIME:
            return this->Rprime();
        case MOVE::R2:
            return this->R2();
        case MOVE::U:
            return this->U();
        case MOVE::UPRIME:
            return this->Uprime();
        case MOVE::U2:
            return this->U2();
        case MOVE::D:
            return this->D();
        case MOVE::DPRIME:
            return this->Dprime();
        case MOVE::D2:
            return this->D2();
        case MOVE::F:
            return this->F();
        case MOVE::FPRIME:
            return this->Fprime();
        case MOVE::F2:
            return this->F2();
        case MOVE::B:
            return this->B();
        case MOVE::BPRIME:
            return this->Bprime();
        case MOVE::B2:
            return this->B2();
    }
}


// action perfomed when someon called invert(move)
RubiksCube &RubiksCube::invert(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->Lprime();
        case MOVE::LPRIME:
            return this->L();
        case MOVE::L2:
            return this->L2();
        case MOVE::R:
            return this->Rprime();
        case MOVE::RPRIME:
            return this->R();
        case MOVE::R2:
            return this->R2();
        case MOVE::U:
            return this->Uprime();
        case MOVE::UPRIME:
            return this->U();
        case MOVE::U2:
            return this->U2();
        case MOVE::D:
            return this->Dprime();
        case MOVE::DPRIME:
            return this->D();
        case MOVE::D2:
            return this->D2();
        case MOVE::F:
            return this->Fprime();
        case MOVE::FPRIME:
            return this->F();
        case MOVE::F2:
            return this->F2();
        case MOVE::B:
            return this->Bprime();
        case MOVE::BPRIME:
            return this->B();
        case MOVE::B2:
            return this->B2();
    }
}

 // randomShuffleCube function 

 vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(unsigned int times) 
 {
     vector<MOVE> moves_performed;
    srand(time(0));
    for (unsigned int i = 0; i < times; i++) {
        unsigned int selectMove = (rand() % 18);
        moves_performed.push_back(MOVE(selectMove));
        this->move(MOVE(selectMove));
    }
    return moves_performed;
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

