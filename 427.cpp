/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return NULL;
        }
        return helper(grid, 0, 0, grid.size(), grid[0].size());
    }

    Node* helper(vector<vector<int>>& grid, int LeftUpX, int LeftUpY, int RightDownX, int RightDownY){
        int sign = grid[LeftUpX][LeftUpY];
        bool flag = true;
        for(int i = LeftUpX; i <= RightDownX){
            for(int j = LeftUpY; j <= RightDownY; j++){
                if(sign != grid[x][y]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            return new Node(sign == 1, true, NULL, NULL, NULL, NULL);
        }
        Node* curNode = new Node(false, false, NULL, NULL, NULL, NULL);
        curNode->topLeft = helper(grid, LeftUpX, LeftUpY, (RightDownX - LeftDownX)/2, (RightDownY - LeftDownY)/2);
        curNode->topRight = helper(grid, LeftUpX, (RightDownX - LeftDownX + 1) / 2, (RightDownX - LeftDownX)/2, RightDownY);
        curNode->bottomLeft = helper(grid, (RightDownX - LeftUpX + 1)/2, LeftUpY, RightDownX, (RightDownY - LeftDownY)/2);
        curNode->bottomRight = helper(grid, (RightDownX - LeftUpX + 1)/2, (RightDownX - LeftDownX + 1) / 2, RightDownX, RightDownY);
        return curNode;
    }
};

