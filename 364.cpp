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
class Solution {
public:
    void depthSumInverseCore(const NestedInteger& integer, int level, int& sum){
        if(integer.isInteger()){
            sum += level * integer.getInteger();
        }else{
            auto list = integer.getList();
            for(auto i : list){
                depthSumInverseCore(i, level - 1, sum);
            }
        }
    }
    void getDepth(const NestedInteger& integer, int level, int& depth){
        if(integer.isInteger()){
            depth = max(depth, level);
        }else{
            level++;
            auto list = integer.getList();
            for(auto i : list){
                getDepth(i, level, depth);
            }
        }
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int sum = 0, depth = 1;
        for(auto i : nestedList){
            getDepth(i, 1, depth);
        }
        for(auto i : nestedList){
            depthSumInverseCore(i, depth, sum);
        }
        return sum;
    }
};