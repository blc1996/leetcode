class Solution {
public:
    bool DFSCore(int cur, vector<int>& res, vector<vector<int>>& graph, int terminate){
        res.push_back(cur);
        if(res.size() == terminate){
            return true;
        }
        for(int i = 0; i < graph.size(); i++){
            if(graph[cur][i]){
                graph[cur][i]--;
                if(DFSCore(i, res, graph, terminate)){
                    return true;
                }
                graph[cur][i]++;
            }
        }
        res.pop_back();
        return false;
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.size() == 0) return vector<string>();
        unordered_map<string, int> name2Idx;
        vector<string> idx2Name;
        int num = 0;
        for(int i = 0; i < tickets.size(); i++){
            if(!name2Idx.count(tickets[i][0])){
                name2Idx.insert({tickets[i][0], num++});
                idx2Name.push_back(tickets[i][0]);
            }
            if(!name2Idx.count(tickets[i][1])){
                name2Idx.insert({tickets[i][1], num++});
                idx2Name.push_back(tickets[i][1]);
            }
        }
        sort(idx2Name.begin(), idx2Name.end());
        name2Idx.clear();
        for(int i = 0; i < idx2Name.size(); i++){
            name2Idx.insert({idx2Name[i], i});
        }
        vector<vector<int>> graph(num, vector<int>(num, 0));
        for(int i = 0; i < tickets.size(); i++){
            graph[name2Idx[tickets[i][0]]][name2Idx[tickets[i][1]]]++;
        }
        vector<int> tempRes;
        DFSCore(name2Idx["JFK"], tempRes, graph, tickets.size() + 1);
        
        vector<string> res;
        for(int i : tempRes){
            res.push_back(idx2Name[i]);
        }
        return res;
    }
};