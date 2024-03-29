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
       
 	tree[node]+=(en-st+1)*lazy[node];//nicer shobgula node er j update kora lagbey oigulaw tow add hobey tree[node] er moddhe..tai(en-st+1) multiply kortey hoise
 	//suppose there is update for arr[start] to arr[end] adding v so total added is (end-start+1)*v .As in a segment tree a node (tree[node] )gives sum of array
	 //values it covers ,so we updated tree node as tree[node]+=(end-start+1)*v ,later we will update left and right node
	 
	 
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
 		lazy[node*2]+=val;
 		lazy[node*2 +1]+=val;
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

/*
#include <bits/stdc++.h>
#define sz 1000005
#define ll long long
using namespace std;
ll tree[sz], lazy[sz];
ll z;

void updateRange(ll node, ll st, ll en, ll l, ll r, ll val) // l,r=starting and ending indexes of update query.
{

   if (lazy[node])
   {

      tree[node] += ((en - st) + 1) * lazy[node]; // nicer shobgula node er j update kora lagbey oigulaw tow add hobey tree[node] er moddhe..tai(en-st+1) multiply kortey hoise

      if (st != en)
      {

         lazy[node * 2] += lazy[node];
         lazy[node * 2 + 1] += lazy[node];
      }

      lazy[node] = 0;
   }
   // out of range
   if (st > en || st > r || en < l)
      return;

   if (st >= l && en <= r)
   {

      tree[node] += ((en - st) + 1) * val;

      if (st != en)
      {

         lazy[node * 2] += val;
         lazy[node * 2 + 1] += val;
      }
      return;
   }

   ll mid = (st + en) / 2;
   updateRange(node * 2, st, mid, l, r, val);
   updateRange(node * 2 + 1, mid + 1, en, l, r, val);

   tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll st, ll en, ll l, ll r)
{
   if (st > en || st > r || en < l)
      return 0; // out of range
   if (lazy[node] != 0)
   {

      tree[node] += (en - st + 1) * lazy[node];
      if (st != en)
      {
         lazy[node * 2] += lazy[node];
         lazy[node * 2 + 1] += lazy[node];
      }
      lazy[node] = 0;
   }
   if (st >= l && en <= r)
      return tree[node];
   ll mid = (st + en) / 2;
   ll ret = 0;
   ret += query(node * 2, st, mid, l, r);
   ret += query(node * 2 + 1, mid + 1, en, l, r);
   return ret;
}
void init()
{
   for (ll i = 0; i < sz; i++)
   {
      tree[i] = 0, lazy[i] = 0;
   }
}
void nahid()
{
   //cout << "Case " << ++z << ":" << endl;

   ll n, q;
   cin >> n >> q;
   init();
   while (q--)
   {
      ll m;
      cin >> m;
      if (m == 0)
      {
         ll x, y, v;
         cin >> x >> y >> v;
         updateRange(1, 0, n - 1, x-1, y-1, v);
         // for (ll i = 0; i < n; i++)
         //    cout << tree[i] << " ";
         // cout << endl;
      }
      else
      {
         ll x, y;
         cin >> x >> y;
         cout << query(1, 0, n - 1, x-1, y-1) << endl;
      }
   }
}
int main()
{
   ll t;

   cin >> t;
   while (t--)
   {
      nahid();
   }
}
*/
