#include <iostream>
#include <vector>
#include <memory>
#include <string>

class TreeNode {
public:
    std::string feature;
    double threshold;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    bool isLeaf;
    int classLabel;

    TreeNode(std::string feature, double threshold)
        : feature(feature), threshold(threshold), isLeaf(false), classLabel(-1) {}

    TreeNode(int classLabel)
        : isLeaf(true), classLabel(classLabel) {}
};

class DecisionTree {
public:
    std::shared_ptr<TreeNode> root;

    DecisionTree() : root(nullptr) {}

    void train(const std::vector<std::vector<double>>& data, const std::vector<int>& labels) {
        // Implement the training logic here
    root = buildTree(data, labels);
    }

    int predict(const std::vector<double>& instance) {
        return predict(instance, root);
    }

private:
    int predict(const std::vector<double>& instance, std::shared_ptr<TreeNode> node) {
        if (node->isLeaf) {
            return node->classLabel;
        }

        if (instance[std::stoi(node->feature)] <= node->threshold) {
            return predict(instance, node->left);
        } else {
            return predict(instance, node->right);
        }
    }
};

int main() {
    DecisionTree tree;
    // Add code to train and test the decision tree
    return 0;
}