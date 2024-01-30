#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
    struct Node
    {
        Node *parent = this;
        Node() {}
        ~Node() {}
        Node *getParent(Node *node)
        {
            Node *currentNode = node;
            while (currentNode->parent != currentNode)
            {
                currentNode = currentNode->parent;
            }
            return currentNode;
        }
    };

public:
    int numIslands(vector<vector<char>> &grid)
    {
        // initialize node vec
        int xSize = grid[0].size();
        int ySize = grid.size();
        auto nodeMatrix = vector<vector<Node *>>(ySize);
        for (int i = 0; i < ySize; ++i)
        {
            nodeMatrix[i] = vector<Node *>(xSize);
        }

        for (int i = 0; i < ySize; ++i)
        {
            for (int j = 0; j < xSize; ++j)
            {
                if (grid[i][j] == '1')
                {
                    nodeMatrix[i][j] = new Node(); // nodes where 1, else nullptr
                }
                else
                {
                    nodeMatrix[i][j] = nullptr;
                }
            }
        } // Adds pointers to matrix

        for (int i = 0; i < ySize; ++i)
        {
            for (int j = 0; j < xSize; ++j)
            {
                if (nodeMatrix[i][j])
                {
                    vector<Node *> adjacent;
                    adjacent.push_back(i > 0 ? nodeMatrix[i - 1][j] : nullptr);         // above
                    adjacent.push_back(j + 1 < xSize ? nodeMatrix[i][j + 1] : nullptr); // to right
                    adjacent.push_back(i + 1 < ySize ? nodeMatrix[i + 1][j] : nullptr); // below
                    adjacent.push_back(j > 0 ? nodeMatrix[i][j - 1] : nullptr);         // to left
                    for (Node *ad : adjacent)
                    {
                        if (ad)
                        {
                            auto adjacentParent = ad->getParent(ad);   // retrieves parent
                            adjacentParent->parent = nodeMatrix[i][j]; // sets adjacent parent to point to self
                        }
                    }
                }
                // set their parents to currentnode parent
            }
        }

        // check all nodes' parent, and add them to set
        unordered_set<Node *> islands;
        for (auto row : nodeMatrix)
        {
            for (auto node : row)
            {
                if (node)
                {
                    islands.insert(node->getParent(node));
                }
            }
        }

        return islands.size();
        // return set.size
        // profit :)
    }
};

int main()
{
    vector<vector<char>> case1 = {
        {'1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    cout << Solution().numIslands(case1);
    return 0;
}
