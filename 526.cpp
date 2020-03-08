class Solution {
public:
    unordered_set<int> set;
    int sum;

    int countArrangement(int N) {
        set = unordered_set<int>();
        sum = 0;
        for(int i = 1; i <= N; i++){
            helper(1, i, N);
        }
        return sum;
    }

    void helper(int index, int num, int N){
        if(index % num != 0 && num % index != 0)
            return;
        set.insert(num);
        for(int i = 1; i <= N; i++){
            if(set.count(i) == 0)
                helper(index + 1, i, N);
        }
        if(index == N)
            sum++;
        set.erase(num);
    }
};


class Solution {
public:
    unordered_set<int> set;
    int sum;

    int countArrangement(int N) {
        set = unordered_set<int>();
        sum = 0;
        for(int i = 1; i <= N; i++){
            helper(1, i, N);
        }
        return sum;
    }

    void helper(int index, int num, int N){
        if(index % num != 0 && num % index != 0)
            return;
        set.insert(num);
        for(int i = 1; i <= N; i++){
            if(set.count(i) == 0)
                helper(index + 1, i, N);
        }
        if(index == N)
            sum++;
        set.erase(num);
    }
};