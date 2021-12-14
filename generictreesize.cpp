#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*> children;
};

Node* newNode(int val){
    Node* node=new Node();
    node->data=val;
    return node;
}
Node* constructor(int arr[],int n){
 
    stack<Node*> st;
    Node* root;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }
        else{
            Node* t= newNode(arr[i]);
            if(st.empty()==true){
                root=t;
            }
            else{
                st.top()->children.push_back(t);
            }
              st.push(t);
        }
    }
    return root;
}

void display(Node* node){
    string str;
    str+=to_string(node->data);
    str+="-->";

    for(Node* it:node->children){
        str+=to_string(it->data)+", ";
    }
    str+=".";
    cout<<str<<endl;
    for(Node* it:node->children){
        display(it);
    }
}

int size(Node* root){
    int res=0;
    for(Node* child: root->children){
        res+=size(child);
    }
    return 1+res;
}

int main(){
       int n;
       cin>>n;
       
       int arr[n];
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       
       Node* root=constructor(arr,n);
       int sz=size(root);
       cout<<sz<<endl;
}
