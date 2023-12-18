#include <iostream>
using namespace std;

class LongestCommonSubsequence {
private:
    int** count;
    int m,n;
public:
    LongestCommonSubsequence(int m, int n) {
        count = new int*[m + 1];
        this->m = m;
        this->n = n;
        for (int i = 0; i <= m; i++) {
            count[i] = new int[n + 1];
            fill_n(count[i], n + 1, 0);
        }
    }

    ~LongestCommonSubsequence() {
        for (int i = 0; count && i <= m; i++) {
            delete[] count[i];
        }
        delete[] count;
    }

    void LCS_Length(char* A, char* B, int m, int n) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i - 1] == B[j - 1]) {
                    count[i][j] = count[i - 1][j - 1] + 1;
                } else if (count[i - 1][j] >= count[i][j - 1]) {
                    count[i][j] = count[i - 1][j];
                } else {
                    count[i][j] = count[i][j - 1];
                }
            }
        }
        cout << count[m][n] << endl;
    }
};

int main() {
    int x, y;

    cout << "Enter length of first sequence: ";
    cin >> x;
    char* A = new char[x];
    cout << "Enter first sequence:";
    for (int i = 0; i < x; i++) {
        cin >> A[i];
    }

    cout << "Enter length of second sequence: ";
    cin >> y;
    char* B = new char[y];
    cout << "Enter second sequence:";
    for (int i = 0; i < y; i++) {
        cin >> B[i];
    }

    LongestCommonSubsequence lcs(x, y);
    lcs.LCS_Length(A, B, x, y);

    delete[] A;
    delete[] B;
    return 0;
}
