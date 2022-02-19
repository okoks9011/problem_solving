package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func main() {
	in = bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	q := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		fmt.Fscan(in, &q[i])
	}

	p := make([]int, n)
	p[0] = 0
	minV := p[0]
	for i := 1; i < n; i++ {
		p[i] = p[i-1] + q[i-1]
		if p[i] < minV {
			minV = p[i]
		}
	}

	pSet := make(map[int]struct{})
	for i := 0; i < n; i++ {
		p[i] = p[i] - minV + 1
		pSet[p[i]] = struct{}{}
	}
	for i := 1; i <= n; i++ {
		_, ok := pSet[i]
		if !ok {
			fmt.Println(-1)
			return
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", p[i])
	}
	fmt.Println()
}
