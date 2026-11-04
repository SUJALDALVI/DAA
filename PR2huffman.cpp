
#include <iostream>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node* createNode(char ch, int freq) {
    Node* temp = new Node;
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

void sortNodes(Node* a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i]->freq > a[j]->freq)
                swap(a[i], a[j]);
        }
    }
}

void printCodes(Node* root, string code) {
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    Node* a[100];
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        char ch;
        int freq;

        cout << "Enter character and frequency: ";
        cin >> ch >> freq;

        a[i] = createNode(ch, freq);
    }

    while(n > 1) {
        sortNodes(a, n);

        Node* left = a[0];
        Node* right = a[1];

        Node* parent = createNode('$',
            left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        for(int i = 2; i < n; i++)
            a[i-2] = a[i];

        a[n-2] = parent;
        n--;
    }

    cout << "\nHuffman Codes:\n";
    printCodes(a[0], "");

    return 0;
}

/*
====================== THEORY ======================

Huffman Coding is a lossless data compression algorithm.
It assigns variable-length binary codes to characters
according to their frequencies.

Characters with higher frequencies get shorter codes,
while characters with lower frequencies get longer codes.

Huffman Coding generates Prefix Codes, which means
no code is the prefix of another code.

Example:
A = 0
B = 10
C = 110
D = 111

1. GREEDY APPROACH:

1. Create a node for each character and frequency.
2. Sort nodes in ascending order of frequency.
3. Select the two smallest frequency nodes.
4. Create a parent node with their frequency sum.
5. Connect both nodes to the parent.
6. Insert the parent back into the array.
7. Repeat until only one node remains.
8. Assign 0 to the left branch and 1 to the right.
9. Print the Huffman codes.

2. TIME COMPLEXITY:

For this array-based implementation:
O(n^3)

3. SPACE COMPLEXITY:

O(n)

4. APPLICATIONS:

1. Text file compression.
2. ZIP and GZIP compression formats.
3. Multimedia compression techniques.

5. ALGORITHM:

Step 1: Start.
Step 2: Enter characters and frequencies.
Step 3: Create nodes and store them in an array.
Step 4: Sort nodes by frequency.
Step 5: Select two minimum-frequency nodes.
Step 6: Create a parent node with their sum.
Step 7: Insert the parent into the array.
Step 8: Repeat until one node remains.
Step 9: Generate Huffman codes using recursion.
Step 10: Print codes and stop.

6. FLOWCHART:

             +-----------+
             |   START   |
             +-----------+
                   |
                   v
          +------------------+
          | Enter Characters |
          | and Frequencies  |
          +------------------+
                   |
                   v
          +------------------+
          | Create Nodes     |
          +------------------+
                   |
                   v
          +------------------+
          | Sort by Frequency|
          +------------------+
                   |
                   v
             +-----------+
             |   n > 1?  |
             +-----------+
               /       \
             YES        NO
              |          |
              v          v
        +-----------+  +-------------+
        | Select Two|  | Root Node   |
        | Smallest  |  | Generated   |
        +-----------+  +-------------+
              |          |
              v          v
        +-----------+  +-------------+
        | Create    |  | Generate    |
        | Parent    |  | Huffman     |
        +-----------+  | Codes       |
              |        +-------------+
              v              |
        +-----------+        v
        | Insert    |  +-------------+
        | Parent    |  | Print Codes|
        +-----------+  +-------------+
              |              |
              v              v
        +-----------+  +-------------+
        | Decrease n|  |    STOP     |
        +-----------+  +-------------+
              |
              +----> Back to Sort

7. CONCLUSION:

We successfully implemented Huffman Encoding using
a Greedy Strategy. It generates variable-length
prefix codes based on character frequencies and
is used for lossless data compression.

g++ PR1NONFIBO.cpp -o PR1NONFIBO
.\PR1NONFIBO.exe
==================================================
*/
