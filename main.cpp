#include <bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------CONSTANTS----------------------------------------------------------------

typedef long long ll;
double EPS = 1e-9;
int INF = 1000000005;
ll INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
#define all(v) v.begin(), v.end()

//----------------------------------------------------------------VECTOR MACROS----------------------------------------------------------------

#define vmax(v) *max_element(all(v))
#define vmin(v) *min_element(all(v))
#define vsum(v) accumulate(all(v), 0)

//----------------------------------------------------------------DEFINITIONS----------------------------------------------------------------

class Node{
public:
    int val;
    Node* next;

    Node(int data): val(data), next(nullptr) {}
};

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data): val(data), left(nullptr), right(nullptr) {}
};

//----------------------------------------------------------------INPUT HELPERS----------------------------------------------------------------

Node* createList(vector<int> v){
    if(v.size() == 0) return nullptr;
    
    Node* head = new Node(v[0]);
    Node* cur = head;

    int i=1;
    while(i<v.size()){
        cur->next=new Node(v[i]);
        cur=cur->next;
        i++;
    }

    return head;
}

TreeNode* createBinaryTree(vector<int> v, int i = 0){
    TreeNode* root = nullptr;

    if (i < v.size()){
        root = new TreeNode(v[i]);
        root->left = createBinaryTree(v,2 * i + 1);
        root->right = createBinaryTree(v,2 * i + 2);
    }

    return root;
}

//----------------------------------------------------------------OUTPUT HELPERS----------------------------------------------------------------

template <typename T>
void printb(T n)
{
    cout << n;
}
void printb(char c)
{
    cout << "'" << c << "'";
}
void printb(string s)
{
    cout << '"' << s << '"';
}
template <class T1, class T2>
void printb(pair<T1, T2> p)
{
    cout << "(";
    printb(p.first);
    printb(", ");
    printb(p.second);
    cout << ")";
}
template <class T>
void printb(vector<T> v)
{
    cout << "[";
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        printb(*i);
        if (i != (--v.end()))
            cout << ", ";
    }
    cout << "]";
}
template <class T1, class T2>
void printb(map<T1, T2> m)
{
    cout << "{";
    for (auto p = m.begin(); p != m.end(); ++p)
    {
        printb(p->first);
        cout << ": ";
        printb(p->second);
        if (p != (--m.end()))
            cout << ", ";
    }
    cout << "}";
}

void printList(Node* head){
    while(head){
        cout<<head->val<<' ';
        head=head->next;
    }  
    cout<<endl;
}

void printTree(TreeNode* root){
    if(!root) return;

    queue<TreeNode*> q;
    q.push(root); 

    while(!q.empty()){
        int s=q.size();
        vector<int> t;

        while(s--){
            TreeNode* node=q.front();
            t.push_back(node->val);
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        for(int i:t) cout<<i<<' ';
        cout<<endl;
    }
}

//----------------------------------------------------------------LEETCODE HELPERS----------------------------------------------------------------
void IO(){
    
}

int main(){
    IO();
}
