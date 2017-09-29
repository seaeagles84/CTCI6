/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        
        int max_global = 0;
        for (int i = 0; i < points.size(); i++) {
            //Must be inside the first loop! 
            unordered_map<double,int> hash_slope;
            int same = 1;
            int infinite = 0;
            for (int j = i+1; j < points.size(); j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    same++;
                } else if (points[j].x == points[i].x) {
                    infinite++;
                } else {
                    double slope = double(points[j].y - points[i].y)/double(points[j].x - points[i].x);
                    cout << points[j].y - points[i].y << endl;
                    cout << points[j].x - points[i].x << endl;
                    cout << "slope: " << slope << endl;
                    hash_slope[slope]++;
                    
                    cout << (double)(94911150.0/94911151.0) << endl;
                    cout << (double)(8.0/3.0) << endl;
                }
            }
            
            int local_max = infinite;
            for (auto it = hash_slope.begin(); it != hash_slope.end(); it++) {
                if (it->second > local_max)
                    local_max = it->second;
            }
            
            local_max = local_max+same;
            
            if (max_global < local_max)
                max_global = local_max;
            
            cout << "same/infinite/local_max = " << same << " " << infinite << " " << local_max << endl;
        }
        return max_global; 
    }
};
