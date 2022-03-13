#include <iostream>
#include <vector>
 
using namespace std;
 
class DSU {
 
public:
    int size;
    int components;
    vector<int> component_size;
    vector<int> id;
 
    DSU(int size) {
        this->size = size;
        this->components = size;
        this->component_size.resize(size, 1);
        this->id.resize(size);
        for(int i = 0; i < size; i++) {
            id[i] = i;
        }
    }
 
    int getSize() {
        return this->size;
    }
 
    int Find(int a) {
        int root = a;
 
        while(root != id[root]) {
            root = id[root];
        }
 
        while(a != root) {
            id[a] = root;
            a = id[a];
        }
 
        return root;
    }
 
    int Union(int a, int b) {
        int root_a = Find(a);
        int root_b = Find(b);
 
        if(root_a == root_b) {
            return root_a;
        } else {
            if (component_size[root_a] >= component_size[root_b]) {
                component_size[root_a] += component_size[id[root_b]];
                components--;
                return id[root_b] = root_a;
            } else {
                component_size[root_b] += component_size[id[root_a]];
                components--;
                return id[root_a] = root_b;
            }
        }
    }
 
    void Show() {
        for(int i=0; i<size; i++) {
            cout << i << ' ' << id[i] << endl;
        }
        cout << endl;
        for(int i=0; i<size; i++) {
            cout << i << ' ' << component_size[Find(i)] << endl;
        }
    }
 
};
 
void test();
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
//    cin >> t;
    while(t--) {
        test();
        cout << endl;
    }
}
 
void test() {
    int n, m, hazine;
    cin >> n >> m >> hazine;
    int zero_count = 0;
    DSU dsu(n + m);
    vector<bool> c(n, false);
    int ans = 0;
    for(int i=0; i<n; i++) {
        int k, u, v;
        cin >> k;
        if(k == 0) {
            ans++;
            zero_count++;
        } else {
            cin >> u; u--;
            dsu.Union(i, n + u);
        }
        for(int j=1; j<k; j++) {
            cin >> v; v--;
            dsu.Union(n + u, n + v);
        }
    }
    for(int i=0; i<n; i++) {
        int root = dsu.Find(i);
        if (!c[root] && dsu.component_size[root] > 1) {
            c[root] = true;
            ans++;
        }
    }
    if(zero_count == n) ans++;
    cout << hazine * (ans - 1);
}