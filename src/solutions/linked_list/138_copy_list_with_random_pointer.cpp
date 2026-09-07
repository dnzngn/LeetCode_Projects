/*
 * LeetCode #138 - Copy List with Random Pointer
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Medium
*/

#include <iostream>
#include <unordered_set>
#include <vector>



#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
// Definition for singly-linked list.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapping;   // orijinal adres → kopya adres

        // Faz 1: butun dugumleri yarat, hicbir pointer baglama
        for (Node* p = head; p; p = p->next)
            mapping[p] = new Node(p->val);

        // Faz 2: pointer'lari bagla
        for (Node* p = head; p; p = p->next) {
            mapping[p]->next   = mapping[p->next];
            mapping[p]->random = mapping[p->random];
        }

        return mapping[head];
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p138 {

// ---------- yardimcilar ----------

// [val, random_index] listesinden graph kurar. random_index < 0 → nullptr
Node* build(const vector<pair<int,int>>& spec) {
    if (spec.empty()) return nullptr;

    vector<Node*> nodes;
    nodes.reserve(spec.size());
    for (const auto& s : spec) nodes.push_back(new Node(s.first));

    for (size_t i = 0; i + 1 < nodes.size(); ++i)
        nodes[i]->next = nodes[i + 1];

    for (size_t i = 0; i < nodes.size(); ++i) {
        int idx = spec[i].second;
        nodes[i]->random = (idx < 0) ? nullptr : nodes[idx];
    }
    return nodes[0];
}

// [val,random_index] formatinda basar — random'lari da gorunur kilar
void print(Node* head) {
    unordered_map<Node*, int> index;
    int i = 0;
    for (Node* p = head; p; p = p->next) index[p] = i++;

    cout << "[";
    for (Node* p = head; p; p = p->next) {
        cout << "[" << p->val << ",";
        if (!p->random) {
            cout << "null";
        } else {
            auto it = index.find(p->random);          // operator[] DEGIL:
            if (it != index.end()) cout << it->second; // yabanci dugumu 0 diye
            else                   cout << "FOREIGN";  // gizlemesin
        }
        cout << "]";
        if (p->next) cout << ",";
    }
    cout << "]";
}

bool validate(Node* orig, Node* copy) {
    vector<Node*> o, c;
    for (Node* p = orig; p; p = p->next) o.push_back(p);
    // cycle olusturulduysa sonsuz donguye girmeyelim
    for (Node* p = copy; p && c.size() <= o.size() + 1; p = p->next) c.push_back(p);

    if (c.size() != o.size()) {
        cout << "    FAIL: uzunluk " << c.size() << " != " << o.size()
             << " (cycle olabilir)\n";
        return false;
    }

    unordered_set<Node*> origSet(o.begin(), o.end());
    unordered_map<Node*, int> oIdx, cIdx;
    for (size_t i = 0; i < o.size(); ++i) oIdx[o[i]] = static_cast<int>(i);
    for (size_t i = 0; i < c.size(); ++i) cIdx[c[i]] = static_cast<int>(i);

    for (size_t i = 0; i < o.size(); ++i) {
        if (o[i]->val != c[i]->val) {
            cout << "    FAIL: val uyusmazligi @" << i << "\n"; return false;
        }
        if (origSet.count(c[i])) {
            cout << "    FAIL: kopya, orijinal dugumu paylasiyor @" << i << "\n"; return false;
        }

        Node* orand = o[i]->random;
        Node* crand = c[i]->random;

        if ((orand == nullptr) != (crand == nullptr)) {
            cout << "    FAIL: random null uyusmazligi @" << i << "\n"; return false;
        }
        if (orand) {
            if (origSet.count(crand)) {
                cout << "    FAIL: random ORIJINALE bakiyor @" << i << "\n"; return false;
            }
            auto it = cIdx.find(crand);
            if (it == cIdx.end()) {
                cout << "    FAIL: random listeye ait olmayan dugum @" << i << "\n"; return false;
            }
            if (it->second != oIdx[orand]) {
                cout << "    FAIL: random hedefi yanlis @" << i
                     << " (beklenen " << oIdx[orand] << ", gelen " << it->second << ")\n";
                return false;
            }
        }
    }
    return true;
}

void freeList(Node* head) {
    while (head) { Node* nx = head->next; delete head; head = nx; }
}

void run(const string& name, const vector<pair<int,int>>& spec) {
    Node* orig = build(spec);

    Solution sol;
    Node* copy = sol.copyRandomList(orig);

    cout << "  " << name << "\n";
    cout << "    input : "; print(orig); cout << "\n";
    cout << "    output: "; print(copy); cout << "\n";
    cout << (validate(orig, copy) ? "    PASS\n" : "    FAIL\n");

    freeList(orig);
    freeList(copy);
}

// ---------- testler ----------

void test() {
    run("T1 ileri bakan random (LC ornegi)", {{7,-1},{13,0},{11,4},{10,2},{1,0}});
    run("T2 karsilikli random",              {{1,1},{2,1}});
    run("T3 tum random null",                {{3,-1},{3,0},{3,-1}});
    run("T4 bos liste",                      {});
    run("T5 tek dugum, self-loop",           {{1,0}});
    run("T6 tek dugum, null random",         {{1,-1}});
    run("T7 hepsi ayni hedefe",              {{5,2},{6,2},{7,2},{8,2}});
    run("T8 tamami geriye",                  {{1,-1},{2,0},{3,1},{4,2}});
    run("T9 tamami ileriye",                 {{1,3},{2,3},{3,3},{4,-1}});

    cout << "================================================\n";
}


REGISTER_PROBLEM(138, "Copy List with Random Pointer")
} // namespace p138

