#include <iostream>
#include <queue>

// Assume that one employee has no more than two collegues(junior staff members) to make it easy.
// Later it can be expanded.
struct node
{
    std::string position;
    node* first;
    node* second;
};

struct org_tree
{
    node* root;

    /** Create a root node, CEO in the company */
    static org_tree create_org_structure(const std::string& pos)
    {
        org_tree tree;
        tree.root = new node { pos, nullptr, nullptr };
        return tree;
    }

    static node* find(node* root, const std::string& value)
    {
        if (root == nullptr)
            return nullptr;
        if (root->position == value)
            return root;
        auto firstFound = org_tree::find(root->first, value);
        if (firstFound != nullptr)
            return firstFound;
        return org_tree::find(root->second, value);
    }

    bool addSubordinate(const std::string& manager, const std::string& subordinate)
    {
        auto managerNode = org_tree::find(root, manager);

        if (!managerNode) {
            std::cout << manager << "을(를) 찾을 수 없습니다. " << std::endl;
            return false;
        }
        if (managerNode->first && managerNode->second) {
            std::cout << manager << " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << std::endl;
            return false;
        }
        if(!managerNode->first)
            managerNode->first = new node {subordinate, nullptr, nullptr};
        else
            managerNode->second = new node {subordinate, nullptr, nullptr};
        
        std::cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << std::endl;
        return true;
    }

    /** level order traversal */
    static void levelOrder(node* start)
    {
        if (!start)
            return;
        std::queue<node*> q;
        q.push(start);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto current = q.front();
                q.pop();
                std::cout << current->position << ", ";
                if (current->first)
                    q.push(current->first);
                if (current->second)
                    q.push(current->second);
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    auto tree = org_tree::create_org_structure("CEO");

    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "물류팀장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("부사장", "재무부장");

    tree.levelOrder(tree.root);

    return 0;
}