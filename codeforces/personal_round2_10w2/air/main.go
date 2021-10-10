package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

type customer struct {
	t    int
	l, h int64
}

func solve() {
	var n int
	var m int64
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	cs := make([]customer, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &cs[i].t)
		fmt.Fscan(in, &cs[i].l)
		fmt.Fscan(in, &cs[i].h)
	}

	time := 0
	minT := m
	maxT := m
	for _, c := range cs {
		diff := int64(c.t - time)
		minT -= diff
		maxT += diff

		if c.l > minT {
			minT = c.l
		}
		if c.h < maxT {
			maxT = c.h
		}
		if minT > maxT {
			fmt.Println("NO")
			return
		}
		time = c.t
	}
	fmt.Println("YES")
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var q int
	fmt.Fscan(in, &q)
	for i := 0; i < q; i++ {
		solve()
	}
}
