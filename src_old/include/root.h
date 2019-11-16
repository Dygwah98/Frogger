#ifndef ROOT_H
#define ROOT_H

#include<iostream>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<memory>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
using namespace std;

enum struct Event : int { nd = -1, Exit = 0, Execute = 1, Redraw = 2, Stop = 3 };
enum struct Keys : int { nd = -1, UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 };
enum struct Collision : int { nd = -1, Log = 0, Deadly = 1, Arrival = 2 };

template<class T>
inline bool in_range(T lower, T val, T upper, bool loweq = true, bool upeq = true) {
    return (loweq ? val >= lower : val > lower) and (upeq ? upper >= val : upper > val);
}

template<class K, class V>
inline bool contains(const map<K, V>& map, const K& key) {
    return map.find(key) != map.end();
}

template<class V>
inline bool contains(const vector<V>& vec, int key) {
    return in_range<int>(0, key, vec.size(), true, false);
}

#endif