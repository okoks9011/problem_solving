package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var n int
	fmt.Fscan(in, &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	minV, maxV := -1, -1

	for i := 0; i < n; i++ {
		if a[i] != -1 {
			continue
		}
		if i > 0 && a[i-1] != -1 {
			if minV == -1 || a[i-1] < minV {
				minV = a[i-1]
			}
			if maxV == -1 || a[i-1] > maxV {
				maxV = a[i-1]
			}
		}
		if i < n-1 && a[i+1] != -1 {
			if minV == -1 || a[i+1] < minV {
				minV = a[i+1]
			}
			if maxV == -1 || a[i+1] > maxV {
				maxV = a[i+1]
			}
		}
	}
	m := (maxV - minV + 1) / 2
	k := minV + m
	if k == -1 {
		k = 0
	}

	for i := 0; i < n-1; i++ {
		if a[i] == -1 || a[i+1] == -1 {
			continue
		}
		diff := a[i+1] - a[i]
		if diff < 0 {
			diff = -diff
		}
		if diff > m {
			m = diff
		}
	}
	fmt.Println(m, k)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
