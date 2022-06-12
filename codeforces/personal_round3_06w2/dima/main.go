package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func printAnswer(ans []int) {
	fmt.Println("TAK")
	for _, idx := range ans {
		fmt.Printf("%d ", idx+1)
	}
	fmt.Println()
}

func main() {
	var n, m int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscan(in, &a[i][j])
		}
	}

	ans := make([]int, n)
	acc := 0
	for i := 0; i < n; i++ {
		acc ^= a[i][0]
	}
	if acc != 0 {
		printAnswer(ans)
		return
	}

	for i := 0; i < n; i++ {
		for j := 1; j < m; j++ {
			if a[i][0] != a[i][j] {
				ans[i] = j
				printAnswer(ans)
				return
			}
		}
	}
	fmt.Println("NIE")
}
