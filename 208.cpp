class Trie {
public:
    unordered_set<string> words;
    /** Initialize your data structure here. */
    Trie() {
        words = unordered_set<string>();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        for(unsigned i = 1; i <= word.size(); i++)
            words.insert(word.substr(0, i));
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return words.count(word) != 0
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return words.count(word) != 0
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
