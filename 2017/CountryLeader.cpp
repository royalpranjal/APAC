// https://code.google.com/codejam/contest/11274486/dashboard#s=p0

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    string soFarMax = "";
    string overallMax = "";
    int soFar = 0;
    int overall = 0;
    int totOv = 0;
    int totSo = 0;
    int Tcase = 0;
    int T;

    cin >> T;

    while(T > 0){
        overall = 0;
        totOv = 0;
        overallMax = "";
        int N;
        cin >> N;
        vector<int> ov(26, 0);
        while(N >= 0){
            vector<int> so(26, 0);
            soFarMax = "";
            soFar = 0;
            totSo = 0;
            //cin >> soFarMax;
            getline(cin, soFarMax);

            for(int i = 0; i < soFarMax.size(); i++){
                char c = soFarMax[i];
                int num = c;
                if(num >= 65 && num <= 90){
                    if(so[abs(65-num)] == 0){
                        soFar++;
                        so[abs(65-num)] = 1;
                    }
                    totSo++;
                }
            }

            if(soFar > overall){
                overall = soFar;
                overallMax = soFarMax;
                ov = so;
            }
            else if(soFar == overall){
                int i = 0; // overallMax
                int j = 0; // soFarMax
                int maxi = soFarMax.size();
                if(overallMax.size() > soFarMax.size()){
                    maxi = overallMax.size();
                }

                while(i < maxi){
                    char c = overallMax[i];
                    char d = soFarMax[j];
                    int o = c;
                    int s = d;
                    if(((o <= 90) && (o >= 65)) && ((s <= 90) && (s >= 65))){
                        if(o > s){
                            overall = soFar;
                            overallMax = soFarMax;
                            ov = so;
                            totOv = totSo;
                            break;
                        }
                        else if(o == s){
                            i++;
                            j++;
                        }
                        else{
                            break;
                        }
                    }
                    if(!((o <= 90) && (o >= 65))){
                        if(i == soFarMax.size()-1){
                            if(totOv < totSo){
                                overall = soFar;
                                overallMax = soFarMax;
                                ov = so;
                                totOv = totSo;
                            }
                            else if(totOv == totSo){
                                if(overallMax.size() > soFarMax.size()){
                                    overall = soFar;
                                    overallMax = soFarMax;
                                    ov = so;
                                    totOv = totSo;
                                }
                            }
                            break;
                        }
                        i++;
                    }
                    if(!((s <= 90) && (s >= 65))){
                        if(j == soFarMax.size()-1){
                            if(totOv < totSo){
                                overall = soFar;
                                overallMax = soFarMax;
                                ov = so;
                                totOv = totSo;
                            }
                            else if(totOv == totSo){
                                if(overallMax.size() > soFarMax.size()){
                                    overall = soFar;
                                    overallMax = soFarMax;
                                    ov = so;
                                    totOv = totSo;
                                }
                            }
                            break;
                        }
                        j++;
                    }
                }
            }
            N--;
            so.erase(so.begin(), so.end());
        }
        //cout << overallMax << " : " << overall << " : " << totOv << endl;
        Tcase++;
        cout << "Case #" << Tcase << ": "<< overallMax << endl;
        T--;
        ov.erase(ov.begin(), ov.end());
    }


    return 0;
}
