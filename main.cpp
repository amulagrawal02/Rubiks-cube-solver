#include <bits/stdc++.h>
//#include "RubiksCube.cpp"
#include "RubiksCube3dArray.cpp"
#include "./Solver/DFSSolver.h"
#include "./Solver/BFSSolver.h"
#include "./Solver/IDDFSSolver.h"

using namespace std; 
int main()
{   
     RubiksCube3dArray cube1;
     RubiksCube3dArray cube2;

     // // for(int i = 0; i< 10; i++)
     // // {
     // //      obj.randomSuffle();
     // // }
     
     //  obj.L();
     //   obj.printRubikCube();
    
     // //  obj.Uprime();
    
     // //  obj.printRubikCube();

     // obj.F();
     // //  obj.printRubikCube();
     // //  obj.Uprime();
    
     //  obj.printRubikCube();
     //  obj.R();
     //  obj.printRubikCube();

     
     // obj.D();
     // obj.printRubikCube();

     // obj.B();
     // obj.B2();

     // obj.Rprime();
     // obj.Bprime();
     
     // // obj.R();
    
     //  obj.printRubikCube();

     // // obj.Rprime();
     // // obj.printRubikCube();

     // // obj.Fprime();
     // // obj.printRubikCube();

     // // obj.D();
     // // obj.printRubikCube();
     // // obj.U();
     // // obj.printRubikCube();
//      obj.Dprime();
//      obj.printRubikCube();


//     cout<<obj.isSolve()<<endl;

//      obj.move(RubiksCube :: MOVE(1));
//      obj.printRubikCube();

     // random shuffle 
     vector<RubiksCube :: MOVE> randomMove =  cube1.randomShuffleCube(7);

     cube1.printRubikCube();
     cout<<"Random moves to solve the cube"<<endl;
     for(auto mv : randomMove)
     { 
        cout<<cube2.getMove(mv)<<" ";
     }
     cout<<endl;
    // DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube1, 6);
    // BFSSolver<RubiksCube3dArray, Hash3d> bfsSolver(cube1);
     
     IDDFSSolver<RubiksCube3dArray, Hash3d> iddfsSolver(cube1,8);


     vector<RubiksCube :: MOVE> movesToSolve = iddfsSolver.solve();

     iddfsSolver.rubikscube.printRubikCube();
     cout<<"After solve moves to solve the cube"<<endl;
     for(auto mv : movesToSolve)
     {
          
        cout<<cube2.getMove(mv)<<" ";
     }
     // cout<<endl;


    

}