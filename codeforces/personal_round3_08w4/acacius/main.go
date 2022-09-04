package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	key = []byte("abacaba")
)

func countKey(s []byte) int {
	count := 0
	for start := 0; start+len(key) <= len(s); start++ {
		found := true
		for i := 0; i < len(key); i++ {
			if s[start+i] != key[i] {
				found = false
				break
			}
		}
		if found {
			count++
		}
	}
	return count
}

func printS(s []byte) {
	for i := range s {
		if s[i] == '?' {
			s[i] = 'z'
		}
	}
	fmt.Println(string(s))
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	var sRaw string
	fmt.Fscan(in, &sRaw)

	s := []byte(sRaw)
	cnt := countKey(s)
	if cnt >= 2 {
		fmt.Println("No")
		return
	}
	if cnt == 1 {
		fmt.Println("Yes")
		printS(s)
		return
	}

	for start := 0; start+len(key) <= len(s); start++ {
		var replace []int
		found := true
		for i := 0; i < len(key); i++ {
			if s[start+i] == '?' {
				replace = append(replace, start+i)
				s[start+i] = key[i]
			}
			if s[start+i] != key[i] {
				found = false
				break
			}
		}
		if found {
			cnt := countKey(s)
			if cnt == 1 {
				fmt.Println("Yes")
				printS(s)
				return
			}
		}
		for _, ri := range replace {
			s[ri] = '?'
		}
	}
	fmt.Println("No")
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
