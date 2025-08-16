#include <bits/stdc++.h>
// la basura que tiene que poner para poder usarlo
#include <ext/pb_ds/assoc_container.hpp>     
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;
// OJO: si quiere cambiar el tipo de dato que recibe el OS, solo ocupa cambiar 
// los campitos donde dice int aquí abajito
#define ordered_set tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update >

#define ll long long
using namespace std;

int main() {
    ordered_set nikolOS;

    nikolOS.insert(5);
    nikolOS.insert(1);
    nikolOS.insert(2);


    // el segundo (OJO QUE ES CERO INDEXADO) más peq
    cout << *(nikolOS.find_by_order(1))<< endl;


    // el # de elementos < (OJO QUE ES ESTRICTO) que 5
    cout << nikolOS.order_of_key(5)<< endl;
}