class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(E >= C || F >= D || G <= A || H <= B)
            return (C - A) * (D - B) + (G - E) * (H - F);
        else if(E >= A && F >= B && G <= C && H <= D)
            return (C - A) * (D - B);
        else if(E < A && F < B && G > C && H > D)
            return (G - E) * (H - F);
        else{
            int reduce1 = min(abs((H-B)*(C-E)), abs((D-F)*(C-E)));
            int reduce2 = min(abs((H-B)*(G-A)), abs((G-A)*(D-F)));
            int reduce3 = min(abs(C-E)*(D-B), abs((C-A)*(H-B)));
            int reduce4 = min(abs((G-A)*(D-B)), abs((C-A)*(D-F)));
            int reduce5 = min(abs((G-E)*(D-F)), abs((G-E)*(H-B)));
            int reduce6 = min(abs((G-A)*(H-F)), abs((C-E)*(H-F)));
            int reduce7 = min(abs((G-E)*(D-B)), abs((C-A)*(H-F)));
            int reduce = min(reduce1, reduce2);
            reduce = min(reduce, reduce3);
            reduce = min(reduce, reduce4);
            reduce = min(reduce, reduce5);
            reduce = min(reduce, reduce6);
            reduce = min(reduce, reduce7);
            return (C - A) * (D - B) + (G - E) * (H - F) - reduce;
        }
    }
};
