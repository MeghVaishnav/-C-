#include <iostream>
using namespace std;

class MirrorTrees {
	public:
		struct node {
			int data;
			 node*left;
			 node*right;
			
			node(int val) {
				data=val;
				left= NULL;
				right= NULL;
				
			}
		};
		
		static bool areMirror(node*t1,node*t2) {
			if(t1==NULL && t2==NULL) return true;
			if(t1==NULL && t2!= NULL) return false;
			
			
			return (t1->data == t2->data) && areMirror(t1->left,t2->right) &&
			areMirror(t1->right,t2->left);
		} 
};

int main() {
	
	MirrorTrees::node*t1= new MirrorTrees::node(1);
	t1->left= new MirrorTrees::node(NULL);
	t1->right= new MirrorTrees::node(NULL);
	t1->left->right = new MirrorTrees::node(NULL);
	t1->left->left = new MirrorTrees::node (NULL);
	t1->right->left= new MirrorTrees::node (NULL);
	t1->right->right = new MirrorTrees::node (NULL);
	
	MirrorTrees::node*t2 = new MirrorTrees::node(1);
	t2->left=new MirrorTrees::node (NULl);
	t2->right=new MirrorTrees::node (NULL);
	t2->left->right=new MirrorTrees::node (NULL);
	t2->left->left=new MirrorTrees::node (NULL);
	t2->right->left=new MirrorTrees::node (NULL);
	t2->right->right= new MirrorTrees::node (NULL);
	
	
	if(MirrorTrees::areMirror(t1,t2)) 
	cout<<"Given two trees are mirror of eachother."<<endl;
	else
	cout<<"Give two trees are NOT mirror of eachother."<<endl;
	 
	 
	 return 0;
	
	
}

