package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in *bufio.Reader

type word struct {
	a, b, c, d, e int
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func calMaxWords(words []word, getDiff func(word) int) int {
	diffs := make([]int, len(words))
	for i, w := range words {
		diffs[i] = getDiff(w)
	}

	// sort.Slice(diffs, func(i, j int) bool {
	// 	return diffs[i] > diffs[j]
	// })
	sort.Sort(sort.Reverse(sort.IntSlice(diffs)))

	acc, cnt := 0, 0
	for _, di := range diffs {
		if acc+di > 0 {
			acc += di
			cnt++
			continue
		}
		break
	}
	return cnt
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	words := make([]word, n)
	for i := 0; i < n; i++ {
		var tmp string
		fmt.Fscan(in, &tmp)
		for _, ch := range tmp {
			switch ch {
			case 'a':
				words[i].a++
			case 'b':
				words[i].b++
			case 'c':
				words[i].c++
			case 'd':
				words[i].d++
			case 'e':
				words[i].e++
			default:
				panic("unknown character")
			}
		}
	}
	result := calMaxWords(words, func(w word) int {
		return w.a - (w.b + w.c + w.d + w.e)
	})
	result = max(result, calMaxWords(words, func(w word) int {
		return w.b - (w.a + w.c + w.d + w.e)
	}))
	result = max(result, calMaxWords(words, func(w word) int {
		return w.c - (w.a + w.b + w.d + w.e)
	}))
	result = max(result, calMaxWords(words, func(w word) int {
		return w.d - (w.a + w.b + w.c + w.e)
	}))
	result = max(result, calMaxWords(words, func(w word) int {
		return w.e - (w.a + w.b + w.c + w.d)
	}))
	fmt.Println(result)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
