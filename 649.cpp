#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int n, k;
    fin >> n >> k;
    string password;
    fin >> password;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string prov = password.substr(i, j - i + 1);

            sort(prov.begin(), prov.end());

            int pred = 0;
            int maxi = 0;

            for (int t = 0; t < j - i + 1; t++) {
                if (prov[t] == prov[t + 1]) {
                    pred++;
                }
                else {
                    pred++;
                    if (pred > maxi) {
                        maxi = pred;
                    }
                    pred = 0;
                }
            }

            if (maxi <= k) {
                answer++;
            }
        }
    }

    fout << answer;

    return 0;
}