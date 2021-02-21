#include<iostream>
#include<map>
#include<queue>
using namespace std;
class tree{
    private:
        int data;
        tree *left,*right;
        
    public:
        tree(int val){
            this->data = val;
            this->left = this->right = NULL;
        }
        tree *insert(tree *root,int val){
            if(root==NULL)
            {
                return new tree(val);
            }
            if(val<root->data){
                root->left = insert(root->left,val);
            }
            if(val>root->data){
                root->right = insert(root->right,val);
            }
            return root;
        }
          void top_view(tree *root){
        map<int,int> mp;
        queue<pair<tree *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int hd = node.second;
            auto nbr = node.first;
            if(mp.count(hd)==0){
                mp[hd] = nbr->data;
            }
            if(nbr->left){
                q.push({nbr->left,hd-1});
                }
            if(nbr->right){
                q.push({nbr->right,hd+1});
            }
        }
        for(auto x:mp){
        cout<<x.second<<" ";
    }
    }
    void bottom_view(tree *root){
         map<int,int> mp;
        queue<pair<tree *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int hd = node.second;
            auto nbr = node.first;
            mp[hd] = nbr->data;
            if(nbr->left){
                q.push({nbr->left,hd-1});
                }
            if(nbr->right){
                q.push({nbr->right,hd+1});
            }
        }
        for(auto x:mp){
        cout<<x.second<<" ";
    }
    }
    
};

int main(){
    /*
         5
      4     8
        6      10
    */
    tree *root = NULL;              
    root = root->insert(root,5);
    root = root->insert(root,8);
    root = root->insert(root,4);
    root = root->insert(root,6);
    root = root->insert(root,10);
    root = root->insert(root,15);
    root = root->insert(root,7);
    root = root->insert(root,9);
    cout<<"Top View"<<endl;
    root->top_view(root);
    cout<<"\nBottom View"<<endl;
    root->bottom_view(root);
    return 0;
}

