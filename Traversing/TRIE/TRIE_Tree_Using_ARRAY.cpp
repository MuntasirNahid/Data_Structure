#include <iostream>
#include <cstring>
#define sz 10000
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define trie_sz 26
using namespace std;


struct node{
    bool ending;
    int next[trie_sz];
    node()
    {
        ending = false;
        for (int i = 0; i<trie_sz; i++)
            next[i] = 0;
    }
};

struct TRIE{
    int counter;
    node data[sz];
    TRIE();
    void insert_into_trie(string &str);
    bool search_into_trie(string &str);
    void delete_from_trie();
};

TRIE::TRIE(){
    counter = 1;//index ta janar jonnoi muloto counter ta newa..
}

void TRIE::insert_into_trie(string &str){
    int now, len = str.size(), k = 0;
    for (int i  = 0; i<len; i++)
    {
        now = str[i] - 'a';
        if(data[k].next[now] == 0)//porer step ta ==zero holey counter++ korey nilam...
            data[k].next[now] = counter++;
        k = data[k].next[now];//ek step nisey namaya dilam...
    }
    data[k].ending =  true;
}
bool TRIE::search_into_trie(string &str){
    int now, len = str.size(), k = 0;
    for (int i = 0; i<len; i++)
    {
        now = str[i] - 'a';
        if(data[k].next[now] == 0) return false;
        k = data[k].next[now];
    }
    return data[k].ending;
}

void TRIE::delete_from_trie(){
    counter=1;
    clr(data,0);//zero diye initialize...
}
int main()
{
    int n, q;
    string str;
    TRIE tr;

    cin >> n;
    for (int i = 0; i<n; i++)
    {
        cin >> str;
        tr.insert_into_trie(str);
    }

    cin >> q;

    for (int i = 0; i<q; i++)
    {
        cin >> str;
        cout <<"Query Number "<<i+1<<" :"<<str<<endl;
        cout<<"Result :" <<str<<" does " << (tr.search_into_trie(str)?"":"not ") << "exist!" << endl;
    }
    tr.delete_from_trie();
    return 0;
}
/**
17
abcdaabcdefa
ababcadacc
aaa
aa
aab
aabccc
aabc
aab
abcdaabcde
wow
this
that
those
this
is
absolutely
vogue
10
these
is
i
absolute
abcdaabcd
vog
abcdaabcdefa
aaaa
aabc
aabcc
*/
