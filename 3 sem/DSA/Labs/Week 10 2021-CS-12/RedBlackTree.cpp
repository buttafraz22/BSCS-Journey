#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node *parent;
    int color;

    Node()
    {
    }
    Node(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->color = 1;
    }
};

template <class T>
class RedBlackTree
{
    Node<T> *root = NULL;

public:
    RedBlackTree()
    {
    }

    RedBlackTree(T arr[], int size)
    {
        for (int i = 0; i < size; ++i)
        {
            this->RB_INSERT(arr[i]);
        }
    }

    ~RedBlackTree();

    Node<T> *searchTree(Node<T> *root, T element)
    {

        if (root == NULL || root->data == element)
        {
            return root;
        }

        if (root->data < element)
        {
            if (root->right == NULL)
            {
                return root;
            }
            return searchTree(root->right, element);
        }
        else
        {
            if (root->left == NULL)
            {
                return root;
            }
            return searchTree(root->left, element);
        }
        return NULL;
    }

    Node<T> *treeMinimum(Node<T> *root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }

    Node<T> *treeMaximum(Node<T> *root)
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }

    Node<T> *treeSuccessor(Node<T> *given)
    {
        if (given->right != NULL)
        {
            return treeMinimum(given->right);
        }
        Node<T> *y = given->parent;
        while (y != NULL && given->data == y->right->data)
        {
            given = y;
            y = y->parent;
        }
        return y;
    }

    Node<T> *getRBTree()
    {
        return root;
    }

    bool isBST(Node<T> *root)
    {

        if (root == NULL)
        {
            return true;
        }
        else if (root->left != NULL && maximumBin(root->left) > root->data)
        {
            return false;
        }
        else if (root->right != NULL && minimumBin(root->right) < root->data)
        {
            return false;
        }

        return true;
    }

    T maximumBin(Node<T> *root)
    {
        if (root == NULL)
        {
            return INT32_MIN;
        }
        T curNode = root->data;
        T leftmax = maximumBin(root->left);
        T rightmax = maximumBin(root->right);

        T bin = min(leftmax, rightmax);
        T ret = max(curNode, bin);

        return ret;
    }

    T minimumBin(Node<T> *root)
    {
        if (root == NULL)
        {
            return INT32_MAX;
        }
        T curNode = root->data;
        T leftmin = minimumBin(root->left);
        T rightmin = minimumBin(root->right);

        T bin = max(leftmin, rightmin);
        T ret = min(curNode, bin);

        return ret;
    }

    void traverseInOrder(Node<T> *root)
    {
        if (root != NULL)
        {
            traverseInOrder(root->left);
            cout << " " << root->data;
            traverseInOrder(root->right);
        }
        return;
    }

    void traversePreOrder(Node<T> *root)
    {
        if (root != NULL)
        {
            cout << " " << root->data;
            traverseInOrder(root->left);
            traverseInOrder(root->right);
        }
        return;
    }

    void traversePostOrder(Node<T> *root)
    {
        if (root != NULL)
        {
            traverseInOrder(root->left);
            traverseInOrder(root->right);
            cout << " " << root->data;
        }
        return;
    }

    int NumberOfNodes(Node<T> *root)
    {
        int count = 0;
        if (root != NULL)
        {
            count++;
            count += NumberOfNodes(root->left);
            count += NumberOfNodes(root->right);
        }
        return count;
    }

    void leftRotate(Node<T> *x, Node<T>* y)
    {
        y = x->right;

        x->right = y->left;

        if (y->left != NULL)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;

        if (x->parent == NULL)
        {
            this->root = y;
        }

        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }

        else
        {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }
    void rightRotate(Node<T> *x , Node<T>* y)
    {
        y = x->left;

        x->left = y->right;

        if (y->right != NULL)
        {
            y->right->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == NULL)
        {
            this->root = y;
        }

        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;
    }

    Node<T> *BSTInsert(Node<T> *root, Node<T> *pt)
    {
        if (root == NULL)
            return pt;

        if (pt->data < root->data)
        {
            root->left = BSTInsert(root->left, pt);
            root->left->parent = root;
        }
        else if (pt->data > root->data)
        {
            root->right = BSTInsert(root->right, pt);
            root->right->parent = root;
        }

        return root;
    }

    void RBT_INSERT_FIX(Node<T> *&root, Node<T> *&pt)
    {
        Node<T> *parent_pt = NULL;
        Node<T> *grand_parent_pt = NULL;

        while ((pt != root) && (pt->color != 0) &&
               (pt->parent->color == 1))
        {

            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            if (parent_pt == grand_parent_pt->left)
            {

                Node<T> *uncle_pt = grand_parent_pt->right;

                if (uncle_pt != NULL && uncle_pt->color ==
                                            1)
                {
                    grand_parent_pt->color = 1;
                    parent_pt->color = 0;
                    uncle_pt->color = 0;
                    pt = grand_parent_pt;
                }

                else
                {

                    if (pt == parent_pt->right)
                    {
                        leftRotate(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    rightRotate(root, grand_parent_pt);
                    swap(parent_pt->color,
                         grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
            else
            {
                Node<T> *uncle_pt = grand_parent_pt->left;

                if ((uncle_pt != NULL) && (uncle_pt->color ==
                                           1))
                {
                    grand_parent_pt->color = 1;
                    parent_pt->color = 0;
                    uncle_pt->color = 0;
                    pt = grand_parent_pt;
                }
                else
                {
                    if (pt == parent_pt->left)
                    {
                        rightRotate(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    leftRotate(root, grand_parent_pt);
                    swap(parent_pt->color,
                         grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }

        root->color = 0;
    }
    bool RB_INSERT(T data)
    {
        Node<T> *pt = new Node<T>(data);

        root = BSTInsert(root, pt);

        this->RBT_INSERT_FIX(root, pt);
        return true;
    }

    void RB_TRANSPLANT(Node<T> *u, Node<T> *v)
    {
        if (u->parent == NULL)
        {
            this->root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }
    void RB_DELETE_FIX(Node<T> *x)
    {
        Node<T> *s;
        while (x != root && x->color == 0)
        {
            if (x == x->parent->left)
            {
                s = x->parent->right;
                if (s->color == 1)
                {
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == 0 && s->right->color == 0)
                {
                    s->color = 1;
                    x = x->parent;
                }
                else
                {
                    if (s->right->color == 0)
                    {
                        s->left->color = 0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else
            {
                s = x->parent->left;
                if (s->color == 1)
                {
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == 0 && s->right->color == 0)
                {
                    s->color = 1;
                    x = x->parent;
                }
                else
                {
                    if (s->left->color == 0)
                    {
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = 0;
    }

    bool Delete(T key)
    {
        Node<T> *node = searchTree(this->root, key);

        Node<T> *z = NULL;
        Node<T> *x;
        Node<T> *y;
        while (node != NULL)
        {
            if (node->data == key)
            {
                z = node;
            }

            if (node->data <= key)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }

        if (z == NULL)
        {
            cout << "Key not found in the tree" << endl;
            return 0;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == NULL)
        {
            x = z->right;
            RB_TRANSPLANT(z, z->right);
        }
        else if (z->right == NULL)
        {
            x = z->left;
            RB_TRANSPLANT(z, z->left);
        }
        else
        {
            y = treeMinimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                RB_TRANSPLANT(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            RB_TRANSPLANT(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0)
        {
            RB_DELETE_FIX(x);
        }
        return true;
    }
};

int main()
{

    int arr[] = {55,40,65,60,75,57};
    RedBlackTree<int> *bst = new RedBlackTree<int>(arr,6);
    bst->traverseInOrder(bst->getRBTree());
    return 0;
}