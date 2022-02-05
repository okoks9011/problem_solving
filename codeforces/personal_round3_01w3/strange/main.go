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

	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		b[i] = a[i]
	}

	sort.Ints(a)
	odd, even := make(map[int]int), make(map[int]int)
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			even[a[i]]++
		} else {
			odd[a[i]]++
		}
	}

	for i := 0; i < n; i++ {
		if i%2 == 0 {
			if even[b[i]] == 0 {
				fmt.Println("NO")
				return
			} else {
				even[b[i]]--
			}
		} else {
			if odd[b[i]] == 0 {
				fmt.Println("NO")
				return
			} else {
				odd[b[i]]--
			}
		}
	}
	fmt.Println("YES")
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
