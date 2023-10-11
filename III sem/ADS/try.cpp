#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define MAX_LEVEL 6
const float P = 0.5;

using namespace std;

struct snode {
    int value;
    snode **forw;

    snode(int level, int value) {
        forw = new snode *[level + 1];
        memset(forw, 0, sizeof(snode *) * (level + 1));
        this->value = value;
    }

    ~snode() {
        delete[] forw;
    }
};

struct skiplist {
    snode *header;
    int level;

    skiplist() {
        header = new snode(MAX_LEVEL, INT_MIN);
        level = 0;
    }

    ~skiplist() {
        snode *x = header->forw[0];
        while (x) {
            snode *next = x->forw[0];
            delete x;
            x = next;
        }
        delete header;
    }

    void display();
    bool contains(int);
    void insert_element(int);
    void delete_element(int);
};

int random_level() {
    static bool first = true;
    if (first) {
        srand((unsigned) time(NULL));
        first = false;
    }
    int lvl = (int)(log(frand()) / log(1. - P));
    return lvl < MAX_LEVEL ? lvl : MAX_LEVEL;
}

void skiplist::display() {
    snode *x = header->forw[0];
    while (x) {
        cout << x->value;
        x = x->forw[0];
        if (x)
            cout << " - ";
    }
    cout << endl;
}

bool skiplist::contains(int s_value) {
    snode *x = header;
    for (int i = level; i >= 0; i--) {
        while (x->forw[i] && x->forw[i]->value < s_value) {
            x = x->forw[i];
        }
    }
    x = x->forw[0];
    return x && x->value == s_value;
}

void skiplist::insert_element(int value) {
    snode *x = header;
    snode *update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(snode *) * (MAX_LEVEL + 1));
    for (int i = level; i >= 0; i--) {
        while (x->forw[i] && x->forw[i]->value < value) {
            x = x->forw[i];
        }
        update[i] = x;
    }
    x = x->forw[0];
    if (!x || x->value != value) {
        int lvl = random_level();
        if (lvl > level) {
            for (int i = level + 1; i <= lvl; i++) {
                update[i] = header;
            }
            level = lvl;
        }
        x = new snode(lvl, value);
        for (int i = 0; i <= lvl; i++) {
            x->forw[i] = update[i]->forw[i];
            update[i]->forw[i] = x;
        }
    }
}

void skiplist::delete_element(int value) {
    snode *x = header;
    snode *update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(snode *) * (MAX_LEVEL + 1));
    for (int i = level; i >= 0; i--) {
        while (x->forw[i] && x->forw[i]->value < value) {
            x = x->forw[i];
        }
        update[i] = x;
    }
    x = x->forw[0];
    if (x && x->value == value) {
        for (int i = 0; i <= level; i++) {
            if (update[i]->forw[i] != x)
                break;
            update[i]->forw[i] = x->forw[i];
        }
        delete x;
        while (level > 0 && !header->forw[level]) {
            level--;
        }
    }
}

int main() {
    skiplist ss;
    int choice, n;

    while (true) {
        cout << "\nOperations on Skip List\n\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> n;
                ss.insert_element(n);
                if (ss.contains(n))
                    cout << "Element Inserted" << endl;
                break;
            case 2:
                cout << "Enter the element to be deleted: ";
                cin >> n;
                if (!ss.contains(n)) {
                    cout << "Element not found" << endl;
                    break;
                }
                ss.delete_element(n);
                if (!ss.contains(n))
                    cout << "Element Deleted" << endl;
                break;
            case 3:
                cout << "Enter the element to be searched: ";
               
