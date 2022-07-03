package main

import (
	"fmt"
)

// removeChar removes characater x if x has preceeding x-1.
func removeChar(cur []rune, x rune) ([]rune, int) {
	cnt := 0
	var buf []rune
	for i := 0; i < len(cur); i++ {
		if cur[i] != x {
			buf = append(buf, cur[i])
			continue
		}
		if len(buf) == 0 || buf[len(buf)-1] != x-1 {
			buf = append(buf, cur[i])
		} else {
			cnt++
		}
	}
	return buf, cnt
}

func reverse(buf []rune) {
	n := len(buf)
	for i := 0; i < n/2; i++ {
		buf[i], buf[n-1-i] = buf[n-1-i], buf[i]
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	var s string
	fmt.Scan(&s)

	result := 0
	cur := []rune(s)
	for x := 'z'; x > 'a'; x-- {
		removedForward, cnt := removeChar(cur, x)
		result += cnt

		reverse(removedForward)
		removed, cnt := removeChar(removedForward, x)
		result += cnt

		cur = removed
	}
	fmt.Println(result)
}
