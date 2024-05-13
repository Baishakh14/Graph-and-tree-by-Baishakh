#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}sn;

struct node *createnode(int data)
{
   struct node *ab = (struct node *) malloc (sizeof(struct node));
   ab->data = data;
   ab->left = NULL;
   ab->right = NULL;
return ab;
}

struct node *insert(struct node *root,int data)
{
   if(root == NULL)
   {
       root = createnode(data);
       return root;
   }
   if(data>= root->data)
   {
    root->right = insert(root->right,data);
   }
   else
   root->left = insert(root->left,data);
   return root;
   }

//    void inorder(struct node *root)
//    {
//     if(root != NULL)
//     {
//         inorder(root->left);
//         cout<<root->data<<" ";
//         inorder(root->right);
//     }
//    }

void bfs(struct node *root)
{
    cout<<root->data;
    queue<struct node*>q;
    q.push(root->left);
    q.push(root->right);
    struct node *v;
    while(!q.empty())
    {
       v = q.front();
       q.pop();
       if(!v) continue;
       cout<<' '<<v->data;
       q.push(v->left);
       q.push(v->right);
    }
}
int main()
{
    int t = 1;
 int n;
 cin>>n;
 while(n--)
 {
    int a;
    cin>>a;
    int ab[a];
    for(int i = 0;i<a;i++)
    {
        cin>>ab[i];
    }
 struct node *root = NULL;
 for(int i = 0;i<a;i++)
 {
    root = insert(root,ab[i]);
 }
 //inorder(root);
 cout<<"Case "<<t++<<":"<<endl;
 bfs(root);
 cout<<endl<<endl;
 }

    return 0;
}
