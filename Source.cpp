#include <iostream>
using namespace std;


#define ALPHABET_SIZE (26)


#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];

    bool isWordEnd;
};

struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;
    pNode->isWordEnd = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode* root, const string key)
{
    struct TrieNode* pCrawl = root;

    for (int level = 0; level < key.length(); level++) {
        int index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isWordEnd = true;
}

bool isLastNode(struct TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}

void suggestionsRec(struct TrieNode* root,
    string currPrefix)
{

    if (root->isWordEnd)
        cout << currPrefix << endl;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            char child = 'a' + i;
            suggestionsRec(root->children[i],
                currPrefix + child);
        }
}


int printAutoSuggestions(TrieNode* root, const string query)
{
    struct TrieNode* pCrawl = root;
    for (char c : query) {
        int ind = CHAR_TO_INDEX(c);

      
        if (!pCrawl->children[ind])
            return 0;

        pCrawl = pCrawl->children[ind];
    }
   
    if (isLastNode(pCrawl)) {
        cout << query << endl;
        return -1;
    }
    suggestionsRec(pCrawl, query);
    return 1;
}


int main()
{
    struct TrieNode* root = getNode();
    string keyword;
    int o = 0;

    insert(root, "ace");
    insert(root, "apple");
    insert(root, "brain");
    insert(root, "ball");
    insert(root, "can");
    insert(root, "call");
    insert(root, "day");
    insert(root, "done");
    insert(root, "exit");
    insert(root, "entry");
    insert(root, "fire");
    insert(root, "fly");
    insert(root, "goblin");
    insert(root, "gone");
    insert(root, "hello");
    insert(root, "hint");
    insert(root, "intro");
    insert(root, "idea");
    insert(root, "jazz");
    insert(root, "joke");
    insert(root, "know");
    insert(root, "keyboard");
    insert(root, "line");
    insert(root, "linear");
    insert(root, "might");
    insert(root, "magic");
    insert(root, "nice");
    insert(root, "name");
    insert(root, "orange");
    insert(root, "onion");
    insert(root, "potato");
    insert(root, "patty");
    insert(root, "quality");
    insert(root, "quartz");
    insert(root, "road");
    insert(root, "rage");
    insert(root, "supermassive");
    insert(root, "sword");
    insert(root, "traitorous");
    insert(root, "teammate");
    insert(root, "unacceptable");
    insert(root, "username");
    insert(root, "vendor");
    insert(root, "valley");
    insert(root, "wicked");
    insert(root, "wizard");
    insert(root, "xenophobic");
    insert(root, "xylophonist");
    insert(root, "young");
    insert(root, "yordle");
    insert(root, "zebra");
    insert(root, "zombie");

    do 
    {
        cin >> keyword;

        int comp = printAutoSuggestions(root, keyword);
    } while (o == 0);


    return 0;
}