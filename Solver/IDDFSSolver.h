#include<bits/stdc++.h>
#include "../RubiksCube.h"
#include "./DFSSolver.h"


#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H


template <typename T, typename H>
class IDDFSSolver{

    public :
    T rubikscube;
    int max_depth;
    IDDFSSolver(T _rubikscube, int _max_depth_ = 8)
    {
        rubikscube = _rubikscube;
        max_depth = _max_depth_;
    }

    vector<RubiksCube :: MOVE> solve()
    {
        vector<RubiksCube :: MOVE> moves;

        for(int i = 1; i<=max_depth; i++)
        {
            DFSSolver<T, H> dfsSolver(rubikscube, i);
            moves = dfsSolver.solve();

            // here dfsSolver.rubikscube represent the solved cube in dfsSolver class 
            // here we don't check the rubiksCube which define in this class
            if(dfsSolver.rubikscube.isSolve())
            {
                // now  the rubikscube in dfsSolver classed is solved we also convert this
                // rubikscube to be solved. 

                rubikscube = dfsSolver.rubikscube;
                break;
            }
        }
        return moves;

    }


};


#endif //RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H