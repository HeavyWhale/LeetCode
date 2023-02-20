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
using std::string, std::cout, std::endl, std::stringstream, std::to_string;


template <class T>
inline void hash_combine(size_t& seed, const T& v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
};

// TODO: Use traits to generalize all repr functions on arbitrary container
// see https://stackoverflow.com/a/7728728/9438200 for more detail

// override the `to_string`
string to_string(const string& s) {
    return s;
}

template <class T>
string repr(const T& t)
{
    return to_string(t);
}

template <class T>
string repr(const vector<T>& vec)
{
    stringstream ss;
    ss << '[';
    if (vec.empty()) goto END;
    for (auto it = vec.cbegin() ;; ) {
        ss << repr(*it);
        if (++it == vec.cend()) break;
        ss << '|';
    }
END:
    ss << ']';
    return ss.str();
}

template <class T>
string repr(const vector<vector<T>>& vec)
{
    stringstream ss;
    ss << '[';
    if (vec.empty()) goto END;
    for (auto it = vec.cbegin() ;; ) {
        ss << repr(*it);
        if (++it == vec.cend()) break;
        ss << " | ";
    }
END:
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
    if (st.empty()) goto END;
    for (size_t i = 0 ;; ) {
        ss << repr(Hack::itemAt(i, st));
        if (++i == st.size()) break;
        ss << '|';
    }
END:
    ss << ')';
    return ss.str();
}

template <class T>
string repr(const queue<T>& q)
{
    stringstream ss;
    ss << '(';
    // Adapted from https://stackoverflow.com/a/12631811/9438200
    struct Hack : public queue<T> {
        static T itemAt(size_t i, const queue<T>& st) { return (st.*&Hack::c)[i]; }
    };
    if (q.empty()) goto END;
    for (size_t i = 0 ;; ) {
        ss << repr(Hack::itemAt(i, q));
        if (++i == q.size()) break;
        ss << '|';
    }
END:
    ss << ']';
    return ss.str();
}

template<class Key, class Value>
string repr(const map<Key, Value>& map)
{
    stringstream ss;
    ss << '{';
    if (map.empty()) goto END;
    ss << ' ';
    for (auto it = map.cbegin() ;; ) {
        ss << repr(it->first) << ':' << repr(it->second);
        if (++it == map.cend()) break;
        ss << " | ";
    }
    ss << ' ';
END:
    ss << '}';
    return ss.str();
}

template<class Key>
string repr(const set<Key>& set)
{
    stringstream ss;
    ss << '{';
    if (set.empty()) goto END;
    ss << ' ';
    for (auto it = set.cbegin() ;; ) {
        ss << repr(*it);
        if (++it == set.cend()) break;
        ss << " | ";
    }
    ss << ' ';
END:
    ss << '}';
    return ss.str();
}

template<class Key, class Value>
string repr(const unordered_map<Key, Value>& map)
{
    stringstream ss;
    ss << '{';
    if (map.empty()) goto END;
    ss << ' ';
    for (auto it = map.cbegin() ;; ) {
        ss << repr(it->first) << ':' << repr(it->second);
        if (++it == map.cend()) break;
        ss << " | ";
    }
    ss << ' ';
END:
    ss << '}';
    return ss.str();
}

template<class Key>
string repr(const unordered_set<Key>& set)
{
    stringstream ss;
    ss << '{';
    if (!set.empty()) {
        ss << ' ';
        for (auto it = set.cbegin() ;; ) {
            ss << repr(*it);
            if (++it == set.cend()) break;
            ss << " | ";
        }
        ss << ' ';
    }
    ss << '}';
    return ss.str();
}

// FIXME: Only works for iterators corresponding to one item (vector<int>, set<int> for example)
/*
template <class _ForwardIterator>
string repr(_ForwardIterator __first, _ForwardIterator __last)
{
    static_assert(std::__is_cpp17_forward_iterator<_ForwardIterator>::value,
        "std::max_element requires a ForwardIterator");
    stringstream ss;
    ss << '{';
    if (__first != __last) {
        ss << ' ';
        for (_ForwardIterator __i = __first ;; ) {
            ss << repr(*__i);
            if (++__i == __last) break;
            ss << '|';
        }
        ss << ' ';
    }
    ss << '}';
    return ss.str();
}
*/


template <typename T>
string arr_repr(const T* arr, const size_t size)
{
    stringstream ss;
    ss << '[';
    if (size == 0) goto END;
    for (size_t i = 0 ;; ) {
        ss << repr(arr[i]);
        if (++i == size) break;
        ss << '|';
    }
END:
    ss << ']';
    return ss.str();
}
