#include <bits/stdc++.h>
using namespace std;

// ==== STREAM OVERLOADS FIRST ====

// ==== pair ====
template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

// ==== vector ====
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    os << "[ ";
    for (auto &x : v) os << x << " ";
    return os << "]";
}

// ==== vector<vector<T>> ====
template<typename T>
ostream& operator<<(ostream &os, const vector<vector<T>> &v) {
    os << "[\n";
    for (auto &row : v) os << "  " << row << "\n";
    return os << "]";
}

// ==== vector<pair<T1, T2>> ====
template<typename T1, typename T2>
ostream& operator<<(ostream &os, const vector<pair<T1, T2>> &vp) {
    os << "[ ";
    for (auto &p : vp) os << p << " ";
    return os << "]";
}

// ==== set ====
template<typename T>
ostream& operator<<(ostream &os, const set<T> &s) {
    os << "{ ";
    for (auto &x : s) os << x << " ";
    return os << "}";
}

// ==== unordered_set ====
template<typename T>
ostream& operator<<(ostream &os, const unordered_set<T> &s) {
    os << "{ ";
    for (auto &x : s) os << x << " ";
    return os << "}";
}

// ==== multiset ====
template<typename T>
ostream& operator<<(ostream &os, const multiset<T> &s) {
    os << "{ ";
    for (auto &x : s) os << x << " ";
    return os << "}";
}

// ==== map ====
template<typename K, typename V>
ostream& operator<<(ostream &os, const map<K, V> &m) {
    os << "{ ";
    for (auto &x : m) os << "(" << x.first << ": " << x.second << ") ";
    return os << "}";
}

// ==== unordered_map ====
template<typename K, typename V>
ostream& operator<<(ostream &os, const unordered_map<K, V> &m) {
    os << "{ ";
    for (auto &x : m) os << "(" << x.first << ": " << x.second << ") ";
    return os << "}";
}

// ==== tuple ====
template<typename T1, typename T2, typename T3>
ostream& operator<<(ostream &os, const tuple<T1, T2, T3> &t) {
    return os << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")";
}

// ==== DEBUGGING MACRO ====
#define dbg(x...) cerr << #x << " = "; _print(x); cerr << endl;

void _print() { cerr << endl; }

template <typename T, typename... V>
void _print(T t, V... v) {
    cerr << t << " ";
    _print(v...);
}
