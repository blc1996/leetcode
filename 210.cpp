class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> courses(numCourses, vector<int>());
        for(unsigned i = 0; i < prerequisites.size(); i++){
            courses[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        unordered_set<int> grey, black;
        vector<int> output;
        for(unsigned i = 0; i < numCourses; i++){
            if(!black.count(i) && !dfs(courses, i, grey, black, output))
                return vector<int>();
        }
        return output;
    }

    bool dfs(vector<vector<int>>& graph, int vertex, unordered_set<int>& grey, unordered_set<int>& black, vector<int>& output){
        if(grey.count(vertex))
            return false;

        grey.insert(vertex);
        for(unsigned i = 0; i < graph[vertex].size(); i++){
            if(black.count(graph[vertex][i]) == 0){
                if(!dfs(graph, graph[vertex][i], grey, black, output))
                    return false;
            }
        }
        grey.erase(vertex);
        black.insert(vertex);
        output.push_back(vertex);
        return true;
    }
};
