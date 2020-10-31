/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//加入长度信息,提供后续判断依据。

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root) return "#";
        string res = to_string(root->val) + " " + to_string(root->children.size());
        for(Node* node:root->children)
            res+=" "+serialize(node);
        return res;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream ss(data);
        return dfs(ss);
    }

    Node* dfs(istringstream& ss){
        string item;
        ss>>item;
        if(item=="#") return nullptr;
        else{
            Node* node = new Node(stoi(item));
            ss>>item;
            for(int i =0;i<stoi(item);i++)
                node->children.push_back(dfs(ss));
            return node;
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));