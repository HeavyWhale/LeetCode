#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stack>
#include <queue>

#include <algorithm>        // swap, max, min, transform, sort, max_element, min_element, for_each

#include <string>
#include <iostream>
#include <functional>       // function
#include <sstream>
#include <iomanip>          // setw, set_fill

#include <climits>          // INT_MAX, INT_MIN

#include <__iterator/iterator_traits.h>

// containers
using std::vector, std::unordered_map, std::unordered_set, std::stack, 
    std::queue, std::pair, std::tuple, std::map, std::set;
// functions
using std::swap, std::max, std::min, std::function, std::apply, std::stoi,
    std::make_pair, std::transform, std::sort, std::back_inserter,
    std::min_element, std::max_element, std::for_each;
// io-related
using std::string, std::cout, std::endl, std::stringstream, std::to_string,
    std::ostringstream, std::setw, std::setfill;

#define DEBUG(...) cout << NAMED_REPR(__VA_ARGS__) << '\n'

// This is MAGIC. Completely out of mind!
// From https://stackoverflow.com/a/64215959/9438200
#define NAMED_REPR(...) named_repr_of_vars(#__VA_ARGS__,__VA_ARGS__)

// TODO: Use traits to generalize all repr functions' application on arbitrary container
// see https://stackoverflow.com/a/7728728/9438200 for more detail

// override `to_string`
inline string to_string(const string& str) {
    return str;
}

inline string to_string(const bool& boolean) {
    return boolean ? "true" : "false";
}

template <class T>
inline string repr(const T& t)
{
    return to_string(t);
}

template <class T>
string repr(const vector<T>& vec)
{
    ostringstream oss;
    oss << '[';
    if (!vec.empty()) {
        for (auto it = vec.cbegin() ;; ) {
            oss << repr(*it);
            if (++it == vec.cend()) break;
            oss << '|';
        }
    }
    oss << ']';
    return oss.str();
}

template <class T>
string repr(const vector<vector<T>>& vec)
{
    ostringstream oss;
    oss << '[';
    if (!vec.empty()) {
        for (auto it = vec.cbegin() ;; ) {
            oss << repr(*it);
            if (++it == vec.cend()) break;
            oss << " | ";
        }
    }
    oss << ']';
    return oss.str();
}

template <class T>
string repr(const stack<T>& st)
{
    ostringstream oss;
    oss << '[';
    // Adapted from https://stackoverflow.com/a/12631811/9438200
    struct Hack : public stack<T> {
        static T itemAt(size_t i, const stack<T>& st) { return (st.*&Hack::c)[i]; }
    };
    if (!st.empty()) {
        for (size_t i = 0 ;; ) {
            oss << repr(Hack::itemAt(i, st));
            if (++i == st.size()) break;
            oss << '|';
        }
    }
    oss << ')';
    return oss.str();
}

template <class T>
string repr(const queue<T>& que)
{
    ostringstream oss;
    oss << '(';
    // Adapted from https://stackoverflow.com/a/12631811/9438200
    struct Hack : public queue<T> {
        static T itemAt(size_t i, const queue<T>& st) { return (st.*&Hack::c)[i]; }
    };
    if (!que.empty()) {
        for (size_t i = 0 ;; ) {
            oss << repr(Hack::itemAt(i, que));
            if (++i == que.size()) break;
            oss << '|';
        }
    }
    oss << ']';
    return oss.str();
}

template<class Key, class Value>
string repr(const map<Key, Value>& map)
{
    ostringstream oss;
    oss << '{';
    if (!map.empty()) {
        oss << ' ';
        for (auto it = map.cbegin() ;; ) {
            oss << repr(it->first) << ':' << repr(it->second);
            if (++it == map.cend()) break;
            oss << " | ";
        }
        oss << ' ';
    }
    oss << '}';
    return oss.str();
}

template<class Key>
string repr(const set<Key>& set)
{
    ostringstream oss;
    oss << '{';
    if (!set.empty()) {
        oss << ' ';
        for (auto it = set.cbegin() ;; ) {
            oss << repr(*it);
            if (++it == set.cend()) break;
            oss << " | ";
        }
        oss << ' ';
    }
    oss << '}';
    return oss.str();
}

template<class Key, class Value>
string repr(const unordered_map<Key, Value>& map)
{
    ostringstream oss;
    oss << '{';
    if (!map.empty()) {
        oss << ' ';
        for (auto it = map.cbegin() ;; ) {
            oss << repr(it->first) << ':' << repr(it->second);
            if (++it == map.cend()) break;
            oss << " | ";
        }
        oss << ' ';
    }
    oss << '}';
    return oss.str();
}

template<class Key>
string repr(const unordered_set<Key>& set)
{
    ostringstream oss;
    oss << '{';
    if (!set.empty()) {
        oss << ' ';
        for (auto it = set.cbegin() ;; ) {
            oss << repr(*it);
            if (++it == set.cend()) break;
            oss << " | ";
        }
        oss << ' ';
    }
    oss << '}';
    return oss.str();
}

// FIXME: Only works for iterators corresponding to one item (vector<int>, set<int> for example)
/*
template <class _ForwardIterator>
string repr(_ForwardIterator __first, _ForwardIterator __last)
{
    static_aossert(std::__is_cpp17_forward_iterator<_ForwardIterator>::value,
        "std::max_element requires a ForwardIterator");
    ostringstream oss;
    oss << '{';
    if (__first != __last) {
        oss << ' ';
        for (_ForwardIterator __i = __first ;; ) {
            oss << repr(*__i);
            if (++__i == __last) break;
            oss << '|';
        }
        oss << ' ';
    }
    oss << '}';
    return oss.str();
}
*/


template <typename T>
string arr_repr(const T* arr, const size_t size)
{
    ostringstream oss;
    oss << '[';
    if (size != 0) {
        for (size_t i = 0 ;; ) {
            oss << repr(arr[i]);
            if (++i == size) break;
            oss << '|';
        }
    }
    oss << ']';
    return oss.str();
}

// This is MAGIC. Completely out of mind!
// From https://stackoverflow.com/a/64215959/9438200
// Search Keyword: cpp print variables and their names
template <class T, class... Args>
string named_repr_of_vars(const char* names, T&& var, Args&&... args) {
    ostringstream oss;

    // find variable name end
    const char* end = names;
    while (*end != ',' && *end != '\0') ++end;

    // display one variable
    oss.write(names, end - names) << " = " << repr(var) << ',';

    // continue parsing?
    if constexpr(sizeof...(Args) > 0) {
        // recursively call named_repr_of_vars() with the new beginning for names
        oss << named_repr_of_vars(end + 1, std::forward<Args>(args)...);
    } else {
        string ret = oss.str();
        ret.pop_back();
        return ret;
    }

    return oss.str();
}

// return the `str` but all characters are replaced by space (' ')
string phantom(const string& str) {
    ostringstream oss;
    for (int i = 0; i < str.size(); ++i) oss << ' ';
    return oss.str();
}
