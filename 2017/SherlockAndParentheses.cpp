// https://code.google.com/codejam/contest/5254487/dashboard

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){

    int testCases;
    cin >> testCases;

    int caseCount = 1;

    while(testCases){
        int left, right;
        cin >> left >> right;

        int n = min(left, right);

        long long int ans = 0;

        if(left == 0 && right == 0){
            ans = 1;
        }
        else{
            for(int i = n; i > 0; i--){
                ans = ans + i;
            }
        }

        cout << "Case #" << caseCount << ": " << ans << endl;
        caseCount++;
        testCases--;
    }

    return 0;
}
