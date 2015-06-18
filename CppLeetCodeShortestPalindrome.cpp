/*
	Date		:	Friday, May 29, 2015
	Author		:	QualiP (https://github.com/QualiP)

	Objective	:	Shortest Palindrome (https://leetcode.com/problems/shortest-palindrome/)
					"Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
					 Find and return the shortest palindrome you can find by performing this transformation.

					 For example:

					 Given "aacecaaa", return "aaacecaaa".

					 Given "abcd", return "dcbabcd".

					 Credits	:
					 Special thanks to @ifanchu for adding this problem and creating all test cases.
					 Thanks to @Freezen for additional test cases."
*/
#include <string>
#include <iostream>

class Solution{
public:
	std::string shortestPalindrome(std::string s){
		std::string p = s;
		std::string temp;
		for (int i = 0, j = s.length() - 1; i < s.length(); ++i, --j) {
			if (!isPalindrome(p)) {
				temp += s[j];
				p = s;				/* Remove the last prepend of temp. */
				p.insert(0, temp);
			}
			else {
				break;
			}
		}
		return p;
	}

	bool isPalindrome(std::string s) {
		if (s.length() % 2 == 0) {
			return false;
		}
		/*else if () {
			
		}*/
		else {
			/* Defining first_half and second_half is too slow to submit to leetcode.
				See also: KMP algorithm. */
			std::string first_half;
			for (int i = 0; i < ((s.length() - 1) / 2); ++i) { first_half += s[i]; }
			std::string second_half;
			for (int i = s.length() - 1; i >(s.length() - 1) / 2; --i) { second_half += s[i]; }
			if (first_half.compare(second_half) == 0) { return true; }
			else { return false; }
		}
	}
};


int main() {
	Solution s;
	std::string str;
	std::cin >> str;
	std::cout << s.shortestPalindrome(str) << '\n';
}
