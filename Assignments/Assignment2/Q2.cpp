#include <iostream>
using namespace std;

struct node
{
    int r, c, v; // row, column, and value
};

struct sparse
{
private:
    int nrow, ncol, nz; // number of rows, columns, and non-zero elements
    node *mat;

public:
    sparse() : nrow(0), ncol(0), nz(0), mat(nullptr) {}

    sparse(int nr, int nc, int z)
    {
        nrow = nr;
        ncol = nc;
        nz = z;
        mat = new node[nz];
    }

    void insert_data()
    {
        cout << "Enter row, column and value of each non-zero element:" << endl;
        for (int i = 0; i < nz; i++)
        {
            cin >> mat[i].r >> mat[i].c >> mat[i].v;
        }
    }

    int find(int i, int j) const
    {
        for (int k = 0; k < nz; k++)
        {
            if (mat[k].r == i && mat[k].c == j)
                return mat[k].v;
        }
        return 0;
    }

    void print() const
    {
        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol; j++)
            {
                cout << find(i, j) << " ";
            }
            cout << endl;
        }
    }

    // Addition of two sparse matrices
    void add_mat(const sparse &m1, const sparse &m2)
    {
        if (m1.nrow != m2.nrow || m1.ncol != m2.ncol)
        {
            cout << "Matrix sizes do not match for addition." << endl;
            return;
        }

        nrow = m1.nrow;
        ncol = m1.ncol;

        // Maximum possible non-zero count = sum of nz's of both matrices
        mat = new node[m1.nz + m2.nz];
        int k = 0;

        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol; j++)
            {
                int temp = m1.find(i, j) + m2.find(i, j);
                if (temp != 0)
                {
                    mat[k].r = i;
                    mat[k].c = j;
                    mat[k].v = temp;
                    k++;
                }
            }
        }
        nz = k;
    }

    // Addition of sparse matrix with normal matrix
    // normal is 2D array with size rows x cols
    void add_with_normal(const sparse &m1, int normal[][10], int rows, int cols)
    {
        if (m1.nrow != rows || m1.ncol != cols)
        {
            cout << "Matrix sizes do not match for addition." << endl;
            return;
        }

        nrow = m1.nrow;
        ncol = m1.ncol;

        mat = new node[nrow * ncol]; // worst case all elements non-zero
        int k = 0;

        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol; j++)
            {
                int temp = m1.find(i, j) + normal[i][j];
                if (temp != 0)
                {
                    mat[k].r = i;
                    mat[k].c = j;
                    mat[k].v = temp;
                    k++;
                }
            }
        }
        nz = k;
    }

    ~sparse()
    {
        delete[] mat;
    }
};

int main()
{
    sparse m1(3, 3, 3);
    sparse m2(3, 3, 2);
    sparse m3, m4;

    m1.insert_data();
    cout << "\nSparse Matrix 1:" << endl;
    m1.print();

    m2.insert_data();
    cout << "\nSparse Matrix 2:" << endl;
    m2.print();

    m3.add_mat(m1, m2);
    cout << "\nAddition of two sparse matrices:" << endl;
    m3.print();

    // Normal matrix (3x3)
    int normal[10][10] = {
        {1, 0, 2},
        {0, 3, 0},
        {4, 0, 5}};

    cout << "\nNormal Matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << normal[i][j] << " ";
        }
        cout << endl;
    }

    m4.add_with_normal(m1, normal, 3, 3);
    cout << "\nAddition of sparse + normal matrix:" << endl;
    m4.print();

    return 0;
}
