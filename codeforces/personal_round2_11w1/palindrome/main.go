package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var n, m int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Fscan(in, &a[i][j])
		}
	}

	cnt := make(map[int][2]int)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			x := i + j
			v, ok := cnt[x]
			if !ok {
				v = [2]int{0, 0}
			}
			// a[i][j] should be 0 or 1.
			v[a[i][j]]++
			cnt[x] = v
		}
	}

	result := 0
	s := n + m - 2
	for i := 0; i < (s+1)/2; i++ {
		zeros := cnt[i][0] + cnt[s-i][0]
		ones := cnt[i][1] + cnt[s-i][1]
		if zeros > ones {
			result += ones
		} else {
			result += zeros
		}
	}
	fmt.Println(result)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
