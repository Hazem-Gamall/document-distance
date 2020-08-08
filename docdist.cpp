#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

int inner_product(unordered_map<string,int> d1, unordered_map<string,int> d2){
    double sum =0;
    for(auto i : d1){
        auto x = d2.find(i.first);
        if(x != d2.end()){
            sum += i.second * x->second;
        }
    }
    return sum;
}

double vector_angle(unordered_map<string,int> d1,
unordered_map<string,int> d2){
    double numerator = inner_product(d1,d2);
    double denominator = sqrt(inner_product(d1,d1) * inner_product(d2,d2));
    return acos(numerator/denominator);
}

unordered_map<string,int> wrodsFromFile(string filename){
    ifstream f;
    string s;

    unordered_map<string,int> d;
    f.open(filename);
    while(f >> s){
        for(int i = 0; i < s.length(); ++i){
            s[i] = tolower(s[i]);
        }

        auto x = d.find(s);
        if(x != d.end()){   //found
            x->second++;
        } else{
            d.insert({s,1});
        }
    }
    return d;
}


int main(){
    unordered_map<string,int> d1;
    unordered_map<string,int> d2;

    d1 = wrodsFromFile("text.txt");
    d2 = wrodsFromFile("text2.txt");
    
    double angle = vector_angle(d1,d2);

    cout << "angle:" << angle << endl;

    return 0;
}