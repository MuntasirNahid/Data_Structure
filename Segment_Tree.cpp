/*A Segment Tree is a data structure that allows answering range queries over an array effectively, while still being flexible enough to allow modifying the array. This includes finding the sum of consecutive array elements a[l…r], or finding the minimum element in a such a range in O(logn) time. Between answering such queries the Segment Tree allows modifying the array by replacing one element, or even change the elements of a whole subsegment (e.g. assigning all elements a[l…r] to any value, or adding a value to all element in the subsegment).
*/

//ekta range er moddhe  element er sum ber kortey holey cummulative sum ber korey kora jay..but jodi koyekta element er value update korey tahole oi element er pore joto element ache shobgular cummolative sum update kortey hoy..seshob er jonno segment tree use koras hoye thakey..

//n er range takey (0-n) binary search er moto korey barbar duivag kortey thakbo..jotokkhn na 0-0,1-1,2-2,..n-n emon na ashey..protita node e tar child node gular sum thakbey..
//range er upper bound and lower bound kon kon chunk er moddhe porey oita check kortey hobey.
//range direct kono chunk er moddhe na porley vangtey hobe(child tree tey jaitey hobey)..
//mane puro query range ta kono chunk er range er moddhe na porley vangtey hobey(overlapping ache)
//query range er puro bahire kono chunk porley seta bad diye dibo.

//query range er vitore kono chunk porley seta key include kore nibo sum er  moddhe,
//update er khetrey just parent gulo k update diye diye jabo..

//complexity of every query and updates is(log N); Build=memory=(nlogN);

//LAZY PROPAGATION:
//-------------------
//ekbare child node e giye update na korey child node ta jei parent node er under a achey oitakey update korey.so that,comparison onek kome jay.
//jokhn dorkar tokhn update korey(oi range e query thakley)..dorkar na porley update korey na.
// When we need to update an interval, we will update a node and mark its child that it needs to be updated and update it when needed.

#include <iostream>
#define sz 40000
using namespace std;
int tree[sz];

void update(int ind, int lb, int ub, int pos, int val)//pos=kon position er moddhe update ta dibo..val=update 
//kore kon value ta rakhbo..
{
    if(pos < lb || ub < pos) return;//range er moddhei nai..

    if(lb==ub)//0-0,1-1...emon....update dewar ashol jayga.
    {
        if(lb == pos)//or ub==pos..same kotha e.
            tree[ind] = val;//update diye dilam
        return;
    }

    int mid = (lb+ub)/2;
    if(pos<=mid) update(2*ind,lb,mid,pos,val);//left side a jabeyy..
    else update(2*ind+1,mid+1,ub,pos,val);//right side a jabey...
    tree[ind] = tree[2*ind] + tree[2*ind+1];//tree takey reconstruct kora....
}

int query(int ind, int lb, int ub, int qlb, int qub)//tree er lb and ub,query er lb and ub.
{
    if(qlb <= lb && ub <= qub) return tree[ind];//lb,ub er range purotai qlb,qub er modhe porey geche...jemon lb-up=2-4,qlb-qrb=1-8;
    if(qub < lb || qlb > ub) return 0;//purotai range er baire....
   //overlapping er khetre....
    int mid =  (ub+lb)/2;
    int ret = 0;
    ret += query(ind*2,lb,mid,qlb,qub);//left side theke..
    ret += query(ind*2+1,mid+1,ub,qlb,qub);//right side theke... 
    return ret;
}

int main()
{
    int n, q, x, y, k;

    cin >> n;
    for (int i = 0; i<n; i++)
    {
        cin >> x;
        update(1,0,n-1,i,x);// start node er moddhe 1.mane root node(0-(n-1)) ta hocche 1 index er moddhe..left child hocche 2*k inddex e..right child hocche 2*k_1 index er moddhe
        // ..0,n-1-->tree ta koto theke koto index er moddhe construct korchi. 
    }

    cin >> q;
    for (int i = 0; i<q; i++)
    {
        cin >> k >> x >> y;
        if(k==1)//x and y range er sum return ;0,n-1 holo tree tar start and end;
            cout << query(1,0,n-1,x,y) << endl;
        else//2 holo x th index er moddhe y diye update..
            update(1,0,n-1,x,y);
    }
    return 0;
}
/**
5
7 3 10 2 1
7
1 0 4
2 2 4
1 0 4
1 1 4
1 0 3
2 0 17
1 0 0
*/
