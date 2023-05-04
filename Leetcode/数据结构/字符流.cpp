struct TrieNode
{
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode* fail;
    TrieNode()
    {
        children = vector<TrieNode*>(26,nullptr);
        isEnd = false;
        fail = nullptr;
    }  
};

class StreamChecker {
public:
    TrieNode* temp;
    TrieNode* root;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(string word: words)
        {
            TrieNode* cur = root;
            for(int i = 0; i < word.size(); i ++)
            {
                int idx = word[i] - 'a';
                if(cur->children[idx] == nullptr)
                    cur->children[idx] = new TrieNode();
                cur = cur->children[idx];
            }
            cur->isEnd = true;
        }
        root->fail = root;
        queue<TrieNode*> q;
        for(int i = 0; i < 26; i ++)
        {
            if(root->children[i]!=nullptr)
            {
                root->children[i]->fail = root;
                q.push(root->children[i]);
            }
            else 
            {
                root->children[i] = root;
            }
        }

        while(!q.empty())
        {
            TrieNode* node = q.front(); q.pop();
            node->isEnd = node->isEnd | node->fail->isEnd;
            for(int i = 0; i < 26; i ++)
            {
                if(node->children[i]!=nullptr)
                {
                    node->children[i]->fail = node->fail->children[i];
                    q.push(node->children[i]);
                }
                else{
                    node->children[i] = node->fail->children[i];
                }
            }
        }

        temp = root;
    }
    
    bool query(char letter) {
        temp = temp->children[letter-'a'];
        return temp->isEnd;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */