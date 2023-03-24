#include "../utils.h"

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].emplace_back(Entry{timestamp, value});
    }
    
    string get(string key, int timestamp) {
        const auto& values = data[key];
        if (values.empty()) return "";
        auto lit = values.cbegin(), rit = values.cend();
        while (lit + 1 < rit) {
            const auto mit = lit + (rit - lit) / 2;
            if (mit->timestamp == timestamp) rit = mit;
            else if (mit->timestamp > timestamp) rit = mit;
            else lit = mit;
        }
        if (rit->timestamp <= timestamp) return rit->value;
        if (lit->timestamp <= timestamp) return lit->value;
        return "";
    }

private:
    struct Entry {
        int timestamp;
        string value;
    };
    unordered_map<string, vector<Entry>> data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
