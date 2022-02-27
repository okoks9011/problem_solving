package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func isPalindrome(si, ei int, s string) bool {
	for i := si; i <= ei; i++ {
		if s[i] != s[ei-(i-si)] {
			return false
		}
	}
	return true
}

func reverse(s string) string {
	tmp := []rune(s)
	n := len(tmp)
	for i := 0; i < n/2; i++ {
		tmp[i], tmp[n-1-i] = tmp[n-1-i], tmp[i]
	}
	return string(tmp)
}

func getLongestPalindromeFromLeft(s string) string {
	n := len(s)
	result := ""
	for i := 0; i < n; i++ {
		remain := n - (i + 1)
		pi := 0
		for ; pi <= i && pi < remain && s[pi] == s[n-1-pi]; pi++ {
		}

		if pi > i {
			curResult := s[:pi] + s[n-pi:]
			if len(curResult) > len(result) {
				result = curResult
			}
		} else if isPalindrome(pi, i, s) {
			curResult := s[:i+1] + s[n-pi:]
			if len(curResult) > len(result) {
				result = curResult
			}
		}
	}
	return result
}

func solve() {
	var s string
	fmt.Fscan(in, &s)

	leftResult := getLongestPalindromeFromLeft(s)
	rightResult := getLongestPalindromeFromLeft(reverse(s))
	if len(leftResult) < len(rightResult) {
		fmt.Println(rightResult)
	} else {
		fmt.Println(leftResult)
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
