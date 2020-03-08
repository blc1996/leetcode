class Solution {
public:
    int findHeightAndParent(TreeNode* root, int target, TreeNode** parent){
        queue<pair<TreeNode*, int>> q;
        unordered_map<TreeNode*, TreeNode*> mp;
        q.push(pair<TreeNode*, int>(root, 0));
        while(!q.empty()){
            TreeNode* curNode = q.front().first;
            int height = q.front().second;
            if(curNode->val == target){
                *parent = mp[curNode];
                return height;
            }
            q.pop();
            if(curNode->left){
                mp[curNode->left] = curNode;
                q.push(pair<TreeNode*, int>(curNode->left, height + 1));
            }
            if(curNode->right){
                mp[curNode->right] = curNode;
                q.push(pair<TreeNode*, int>(curNode->right, height + 1));
            }
        }
        *parent = NULL;
        return 0;
    }


    bool isCousins(TreeNode* root, int x, int y) {
        if(!root){
            return false;
        }
        TreeNode* parentNodeX, *parentNodeY;
        int heightX = findHeightAndParent(root, x, &parentNodeX);
        int heightY = findHeightAndParent(root, y, &parentNodeY);

        if(heightX == heightY && parentNodeX && parentNodeY && parentNodeX != parentNodeY){
            return true;
        }else{
            return false;
        }
    }
};