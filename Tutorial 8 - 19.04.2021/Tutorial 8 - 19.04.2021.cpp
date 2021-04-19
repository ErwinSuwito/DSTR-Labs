// Tutorial Week 8 - 19.04.2021. Done on Week 9

#include <iostream>
using namespace std;

struct number {
    int row, col, input;
    number* next;
};

struct number* head = NULL;

int main()
{
    int sparseMatrix[8][8] = { {0, 0, 3, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 4, 0, 0, 0, 9, 0},
                               {0, 0, 0, 6, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0},
                               {1, 0, 4, 5, 4, 0, 0, 4},
                               {0, 0, 4, 0, 0, 0, 7, 0} };

    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++) {
            // cout << endl << r << ", " << c << " value: " << sparseMatrix[r][c];
            if (sparseMatrix[r][c] != 0) {
                struct number* newNode = (struct number*)malloc(sizeof(struct number));

                newNode->col = c;
                newNode->row = c;
                newNode->input = sparseMatrix[r][c];
                newNode->next = head;
                head = newNode;
            }
        }
    }
    

    cout << "Printing non-zeroes from the sparse matrix..." << endl;
    number* ptr;
    ptr = head;

    while (ptr != NULL) 
    {
        cout << "===============================" << endl;
        cout << endl << "Column: " << ptr->col;
        cout << endl << "Row: " << ptr->row;
        cout << endl << "Value: " << ptr->input << endl;
        ptr = ptr->next;
    }
}
