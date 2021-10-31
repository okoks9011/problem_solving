package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	sort.Sort(sort.Reverse(sort.IntSlice(a)))

	b := make([]int, n)
	i, bIdx := 0, 0
	for ; i < (n+1)/2; i++ {
		b[bIdx] = a[i]
		bIdx += 2
	}
	if n%2 == 0 {
		b[n-1] = a[i]
		i++
	}
	bIdx = 1
	for ; i < n; i++ {
		b[bIdx] = a[i]
		bIdx += 2
	}
	cnt := 0
	for j := 1; j < n-1; j++ {
		if b[j-1] > b[j] && b[j] < b[j+1] {
			cnt++
		}
	}
	fmt.Println(cnt)
	for j := 0; j < n; j++ {
		fmt.Printf("%d ", b[j])
	}
	fmt.Println()
}
