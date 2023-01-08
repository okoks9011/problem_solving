package main

import "fmt"

func solve() {
	var n, l, r, s int
	fmt.Scan(&n)
	fmt.Scan(&l)
	fmt.Scan(&r)
	fmt.Scan(&s)

	d := r - l + 1
	minV := (1 + d) * d / 2
	maxV := (n + (n - d + 1)) * d / 2
	if s < minV || maxV < s {
		fmt.Println(-1)
		return
	}
	chunkSize := n - d
	if chunkSize == 0 {
		for i := 1; i <= n; i++ {
			fmt.Printf("%d ", i)
		}
		fmt.Println()
		return
	}

	right := (s - minV) / chunkSize
	step := (s - minV) % chunkSize
	left := d - right - 1
	x := left + 1 + step

	selected := make([]bool, n+1)
	for i := 1; i <= left; i++ {
		selected[i] = true
	}
	selected[x] = true
	for i := 0; i < right; i++ {
		selected[n-i] = true
	}

	include, exclude := make([]int, 0), make([]int, 0)
	for i := 1; i <= n; i++ {
		if selected[i] {
			include = append(include, i)
		} else {
			exclude = append(exclude, i)
		}
	}

	for i := 1; i <= n; i++ {
		if i < l || r < i {
			fmt.Printf("%d ", exclude[len(exclude)-1])
			exclude = exclude[:len(exclude)-1]
		} else {
			fmt.Printf("%d ", include[len(include)-1])
			include = include[:len(include)-1]
		}
	}
	fmt.Println()
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		solve()
	}
}
