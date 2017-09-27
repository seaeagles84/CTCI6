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
        
        int i = 0;
        int size = intervals.size();
        while (i < size && intervals[i].end < newInterval.start) {
            outcome.push_back(intervals[i++]);
        }
        
        Interval mergedInterval = newInterval;
        while (i < size && intervals[i].start <= newInterval.end) {
            mergedInterval.start = min(intervals[i].start, mergedInterval.start);
            mergedInterval.end = max(intervals[i].end, mergedInterval.end);   
            i++;
        }
        outcome.push_back(mergedInterval);
        
        while (i < size) {
            outcome.push_back(intervals[i++]);
        }
        
        return outcome;
    }
};
