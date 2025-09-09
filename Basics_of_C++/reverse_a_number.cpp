while(x > 0){
            long long digit = x % 10;
            reverse = (reverse * 10) + digit;
            x = x / 10;
        }