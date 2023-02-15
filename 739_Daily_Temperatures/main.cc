#include "prac4.cc"

int main() {
    vector<int> 
        temp  {73,74,75,71,69,72,76,73},        
        temp1 {30,40,50,60},                    
        temp2 {30,60,90},                       
        myex  {60,44,73,85,46,41,76},           
        error {34,80,80,34,34,80,80,80,80,34};  
    Solution s {};
    cout << repr(s.dailyTemperatures(temp)) << '\n';     // [1,1,4,2,1,1,0,0]
    cout << repr(s.dailyTemperatures(temp1)) << '\n';    // [1,1,1,0]
    cout << repr(s.dailyTemperatures(temp2)) << '\n';    // [1,1,0]
    cout << repr(s.dailyTemperatures(myex)) << '\n';     // [2,1,1,0,2,1,0]
    cout << repr(s.dailyTemperatures(error)) << '\n';    // [1|0|0|2|1|0|0|0|0|0]
}
