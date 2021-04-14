/////////////////////////////////////////////////
// The function that is main topic of this code is highlighted in ///////// symbol

//////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//_______________________Macros Start____________________________
#define pb push_back
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define vii vector < pair <int,int> >
#define vll vector < pair <ll,ll> > 
#define mii map<int,int>
#define mll map<ll,ll>
#define si set <int>
#define sl set <ll>
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define fr first
#define sc second
#define rep(i,a,n) for(ll i=a ; i<n ; i++)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// ________________________Macros End______________________________

// ________________________Utility Functions Start__________________
ll M=1e9+7;

ll binomialCoeff(ll n, ll k) 
{ 
    ll res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of 
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (ll i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 
ll mods(ll a,ll b){
    a=a%M;
    b=b%M;
    return (a+b)%M;
}
ll modp(ll a,ll b){
    a=a%M;
    b=b%M;
    return (a*b)%M;

}
struct MyComp
{
    bool operator()(const pair<int,int>& x, const pair<int,int>& y) const
    {
        return x.second > y.second || (x.second == y.second && x.first > y.first);
    }
};
//__________________________Utility Fuction End____________________________________

//___________________________Starters for Graph Begin_______________________________
const int N=1e5+5;
vi adj[N];
vi visited(N,0);
void makeGraph(int m){
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
}


//_____________________________Starters for Graph End___________________________________

//_____________________________starters for pointer related DS begin___________________________
struct node{
    int data;
    node* link;
};

struct bstNode{
    int data;
    bstNode* left;
    bstNode* right;
};

bstNode* root=NULL;

bstNode* newNode(int data){
    bstNode* newNode=new bstNode;
    newNode->data=data;
    newNode->left=newNode->right=NULL;
}

bstNode* insert(bstNode* root,int data){
    if(root==NULL){
        root=newNode(data);
        return root;
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }

}
void levelorder(bstNode* root){
        queue <bstNode*> q;
        q.push(root);
        
        while(!q.empty()){
            bstNode* cur=q.front();
            q.pop();
            cout<<cur->data<<" ";
            if(cur->left!=NULL){
                q.push(cur->left);
            }
            if(cur->right!=NULL){
                q.push(cur->right);
            }
            
        }
}
void inorder(bstNode* root){
    if(root==NULL){

        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(bstNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(bstNode* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
//_____________________________starters for pointer related DS end___________________________






//____________________________Main Start__________________________________________________
int main(){
    fastio
    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,7);
    root=insert(root,11);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;
    



    

    
    
    
}
//_____________________________Main End______________________________________________________
