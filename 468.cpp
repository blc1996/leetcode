class Solution {
public:
    string validIPAddress(string IP) {
        if(IPV4(IP)){
            return string("IPv4");
        }else if(IPV6(IP)){
            return string("IPv6");
        }else{
            return string("Neither");
        }
    }

    bool IPV4(string IP){
        IP.push_back('.');
        int rep = 4;
        while(IP.size()){
            if(IP[0] == '-'){
                return false;
            }
            int offset = IP.find('.');
            int num = 0;
            size_t sz;
            try{
                num = stoi(IP.substr(0, offset), &sz);
            }catch (...) {
                return false;
            }
            if(sz != offset || (IP[0] == '0' && offset > 1) || num < 0 || num > 255){
                return false;
            }
            
            IP.erase(IP.begin(), IP.begin() + offset + 1);
            rep--;
        }
        return rep == 0;
    }

    bool IPV6(string IP){
        IP.push_back(':');
        int rep = 8;
        while(IP.size()){
            int offset = IP.find(':');
            if(offset > 4 || offset < 1){
                return false;
            }
            for(auto cur = IP.begin(); cur != IP.begin() + offset; cur++){
                if( (*cur < '0' || *cur > '9') && (*cur < 'a' || *cur > 'f') && (*cur < 'A' || *cur > 'F') ){
                    return false;
                }
            }
            IP.erase(IP.begin(), IP.begin() + offset + 1);
            rep--;
        }
        return rep == 0;
    }
};