// this is the generic class which contain the comman components of rubiks cube. 
// despite of type of solver we use or type of model we use. 


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
    enum class MOVE{
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    // class represnt all types of color. 
    enum class COLOR {
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
  //  virtual vector<MOVE> randomSuffle(int times);

    // given a rubiks cube and print the cube in planar form. 
    /* As you know the printRubikCube it's common for all types of model, but instead of creating it's 
    virtual we create help function virtual */
    void printRubikCube(); 

    /*
     * Returns the color of the cell at (row, col) in face.
     * If Rubik's Cube face is pointing at you, then the row numbering starts from the
     * top to bottom, and column numbering starts from the left to right.
     * The rows and columns are 0-indexed.
     * @param Face, row, and column index
     */ 

    virtual COLOR getColor(FACE f, int row, int col)const = 0;

    char getColorLetter(COLOR color);

    // left moves
    virtual RubiksCube & L() = 0;
    virtual RubiksCube &Lprime() = 0;
    virtual RubiksCube &L2() = 0;

    // upper moves
    virtual RubiksCube & U() = 0;
    virtual RubiksCube &Uprime() = 0;
    virtual RubiksCube &U2() = 0;

    // front moves
    virtual RubiksCube &F() = 0;
    virtual RubiksCube &Fprime() = 0;
    virtual RubiksCube &F2() = 0;

    // Right moves
    virtual RubiksCube &R() = 0;
    virtual RubiksCube &Rprime() = 0;
    virtual RubiksCube &R2() = 0;


};