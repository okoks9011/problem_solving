package main

import "fmt"

type cell struct {
	x, y int
}

func main() {
	var n, m, k int
	fmt.Scan(&n)
	fmt.Scan(&m)
	fmt.Scan(&k)

	trails := make([]cell, 0, n*m)
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			for j := 0; j < m; j++ {
				trails = append(trails, cell{i + 1, j + 1})
			}
		} else {
			for j := m - 1; j >= 0; j-- {
				trails = append(trails, cell{i + 1, j + 1})
			}
		}
	}

	ti := 0
	for i := 0; i < k-1; i++ {
		fmt.Printf("2 %d %d ", trails[ti].x, trails[ti].y)
		ti++
		fmt.Printf("%d %d\n", trails[ti].x, trails[ti].y)
		ti++
	}
	fmt.Printf("%d ", n*m-ti)
	for ; ti < n*m; ti++ {
		fmt.Printf("%d %d ", trails[ti].x, trails[ti].y)
	}
	fmt.Println()
}
