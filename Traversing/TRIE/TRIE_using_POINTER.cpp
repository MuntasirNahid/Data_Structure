#include <iostream>
#define sz 10000
#define trie_sz 26
using namespace std;
struct node{
    bool ending;//word er ending ta ekta bool e niye nichi.. 
    node *next[trie_sz];//proti ta digit er por 26 ta digit rakhar ghor rekhe disi.. 
    node()
    {
        ending = false;
        for (int i = 0; i<trie_sz; i++)
            next[i] = NULL;//proti ta digit er por 26 ta place k null korey initialize korey rakhlam...
    }
};

struct TRIE{
    node *root;
    TRIE();
    void insert_into_trie(string &str);
    bool search_into_trie(string &str);
    void delete_from_trie();

    /// utility function
    void delete_node(node *cur);
};

TRIE::TRIE(){
    root = new node();
}

void TRIE::insert_into_trie(string &str){
    node *cur = root;
    int now, len = str.size();
    for (int i  = 0; i<len; i++)
    {
        now = str[i] - 'a';
        if(cur->next[now] == NULL)//jodi null thakey porer ta..
            cur->next[now] =  new node();//null holey pore new node create korlam...
        cur = cur->next[now];//cur ke cur er next korey dilam...1 step nisey namlo...
    }
    cur->ending =  true;//word shesh..ekhn ending ta true korey dilam...
}
bool TRIE::search_into_trie(string &str){
    node *cur = root;
    int now, len = str.size();
    for (int i = 0; i<len; i++)
    {
        now = str[i] - 'a';
        if(cur->next[now] == NULL) return false;//null pailey false return...maney nai emon word...
        cur = cur->next[now];
    }
    return cur->ending;//ending ta return...
}

void TRIE::delete_node(node *cur){
    for (int i = 0; i<trie_sz; i++)
        if(cur->next[i]!=NULL) delete_node(cur->next[i]);
    delete cur;//shobar sheshe nijeke delete korey dewa...
}

void TRIE::delete_from_trie(){
    delete_node(root);
}
int main()
{
    int n, q;//n=word shongkha...q=query shongkha...
    string str;
    TRIE *tr = new TRIE();

    cin >> n;
    for (int i = 0; i<n; i++)
    {
        cin >> str;
        tr->insert_into_trie(str);
    }

    cin >> q;

    for (int i = 0; i<q; i++)
    {
        cin >> str;
        cout <<"Query Number "<<i+1<<" :"<<str<<endl;
        cout<<"Result :" <<str<<" does " << (tr->search_into_trie(str)?"":"not ") << "exist!" << endl;
    }
    tr->delete_from_trie();//multiple test case er jonno delete ta kaje lagey...
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
