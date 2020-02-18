#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string str_result;
        string str_tmp;
        vector<string> vec_tmp;
        vector<string> vec_result;
        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == '/') {
                if(str_tmp.size() > 0) {
                    vec_tmp.push_back(str_tmp);
                    str_tmp = "";
                }
            } else {
                str_tmp += path[i];
            }
        }

        if(str_tmp.size() > 0) {
            vec_tmp.push_back(str_tmp);
        }

        for(int i = 0; i < vec_tmp.size(); ++i) {
            if(vec_tmp[i] == ".") {
                continue;
            } else if(vec_tmp[i] == "..") {
                if(vec_result.size() > 0) {
                    vec_result.pop_back();
                }
            } else {
                vec_result.push_back(vec_tmp[i]);
            }
        }

        for(int i = 0; i < vec_result.size(); ++i) {
            str_result += "/" + vec_result[i];
        }
        if(str_result.size() == 0) {
            return "/";
        }
        return str_result;
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("/a/../../b/../c//.//") << endl;
}
