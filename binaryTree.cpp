#include <iostream>
#include <cstdlib>
#include <vector>
/*
* Author Richmond Frimpong
*  August 17 , 2015
* SIMPLE BTREE IN C++, Feel free to use this code and modify it
* A more prefered implementation will be using a template<class Element>
*/
using namespace std;
//integer binary Tree
class BinaryTree{
	
	public:
	BinaryTree();
	~BinaryTree();
	void insert(int);
	void StrictlyLeftTree();
	void StrictlyRightTree();
	int searchBTree(int);
	void display();
	int getSize();
	void displayRootFirst();
	void properDisplay();
	private:
	struct TreeNode{
		int value;  // can change this to be generic (IDEAL) element;
		TreeNode *left;
		TreeNode *right;
		};	
	TreeNode *ROOT;
	vector<int> v;
	int gl_index;
	void display(TreeNode*) ;
	void displayRootFirst(TreeNode*);
};

BinaryTree::BinaryTree(){ //constructor
	ROOT = NULL;
}
BinaryTree::~BinaryTree() {
	cout <<"TREE DELETED"<<endl;
}//destructor

int BinaryTree::getSize(){
	return v.size();
}
void BinaryTree::insert(int data){
	TreeNode *newNode = new TreeNode();
	TreeNode *temp = new TreeNode();
	newNode->value = data;
	newNode->left = NULL;
	newNode->right = NULL;
	if(ROOT == NULL){
		ROOT = newNode;
	}else{
		//assign a root to a temp node
		temp = ROOT;
		while(temp != NULL){
			if(data < temp->value){
				//iterate over the left elements and find the right spot
				if(temp->left){
					temp = temp->left; 
				}else{
					temp->left = newNode;
					break; //insertion is done
				}
			}else if(data > temp->value){
				//iterate over the right elements and find the right spot
				if(temp->right){
					temp = temp->right;
				}else{
					temp->right = newNode;
					break; //done
				}
			}else{
				cout <<"INSERTION OF DUPLICATES NOT ALLOWED"<<endl;
				break;
			}
		}
	}
 }
int BinaryTree::searchBTree(int data_to_search){
	 TreeNode *node = ROOT;
	 while(node != NULL){
		 if(node->value == data_to_search){
			return node->value;
		}
		else if(data_to_search < node->value){
			node = node->left;
		}else{
			node = node->right;
		}
	}
	 return 0;
 }
	 
 void BinaryTree::StrictlyLeftTree(){
	 TreeNode *it = ROOT;
	 while(it != NULL){
		 cout <<"DATA\t: " << it->value << endl;
		 it = it->left;
	 }
 }
 void BinaryTree::StrictlyRightTree(){	
	TreeNode *it = ROOT;
	it = it->right; //avoids printing the root twice
	while(it != NULL){
		 cout <<"DATA\t: " << it->value << endl;
		 it = it->right;
	 }
 } 
 void BinaryTree::display(TreeNode* aRoot){
	 if(aRoot == NULL)
		 return;
	 
	 display(aRoot->left); // returns the size of the elements also
	 v.push_back(aRoot->value); //intially i was getting compile time errors which was absurd
	 display(aRoot->right);
 }
 void BinaryTree::display(){
	 display(ROOT);
 }
 void BinaryTree::displayRootFirst(TreeNode* root){
	 if (root == NULL)
		 return;
	 cout << root->value <<endl;
	 displayRootFirst(root->left);
	 displayRootFirst(root->right);
 }
 void BinaryTree::displayRootFirst() {
	 displayRootFirst(ROOT);
 }
 /* Added featur to print tree nicely for noobs */
 void BinaryTree::properDisplay(){	

	display(); 
	int tempArray[v.size()];
	int i = 0;
	int length = getSize();
	int middle = length / 2;
	std::copy(v.begin() , v.end() , tempArray); //much faster than the generic implementation
	cout <<"** ROOT =>" << tempArray[middle] <<" **"<<endl;
	cout <<"LEFT TREE .........."<<endl;
	while( i < middle){
		cout << "<--" << tempArray[i] ; 
		i++;
	}
	cout << endl;
	cout <<"RIGHT TREE .........."<<endl;
	int upper = middle + 1;
	while( upper < length ){
		cout << "-->" << tempArray[upper] ; 
		upper++;
	}
	cout << endl;	
 }
 int main(){
	cout <<"TESTING BTREE 2 . . . . . . . .  " << endl;
	BinaryTree tree2;
	tree2.insert(4);
	tree2.insert(5);
	tree2.insert(10);
	tree2.insert(6);
	tree2.insert(1);
	tree2.insert(2);
	tree2.insert(3);
	tree2.insert(8);
	tree2.insert(7);
	cout <<"*********************************"<<endl;
	tree2.properDisplay();
	cout <<"******************SEARCHING ************"<<endl;
	cout<<"FOUND\t:" << tree2.searchBTree(10) <<endl;
	return 0;
 }
