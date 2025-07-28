#include <bits/stdc++.h>
using namespace std; 
int main() {

    int tC=5;
    cout<<5<<endl;
    while (tC--) {
        int n = (rand()%20)+1;
        
        vector<int> v(2*n);
        
        for(int i=0; i<2*n; i++) v[i]=(i%n +1);
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(v.begin(), v.end(),  std::default_random_engine(seed));
        cout<<n<<endl;
        for(int i=0; i<2*n; i++) {
            if (i==n) cout<<endl;
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    
}