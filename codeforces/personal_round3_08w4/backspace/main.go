package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func solve() {
	var s, t string
	fmt.Fscan(in, &s)
	fmt.Fscan(in, &t)

	lastPick := -1
	si, ti := 0, 0
	for ; si < len(s); si++ {
		if lastPick == -1 && si%2 == 0 {
			continue
		}
		if lastPick != -1 && (si-lastPick)%2 == 0 {
			continue
		}
		if s[si] == t[ti] {
			ti++
			lastPick = si
		}
		if ti >= len(t) {
			fmt.Println("YES")
			return
		}
	}

	lastPick = -1
	si, ti = 0, 0
	for ; si < len(s); si++ {
		if lastPick == -1 && si%2 == 1 {
			continue
		}
		if lastPick != -1 && (si-lastPick)%2 == 0 {
			continue
		}
		if s[si] == t[ti] {
			ti++
			lastPick = si
		}
		if ti >= len(t) {
			fmt.Println("YES")
			return
		}
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
