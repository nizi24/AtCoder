#include <bits/stdc++.h>
using namespace std;

void calc(map<string, int> ver_map, int &result, string cal_sym) {
    if (cal_sym == ";") {
        return;
    }
    string x;
    cin >> x;
    int dight = ver_map.count(x) ? ver_map.at(x) : stoi(x);
    if (result != 10000) {
        if (cal_sym == "+") {
            result += dight;
        } else if (cal_sym == "-") {
            result -= dight;
        }
    } else {
        result = dight;
    }
    cin >> cal_sym;
    calc(ver_map, result, cal_sym);
}

void input_ver(map<string, int> &ver_map) {
    string ver_name, eq;
    cin >> ver_name;
    cin >> eq;
    int result = 10000;
    calc(ver_map, result, "");
    ver_map[ver_name] = result;
}

void print_int(map<string, int> ver_map) {
    int result = 10000;
    calc(ver_map, result, "");
    cout << result << endl;
}

void create_vec(vector<int> &ary, map<string, int> ver_map) {
    string x;
    cin >> x;
    if (x == "[") {
        create_vec(ary, ver_map);
        return;
    }
    if (x == "]") {
        return;
    }
    if (x == ",") {
        create_vec(ary, ver_map);
        return;
    }
    int dight = ver_map.count(x) ? ver_map.at(x) : stoi(x);
    ary.push_back(dight);
    create_vec(ary, ver_map);
}

void calc_vec(vector<int> &result, map<string, vector<int>> &vec_map, map<string, int> ver_map, string cal_sym) {
    if (cal_sym == ";") {
        return;
    }
    string x;
    cin >> x;
    vector<int> ary;
    if (x == "[") {
        create_vec(ary, ver_map);
    } else {
        if (vec_map.count(x)) {
            ary = vec_map[x];
        }
    }
    if (!result.size()) {
        result = ary;
    }
    if (cal_sym == "+") {
        for (int i = 0; i < ary.size(); i++) {
            result.at(i) += ary.at(i);
        }
    } else if (cal_sym == "-") {
        for (int i = 0; i < ary.size(); i++) {
            result.at(i) -= ary.at(i);
        }
    }
    cin >> cal_sym;
    calc_vec(result, vec_map, ver_map, cal_sym);
}

void vec(map<string, vector<int>> &vec_map, map<string, int> ver_map) {
    string ver_name, eq, begin;
    cin >> ver_name;
    cin >> eq;
    vector<int> ary;
    calc_vec(ary, vec_map, ver_map, "");
    vec_map[ver_name] = ary;
}

void print_vec(map<string, vector<int>> vec_map, map<string, int> ver_map) {
    vector<int> result;
    calc_vec(result, vec_map, ver_map, "");
    cout << "[ ";
    for (int i = 0; i < result.size(); i++) {
        cout << result.at(i) << " ";
    }
    cout << "]" << endl;
}

int main() {
    int n;
    cin >> n;
    map<string, int> ver_map;
    map<string, vector<int>> vec_map;
    for (int i = 0; i < n; i++) {
        string lead;
        cin >> lead;
        if (lead == "int") {
            input_ver(ver_map);
        } else if (lead == "print_int") {
            print_int(ver_map);
        } else if (lead == "vec") {
            vec(vec_map, ver_map);
        } else if (lead == "print_vec") {
            print_vec(vec_map, ver_map);
        }
    }
}