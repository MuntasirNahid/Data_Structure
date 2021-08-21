/*Tree is a special type of graph which has no cycle..

Complete Binary Tree:
The tree T is said to be complete binary tree if all its levels ,except possibly the last ,have the maximum number of possible nodes,
and if all the nodes at the appear as far left as possible .

jekono shonkhok n er jonno complete binary tree unique.

just ekta element (root) thaklew sheta binary tree.

complete binary tree er khetre left allign pradhanno pay.

extended binary tree er child obosshoi 2 type thaktey hobey.either 0 or 2.

*/

/*
Binary tree k memory tey representation er way 2 ta..
1)linked representation
2)sequential representation.


 1 based holey 2^k=left child,(2^k)+1=right child.
 0 based holey 2^n+1=left child,2^n+2=right child.
 parent=floor(k/2);


 traversal:
 preorder:
 root->left->right
 inorder:
 left->root->right
 postorder:
 left->right->root.

*/
