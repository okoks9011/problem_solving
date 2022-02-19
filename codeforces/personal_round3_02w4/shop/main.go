package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

type seg struct {
	l, r int
	c    int64
}

type lr struct {
	l, r int
}

func min(a, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	segs := make([]seg, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &segs[i].l)
		fmt.Fscan(in, &segs[i].r)
		fmt.Fscan(in, &segs[i].c)
	}

	left, right := segs[0].l, segs[0].r
	lMinCost, rMinCost := make(map[int]int64), make(map[int]int64)
	lrMinCost := make(map[lr]int64)
	for i := 0; i < n; i++ {
		si := segs[i]
		if si.l < left {
			left = si.l
		}
		if right < si.r {
			right = si.r
		}

		v, ok := lMinCost[si.l]
		if !ok {
			lMinCost[si.l] = si.c
		} else {
			lMinCost[si.l] = min(v, si.c)
		}
		v, ok = rMinCost[si.r]
		if !ok {
			rMinCost[si.r] = si.c
		} else {
			rMinCost[si.r] = min(v, si.c)
		}
		v, ok = lrMinCost[lr{si.l, si.r}]
		if !ok {
			lrMinCost[lr{si.l, si.r}] = si.c
		} else {
			lrMinCost[lr{si.l, si.r}] = min(v, si.c)
		}

		cost := lMinCost[left] + rMinCost[right]
		v, ok = lrMinCost[lr{left, right}]
		if ok {
			cost = min(cost, v)
		}
		fmt.Println(cost)
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
