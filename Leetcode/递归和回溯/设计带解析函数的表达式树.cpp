class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};

class TreeBuilder {
    static std::unordered_map<std::string, std::function<int(int, int)>> operators;
    struct NodeImpl : public Node {
        const std::string op;
        const int value;
        const Node* left;
        const Node* right;

        explicit NodeImpl(const std::string& op)
        : Node(), op(op), value(0), left(nullptr), right(nullptr) {}

        explicit NodeImpl(int value)
        : Node(), op(""), value(value), left(nullptr), right(nullptr) {}

        virtual ~NodeImpl() {
            delete left;
            delete right;
        }

        virtual int evaluate() const override {
            return op.empty()
                    ? value
                    : operators.at(op)(left->evaluate(), right->evaluate());
        }
    };

public:
    static Node* buildTree(const std::vector<std::string>& postfix) {
        std::stack<Node*> stack;
        for (const std::string& s : postfix) {
            if(s=="+" || s=="-" || s=="*" || s=="/") {
                NodeImpl* node = new NodeImpl(s);
                node->right = stack.top();
                stack.pop();
                node->left = stack.top();
                stack.pop();
                stack.push(node);
            }
            else{
                int value = std::stoi(s);
                stack.push(new NodeImpl(value));
            }
        }
        return stack.top();
    }

    template <typename F>
    static void register_operator(const std::string& op, const F& action) {
        operators[op] = action;
    }
};

namespace {

auto operators_init() {
    std::unordered_map<std::string, std::function<int(int, int)>> operators;
    operators["+"] = [](int a, int b) { return a + b; };
    operators["-"] = [](int a, int b) { return a - b; };
    operators["*"] = [](int a, int b) { return a * b; };
    operators["/"] = [](int a, int b) { return a / b; };
    return operators;
}

}

std::unordered_map<std::string, std::function<int(int, int)>>
        TreeBuilder::operators = operators_init();
