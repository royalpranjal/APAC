// https://code.google.com/codejam/contest/6274486/dashboard#s=p1

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int test;

    cin >> test;

    int c = 1;

    while(test){
        int rows, cols, mons;

        cin >> rows >> cols >> mons;

        vector<vector<int> > sq(rows, vector<int>(cols, 1));

        int remp = 0;

        while(remp != mons){
            int r, c;
            cin >> r >> c;

            sq[r][c] = 0;

            remp++;
        }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(sq[i][j] != 0){
                    sq[i][j] = 1 + min(sq[i-1][j], min(sq[i-1][j-1], sq[i][j-1]));
                }
            }
        }

        long long int val = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                val = val + sq[i][j];
            }
        }

        cout << "Case #" << c << ": " << val << endl;

        test--;
        c++;
    }

    return 0;
}

