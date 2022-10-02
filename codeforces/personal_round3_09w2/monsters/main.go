package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

type elem struct {
	pos, value int
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	k := make([]int, n)
	for i := range k {
		fmt.Fscan(in, &k[i])
	}
	h := make([]int, n)
	for i := range h {
		fmt.Fscan(in, &h[i])
	}

	var stack []elem
	for i := 0; i < n; i++ {
		goalI := h[i]
		startI := k[i] - goalI + 1
		for len(stack) > 0 && stack[len(stack)-1].pos >= startI {
			last := stack[len(stack)-1]
			goalI = max(goalI, last.value+k[i]-last.pos)
			startI = k[i] - goalI + 1
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, elem{pos: k[i], value: goalI})
	}

	var result int64 = 0
	for _, e := range stack {
		v := int64(e.value)
		result += (v + 1) * v / 2
	}
	fmt.Println(result)
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
