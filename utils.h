#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

#include <algorithm>

#include <string>
#include <iostream>
#include <functional>
#include <sstream>
#include <iomanip>

#include <climits>

// containers
using std::vector, std::unordered_map, std::unordered_set, std::stack, 
    std::queue, std::pair, std::tuple;
// functions
using std::swap, std::max, std::min, std::function, std::apply, std::stoi,
    std::make_pair, std::transform, std::sort, std::back_inserter,
    std::min_element, std::max_element;
// io-related
using std::string, std::cout, std::endl, std::stringstream, std::to_string;


template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
};

template <class T>
string repr(const vector<T>& vec)
{
    stringstream ss;
    ss << '[';
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << to_string(vec[i]);
        if (i < vec.size() - 1) ss << '|';
    }
    ss << ']';
    return ss.str();
}

template <class T>
string repr(const stack<T>& st)
{
    stringstream ss;
    ss << '[';
    // Adapted from https://stackoverflow.com/a/12631811/9438200
    struct Hack : public stack<T> {
        static T itemAt(size_t i, const stack<T>& st) { return (st.*&Hack::c)[i]; }
    };
    
    for (size_t i = 0; i < st.size(); ++i) {
        ss << to_string(Hack::itemAt(i, st));
        if (i < st.size() - 1) ss << '|';
    }
    ss << ')';
    return ss.str();
}

template <class T>
string repr(const queue<T>& st)
{
    stringstream ss;
    ss << '(';
    // Adapted from https://stackoverflow.com/a/12631811/9438200
    struct Hack : public queue<T> {
        static T itemAt(size_t i, const queue<T>& st) { return (st.*&Hack::c)[i]; }
    };
    
    for (size_t i = 0; i < st.size(); ++i) {
        ss << to_string(Hack::itemAt(i, st));
        if (i < st.size() - 1) ss << '|';
    }
    ss << ']';
    return ss.str();
}

string repr(const vector<string>& vec)
{
    stringstream ss;
    ss << '[';
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i < vec.size() - 1) ss << '|';
    }
    ss << ']';
    return ss.str();
}

string repr(const vector<char>& vec)
{
    stringstream ss;
    ss << '[';
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i < vec.size() - 1) ss << '|';
    }
    ss << ']';
    return ss.str();
}

template <typename T>
string arr_repr(const T* arr, const size_t size)
{
    stringstream ss;
    ss << '[';
    for (size_t i = 0; i < size; ++i) {
        ss << to_string(arr[i]);
        if (i < size - 1) ss << '|';
    }
    ss << ']';
    return ss.str();
}
