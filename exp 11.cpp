#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, map<char, string>& huffmanCode)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main()
{
    string text;

    cout << "Enter the text: ";
    getline(cin, text);

    map<char, int> frequency;

    // Calculate frequency of each character
    for (char ch : text)
    {
        frequency[ch]++;
    }

    // Create priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a node for each character
    for (auto pair : frequency)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('\0', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    // Generate Huffman codes
    map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";

    for (auto pair : huffmanCode)
    {
        if (pair.first == ' ')
            cout << "Space";
        else
            cout << pair.first;

        cout << " : " << pair.second << endl;
    }

    // Encode the text
    string encodedText = "";

    for (char ch : text)
    {
        encodedText += huffmanCode[ch];
    }

    cout << "\nOriginal Text:\n";
    cout << text << endl;

    cout << "\nEncoded Text:\n";
    cout << encodedText << endl;

    return 0;
}