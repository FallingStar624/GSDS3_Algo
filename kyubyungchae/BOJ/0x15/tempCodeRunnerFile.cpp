#include <iostream>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <math.h>
#include <vector>
#include <utility>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;

    cin >> t;

    while(t--) {
        unordered_map<string, int> umap;
        cin >> n;
        while(n--) {
            string cloth, type;
            cin >> cloth >> type;

            if(umap.find(type) == umap.end()) {
                umap[type] = 1;
            } else {
                umap[type] += 1;                
            }
        }

        int ans = 0;
        for(auto elem : umap){
            ans += pow((double)2, (double)elem.second);
        }
        cout << (ans - 1) << '\n';
    }


    return 0;
}

