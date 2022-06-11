package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func ask(l, r int) int {
	if l == r {
		return -1
	}
	fmt.Fprintf(out, "? %d %d\n", l, r)
	out.Flush()

	var t int
	fmt.Fscan(in, &t)
	return t
}

func guess(l, r int) int {
	if l > r {
		panic("impossible")
	}
	if l == r {
		return l
	}
	if r-l == 1 {
		x := ask(l, r)
		if x == l {
			return r
		} else if x == r {
			return l
		} else {
			panic("impossible")
		}
	}

	x := ask(l, r)
	mid := l + (r-l)/2
	if x <= mid { // second max is in the left half
		x2 := ask(l, mid)
		if x2 == x {
			return guess(l, mid)
		} else {
			return guess(mid+1, r)
		}
	} else { // second max is in the right half
		x2 := ask(mid+1, r)
		if x2 == x {
			return guess(mid+1, r)
		} else {
			return guess(l, mid)
		}
	}
}

func main() {
	var n int
	fmt.Fscan(in, &n)

	fmt.Fprintf(out, "! %d\n", guess(1, n))
	out.Flush()
}
