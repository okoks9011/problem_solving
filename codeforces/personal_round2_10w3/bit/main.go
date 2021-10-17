package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	var s string
	fmt.Fscan(in, &s)

	merged := make([]byte, k)
	for i := 0; i < k; i++ {
		merged[i] = s[i]
		for j := i; j < n; j += k {
			if merged[i] == '?' {
				merged[i] = s[j]
				continue
			}
			if s[j] == '?' {
				continue
			}
			if merged[i] != s[j] {
				fmt.Println("NO")
				return
			}
		}
	}
	cnt := make(map[byte]int)
	for _, v := range merged {
		cnt[v]++
	}

	diff := cnt['1'] - cnt['0']
	if diff < 0 {
		diff = -diff
	}
	if diff <= cnt['?'] {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
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
