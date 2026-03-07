// print all prime factors of a number
// given a value N, print all prime factors of it
// basically, write all the divisors, and return the prime divisors (prime numbers that divide the number)

// brute:
// find all divisors and then check which are prime
// we already know how to check prime
// take a list
// iterate from 2 to N
// if N is divided by i, and i is prime as well, then add i to the list
// TC: (N x sqrt(N))

// better:
// now again we can optimize by looping from i from 2 to sqrt(N)
// TC for this will be approx (2xN). we cannot exactly derive it as there are lot of if conditions

// optimal:
// say N is 780
// divide it by 2, until it cannot be further divided by 2. so 390 -> 195
// divide by 3 until it cannot. 195 -> 65
// now notice that we divided it by 2 till it wasnt possible, so it wont be divisible by 4
// divide by 5, 65 -> 13
// now it cannot be divided by 6
// and so on
// therefore,
// start with i = 2 till N, i++
// if(N % i == 0) list.add(i)
// then, while(n % i == 0) n = n / i; // keep on dividing it by the prime factor as many times as possible. 
// as we are reducing N also, the loop will not run till N (780), it will only run for 5-7 times

for(int i = 2; i<= N; i++){
    if(N % i == 0){
        list.add(i);
        while(n % i == 0){
            N = N / i;
        }
    }
}

// for a large number which is prime, the complexity stays at O(N) because then no number from i 2 to N-1 will divide it

// OPTIMIZATION:
// loop from i = 2 to sqrt N, and write same loop conditions
// and at the end, if N != 1, add it to the list
// TC: root N x log N