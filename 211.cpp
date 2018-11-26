class WordDictionary {
public:
    class dictNode{
    public:
        char c;
        bool isEnd;
        vector<dictNode *> childrens;

        dictNode(char character, bool end){
            c = character;
            isEnd = end;
            childrens = vector<dictNode *>();
        }
    };

    dictNode* head;
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new dictNode('.', false);
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        dictNode* current = head;
        for(unsigned i = 0; i < word.size(); i++){
            bool flag = false;
            for(unsigned j = 0; j < current->childrens.size(); j++){
                if(word[i] == current->childrens[j]->c){
                    current = current->childrens[j];
                    flag = true;
                    if(i == word.size() - 1)
                        current->isEnd = true;
                    break;
                }
            }
            if(!flag){
                dictNode* temp = new dictNode(word[i], i == word.size()-1);
                current->childrens.push_back(temp);
                current = temp;
            }
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(word, 0, head);
    }

    bool helper(string& word, int index, dictNode* current){
        if(word[index] == '.'){
            for(unsigned j = 0; j < current->childrens.size(); j++){
                if(index == word.size() - 1 && current->childrens[j]->isEnd == true)
                    return true;
                if(helper(word, index + 1, current->childrens[j]))
                    return true;
            }
            return false;
        }
        for(unsigned j = 0; j < current->childrens.size(); j++){
            if(word[index] == current->childrens[j]->c){
                current = current->childrens[j];
                if(index == word.size() - 1 && current->isEnd == true)
                    return true;
                else if(index == word.size() - 1)
                    return false;
                return helper(word, index + 1, current);
                break;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
