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

    void printLCS(int row, int col, string text1, string text2, int **mat)
    {
        int length = mat[row][col];
        char *lcs = new char[length + 1];

        int i = row, j = col, index = length;
        while (i > 0 && j > 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                lcs[index] = text1[i - 1];
                i--;
                j--;
                index--;
            }
            else if (mat[i - 1][j] > mat[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        cout << "\nThe largest common subsequence is: ";
        for (int k = 1; k <= length; k++)
        {
            cout << lcs[k];
        }

        delete[] lcs;
    }

    void lcs(int row, int col, string text1, string text2)
    {
        int **mat = new int *[row + 1];
        for (int i = 0; i <= row; i++)
        {
            mat[i] = new int[col + 1];
        }

        for (int i = 0; i <= row; i++)
        {
            for (int j = 0; j <= col; j++)
            {
                if (i == 0 || j == 0)
                {
                    mat[i][j] = 0;
                }
                else if (text1[i - 1] == text2[j - 1])
                {
                    mat[i][j] = mat[i - 1][j - 1] + 1;
                }
                else
                {
                    mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
                }
            }
        }
        cout << "\n"<< "The largest common subsequence length is: " << mat[row][col];
        printLCS(row, col, text1, text2, mat);

        // Deallocate memory
        for (int i = 0; i <= row; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
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
    lcs.lcs(x, y,A,B);

    delete[] A;
    delete[] B;
    cout<<endl;
    return 0;
}
