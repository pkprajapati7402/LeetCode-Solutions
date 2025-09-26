#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Huffman Tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Compare function for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // smallest freq has higher priority
    }
};

// Print Huffman Codes recursively
void printCodes(Node* root, string code) {
    if (!root) return;

    // Leaf node → print the character and its code
    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char ch;
    int freq;
    unordered_map<char, int> freqMap;

    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch >> freq;
        freqMap[ch] = freq;
    }

    // Min-heap for building Huffman Tree
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes
    for (auto pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Internal node with combined frequency
        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}
