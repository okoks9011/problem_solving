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

	var sum int64 = 0
	maxV := 0
	for _, ai := range a {
		sum += int64(ai)
		if maxV < ai {
			maxV = ai
		}
	}
	if sum%2 == 0 && int64(maxV) <= sum/2 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
