#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> strToInt(string ip) {
    vector<int> ipInt;
    while(ip.size() != 0) {
        int ind = ip.find('.');
        string subtemp;
        if(ind == -1) {
            subtemp = ip;
        }else {
            subtemp = ip.substr(0, ind);
            ip = ip.substr(ind + 1);
        }
        int temp = 0;
        for(int i = 0; i < subtemp.size(); i++) {
            temp = temp *10 + (subtemp[i] - '0');
        }
        ipInt.push_back(temp);
        if(ipInt.size() == 4) {
            break;
        }
    }
    return ipInt;
}

bool isMaskFun(string mask) {
    int in[] = {0, 128, 192, 224, 240, 248, 252, 254, 255};
    vector<int> maskConst(in, in+9);
    //cout << "mask is: " << mask << endl;
    vector<int> intMask = strToInt(mask);
    if(intMask[0] == 255 && intMask[1] == 255 && intMask[2] == 255 && intMask[3] == 255)
        return false;

    bool flag = true;
    for(int i = 0; i < intMask.size(); i++) {
        if(find(maskConst.begin(), maskConst.end(), intMask[i]) == maskConst.end()) {
            flag = false;
            break;
        }
        if(i > 0 && intMask[i-1] != 255 && intMask[i] != 0) {
            flag = false;
            break;
        }
    }

    if(flag) {
        //cout << "It is a mask ip" << endl;
    }else{
        //cout << "not a mask" << endl;
    }
    return flag;
}
void handleIp(string ip, char *ipType, char *sType) {
    //cout << "ip address is: " << ip << endl;
    vector<int> intIp = strToInt(ip);

    if (intIp[0] >= 1 && intIp[0] <= 126)
        *ipType = 'A';
    else if (intIp[0] >= 128 && intIp[0] <= 191)
        *ipType = 'B';
    else if (intIp[0] >= 192 && intIp[0] <= 223)
        *ipType = 'C';
    else if (intIp[0] >= 224 && intIp[0] <= 239)
        *ipType = 'D';
    else if (intIp[0] >= 240 && intIp[0] <= 255)
        *ipType = 'E';
    else
        *ipType = '-';

    // is special
    //cout << intIp[0] << ", " << intIp[1] << endl;
    if((intIp[0] == 10 && (intIp[1] >= 0 && intIp[1] <= 255)) || (intIp[0] == 172 && (intIp[1] >= 16 && intIp[1] <= 31)) || (intIp[0] == 192 && intIp[1] == 168))
        *sType = 'S';

    //cout << *ipType << ", " << *sType << endl;
}
int main() {
    string ipAdd;
    vector<string> inputIp;
    int aType = 0, bType = 0, cType = 0, dType = 0, eType = 0, errType = 0, selfType = 0;

    while(cin >> ipAdd) {
        string tempMask;
        int indexNotition = ipAdd.find('~');
        tempMask = ipAdd.substr(indexNotition + 1);
        bool isMask = isMaskFun(tempMask);

        string tempIp = ipAdd.substr(0, indexNotition);
        if(isMask) {
            inputIp.push_back(tempIp);
        } else {
            errType++;
        }
    }
    for(int i = 0; i < inputIp.size(); i++) {
        char ipType = '-', sType = '-';
        handleIp(inputIp[i], &ipType, &sType);
        if(ipType == 'A') aType++;
        if(ipType == 'B') bType++;
        if(ipType == 'C') cType++;
        if(ipType == 'D') dType++;
        if(ipType == 'E') eType++;
        if(sType == 'S') selfType++;
    }
    cout << aType << " " << bType << " " << cType << " " << dType << " " << eType << " " << errType << " " << selfType << endl;
    return 0;
}