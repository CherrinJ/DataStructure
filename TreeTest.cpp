#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>

 using namespace std;

 //链式存储
  class TreeNode {
    // private:
        
    public:
        string m_value;
        TreeNode *m_lChild = nullptr, *m_rChild = nullptr;

    public:
        TreeNode(){
        }

        TreeNode(string value):m_value(value){
        }
        // ~TreeNode(){
        //     // delete m_childern;
        //     m_lChild = NULL;
        //     m_rChild = NULL;
        // }

        void setValue(string value){
            m_value = value;
        }

        string getValue(){
            return m_value;
        }

        bool operator==(const TreeNode &node){
            if(m_value == node.m_value && node.m_rChild == m_rChild && node.m_lChild == m_lChild){
                return true;
            } else {
                return false;
            }
        }

    TreeNode& operator=(TreeNode& node){
        m_value = node.getValue();
        m_rChild = node.m_rChild;
        m_lChild = node.m_lChild;
        return *this;
    }
  };

  class BinaryTree {
      private:
        TreeNode* m_heap = nullptr;
        // string TreeArr[9] = {"a","b","#","d","#","c","e","#"};
      public:
       BinaryTree(){
       }
       virtual ~BinaryTree(){}
    
        inline TreeNode* Front(){
            return m_heap;
        }

        
        TreeNode* addNodeByArrIndex(int index, vector<string> &vect){
            string data = vect[index];
           
            if(data == "#"){
                return NULL;
            } 

            TreeNode* temp = new TreeNode(data);
            if(m_heap == NULL){
                m_heap = temp;
            }

            int lIndex = 2 * index + 1;
            int rIndex = 2 * index + 2;
            if(lIndex >= vect.size()){
                temp->m_lChild = nullptr;
            } else{
                temp->m_lChild = addNodeByArrIndex(lIndex, vect);
            }
            if(rIndex >= vect.size()){
                temp->m_rChild = nullptr;
            } else {
                temp->m_rChild = addNodeByArrIndex( rIndex, vect);
            }
            
            // cout<<"----"<<temp<<endl;
            return temp;
        }

    //左子树小于右子树
       void addNode(string data){
           TreeNode* node = new TreeNode(data);
           TreeNode* curNode = m_heap;
           bool add = false;
           if(m_heap == NULL){
                m_heap = node;
           } else {
               while(!add){
                   if((curNode)->getValue() < data){
                        if((curNode)->m_lChild == NULL){
                            (curNode)->m_lChild = node;
                            add = true;
                            break;
                        } else{
                            curNode= (curNode)->m_lChild;
                        }
                    } else {
                        if((curNode)->m_rChild == NULL){
                            (curNode)->m_rChild = node;
                            add = true;
                            break;
                        }
                        else {
                            curNode= (curNode)->m_rChild;
                        } 
                    }
               }
           }
       }
    
    //树的遍历方式(深度遍历)
    //前序遍历（根->左->右）(递归)
    void PreOrder(TreeNode node){
        cout<<node.getValue()<<", ";
        if(node.m_lChild){
            PreOrder(*(node.m_lChild));
        }
        if(node.m_rChild){
            PreOrder(*(node.m_rChild));
        }
    }
     //前序非递归
    void preOrder2(){
        TreeNode* node = m_heap;
        stack<TreeNode*> treeStack;
        while(node || !treeStack.empty() ){
            if(node){
                cout<<node->getValue()<<", ";
                treeStack.push(node);
                node = node->m_lChild;
            } else {
                node = treeStack.top();
                node = node->m_rChild;
                treeStack.pop();
            }
        }

    }

    //中序遍历（左->根->右）
    void InOrder(TreeNode& node){
        if(node.m_lChild){
            InOrder(*(node.m_lChild));
        }
        cout<<node.getValue()<<", ";

        if(node.m_rChild){
            InOrder(*(node.m_rChild));
        }
    }
    //中序非递归
    void InOrder2(){
        TreeNode* temp =Front();
        stack<TreeNode*> treeStack;
        while(temp || !treeStack.empty()){
            if(temp){
                treeStack.push(temp);
                temp = temp->m_lChild;
            } else {
                temp = treeStack.top();
                cout<<temp->getValue()<<", ";
                temp = temp->m_rChild;
                treeStack.pop();
            }
        }
    }

    //后序遍历（左->右->根）
    void PostOrder(TreeNode& node){
        if(node.m_lChild){
            PostOrder(*(node.m_lChild));
        }

        if(node.m_rChild){
            PostOrder(*(node.m_rChild));
        }
        cout<<node.getValue()<<", ";
    }  
    //后续，非递归
    void PostOrder2(){
        TreeNode* temp = Front();
        stack<TreeNode*> treeStack;
        stack<int> TreeChildren;
        // int childIndex = 0;
        while(temp || !treeStack.empty()){
            if(temp){
                treeStack.push(temp);
                TreeChildren.push(0);
                temp = temp->m_lChild;
            }else{
                temp = treeStack.top();
                
                int flag = TreeChildren.top();
                if(flag == 0){
                    TreeChildren.top() = 1;
                    temp = temp->m_rChild;
                } else{
                    cout<<temp->getValue()<<", ";
                    temp = NULL;
                    treeStack.pop();
                    TreeChildren.pop();
                }
                
            }
        }
    }

    ///广度遍历（层级遍历）又叫宽度优先搜索，或横向优先搜索。-breadth first search
    void BreadthFirstSearch(){
        queue<TreeNode*> treeQue;
        treeQue.push(Front());

        while(!treeQue.empty()){
            TreeNode* temp = treeQue.front();
            treeQue.pop();
            cout<< temp->getValue()<<", ";
            if(temp->m_lChild){
                treeQue.push(temp->m_lChild);
            }
            if(temp->m_rChild){
                treeQue.push(temp->m_rChild);
            }
        }
    }

  };
  
  //二叉树创建，遍历
  //https://blog.csdn.net/qq_29567701/article/details/79857137
  //https://www.jianshu.com/p/6e739de0d206
  //https://www.cnblogs.com/houzhihoujueblogs/articles/4614506.html

