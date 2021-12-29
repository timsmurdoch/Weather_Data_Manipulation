
template <class T>
struct node{
    T data;
    node<T> * left;
    node<T> * right;
    node<T>(){left = nullptr; right = nullptr;}
};

	/**
	 * @class BST
	 * @brief Stores a Tree which u can insert into
	 *
	 * Place elements into a tree and print them, and check if a value is in the tree
	 *
	 *
	 * @author Timothy Smith
	 * @version 01
	 * @date 20/05/2020, Timothy Smith, Begin class
	 *
	 *
	 * @todo Wait for next lab
	 *
	 * @bug No known bugs
	 */

template <class T>
class BST{  //BST.h;


    public:

        /**
         * @brief  Constructor for BST
         *
         * Sets root node the nullptr
         *
         */

        BST();

        /**
         * @brief  Destructor for BST
         *
         * Destroys the tree
         *
         */

        ~BST();

        /**
         * @brief  Puts a new value into the tree
         *
         * Puts in a value into the tree
         *
         * @param const T - data
         * @return void
         */

        void Insert(const T data);

        /**
         * @brief  Searches for a value in a tree
         *
         * If the value is in the tree return true, otherwise return false
         *
         * @param const T - data
         * @return bool
         */

        bool Search(const T data);

         /**
         * @brief   Prints the data in order
         *
         * Print the data in order
         *
         * @return void
         */

        void inOrder(void (*visit) (T&item)) const;

         /**
         * @brief   Prints the data in preorder
         *
         * Print the data in preorder
         *
         * @return void
         */

        void preOrder(void (*visit) (T&item)) const;

         /**
         * @brief   Prints the data in postORder
         *
         * Print the data in postOrder
         *
         * @return void
         */

        void postOrder(void (*visit) (T&item)) const;

         /**
         * @brief   Overloads the = operator
         *
         * Overload the assignment operator
         *
         * @param const BST<T> - &Tree
         * @return BST<T>
         *
         */

        const BST<T> & operator =(const BST<T> & Tree);

         /**
         * @brief   Copy Constructor
         *
         * Used to make a new copy of BST
         *
         * @param const BST<T> - &Tree
         * @return BST
         *
         */

        BST(const BST<T> & Tree);

        void deletNode(T data);

    private:

            /// Sets the root pointer to nullptr
        node<T> * rootPointer = nullptr;

         /**
         * @brief   Prints the data in preorder
         *
         * Print the data in preorder
         *
         * @param node<T> - *root
         * @return void
         */

        void preOrder(node<T> * root, void(*visit) (T&item) ) const;

         /**
         * @brief   Prints the data in postOrder
         *
         * Print the data in postOrder
         *
         * @param node<T> - *root
         * @return void
         */

        void postOrder(node<T> * root, void(*visit) (T&item)) const;

         /**
         * @brief   Prints the data in order
         *
         * Print the data in order
         *
         * @param node<T> - *root
         * @return void
         */

        void inOrder(node<T> * root, void(*visit) (T&item)) const;

        /**
         * @brief  Searches for a value in a tree
         *
         * If the value is in the tree return true, otherwise return false
         *
         * @param const T - data, note<T> - *root
         * @return bool
         */

        bool Search(node<T> * root, T data);

        /**
         * @brief  Deletes the entire tree
         *
         * Deleted the tree and all of its nodes
         *
         * @param const T - *&data
         * @return void
         */

        void deleteTree(node<T> * &root);

        /**
         * @brief  Inserts data
         *
         * Inserts data into the tree if does not already exist
         *
         * @param node<T> - *&newnode , node<T> - *&current
         * @return void
         */

        void Insert(node<T> *newnode, node<T> *current);

        /**
         * @brief  Copy Function used to copy a tree
         *
         * Copy Function used to copy a tree
         *
         * @param note<T> - *&copyTreeRoot, node<T> - *&otherTreeRoot
         * @return void
         */

        void copyTree( node<T>* & copyTreeRoot,  node<T> *otherTreeRoot);

        /**
         * @brief  Delete a node in the tree
         *
         * Delete a node in the tree
         *
         * @param node - *&root, T - data
         * @return void
         */

        void deletNode(node<T> *& root, T data);

        /**
        * @brief Finds the max data inside of the BST
        *
        * Looks to the right and finds the biggest data
        *
        * @param node<T> - *root
        * @return node<T> - *root
        */

        node<T> * maxData(node<T> * root);
};

