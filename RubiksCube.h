#include<bits/stdc++.h>
using namespace std; 

class RubiksCube{

    public : 

    // class represnt all types of faces in the cubes
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };


    // class represnt all types of moves. 
    enum class move{
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    // class represnt all types of color. 
    enum class color {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };


    // random suffle fucntion 
    // function returns us the types of moves we have to perform to suffle the cube.  
    // times represent = no. of moves me make 
    virtual vector<move> randomSuffle(int times);

    virtual void printRubikCube(); 


};