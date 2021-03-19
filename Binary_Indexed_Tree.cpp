//for Cumulative sums
//HackerEarth
//https://www.hackerearth.com/practice/notes/binary-indexed-tree-or-fenwick-tree/

//segment tree --> Query=Update= 0(logN);Build=memory=0(nlogN)

//BIT---> Query=Update=0(logN);Build=memory=0(N);

//code choto and kom space ney ..thats why segment tree er jaygay BIT use kora jay..

//another name is Fenwick tree

//range update er moddhe beshi kaje lage.

//point update

//prefix sum: 1st er theke i porjonto element er sum

//2 er power , x-or ei duita jinish use korey thakey.


//1->00001  -1
//2->00010   -1+1=2(1 er binary representation er sathey 1 add korley amra 2 er ta pacchi)
//3->00011    -2+3

//4->00100    -4
//5->00101    -4+5
 //mane 2 ,4,8,16 egular moddhe eder ager number gular sum paitechi...

#include<iostream>
#define sz 10000
using namespace std;
int BIT[sz], n;
void update(int x, int delta)//hackerearth...
{
    for (; x <= n ; x += x&-x )//x+=x&-x -->set bit ta add korey nicchi..barbar last set bit ta add kore dicchi..foley 
        //update er jonno jeshob jaygay effect korey segulay change hoye jacche.
        //like Bit[5] er moddhe jodi update hoy 101 +001(set bit er sathe jog)=110 mane Bit[6] eo update hobe.then
        //110+010=100(mane 8 er moddhe update hobey..0and so on..
        BIT[x] += delta;
}

int query(int x)//hackerearth..
{
    int sum = 0;
    for (; x > 0 ; x -= x&-x )
        sum += BIT[x];
    return sum;
}

int main()
{
    int q, x, y, k;

    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> x;
        update(i,x);
    }

    cin >> q;
    for (int i = 0; i<q; i++)
    {
        cin >> k >> x >> y;
        if(k==1)//query...maneh sum gula...
            cout << query(y+1) - query(x) << endl;//0 based indexing. jemon[2,7]range er jonno 1 based indexing er moddhe q[7]-q[2-1]=ans;
        else//update kora...
            update(x+1,y - query(x+1) + query(x) );//x+1 tomo element(0 based indexing) er moddhe update..
        //maneh x tomo index a y change korbo...ekhetre y-(query(x+1)-query(x));....jemon 2 3 5 6...5 er jaygay 
        //2 update ditey caile change=2(y)-5=-3=delta...oirokom arki...BIt er moddhe tow emon sum hishab
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
