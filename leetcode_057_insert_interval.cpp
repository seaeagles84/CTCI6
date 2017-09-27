/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        vector<Interval> outcome;
        int newstart = -1;
        int newend = -1;
        int i;
        
        if (intervals.size() == 0) {
            Interval tempInterval(newInterval.start, newInterval.end); 
            outcome.push_back(tempInterval);
            cout << "hello!" << endl;
            return outcome;
        }
        
        for (i = 0; i < intervals.size(); i++) {
            // No overlap 
            if (intervals[i].end < newInterval.start) {
                outcome.push_back(intervals[i]);
                
            } else { // intervals[i].end >= newInterval.start
                
                if (newstart == -1) {
                    // Before the current interval 
                    if (intervals[i].start > newInterval.end) {
                        Interval tempInterval(newInterval.start, newInterval.end); 
                        outcome.push_back(tempInterval);
                        i = i;
                        break;
                    } else { // Overlap with the current interval
                        newstart = min(intervals[i].start, newInterval.start);
                        // Ending with current one (not touching the next one)
                        if (i != (intervals.size()-1) && intervals[i+1].start > newInterval.end) {
                            newend = max(intervals[i].end, newInterval.end);
                            Interval tempInterval(newstart, newend); 
                            outcome.push_back(tempInterval);
                            i++;
                            break;
                        }                    
                    }
                } else {
                    if (intervals[i].start > newInterval.end) {
                        newend = max(intervals[i-1].end , newInterval.end);
                        Interval tempInterval(newstart, newend); 
                        outcome.push_back(tempInterval);
                        i = i;
                        break;
                    }
                }
            }
        }
        
        if (i == intervals.size()) {
            if (newstart == -1) { // the last one
                Interval tempInterval(newInterval.start, newInterval.end); 
                outcome.push_back(tempInterval);        
            } else if (newend == -1) { // merging up to the last one
                newend = max(intervals[i-1].end , newInterval.end);
                Interval tempInterval(newstart, newend); 
                outcome.push_back(tempInterval);
            }
        }
        
        for (; i < intervals.size(); i++) {
            outcome.push_back(intervals[i]);
        }
        
        return outcome;
    }
};
