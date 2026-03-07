// given two positive integers x and n
// say x = 2, n = 5
// return pow(2, 5) which is 2^5 = 32

// brute: ans  = 1
// for i from 1 till N, ans = ans multiplied by x

// optimal:
// say x = 2, n = 21
// so 2^21
// keep ans = 1;
// check if n is even. no. 
// then write it as 2^21 = 2 x 2^20
// now calculate 2^20. but first, since we took out 2, add it to the ans. so ans = 1 x 2
// and now n = 20
// is n even. yes
// write 2^20 = (2^2)^20/2
// which is 4^10
// which is x = 4, n = 10
// which is nothing but 16^5
// x  = 16, n = 5
// since now n is odd, take out one 16 and add to the answer, so ans = 1 x 2 x 16
// and n = 4
// 16^4  = 256 ^ 2
// now x = 256, n = 2
// which is 65536^1
// now x = 65536 and n = 1
// since n is odd, add it to the answer
// ans = 1 x 2 x 16 x 65536
// n becomes 0 and stop

func(x, n){
    ans = 1;
    while(n > 0){
        if(n % 2 == 1){
            ans = ans x x;
            n = n - 1;
        }
        else{
            n = n / 2;
            x = x x x;
        }
    }

    return ans;
}

// TC: approx log(N) base 2