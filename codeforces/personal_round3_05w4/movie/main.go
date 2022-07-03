package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func isPalindrome(t string) bool {
	if len(t) <= 1 {
		return true
	}

	n := len(t)
	for i := 0; i < n/2; i++ {
		if t[i] != t[n-1-i] {
			return false
		}
	}
	return true
}

func reverseStr(t string) string {
	n := len(t)
	tmp := make([]rune, n)
	for i, ti := range t {
		tmp[n-1-i] = ti
	}
	return string(tmp)
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	s := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &s[i])
	}

	for _, si := range s {
		if isPalindrome(si) {
			fmt.Println("YES")
			return
		}
	}

	founds := make(map[string]bool)
	for _, si := range s {
		revSi := reverseStr(si)
		if _, ok := founds[revSi]; ok {
			fmt.Println("YES")
			return
		}

		if len(si) == 2 {
			base := []rune(revSi)
			for c := 'a'; c <= 'z'; c++ {
				cur := string(append(base, c))
				if _, ok := founds[cur]; ok {
					fmt.Println("YES")
					return
				}
			}
		} else if len(si) == 3 {
			if _, ok := founds[revSi[:2]]; ok {
				fmt.Println("YES")
				return
			}
		} else {
			panic("impossible")
		}
		founds[si] = true
	}
	fmt.Println("NO")
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
