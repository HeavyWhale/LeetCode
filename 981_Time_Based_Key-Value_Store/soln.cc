#include "../utils.h"

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].emplace_back(Entry{timestamp, value});
    }
    
    string get(string key, int timestamp) {
        const vector<Entry>& values = data[key];
        if (values.size() == 0) return "";
        auto sit = values.cbegin(), eit = values.cend() - 1;
        while (sit + 1 < eit) {
            const auto mit = sit + (eit - sit) / 2;
            if (mit->timestamp == timestamp) eit = mit;
            else if (mit->timestamp < timestamp) sit = mit;
            else eit = mit;
        }
        if (eit->timestamp <= timestamp) return eit->value;
        if (sit->timestamp <= timestamp) return sit->value;
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
