class Solution {
public:
    bool canFinishImpl(int cID, unordered_map<int,vector<int>>& crs, vector<bool>& visited, vector<bool>& mytested) {
        
        //ridiculous: why was this IDE (in leekcode) acting strangely and not recognizing my change here...
        //once I moved this line down to 12 then back to here, now this line worked and the time from 1200 ms to 3 ms....
        mytested[cID] = true;
        
        if (visited[cID]) 
            return false;
        
        //mytested[cID] = true;
        //cout << "tested of CID: " << cID << " " << tested[cID] << endl;
        
        visited[cID] = true;
        for (int j = 0; j < crs[cID].size(); j++) {
            int preq = crs[cID][j];
                if (!canFinishImpl(preq, crs, visited, mytested))
                    return false;
                    
                
        }
        visited[cID] = false;
        return true;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int,vector<int>> crs(numCourses);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int>& temp = crs[prerequisites[i].first];
            temp.push_back(prerequisites[i].second);
        }
        
        /*
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < crs[i].size(); j++)
                cout << crs[i][j] << " ";
            cout << endl;
        }
        */
        /*
        
        // Need to go over each case, because no guarantee that all courses are somehow connected.
        for (int i = 0; i < numCourses; i++) {
            vector<bool> visited(numCourses, false);
            queue<int> myqueue;
            myqueue.push(i);
            visited[i] = true;

            while (!myqueue.empty()) {
                int next = myqueue.front();
                myqueue.pop();
                
                for (int j = 0; j < crs[next].size(); j++) {
                    int preq = crs[next][j];
                    if (visited[preq]) {
                        cout << "i: " << i << " next: " << next << " j: " << j << " preq: " << preq << endl;
                        return false;
                    }
                    myqueue.push(preq);
                    visited[preq] = true;
                }
            }
        }
        */
        
        // Need to go over each case, because no guarantee that all courses are somehow connected.
        vector<bool> visited(numCourses, false);
        vector<bool> mytested(numCourses, false);
        int call = 0;
        for (int i = 0; i < numCourses; i++) {
            /* only if it has not been tested yet! */
            if (!mytested[i]) {
                call++;
                if (!canFinishImpl(i, crs, visited, mytested))
                    return false;
               
            }
        }
        
        cout << "# of first trial: " << call << endl;
                
        
        return true;
    }
};
