#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class LFUCache {
public:
    int sz;
    int capacity;
    int minFreq;

    struct Node {
        Node* prev;
        Node* next;
        int key;
        int val;
        Node(int key, int val) : key(key), val(val), prev(NULL), next(NULL) {}
    };

    // freq -> (dummy_head, dummy_tail)
    unordered_map<int, pair<Node*, Node*>> freqList;
    // key -> (frequency, pointer to Node)
    unordered_map<int, pair<int, Node*>> keyMap;
    // freq -> count of keys with this frequency
    map<int, int> freqCount;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->sz = 0;
        this->minFreq = 0;
    }

    void insertNode(int key, int val, int freq) {
        Node* node = new Node(key, val);
        if (freqList.find(freq) == freqList.end()) {
            Node* head = new Node(0, 0);
            Node* tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            freqList[freq] = {head, tail};
        }
        Node* tail = freqList[freq].second;
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;

        keyMap[key] = {freq, node};
        freqCount[freq]++;
    }

    void removeNode(Node* node, int freq) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        freqCount[freq]--;
        if (freqCount[freq] == 0) {
            freqCount.erase(freq);
            // Clean up empty freq list
            delete freqList[freq].first;
            delete freqList[freq].second;
            freqList.erase(freq);
        }
        delete node;
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) return -1;

        int freq = keyMap[key].first;
        Node* node = keyMap[key].second;
        int val = node->val;

        // Update frequency
        removeNode(node, freq);
        insertNode(key, val, freq + 1);

        if (freq == minFreq && freqCount.find(freq) == freqCount.end()) {
            minFreq++;
        }

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyMap.find(key) != keyMap.end()) {
            // Update value and frequency
            int freq = keyMap[key].first;
            Node* node = keyMap[key].second;
            removeNode(node, freq);
            insertNode(key, value, freq + 1);
            if (freq == minFreq && freqCount.find(freq) == freqCount.end()) {
                minFreq++;
            }
        } else {
            if (sz == capacity) {
                // Evict LRU from minFreq list
                Node* lru = freqList[minFreq].first->next;
                int delKey = lru->key;
                removeNode(lru, minFreq);
                keyMap.erase(delKey);
                sz--;
            }
            insertNode(key, value, 1);
            minFreq = 1;
            sz++;
        }
    }
};
