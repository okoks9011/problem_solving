package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	N     = 100
	limit = 30
)

var (
	in = bufio.NewReader(os.Stdin)
)

var (
	twos  []int64
	rests []int64
)

func init() {
	cur := int64(1)
	i := 0
	for ; i < limit; i++ {
		twos = append(twos, cur)
		cur *= 2
	}
	for j := 0; j < limit/2; j++ {
		twos[j], twos[limit-1-j] = twos[limit-1-j], twos[j]
	}

	for ; i < N; i++ {
		rests = append(rests, int64(i*3))
	}
}

func solve() {
	var n int
	fmt.Fscan(in, &n)
	// n should be 100

	for _, ri := range rests {
		fmt.Printf("%d ", ri)
	}
	for _, ti := range twos {
		fmt.Printf("%d ", ti)
	}
	fmt.Println()

	b := make([]int64, N)
	for i := 0; i < len(b); i++ {
		fmt.Fscan(in, &b[i])
	}

	var (
		xSum int64 = 0
		ySum int64 = 0
		xs   []int64
	)

	apply := func(p []int64) {
		for _, pi := range p {
			if xSum < ySum {
				xSum += pi
				xs = append(xs, pi)
			} else {
				ySum += pi
			}

		}
	}
	apply(b)
	apply(rests)
	apply(twos)

	for _, xi := range xs {
		fmt.Printf("%d ", xi)
	}
	fmt.Println()
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
