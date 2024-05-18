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
    std::vector<std::string> inputVector, parts, ipVector;
    vector<vector<string>> ips;

    // string testIp = "217.72.94.100";
    // vector<string> testIpSplitted = split(testIp, '.');
    // printIpVector(testIpSplitted, "test ip: ");

    while(std::getline( std::cin, input )) {
        //std::cout << "New line is: " << input << std::endl;
        parts = split(input, '\t');
        //std::cout << "IP address is: " << parts[0] << std::endl;
        inputVector.push_back(parts[0]);
        ipVector = split(parts[0], '.');
        ips.push_back(ipVector);
    }
    // std::cout << "Count of ip addresses: " << inputVector.size() << " \n";

    std::sort(inputVector.begin(), inputVector.end(), [](string a, string b) {
        vector<string> va = split(a, '.'),
            vb = split(b, '.');
        try {
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
        } catch(std::invalid_argument &ia) {
            std::cout << "throwing an instance of 'std::invalid_argument' \n";
            std::cout << "a address: " << a << "\n";
            printIpVector(va, "a splitted address: ");
            std::cout << "b address: " << b << "\n";
            printIpVector(vb, "b splitted address: ");
            return false;
        }
    });

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

    // std::cout << "Sorted addresses: \n";
    // for(auto &i : inputVector) {
    //     std::cout << i << "\n";
    // }
    for(auto &i : ips) {
        printIpVector(i);
    }

    for(auto &i : ips) {
        if(i[0] == "1")
            printIpVector(i);
    }

    for(auto &i : ips) {
        if(i[0] == "46" && i[1] == "70")
            printIpVector(i);
    }

    for(auto &i : ips) {
        if(i[0] == "46" || i[1] == "46" || i[2] == "46" || i[3] == "46")
            printIpVector(i);
    }

    //std::cout << " --- finish --- \n";
}
