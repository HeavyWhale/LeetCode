#include "prac1.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    TimeMap timeMap = TimeMap();
    timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    DEBUG(timeMap.get("foo", 1));         // return "bar"
    DEBUG(timeMap.get("foo", 3));         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    DEBUG(timeMap.get("foo", 4));         // return "bar2"
    DEBUG(timeMap.get("foo", 5));         // return "bar2"
    return 0;
}
