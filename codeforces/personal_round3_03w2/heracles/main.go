package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	in  *bufio.Reader
	out *bufio.Writer
)

type vertex struct {
	w int64
	d int
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	vertices := make([]vertex, n)
	var wSum int64 = 0
	for i := 0; i < n; i++ {
		var wi int64
		fmt.Fscan(in, &wi)

		vertices[i].w = wi
		wSum += wi
	}
	for i := 0; i < n-1; i++ {
		var u, v int
		fmt.Fscan(in, &u)
		fmt.Fscan(in, &v)
		u--
		v--

		vertices[u].d++
		vertices[v].d++
	}

	sort.Slice(vertices, func(i, j int) bool {
		return vertices[i].w > vertices[j].w
	})

	cur := 0
	for i := 0; i < n-1; i++ {
		fmt.Fprintf(out, "%d ", wSum)

		for ; cur < n && vertices[cur].d <= 1; cur++ {
		}
		if cur >= n {
			break
		}
		wSum += vertices[cur].w
		vertices[cur].d--
	}
	fmt.Fprintln(out)
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
