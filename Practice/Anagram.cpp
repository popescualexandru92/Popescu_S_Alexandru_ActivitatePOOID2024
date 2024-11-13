#include<iostream>
#include<string>
#include<map>


using namespace std;


map<char, int> toMap(string str) {
	map<char, int> map = {};
	for (int i = 0; i < str.length(); i++) {
		if (map.find(str[i]) ==map.end()) {
			map.insert({str[i],1});
		}
		else {
			map[str[i]]++;
		}
	}
	return map;
}

bool isAnagram(string str1, string str2) {
	if (str1.length() != str2.length())
		return false;
	else {
		map<char, int> m1 = toMap(str1);
		map<char, int> m2 = toMap(str2);
		return m1 == m2;
	}
}

int main() {
	string s = "dsadagfbvxzfaff adsf sad";

	cout << (isAnagram("abcbac", "abccdab")?"true":"false");


}