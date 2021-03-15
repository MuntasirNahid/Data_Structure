//root er boro hole right subtree e coley jabey..
//root er choto holey left subtree e coley jabey..
//root er shoman holey right subtree e jabo..
//delete and insertion onek costly.->sorted linear array
//insertion deletion easy but search kora ta expensive ->linked list
//Binary Sorted Tree o bola hoye thakey..

//Case 3 deletion: 2 ta child achey emon
//inorder successor(S(n)) er kono left child thakbey na..
//in order successor ber korar niyom:
//N er(jetakey delete korbo) right e jabo 1 step.then left e jetey thakbo..jetar ar left pabona..shetai in order successor.
//N k S(n) diye replace kore case 1 and case 2 follow korlei hoye jabey.

#include <iostream>
using namespace std;

struct node {
	int val;
	node *left, *right, *parent;
	node(int x) {
		val = x;
		left = right = parent = NULL;
	}
};

struct BST {
	node *root;
	/// constructor
	BST();
	///utility function
	node* find_child(int, node*);
	node* find_succ(node*);
	node* find_node(int);
	

	/// global function
	void insert(int);
	void del(int);
	bool find(int);

};


BST::BST() {
	root = NULL;
}

node* BST::find_child(int val, node *temp) {
	if (temp->val <= val) return temp->right;
	return temp->left;
}

void BST::insert(int x)
{
	node *cur = new node(x), *temp, *temp_child;
	if (root == NULL) {
		root = cur;
		return;
	}
	temp = root;
	temp_child = find_child(x, temp);
	while (temp_child != NULL) {//jotokkhn porjntow temp er child NULL na pacchey..
		temp = temp_child;
		temp_child = find_child(x, temp);
	}//NULL peye geche ekhn insert korey dibey..
	if (temp->val <= x) temp->right = cur;
	else temp->left = cur;
	cur->parent = temp;
}

node* BST::find_node(int x)
{
	node  *temp, *temp_child;
	if (root == NULL)
		return NULL;
	temp = root;
	temp_child = find_child(x, temp);
	while (temp_child != NULL) {
		if (temp->val == x) return temp;
		temp = temp_child;
		temp_child = find_child(x, temp);
	}
	return temp;//na pailey tow null return korbey
}

node* BST::find_succ(node* temp)
{
	if (temp->right->left == NULL) return temp->right;
	node *ret = temp->right;
	while (ret->left != NULL)
		ret = ret->left;
	return ret;
}

void BST::del(int x)
{
	node *temp = find_node(x), *temp_child, *in_succ;

	/// case 1
	if (temp->left == NULL && temp->right == NULL) {
		if (temp == root)
			root = NULL;
		else if (temp->parent->left == temp)
			temp->parent->left = NULL;
		else
			temp->parent->right = NULL;
		delete temp;
		return;
	}
	/// case 2
	if (temp->left == NULL || temp->right == NULL) {
		temp_child =  temp->left == NULL ? temp->right : temp->left;
		if (temp == root)
			root = temp_child;
		else if (temp->parent->left == temp) { //temp jodi tar parent er left child hoy
			temp->parent->left = temp_child;//tahole tar bacca ke tar baper sathey cnctd korey dilam
			temp_child->parent = temp->parent;//bacca key boley dilam tomar dada hoilo tomar bap(mirzapur xD)
		}

		else {
			temp->parent->right = temp_child;
			temp_child->parent = temp->parent;
		}
		delete temp;
		return;
	}
	/// case 3
	in_succ = find_succ(temp);
	node *cur = new node(in_succ->val);

	cur->left = temp->left;//replace korar por temp er left child hoye jabey crnt er left child..because in_succ ber korar shomoy 1st bar dan dike traverse
	bool direct_succ = temp->right == in_succ;
	if (!direct_succ) //temp er right child tai in order succesor na hoile..
		cur->right = temp->right;
	else
		cur->right = in_succ->right;//replace er por crnt er right child hoye jabey in order succ er right
	temp->left->parent = cur;//replace er por crnt ke parent banaya dichi left child er..

	del(in_succ->val); //replace kora done..ekhn ager takey dlt korey dibo..

	if (temp->right != NULL )temp->right->parent = cur; //in order succ takey parent banaya dichi right child er
	if (temp == root) root = cur;
	else {
		cur->parent = temp->parent;//current er parent k temp er parent korey dilam..
		if (temp->parent->left == temp) temp->parent->left = cur; //temp takey delete kore diye tar bacca ke tar baper kachey bujhai dilam...
		else temp->parent->right = cur;
	}
	delete temp;
	return;
}

bool BST::find(int x)
{
	node *temp = find_node(x);
	return (temp != NULL && temp->val == x);
}


int main()
{
	int n, m, x, y, res;
	BST *bst = new BST();
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		/// 1 - insert, 2 - delete, 3 - find
		cin >> x >> y;

		switch (x)
		{
		case 1:
			bst->insert(y);
			break;

		case 2:
			bst->del(y);
			break;

		case 3:
			res = bst->find(y);
			cout << y << " is" << (res ? "" : " not") << " found!\n";
			break;
		default:
			cout << "Ops! I cannot read your mind!\n";
			break;
		}

	}
	return 0;
}
/**
16
1 38
1 14
1 56
1 8
1 23
1 18
1 56
1 45
1 82
1 70
2 45
2 23
2 14
3 45
3 70
4 70
*/