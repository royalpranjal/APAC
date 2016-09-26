// https://code.google.com/codejam/contest/5254487/dashboard#s=p1

#include<iostream>
#include<cmath>

using namespace std;

long long int calPow(long long int base, long long int power, long long int K){

    if(base == 0){
        return 0;
    }
    else if(power == 0){
        return 1;
    }

    long long int temp = base%K;
    long long int rem = 1;

    while(power){
        if(power%2 != 0){
            rem = (rem*temp)%K;
        }

        temp = temp*temp;
        temp = temp%K;

        power = power/2;

        if(rem >= K){
            rem = rem%K;
        }
    }

    return rem;
}

int main(){
    int test;
    cin >> test;

    int c = 1;

    while(test){
        long long int A, B, N, K;
        long long int sol = 0;
        cin >> A >> B >> N >> K;

        for(long long int i = 1; i <= N; i++){
            for(long long int j = 1; j <= N; j++){
                if(i != j){
                    long long int val = (calPow(i, A, K) + calPow(j, B, K))%K;
                    if(val == 0){
                        sol++;
                        sol = sol%1000000007;
                    }
                }
            }
        }

        cout << "Case #" << c << ": " << sol << endl;

        test--;
        c++;
    }

    return 0;
}
