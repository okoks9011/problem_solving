package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in *bufio.Reader

func solve() {
	var n int
	fmt.Fscan(in, &n)

	cnt := make(map[int]int)
	for i := 0; i < n; i++ {
		var pi int
		fmt.Fscan(in, &pi)
		cnt[pi]++
	}
	if n < 10 || len(cnt) < 4 {
		fmt.Println("0 0 0")
		return
	}

	var scores []int
	for score := range cnt {
		scores = append(scores, score)
	}
	sort.Slice(scores, func(i, j int) bool {
		return scores[i] > scores[j]
	})

	idx := 0
	g := cnt[scores[idx]]
	idx++

	s := 0
	for ; s <= g && idx < len(scores); idx++ {
		s += cnt[scores[idx]]
	}

	b := 0
	for ; idx < len(scores); idx++ {
		next := cnt[scores[idx]]
		if g+s+b+next > n/2 {
			break
		}
		b += next
	}

	if g >= s || g >= b {
		fmt.Println("0 0 0")
		return
	}
	fmt.Printf("%d %d %d\n", g, s, b)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
