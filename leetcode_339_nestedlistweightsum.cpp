class Solution {
public:
    int depthSum(const vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (const auto &element : nestedList) {
            if (element.isInteger())
                sum += element.getInteger()*depth;
            else
                sum += depthSum(element.getList(), depth+1);
        }
        return sum;
    }

    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSum(nestedList, 1);
    }
};
