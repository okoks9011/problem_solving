package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

type div struct {
	a, b int
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func abs(x int) int {
	if x < 0 {
		return -x
	} else {
		return x
	}
}

func main() {
	var n int
	fmt.Fscan(in, &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &b[i])
	}

	base := 0
	cnt := make(map[div]int)
	for i := 0; i < n; i++ {
		if a[i] == 0 {
			if b[i] == 0 {
				base++
			}
			continue
		}
		if b[i] == 0 {
			cnt[div{a: 1, b: 0}]++
			continue
		}

		sameParity := (a[i] > 0 && b[i] > 0) || (a[i] < 0 && b[i] < 0)

		ai, bi := abs(a[i]), abs(b[i])
		g := gcd(ai, bi)
		ai /= g
		bi /= g

		if !sameParity {
			ai = -ai
		}

		cnt[div{a: ai, b: bi}]++
	}

	result := 0
	for _, v := range cnt {
		if v > result {
			result = v
		}
	}
	result += base
	fmt.Println(result)
}
