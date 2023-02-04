#include "../utils.h"

int gen_int(int start, int end) {
    return start + (rand() % static_cast<int>(end - start + 1));
}

void test(unordered_map<int, int>& map, int times = 100000) {
    bool visited[10000] = {0};
    cout << "BEGIN...\n";
    for (int i = 0; i < times; ++i) {
        int n = gen_int(0, 10000);
        // cout << "Iter " << i << ": Generated int i = " << n << ", try inserting into map ..." << '\n';
        if (!visited[n]) {
            // cout << ">>> NEW <<< \n";
            map[n] += 1;
            assert(map[n] == 1);
            visited[n] = true;
        }
        // cout << "The allocated map[i] = " << (map[n]++) << '\n';
        // cout << "Then map[i] = " << map[n] << '\n' << '\n';
    } // for
    cout << "END\n"; 
}

int main() {
    unordered_map<int, int> map;
    test(map);
}
