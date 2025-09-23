class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>ver1(501, "0");
        vector<string>ver2(501,"0");
        int m =0;
        string s = "";
        for(int i = 0 ; i<=version1.size();i++){
            if(i == version1.size()){
                ver1[m] = s;
                m++;
                s= "";
                continue;
            }
            if(version1[i]=='.'){
                ver1[m] = s;
                m++;
                s= "";
                continue;
            }
            s.push_back(version1[i]);
        }
        m = 0;
        s = "";

        for(int i = 0 ; i<=version2.size();i++){
            if(i == version2.size()){
                ver2[m] = s;
                m++;
                s= "";
                continue;
            }
            if(version2[i]=='.'){
                ver2[m] = s;
                m++;
                s= "";
                continue;
            }
            s.push_back(version2[i]);
        }


        for(int i = 0; i<=500;i++){
            if(stoi(ver1[i]) >  stoi(ver2[i])){
                return 1 ;
            }
            else if(stoi(ver1[i]) <  stoi(ver2[i]))
                return -1;
        }

        return 0;
    }
};