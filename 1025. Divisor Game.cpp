class Solution {
public:
    bool divisorGame(int n) {
        // bool alice_win = false;
        // while (n >= 2) {                
        //     n -= 1;                     
        //     alice_win = !alice_win;
        // }
        // return alice_win;
        /* if n == 1 alice lose, n == 2 alice win.
           expand this to larger n. When n is odd, only can subtract odd num to make n even.
           optimally, leave opponent with odd num can always win.
        */
        return n % 2 == 0;
    }
};
