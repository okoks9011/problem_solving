package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func solve() {
	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	pairs := make(map[int]int)
	for i := 0; i < n/2; i++ {
		pairs[i] = (n - 1) ^ i
	}

	if 0 < k && k < n-1 {
		ck := (n - 1) ^ k
		if k < n/2 {
			delete(pairs, k)
		} else {
			delete(pairs, ck)
		}
		pairs[0] = ck
		pairs[k] = n - 1
	} else if k == n-1 {
		if n == 4 {
			fmt.Println(-1)
			return
		}
		delete(pairs, 0)
		delete(pairs, 1)
		delete(pairs, 2)
		pairs[0] = 2
		pairs[1] = n - 3
		pairs[n-2] = n - 1
	}

	for a, b := range pairs {
		fmt.Println(a, b)
	}
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
