#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    {
        BST<char> tree;
        try {
            char s = tree.largest();
        }catch (std::out_of_range e) {
            cout << e.what() << endl;
        }

        tree.insert('d');
        tree.insert('f');
        tree.insert('b');
        tree.insert('a');
        tree.insert('c');
        tree.insert('g');
        tree.insert('e');

        cout << "The largest value is: " << tree.largest() << endl;
        cout << "The smallest value is: " << tree.smallest() << endl;
        cout << "The height of the tree is: " << tree.height('d') << endl;
        cout << "The height from node f is: " << tree.height('f') << endl;

        tree.inOrder();
        tree.remove('d');
        cout << endl;

        tree.inOrder();
        tree.remove('c');
        cout << endl;

        tree.inOrder();
        tree.remove('g');
        cout << endl;

        tree.inOrder();
        tree.remove('e');
        cout << endl;

        tree.inOrder();
        tree.remove('f');
        cout << endl;

        cout << "The largest value is: " << tree.largest() << endl;
        cout << "The smallest value is: " << tree.smallest() << endl;

        tree.inOrder();
        tree.remove('b');
        cout << endl;

        tree.inOrder();
        tree.remove('a');
        cout << endl;

        tree.inOrder();
        tree.remove('d');
        cout << endl;
     }
    {
        BST<int> tree;
        tree.insert(30);
        tree.insert(10);
        tree.insert(0);
        tree.insert(50);
        tree.insert(20);
        tree.insert(40);
        tree.insert(60);
        tree.insert(90);

        tree.inOrder();
        cout << endl;

        tree.remove(90);

        tree.inOrder();
        cout << endl;

        cout << "The largest value is: " << tree.largest() << endl;
        cout << "The smallest value is: " << tree.smallest() << endl;
    }
    return 0;
}