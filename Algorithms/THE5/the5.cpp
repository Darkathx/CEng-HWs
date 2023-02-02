#include "the5.h"

/* 
    in the5.h "struct Room" is defined as below:
    
    struct Room {
        int id;
        char content;
        vector<Room*> neighbors;
    };

*/

bool maze_DFS(Room* currRoom, vector<int>& path) {
    int res;
    path.push_back(currRoom->id);
    if(currRoom -> content == '*') {
        return 1;
    }
    currRoom -> content = 'v';
    for(int i = 0; i < currRoom->neighbors.size(); i++) {
        if(currRoom->neighbors[i]->content != 'v') {
            res = maze_DFS(currRoom->neighbors[i], path);
            path.push_back(currRoom->id);
            if(res == 1) {
                return 1;
            }
        }
    }
    return 0;
}
/*
void maze_DFS_iter(Room* firstRoom, vector<int>& path) {
    stack<Room*> s;
    Room* currRoom;
    s.push(firstRoom);
    while(!s.empty()) {
        currRoom = s.top();
        s.pop();
        path.push_back(currRoom->id);
        if(currRoom->content == 'v') {
            continue;
        }
        if(currRoom->content == '*') {
            while(!s.empty()) {
                currRoom = s.top;
                s.pop();
                path.push_back(currRoom->id);
            }
        }
        currRoom->content = 'v';
        for(int i = currRoom->neighbors.size() - 1; i >= 0; i--) {
            if(currRoom->neighbors[i]->content != 'v') {
                s.push(currRoom->neighbors[i]);
            }
        }
    }
}
*/

vector<int> maze_trace(vector<Room*> maze) { 

    vector<int> path;
    maze_DFS(maze[0], path);
    
    //your code here
    

    return path; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}


