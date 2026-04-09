using ll = long long;
class Solution {
public:
    int tribonacci(int n) {
        ll a = 0, b = 1, c = 1;

        int i = 3;
        while(i <= n) {
            int d = a + b + c;
            a = b;
            b = c;
            c = d;
            i++;
        }

        return n > 0 ? c : 0;
    }
};