#include<bits/stdc++.h>
#include "../RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_IDASTAR_H
#define RUBIKS_CUBE_SOLVER_IDASTAR_H


template <typename T, typename H>
class IDAstar{
    
    private : 

    

    vector<RubiksCube :: MOVE> moves; 
    unordered_map<T, bool, H> visited; 
    unordered_map<T, RubiksCube :: MOVE, H> move_done;

    void resetStructure() {
        moves.clear();
        move_done.clear();
        visited.clear();
    }
    
    struct Node {
        T cube;
        int depth;
        int estimate;

        Node(T _cube, int _depth, int _estimate) : cube(_cube), depth(_depth), estimate(_estimate) {};
    };

    struct compareCube {
        bool operator()(pair<Node, int> const &p1, pair<Node, int> const &p2) {
            auto n1 = p1.first, n2 = p2.first;
            if (n1.depth + n1.estimate == n2.depth + n2.estimate) {
                return n1.estimate > n2.estimate;
            } else return n1.depth + n1.estimate > n2.depth + n2.estimate;
        }
    };

    pair<T, int> idastart(int bound)
    {
       priority_queue<pair<Node, int>, vector<pair<Node, int>>, compareCube> pq;
       Node start = Node(rubikcube , 0, 0);

       pq.push({start, 0});

       int next_bound = 100; 

       while(!pq.empty())
       {
         auto p = pq.top();
         Node node = p.first; 
         pq.pop();
         if(visited[node.cube]) continue;
        visited[node.cube] = true;
        move_done[node.cube] = RubiksCube :: MOVE(p.second);

        if(node.cube.isSolve()) return {node.cube, bound};
        node.depth++;
        for(int i = 0; i<18; i++)
        {
            auto curr_move = RubiksCube :: MOVE(i);
            node.cube.move(curr_move);
            if(!visited[node.cube])
            {
                node.estimate = 0;
                if(node.estimate + node.depth > bound)
                {
                    next_bound = min(next_bound, node.estimate + node.depth);
                }
                else{
                    pq.push({node, i});
                }
            }
            node.cube.invert(curr_move);
        }
        return {rubikcube, next_bound};

       }


    }

    public : 
    T rubikcube; 
    IDAstar(T rb)
    {
        rubikcube = rb; 
    }

    vector<RubiksCube :: MOVE> solve()
    {
        int bound = 1;
        auto p = idastart(bound);
        while (p.second != bound) {
             resetStructure();
            bound = p.second;
            p = idastart(bound);
        }
        T solved_cube = p.first;
        assert(solved_cube.isSolved());
        T curr_cube = solved_cube;
        while (!(curr_cube == rubikcube)) {
            RubiksCube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubikcube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }


};

#endif //RUBIKS_CUBE_SOLVER_IDASTAR_H