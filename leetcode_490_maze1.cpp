class Solution {
public:
    vector<int> getEnd(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir) {
        int row = maze.size();
        int col = maze[0].size();
        
        vector<int> end = start;
        while (end[0] >= 0 && end[0] < row && end[1] >= 0 && end[1] < col && maze[end[0]][end[1]] == 0) {
            end[0] += dir[0];
            end[1] += dir[1];
        }
        end[0] -= dir[0];
        end[1] -= dir[1];
        return end;
    }
    
    bool hasPathImpl(vector<vector<int>>& maze, vector<int>& cur, vector<int>& destination, vector<vector<bool>>& visited) {
        int row = maze.size();
        int col = maze[0].size();
        
        if (visited[cur[0]][cur[1]])
            return false;
        
        if (cur == destination) {
            //cout << "halo1" << endl;
            return true;
        }
        
        visited[cur[0]][cur[1]] = true;
        
        vector<vector<int>> dir {{-1,0},{1,0},{0,1},{0,-1}}; //L, R, U, D
        for (int i = 0; i < dir.size(); i++) {
            vector<int> next = getEnd(maze, cur, dir[i]);
            if (next == destination || hasPathImpl(maze, next, destination, visited)) {
                //cout << "halo2" << endl;;
                return true;
            }
        }
        
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size();
        int col = maze[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col));
        
        return hasPathImpl(maze, start, destination, visited);
    }
};