template <class T>
node<T> * BST<T>::maxData(node<T> * root)
{
    if(root->right != nullptr){
        return maxData(root->right);
    }
    return root;
}

template <class T>
void BST<T>::deletNode(T data)
{
    deletNode(rootPointer, data);
}

template <class T>
void BST<T>::deletNode(node<T> *& root, T data)
{
    if(root == nullptr)
        return;
    if(data < root->data)
        deletNode(root->left, data);
    else if(data > root->data)
        deletNode(root->right, data);
    else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        else if(root->left && root->right)
        {
            node<T> * predecessor = maxData(root->left);
            root->data = predecessor->data;

            deletNode(root->left, predecessor->data);
        }
        else{
            node<T> * child;
            if(root->left == nullptr)
                child = root->left;
            else
                child = root->right;

            node<T> * current = root;

            root = child;

            delete current;
        }
    }
}

template <class T>
BST<T>::BST(const BST<T> & Tree)
{
    if(Tree.rootPointer == nullptr)
        rootPointer == nullptr;
    else
        (copyTree(rootPointer, Tree.rootPointer));

}

template <class T>
void BST<T>::copyTree( node<T>* & copyTreeRoot, node<T> *otherTreeRoot)
{
    if(otherTreeRoot == nullptr)
        copyTreeRoot == nullptr;
    else
    {
        copyTreeRoot = new node<T>;
        copyTreeRoot->data = otherTreeRoot->data;
        copyTree(copyTreeRoot->left, otherTreeRoot->left);
        copyTree(copyTreeRoot->right, otherTreeRoot->right);
    }
}

template <class T>
const BST<T> & BST<T>::operator =(const BST<T> & Tree)
{
    if(this != &Tree)
    {
        if(rootPointer != nullptr)
            deleteTree(rootPointer);
        if(Tree.rootPointer == nullptr)
            rootPointer = nullptr;
        else
            copyTree(rootPointer, Tree.rootPointer);

    }
    return *this;
}

template <class T>
BST<T>::~BST()
{
    deleteTree(rootPointer);
}

template <class T>
void BST<T>::deleteTree(node<T> * &root)
{
    if(root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

template <class T>
void BST<T>::inOrder(void (*visit) (T & item)) const
{
    inOrder(rootPointer, *visit);
}

template <class T>
void BST<T>::inOrder(node<T> * root, void(*visit) (T & item)) const
{
    if(root != nullptr)
    {
        inOrder(root->left, *visit);
        (*visit)(root->data);
        inOrder(root->right, *visit);
    }
}

template <class T>
void BST<T>::preOrder(void (*visit) (T & item)) const
{
    preOrder(rootPointer, *visit);
}

template <class T>
void BST<T>::preOrder(node<T> * root, void(*visit) (T & item)) const
{
    if(root != nullptr)
    {
        (*visit)(root->data);
        preOrder(root->left, *visit);
        preOrder(root->right, *visit);

    }
}

template <class T>
void BST<T>::postOrder(void (*visit) (T & item)) const
{
    postOrder(rootPointer, *visit);
}

template <class T>
void BST<T>::postOrder(node<T> * root, void(*visit) (T & item)) const
{
    if(root != nullptr)
    {
        postOrder(root->left, *visit);
        postOrder(root->right, *visit);
        (*visit)(root->data);
    }
}

template <class T>
bool BST<T>::Search(const T data)
{
    bool result = Search(rootPointer, data);
    return result;
}

template <class T>
bool BST<T>::Search(node<T> * root, T data)
{
    if(root == nullptr)
        return false; //return false
    else if(root->data == data)
        return true; //return true
    else if(root->data < data)
        return Search(root->right , data);
    else
        return Search(root->left, data);

}

template <class T>
BST<T>::BST()
{
    rootPointer = nullptr;
}

template <class T>
void BST<T>::Insert(T data)
{
    node<T> * newnode = new node<T>;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;

    if(rootPointer == nullptr){
        rootPointer = newnode;
    }else{
        Insert(newnode, rootPointer);
    }

    return;
}

template <class T>
void BST<T>::Insert(node<T> * newnode, node<T> * current)
{
    if(newnode->data == current->data) //Prevent duplicates
    {
        return;
    }
    if(newnode->data < current->data){
            if(current->left == nullptr){
                current->left = newnode;
            }
            else{
                Insert(newnode, current->left);
            }
    }else if(current->right == nullptr){
        current->right = newnode;

    }else{
        Insert(newnode, current->right);
    }

    return;
}

















