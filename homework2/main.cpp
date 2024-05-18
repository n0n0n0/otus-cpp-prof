#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printIpVector(vector<string> v, string title = "") {
    if(title != "")
        std::cout << title;
    for(auto it = v.begin(), end = v.end(); it != end; ++it) {
        std::cout << *it;
        if(it != end-1) std::cout << ".";
    }
    std::cout << "\n";
}

vector<string> split(const string &in, char delim) {
    string::size_type firstPos = 0, pos;
    vector<string> result;

    while((pos = in.find(delim, firstPos)) != in.npos ) {
        result.push_back(in.substr(firstPos, pos - firstPos));
        firstPos = pos + 1;
    }
    result.push_back(in.substr(firstPos, in.size() - firstPos));

    return result;
}

int main(int argc, char** argv){
    std::string input, ipaddr;
    std::vector<std::string> parts, ipVector;
    vector<vector<string>> ips;

    while(std::getline( std::cin, input )) {
        parts = split(input, '\t');
        ipVector = split(parts[0], '.');
        ips.push_back(ipVector);
    }

    // sort
    std::sort(ips.begin(), ips.end(), [](vector<string> va, vector<string> vb) {
        if(stoi(va[0]) == stoi(vb[0])) {
            if(stoi(va[1]) == stoi(vb[1])) {
                if(stoi(va[2]) == stoi(vb[2])) {
                    return stoi(va[3]) > stoi(vb[3]);
                } else
                    return stoi(va[2]) > stoi(vb[2]);
            } else
                return stoi(va[1]) > stoi(vb[1]);
        } else 
            return stoi(va[0]) > stoi(vb[0]);
    });

    // print all sorted
    for(auto &i : ips) {
        printIpVector(i);
    }

    // print all with 1.x.x.x
    for(auto &i : ips) {
        if(i[0] == "1")
            printIpVector(i);
    }

    // print all with 46.70.x.x
    for(auto &i : ips) {
        if(i[0] == "46" && i[1] == "70")
            printIpVector(i);
    }

    // print all with any 46
    for(auto &i : ips) {
        if(i[0] == "46" || i[1] == "46" || i[2] == "46" || i[3] == "46")
            printIpVector(i);
    }
}
