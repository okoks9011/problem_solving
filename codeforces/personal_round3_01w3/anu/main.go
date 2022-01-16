package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func main() {
	in = bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	bitCnt := make([]int, 32)
	for _, ai := range a {
		for j := 0; j < 32; j++ {
			if ai == 0 {
				break
			}
			if ai&1 == 1 {
				bitCnt[j]++
			}
			ai >>= 1
		}
	}

	mask := 0
	for j := 31; j >= 0; j-- {
		mask <<= 1
		if bitCnt[j] == 1 {
			mask |= 1
		}
	}

	for i := 1; i < n; i++ {
		if (a[0] & mask) < (a[i] & mask) {
			a[0], a[i] = a[i], a[0]
		}
	}

	for _, ai := range a {
		fmt.Printf("%d ", ai)
	}
	fmt.Println()
}