//-----------------------------------
/*
记ptr指向二叉链表中的一个结点，以下是建立线索的规则：
    （1）如果ptr->lchild为空，则存放指向中序遍历序列中该结点的前驱结点。这个结点称为ptr的中序前驱；
    （2）如果ptr->rchild为空，则存放指向中序遍历序列中该结点的后继结点。这个结点称为ptr的中序后继；
    显然，在决定lchild是指向左孩子还是前驱，rchild是指向右孩子还是后继，需要一个区分标志的。因此，我们在每个结点再增设两个标志域ltag和rtag，注意ltag和rtag只是区分0或1数字的布尔型变量，其占用内存空间要小于像lchild和rchild的指针变量
    --ltag为0表示lchild指向该节点的左孩子，为1表示lchild指向该节点的前驱
    --rtag为0，表示rchild指向该节点的右孩子，为1时，rchild指向该节点的后继
    //https://www.cnblogs.com/lishanlei/p/10707834.html
*/
    typedef enum{LINK, THREAD} PointerThread;
    class ThreadedNode{
        private:
            string m_data;
        public:
            ThreadedNode* m_lChild = nullptr;
            ThreadedNode* m_rChild = nullptr;
            PointerThread lTag = LINK;
            PointerThread rTag = LINK;

        public:
        ThreadedNode(){
            m_data = "*";
        }

        ThreadedNode(string data): m_data(data){
        }
            void setData(string value){
                m_data = value;
            }    
            string getData(){return m_data;}

            void setLtag(int value){

            }
    };
    
    //https://www.cnblogs.com/lishanlei/p/10707834.html
    class ThreadedBinaryTree{
        private:
            ThreadedNode* m_root = nullptr;

        public:
            ThreadedNode* pre = nullptr;
            ThreadedNode* m_head = nullptr;
        public:
            ThreadedNode* getRoot(){
                return m_root;
            }

            ThreadedNode* createTree(vector<string>& vect, int index){
                if(index >= vect.size()) return NULL;

                string data = vect[index];
                ThreadedNode* temp = new ThreadedNode(data);
                if(data == "#"){
                    return NULL;
                } else {
                    
                    if(getRoot() == NULL){
                        m_root = temp;
                    }
                    int lIndex = 2 * index + 1;
                    int rIndex = 2 * index + 2;
                    if(lIndex < vect.size()){
                        temp->m_lChild = createTree(vect, lIndex);
                    } 
                    if(rIndex < vect.size()){
                        temp->m_rChild = createTree(vect, rIndex);
                    }
                }

                return temp;
        }

    //线索化-----------------------
    /* 
    前驱：按不同序遍历的前一个节点；
    后继：按不同序遍历的后一个节点；
    不同许的线索化，会有不同的前驱和后继
    */
    //中序线索化
        void inThreading(ThreadedNode* node){
            if(!node) return;

            if(node->m_lChild)
                inThreading(node->m_lChild);

            cout<<node->getData()<<", ";
            if(!node->m_lChild){
                node->lTag = THREAD;
                node->m_lChild = pre;
            }
            if(pre && !pre->m_rChild){
                pre->rTag = THREAD;
                pre->m_rChild = node;
            }
            pre = node;

            if(node->m_rChild)
                inThreading(node->m_rChild);
        }

    //加个头结点，形成环形
    //https://blog.csdn.net/qq_42552006/article/details/108969409
    //https://www.jianshu.com/p/3965a6e424f5
    void ThreadedWithHead(){
        m_head = new ThreadedNode();
        m_head->rTag = THREAD;
        m_head->m_rChild = pre;

        if(!getRoot()){
            m_head->m_lChild = getRoot();
        } else{
            m_head->m_lChild = getRoot();
            pre = m_head;
            inThreading(getRoot());
            pre->m_rChild = m_head;
            pre->rTag = THREAD;
            m_head->m_rChild = pre;
        }
    }

    //中序遍历， 带头结点遍历
        void InOrderWithHead(){
            ThreadedNode* temp = getRoot();
            while(temp != m_head){
                while(temp->lTag == LINK){
                    temp = temp->m_lChild;
                }

                cout<<temp->getData()<<", ";

                while(temp->rTag == THREAD && temp->m_rChild != m_head){
                    temp = temp->m_rChild;
                    cout<<temp->getData()<<", ";
                }
                temp = temp->m_rChild;
            }
        }

    //不带头结点的中序遍历
    };


    //二叉搜索树
    /*
    根节点的值大于其左子树中任意一个节点的值，小于其右节点中任意一节点的值，这一规则适用于二叉查找树中的每一个节点
    **插入子节点一定都是叶子节点
    https://blog.csdn.net/kang___xi/article/details/80392565
    */
   class BSNode{
        private:
            int m_data;
        public:
            BSNode* m_lChild = nullptr;
            BSNode* m_rChild = nullptr;

        public:
        BSNode(){
            m_data = 0;
        }

        BSNode(int data): m_data(data){
        }
            void setData(int value){
                m_data = value;
            }    
            int getData(){return m_data;}

            void setLtag(int value){

            }
    };
    class BinatySearchTree {
        private:
            BSNode* m_root = nullptr;
        
        public:
            BSNode* getRoot(){
                return m_root;
            }
        
            void createTree(vector<int>& vect, int index, BSNode* curNode){
                if(index >= vect.size()){
                    return;
                }
                int value = vect[index];
                BSNode node(value);
                
                BSNode* temp = curNode;
                if(m_root == nullptr){
                    m_root = &node;
                    temp = &node;
                } else {
                    if(!temp){
                        temp = &node;
                    } else {
                        if(temp->getData() < value){
                            temp = temp->m_lChild;
                        } else{
                            temp = temp->m_rChild;
                        }
                    }
                }
                 return createTree(vect, index + 1, temp);
            }

            void InsertNode(int value){
                BSNode* node = new BSNode(value);
                if(m_root == nullptr){
                    m_root = node;
                } else {
                    BSNode* curNode = m_root;
                    bool found = false;
                    while(!found){
                        if(value < curNode->getData()){
                            //左边
                            if(curNode->m_lChild)
                                curNode = curNode->m_lChild;
                            else{
                               found = true;
                                //插入
                                curNode->m_lChild = node;  
                            }
                            
                        } else if(value > curNode->getData()){
                            //右边
                            if(curNode->m_rChild)
                                curNode = curNode->m_rChild;
                            else{
                               found = true;
                                //插入
                                curNode->m_rChild = node;  
                            }
                        } else {
                            cout<<"this node existed" <<endl;
                        }
                    }
                }
            }
           
           /*
           》要删除的节点无左右孩子
            》要删除的节点只有左孩子
            》要删除的节点只有右孩子
            》要删除的节点有左、右孩子
            https://blog.csdn.net/kang___xi/article/details/80392565
           */
           bool RemoveNode(int value){
               if(m_root == nullptr){
                   cout<<"the node dosent exist"<<endl;
                   return false;
               } else
               {
                   BSNode* temp = m_root;
                    BSNode* parent = nullptr;
                   bool found = false;
                   while(!found){
                       if(temp->getData() == value){
                           found = true;
                       } else{
                           parent = temp;
                           if(value < temp->getData()){
                               temp = temp->m_lChild;
                           } else if(value > temp->getData()){
                               temp = temp->m_rChild;
                           } 
                           if(!temp){
                               cout<<"canot be found"<<endl;
                               return false;
                           }
                       }
                   }
                   if(found){
                       bool isLChild = false;
                       if(parent){
                            if(parent->m_lChild->getData() == temp->getData()){
                               isLChild = true;
                            } else if(parent->m_rChild->getData() == temp->getData()){
                                isLChild = false;
                            }
                        }

                        //删除叶子节点
                       if(!temp->m_lChild && !temp->m_rChild){
                            if(isLChild){
                                parent->m_lChild = nullptr;
                            } else {
                                parent->m_rChild = nullptr;
                            }
                            delete temp;
                            temp = nullptr;
                       }
                        //删除只有右孩子的节点
                       else if(!temp->m_lChild && temp->m_rChild){
                           if(isLChild){
                                parent->m_lChild = temp->m_rChild;
                           } else {
                                parent->m_rChild = temp->m_rChild;
                            }
                           delete temp;
                           temp = nullptr;
                       }
                       //删除只有左孩子的节点
                       else if(!temp->m_rChild && temp->m_lChild){
                           if(isLChild){
                                parent->m_lChild = temp->m_lChild;
                           } else {
                                parent->m_rChild = temp->m_lChild;
                            }

                           delete temp;
                           temp = nullptr;
                       }
                       //删除有左孩子和右孩子的节点
                        else if(temp->m_lChild && temp->m_rChild){
                            BSNode* node = temp->m_rChild;
                            parent = temp;
                            while(node){
                                if(node->m_lChild){
                                    parent = node;
                                    node = node->m_lChild;
                                }
                            }
                            temp->setData(node->getData());
                            if(parent->m_lChild->getData() == node->getData()){
                                parent->m_lChild = nullptr;
                            } else {
                                parent->m_rChild = nullptr;
                            }
                            delete node;
                            node = nullptr;
                        }
                   }
               }
               return  true;
           }

           BSNode* SearchNode(int value){
               BSNode* temp = m_root;
               bool found = false;
               while(temp && !found){
                   if(value < temp->getData()){
                       temp = temp->m_lChild;
                   } else if (value > temp->getData()){
                       temp = temp->m_rChild;
                   } else if(value == temp->getData()){
                       found = true;
                       cout<<"found: "<< temp<<endl;
                       return temp;
                   }
               }
               return NULL;
           }
    };

    class AvlNode{
        public:
            int bf = 0;
            int data;
            AvlNode* lNode = nullptr;
            AvlNode* rNode = nullptr;
            AvlNode* parent = nullptr;

            AvlNode(int value): data(value){
            }
    };

    class AVLTree {
        private:
            AvlNode* m_root = nullptr;

        public:
            AvlNode* getRoot(){
                return m_root;
            }

            // int getHeight(AvlNode* node){
            //     if(node)
            //         return node->bf;
            //     else
            //     {
            //         return 0;
            //     }                                                                                                   
            // }

            //（此例中的平衡因子bf采用的是右子树的高度减去左子树的高度） 
            //https://blog.51cto.com/14233363/2482901
            //https://blog.csdn.net/jyy305/article/details/70949010
            bool InsertNode(int value){
                AvlNode* temp = new AvlNode(value);
                // temp->height = max(getHeight(temp->lNode), getHeight(temp->rNode)) + 1;
                // bool result = false;
                if(getRoot() == nullptr){
                    m_root = temp;//TODO
                    return true;
                } else {
                    //插入(插入的一定是叶子节点)
                    bool insert = false;
                    AvlNode* parent = nullptr;
                    AvlNode* insertNode = m_root;
                    while(!insert && insertNode){
                        if(insertNode->data > value){
                            parent = insertNode;
                            if(insertNode->lNode)
                                insertNode = insertNode->lNode;
                            else{
                                insertNode->lNode = temp;
                                insert = true;
                            }
                        } else if(insertNode->data < value){
                            parent = insertNode;
                            if(insertNode->rNode)
                                insertNode = insertNode->rNode;
                            else {
                                insertNode->rNode = temp;
                                insert = true;
                            }
                        } else{
                            return false;
                        }
                    }
                    insertNode = temp;
                    insertNode->parent = parent;

                    while(parent){
                        //纠正平衡因子
                        if(temp == parent->lNode)
                            --parent->bf;
                        else if(temp == parent->rNode){
                            ++parent->bf;
                        }

                        if(parent->bf == 0){
                            return true;
                        } else if(parent->bf == 1 || parent->bf == -1){
                            temp = parent;
                            parent = parent->parent;
                        } else {
                            //旋转二叉树
                            if(parent->bf == -2){
                                //L
                                AvlNode* subl = parent->lNode ? parent->lNode->rNode : nullptr;
                                if(subl && subl->bf == -1){
                                    //LL
                                    RotateLL(parent);
                                } else if(subl && subl->bf == 1){
                                    //LR
                                    RotateLR(parent);
                                }
                            } else if(parent->bf == 2){
                                //R
                                AvlNode* subr = parent->rNode ? parent->rNode : nullptr;
                                if(subr && subr->bf == 1){
                                    //RR
                                    RotateRR(parent);
                                } else if(subr && subr->bf == -1){
                                    //RL
                                    RotateRL(parent);
                                }
                            }
                            return true;
                        }
                    }
                    return true;
                }
            }
            
            //https://www.cnblogs.com/lanhaicode/p/11321243.html
            bool DeleteNode(AvlNode* node){

            }

            //https://blog.csdn.net/jyy305/article/details/70949010
            //parent: node
            void RotateLL(AvlNode* node){
                //subLchild: node->lchild
                //subRchild: node->lchid->rChild
                AvlNode* subLChild = node->lNode;
                AvlNode* subRChild = nullptr;
                if(subLChild){
                    subRChild = subLChild->rNode;
                    if(subRChild)
                        subRChild->parent = node;
                }
                if(node->parent)
                    node->parent->lNode = subLChild;
                subLChild->rNode = node;
                subLChild->parent = node->parent;
                node->lNode = subRChild;
                node->parent = subLChild;
                subLChild->bf = 0;
                node->bf = 0;

                if(!subLChild->parent)
                    m_root = subLChild;
            }

            void RotateRR(AvlNode* node){
                AvlNode* subr = node->rNode;
                AvlNode* subl = nullptr;
                if(subr){
                    subl = node->rNode->lNode;
                    if(subl){
                        subl->parent = node;
                    }
                }
                if(node->parent)
                    node->parent->rNode = subr;
                subr->lNode = node;
                subr->parent = node->parent;
                node->parent = subr;
                node->rNode = subl;
                node->bf = 0;
                subr->bf = 0;
                if(!subr->parent)
                    m_root = subr;
            }

            void RotateLR(AvlNode* node){
                int bf = 0;
                AvlNode* subL = node->lNode;
                AvlNode* subR = nullptr;
                if(subL)
                    subR = node->rNode;
                if(subR)
                    bf = subR->bf;
                RotateRR(node->lNode);
                RotateLL(node);

                if(bf == -1){
                    node->bf = 1;
                } else{
                    subL->bf = -1;
                }
                if(subR)
                    subR->bf = 0;
            }

            void RotateRL(AvlNode* node){
                int bf = 0;
                AvlNode* subR = node->rNode;
                AvlNode* subL = nullptr;
                if(subR)
                    subL = subR->lNode;
                if(subL){
                    bf = subL->bf;
                }

                RotateLL(node->rNode);
                RotateRR(node);

                if(bf == -1){
                    subR->bf = 1;
                } else{
                    node->bf = -1;
                }
                if(subL)
                    subL->bf = 0;
            }
    };

  int main(){
      vector<string> vect;
      vector<int> int_vect;
      //空节点用“#”代替
      int arr[] = {30, 20, 50, 25,24,23,35,60,70};
      for(int i = 0; i < 9; ++i){
          int_vect.push_back(arr[i]);
      }
      string str[] =  {"0", "1","2", "3", "4", "5", "6", "7","8"};//{ "1", "2","3", "4", "5", "#", "6", "7" };
      for(int i = 0; i < 8; ++i){
          vect.push_back(str[i]);
      }

    {
    // tree.addNodeByArrIndex(0, vect);
    // tree.PreOrder(*(tree.Front()));
    // cout<<endl;
    // cout<<"PreOrder2:"<<endl;
    // tree.preOrder2();
    // cout<<endl;
    // tree.InOrder(*(tree.Front()));
    // cout<<endl<<"InOrder2:"<<endl;
    // tree.InOrder2();
    // cout<<endl;
    // tree.PostOrder(*(tree.Front()));
    // cout<<endl<<"PostOrder2"<<endl;
    // tree.PostOrder2();
    // cout<<endl<<"breadth first search:"<<endl;
    // tree.BreadthFirstSearch();
    }
    {
    // ThreadedBinaryTree ThreadTree;
    // ThreadTree.createTree(vect, 0);
    // // ThreadTree.inThreading(ThreadTree.getRoot());
    // ThreadTree.ThreadedWithHead();
    // cout<<endl;
    // ThreadTree.InOrderWithHead();
    }

    {
        // BinatySearchTree bsTree;
        // // bsTree.createTree(int_vect, 0, bsTree.getRoot());;
        // for(int i = 0; i < 9; ++i){
        //     bsTree.InsertNode(arr[i]);
        // }
        // // bsTree.RemoveNode(30);
        // BSNode node = *(bsTree.SearchNode(25));
    }
    
    AVLTree avlTree;
    
    int arr1[] = {30,40,45,50,60, 55};
    for(int i = 0; i < 6; ++i){
          avlTree.InsertNode(arr1[i]);
    }

    return 0;
  }