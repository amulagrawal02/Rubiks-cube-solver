#include <bits/stdc++.h>
//#include "RubiksCube.cpp"
#include "RubiksCube3dArray.cpp"
using namespace std; 
int main()
{   
     RubiksCube3dArray obj;

     // for(int i = 0; i< 10; i++)
     // {
     //      obj.randomSuffle();
     // }
     
      obj.L();
      obj.printRubikCube();
    
     //  obj.Uprime();
    
     //  obj.printRubikCube();

     obj.F();
     //  obj.printRubikCube();
     //  obj.Uprime();
    
      obj.printRubikCube();
      obj.R();
      obj.printRubikCube();

     
     obj.D();
     obj.printRubikCube();

     obj.B();
     obj.B2();

     obj.Rprime();
     obj.Bprime();
     
     // obj.R();
    
      obj.printRubikCube();

     // obj.Rprime();
     // obj.printRubikCube();

     // obj.Fprime();
     // obj.printRubikCube();

     // obj.D();
     // obj.printRubikCube();
     // obj.U();
     // obj.printRubikCube();
     // obj.Dprime();
     // obj.printRubikCube();



     

}