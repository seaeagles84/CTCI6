// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    // Based on the discussion solution... neat. 
    int findCelebrity(int n) {
        if (n <= 1)
            return -1;
        
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate,i))
                candidate = i;
        }
        
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (!knows(i, candidate) || (i < candidate && knows(candidate, i))) return -1;
            }
        }
        
        return candidate;
    }
};
