#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct cur {
    int value;
    int id;
    int vart;
};

void print(vector<int> a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

bool fvalue(cur a, cur b) {
    return a.value < b.value;
}
bool fid(cur a, cur b) {
    return a.id < b.id;
}

int main() {
   
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int n, d;
    fin >> n >> d;

    vector<cur> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i].value;
        a[i].id = i;
        a[i].vart = 1;
    }
    sort(a.begin(), a.end(), fvalue);

    int l = 0, r = 1;
    int maxg = 1;
    while (r < n) {
        if ((a[r].value - a[l].value) > d) {
            l = r;
            r++;
        }
        else {
            a[r].vart = a[r - 1].vart + 1;
            maxg = max(a[r].vart, maxg);
            r++;
        }
    }

    sort(a.begin(), a.end(), fid);

    fout << maxg << endl;

    for (auto i : a) {
        fout << i.vart << " ";
    }

    return 0;
}