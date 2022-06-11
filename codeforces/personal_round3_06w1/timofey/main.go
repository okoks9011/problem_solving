package main

import (
	"bufio"
	"fmt"
	"os"
	"reflect"
)

var in = bufio.NewReader(os.Stdin)

type edge struct {
	u, v int
}

func main() {
	var n int
	fmt.Fscan(in, &n)

	e := make([]edge, n-1)
	for i := 0; i < n-1; i++ {
		fmt.Fscan(in, &e[i].u)
		fmt.Fscan(in, &e[i].v)
	}

	c := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &c[i])
	}

	candis := make(map[int]struct{})
	for i := 1; i <= n; i++ {
		candis[i] = struct{}{}
	}
	for _, ei := range e {
		if c[ei.u] != c[ei.v] {
			nextCandis := make(map[int]struct{})
			if _, ok := candis[ei.u]; ok {
				nextCandis[ei.u] = struct{}{}
			}
			if _, ok := candis[ei.v]; ok {
				nextCandis[ei.v] = struct{}{}
			}
			candis = nextCandis
		}
	}

	if len(candis) == 0 {
		fmt.Println("NO")
		return
	}
	keys := reflect.ValueOf(candis).MapKeys()
	fmt.Println("YES")
	fmt.Println(keys[0])
}
