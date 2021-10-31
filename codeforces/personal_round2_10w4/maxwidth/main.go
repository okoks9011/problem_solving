package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func main() {
	in = bufio.NewReader(os.Stdin)

	var n, m int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	var s, t string
	fmt.Fscan(in, &s)
	fmt.Fscan(in, &t)

	tIdx := 0
	leftest := make([]int, m)
	for sIdx, si := range []byte(s) {
		if si == t[tIdx] {
			leftest[tIdx] = sIdx
			tIdx++
		}
		if tIdx == m {
			break
		}
	}

	tIdx = m - 1
	rightest := make([]int, m)
	for sIdx := n - 1; sIdx >= 0; sIdx-- {
		if s[sIdx] == t[tIdx] {
			rightest[tIdx] = sIdx
			tIdx--
		}
		if tIdx < 0 {
			break
		}
	}

	maxV := 0
	for i := 1; i < m; i++ {
		if rightest[i]-leftest[i-1] > maxV {
			maxV = rightest[i] - leftest[i-1]
		}
	}
	fmt.Println(maxV)
}
