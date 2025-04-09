#include <vector>
#include <algorithm>
#ifndef TREE_H
#define TREE_H

using namespace std;

template<class I, class N>
class Tree { // @suppress("Class has a virtual method and non-virtual destructor")
public:
    typedef I ElementType;
    typedef N Node;

    virtual bool isEmpty() const = 0;
    virtual void insertRoot(ElementType) = 0;
    virtual Node readRoot() const = 0;
    virtual Node parent(Node) const = 0;
    virtual bool isLeaf(Node) const = 0;
    virtual Node firstChild(Node) const = 0;
    virtual bool isLastSibling(Node) const = 0;
    virtual Node nextSibling(Node) const = 0;
    virtual void insertFirstSubTree(Node, Tree<I, N> &) = 0;
    virtual void insertSubTree(Node, Tree<I, N> &) = 0;
    virtual void deleteSubTree(Node) = 0;
    virtual int numberOfNodes() const = 0;
    virtual void writeNode(Node, ElementType) = 0;
    virtual ElementType readNode(Node) const = 0;
    int treeDepth();
    int treeWidth();

private:
    int depth(Node);
    void width(Node, vector<int>&, int level);
};

template<class I, class N>
int Tree<I, N>::treeDepth() {
    if (isEmpty())
        return 0;
    else {
        return depth(readRoot());
    }
}

template <class I, class N>
int Tree<I, N>::depth(Tree::Node node) {
    if (isLeaf(node)) 
        return 0;
    
    int currentDepth = 1;
    int tempDepth;
    Node tempNode = firstChild(node);
    
    while (!isLastSibling(tempNode)) {
        tempDepth = depth(tempNode);
        if (tempDepth > currentDepth) 
            currentDepth = tempDepth;
        tempNode = nextSibling(tempNode);
    }
    
    tempDepth = depth(tempNode);
    if (tempDepth > currentDepth) 
        currentDepth = tempDepth;
    
    return (currentDepth + 1);
}

template <class I, class N>
int Tree<I, N>::treeWidth() {
    if (!isEmpty()) {
        vector<int> levels;
        width(readRoot(), levels, 0);
        return *max_element(levels.begin(), levels.end());
    } else {
        return 0;
    }
}

template <class I, class N>
void Tree<I, N>::width(Node node, vector<int> &levels, int level) {
    if (level >= levels.size()) 
        levels.push_back(1);
    else 
        levels[level]++;

    if (!isLeaf(node)) {
        Node child = firstChild(node);
        int newLevel = level + 1;
        
        while (!isLastSibling(child)) {
            width(child, levels, newLevel);
            child = nextSibling(child);
        }
        
        width(child, levels, newLevel);
    }
}

#endif
