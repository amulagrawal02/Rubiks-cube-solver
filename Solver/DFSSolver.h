

#include<bits/stdc++.h>
#include "../RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H



// T represent the RubiksCube3dArray, RubiksCube1dArray, and RubiksCubebitArray
// H represent the hash function for all the 
template<typename T, typename H>
class DFSSolver
{

    private : 
    vector<RubiksCube :: MOVE> moves;
    int max_search_depth;

    bool dfs(int depth)
    {
        // base case; 
        if(rubikscube.isSolve()) return true;

        // pruning 
        if(depth > max_search_depth) return false; 

        // logic
        for(int i = 0; i< 18; i++)
        {
            rubikscube.move(RubiksCube :: MOVE(i));
            // cout<<"printing: "<<RubiksCube::MOVE(i)<<endl;
            moves.push_back(RubiksCube :: MOVE(i));

            if(dfs(depth + 1)) return true;

            moves.pop_back();
            rubikscube.invert(RubiksCube :: MOVE(i));

        }
        return false; 
    }
       
    public : 
    T rubikscube;
   
    DFSSolver(T rb, int msd = 8)
    {
        rubikscube = rb;
        max_search_depth = msd;
    }

    vector<RubiksCube :: MOVE> solve()
    {
        dfs(1);
        return moves;
    }

};

#endif //RUBIKS_CUBE_SOLVER_DFSSOLVER_H


