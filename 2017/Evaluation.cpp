// https://code.google.com/codejam/contest/6274486/dashboard#s=p2

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>

using namespace std;

string extract(string temp, int& i){
    string ans = "";

    while(i < temp.size()){
        if(temp[i] == '=' || temp[i] == ')' || temp[i] == ','){
            break;
        }
        ans = ans + temp[i];
        i++;
    }

    return ans;
}

int main(){

    int test;

    cin >> test;

    int c = 1;

    while(test){
        int num;
        cin >> num;

        int coun = num;

        map<string, vector<string> > dep;
        map<string, int> indep;

        while(num){
            string inp;
            //getline(cin, inp);
            cin >> inp;
            string key = "";

            int i = 0;

            while(i < inp.size()){
                if(i == 0){
                    key = extract(inp, i);
                    //cout << key << endl;
                    while(inp[i] != '('){
                        i++;
                    }
                    if(inp[i+1] == ')'){
                        coun--;
                        indep[key] = 1;
                        break;
                    }
                }
                else{
                    string aa = extract(inp, i);
                    dep[key].push_back(aa);
                    //cout << aa << endl;
                }
                i++;
            }
            num--;
        }



        while(coun != 0 && dep.size() != 0){
            map<string,vector<string> >::iterator it = dep.begin();

            while(it != dep.end()){
                bool check = true;

                vector<string> t = it->second;

                for(int i = 0; i < t.size(); i++){
                    if(indep.find(t[i]) == indep.end()){
                        check = false;
                        break;
                    }
                }

                if(check){
                    indep[it->first] = 1;
                    int flag = 0;
                    dep.erase(it);
                    break;
                }
                it++;
            }
            coun--;
        }

        string ans = "BAD";

        if(dep.size() == 0){
            ans = "GOOD";
        }

        cout << "Case #" << c << ": " << ans << endl;
        c++;
        test--;
    }


    return 0;
}

