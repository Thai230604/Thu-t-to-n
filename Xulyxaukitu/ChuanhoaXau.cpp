#include <bits/stdc++.h>

using namespace std;

// Hàm hiện nội dung của một vector chuỗi
void hien(vector<string> &a){
    for(string i : a){
        cout <<  i << " ";
    }
    cout << endl;
}

// Hàm đếm số lần chuỗi 'a' xuất hiện trong chuỗi 's'
int change(string s, string a){
    int c = 0;
    int n = a.size();
    for(int i = 0; i <= s.size() - n ; i++){
        if(s.substr(i, n) == a) c++;
    }
    return c;
}

// Hàm thay thế chuỗi 'a' trong chuỗi 's' bằng chuỗi "children"
string tochange(string s, string a){
    int n = a.size();
    int c = change(s, a);
    int m = s.size() - string("child").size()*c + string("children").size();
    for(int i = 0; i <= m - n;){
        if(s.substr(i, n) == a){
            s.replace(i, a.size(), "children");
            i += string("children").size();  // Di chuyển con trỏ sang phần sau của từ "children"
        }else{
        	i++;
		}
    }
    return s;
}

int main(){
    string s = "child are students, child are going to school";
    
    // Đếm số lần "child" xuất hiện trong chuỗi s
    cout << change(s, "child") << endl;  // Output: 2

    // Thay thế tất cả từ "child" bằng "children"
    cout << tochange(s, "child") << endl;  // Output: children are students, children are going to school
    cout << s;
}
