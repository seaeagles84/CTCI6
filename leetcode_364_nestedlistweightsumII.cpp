/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// my own solution.
class MyPair {
public:
    int m_value;
    int m_depth;
    MyPair(int value, int depth) : m_value(value), m_depth(depth) {}
};

class Solution {
public:
    int depthSumInverse(const vector<NestedInteger>& nestedList, int depth, queue<MyPair> &myQ) {
        
        int maxdepth = depth;
        for (const auto& element : nestedList) {
            if (element.isInteger()) {
                myQ.push(MyPair(element.getInteger(),depth));
            } else {
                maxdepth = max(depthSumInverse(element.getList(), depth+1, myQ), maxdepth);
            }
        }
        return maxdepth;
        
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<MyPair> myQ;
        int maxdepth = depthSumInverse(nestedList, 1, myQ);
        
        int sum = 0;
        while (!myQ.empty()) {
            MyPair myp = myQ.front();
            myQ.pop();
            sum += myp.m_value * (maxdepth + 1 - myp.m_depth);
        }
         
        return sum;
    }
};

// Better solution in the discussion
// Q. Can this be realized in C++?  
public int depthSumInverse(List<NestedInteger> nestedList) {
    int unweighted = 0, weighted = 0;
    while (!nestedList.isEmpty()) {
        List<NestedInteger> nextLevel = new ArrayList<>();
        for (NestedInteger ni : nestedList) {
            if (ni.isInteger())
                unweighted += ni.getInteger();
            else
                nextLevel.addAll(ni.getList());
        }
        weighted += unweighted;
        nestedList = nextLevel;
    }
    return weighted;
}

// Here is the C++ version!!!
// Using vector's 'insert()' function!!! in the end. First time using it in this way.
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int unweighted = 0, weighted = 0;
        while (nestedList.size()) {
            vector<NestedInteger> nextLevel;
            for (NestedInteger ni : nestedList) {
                if (ni.isInteger())
                    unweighted += ni.getInteger();
                else
                    nextLevel.insert(nextLevel.end(), ni.getList().begin(), ni.getList().end());
            }
            weighted += unweighted;
            nestedList = nextLevel;
        }
        return weighted;

    }
};
