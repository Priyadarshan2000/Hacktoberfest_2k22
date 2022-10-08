#include <bits/stdc++.h>
#include <fstream>
#define m 10
using namespace std;
int n, cm, c=1;
int graph[m][m], x[m];
void input(){
    int x;
    ifstream in ("abc.txt");
    in >> n;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            in >> x;
            graph[i][j] = x;
        }
    }
}
void print(){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cout << "\t" << graph[i][j];
        }
        cout << "\n";
    }
}
void next_Value(int k){
   while (1){
    x[k] = (x[k] + 1) % (cm + 1);
    if (x[k] == 0){
        return;
    } 
    int j;
    for (j = 1; j <= k-1; j ++){
        if (graph[k-1][j-1] >= 1 && x[k] == x[j]){
            break;
        }
    }
    if (j == k){
        return;
    }
   }
}
void graph_coloring(int k){
    while(1){
       next_Value(k);
       if (x[k] == 0){
           return;
       }
       if (k == n){
           cout << "Solution No:: ";
           cout << c << endl;
           for (int i = 0; i < n; i ++){
               cout << char(i+65) << "-->" << x[i+1] << endl;
           }
           c ++;
       }
       else{
           graph_coloring(k + 1);
       }
   }
}
int main(){
    input();
    cout << "The graph is :: " << endl;
    print();
    cout << "Enter the chromatic number :: " << endl;
    cin >> cm;
    graph_coloring(1);
    return 0;
}
