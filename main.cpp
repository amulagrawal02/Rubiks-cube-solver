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

     
     obj.U2();
     obj.printRubikCube();
     
     obj.R();
    
     obj.printRubikCube();


     

}