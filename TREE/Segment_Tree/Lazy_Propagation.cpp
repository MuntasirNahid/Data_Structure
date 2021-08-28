//LAZY PROPAGATION:
//-------------------
//ekbare child node e giye update na korey child node ta jei parent node er under a achey oitakey update korey.so that,comparison onek kome jay.
//jokhn dorkar tokhn update korey(oi range e query thakley)..dorkar na porley update korey na.
// When we need to update an interval, we will update a node and mark its child that it needs to be updated and update it when needed.
//range update er khetrey valo kaj korey thake

// A non-zero value of lazy[i] means that this amount needs to be added to node i in segment tree before making any query to the node.

//Below is modified update method.

// To update segment tree for change in array
// values at array indexes from us to ue.
// updateRange(us, ue)
// 1) If current segment tree node has any pending
//    update, then first add that pending update to
//    current node.
// 2) If current node's range lies completely in 
//    update query range.
// ....a) Update current node
// ....b) Postpone updates to children by setting 
//        lazy value for children nodes.
// 3) If current node's range overlaps with update 
//    range, follow the same approach as above simple
//    update.
// ...a) Recur for left and right children.
// ...b) Update current node using results of left 
//       and right calls.


#include<bits/stdc++.h>
using namespace std;

void updateRange(int node,int st,int en,int l,int r,int val)//l,r=starting and ending indexes of update query.
{
	 // If lazy value is non-zero for current node of segment
    // tree, then there are some pending updates. So we need
    // to make sure that the pending updates are done before
    // making new updates. Because this value may be used by
    // parent after recursive calls (See last line of this
    // function)
 if(lazy[node]!=0)
 {
 	 // Make pending updates using value stored in lazy nodes
       
 	tree[node]+=(en-st+1)*lazy[node];
 	// checking if it is not leaf node because if
        // it is leaf node then we cannot go further
 	if(st!=en)
 	{
 		// We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of node,
            // we need to set lazy flags for the children
 		lazy[node*2]+=lazy[node];
 		lazy[node*2 +1]+=lazy[node];
 	}
 	// Set the lazy value for current node as 0 as it  has been updated
 	lazy[node]=0;
 }
 //out of range
 if(st>en || st>r || en<l)
 	return;
 //current segment is fully in range
 if(st>=l && en<=r)
 {
 	// Add the difference to current node
 	tree[node]+=(en-st+1)*val;
 	 // same logic for checking leaf node or not
 	if(st!=en)
 	{
 		    // This is where we store values in lazy nodes,
            // rather than updating the segment tree itelf
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy[]
 		lazy[node*2]=val;
 		lazy[node*2 +1]=val;
 	}
 	return;
 }
 // If not completely in rang, but overlaps, recur for children,
 int mid=(st+en)/2;
 updateRange(node*2,st,mid,l,r,val);
 updateRange(node*2+1,mid+1,en,l,r,val);
 // And use the result of children calls to update this node
    // tree construct..
 tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node,int st,int en,int l,int r)
{
	if(st>en || st>r || en<l)
		return 0;//out of range
	if(lazy[node]!=0)
	{
		// This node needs to be updated
		tree[node]+=(en-st+1)*lazy[node];//update it
		if(st!=en)
		{
			lazy[node*2]+=lazy[node];//Make child as lazy
			lazy[node*2+1]+=lazy[node];//Make child as lazy
		}
		lazy[node]=0;//Reset it
	}
	if(st>=l && en<=r)// Current segment is totally within range [l, r]
		return tree[node];
	int mid=(st+en)/2;
	int ret=0;
	ret+=query(node*2,st,mid,l,r);//Query Left child
	re+=query(node*2+1,mid+1,en,l,r);//Query Right Child
	return ret;
}

int main()
{
	//bla bla

}
