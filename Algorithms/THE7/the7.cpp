#include "the7.h"

// Implement your solution after this line

std::vector<int> findShortestPathAndCost(int n, std::vector<Road> roads, int from, int to, int& cost) {
    std::vector<int> path;
    std::vector<int> distances(n, INT_MAX);
    std::vector<bool> visited(n, false);
    std::vector<int> ancestors(n, INT_MAX);
    int i, j, k, curr;
    distances[from] = 0;
    for(i = 0; i < n; i++) {
        curr = INT_MAX;
        for(j = 0; j < n; j++) {
            if(curr == INT_MAX) {
                if(!visited[j] && distances[j] < curr) {
                    curr = j;
                }
            }
            else {
                if(!visited[j] && distances[j] < distances[curr]) {
                    curr = j;
                }
            }
            
        }
        visited[curr] = true;
        k = roads.size();
        for(j = 0; j < k; j++) {
            if(roads[j].buildings.first == curr) {
                if(distances[roads[j].buildings.second] > distances[curr] + roads[j].time) {
                    distances[roads[j].buildings.second] = distances[curr] + roads[j].time;
                    ancestors[roads[j].buildings.second] = curr;
                }    
            }
            if(roads[j].buildings.second == curr) {
                if(distances[roads[j].buildings.first] > distances[curr] + roads[j].time) {
                    distances[roads[j].buildings.first] = distances[curr] + roads[j].time;
                    ancestors[roads[j].buildings.first] = curr;
                }    
            }
        }
            
    }
    curr = to;
    while(ancestors[curr] < INT_MAX) {
        path.insert(path.begin(), curr);
        curr = ancestors[curr];
    }
    path.insert(path.begin(), curr);
    cost += distances[to];
    return path;
}

void CanCatch(int n, std::vector<Road> roads, int s, int d, int x, int y, int l, int printPath) {
    // You can change these variables. These are here for demo only.
    std::vector<int> path, t1, t2, t3, t4, t5, t6;
    int cost = 0, temp_cost = 0;
    t1 = findShortestPathAndCost(n, roads, s, x, temp_cost);
    t2 = findShortestPathAndCost(n, roads, x, y, temp_cost);
    t3 = findShortestPathAndCost(n, roads, y, d, temp_cost);
    t4 = findShortestPathAndCost(n, roads, s, y, cost);
    t5 = findShortestPathAndCost(n, roads, y, x, cost);
    t6 = findShortestPathAndCost(n, roads, x, d, cost);
    if(temp_cost <= cost && temp_cost <= l) {
        std::cout << "YES BOTH " << temp_cost << "MINUTES" << std::endl;
        if(printPath) {
            path.insert(path.end(), t1.begin(), t1.end());
            path.insert(path.end(), t2.begin() + 1, t2.end());
            path.insert(path.end(), t3.begin() + 1, t3.end());
            PrintRange(path.begin(), path.end());
        }
        return;
    }
    else if(cost <= l) {
        std::cout << "YES BOTH " << cost << "MINUTES" << std::endl;
        if(printPath) {
            path.insert(path.end(), t4.begin(), t4.end());
            path.insert(path.end(), t5.begin() + 1, t5.end());
            path.insert(path.end(), t6.begin() + 1, t6.end());
            PrintRange(path.begin(), path.end());
        }
        return;
    }
    cost = temp_cost = 0;
    t1 = findShortestPathAndCost(n, roads, s, x, temp_cost);
    t2 = findShortestPathAndCost(n, roads, x, d, temp_cost);
    t3 = findShortestPathAndCost(n, roads, s, y, cost);
    t4 = findShortestPathAndCost(n, roads, y, d, cost);
    if(temp_cost <= cost && temp_cost <= l) {
        std::cout << "YES PRINTER " << temp_cost << "MINUTES" << std::endl;
        if(printPath) {
            path.insert(path.end(), t1.begin(), t1.end());
            path.insert(path.end(), t2.begin() + 1, t2.end());
            PrintRange(path.begin(), path.end());
        }
        return;
    }
    else if(cost <= l) {
        std::cout << "YES DORM " << cost << "MINUTES" << std::endl;
        if(printPath) {
            path.insert(path.end(), t3.begin(), t3.end());
            path.insert(path.end(), t4.begin() + 1, t4.end());
            PrintRange(path.begin(), path.end());
        }
        return;
    }
    cost = 0;
    path = findShortestPathAndCost(n, roads, s, d, cost);
    if(cost <= l) {
        std::cout << "YES DIRECTLY " << cost << "MINUTES" << std::endl;
        if(printPath) {
            PrintRange(path.begin(), path.end());
        }
        return;
    }
    else {
        std::cout << "IMPOSSIBLE";
        return;
    }




    
    // You can use the PrintRange function to print the path.
    // It helps you print elements of containers with iterators (e.g., std::vector).
    // Usage: PrintRange(path.begin(), path.end());
    
}