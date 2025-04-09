template <class T>
class treeNode {
private:
    T value;
    treeNode<T>* parent;
    treeNode<T>* firstChild;
    treeNode<T>* sibling;

public:
    T getValue() const {
        return value;
    }

    void setValue(const T& newValue) {
        value = newValue;
    }

    treeNode<T>* getParent() const {
        return parent;
    }

    void setParent(treeNode<T>* newParent) {
        parent = newParent;
    }

    treeNode<T>* getFirstChild() const {
        return firstChild;
    }

    void setFirstChild(treeNode<T>* newFirstChild) {
        firstChild = newFirstChild;
    }

    treeNode<T>* getSibling() const {
        return sibling;
    }

    void setSibling(treeNode<T>* newSibling) {
        sibling = newSibling;
    }
};
