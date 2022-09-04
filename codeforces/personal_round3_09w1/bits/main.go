package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in     = bufio.NewReader(os.Stdin)
	candis []int64
)

func findMatch(l, r int64) int {
	found := -1
	for j, cj := range candis {
		if l <= cj && cj <= r {
			found = j
		}
	}
	return found
}

func main() {
	var n int
	fmt.Fscan(in, &n)

	for v := int64(1); v <= 1e18; {
		candis = append(candis, v)
		v <<= 1
		v += 1
	}

	for i := 0; i < n; i++ {
		var l, r int64
		fmt.Fscan(in, &l)
		fmt.Fscan(in, &r)
		if l == r {
			fmt.Println(l)
			continue
		}

		found := findMatch(l, r)
		if found != -1 {
			fmt.Println(candis[found])
			continue
		}

		var mask int64 = 0
		x := l ^ r
		for x != 0 {
			x >>= 1
			mask <<= 1
			mask += 1
		}
		found = findMatch(l&mask, r&mask)
		if found == -1 {
			panic("impossible")
		}
		fmt.Println(l & ^mask + candis[found])
	}
}
