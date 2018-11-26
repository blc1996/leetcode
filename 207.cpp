class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> courses(numCourses, vector<int>());
        for(unsigned i = 0; i < prerequisites.size(); i++){
            courses[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        unordered_set<int> grey, black;
        for(unsigned i = 0; i < numCourses; i++){
            if(!dfs(courses, i, grey, black))
                return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, int vertex, unordered_set<int>& grey, unordered_set<int>& black){
        if(grey.count(vertex))
            return false;

        grey.insert(vertex);
        for(unsigned i = 0; i < graph[vertex].size(); i++){
            if(black.count(graph[vertex][i]) == 0){
                if(!dfs(graph, graph[vertex][i], grey, black))
                    return false;
            }
        }
        grey.erase(vertex);
        black.insert(vertex);
        return true;
    }
};
