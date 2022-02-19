package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in *bufio.Reader

type airCondi struct {
	idx, t int
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func solve() {
	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	airs := make([]airCondi, k)
	for i := 0; i < k; i++ {
		fmt.Fscan(in, &airs[i].idx)
		airs[i].idx--
	}
	for i := 0; i < k; i++ {
		fmt.Fscan(in, &airs[i].t)
	}

	sort.Slice(airs, func(i, j int) bool {
		return airs[i].idx < airs[j].idx
	})

	stack := []airCondi{airs[0]}
	for i := 1; i < k; i++ {
		last := stack[len(stack)-1]
		if airs[i].t-airs[i].idx >= last.t-last.idx {
			continue
		}
		for len(stack) > 0 {
			last := stack[len(stack)-1]
			if last.t+last.idx >= airs[i].t+airs[i].idx {
				stack = stack[:len(stack)-1]
			} else {
				break
			}
		}
		stack = append(stack, airs[i])
	}

	i := 0
	for si := 0; si < len(stack); si++ {
		air := stack[si]
		for ; i <= air.idx; i++ {
			curT := air.t + air.idx - i
			if si > 0 {
				last := stack[si-1]
				curT = min(curT, last.t+i-last.idx)
			}
			fmt.Printf("%d ", curT)
		}
	}
	air := stack[len(stack)-1]
	for ; i < n; i++ {
		curT := air.t + i - air.idx
		fmt.Printf("%d ", curT)
	}
	fmt.Println()
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var q int
	fmt.Fscan(in, &q)

	for i := 0; i < q; i++ {
		solve()
	}
}
