#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "\U0001F4CB Banker's Algorithm (Deadlock Avoidance)\n";

    cout << "\nEnter number of processes: ";
    cin >> n;

    cout << "Enter number of resource types: ";
    cin >> m;

    vector<vector<int> > alloc(n, vector<int>(m));
    vector<vector<int> > max(n, vector<int>(m));
    vector<vector<int> > need(n, vector<int>(m));
    vector<int> avail(m);
    vector<int> work(m);
    vector<bool> finish(n, false);
    vector<int> safeSeq;

    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process P" << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    cout << "\nEnter Max Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process P" << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    cout << "\nEnter Available Resources: ";
    for (int i = 0; i < m; i++) {
        cin >> avail[i];
        work[i] = avail[i]; // Copy to work
    }

    cout << "\n🧮 Need Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    finish[i] = true;
                    safeSeq.push_back(i);
                    count++;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "\n❌ System is not in a safe state (Deadlock possible).\n";
            return 0;
        }
    }

    cout << "\n✅ Safe Sequence: ";
    for (int i = 0; i < safeSeq.size(); i++) {
        cout << "P" << safeSeq[i];
        if (i != safeSeq.size() - 1) cout << " → ";
    }
    cout << "\n✔️ System is in a safe state.\n";

    return 0;
}
