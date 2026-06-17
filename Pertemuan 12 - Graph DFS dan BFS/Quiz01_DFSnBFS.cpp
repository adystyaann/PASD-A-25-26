#include <iostream>
#include <queue>
using namespace std;

int cost[10][10], visited[10];
char simpul[7] = {' ', 'A', 'B', 'C', 'D', 'E', 'F'};
int n = 6;

// DFS
void DFS(int v) {
    visited[v] = 1;
    cout << simpul[v] << " ";

    for (int j = 1; j <= n; j++) {
        if (cost[v][j] == 1 && !visited[j]) {
            DFS(j);
        }
    }
}

// BFS
void BFS(int start) {
    int visit[10] = {0};
    queue<int> q;

    q.push(start);
    visit[start] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << simpul[v] << " ";

        for (int j = 1; j <= n; j++) {
            if (cost[v][j] == 1 && !visit[j]) {
                visit[j] = 1;
                q.push(j);
            }
        }
    }
}

int main() {

    // Busur (hubungan antar simpul)
    cost[1][2] = cost[2][1] = 1; // A-B
    cost[1][3] = cost[3][1] = 1; // A-C
    cost[2][4] = cost[4][2] = 1; // B-D
    cost[2][5] = cost[5][2] = 1; // B-E
    cost[3][6] = cost[6][3] = 1; // C-F

    char awal;
    cout << "Masukkan simpul awal (A-F): ";
    cin >> awal;

    int start;

    switch (awal) {
        case 'A': start = 1; break;
        case 'B': start = 2; break;
        case 'C': start = 3; break;
        case 'D': start = 4; break;
        case 'E': start = 5; break;
        case 'F': start = 6; break;
        default:
            cout << "Simpul tidak valid!";
            return 0;
    }

    cout << "\nHasil BFS : ";
    BFS(start);

    cout << "\nHasil DFS : ";
    DFS(start);

    int jumlah = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            jumlah++;
    }

    cout << "\nJumlah simpul yang dikunjungi : " << jumlah << endl;

    return 0;
}