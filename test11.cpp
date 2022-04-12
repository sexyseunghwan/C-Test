#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {


    // stack<int> st;
    // int dr[6] = {1,65,33,100,98,22};

    // for (int i = 5; i > 0;) {
    //     //st.push(i = dr[i]);
    //     printf("%d\n",dr[i]);
    // }

    // //printf("%d",st.top());

    
    vector< pair<int,int> > node[3];

    node[0].push_back(make_pair(1,1));
    node[0].push_back(make_pair(1,2));
    node[0].push_back(make_pair(1,3));
    node[0].push_back(make_pair(1,4));
    node[0].push_back(make_pair(1,5));
    node[0].push_back(make_pair(1,6));

    //node[0].clear();
    //node[0] = null;
    vector< pair<int,int> >().swap(node[0]);

    //node[0].push_back(make_pair(1,10));

    cout << node[0][0].second;


}