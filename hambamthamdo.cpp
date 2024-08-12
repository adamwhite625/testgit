#include <iostream>
using namespace std;

#define M 11
#define EMPTY -1
#define DELETED -2

int hashTable[M];

void init() {
    for(int i = 0; i < M; i++) {
        hashTable[i] = EMPTY;
    }
}

int hash(int k) {
    return k % M;
}

void insert(int k) {
    int index = hash(k);
    for (int i = 0; i < M; i++) {
        int tryIndex = (index + i) % M;
        if (hashTable[tryIndex] == EMPTY || hashTable[tryIndex] == DELETED) {
            hashTable[tryIndex] = k;
            return;
        }
    }
    cout << "Hash table is full, cannot insert key " << k << endl;
}

int search(int k) {
    int index = hash(k);
    for (int i = 0; i < M; i++) {
        int tryIndex = (index + i) % M;
        if (hashTable[tryIndex] == EMPTY) {
            return -1; // Không tìm thấy
        }
        if (hashTable[tryIndex] == k) {
            return tryIndex; // Tìm thấy khóa
        }
    }
    return -1; // Không tìm thấy
}

int delKey(int k) {
    int index = search(k);
    if (index == -1) {
        return 0; // Không tìm thấy khóa
    }
    hashTable[index] = DELETED;
    return 1; // Xóa thành công
}

void outputHashTable() {
    for (int i = 0; i < M; i++) {
        if (hashTable[i] == EMPTY) {
            cout << "EMPTY ";
        } else if (hashTable[i] == DELETED) {
            cout << "DELETED ";
        } else {
            cout << hashTable[i] << " ";
        }
