package main

import (
	"bufio"
	"fmt"
	"os"
)

var out = bufio.NewWriter(os.Stdout)

func main() {
	defer out.Flush()

	var n, k int
	fmt.Scan(&n)
	fmt.Scan(&k)

	var base []byte
	for i := 0; i < k; i++ {
		base = append(base, 'a')
		cur := 'a' + byte(i)
		for j := byte('b'); j <= cur; j++ {
			base = append(base, cur, j)
		}
	}

	for i := 0; i < n; i++ {
		fmt.Fprintf(out, "%c", base[i%len(base)])
	}
	fmt.Fprintln(out)
}
