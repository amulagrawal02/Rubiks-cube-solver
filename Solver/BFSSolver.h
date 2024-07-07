#include<bits/stdc++.h>
#include "../RubiksCube.h"


#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

// T represent the RubiksCube3dArray, RubiksCube1dArray, and RubiksCubebitArray
// H represent the hash function for all the 
template<typename T, typename H>
class BFSSolver{

    private : 
    vector<RubiksCube :: MOVE> moves;
    unordered_map<T, bool ,H> visisted;
    unordered_map<T, RubiksCube:: MOVE, H> pathtrack;
    T bfs()
    {
        queue<T> q; 
        q.push(rubikcube);
        visisted[rubikcube] = true; 

        while(!q.empty())
        {
            T cr = q.front();
            q.pop();
            if(cr.isSolve()) 
            {
                return cr; 
            }
            for(int i = 0; i< 18; i++)
            {
                auto curr_move = RubiksCube :: MOVE(i);
                cr.move(curr_move);
                if(!visisted[cr])
                {
                    visisted[cr] = true; 
                    pathtrack[cr] = curr_move;
                    q.push(cr);
                }
                cr.invert(curr_move);
            }
        }
        return rubikcube;

    }

    public : 
    T rubikcube;
    BFSSolver(T _rubikcube)
    {
        rubikcube = _rubikcube;
    }

    vector<RubiksCube :: MOVE> solve()
    {
        T solveCube =  bfs();
        // if true the program continues normally and if fail program terminates abnormally
        assert(solveCube.isSolve());

        T curr_cube = solveCube;

        while(!(curr_cube == rubikcube))
        {
            RubiksCube :: MOVE curr_move = pathtrack[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);

        }
        rubikcube = solveCube;
        reverse(moves.begin(), moves.end());
        return moves;
    }


};

#endif //RUBIKS_CUBE_SOLVER_BFSSOLVER_H